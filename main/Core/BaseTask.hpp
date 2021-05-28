/**@file BaseTask.hpp
 * @author msn@ektos.net (EKTOS A/S)
 * @date created on Jul 26, 2017
 * @version 1.0
 * @brief Interface for RTOS task implementation
 * @note Belongs to ESB project
 */
#ifndef SOURCE_KERNEL_RTOS_BASETASK_HPP_
#define SOURCE_KERNEL_RTOS_BASETASK_HPP_

#include "SYSPort.hpp"
#include "../Common/Types.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "../Common/Common.hpp"
#include "../../config/sdkconfig.h"

/**@brief Interface for RTOS task implementation
 * @ingroup kernel_objects
 */
class BaseTask {
public:
  enum {
	  SysIdlePriority = 0,
  };

  BaseTask()
    : wdtInterval(0),
      id(-1) { }

  virtual ~BaseTask() { }

  /**@brief Will be run in task's context
   * @note after return task will be stopped until it will be created again by create method
   */
  virtual void run() = 0;

  /**@brief Creates and starts new task
   * @param [in] name - Symbolic name for new task
   * @param [in] stack - pointer to start of stack (not top, lowest address)
   * @param [in] stackBlocks - stack size in architecture words (word usual equal to size of pointer)
   * @param [in] priority - task priority
   * @return @b true if task successfully created, otherwise @b false
   */
  bool create(const char *name, void **stack, size_t stackBlocks, int core = 1, uint32_t priority = SysIdlePriority) {
    assert(!isRunning());

	#if CONFIG_FREERTOS_UNICORE == 1
    handle = xTaskCreateStatic(&BaseTask::taskCode,
                                   name,
                                   stackBlocks,
                                   this,
                                   priority,
                                   reinterpret_cast<StackType_t *>(stack),
                                   &xTaskBuffer);

	#else
    handle = xTaskCreateStaticPinnedToCore(&BaseTask::taskCode,
                               name,
                               stackBlocks,
                               this,
                               priority,
                               reinterpret_cast<StackType_t *>(stack),
                               &xTaskBuffer,
							   core);
	#endif
    vTaskSetThreadLocalStoragePointer(handle, 0, this);
    return (handle != 0);
  }

  /**@brief returns task state
   * @return @b true if task is running, and @b false when it have not been created or already ended
   */
  bool isRunning() const {
    if (handle == nullptr) {
      return false;
    }
    return eTaskGetState(handle) != eTaskState::eDeleted;
  }

  /**@brief Returns reference to currently active running task
   * @return reference on current task
   */
  static BaseTask &getCurrentTask() {
    return *(BaseTask *) pvTaskGetThreadLocalStoragePointer(NULL, 0);
  }

private:
//  friend class SYSWDT;
  static void taskCode(void *pvParameters) {
    static_cast<BaseTask *>(pvParameters)->run();
    vTaskDelete(NULL);
  }

  TaskHandle_t handle = nullptr;
  StaticTask_t xTaskBuffer;
//  SingleList::Item item;
  uint32_t wdtInterval;
  uint8_t id;
};

/**@brief Task with predefined and allocated stack
 * @tparam stackSize - Additional stack size in architecture words.
 * @note Full stack size may be calculated by adding minimal stack size for RTOS to stackSize
 */
template<size_t stackSize = 0>
class StaticBaseTask : public BaseTask {
public:

  /**@brief Creates and starts new task
   * @param [in] name - Symbolic name for new task
   * @param [in] priority - task priority
   * @return @b true if task successfully created, otherwise @b false
   */
  bool create(const char *name, int core = 1, uint32_t priority = SysIdlePriority) {
    return BaseTask::create(name, reinterpret_cast<void **>(&stack), sizeOfArray(stack), core, priority);
  }

private:
  StackType_t stack[stackSize + configMINIMAL_STACK_SIZE];
};

#endif /* SOURCE_KERNEL_RTOS_BASETASK_HPP_ */

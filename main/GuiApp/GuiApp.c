/*
 * exampleGuiTask.c
 *
 *  Created on: Apr 12, 2021
 *      Author: f73377
 */

#include "../GuiApp/include/GuiApp.h"

#include "lvgl_helpers.h"
#include "esp_heap_caps.h"

#include "freertos/task.h"
#include "esp_freertos_hooks.h"
#include "freertos/semphr.h"
#include "esp_system.h"
#include "driver/gpio.h"
#include "lvgl.h"
#include "include/MainScreen.h"

#define LV_TICK_PERIOD_MS 1

#ifdef __cplusplus
extern "C" {
#endif

static void run();
static void lvgl_init();
static void lv_tick_task(void *arg);

/* Creates a semaphore to handle concurrent call to lvgl stuff
 * If you wish to call *any* lvgl function from other threads/tasks
 * you should lock on the very same semaphore! */
static SemaphoreHandle_t xGuiSemaphore;
static lv_color_t *buf1;
static lv_color_t *buf2;


static lv_obj_t* mainScreen;

void guiApp_init() {
	xGuiSemaphore = xSemaphoreCreateMutex();
	lvgl_init();


	mainScreen = mainScreen_create();
	lv_scr_load(mainScreen);
}

void guiApp_start(const uint32_t usStackDepth, UBaseType_t uxPriority,
		const BaseType_t xCoreID) {
	xTaskCreatePinnedToCore(run, "gui_run", 4096 * 2, NULL, 0, NULL, 1);
}

static void run(void *pvParameter) {
	(void) pvParameter;

	while (1) {
		/* Delay 1 tick (assumes FreeRTOS tick is 10ms */
		vTaskDelay(pdMS_TO_TICKS(10));

		/* Try to take the semaphore, call lvgl related function on success */
		if (pdTRUE == xSemaphoreTake(xGuiSemaphore, portMAX_DELAY)) {
			lv_task_handler();
			xSemaphoreGive(xGuiSemaphore);
		}
	}

	/* A task should NEVER return */
	free(buf1);
#ifndef CONFIG_LV_TFT_DISPLAY_MONOCHROME
	free(buf2);
#endif
	vTaskDelete(NULL);
}

static void lvgl_init() {
	lv_init();

	/* Initialize SPI or I2C bus used by the drivers */
	lvgl_driver_init();

	buf1 = (lv_color_t*) heap_caps_malloc(
	DISP_BUF_SIZE * sizeof(lv_color_t), MALLOC_CAP_DMA);
	assert(buf1 != NULL);

	buf2 = (lv_color_t*) heap_caps_malloc(
	DISP_BUF_SIZE * sizeof(lv_color_t), MALLOC_CAP_DMA);
	assert(buf2 != NULL);

	static lv_disp_buf_t disp_buf;

	uint32_t size_in_px = DISP_BUF_SIZE;

	/* Initialize the working buffer depending on the selected display.
	 * NOTE: buf2 == NULL when using monochrome displays. */
	lv_disp_buf_init(&disp_buf, buf1, buf2, size_in_px);

	lv_disp_drv_t disp_drv;
	lv_disp_drv_init(&disp_drv);
	disp_drv.flush_cb = disp_driver_flush;

	disp_drv.buffer = &disp_buf;
	lv_disp_drv_register(&disp_drv);

	/* Register an input device when enabled on the menuconfig */
	lv_indev_drv_t indev_drv;
	lv_indev_drv_init(&indev_drv);
	indev_drv.read_cb = touch_driver_read;
	indev_drv.type = LV_INDEV_TYPE_POINTER;
	lv_indev_drv_register(&indev_drv);

	/* Create and start a periodic timer interrupt to call lv_tick_inc */
	const esp_timer_create_args_t periodic_timer_args = { .callback =
			&lv_tick_task, .name = "periodic_gui" };
	esp_timer_handle_t periodic_timer;
	ESP_ERROR_CHECK(esp_timer_create(&periodic_timer_args, &periodic_timer));
	ESP_ERROR_CHECK(
			esp_timer_start_periodic(periodic_timer, LV_TICK_PERIOD_MS * 1000));
}

static void lv_tick_task(void *arg) {
	(void) arg;

	lv_tick_inc(LV_TICK_PERIOD_MS);
}

#ifdef __cplusplus
}
#endif


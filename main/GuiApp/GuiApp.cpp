/*
 * GuiApp.cpp
 *
 *  Created on: Apr 21, 2021
 *      Author: f73377
 */

#include "GuiApp.h"
#include "lvgl.h"
#include "lvgl_helpers.h"
#include "esp_timer.h"

#define LV_TICK_PERIOD_MS 1

static GuiApp guiApp;

static lv_color_t *buf1;
static lv_color_t *buf2;
static SemaphoreHandle_t xGuiSemaphore;

static void lvgl_init();
static void lv_tick_task(void *arg);

MainScreen GuiApp::mMainScreen;

GuiApp::GuiApp() {
	xGuiSemaphore = xSemaphoreCreateMutex();
}

GuiApp::~GuiApp() {
}

void GuiApp::init() {
	lvgl_init();

	mMainScreen.init();
	mMainScreen.load();
}


void vTaskCode( void * pvParameters )
{
	GuiApp::run();

	free(buf1);
	free(buf2);
	vTaskDelete(NULL);
}

void GuiApp::start(uint32_t stackSize, uint8_t priority, uint8_t coreId) {
	xTaskCreatePinnedToCore(vTaskCode, "gui_run", stackSize, NULL, priority, NULL, coreId);
}

void GuiApp::run() {
	while (1) {
		vTaskDelay(pdMS_TO_TICKS(10));
		if (pdTRUE == xSemaphoreTake(xGuiSemaphore, portMAX_DELAY)) {
			lv_task_handler();
			xSemaphoreGive(xGuiSemaphore);
		}
	}
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

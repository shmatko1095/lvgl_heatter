/*
 * SdStorrage.c
 *
 *  Created on: Apr 29, 2021
 *      Author: f73377
 */

#include <stdio.h>
#include <string.h>
#include <sys/unistd.h>
#include <sys/stat.h>
#include "esp_err.h"
#include "esp_log.h"
#include "esp_spiffs.h"

#include "nvs_flash.h"
#include "nvs.h"
#include "nvs_handle.hpp"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"

#include "SpiFfsStorrage.h"

static const char *TAG = "example";

SpiFfsStorrage::SpiFfsStorrage(){
	create("SpiFfsStorrage", 1, 1);
}

void SpiFfsStorrage::run(){
//	nvsExample();
	init();
    while (true) {
//       taskENTER_CRITICAL();
       esp_err_t err;
       printf("Opening Non-Volatile Storage (NVS) handle... ");
       esp_err_t result;
       // Handle will automatically close when going out of scope or when it's reset.
       std::shared_ptr<nvs::NVSHandle> handle = nvs::open_nvs_handle("storage", NVS_READWRITE, &result);
       if (err != ESP_OK) {
           printf("Error (%s) opening NVS handle!\n", esp_err_to_name(err));
       } else {
           printf("Done\n");

           // Read
           printf("Reading restart counter from NVS ... ");
           int32_t restart_counter = 0; // value will default to 0, if not set yet in NVS
           err = handle->get_item("restart_counter", restart_counter);
           switch (err) {
               case ESP_OK:
                   printf("Done\n");
                   printf("Restart counter = %d\n", restart_counter);
                   break;
               case ESP_ERR_NVS_NOT_FOUND:
                   printf("The value is not initialized yet!\n");
                   break;
               default :
                   printf("Error (%s) reading!\n", esp_err_to_name(err));
           }

           // Write
//           printf("Updating restart counter in NVS ... ");
//           restart_counter++;
//           err = handle->set_item("restart_counter", restart_counter);
//           printf((err != ESP_OK) ? "Failed!\n" : "Done\n");
//
//           printf("Committing updates in NVS ... ");
//           err = handle->commit();
//           printf((err != ESP_OK) ? "Failed!\n" : "Done\n");
       }
//       taskEXIT_CRITICAL();
       vTaskDelay(500 / portTICK_PERIOD_MS);
       printf("\n");
    }
}

void SpiFfsStorrage::init(){
	esp_err_t err = nvs_flash_init();
	if (err == ESP_ERR_NVS_NO_FREE_PAGES || err == ESP_ERR_NVS_NEW_VERSION_FOUND) {
	    // NVS partition was truncated and needs to be erased
	    // Retry nvs_flash_init
	    ESP_ERROR_CHECK(nvs_flash_erase());
	    err = nvs_flash_init();
	}
	ESP_ERROR_CHECK( err );
}

void nvsExample(void){
	esp_err_t err = nvs_flash_init();
	if (err == ESP_ERR_NVS_NO_FREE_PAGES || err == ESP_ERR_NVS_NEW_VERSION_FOUND) {
	    // NVS partition was truncated and needs to be erased
	    // Retry nvs_flash_init
	    ESP_ERROR_CHECK(nvs_flash_erase());
	    err = nvs_flash_init();
	}
	ESP_ERROR_CHECK( err );

	while (true) {
	   // Open
	   printf("\n");
	   printf("Opening Non-Volatile Storage (NVS) handle... ");
	   esp_err_t result;
	   // Handle will automatically close when going out of scope or when it's reset.
	   std::shared_ptr<nvs::NVSHandle> handle = nvs::open_nvs_handle("storage", NVS_READWRITE, &result);
	   if (err != ESP_OK) {
	       printf("Error (%s) opening NVS handle!\n", esp_err_to_name(err));
	   } else {
	       printf("Done\n");

	       // Read
	       printf("Reading restart counter from NVS ... ");
	       int32_t restart_counter = 0; // value will default to 0, if not set yet in NVS
	       err = handle->get_item("restart_counter", restart_counter);
	       switch (err) {
	           case ESP_OK:
	               printf("Done\n");
	               printf("Restart counter = %d\n", restart_counter);
	               break;
	           case ESP_ERR_NVS_NOT_FOUND:
	               printf("The value is not initialized yet!\n");
	               break;
	           default :
	               printf("Error (%s) reading!\n", esp_err_to_name(err));
	       }

	       // Write
	       printf("Updating restart counter in NVS ... ");
	       restart_counter++;
	       err = handle->set_item("restart_counter", restart_counter);
	       printf((err != ESP_OK) ? "Failed!\n" : "Done\n");

	       // Commit written value.
	       // After setting any values, nvs_commit() must be called to ensure changes are written
	       // to flash storage. Implementations may write to storage at other times,
	       // but this is not guaranteed.
	       printf("Committing updates in NVS ... ");
	       err = handle->commit();
	       printf((err != ESP_OK) ? "Failed!\n" : "Done\n");
	   }
	   vTaskDelay(1000 / portTICK_PERIOD_MS);
	   printf("\n");
	}

//	// Restart module
//	for (int i = 10; i >= 0; i--) {
//	    printf("Restarting in %d seconds...\n", i);
//	    vTaskDelay(1000 / portTICK_PERIOD_MS);
//	}
//	printf("Restarting now.\n");
//	fflush(stdout);
//	esp_restart();
}

void spiffsStorrageExample(void) {
//    ESP_LOGI(TAG, "Initializing SPIFFS");

    esp_vfs_spiffs_conf_t conf = {
      .base_path = "/spiffs",
      .partition_label = NULL,
      .max_files = 5,
      .format_if_mount_failed = true
    };

    // Use settings defined above to initialize and mount SPIFFS filesystem.
    // Note: esp_vfs_spiffs_register is an all-in-one convenience function.
    esp_err_t ret = esp_vfs_spiffs_register(&conf);

    if (ret != ESP_OK) {
        if (ret == ESP_FAIL) {
            ESP_LOGE(TAG, "Failed to mount or format filesystem");
        } else if (ret == ESP_ERR_NOT_FOUND) {
            ESP_LOGE(TAG, "Failed to find SPIFFS partition");
        } else {
            ESP_LOGE(TAG, "Failed to initialize SPIFFS (%s)", esp_err_to_name(ret));
        }
        return;
    }

    size_t total = 0, used = 0;
    ret = esp_spiffs_info(conf.partition_label, &total, &used);
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "Failed to get SPIFFS partition information (%s)", esp_err_to_name(ret));
    } else {
        ESP_LOGI(TAG, "Partition size: total: %d, used: %d", total, used);
    }

    // Use POSIX and C standard library functions to work with files.
    // First create a file.
    ESP_LOGI(TAG, "Opening file");
    FILE* f = fopen("/spiffs/hello.txt", "w");
    if (f == NULL) {
        ESP_LOGE(TAG, "Failed to open file for writing");
        return;
    }
    fprintf(f, "Hello World!\n");
    fclose(f);
    ESP_LOGI(TAG, "File written");

    // Check if destination file exists before renaming
    struct stat st;
    if (stat("/spiffs/foo.txt", &st) == 0) {
        // Delete it if it exists
        unlink("/spiffs/foo.txt");
    }

    // Rename original file
    ESP_LOGI(TAG, "Renaming file");
    if (rename("/spiffs/hello.txt", "/spiffs/foo.txt") != 0) {
        ESP_LOGE(TAG, "Rename failed");
        return;
    }

    // Open renamed file for reading
    ESP_LOGI(TAG, "Reading file");
    f = fopen("/spiffs/foo.txt", "r");
    if (f == NULL) {
        ESP_LOGE(TAG, "Failed to open file for reading");
        return;
    }
    char line[64];
    fgets(line, sizeof(line), f);
    fclose(f);
    // strip newline
    char* pos = strchr(line, '\n');
    if (pos) {
        *pos = '\0';
    }
    ESP_LOGI(TAG, "Read from file: '%s'", line);

    // All done, unmount partition and disable SPIFFS
    esp_vfs_spiffs_unregister(conf.partition_label);
    ESP_LOGI(TAG, "SPIFFS unmounted");
}


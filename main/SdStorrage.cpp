/*
 * SdStorrage.c
 *
 *  Created on: Apr 29, 2021
 *      Author: f73377
 */

#include "SdStorrage.h"

#include <stdio.h>
#include <string.h>
#include <sys/unistd.h>
#include <sys/stat.h>
#include "esp_err.h"
#include "esp_log.h"
#include "esp_vfs_fat.h"
#include "driver/sdspi_host.h"
#include "driver/spi_common.h"

static const char *TAG = "SdStorrage";

#define SPI_DMA_CHAN    1
#define PIN_NUM_CS  	22
#define PIN_NUM_CLK  	18
#define PIN_NUM_MISO 	19
#define PIN_NUM_MOSI 	23
#define MOUNT_POINT "/sdcard"

const char SdStorrage::mount_point[] = MOUNT_POINT;
sdmmc_card_t* SdStorrage::card = nullptr;



SdStorrage::SdStorrage(){

}

bool SdStorrage::init(){
	esp_err_t ret;
	esp_vfs_fat_sdmmc_mount_config_t mount_config = {
	    .format_if_mount_failed = false,
	    .max_files = 5,
	    .allocation_unit_size = 16 * 1024
	};
	sdmmc_card_t* card;
	ESP_LOGI(TAG, "Initializing SD card");
	ESP_LOGI(TAG, "Using SPI peripheral");

	sdmmc_host_t host = SDSPI_HOST_DEFAULT();
	host.slot = VSPI_HOST;
	spi_bus_config_t bus_cfg = {
	    .mosi_io_num = PIN_NUM_MOSI,
	    .miso_io_num = PIN_NUM_MISO,
	    .sclk_io_num = PIN_NUM_CLK,
	    .quadwp_io_num = -1,
	    .quadhd_io_num = -1,
	    .max_transfer_sz = 4000,
	};
	ret = spi_bus_initialize((spi_host_device_t)host.slot, &bus_cfg, SPI_DMA_CHAN);
	if (ret != ESP_OK) {
	    ESP_LOGE(TAG, "Failed to initialize bus.");
	    return false;
	}

	sdspi_device_config_t slot_config = SDSPI_DEVICE_CONFIG_DEFAULT();
	slot_config.gpio_cs = (gpio_num_t)PIN_NUM_CS;
	slot_config.host_id = (spi_host_device_t)host.slot;

	ret = esp_vfs_fat_sdspi_mount(mount_point, &host, &slot_config, &mount_config, &card);
	if (ret != ESP_OK) {
	    if (ret == ESP_FAIL) {
	        ESP_LOGE(TAG, "Failed to mount filesystem. "
	            "If you want the card to be formatted, set the EXAMPLE_FORMAT_IF_MOUNT_FAILED menuconfig option.");
	    } else {
	        ESP_LOGE(TAG, "Failed to initialize the card (%s). "
	            "Make sure SD card lines have pull-up resistors in place.", esp_err_to_name(ret));
	    }
	    return false;
	}

	sdmmc_card_print_info(stdout, card);
	return true;
}

void SdStorrage::start(){

}

void SdStorrage::run(){
	ESP_LOGI(TAG, "Opening file");
	FILE* f = fopen(MOUNT_POINT"/hello.txt", "w");
	if (f == NULL) {
	    ESP_LOGE(TAG, "Failed to open file for writing");
	    return;
	}
	fprintf(f, "Hello %s!\n", card->cid.name);
	fclose(f);
	ESP_LOGI(TAG, "File written");

	// Check if destination file exists before renaming
	struct stat st;
	if (stat(MOUNT_POINT"/foo.txt", &st) == 0) {
	    // Delete it if it exists
	    unlink(MOUNT_POINT"/foo.txt");
	}

	// Rename original file
	ESP_LOGI(TAG, "Renaming file");
	if (rename(MOUNT_POINT"/hello.txt", MOUNT_POINT"/foo.txt") != 0) {
	    ESP_LOGE(TAG, "Rename failed");
	    return;
	}

	// Open renamed file for reading
	ESP_LOGI(TAG, "Reading file");
	f = fopen(MOUNT_POINT"/foo.txt", "r");
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

	// All done, unmount partition and disable SDMMC or SPI peripheral
	esp_vfs_fat_sdcard_unmount(mount_point, card);
	ESP_LOGI(TAG, "Card unmounted");
}


void sdStorrageExample(void) {
    esp_err_t ret;
    esp_vfs_fat_sdmmc_mount_config_t mount_config = {
        .format_if_mount_failed = false,
        .max_files = 5,
        .allocation_unit_size = 16 * 1024
    };
    sdmmc_card_t* card;
    const char mount_point[] = MOUNT_POINT;
    ESP_LOGI(TAG, "Initializing SD card");
    ESP_LOGI(TAG, "Using SPI peripheral");

    sdmmc_host_t host = SDSPI_HOST_DEFAULT();
    host.slot = VSPI_HOST;
    spi_bus_config_t bus_cfg = {
        .mosi_io_num = PIN_NUM_MOSI,
        .miso_io_num = PIN_NUM_MISO,
        .sclk_io_num = PIN_NUM_CLK,
        .quadwp_io_num = -1,
        .quadhd_io_num = -1,
        .max_transfer_sz = 4000,
    };
    ret = spi_bus_initialize((spi_host_device_t)host.slot, &bus_cfg, SPI_DMA_CHAN);
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "Failed to initialize bus.");
        return;
    }

    sdspi_device_config_t slot_config = SDSPI_DEVICE_CONFIG_DEFAULT();
    slot_config.gpio_cs = (gpio_num_t)PIN_NUM_CS;
    slot_config.host_id = (spi_host_device_t)host.slot;

    ret = esp_vfs_fat_sdspi_mount(mount_point, &host, &slot_config, &mount_config, &card);
    if (ret != ESP_OK) {
        if (ret == ESP_FAIL) {
            ESP_LOGE(TAG, "Failed to mount filesystem. "
                "If you want the card to be formatted, set the EXAMPLE_FORMAT_IF_MOUNT_FAILED menuconfig option.");
        } else {
            ESP_LOGE(TAG, "Failed to initialize the card (%s). "
                "Make sure SD card lines have pull-up resistors in place.", esp_err_to_name(ret));
        }
        return;
    }

    // Card has been initialized, print its properties
    sdmmc_card_print_info(stdout, card);

    // Use POSIX and C standard library functions to work with files.
    // First create a file.
    ESP_LOGI(TAG, "Opening file");
    FILE* f = fopen(MOUNT_POINT"/hello.txt", "w");
    if (f == NULL) {
        ESP_LOGE(TAG, "Failed to open file for writing");
        return;
    }
    fprintf(f, "Hello %s!\n", card->cid.name);
    fclose(f);
    ESP_LOGI(TAG, "File written");

    // Check if destination file exists before renaming
    struct stat st;
    if (stat(MOUNT_POINT"/foo.txt", &st) == 0) {
        // Delete it if it exists
        unlink(MOUNT_POINT"/foo.txt");
    }

    // Rename original file
    ESP_LOGI(TAG, "Renaming file");
    if (rename(MOUNT_POINT"/hello.txt", MOUNT_POINT"/foo.txt") != 0) {
        ESP_LOGE(TAG, "Rename failed");
        return;
    }

    // Open renamed file for reading
    ESP_LOGI(TAG, "Reading file");
    f = fopen(MOUNT_POINT"/foo.txt", "r");
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

    // All done, unmount partition and disable SDMMC or SPI peripheral
    esp_vfs_fat_sdcard_unmount(mount_point, card);
    ESP_LOGI(TAG, "Card unmounted");
}


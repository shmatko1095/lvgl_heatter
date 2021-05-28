/*
 * SdStorrage.c
 *
 *  Created on: Apr 29, 2021
 *      Author: f73377
 */

#include "SpiFfsStorrage.h"
#include "esp_vfs.h"
#include "esp_vfs_fat.h"

#define PATH "/spiflash"
static const char *base_path = PATH;
static wl_handle_t s_wl_handle = WL_INVALID_HANDLE;

SpiFfsStorrage::SpiFfsStorrage() {
	init();
}

void SpiFfsStorrage::init() {
    const esp_vfs_fat_mount_config_t mount_config = {
    		.format_if_mount_failed = true,
			.max_files = 4,
			.allocation_unit_size = CONFIG_WL_SECTOR_SIZE};

    esp_err_t err = esp_vfs_fat_spiflash_mount(base_path, "storage", &mount_config, &s_wl_handle);
    if (err != ESP_OK) {
    	printf("Failed to mount FATFS (%s)\n", esp_err_to_name(err));
    }
}

void SpiFfsStorrage::deinit() {
	printf("End SpiFfsStorrage task, unmounting FAT filesystem\n");
	esp_vfs_fat_spiflash_unmount(base_path, s_wl_handle);
}

void vfsExample(void) {
    const esp_vfs_fat_mount_config_t mount_config = {4, true, CONFIG_WL_SECTOR_SIZE};
    esp_err_t err = esp_vfs_fat_spiflash_mount(base_path, "storage", &mount_config, &s_wl_handle);
    if (err != ESP_OK) {
    	printf("Failed to mount FATFS (%s)\n", esp_err_to_name(err));
        return;
    }
    printf("Opening file\n");
    FILE *f = fopen("/spiflash/hello.txt", "wb");
    if (f == NULL) {
        printf("Failed to open file for writing\n");
        return;
    }
    fprintf(f, "written using ESP-IDF %s\n", esp_get_idf_version());
    fclose(f);
    printf("File written\n");

    // Open file for reading
    printf("Reading file\n");
    f = fopen("/spiflash/hello.txt", "rb");
    if (f == NULL) {
        printf("Failed to open file for reading\n");
        return;
    }
    char line[128];
    fgets(line, sizeof(line), f);
    fclose(f);
    // strip newline
    char *pos = strchr(line, '\n');
    if (pos) {
        *pos = '\0';
    }
    printf("Read from file: '%s'\n", line);

    // Unmount FATFS
    printf("Unmounting FAT filesystem\n");
    ESP_ERROR_CHECK( esp_vfs_fat_spiflash_unmount(base_path, s_wl_handle));

    printf("Done\n");
}

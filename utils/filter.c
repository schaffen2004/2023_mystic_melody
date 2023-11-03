//
// Created by laphv on 9/1/2023.
//

#include "filter.h"

int checkFileExtension(char filePath[])
{
    int sat;
    // Khởi tạo môi trường magic
    magic_t magic = magic_open(MAGIC_MIME_TYPE);
    if (magic == NULL) {
        printf("Failed to initialize libmagic\n");
        return 1;
    }

    // Load các cấu hình của magic
    if (magic_load(magic, NULL) != 0) {
        printf("Failed to load magic database: %s\n", magic_error(magic));
        magic_close(magic);
        return 1;
    }


    // Kiểm tra loại tệp tin sử dụng magic
    const char* filetype = magic_file(magic, filePath);
    if (filetype == NULL) {
        printf("Failed to determine file type: %s\n", magic_error(magic));
        magic_close(magic);
        return 1;
    }

    // Kiểm tra xem file có phải là file âm thanh không
    if (strstr(filetype, "audio/") == filetype) {
        sat = 1;
    } else {
        sat = 0;
    }

    // Đóng môi trường magic
    magic_close(magic);

    return sat;
}

int isImageFile(const char *filename) {
    const char *extension = strrchr(filename, '.');
    if (extension != NULL) {
        if (strcmp(extension, ".jpg") == 0 || strcmp(extension, ".jpeg") == 0 ||
            strcmp(extension, ".png") == 0 || strcmp(extension, ".gif") == 0) {
            return 1; // Là tệp tin ảnh
        }
    }
    return 0; // Không phải tệp tin ảnh
}
int checkImage(char imagePath[])
{
    if (isImageFile(imagePath))
        return 1;
    return 0;

}
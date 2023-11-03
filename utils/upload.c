//
// Created by laphv on 9/1/2023.
//

#include "upload.h"

void saveSound(char nameOfSong[],char inputPath[])
{
    printf("Saving audio file...\n");
    FILE *input_file = fopen(inputPath, "rb");
    if (!input_file) {
        printf(">> Error opening input file\n");
        return;
    }
    char outputPath[] = "database\\songStorage\\";
    strcat(outputPath,nameOfSong);
    strcat(outputPath,".mp3");
    FILE *output_file = fopen(outputPath, "wb");
    if (!output_file) {
        printf(">> Error creating MP3 output file\n");
        fclose(input_file);
        return;
    }

    fseek(input_file, 0, SEEK_END);
    long input_size = ftell(input_file);
    rewind(input_file);

    char *input_buffer = (char *)malloc(input_size);
    if (!input_buffer) {
        printf(">> Memory allocation error\n");
        fclose(input_file);
        fclose(output_file);
        return;
    }

    fread(input_buffer, 1, input_size, input_file);
    fwrite(input_buffer, 1, input_size, output_file);

    free(input_buffer);
    fclose(input_file);
    fclose(output_file);

    printf(">> Saving audio file completely\n");
}

void saveImageSong(char nameOfSong[],char inputPath[])
{
    printf("Saving image file...\n");
    GdkPixbuf *pixbuf = gdk_pixbuf_new_from_file(inputPath, NULL);
    if (pixbuf == NULL) {
        g_print(">> Can not access the image\n");
        return;
    }
    char outputPath[] = "database\\avatarSong\\";
    strcat(outputPath,nameOfSong);
    strcat(outputPath,".jpg");
    gboolean success = gdk_pixbuf_save(pixbuf, outputPath, "jpeg", NULL, NULL);
    g_object_unref(pixbuf);

    if (success) {
        g_print(">> Save image completely\n");
    } else {
        g_print(">> Save fail\n");
    }
}

void saveImagePlaylist(char nameOfSong[],char inputPath[])
{
    printf("Saving image file...\n");
    GdkPixbuf *pixbuf = gdk_pixbuf_new_from_file(inputPath, NULL);
    if (pixbuf == NULL) {
        g_print(">> Can not access the image\n");
        return;
    }
    char outputPath[] = "database\\avatarPlaylist\\";
    strcat(outputPath,nameOfSong);
    strcat(outputPath,".jpg");
    gboolean success = gdk_pixbuf_save(pixbuf, outputPath, "jpeg", NULL, NULL);
    g_object_unref(pixbuf);

    if (success) {
        g_print(">> Save image completely\n");
    } else {
        g_print(">> Save fail\n");
    }
}
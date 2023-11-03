//
// Created by laphv on 8/27/2023.
//

#ifndef MUSIC_UPLOADTAB_H
#define MUSIC_UPLOADTAB_H
#include "gtk/gtk.h"
extern GtkWidget *label_song_upload, *entry_song_upload;
extern GtkWidget *label_artist_upload, *entry_artist_upload;
extern GtkWidget *label_image_upload, *image_file_upload,*notify;
extern GtkWidget *label_music_upload, *music_file_upload;
extern GtkWidget *upload_button,*upload_fixed,*windowUpload;

void uploadShow();

#endif //MUSIC_UPLOADTAB_H

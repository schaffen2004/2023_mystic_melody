//
// Created by laphv on 8/27/2023.
//

#ifndef MUSIC_UPDATEPLAYLIST_H
#define MUSIC_UPDATEPLAYLIST_H
#include "gtk/gtk.h"
#include <string.h>

extern GtkWidget *scrolled_window;
extern GtkWidget *container_box;
extern GtkWidget *provider;

GdkPixbuf* resize_image(const gchar* filename, gint width, gint height);

void createPlaylistShow();

#endif //MUSIC_UPDATEPLAYLIST_H

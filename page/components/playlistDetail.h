//
// Created by laphv on 9/4/2023.
//

#ifndef MUSIC_PLAYLISTDETAIL_H
#define MUSIC_PLAYLISTDETAIL_H
#include "gtk/gtk.h"
#include <string.h>
extern GtkWidget *scroll_Song;
extern GtkWidget *box;
extern GtkWidget *providerInp;
extern int del;
GdkPixbuf* resize(const gchar* filename, gint width, gint height);

void detailShow();

void songInPlaylist(GtkWidget *widget, gpointer data);

void addPlaylistNow();

#endif //MUSIC_PLAYLISTDETAIL_H

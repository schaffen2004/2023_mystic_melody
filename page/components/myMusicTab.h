//
// Created by laphv on 8/27/2023.
//

#ifndef MUSIC_MYMUSICTAB_H
#define MUSIC_MYMUSICTAB_H
#include "gtk/gtk.h"
#include <stdio.h>
extern int myMusicNum;
extern GtkWidget *myMusic_tab_fixed,
        *myMusic_scroll_view,
        *myMusic_grid,
        *myMusic_plus_button,
        *myMusic_plus_icon;

void myMusicShow();

void createAddFrame();

void createMyMusicFrame(char* song_image_path, char* title, char* artist);


gboolean button_press_event(GtkWidget *widget, GdkEventButton *event, gpointer data);

gboolean draw_myMusic_frame(GtkWidget *widget, cairo_t *cr, gpointer data);
#endif //MUSIC_MYMUSICTAB_H

//
// Created by laphv on 8/27/2023.
//

#ifndef MUSIC_EXPLORERTAB_H
#define MUSIC_EXPLORERTAB_H
#include "gtk/gtk.h"

extern int explorer_num;
extern GtkWidget *explorer_tab_fixed,
        *explorer_scroll_view,
        *explorer_grid,
        *explorer_plus_button,
        *explorer_plus_icon;

void explorerShow();

void createExplorerFrame(char* song_image_path, char* title, char* artist);

gboolean draw_explorer_frame(GtkWidget *widget, cairo_t *cr, gpointer data);

#endif //MUSIC_EXPLORERTAB_H

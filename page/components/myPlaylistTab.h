//
// Created by laphv on 8/27/2023.
//

#ifndef MUSIC_MYPLAYLISTTAB_H
#define MUSIC_MYPLAYLISTTAB_H
#include <gtk/gtk.h>
extern int id;

extern GtkWidget
        *playlist_tab_fixed,
        *playlist_scroll_view,
        *playlist_grid,
        *playlist_plus_button,
        *playlist_plus_icon;

extern char
        *selected_playlist_image_path,
        *selected_playlist_name,
        *selected_playlist_creator;

void playlistShow();
void my_playlist_tab_hide();
void createAddPlaylist();
gboolean draw_playlist_frame(GtkWidget *widget, cairo_t *cr, gpointer data);
void createPlaylistFrame(char* playlist_image_path, char* title, char* creator);
#endif //MUSIC_MYPLAYLISTTAB_H

//
// Created by laphv on 8/26/2023.
//

#ifndef MUSIC_HOMEPAGE_H
#define MUSIC_HOMEPAGE_H
#include "gtk/gtk.h"

extern GtkWidget *providerHome;
extern GtkStyleContext *styleContextHome;
extern GtkWidget
        *homeView,
        *fixedHome,
        *scrolledHome,
        *rect_area,
        *tab_label;
extern GtkWidget
        *explorer_button,
        *library_button,
        *myMusic_button,
        *logout_button,
        *explorer_icon,
        *library_icon,
        *myMusic_icon,
        *logout_icon;
extern GtkWidget
        *entry_search_bar,
        *exit_button,
        *exit_icon,
        *search_icon;
extern GtkWidget *providerHeaderBar;
extern GtkStyleContext *styleContextHeaderBar;
extern GtkWidget *progress_bar,*song_label,*artist_label,*image_song_avatar,*play_icon,*play_song_image,*stop_song_image;
extern GtkWidget *time_label;
void homePageShow();

#endif //MUSIC_HOMEPAGE_H

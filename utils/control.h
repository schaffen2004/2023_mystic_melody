//
// Created by laphv on 9/3/2023.
//

#ifndef MUSIC_CONTROL_H
#define MUSIC_CONTROL_H
#include "gtk/gtk.h"

void explorerTab();

void change_tab_label(char *label_string);

gboolean update_time_label(gpointer user_data);

gboolean startSong(GtkWidget *widget, GdkEventButton *event, gpointer data);

void playSong();


void secondsToHMS(int seconds);

void stopMusic();

void togglePlay();

void reInitTab();

void myMusicTab();

void playlistTab();

void signOutClicked();

void uploadSong();
#endif //MUSIC_CONTROL_H

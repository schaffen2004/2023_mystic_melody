//
// Created by laphv on 8/27/2023.
//

#ifndef MUSIC_SONGQUERY_H
#define MUSIC_SONGQUERY_H
#include <sqlite3.h>
#include <stdio.h>
#include "gtk/gtk.h"
#define OK 0
#define FAIL 1
#define ADD_OK 0
#define ADD_FAIL 1

extern char nameOfItArtist[PATH_MAX];

void listExplorer();

int artistName(char song[]);

void listMySong();

int add_song(char name[],char artist[],char user[],int durationOfSong);

#endif //MUSIC_SONGQUERY_H

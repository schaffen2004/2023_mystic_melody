//
// Created by laphv on 8/28/2023.
//

#ifndef MUSIC_LISTOFSONG_H
#define MUSIC_LISTOFSONG_H
#include <stdio.h>
#include <glib.h>

extern GPtrArray* currentPlayList;
extern GPtrArray* listSong;
extern char currSongMame[PATH_MAX];
extern char namePlaylist[PATH_MAX];
extern GPtrArray* nextSong;
extern int location;
extern int list;


void initList();



void addNewSong(char nameSong[]);


#endif //MUSIC_LISTOFSONG_H

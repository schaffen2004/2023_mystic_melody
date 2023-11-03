//
// Created by laphv on 9/1/2023.
//

#ifndef MUSIC_PLAYLISTQUERY_H
#define MUSIC_PLAYLISTQUERY_H
#include <sqlite3.h>
#include <stdio.h>
#include "gtk/gtk.h"
#define OK 0
#define FAIL 1

#define NO 2

void listPlaylist();

int checkPlaylistInDatabase(char namePlaylist[], char userInit[]);

int addPlaylistToDatabase(char namePlaylist[], char userInit[]);

int listPlaylistDetail();

int addSongToPlaylist(char namePlaylist[], char nameSong[]);

int checkSongInPlaylist(char namePlaylist[],char nameSong[]);

#endif //MUSIC_PLAYLISTQUERY_H

//
// Created by laphv on 8/28/2023.
//

#include "listOfSong.h"

GPtrArray* currentPlayList;
GPtrArray* listSong;
int location;
int list = 0;
char currSongMame[PATH_MAX];
char namePlaylist[PATH_MAX];

void initList()
{
    currentPlayList = g_ptr_array_new();
}
void addNewSong(char newSong[])
{
    g_ptr_array_add(currentPlayList, newSong);
}
//
// Created by laphv on 9/3/2023.
//

#include "sys.h"

char currSong[PATH_MAX];
int statusPlaying;
int timeCounter;
int duration;
char textTime[PATH_MAX];
int statusProcess;
int tabStatus;

GPtrArray* playlistDetail;
char songOfPlaylist[PATH_MAX];
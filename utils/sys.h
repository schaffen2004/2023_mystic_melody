//
// Created by laphv on 9/3/2023.
//

#ifndef MUSIC_SYS_H
#define MUSIC_SYS_H
#include "limits.h"
#include "glib.h"

#define STOP 0
#define PLAY 1

extern char currSong[PATH_MAX];
extern int statusPlaying;
extern int timeCounter;
extern int duration;
extern char textTime[PATH_MAX];

#define NOT_STARTED 0
#define RUN 1

extern int statusProcess;

#define EXPLORER 1
#define MY_MUSIC 2
#define PLAYLIST 3

extern int tabStatus;

extern GPtrArray* playlistDetail;

extern char songOfPlaylist[PATH_MAX];

#endif //MUSIC_SYS_H

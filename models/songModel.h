//
// Created by laphv on 9/1/2023.
//

#ifndef MUSIC_SONGMODEL_H
#define MUSIC_SONGMODEL_H
#include <mpg123.h>
#include <magic.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
extern int du;
extern char nameOfSong[PATH_MAX];
extern char nameOfArtist[PATH_MAX];
extern char userPost[PATH_MAX];
extern int durationOfSong;


int getDurationSong(char pathOfSong[]);
#endif //MUSIC_SONGMODEL_H

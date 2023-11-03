//
// Created by laphv on 9/1/2023.
//

#ifndef MUSIC_UPLOAD_H
#define MUSIC_UPLOAD_H
#include "gtk/gtk.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lame/lame.h"
#include <jpeglib.h>

void saveSound(char nameOfSong[],char inputPath[]);

void saveImageSong(char nameOfSong[],char inputPath[]);

void saveImagePlaylist(char nameOfSong[],char inputPath[]);

#endif //MUSIC_UPLOAD_H

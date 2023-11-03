//
// Created by laphv on 8/26/2023.
//

#ifndef MUSIC_INTROPAGE_H
#define MUSIC_INTROPAGE_H
#include "gtk/gtk.h"

extern GtkWidget *introView,*introLogo;
extern GdkPixbuf *accessIntroLogo;
extern GtkStyleContext *styleContextIntro;

void introShow();

#endif //MUSIC_INTROPAGE_H

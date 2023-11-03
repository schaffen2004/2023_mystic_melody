//
// Created by laphv on 8/26/2023.
//

#ifndef MUSIC_USERQUERY_H
#define MUSIC_USERQUERY_H
#include <limits.h>
#include <sqlite3.h>
#include<stdio.h>
#include <string.h>

#define LOGIN_OK 0
#define LOGIN_FAIL 1
#define SIGNUP_OK 0
#define SIGNUP_FAIL 1

extern char username_current[PATH_MAX];

int checkSignIn(char username[],char password[]);

int addAccount(char username[], char password[]);

#endif //MUSIC_USERQUERY_H

//
// Created by laphv on 8/26/2023.
//

#include "userModel.h"

char username[PATH_MAX];



void setUserName(char changeValue[])
{
    strcpy(username,changeValue);
    printf("Setting account info\n");
}




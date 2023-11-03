#include <stdio.h>
#include "page/IntroPage.h"

int main(int argc, char *argv[]) {

    printf("Starting...\n");

    //khai báo gtk
    gtk_init(&argc, &argv);

    //hiển thị intro view
    introShow();

    return 0;

}

//
// Created by laphv on 9/1/2023.
//

#include "songModel.h"
#include <stdio.h>
char nameOfSong[PATH_MAX];
char nameOfArtist[PATH_MAX];
int durationOfSong;
int du;
void setSongProperties(char newNameOfSong[], char newNameOfArtist, int newDuration)
{
    strcpy(nameOfSong,newNameOfSong);
    strcpy(nameOfArtist,newNameOfArtist);
    durationOfSong = newDuration;
}

int getDurationSong(char pathOfSong[]) {

    mpg123_init();
    mpg123_handle *mh = mpg123_new(NULL, NULL);

    // Mở tệp tin MP3
    int err = mpg123_open(mh, pathOfSong);
    if (err != MPG123_OK) {
        printf("Không thể mở tệp tin.\n");
        return 1;
    }

    // Lấy tổng số mẫu âm thanh
    off_t num_samples = mpg123_length(mh);

    // Lấy tốc độ mẫu
    long rate;
    mpg123_getformat(mh, &rate, NULL, NULL);

    // Tính số giây dựa trên tổng số mẫu và tốc độ mẫu
    double seconds = (double)num_samples / (double)rate;
    int result = (int) floor(seconds);
    du = result;

    // Giải phóng bộ nhớ và đóng tệp tin
    mpg123_close(mh);
    mpg123_delete(mh);
    mpg123_exit();

}
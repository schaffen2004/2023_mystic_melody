//
// Created by laphv on 9/3/2023.
//

#include "control.h"
#include "page//components/explorerTab.h"
#include "page/HomePage.h"
#include "utils/sys.h"
#include "query/songQuery.h"
#include <windows.h>
#include <mmsystem.h>
#include "models/songModel.h"
#include "page/components/myPlaylistTab.h"
#include "page/components/myMusicTab.h"
#include "page/SignInPage.h"
#include "page/components/uploadTab.h"
#include "utils/upload.h"
#include "utils/filter.h"
#include "query/userQuery.h"
#include "models/userModel.h"
#include "models/listOfSong.h"
#include "page/components/addToPlaylist.h"
#include "page/components/playlistDetail.h"
#include <cairo.h>
#pragma comment(lib, "winmm.lib")



void reInitTab()
{
    if(tabStatus == EXPLORER)
    {
        gtk_widget_destroy(explorer_tab_fixed);
        tabStatus = 0;
    }
    if(tabStatus == MY_MUSIC)
    {
        gtk_widget_destroy(myMusic_tab_fixed);
        tabStatus = 0;
    }
    if(tabStatus == PLAYLIST)
    {
        gtk_widget_destroy(playlist_tab_fixed);
        tabStatus = 0;
    }

}
void explorerTab()
{
    reInitTab();
    tabStatus = EXPLORER;
    change_tab_label("Explorer");
    explorerShow();
}

void myMusicTab()
{
    reInitTab();
    tabStatus = MY_MUSIC;
    change_tab_label("My Music");
    myMusicShow();
}

void playlistTab()
{
    reInitTab();
    tabStatus = PLAYLIST;
    change_tab_label("Playlist");
    playlistShow();
}
void change_tab_label(char *label_string) {
    GdkRGBA color_tab_label;
    gdk_rgba_parse(&color_tab_label, "white");

    // Thay đổi nội dung label
    gtk_label_set_text(GTK_LABEL(tab_label), label_string);
    gtk_widget_override_color(tab_label, GTK_STATE_NORMAL, &color_tab_label);

    // Lấy layout của label
    PangoLayout *layout = gtk_label_get_layout(GTK_LABEL(tab_label));

    // Thay đổi kích thước và độ đậm của label
    PangoFontDescription *font_desc = pango_font_description_new();
    pango_font_description_set_weight(font_desc, PANGO_WEIGHT_BOLD);
    pango_font_description_set_size(font_desc, 24 * PANGO_SCALE);
    pango_layout_set_font_description(layout, font_desc);
}
void secondsToHMS(int seconds) {
    int hours, minutes, secs;

    hours = seconds / 3600; // 1 giờ có 3600 giây
    seconds %= 3600;
    minutes = seconds / 60; // 1 phút có 60 giây
    seconds %= 60;
    secs = seconds;

    sprintf(textTime, "%02d:%02d:%02d", hours, minutes, secs);
}

gboolean update_time_label(gpointer user_data) {
    if(statusPlaying == PLAY)
    {
        timeCounter += 1;
        secondsToHMS(timeCounter);
        gtk_label_set_text(time_label, textTime);
        float value = (float)timeCounter/duration;
        gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progress_bar), value);
        if(timeCounter == duration)
        {
            stopMusic();
            location+=1;
            // Lấy độ dài của GPtrArray
            guint length = listSong->len;
            if(location < length)
            {
                timeCounter = 0;
                char temp [PATH_MAX];
                char* str = g_ptr_array_index(listSong, location);
                strcpy(temp,"database\\songStorage\\");
                strcat(temp,str);
                strcat(temp,".mp3");
                getDurationSong(temp);
                duration = du;
                playSong();
            }
        }
    }
    return G_SOURCE_CONTINUE;
}

gboolean startSong(GtkWidget *widget, GdkEventButton *event, gpointer data) {
    del = 1;
    char *title = (char *) data;
    if (event->button == 1) {

        timeCounter = 0;
        statusPlaying = PLAY;
        gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progress_bar), 0.0);

        location = 0;
        listSong = g_ptr_array_new();
        g_ptr_array_add(listSong, title);

        strcpy(currSong,title);
        char temp [PATH_MAX];
        strcpy(temp,"database\\songStorage\\");
        strcat(temp,currSong);
        strcat(temp,".mp3");
        getDurationSong(temp);
        duration = du;
        if(statusProcess == NOT_STARTED)
        {
            g_timeout_add_seconds(1, update_time_label, NULL);
            statusProcess = RUN;
        }
        playSong();
    } else if (event->button == 3) {
        addToPlaylistShow(title);
    }
}



void playSong()
{
    statusPlaying = PLAY;
    char temp[PATH_MAX];
    gchar* song = g_ptr_array_index(listSong, location);

    strcpy(temp,"database\\avatarSong\\");
    strcat(temp,song);
    strcat(temp,".jpg");

    gtk_widget_destroy(image_song_avatar);
    GError *error = NULL;
    GdkPixbuf *pixbuf = gdk_pixbuf_new_from_file(temp, &error);
    if (error) {
        g_printerr("Error loading file: %s\n", error->message);
        g_error_free(error);
    }

    GdkPixbuf *scaled_pixbuf = gdk_pixbuf_scale_simple(pixbuf, 140, 140, GDK_INTERP_BILINEAR);
    image_song_avatar = gtk_image_new_from_pixbuf(scaled_pixbuf);
    gtk_fixed_put(GTK_FIXED(fixedHome), image_song_avatar, 0, 680);


    gtk_widget_show(image_song_avatar);
    gtk_widget_show(artist_label);
    gtk_widget_show(song_label);

    gtk_image_set_from_file(play_song_image, "assets/stop_button.svg");
    gtk_label_set_text(GTK_LABEL(song_label), song);
    artistName(song);
    gtk_label_set_text(GTK_LABEL(artist_label), nameOfItArtist);
    // Đóng tập tin nhạc
    mciSendString("close music", NULL, 0, NULL);

    char music[PATH_MAX];
    strcpy(music, "open \"");
    strcat(music, "database\\songStorage\\");
    strcat(music, song);
    strcat(music, ".mp3");
    strcat(music, "\" type mpegvideo alias music");
    // Mở tập tin nhạc
    mciSendString(music, NULL, 0, NULL);

    char cont[PATH_MAX], pn[PATH_MAX];

    int tg = timeCounter;
    tg = tg * 1000;

    sprintf(cont, "%d", tg);

    strcpy(pn, "seek music to ");
    strcat(pn, cont);
    // Tua đến thời điểm
    mciSendString(pn, NULL, 0, NULL);
    // Tiếp tục phát nhạc
    mciSendString("play music", NULL, 0, NULL);
}

void stopMusic() {
    statusPlaying = NOT_STARTED;
    gtk_image_set_from_file(play_song_image, "assets/play_button.svg");
    // Đóng tập tin nhạc
    mciSendString("close music", NULL, 0, NULL);
}

void togglePlay()
{
    if(statusPlaying == STOP || statusPlaying == NOT_STARTED)
    {

        if(timeCounter >= duration)
        {
            printf("1\n");
            timeCounter = 0;
        }
        if(listSong != NULL && del == 1)
        {
            playSong();
        }
    }
    else
    {
        stopMusic();
    }
}

void signOutClicked()
{
    tabStatus = 0;
    stopMusic();
    statusPlaying = STOP;
    char filename[] = "database\\Temp.txt";
    FILE *fileCheck = fopen(filename, "r");
    if (fileCheck  == NULL) {
        perror("Error opening file");
        return;
    }

    if (fseek(fileCheck , 0, SEEK_END) != 0) {
        perror("Error seeking file");
        fclose(fileCheck );
        return;
    }

    long fileSize = ftell(fileCheck );
    if (fileSize == 0) {
        g_timeout_add_seconds(0, (GSourceFunc) gtk_widget_destroy, homeView);
        g_timeout_add_seconds(0, (GSourceFunc) signInShow, homeView);
        fclose(fileCheck);
        return;
    }

    // Mở file Temp.txt ở chế độ ghi ("w" - write mode)
    FILE *file = fopen("database\\Temp.txt", "w");

    if (file == NULL) {
        printf(">> Can not open file Temp\n");
        return; // Thoát khỏi chương trình với mã lỗi
    }

    // Đóng file ngay sau khi mở để xóa hết nội dung
    fclose(file);

    printf("Clear all data in file Temp.txt\n");

    g_timeout_add_seconds(0, (GSourceFunc) gtk_widget_destroy, homeView);
    g_timeout_add_seconds(0, (GSourceFunc) signInShow, homeView);
}

void uploadSong()
{
    const char *song_name = gtk_entry_get_text(GTK_ENTRY(entry_song_upload));
    const char *artist_name = gtk_entry_get_text(GTK_ENTRY(entry_artist_upload));
    const char *src_path_image = gtk_file_chooser_get_filename(image_file_upload);
    const char *src_path_audio = gtk_file_chooser_get_filename(music_file_upload);

    if (checkFileExtension(src_path_audio) == 0) {
        gtk_label_set_text(GTK_LABEL(notify), "Format of file audio is invalid!");
    } else {
        if (checkImage(src_path_image) == 0) {
            gtk_label_set_text(GTK_LABEL(notify), "Format of file image is invalid!");
        } else {
            getDurationSong(src_path_audio);
            int durationTemp = du;

            if (add_song(song_name, artist_name, username,durationTemp) == ADD_OK);
            {

                saveSound(song_name,src_path_audio);
                saveImageSong(song_name,src_path_image);
            }
            gtk_label_set_text(GTK_LABEL(notify), "Success");
            g_timeout_add_seconds(1, (GSourceFunc) gtk_widget_destroy, windowUpload);
        }
    }
}
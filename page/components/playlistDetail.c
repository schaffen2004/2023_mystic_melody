//
// Created by laphv on 9/4/2023.
//

#include "playlistDetail.h"
#include "query/playlistQuery.h"
#include "utils/sys.h"
#include "models/listOfSong.h"
#include "utils/control.h"
#include "page/HomePage.h"
#include "models/songModel.h"

GtkWidget *scroll_Song;
GtkWidget *box;
GtkWidget *providerInp;
GtkWidget *detail;
GtkStyleContext *styleContext;
GtkWidget *playlistSong;
GtkWidget *image_playlist_detail;
int songNumber;
int del;

GdkPixbuf *resize(const gchar *filename, gint width, gint height) {
    GdkPixbuf *pixbuf = gdk_pixbuf_new_from_file(filename, NULL);
    GdkPixbuf *resized_pixbuf = gdk_pixbuf_scale_simple(pixbuf, width, height, GDK_INTERP_BILINEAR);
    g_object_unref(pixbuf);
    return resized_pixbuf;
}

void songInPlaylist(GtkWidget *widget, gpointer data) {

    char *temp = (char *) data;
    strcpy(namePlaylist, temp);
    detailShow();
}

void addPlaylistNow() {
    listSong = g_ptr_array_new();
    location = 0;
    del = 0;
    if (songNumber != 0) {
        del = 1;
        for (guint i = 0; i < currentPlayList->len; i++) {
            char *str = g_ptr_array_index(currentPlayList, i);
            g_ptr_array_add(listSong, str);
        }
        timeCounter = 0;
        statusPlaying = PLAY;
        gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progress_bar), 0.0);

        char temp[PATH_MAX];
        char *str = g_ptr_array_index(listSong, 0);
        strcpy(temp, "database\\songStorage\\");
        strcat(temp, str);
        strcat(temp, ".mp3");
        getDurationSong(temp);
        duration = du;
        if (statusProcess == NOT_STARTED) {
            g_timeout_add_seconds(1, update_time_label, NULL);
            statusProcess = RUN;
        }

        // Sử dụng hàm kiểm tra số phần tử
        playSong();
    }
    else
    {
        if(statusPlaying == PLAY)
        {
            stopMusic();
        }
        listSong = g_ptr_array_new();
    }
}

void detailShow() {
    // Tạo một cửa sổ mới
    detail = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(detail), "Create new playlist");
    gtk_window_set_default_size(GTK_WINDOW(detail), 846, 450);
    gtk_window_set_position(GTK_WINDOW(detail), GTK_WIN_POS_CENTER);

    // Tạo GtkstyleContextSignIn cho cửa sổ intro
    styleContext = gtk_widget_get_style_context(detail);

    // Áp dụng các thuộc tính CSS tùy chỉnh cho cửa sổ intro
    gtk_style_context_add_class(styleContext, "add-window");

    // Đăng ký bộ chọn CSS
    providerInp = gtk_css_provider_new();
    gtk_css_provider_load_from_path(providerInp, "assets\\css\\Style.css", NULL);
    gtk_style_context_add_provider(styleContext, GTK_STYLE_PROVIDER(providerInp),
                                   GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);

    // Load tệp CSS
    gtk_css_provider_load_from_path(providerInp, "assets\\css\\Style.css", NULL);

    // Tạo một đối tượng fixed container
    GtkWidget *fixed = gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(detail), fixed);

    GdkPixbuf *pixbuf = gdk_pixbuf_new_from_file("assets\\play_playlist.png", NULL);
    GdkPixbuf *scaled_pixbuf = gdk_pixbuf_scale_simple(pixbuf, 60, 60, GDK_INTERP_BILINEAR);
    GtkWidget *play_pause_image = gtk_image_new_from_pixbuf(scaled_pixbuf);
    gtk_fixed_put(GTK_FIXED(fixed), play_pause_image, 41, 350);
    GtkWidget *play_pause_button = gtk_button_new();
    gtk_widget_set_size_request(play_pause_button, 60, 60);
    gtk_fixed_put(GTK_FIXED(fixed), play_pause_button, 41, 350);
    gtk_button_set_relief(GTK_BUTTON(play_pause_button), GTK_RELIEF_NONE);
    g_signal_connect(play_pause_button, "clicked", G_CALLBACK(addPlaylistNow), NULL);


    GdkPixbuf *pixbuf_del = gdk_pixbuf_new_from_file("assets\\delete.png", NULL);
    GdkPixbuf *scaled_pixbuf_del = gdk_pixbuf_scale_simple(pixbuf_del, 60, 60, GDK_INTERP_BILINEAR);
    GtkWidget *del_image = gtk_image_new_from_pixbuf(scaled_pixbuf_del);
    gtk_fixed_put(GTK_FIXED(fixed), del_image, 180, 350);
    GtkWidget *del_button = gtk_button_new();
    gtk_widget_set_size_request(del_button, 60, 60);
    gtk_fixed_put(GTK_FIXED(fixed), del_button, 180, 350);
    gtk_button_set_relief(GTK_BUTTON(del_button), GTK_RELIEF_NONE);

    //Label playlistSong
    playlistSong = gtk_label_new(namePlaylist);
    gtk_widget_set_size_request(playlistSong, 401, 48);
    gtk_fixed_put(GTK_FIXED(fixed), playlistSong, 223, 12);
    gtk_widget_set_name(playlistSong, "Create_Playlist");
    gtk_style_context_add_provider(gtk_widget_get_style_context(playlistSong), GTK_STYLE_PROVIDER(providerInp),
                                   GTK_STYLE_PROVIDER_PRIORITY_USER);

    //box2
//    GtkWidget *box2 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    scroll_Song = gtk_scrolled_window_new(NULL, NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scroll_Song), GTK_POLICY_AUTOMATIC, GTK_POLICY_ALWAYS);
    gtk_widget_set_size_request(scroll_Song, 361, 341);
    gtk_fixed_put(GTK_FIXED(fixed), scroll_Song, 472, 90);
    gtk_widget_set_name(scroll_Song, "scrolled_window");
    gtk_style_context_add_provider(gtk_widget_get_style_context(scroll_Song), GTK_STYLE_PROVIDER(providerInp),
                                   GTK_STYLE_PROVIDER_PRIORITY_USER);

    //Image_Playlist
    GtkWidget *Image_Playlist = gtk_image_new();
    gtk_widget_set_size_request(Image_Playlist, 200, 200);
    gtk_fixed_put(GTK_FIXED(fixed), Image_Playlist, 41, 106);
    gtk_widget_set_name(Image_Playlist, "Image_Playlist");
    gtk_style_context_add_provider(gtk_widget_get_style_context(Image_Playlist), GTK_STYLE_PROVIDER(providerInp),
                                   GTK_STYLE_PROVIDER_PRIORITY_USER);

    //Label_Recommend_Songs
    GtkWidget *Label_Recommend_Songs = gtk_label_new("");
    gtk_widget_set_size_request(Label_Recommend_Songs, 268, 25);
    gtk_fixed_put(GTK_FIXED(fixed), Label_Recommend_Songs, 518, 106);
    gtk_widget_set_name(Label_Recommend_Songs, "Label_Recommend_Songs");
    gtk_style_context_add_provider(gtk_widget_get_style_context(Label_Recommend_Songs), GTK_STYLE_PROVIDER(providerInp),
                                   GTK_STYLE_PROVIDER_PRIORITY_USER);

    char temp[PATH_MAX];
    strcpy(temp, "database\\avatarPlaylist\\");
    strcat(temp, namePlaylist);
    strcat(temp, ".jpg");

    // Thay đổi kích thước hình ảnh và hiển thị nó trong GtkImage
    GdkPixbuf *resized_pixbuf = resize(temp, 200, 200);
    gtk_image_set_from_pixbuf(GTK_IMAGE(Image_Playlist), resized_pixbuf);
    g_object_unref(resized_pixbuf);


    // Tạo một Vertical Box (VBox) để chứa danh sách playlist
    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_container_set_border_width(GTK_CONTAINER(vbox), 10);

    initList();
    listPlaylistDetail();
    songNumber = 0;
    for (guint i = 0; i < currentPlayList->len; i++) {
        songNumber +=1;
        char *str = g_ptr_array_index(currentPlayList, i);
        //Tạo một Box để chứa hình ảnh và thông tin playlist
        GtkWidget *hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);

        char temp[PATH_MAX];
        strcpy(temp, "database\\avatarSong\\");
        strcat(temp, str);
        strcat(temp, ".jpg");

        // Thêm ảnh playlist bên trái với kích thước 10x10px
        GdkPixbuf *pixbuf = gdk_pixbuf_new_from_file(temp, NULL);
        GdkPixbuf *scaled_pixbuf = gdk_pixbuf_scale_simple(pixbuf, 80, 80, GDK_INTERP_BILINEAR);
        GtkWidget *image = gtk_image_new_from_pixbuf(scaled_pixbuf);
        gtk_box_pack_start(GTK_BOX(hbox), image, FALSE, FALSE, 0);

        // Thêm thông tin playlist bên phải
        char label_text[256];
        snprintf(label_text, sizeof(label_text), "%s",
                 str);
        GtkWidget *label = gtk_label_new(label_text);
        gtk_box_pack_start(GTK_BOX(hbox), label, TRUE, TRUE, 0);

        // Thiết lập màu chữ của GtkLabel thành màu trắng
        GdkRGBA white_color = {1.0, 1.0, 1.0, 1.0};
        gtk_widget_override_color(label, GTK_STATE_FLAG_NORMAL, &white_color);

        // Tạo một viền bao
        GtkWidget *frame = gtk_frame_new(NULL);
//        gtk_frame_set_shadow_type(GTK_FRAME(frame), GTK_SHADOW_ETCHED_IN);
        gtk_container_add(GTK_CONTAINER(frame), hbox);

        gtk_container_add(GTK_CONTAINER(vbox), frame);
    }

    // Đặt VBox làm nội dung của Scroll Window
    gtk_container_add(GTK_CONTAINER(scroll_Song), vbox);

    gtk_widget_show_all(detail);
    gtk_main();
}
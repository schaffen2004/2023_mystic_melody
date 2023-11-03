//
// Created by laphv on 8/27/2023.
//

#include "myPlaylistTab.h"
#include "page/HomePage.h"
#include "page/components/myPlaylistTab.h"
#include "models/listOfSong.h"
#include "query/playlistQuery.h"
#include "page/components/playlistDetail.h"
#include "page/components/updatePlaylist.h"
// Biến toàn cục
int id;

GtkWidget
        *playlist_tab_fixed,
        *playlist_scroll_view,
        *playlist_grid,
        *playlist_plus_button,
        *playlist_plus_icon;

char
        *selected_playlist_image_path,
        *selected_playlist_name,
        *selected_playlist_creator;

void playlistShow()
{
    id = 0;
    // Khởi tạo playlist_tab_fixed
    playlist_tab_fixed = gtk_fixed_new();
    gtk_fixed_put(GTK_FIXED(fixedHome), playlist_tab_fixed, 0, 0);


    // Khởi playlist_scroll_view
    int
            scroll_view_width = 400,
            scroll_view_height = 480;

    playlist_scroll_view = gtk_scrolled_window_new(NULL, NULL);
    gtk_fixed_put(GTK_FIXED(playlist_tab_fixed), playlist_scroll_view, 160, 200);
    gtk_widget_set_size_request(playlist_scroll_view, scroll_view_width, scroll_view_height);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(playlist_scroll_view), GTK_POLICY_NEVER, GTK_POLICY_AUTOMATIC);

    // Khởi tạo playlist_grid
    playlist_grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(playlist_scroll_view), playlist_grid);
    gtk_widget_set_size_request(playlist_grid, scroll_view_width, scroll_view_height);
    gtk_grid_set_row_spacing(GTK_GRID(playlist_grid), 50);
    gtk_grid_set_column_spacing(GTK_GRID(playlist_grid), 50);
    gtk_grid_set_row_homogeneous(GTK_GRID(playlist_grid), TRUE);
    gtk_grid_set_column_homogeneous(GTK_GRID(playlist_grid), TRUE);

    // Ví dụ tạo các playlist frames
    // Gọi createPlaylistFrame() cho mỗi playlist trong database

    initList();
    listPlaylist();
    createAddPlaylist();
    for (guint i = 0; i < currentPlayList->len; i++) {
        char* str = g_ptr_array_index(currentPlayList, i);
        createPlaylistFrame("assets\\test.png", str, "Nhat");
    }

    // Hiển thị playlist_tab_fixed
    gtk_widget_show_all(playlist_tab_fixed);
}

void my_playlist_tab_hide()
{
    // Xóa playlist_tab_fixed
    gtk_widget_destroy(playlist_tab_fixed);
}

void createAddPlaylist() {
    // Tạo frame cho mỗi song
    GtkWidget *playlist_frame = gtk_fixed_new();
    gtk_widget_set_size_request(playlist_frame, 200, 250);
    gtk_grid_attach(GTK_GRID(playlist_grid), playlist_frame, id % 5, id / 5, 1, 1);

    // Tạo vùng để vẽ hcn cho mỗi frame
    GtkWidget *song_frame_dr_a = gtk_drawing_area_new();
    gtk_widget_set_size_request(song_frame_dr_a, 200, 250);
    gtk_fixed_put(GTK_FIXED(playlist_frame), song_frame_dr_a, 0, 0);
    g_signal_connect(song_frame_dr_a, "draw", G_CALLBACK(draw_playlist_frame), NULL);

    // Tạo button cho mỗi frame
    GtkWidget *song_frame_button = gtk_button_new();
    gtk_widget_set_size_request(song_frame_button, 200, 250);
    gtk_fixed_put(GTK_FIXED(playlist_frame), song_frame_button, 0, 0);
    gtk_button_set_relief(GTK_BUTTON(song_frame_button), GTK_RELIEF_NONE);
    g_signal_connect(song_frame_button, "clicked", G_CALLBACK(createPlaylistShow),NULL);



    // Tạo image cho mỗi frame
    GError *error = NULL;
    GdkPixbuf *pixbuf = gdk_pixbuf_new_from_file("assets/add.png", &error);
    if (error) {
        g_printerr("Error loading file: %s\n", error->message);
        g_error_free(error);
    }
    GdkPixbuf *scaled_pixbuf = gdk_pixbuf_scale_simple(pixbuf, 160, 160, GDK_INTERP_BILINEAR);
    GtkWidget *playlist_frame_image = gtk_image_new_from_pixbuf(scaled_pixbuf);
    gtk_fixed_put(GTK_FIXED(playlist_frame), playlist_frame_image, 20, 20);

    // Tạo labels cho mỗi frame
    GtkWidget *song_frame_title_label = gtk_label_new("ADD NEW PLAYLIST");
    gtk_fixed_put(GTK_FIXED(playlist_frame), song_frame_title_label, 20, 190);
    gtk_widget_set_size_request(song_frame_title_label, 160, 30);
    gtk_label_set_xalign(song_frame_title_label, 0);

    // Tăng số lượng song
    id++;
}

// Create playlist_frame
void createPlaylistFrame(char* playlist_image_path, char* title, char* creator) {
    // Tạo frame cho mỗi song
    GtkWidget *playlist_frame = gtk_fixed_new();
    gtk_widget_set_size_request(playlist_frame, 200, 250);
    gtk_grid_attach(GTK_GRID(playlist_grid), playlist_frame, id % 5, id / 5, 1, 1);

    // Tạo vùng để vẽ hcn cho mỗi frame
    GtkWidget *song_frame_dr_a = gtk_drawing_area_new();
    gtk_widget_set_size_request(song_frame_dr_a, 200, 250);
    gtk_fixed_put(GTK_FIXED(playlist_frame), song_frame_dr_a, 0, 0);
    g_signal_connect(song_frame_dr_a, "draw", G_CALLBACK(draw_playlist_frame), NULL);

    // Tạo button cho mỗi frame
    GtkWidget *song_frame_button = gtk_button_new();
    gtk_widget_set_size_request(song_frame_button, 200, 250);
    gtk_fixed_put(GTK_FIXED(playlist_frame), song_frame_button, 0, 0);
    gtk_button_set_relief(GTK_BUTTON(song_frame_button), GTK_RELIEF_NONE);
    g_signal_connect(song_frame_button, "clicked", G_CALLBACK(songInPlaylist), title);

    // Tạo image cho mỗi frame
    char temp[PATH_MAX];
    strcpy(temp,"database\\avatarPlaylist\\");
    strcat(temp,title);
    strcat(temp,".jpg");

    // Tạo image cho mỗi frame
    GError *error = NULL;
    GdkPixbuf *pixbuf = gdk_pixbuf_new_from_file(temp, &error);
    if (error) {
        g_printerr("Error loading file: %s\n", error->message);
        g_error_free(error);
    }
    GdkPixbuf *scaled_pixbuf = gdk_pixbuf_scale_simple(pixbuf, 160, 160, GDK_INTERP_BILINEAR);
    GtkWidget *playlist_frame_image = gtk_image_new_from_pixbuf(scaled_pixbuf);
    gtk_fixed_put(GTK_FIXED(playlist_frame), playlist_frame_image, 20, 20);

    // Tạo labels cho mỗi frame
    GtkWidget *song_frame_title_label = gtk_label_new(title);
    gtk_fixed_put(GTK_FIXED(playlist_frame), song_frame_title_label, 20, 190);
    gtk_widget_set_size_request(song_frame_title_label, 160, 30);
    gtk_label_set_xalign(song_frame_title_label, 0);

    // Tăng số lượng song
    id++;
}


// Vẽ hcn cho playlist_frame
gboolean draw_playlist_frame(GtkWidget *widget, cairo_t *cr, gpointer data)
{
    // Màu của playlist_frame
    GdkRGBA frame_color;
    gdk_rgba_parse(&frame_color, "#1DB954");

    // Vẽ playlist_frame
    cairo_set_source_rgba(cr, frame_color.red, frame_color.green, frame_color.blue, frame_color.alpha);
    cairo_rectangle(cr, 0, 0, 200, 250);
    cairo_fill(cr);

    return FALSE;
}
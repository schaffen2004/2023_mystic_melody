//
// Created by PC on 9/25/2023.
//

#include "addToPlaylist.h"
#include "query/playlistQuery.h"
#include "models/listOfSong.h"
#include "query/playlistQuery.h"

GPtrArray *song_list; // Danh sách bài hát sử dụng GPtrArray
GtkWidget *add_win;
// Callback khi nút "In Bài Hát" được nhấn
void print_selected_songs(GtkWidget *widget, gpointer data) {
    char *title = (char*) data;
    GString *selected_songs = g_string_new(NULL);

    for (guint i = 0; i < song_list->len; i++) {
        GtkWidget *checkbox = g_ptr_array_index(song_list, i);
        if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(checkbox))) {
            const gchar *song_name = gtk_button_get_label(GTK_BUTTON(checkbox));
            if(checkSongInPlaylist(song_name,title)==NO)
            {
                addSongToPlaylist(song_name,title);
            }
            g_string_append_printf(selected_songs, "%s\n", song_name);
        }
    }

    if (selected_songs->len > 0) {
        g_print("Selection:\n%s", selected_songs->str);
    } else {
        g_print("No Song");
    }

    g_string_free(selected_songs, TRUE);
    g_timeout_add_seconds(0.5, (GSourceFunc)gtk_widget_destroy, add_win);
//    g_timeout_add_seconds(1, (GSourceFunc)homePageShow, introView);
}

void addToPlaylistShow(char name[PATH_MAX]){

    // Tạo cửa sổ chính
    add_win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(add_win), "ADD SONG TO PLAYLIST");
    gtk_container_set_border_width(GTK_CONTAINER(add_win), 10);
    gtk_window_set_default_size(GTK_WINDOW(add_win), 500, 500);
    gtk_window_set_position(GTK_WINDOW(add_win), GTK_WIN_POS_CENTER_ALWAYS);

    // Tạo GtkstyleContextSignIn cho cửa sổ intro
    GtkWidget *styleContextSignIn = gtk_widget_get_style_context(add_win);

    // Áp dụng các thuộc tính CSS tùy chỉnh cho cửa sổ intro
    gtk_style_context_add_class(styleContextSignIn, "window");
    // Đăng ký bộ chọn CSS
    GtkWidget *providerSignIn = gtk_css_provider_new();
    gtk_css_provider_load_from_path(providerSignIn, "assets\\css\\addSongToPlaylist.css", NULL);
    gtk_style_context_add_provider(styleContextSignIn, GTK_STYLE_PROVIDER(providerSignIn),
                                   GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);

    // Tạo một vbox để chứa label, thanh cuộn và nút
    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(add_win), vbox);

    // Tạo label
    GtkWidget *label = gtk_label_new("Playlists:");
    gtk_box_pack_start(GTK_BOX(vbox), label, FALSE, FALSE, 5);
    gtk_widget_set_name(label, "Label");
    gtk_style_context_add_provider(gtk_widget_get_style_context(label), GTK_STYLE_PROVIDER(providerSignIn),
                                   GTK_STYLE_PROVIDER_PRIORITY_USER);

    // Tạo thanh cuộn dọc để chứa danh sách checkbox
    GtkWidget *scrolled_window = gtk_scrolled_window_new(NULL, NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled_window),
                                   GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_box_pack_start(GTK_BOX(vbox), scrolled_window, TRUE, TRUE, 5);

    GtkWidget *checkbox_list = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(scrolled_window), checkbox_list);

    // Tạo danh sách checkbox
    song_list = g_ptr_array_new_with_free_func(g_object_unref);

    initList();
    listPlaylist();

    for (guint i = 0; i < currentPlayList->len; i++) {
        char* str = g_ptr_array_index(currentPlayList, i);
        GtkWidget *checkbox = gtk_check_button_new_with_label(str);
        gtk_container_add(GTK_CONTAINER(checkbox_list), checkbox);
        g_ptr_array_add(song_list, checkbox);
        // Đặt màu chữ của checkbox thành màu trắng
        GdkRGBA white_color;
        gdk_rgba_parse(&white_color, "white");
        gtk_widget_override_color(checkbox, GTK_STATE_NORMAL, &white_color);
    }

    // Tạo nút "In Bài Hát"
    GtkWidget *print_button = gtk_button_new_with_label("ADD");
    gtk_box_pack_start(GTK_BOX(vbox), print_button, FALSE, FALSE, 5);
    gtk_widget_set_name(print_button, "button_Create");
    gtk_style_context_add_provider(gtk_widget_get_style_context(print_button), GTK_STYLE_PROVIDER(providerSignIn),
                                   GTK_STYLE_PROVIDER_PRIORITY_USER);

    // Kết nối callback cho nút "In Bài Hát"
    g_signal_connect(G_OBJECT(print_button), "clicked", G_CALLBACK(print_selected_songs), name);


    // Hiển thị cửa sổ chính và chạy ứng dụng
    gtk_widget_show_all(add_win);
    gtk_main();

    // Giải phóng bộ nhớ
    g_ptr_array_unref(song_list);
}

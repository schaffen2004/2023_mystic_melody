//
// Created by laphv on 8/27/2023.
//

#include "explorerTab.h"
#include "page/HomePage.h"
#include "models/listOfSong.h"
#include "query/songQuery.h"
#include "utils/control.h"

int explorer_num;
GtkWidget *explorer_tab_fixed,
        *explorer_scroll_view,
        *explorer_grid,
        *explorer_plus_button,
        *explorer_plus_icon;

void explorerShow()
{
    explorer_num = 0;
    // Khởi tạo explorer_tab_fixed
    explorer_tab_fixed = gtk_fixed_new();
    gtk_fixed_put(GTK_FIXED(fixedHome), explorer_tab_fixed, 0, 0);

    // Khởi tạo upload_plus_button
    explorer_plus_button = gtk_button_new();
    gtk_fixed_put(GTK_FIXED(explorer_tab_fixed), explorer_plus_button, 340, 110);
    gtk_widget_set_size_request(explorer_plus_button, 60, 60);
    gtk_button_set_relief(GTK_BUTTON(explorer_plus_button), GTK_RELIEF_NONE);

    // Kết nối tín hiệu "clicked" của explorer_plus_button với hàm button_upload_click
//    g_signal_connect(explorer_plus_button, "clicked", G_CALLBACK(button_upload_click), NULL);

    // Khởi tạo explorer_plus_icon
//    explorer_plus_icon = gtk_image_new_from_file("assets/add_logo.svg");
//    gtk_fixed_put(GTK_FIXED(explorer_tab_fixed), explorer_plus_icon, 360, 130);

    // Khởi explorer_scroll_view
    int
            scroll_view_width = 400,
            scroll_view_height = 480;

    explorer_scroll_view = gtk_scrolled_window_new(NULL, NULL);
    gtk_widget_set_size_request(explorer_scroll_view, scroll_view_width, scroll_view_height);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(explorer_scroll_view), GTK_POLICY_NEVER, GTK_POLICY_AUTOMATIC);
    gtk_fixed_put(GTK_FIXED(explorer_tab_fixed), explorer_scroll_view, 160, 200);

    // Khởi tạo song_grid
    explorer_grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(explorer_scroll_view), explorer_grid);
    gtk_widget_set_size_request(explorer_grid, scroll_view_width, scroll_view_height);
    gtk_grid_set_row_spacing(GTK_GRID(explorer_grid), 50);
    gtk_grid_set_column_spacing(GTK_GRID(explorer_grid), 50);
    gtk_grid_set_row_homogeneous(GTK_GRID(explorer_grid), TRUE);
    gtk_grid_set_column_homogeneous(GTK_GRID(explorer_grid), TRUE);

    initList();
    listExplorer();
    // Ví dụ tạo các song frames
    // Gọi createSongFrame() cho mỗi bài upload lên
    for (guint i = 0; i < currentPlayList->len; i++) {
        char* str = g_ptr_array_index(currentPlayList, i);
        createExplorerFrame("assets\\test.png", str, "Nhat");
    }


    // Hiển thị explorer_tab_fixed
    gtk_widget_show_all(explorer_tab_fixed);
}

void createExplorerFrame(char* explorer_image_path, char* title, char* artist) {
    // Tạo frame cho mỗi song
    GtkWidget *explorer_frame = gtk_fixed_new();
    gtk_widget_set_size_request(explorer_frame, 200, 250);
    gtk_grid_attach(GTK_GRID(explorer_grid), explorer_frame, explorer_num % 5, explorer_num / 5, 1, 1);

    // Tạo vùng để vẽ hcn cho mỗi frame
    GtkWidget *explorer_frame_dr_a = gtk_drawing_area_new();
    gtk_widget_set_size_request(explorer_frame_dr_a, 200, 250);
    gtk_fixed_put(GTK_FIXED(explorer_frame), explorer_frame_dr_a, 0, 0);
    g_signal_connect(explorer_frame_dr_a, "draw", G_CALLBACK(draw_explorer_frame), NULL);

    // Tạo button cho mỗi frame
    GtkWidget *explorer_frame_button = gtk_button_new();
    gtk_widget_set_size_request(explorer_frame_button, 200, 250);
    gtk_fixed_put(GTK_FIXED(explorer_frame), explorer_frame_button, 0, 0);
    gtk_button_set_relief(GTK_BUTTON(explorer_frame_button), GTK_RELIEF_NONE);
    g_signal_connect(explorer_frame_button, "button_press_event", G_CALLBACK(startSong), title);

    char temp[PATH_MAX];
    strcpy(temp,"database\\avatarSong\\");
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
    GtkWidget *explorer_frame_image = gtk_image_new_from_pixbuf(scaled_pixbuf);
    gtk_fixed_put(GTK_FIXED(explorer_frame), explorer_frame_image, 20, 20);

    // Tạo labels cho mỗi frame
    GtkWidget *explorer_frame_title_label = gtk_label_new(title);
    gtk_fixed_put(GTK_FIXED(explorer_frame), explorer_frame_title_label, 20, 190);
    gtk_widget_set_size_request(explorer_frame_title_label, 160, 30);
    gtk_label_set_xalign(explorer_frame_title_label, 0);

    artistName(title);
    GtkWidget *explorer_frame_artist_label = gtk_label_new(nameOfItArtist);
    gtk_fixed_put(GTK_FIXED(explorer_frame), explorer_frame_artist_label, 20, 210);
    gtk_widget_set_size_request(explorer_frame_artist_label, 160, 30);
    gtk_label_set_xalign(explorer_frame_artist_label, 0);

    // Tăng số lượng song
    explorer_num++;
}

// Vẽ hcn cho explorer_frame
gboolean draw_explorer_frame(GtkWidget *widget, cairo_t *cr, gpointer data)
{
    // Màu của explorer_frame
    GdkRGBA frame_color;
    gdk_rgba_parse(&frame_color, "#1DB954");

    // Vẽ explorer_frame
    cairo_set_source_rgba(cr, frame_color.red, frame_color.green, frame_color.blue, frame_color.alpha);
    cairo_rectangle(cr, 0, 0, 200, 250);
    cairo_fill(cr);

    return FALSE;
}
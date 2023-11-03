//
// Created by laphv on 8/27/2023.
//

#include "myMusicTab.h"

#include "models/listOfSong.h"
#include "page/HomePage.h"
#include "query/songQuery.h"
#include "page/components/uploadTab.h"
#include "utils/control.h"

int myMusic_num;
GtkWidget *myMusic_tab_fixed,
        *myMusic_scroll_view,
        *myMusic_grid,
        *myMusic_plus_button;

void myMusicShow()
{
    myMusic_num = 0;
    // Khởi tạo myMusic_tab_fixed
    myMusic_tab_fixed = gtk_fixed_new();
    gtk_fixed_put(GTK_FIXED(fixedHome), myMusic_tab_fixed, 0, 0);

    // Khởi tạo upload_plus_button
    myMusic_plus_button = gtk_button_new();
    gtk_fixed_put(GTK_FIXED(myMusic_tab_fixed), myMusic_plus_button, 360, 130);
    gtk_widget_set_size_request(myMusic_plus_button, 30, 30);
    gtk_button_set_relief(GTK_BUTTON(myMusic_plus_button), GTK_RELIEF_NONE);

    // Kết nối tín hiệu "clicked" của myMusic_plus_button với hàm button_upload_click
//    g_signal_connect(myMusic_plus_button, "clicked", G_CALLBACK(button_upload_click), NULL);



    // Khởi myMusic_scroll_view
    int
            scroll_view_width = 400,
            scroll_view_height = 480;

    myMusic_scroll_view = gtk_scrolled_window_new(NULL, NULL);
    gtk_widget_set_size_request(myMusic_scroll_view, scroll_view_width, scroll_view_height);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(myMusic_scroll_view), GTK_POLICY_NEVER, GTK_POLICY_AUTOMATIC);
    gtk_fixed_put(GTK_FIXED(myMusic_tab_fixed), myMusic_scroll_view, 160, 200);

    // Khởi tạo song_grid
    myMusic_grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(myMusic_scroll_view), myMusic_grid);
    gtk_widget_set_size_request(myMusic_grid, scroll_view_width, scroll_view_height);
    gtk_grid_set_row_spacing(GTK_GRID(myMusic_grid), 50);
    gtk_grid_set_column_spacing(GTK_GRID(myMusic_grid), 50);
    gtk_grid_set_row_homogeneous(GTK_GRID(myMusic_grid), TRUE);
    gtk_grid_set_column_homogeneous(GTK_GRID(myMusic_grid), TRUE);

    initList();
    listMySong();
    createAddFrame();
    for (guint i = 0; i < currentPlayList->len; i++) {
        char* str = g_ptr_array_index(currentPlayList, i);
        createMyMusicFrame("assets\\test.png", str, "Nhat");
    }

    // Hiển thị myMusic_tab_fixed
    gtk_widget_show_all(myMusic_tab_fixed);
}
void myMusic_tab_hide()
{
    // Xóa upload_tab_fixed
    gtk_widget_destroy(myMusic_tab_fixed);
}
// Create myMusic_frame
void createAddFrame() {
    // Tạo frame cho mỗi song
    GtkWidget *myMusic_frame = gtk_fixed_new();
    gtk_widget_set_size_request(myMusic_frame, 200, 250);
    gtk_grid_attach(GTK_GRID(myMusic_grid), myMusic_frame, myMusic_num % 5, myMusic_num / 5, 1, 1);

    // Tạo vùng để vẽ hcn cho mỗi frame
    GtkWidget *myMusic_frame_dr_a = gtk_drawing_area_new();
    gtk_widget_set_size_request(myMusic_frame_dr_a, 200, 250);
    gtk_fixed_put(GTK_FIXED(myMusic_frame), myMusic_frame_dr_a, 0, 0);
    g_signal_connect(myMusic_frame_dr_a, "draw", G_CALLBACK(draw_myMusic_frame), NULL);

    // Tạo button cho mỗi frame
    GtkWidget *myMusic_frame_button = gtk_button_new();
    gtk_widget_set_size_request(myMusic_frame_button, 200, 250);
    gtk_fixed_put(GTK_FIXED(myMusic_frame), myMusic_frame_button, 0, 0);
    gtk_button_set_relief(GTK_BUTTON(myMusic_frame_button), GTK_RELIEF_NONE);

    g_signal_connect(myMusic_frame_button, "button_press_event", G_CALLBACK(uploadShow), "add");

    GError *error = NULL;
    GdkPixbuf *pixbuf = gdk_pixbuf_new_from_file("assets/add.png", &error);
    if (error) {
        g_printerr("Error loading file: %s\n", error->message);
        g_error_free(error);
    }
    GdkPixbuf *scaled_pixbuf = gdk_pixbuf_scale_simple(pixbuf, 160, 160, GDK_INTERP_BILINEAR);
    GtkWidget *myMusic_frame_image = gtk_image_new_from_pixbuf(scaled_pixbuf);
    gtk_fixed_put(GTK_FIXED(myMusic_frame), myMusic_frame_image, 20, 20);

    // Tạo labels cho mỗi frame
    GtkWidget *myMusic_frame_title_label = gtk_label_new("ADD NEW SONG");
    gtk_fixed_put(GTK_FIXED(myMusic_frame), myMusic_frame_title_label, 20, 190);
    gtk_widget_set_size_request(myMusic_frame_title_label, 160, 30);
    gtk_label_set_xalign(myMusic_frame_title_label, 0);


    // Tăng số lượng song
    myMusic_num++;
}

// Create myMusic_frame
void createMyMusicFrame(char* myMusic_image_path, char* title, char* artist) {
    // Tạo frame cho mỗi song
    GtkWidget *myMusic_frame = gtk_fixed_new();
    gtk_widget_set_size_request(myMusic_frame, 200, 250);
    gtk_grid_attach(GTK_GRID(myMusic_grid), myMusic_frame, myMusic_num % 5, myMusic_num / 5, 1, 1);

    // Tạo vùng để vẽ hcn cho mỗi frame
    GtkWidget *myMusic_frame_dr_a = gtk_drawing_area_new();
    gtk_widget_set_size_request(myMusic_frame_dr_a, 200, 250);
    gtk_fixed_put(GTK_FIXED(myMusic_frame), myMusic_frame_dr_a, 0, 0);
    g_signal_connect(myMusic_frame_dr_a, "draw", G_CALLBACK(draw_myMusic_frame), NULL);

    // Tạo button cho mỗi frame
    GtkWidget *myMusic_frame_button = gtk_button_new();
    gtk_widget_set_size_request(myMusic_frame_button, 200, 250);
    gtk_fixed_put(GTK_FIXED(myMusic_frame), myMusic_frame_button, 0, 0);
    gtk_button_set_relief(GTK_BUTTON(myMusic_frame_button), GTK_RELIEF_NONE);

    g_signal_connect(myMusic_frame_button, "button_press_event", G_CALLBACK(startSong), title);
    // Tạo image cho mỗi frame
    char temp[PATH_MAX];
    strcpy(temp,"database\\avatarSong\\");
    strcat(temp,title);
    strcat(temp,".jpg");
    GError *error = NULL;
    GdkPixbuf *pixbuf = gdk_pixbuf_new_from_file(temp, &error);
    if (error) {
        g_printerr("Error loading file: %s\n", error->message);
        g_error_free(error);
    }
    GdkPixbuf *scaled_pixbuf = gdk_pixbuf_scale_simple(pixbuf, 160, 160, GDK_INTERP_BILINEAR);
    GtkWidget *myMusic_frame_image = gtk_image_new_from_pixbuf(scaled_pixbuf);
    gtk_fixed_put(GTK_FIXED(myMusic_frame), myMusic_frame_image, 20, 20);

    // Tạo labels cho mỗi frame
    GtkWidget *myMusic_frame_title_label = gtk_label_new(title);
    gtk_fixed_put(GTK_FIXED(myMusic_frame), myMusic_frame_title_label, 20, 190);
    gtk_widget_set_size_request(myMusic_frame_title_label, 160, 30);
    gtk_label_set_xalign(myMusic_frame_title_label, 0);
    artistName(title);
    GtkWidget *myMusic_frame_artist_label = gtk_label_new(nameOfItArtist);
    gtk_fixed_put(GTK_FIXED(myMusic_frame), myMusic_frame_artist_label, 20, 210);
    gtk_widget_set_size_request(myMusic_frame_artist_label, 160, 30);
    gtk_label_set_xalign(myMusic_frame_artist_label, 0);

    // Tăng số lượng song
    myMusic_num++;
}


// Vẽ hcn cho myMusic_frame
gboolean draw_myMusic_frame(GtkWidget *widget, cairo_t *cr, gpointer data)
{
    // Màu của myMusic_frame
    GdkRGBA frame_color;
    gdk_rgba_parse(&frame_color, "#1DB954");

    // Vẽ myMusic_frame
    cairo_set_source_rgba(cr, frame_color.red, frame_color.green, frame_color.blue, frame_color.alpha);
    cairo_rectangle(cr, 0, 0, 200, 250);
    cairo_fill(cr);

    return FALSE;
}
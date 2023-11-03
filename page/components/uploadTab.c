//
// Created by laphv on 8/27/2023.
//

#include "uploadTab.h"
#include "utils/control.h"

GtkWidget *label_song_upload, *entry_song_upload;
GtkWidget *label_artist_upload, *entry_artist_upload;
GtkWidget *label_image_upload, *image_file_upload;
GtkWidget *label_music_upload, *music_file_upload,*notify;
GtkWidget *upload_button,*upload_fixed;
GtkWidget *windowUpload;
void on_file_chooser_button_clicked(GtkFileChooserButton *button, GtkLabel *label) {
    const gchar *filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(button));
    gtk_label_set_text(label, filename);

}
void uploadShow()
{
    // Tạo window
    windowUpload = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_position(GTK_WINDOW(windowUpload), GTK_WIN_POS_CENTER_ALWAYS);
    gtk_window_set_default_size(GTK_WINDOW(windowUpload), 500, 700);
    g_signal_connect(windowUpload, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Tạo GtkstyleContextSignIn cho cửa sổ intro
    GtkWidget *styleContextSignIn = gtk_widget_get_style_context(windowUpload);
    // Áp dụng các thuộc tính CSS tùy chỉnh cho cửa sổ intro
    gtk_style_context_add_class(styleContextSignIn, "upload-window");
    // Đăng ký bộ chọn CSS
    GtkWidget *providerSignIn = gtk_css_provider_new();
    gtk_css_provider_load_from_path(providerSignIn, "assets\\css\\uploadSong.css", NULL);
    gtk_style_context_add_provider(styleContextSignIn, GTK_STYLE_PROVIDER(providerSignIn),
                                   GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);


    // Tạo fixed
    GtkWidget *fixed = gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(windowUpload), fixed);

    GdkRGBA color_upload;
    gdk_rgba_parse(&color_upload, "white");
    upload_fixed = gtk_fixed_new();
    gtk_fixed_put(GTK_FIXED(fixed), upload_fixed, 0, 0);

    label_song_upload = gtk_label_new("Song Name:");
//    gtk_widget_set_size_request(label_song_upload, 320, 65);
    gtk_fixed_put(GTK_FIXED(fixed), label_song_upload, 83.96, 60);
    gtk_widget_override_color(label_song_upload , GTK_STATE_NORMAL, &color_upload);

    entry_song_upload = gtk_entry_new();
    gtk_widget_set_size_request(entry_song_upload, 330, 40);
    gtk_fixed_put(GTK_FIXED(upload_fixed), entry_song_upload, 83.96, 120);


    label_artist_upload = gtk_label_new("Artist:");
    gtk_fixed_put(GTK_FIXED(upload_fixed), label_artist_upload, 83.96, 180);
    gtk_widget_override_color(label_artist_upload, GTK_STATE_NORMAL, &color_upload);

    entry_artist_upload = gtk_entry_new();
    gtk_widget_set_size_request(entry_artist_upload, 330, 40);
    gtk_fixed_put(GTK_FIXED(upload_fixed), entry_artist_upload, 83.96, 240);

    label_image_upload = gtk_label_new("Select Image:");
    gtk_fixed_put(GTK_FIXED(upload_fixed), label_image_upload, 83.96, 300);
    gtk_widget_override_color(label_image_upload, GTK_STATE_NORMAL, &color_upload);

    image_file_upload = gtk_file_chooser_button_new("Select Image File", GTK_FILE_CHOOSER_ACTION_OPEN);
    gtk_widget_set_size_request(image_file_upload, 330, -1);
    gtk_fixed_put(GTK_FIXED(upload_fixed), image_file_upload, 83.96, 360);

    label_music_upload = gtk_label_new("Select Music:");
    gtk_fixed_put(GTK_FIXED(upload_fixed), label_music_upload, 83.96, 420);
    gtk_widget_override_color(label_music_upload, GTK_STATE_NORMAL, &color_upload);

    music_file_upload = gtk_file_chooser_button_new("Select Music File", GTK_FILE_CHOOSER_ACTION_OPEN);
    gtk_widget_set_size_request(music_file_upload, 330, -1);
    gtk_fixed_put(GTK_FIXED(upload_fixed), music_file_upload, 83.96, 480);

    upload_button = gtk_button_new_with_label("Upload");
    gtk_widget_set_size_request(upload_button, 330, 65);

    gtk_fixed_put(GTK_FIXED(upload_fixed), upload_button, 83.96, 540);
    g_signal_connect(upload_button, "clicked", G_CALLBACK(uploadSong), NULL);
    gtk_widget_set_name(upload_button, "upload_button");
    gtk_style_context_add_provider(gtk_widget_get_style_context(upload_button), GTK_STYLE_PROVIDER(providerSignIn),
                                   GTK_STYLE_PROVIDER_PRIORITY_USER);

    notify = gtk_label_new("");
    gtk_fixed_put(GTK_FIXED(upload_fixed), notify, 83.96, 650);
    gtk_widget_override_color(notify, GTK_STATE_NORMAL, &color_upload);
    gtk_widget_set_name(notify, "notify");
    gtk_style_context_add_provider(gtk_widget_get_style_context(notify), GTK_STYLE_PROVIDER(providerSignIn),
                                   GTK_STYLE_PROVIDER_PRIORITY_USER);
//    // Hiển thị tất cả các widget
    gtk_widget_show_all(windowUpload);

    gtk_main();

}
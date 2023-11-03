//
// Created by laphv on 8/27/2023.
//

#include "updatePlaylist.h"
#include "query/playlistQuery.h"
#include "models/userModel.h"
#include "utils/filter.h"
#include "utils/upload.h"
#include "models/listOfSong.h"

GtkWidget *scrolled_window;
GtkWidget *container_box;
GtkWidget *window;
GtkWidget *provider;
GtkStyleContext *styleContextAdd;
GtkWidget *Entry_Playlist_Name;
GtkWidget *Create_Playlist;
GtkWidget  *image_playlist_upload;
// Hàm để thay đổi kích thước hình ảnh

void show_message_dialog() {
    GtkWidget *dialog = gtk_message_dialog_new(GTK_WINDOW(window),
                                               GTK_DIALOG_MODAL,
                                               GTK_MESSAGE_INFO,
                                               GTK_BUTTONS_OK,
                                               "Add playlist is not successful.");
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}

void addPlaylist()
{
    const gchar *namePlaylist = gtk_entry_get_text(GTK_ENTRY(Entry_Playlist_Name));
    if(checkPlaylistInDatabase(namePlaylist,username)==FAIL)
    {
        gtk_label_set_text(GTK_LABEL(Create_Playlist),"Playlist had existed");

    }
    else
    {
        char src_image[PATH_MAX];

        strcpy(src_image,"assets\\default.jpg");
        char *src_path_image = gtk_file_chooser_get_filename(image_playlist_upload);

        if(src_path_image != NULL)
        {
            strcpy(src_image,src_path_image);
        }
        if(addPlaylistToDatabase(namePlaylist,username)==0)
        {
            if(checkImage(src_image) == 1)
            {
                const char *playlist_name = gtk_entry_get_text(GTK_ENTRY(Entry_Playlist_Name));
                saveImagePlaylist(playlist_name,src_image);
            }
            gtk_widget_destroy(window);
        }
        else
        {
            show_message_dialog();
        }
    }

}

GdkPixbuf* resize_image(const gchar* filename, gint width, gint height) {
    GdkPixbuf* pixbuf = gdk_pixbuf_new_from_file(filename, NULL);
    GdkPixbuf* resized_pixbuf = gdk_pixbuf_scale_simple(pixbuf, width, height, GDK_INTERP_BILINEAR);
    g_object_unref(pixbuf);
    return resized_pixbuf;
}

void createPlaylistShow() {

    // Tạo một cửa sổ mới
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Create new playlist");
    gtk_window_set_default_size(GTK_WINDOW(window), 846, 450);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

    // Tạo GtkstyleContextSignIn cho cửa sổ intro
    styleContextAdd= gtk_widget_get_style_context(window);

    // Áp dụng các thuộc tính CSS tùy chỉnh cho cửa sổ intro
    gtk_style_context_add_class(styleContextAdd, "add-window");

    // Đăng ký bộ chọn CSS
    provider = gtk_css_provider_new();
    gtk_css_provider_load_from_path(provider, "assets\\css\\Style.css", NULL);
    gtk_style_context_add_provider(styleContextAdd, GTK_STYLE_PROVIDER(provider),
                                   GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);

    // Load tệp CSS
    gtk_css_provider_load_from_path(provider, "assets\\css\\Style.css", NULL);

    // Tạo một đối tượng fixed container
    GtkWidget *fixed = gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(window), fixed);

    //Label Create_Playlist
    Create_Playlist = gtk_label_new("CREATE PLAYLIST");
    gtk_widget_set_size_request(Create_Playlist, 401, 48);
    gtk_fixed_put(GTK_FIXED(fixed), Create_Playlist, 223, 12);
    gtk_widget_set_name(Create_Playlist, "Create_Playlist");
    gtk_style_context_add_provider(gtk_widget_get_style_context(Create_Playlist), GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);

    //box2
//    GtkWidget *box2 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    scrolled_window = gtk_scrolled_window_new(NULL, NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled_window), GTK_POLICY_AUTOMATIC, GTK_POLICY_ALWAYS);
    gtk_widget_set_size_request(scrolled_window, 361, 341);
    gtk_fixed_put(GTK_FIXED(fixed), scrolled_window, 472, 90);
    gtk_widget_set_name( scrolled_window, "scrolled_window");
    gtk_style_context_add_provider(gtk_widget_get_style_context( scrolled_window), GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);

    //Image_Playlist
    GtkWidget *Image_Playlist = gtk_image_new();
    gtk_widget_set_size_request(Image_Playlist, 200, 200);
    gtk_fixed_put(GTK_FIXED(fixed), Image_Playlist, 41, 106);
    gtk_widget_set_name(Image_Playlist, "Image_Playlist");
    gtk_style_context_add_provider(gtk_widget_get_style_context(Image_Playlist), GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);

    //Label_Recommend_Songs
    GtkWidget *Label_Recommend_Songs = gtk_label_new("");
    gtk_widget_set_size_request(Label_Recommend_Songs, 268, 25);
    gtk_fixed_put(GTK_FIXED(fixed), Label_Recommend_Songs, 518, 106);
    gtk_widget_set_name(Label_Recommend_Songs, "Label_Recommend_Songs");
    gtk_style_context_add_provider(gtk_widget_get_style_context(Label_Recommend_Songs), GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);

    // Thay đổi kích thước hình ảnh và hiển thị nó trong GtkImage
    GdkPixbuf* resized_pixbuf = resize_image("assets\\default.jpg", 200, 200);
    gtk_image_set_from_pixbuf(GTK_IMAGE(Image_Playlist), resized_pixbuf);
    g_object_unref(resized_pixbuf);

    // button Sign in
    GtkWidget *button_Create = gtk_button_new_with_label("CREATE");
    gtk_widget_set_size_request(button_Create, 197, 48);
    gtk_fixed_put(GTK_FIXED(fixed), button_Create, 141, 354);
    gtk_widget_set_name(button_Create, "button_Create");
    gtk_style_context_add_provider(gtk_widget_get_style_context(button_Create), GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
    g_signal_connect(button_Create, "clicked", G_CALLBACK(addPlaylist), NULL);

    //Entry_Playlist_Name
    Entry_Playlist_Name = gtk_entry_new();
    gtk_widget_set_size_request(Entry_Playlist_Name, 180, 35);
    gtk_fixed_put(GTK_FIXED(fixed), Entry_Playlist_Name, 258, 189);
    gtk_entry_set_placeholder_text(GTK_ENTRY(Entry_Playlist_Name), "PLAYLIST'S NAME");
    gtk_widget_set_name(Entry_Playlist_Name, "entry_playlist");
    gtk_style_context_add_provider(gtk_widget_get_style_context(Entry_Playlist_Name), GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);

    image_playlist_upload = gtk_file_chooser_button_new("Select Image File", GTK_FILE_CHOOSER_ACTION_OPEN);
    gtk_widget_set_size_request(image_playlist_upload, 180, -1);
    GdkRGBA black_color = {0.0, 0.0, 0.0, 1.0};
    gtk_widget_override_background_color(image_playlist_upload, GTK_STATE_FLAG_NORMAL, &black_color);
    gtk_fixed_put(GTK_FIXED(fixed), image_playlist_upload, 258, 250);

    // Tạo một Vertical Box (VBox) để chứa danh sách playlist
    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_container_set_border_width(GTK_CONTAINER(vbox), 10);

    initList();
    listPlaylist();

    for (guint i = 0; i < currentPlayList->len; i++)
    {
        char* str = g_ptr_array_index(currentPlayList, i);
        //Tạo một Box để chứa hình ảnh và thông tin playlist
        GtkWidget *hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);

        char temp[PATH_MAX];
        strcpy(temp,"database\\avatarPlaylist\\");
        strcat(temp,str);
        strcat(temp,".jpg");

        // Thêm ảnh playlist bên trái với kích thước 10x10px
        GdkPixbuf *pixbuf = gdk_pixbuf_new_from_file(temp, NULL);
        GdkPixbuf *scaled_pixbuf = gdk_pixbuf_scale_simple(pixbuf, 80, 80, GDK_INTERP_BILINEAR);
        GtkWidget *image = gtk_image_new_from_pixbuf(scaled_pixbuf);
        gtk_box_pack_start(GTK_BOX(hbox), image, FALSE, FALSE, 0);

        // Thêm thông tin playlist bên phải
        char label_text[256];
        snprintf(label_text, sizeof(label_text), "Tên Playlist: %s",
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
    gtk_container_add(GTK_CONTAINER(scrolled_window), vbox);

    gtk_widget_show_all(window);
    gtk_main();
}
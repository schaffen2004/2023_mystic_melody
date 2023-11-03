//
// Created by laphv on 8/26/2023.
//

#include "HomePage.h"
#include "utils/control.h"

GtkWidget *providerHome;
GtkStyleContext *styleContextHome;
GtkWidget
        *homeView,
        *fixedHome,
        *scrolledHome,
        *rect_area,
        *tab_label;
GtkWidget
        *explorer_button,
        *library_button,
        *myMusic_button,
        *logout_button,
        *explorer_icon,
        *library_icon,
        *myMusic_icon,
        *logout_icon;
GtkWidget
        *entry_search_bar,
        *exit_button,
        *exit_icon,
        *search_icon;
GtkWidget *providerHeaderBar;

GtkStyleContext *styleContextHeaderBar;
GtkWidget *progress_bar,*song_label,*artist_label,*image_song_avatar,*play_icon,*play_song_image,*stop_song_image;
GtkWidget *time_label;

void on_draw_header_bar(GtkWidget *widget, cairo_t *cr, gpointer user_data) {
    // Chỉnh màu cho background của hcn
    cairo_set_source_rgb(cr, 41/255.0, 40/255.0, 40/255.0); // fill color

    // Bắt đầu vẽ hcn
    cairo_rectangle(cr, 0, 0, 300, 680);
    cairo_fill_preserve(cr); // fill the rectangle
    cairo_stroke(cr); // draw the border
}

void mainMenuShow()
{
    // Tạo một hình chữ nhật để chứa toàn bộ Widget
    rect_area = gtk_drawing_area_new();
    // Set size và vị trí cho hình chữ nhật
    gtk_widget_set_size_request(rect_area,80 , 800);
    gtk_fixed_put(GTK_FIXED(fixedHome), rect_area, 0, 0);
    // bắt đầu vẽ hình chữ nhật
    g_signal_connect(rect_area, "draw", G_CALLBACK(on_draw_header_bar), NULL);

    // Khởi tạo nút Explorer
    explorer_button = gtk_button_new();
    gtk_fixed_put(GTK_FIXED(fixedHome), explorer_button, 0, 100);
    gtk_widget_set_size_request(explorer_button, 80, 80);
    gtk_button_set_relief(GTK_BUTTON(explorer_button), GTK_RELIEF_NONE);

//    // Khởi tạo nút Favourite
//    favourite_button = gtk_button_new();
//    gtk_fixed_put(GTK_FIXED(fixedHome), favourite_button, 0, 400);
//    gtk_widget_set_size_request(favourite_button, 80, 80);
//    gtk_button_set_relief(GTK_BUTTON(favourite_button), GTK_RELIEF_NONE);

    // Khởi tạo nút Library
    library_button = gtk_button_new();
    gtk_fixed_put(GTK_FIXED(fixedHome), library_button, 0, 300);
    gtk_widget_set_size_request(library_button, 80, 80);
    gtk_button_set_relief(GTK_BUTTON(library_button), GTK_RELIEF_NONE);

    // Khởi tạo nút myMusic
    myMusic_button = gtk_button_new();
    gtk_fixed_put(GTK_FIXED(fixedHome), myMusic_button, 0, 200);
    gtk_widget_set_size_request(myMusic_button, 80, 80);
    gtk_button_set_relief(GTK_BUTTON(myMusic_button), GTK_RELIEF_NONE);

    // Khởi tạo nút Log out
    logout_button = gtk_button_new();
    gtk_fixed_put(GTK_FIXED(fixedHome), logout_button, 0, 600);
    gtk_widget_set_size_request(logout_button, 80, 80);
    gtk_button_set_relief(GTK_BUTTON(logout_button), GTK_RELIEF_NONE);

//    // Add event clicked cho từng nút
    g_signal_connect(explorer_button, "clicked", G_CALLBACK(explorerTab), NULL);
    g_signal_connect(library_button, "clicked", G_CALLBACK(playlistTab), NULL);
    g_signal_connect(myMusic_button, "clicked", G_CALLBACK(myMusicTab), NULL);
    g_signal_connect(logout_button, "clicked", G_CALLBACK(signOutClicked), NULL);

    // Thêm các icon của từng
    explorer_icon = gtk_image_new_from_file("assets\\explorer_icon.png");
    gtk_fixed_put(GTK_FIXED(fixedHome), explorer_icon, 25, 125);
    library_icon = gtk_image_new_from_file("assets\\library_icon.png");
    gtk_fixed_put(GTK_FIXED(fixedHome), library_icon, 25, 325);
    myMusic_icon = gtk_image_new_from_file("assets\\upload_icon.png");
    gtk_fixed_put(GTK_FIXED(fixedHome), myMusic_icon, 25, 225);
    logout_icon = gtk_image_new_from_file("assets\\logout_icon.png");
    gtk_fixed_put(GTK_FIXED(fixedHome), logout_icon, 25, 625);
}

void on_draw_event(GtkWidget *widget, cairo_t *cr, gpointer user_data) {

    // Chỉnh màu cho background của hcn
    cairo_set_source_rgb(cr, 41/255.0, 40/255.0, 40/255.0);// fill color

    // Bắt đầu vẽ hcn
    cairo_rectangle(cr, 0, 0, 1500, 140);
    cairo_fill_preserve(cr); // fill the rectangle
}

void musicBarShow()
{
    // Tạo một hình chữ nhật để chứa toàn bộ Widget
    GtkWidget *rect_area = gtk_drawing_area_new();
    // Set size và vị trí cho hình chữ nhật
    gtk_widget_set_size_request(rect_area, 1500, 140);
    gtk_fixed_put(GTK_FIXED(fixedHome), rect_area, 0, 680);
    // bắt đầu vẽ hình chữ nhật
    g_signal_connect(rect_area, "draw", G_CALLBACK(on_draw_event), NULL);

    progress_bar = gtk_progress_bar_new();
    gtk_widget_set_size_request(progress_bar, 650, 10); // Set the size of the progress bar
    gtk_fixed_put(fixedHome, progress_bar, 500, 769); // Set the position of the progress bar

    time_label = gtk_label_new("00:00:00");
    gtk_widget_set_size_request(time_label, 50, 50);
    gtk_fixed_put(fixedHome, time_label, 500, 730); // Set the position of the time label
    gtk_widget_set_name(time_label,"time_label");
    gtk_style_context_add_provider(gtk_widget_get_style_context(time_label), GTK_STYLE_PROVIDER(providerHome),
                                   GTK_STYLE_PROVIDER_PRIORITY_USER);

    GtkWidget *playButton = gtk_button_new();
    gtk_fixed_put(GTK_FIXED(fixedHome), playButton, 800, 715);
    gtk_widget_set_name(playButton, "play-button");
    gtk_style_context_add_provider(gtk_widget_get_style_context(playButton), GTK_STYLE_PROVIDER(providerHome),
                                   GTK_STYLE_PROVIDER_PRIORITY_USER);
//    g_signal_connect(playButton, "clicked", G_CALLBACK(toggle_progress), NULL);

    play_icon = gtk_image_new_from_file("assets\\explorer_icon.png");
    gtk_fixed_put(GTK_FIXED(fixedHome), play_icon, 25, 125);

    GdkRGBA color;
    gdk_rgba_parse(&color, "#ffffff");

    // Tạo label để chứ tên bài hát và tên nghệ sĩ
    song_label = gtk_label_new("");
    gtk_widget_override_color(song_label, GTK_STATE_FLAG_NORMAL, &color);
    gtk_fixed_put(GTK_FIXED(fixedHome), song_label, 170, 710);
    gtk_widget_set_name(song_label, "song-label");

    artist_label = gtk_label_new("");
    gtk_widget_override_color(artist_label, GTK_STATE_FLAG_NORMAL, &color);
    gtk_fixed_put(GTK_FIXED(fixedHome), artist_label, 170, 740);
    gtk_widget_set_name(artist_label, "artist-label");


    gtk_widget_set_name(progress_bar, "custom-progress-bar");
    gtk_style_context_add_provider(gtk_widget_get_style_context(progress_bar), GTK_STYLE_PROVIDER(providerHome),
                                   GTK_STYLE_PROVIDER_PRIORITY_USER);

//    // Khởi tạo widget cho việc chứa ảnh của bài hát
//    image_song_avatar = gtk_image_new_from_file("assets/OIP.jpg");
//
//    gtk_fixed_put(GTK_FIXED(fixedHome), image_song_avatar, 36, 690);

    // Khởi tạo widget cho việc chứa ảnh của bài hát
    play_song_image = gtk_image_new_from_file("assets/play_button.svg");
    gtk_fixed_put(GTK_FIXED(fixedHome), play_song_image, 800, 715);
    g_signal_connect(playButton, "clicked", G_CALLBACK(togglePlay), NULL);

//    GError *error = NULL;
//    GdkPixbuf *pixbuf = gdk_pixbuf_new_from_file("assets/OIP.jpg", &error);
//    GdkPixbuf *scaled_pixbuf = gdk_pixbuf_scale_simple(pixbuf, 160, 160, GDK_INTERP_BILINEAR);
//    image_song_avatar = gtk_image_new_from_pixbuf(scaled_pixbuf);
//    gtk_fixed_put(GTK_FIXED(fixedHome), play_song_image, 36, 690);
//    gtk_widget_set_name(image_song_avatar, "song-poster");

    GError *error = NULL;
    GdkPixbuf *pixbuf = gdk_pixbuf_new_from_file("assets/default.jpg", &error);
    if (error) {
        g_printerr("Error loading file: %s\n", error->message);
        g_error_free(error);
    }
    GdkPixbuf *scaled_pixbuf = gdk_pixbuf_scale_simple(pixbuf, 140, 140, GDK_INTERP_BILINEAR);
    image_song_avatar = gtk_image_new_from_pixbuf(scaled_pixbuf);
    gtk_fixed_put(GTK_FIXED(fixedHome), image_song_avatar, 0, 680);

    gtk_widget_hide(image_song_avatar);
    gtk_widget_hide(song_label);
    gtk_widget_hide(artist_label);
}

void headerBarShow()
{
    // Create a box to hold the search button and entry widget
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    gtk_fixed_put(GTK_FIXED(fixedHome), box, 425, 26);

    // Create the search button
    GtkWidget *search = gtk_button_new();
    gtk_fixed_put(GTK_FIXED(fixedHome), search, 440, 34);
    gtk_button_set_relief(GTK_BUTTON(search), GTK_RELIEF_NONE);
//    g_signal_connect(search, "clicked", G_CALLBACK(searchTabShow), NULL);

    // Create a box to hold the search button image
    GtkWidget *search_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    gtk_container_add(GTK_CONTAINER(search), search_box);

    // Create an image widget for the search button
    search_icon = gtk_image_new_from_file("assets/search_icon.png");
    gtk_widget_set_name(search_icon, "button_search");
    gtk_fixed_put(GTK_FIXED(fixedHome), search_icon, 444, 38);

    // Create the entry widget
    entry_search_bar = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(box), entry_search_bar, TRUE, TRUE, 0);
    gtk_widget_set_size_request(entry_search_bar, 700, 50);

    // Apply custom CSS style to the entry widget
    const gchar *css_entry = "* {"
                             "  background: #292828;"
                             "  color: #FFFFFF;"
                             "  border: 1px solid #000000;"
                             "  border-radius: 15px; /* Adjust the border-radius as per your preference */"
                             "  padding: 0 65px; /* Adjust the padding as per your preference */"
                             "  margin: -3px;"
                             "}";

    GtkCssProvider *css_provider_entry = gtk_css_provider_new();
    gtk_css_provider_load_from_data(css_provider_entry, css_entry, -1, NULL);
    gtk_style_context_add_provider(gtk_widget_get_style_context(entry_search_bar),
                                   GTK_STYLE_PROVIDER(css_provider_entry),
                                   GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);

    // Create the exit button
    exit_button = gtk_button_new();
    gtk_fixed_put(GTK_FIXED(fixedHome), exit_button, 1450, 0);
    gtk_widget_set_size_request(exit_button, 50, 50);
    gtk_button_set_relief(GTK_BUTTON(exit_button), GTK_RELIEF_NONE);

    // Create an image widget for the exit button
    exit_icon = gtk_image_new_from_file("assets/exit_icon.png");
    gtk_button_set_image(GTK_BUTTON(exit_button), exit_icon);

    g_signal_connect(exit_button, "clicked", G_CALLBACK(exit), NULL);
}

void homePageShow()
{
    homeView = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_decorated(GTK_WINDOW(homeView), FALSE);
    gtk_window_set_position(GTK_WINDOW(homeView), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(homeView), 1500, 800);
    gtk_window_set_title(GTK_WINDOW(homeView), "Mystic melody");

    // Tạo GtkstyleContextSignIn cho cửa sổ intro
    styleContextHome = gtk_widget_get_style_context(homeView);

    // Áp dụng các thuộc tính CSS tùy chỉnh cho cửa sổ intro
    gtk_style_context_add_class(styleContextHome, "home-window");

    fixedHome = gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(homeView), fixedHome);

    // Đăng ký bộ chọn CSS
    providerHome = gtk_css_provider_new();
    gtk_css_provider_load_from_path(providerHome, "assets\\css\\home.css", NULL);
    gtk_style_context_add_provider(styleContextHome, GTK_STYLE_PROVIDER(providerHome),
                                   GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);


    scrolledHome = gtk_scrolled_window_new(NULL, NULL);
    gtk_widget_set_size_request(scrolledHome, 1020, 510);
    gtk_fixed_put(GTK_FIXED(fixedHome), scrolledHome, 400, 170);

    mainMenuShow();
    musicBarShow();
    headerBarShow();
    tab_label = gtk_label_new("");
    gtk_fixed_put(GTK_FIXED(fixedHome), tab_label, 155, 115);

    // Lấy layout của label
    PangoLayout *layout = gtk_label_get_layout(GTK_LABEL(tab_label));

    // Thay đổi kích thước và độ đậm của label
    PangoFontDescription *font_desc = pango_font_description_new();
    pango_font_description_set_weight(font_desc, PANGO_WEIGHT_BOLD);
    pango_font_description_set_size(font_desc, 24 * PANGO_SCALE);
    pango_layout_set_font_description(layout, font_desc);
    explorerTab();
    gtk_widget_show_all(homeView);


    gtk_main();
}
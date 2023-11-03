//
// Created by laphv on 8/26/2023.
//

#include "SignInPage.h"
#include "query/userQuery.h"
#include "page/HomePage.h"
#include "page/SignUpPage.h"
#include "models/userModel.h"
GtkWidget *providerSignIn;
GtkWidget *fixedSignIn, *signInView;
gboolean passwordVisible = FALSE;
GtkWidget *entryPasswordSignIn;
GtkWidget *entryUsernameSignIn;
GtkWidget *passwordStatusLabel;
GtkStyleContext *styleContextSignIn;
GtkWidget *checkbox;

void show_password_status_label(const gchar *message) {
    gtk_label_set_text(GTK_LABEL(passwordStatusLabel), message);
}

void button_Sign_In_clicked(GtkWidget *widget, gpointer data) {
    // Kiểm tra mật khẩu
    const gchar *enteredPassword = gtk_entry_get_text(GTK_ENTRY(entryPasswordSignIn));
    const gchar *enterUserName = gtk_entry_get_text(GTK_ENTRY(entryUsernameSignIn));
    if (checkSignIn(enterUserName, enteredPassword) == 0) {
        // Mật khẩu chính xác, thực hiện các xử lý tiếp theo
        show_password_status_label("Successful");
        gboolean active = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(checkbox));
        if(active)
        {
            FILE *file;
            file = fopen("database\\Temp.txt", "w");  // Mở file trong chế độ ghi thêm ("a")

            if (file == NULL) {
                printf("Không thể mở file.\n");
            }

            // Ghi hai dòng vào file
            fprintf(file, enterUserName );



            // Đóng file
            fclose(file);
            printf("Saved account in Temp\n");
        }
        setUserName(enterUserName);
        g_timeout_add_seconds(0, (GSourceFunc) gtk_widget_destroy, signInView);
        g_timeout_add_seconds(0, (GSourceFunc) homePageShow, signInView);

    } else {
        // Hiển thị thông báo lỗi
        show_password_status_label("YOUR USERNAME OR PASSWORD IS INCORRECT, PLEASE TRY AGAIN");
    }
}

void Sign_Up_clicked(GtkWidget *widget, gpointer data) {
    g_timeout_add_seconds(1, (GSourceFunc) gtk_widget_destroy, signInView);
    g_timeout_add_seconds(1, (GSourceFunc) signUpShow, signInView);
}

void togglePasswordVisibility(GtkImage *togglebutton, GtkWidget *entry) {
    passwordVisible = !passwordVisible;  // Đảo ngược trạng thái hiển thị mật khẩu

    // Thực hiện các thay đổi tương ứng dựa trên trạng thái hiện tại
    if (passwordVisible) {
        gtk_entry_set_visibility(GTK_ENTRY(entry), TRUE);  // Hiển thị mật khẩu

        GdkPixbuf *icon = gdk_pixbuf_new_from_file("assets\\image\\show.svg", NULL);
        GtkWidget *newImage = gtk_image_new_from_pixbuf(icon);
        gtk_button_set_image(GTK_BUTTON(togglebutton), newImage);
    } else {
        gtk_entry_set_visibility(GTK_ENTRY(entry), FALSE);  // Ẩn mật khẩu

        GdkPixbuf *icon = gdk_pixbuf_new_from_file("assets\\image\\hide.svg", NULL);
        GtkWidget *newImage = gtk_image_new_from_pixbuf(icon);
        gtk_button_set_image(GTK_BUTTON(togglebutton), newImage);
    }
}

void signInShow()
{
    // Tạo một cửa sổ mới
    signInView = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_decorated(GTK_WINDOW(signInView), FALSE);
    gtk_window_set_title(GTK_WINDOW(signInView), "Login");
    gtk_window_set_default_size(GTK_WINDOW(signInView), 500, 700);
    gtk_window_set_position(GTK_WINDOW(signInView), GTK_WIN_POS_CENTER);

    // Tạo GtkstyleContextSignIn cho cửa sổ intro
    styleContextSignIn = gtk_widget_get_style_context(signInView);

    // Áp dụng các thuộc tính CSS tùy chỉnh cho cửa sổ intro
    gtk_style_context_add_class(styleContextSignIn, "sign-in-window");

    // Tạo một đối tượng fixed container
    fixedSignIn = gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(signInView), fixedSignIn);


    // Đăng ký bộ chọn CSS
    providerSignIn = gtk_css_provider_new();
    gtk_css_provider_load_from_path(providerSignIn, "assets\\css\\signIn.css", NULL);
    gtk_style_context_add_provider(styleContextSignIn, GTK_STYLE_PROVIDER(providerSignIn),
                                   GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);

    // Label_MysticMelody
    GtkWidget *label_MysticMelody = gtk_label_new("MYSTIC MELODY");
    gtk_widget_set_size_request(label_MysticMelody, 272, 34);
    gtk_fixed_put(GTK_FIXED(fixedSignIn), label_MysticMelody, 114, 202);
    gtk_widget_set_name(label_MysticMelody, "label_MysticMelody");
    gtk_style_context_add_provider(gtk_widget_get_style_context(label_MysticMelody), GTK_STYLE_PROVIDER(providerSignIn),
                                   GTK_STYLE_PROVIDER_PRIORITY_USER);

    // Label_Don'tHave
    GtkWidget *label_DonnotHave = gtk_label_new("Don't have an account?");
    gtk_widget_set_size_request(label_DonnotHave, 229, 19);
    gtk_fixed_put(GTK_FIXED(fixedSignIn), label_DonnotHave, 92, 626);
    gtk_widget_set_name(label_DonnotHave, "label_DonnotHave");
    gtk_style_context_add_provider(gtk_widget_get_style_context(label_DonnotHave), GTK_STYLE_PROVIDER(providerSignIn),
                                   GTK_STYLE_PROVIDER_PRIORITY_USER);

    // Label_SIGNUP
    GtkWidget *label_SignUp = gtk_label_new("SIGN UP");
    gtk_widget_set_size_request(label_SignUp, 80, 24);
    gtk_fixed_put(GTK_FIXED(fixedSignIn), label_SignUp, 328, 626);
    gtk_widget_set_name(label_SignUp, "label_SignUp");
    gtk_style_context_add_provider(gtk_widget_get_style_context(label_SignUp), GTK_STYLE_PROVIDER(providerSignIn),
                                   GTK_STYLE_PROVIDER_PRIORITY_USER);

    // Logo
    GtkWidget *Logo = gtk_image_new_from_file("assets\\image\\logo.png");
    gtk_widget_set_size_request(Logo, 164, 171);
    gtk_fixed_put(GTK_FIXED(fixedSignIn), Logo, 168, 31);
    gtk_widget_set_name(Logo, "Logo");
    gtk_style_context_add_provider(gtk_widget_get_style_context(Logo), GTK_STYLE_PROVIDER(providerSignIn),
                                   GTK_STYLE_PROVIDER_PRIORITY_USER);

    // Logo_account
    GtkWidget *Logo_account = gtk_image_new_from_file("assets\\image\\user.svg");
    gtk_widget_set_size_request(Logo_account, 20, 20);
    gtk_fixed_put(GTK_FIXED(fixedSignIn), Logo_account, 61, 320);
    gtk_widget_set_name(Logo_account, "Logo_account");
    gtk_style_context_add_provider(gtk_widget_get_style_context(Logo_account), GTK_STYLE_PROVIDER(providerSignIn),
                                   GTK_STYLE_PROVIDER_PRIORITY_USER);

    // Logo_password
    GtkWidget *Logo_password = gtk_image_new_from_file("assets\\image\\padlock.svg");
    gtk_widget_set_size_request(Logo_password, 20, 20);
    gtk_fixed_put(GTK_FIXED(fixedSignIn), Logo_password, 61, 428);
    gtk_widget_set_name(Logo_password, "Logo_password");
    gtk_style_context_add_provider(gtk_widget_get_style_context(Logo_password), GTK_STYLE_PROVIDER(providerSignIn),
                                   GTK_STYLE_PROVIDER_PRIORITY_USER);

    //passwordStatusLabel
    passwordStatusLabel = gtk_label_new(NULL);
    gtk_widget_set_name(passwordStatusLabel, "passwordStatusLabel");
    gtk_widget_set_size_request(passwordStatusLabel, 431, 14);
    gtk_fixed_put(GTK_FIXED(fixedSignIn), passwordStatusLabel, 30, 266);
    gtk_style_context_add_provider(gtk_widget_get_style_context(passwordStatusLabel), GTK_STYLE_PROVIDER(providerSignIn),
                                   GTK_STYLE_PROVIDER_PRIORITY_USER);

    // button Sign in
    GtkWidget *button_Sign_In = gtk_button_new_with_label("SIGN IN");
    gtk_widget_set_size_request(button_Sign_In, 320, 65);
    gtk_fixed_put(GTK_FIXED(fixedSignIn), button_Sign_In, 90, 529);
    gtk_widget_set_name(button_Sign_In, "button_Sign_In");
    gtk_style_context_add_provider(gtk_widget_get_style_context(button_Sign_In), GTK_STYLE_PROVIDER(providerSignIn),
                                   GTK_STYLE_PROVIDER_PRIORITY_USER);

    // Entry Username
    entryUsernameSignIn = gtk_entry_new();
    gtk_widget_set_size_request(entryUsernameSignIn, 330, 40);
    gtk_fixed_put(GTK_FIXED(fixedSignIn), entryUsernameSignIn, 83.96, 310);
    gtk_entry_set_placeholder_text(GTK_ENTRY(entryUsernameSignIn), "USERNAME");
    gtk_widget_set_name(entryUsernameSignIn, "Entry_Username");
    gtk_style_context_add_provider(gtk_widget_get_style_context(entryUsernameSignIn), GTK_STYLE_PROVIDER(providerSignIn),
                                   GTK_STYLE_PROVIDER_PRIORITY_USER);

    // Entry password
    entryPasswordSignIn = gtk_entry_new();
    gtk_entry_set_visibility(GTK_ENTRY(entryPasswordSignIn), FALSE); // Ẩn mật khẩu
    gtk_widget_set_size_request(entryPasswordSignIn, 330, 40);
    gtk_fixed_put(GTK_FIXED(fixedSignIn), entryPasswordSignIn, 83.96, 418);
    gtk_entry_set_placeholder_text(GTK_ENTRY(entryPasswordSignIn), "PASSWORD");
    gtk_widget_set_name(entryPasswordSignIn, "Entry_Password");
    gtk_style_context_add_provider(gtk_widget_get_style_context(entryPasswordSignIn), GTK_STYLE_PROVIDER(providerSignIn),
                                   GTK_STYLE_PROVIDER_PRIORITY_USER);

    // Tạo một GtkImage làm nút ToggleButton mặc định là hide
    GtkWidget *toggleButton = gtk_toggle_button_new();
    gtk_button_set_image(GTK_BUTTON(toggleButton), gtk_image_new_from_file("assets\\image\\hide.svg"));
    gtk_widget_set_size_request(toggleButton, 24, 17);
    gtk_fixed_put(GTK_FIXED(fixedSignIn), toggleButton, 415, 422);
    gtk_widget_set_name(toggleButton, "toggleButton");
    gtk_style_context_add_provider(gtk_widget_get_style_context(toggleButton), GTK_STYLE_PROVIDER(providerSignIn),
                                   GTK_STYLE_PROVIDER_PRIORITY_USER);

    // Tạo checkbox
    checkbox = gtk_check_button_new_with_label("REMEMBER ME");
    gtk_widget_set_size_request(checkbox, 23, 23);
    gtk_fixed_put(GTK_FIXED(fixedSignIn), checkbox, 59, 481);
    gtk_widget_set_name(checkbox, "checkbox");
    gtk_style_context_add_provider(gtk_widget_get_style_context(checkbox), GTK_STYLE_PROVIDER(providerSignIn),
                                   GTK_STYLE_PROVIDER_PRIORITY_USER);
    // Tạo button cho mỗi frame
    GtkWidget *song_frame_button = gtk_button_new();
    gtk_widget_set_size_request(song_frame_button , 80, 24);
    gtk_fixed_put(GTK_FIXED(fixedSignIn), song_frame_button , 328, 626);
    gtk_button_set_relief(GTK_BUTTON(song_frame_button ), GTK_RELIEF_NONE);

    g_signal_connect(song_frame_button, "clicked", G_CALLBACK(Sign_Up_clicked), NULL);

    // Signal
    g_signal_connect(button_Sign_In, "clicked", G_CALLBACK(button_Sign_In_clicked), NULL);
    g_signal_connect(toggleButton, "toggled", G_CALLBACK(togglePasswordVisibility), entryPasswordSignIn);

    gtk_widget_show_all(signInView);
    gtk_main();
}
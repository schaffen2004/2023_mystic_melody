//
// Created by laphv on 8/26/2023.
//

#include "SignUpPage.h"
#include "page/SignInPage.h"
#include "query/userQuery.h"
GtkWidget *providerSignUp;
GtkWidget *fixedSignUp, *signUpPage,*Entry_Username;
gboolean passwordVisibleSignUp = FALSE;
GtkWidget *passwordStatusLabelSignUp;
GtkWidget *Entry_Password,*Entry_Repassword;
GtkWidget *providerSignUp;
GtkStyleContext *styleContextSignUp;
void showPasswordStatus(const gchar *message) {
    gtk_label_set_text(GTK_LABEL(passwordStatusLabelSignUp), message);
}
void buttonSignIn()
{
    g_timeout_add_seconds(0, (GSourceFunc) gtk_widget_destroy, signUpPage);
    g_timeout_add_seconds(0, (GSourceFunc) signInShow, signUpPage);
}
void buttonSignUpClicked(GtkWidget *widget, gpointer data) {
    // Kiểm tra mật khẩu
    const gchar *entered_username = gtk_entry_get_text(GTK_ENTRY(Entry_Username));
    const gchar *entered_password = gtk_entry_get_text(GTK_ENTRY(Entry_Password));
    const gchar *correct_password = gtk_entry_get_text(GTK_ENTRY(Entry_Repassword)); // Thay "your_password" bằng mật khẩu chính xác

    if (strcmp(entered_password, correct_password) == 0) {
        if(addAccount(entered_username,entered_password)==LOGIN_OK)
        {
            g_timeout_add_seconds(0, (GSourceFunc) gtk_widget_destroy, signUpPage);
            g_timeout_add_seconds(0, (GSourceFunc) signInShow, signUpPage);
            printf("Sign up successfully!");
        }
    } else {
        // Hiển thị thông báo lỗi
        showPasswordStatus("YOUR PASSWORD IS INCORRECT!PLEASE TRY AGAIN.");
    }
}
void Sign_In_clicked(GtkWidget *widget, gpointer data){
    // Xử lý sự kiện khi nhấn label "Sign In"
}
void togglePasswordVisibilitySignUp(GtkImage *togglebutton, GtkWidget *entry) {
    passwordVisibleSignUp = !passwordVisibleSignUp;  // Đảo ngược trạng thái hiển thị mật khẩu

    // Thực hiện các thay đổi tương ứng dựa trên trạng thái hiện tại
    if (passwordVisibleSignUp) {
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

void signUpShow()
{

    // Tạo một cửa sổ mới
    signUpPage = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_decorated(GTK_WINDOW(signUpPage), FALSE);
    gtk_window_set_title(GTK_WINDOW(signUpPage), "SignUp");
    gtk_window_set_default_size(GTK_WINDOW(signUpPage), 500, 700);
    gtk_window_set_position(GTK_WINDOW(signUpPage), GTK_WIN_POS_CENTER);

    // Tạo GtkstyleContextSignIn cho cửa sổ intro
    styleContextSignUp = gtk_widget_get_style_context(signUpPage);

    // Áp dụng các thuộc tính CSS tùy chỉnh cho cửa sổ intro
    gtk_style_context_add_class(styleContextSignUp, "sign-up-window");
    // Tạo một đối tượng fixedSignUp container
    fixedSignUp = gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(signUpPage), fixedSignUp);

    // Đăng ký bộ chọn CSS
    providerSignUp = gtk_css_provider_new();
    gtk_css_provider_load_from_path(providerSignUp, "assets\\CSS\\signUp.css", NULL);
    gtk_style_context_add_provider(styleContextSignUp, GTK_STYLE_PROVIDER(providerSignUp),
                                   GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);

    // Label_MysticMelody
    GtkWidget *label_MysticMelody = gtk_label_new("MYSTIC MELODY");
    gtk_widget_set_size_request(label_MysticMelody, 272, 34);
    gtk_fixed_put(GTK_FIXED(fixedSignUp), label_MysticMelody, 114, 183);
    gtk_widget_set_name(label_MysticMelody, "label_MysticMelody");
    gtk_style_context_add_provider(gtk_widget_get_style_context(label_MysticMelody), GTK_STYLE_PROVIDER(providerSignUp), GTK_STYLE_PROVIDER_PRIORITY_USER);

    // Label_Already
    GtkWidget *Label_Already = gtk_label_new("Already have a account?");
    gtk_widget_set_size_request(Label_Already, 255, 19);
    gtk_fixed_put(GTK_FIXED(fixedSignUp), Label_Already, 83, 651);
    gtk_widget_set_name(Label_Already, "Label_Already");
    gtk_style_context_add_provider(gtk_widget_get_style_context(Label_Already), GTK_STYLE_PROVIDER(providerSignUp), GTK_STYLE_PROVIDER_PRIORITY_USER);

    // Label_SignIn
    GtkWidget * label_SignIn = gtk_label_new("SIGN IN");
    gtk_widget_set_size_request( label_SignIn, 78, 24);
    gtk_fixed_put(GTK_FIXED(fixedSignUp),  label_SignIn, 339, 651);
    gtk_widget_set_name( label_SignIn, "label_SignIn");
    gtk_style_context_add_provider(gtk_widget_get_style_context( label_SignIn), GTK_STYLE_PROVIDER(providerSignUp), GTK_STYLE_PROVIDER_PRIORITY_USER);

    // Logo
    GtkWidget *Logo = gtk_image_new_from_file("assets\\image\\logo.png");
    gtk_widget_set_size_request(Logo, 164, 171);
    gtk_fixed_put(GTK_FIXED(fixedSignUp), Logo, 168, 12);
    gtk_widget_set_name( Logo, "Logo");
    gtk_style_context_add_provider(gtk_widget_get_style_context( Logo), GTK_STYLE_PROVIDER(providerSignUp), GTK_STYLE_PROVIDER_PRIORITY_USER);

    // Logo_account
    GtkWidget *Logo_account = gtk_image_new_from_file("assets\\image\\user.svg");
    gtk_widget_set_size_request(Logo_account, 20, 20);
    gtk_fixed_put(GTK_FIXED(fixedSignUp), Logo_account, 61, 301);
    gtk_widget_set_name( Logo_account, "Logo");
    gtk_style_context_add_provider(gtk_widget_get_style_context( Logo_account), GTK_STYLE_PROVIDER(providerSignUp), GTK_STYLE_PROVIDER_PRIORITY_USER);

    // Logo_password
    GtkWidget *Logo_password = gtk_image_new_from_file("assets\\image\\padlock.svg");
    gtk_widget_set_size_request(Logo_password, 20, 20);
    gtk_fixed_put(GTK_FIXED(fixedSignUp), Logo_password, 61, 396);
    gtk_widget_set_name( Logo_password, "LogoAc");
    gtk_style_context_add_provider(gtk_widget_get_style_context( Logo_password), GTK_STYLE_PROVIDER(providerSignUp), GTK_STYLE_PROVIDER_PRIORITY_USER);

    // Logo_Repassword
    GtkWidget *Logo_Repassword = gtk_image_new_from_file("assets\\image\\padlock.svg");
    gtk_widget_set_size_request(Logo_Repassword, 20, 20);
    gtk_fixed_put(GTK_FIXED(fixedSignUp), Logo_Repassword, 61, 480);
    gtk_widget_set_name( Logo_Repassword, "LogoaC");
    gtk_style_context_add_provider(gtk_widget_get_style_context( Logo_Repassword), GTK_STYLE_PROVIDER(providerSignUp), GTK_STYLE_PROVIDER_PRIORITY_USER);

    //passwordStatusLabelSignUp
    passwordStatusLabelSignUp = gtk_label_new(NULL);
    gtk_widget_set_name(passwordStatusLabelSignUp, "passwordStatusLabelSignUp");
    gtk_widget_set_size_request(passwordStatusLabelSignUp, 360, 21);
    gtk_fixed_put(GTK_FIXED(fixedSignUp), passwordStatusLabelSignUp, 83, 247);
    gtk_style_context_add_provider(gtk_widget_get_style_context(passwordStatusLabelSignUp), GTK_STYLE_PROVIDER(providerSignUp), GTK_STYLE_PROVIDER_PRIORITY_USER);

    // button Sign up
    GtkWidget *button_Sign_up = gtk_button_new_with_label("SIGN UP");
    gtk_widget_set_size_request(button_Sign_up, 320, 65);
    gtk_fixed_put(GTK_FIXED(fixedSignUp), button_Sign_up, 90, 556);
    gtk_widget_set_name(button_Sign_up, "button_Sign_up");
    gtk_style_context_add_provider(gtk_widget_get_style_context(button_Sign_up), GTK_STYLE_PROVIDER(providerSignUp), GTK_STYLE_PROVIDER_PRIORITY_USER);

    // Entry Username
    Entry_Username = gtk_entry_new();
    gtk_widget_set_size_request(Entry_Username, 330, 40);
    gtk_fixed_put(GTK_FIXED(fixedSignUp), Entry_Username, 83.96, 291);
    gtk_entry_set_placeholder_text(GTK_ENTRY(Entry_Username), "USERNAME");
    gtk_widget_set_name(Entry_Username, "Entry_Username");
    gtk_style_context_add_provider(gtk_widget_get_style_context(Entry_Username), GTK_STYLE_PROVIDER(providerSignUp), GTK_STYLE_PROVIDER_PRIORITY_USER);

    // Entry password
    Entry_Password = gtk_entry_new();
    gtk_entry_set_visibility(GTK_ENTRY(Entry_Password), FALSE); // Ẩn mật khẩu
    gtk_widget_set_size_request(Entry_Password, 330, 40);
    gtk_fixed_put(GTK_FIXED(fixedSignUp), Entry_Password, 83.96, 386);
    gtk_entry_set_placeholder_text(GTK_ENTRY(Entry_Password), "PASSWORD");
    gtk_widget_set_name(Entry_Password, "Entry_Password");
    gtk_style_context_add_provider(gtk_widget_get_style_context(Entry_Password), GTK_STYLE_PROVIDER(providerSignUp), GTK_STYLE_PROVIDER_PRIORITY_USER);

    // Entry Repassword
    Entry_Repassword = gtk_entry_new();
    gtk_entry_set_visibility(GTK_ENTRY(Entry_Repassword), FALSE); // Ẩn mật khẩu
    gtk_widget_set_size_request(Entry_Repassword, 330, 40);
    gtk_fixed_put(GTK_FIXED(fixedSignUp), Entry_Repassword, 83.96, 470);
    gtk_entry_set_placeholder_text(GTK_ENTRY(Entry_Repassword), "REPEAT PASSWORD");
    gtk_widget_set_name(Entry_Repassword, "Entry_Password");
    gtk_style_context_add_provider(gtk_widget_get_style_context(Entry_Repassword), GTK_STYLE_PROVIDER(providerSignUp), GTK_STYLE_PROVIDER_PRIORITY_USER);

    // Tạo một GtkImage làm nút ToggleButton mặc định là hide
    GtkWidget *toggleButton1 = gtk_toggle_button_new();
    gtk_button_set_image(GTK_BUTTON(toggleButton1), gtk_image_new_from_file("assets\\image\\hide.svg"));
    gtk_widget_set_size_request(toggleButton1, 24, 17);
    gtk_widget_set_name(toggleButton1, "toggleButton");
    gtk_fixed_put(GTK_FIXED(fixedSignUp), toggleButton1, 415, 390);
    gtk_style_context_add_provider(gtk_widget_get_style_context(toggleButton1), GTK_STYLE_PROVIDER(providerSignUp),
                                   GTK_STYLE_PROVIDER_PRIORITY_USER);

    // Tạo một GtkImage làm nút ToggleButton mặc định là hide
    GtkWidget *toggleButton2 = gtk_toggle_button_new();
    gtk_button_set_image(GTK_BUTTON(toggleButton2), gtk_image_new_from_file("assets\\image\\hide.svg"));
    gtk_widget_set_size_request(toggleButton2, 24, 17);
    gtk_fixed_put(GTK_FIXED(fixedSignUp), toggleButton2, 415, 473);
    gtk_widget_set_name(toggleButton2, "toggleButton");
    gtk_style_context_add_provider(gtk_widget_get_style_context(toggleButton2), GTK_STYLE_PROVIDER(providerSignUp),
                                   GTK_STYLE_PROVIDER_PRIORITY_USER);

    // Tạo button cho mỗi frame
    GtkWidget *song_frame_button = gtk_button_new();
    gtk_widget_set_size_request(song_frame_button , 78, 24);
    gtk_fixed_put(GTK_FIXED(fixedSignUp), song_frame_button , 339, 651);
    gtk_button_set_relief(GTK_BUTTON(song_frame_button ), GTK_RELIEF_NONE);

    g_signal_connect(song_frame_button, "clicked", G_CALLBACK(buttonSignIn), NULL);
    // Signal
    g_signal_connect(button_Sign_up, "clicked", G_CALLBACK(buttonSignUpClicked), NULL);
    g_signal_connect(toggleButton1, "toggled", G_CALLBACK(togglePasswordVisibilitySignUp), Entry_Password);
    g_signal_connect(toggleButton2, "toggled", G_CALLBACK(togglePasswordVisibilitySignUp), Entry_Repassword);

    // Hiển thị tất cả các widget và bắt đầu vòng lặp chính
    gtk_widget_show_all(signUpPage);
    gtk_main();
}
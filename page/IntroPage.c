//
// Created by laphv on 8/26/2023.
//

#include "IntroPage.h"
#include "page/SignInPage.h"
#include "utils/loadTemp.h"
#include "models/userModel.h"
#include "page/HomePage.h"
#include "utils/sys.h"

GtkWidget *introView,*introLogo;
GdkPixbuf *accessIntroLogo;
GtkStyleContext *styleContextIntro;

void introShow()
{
    statusProcess = NOT_STARTED;
    statusPlaying = STOP;
    // Tạo cửa sổ intro
    introView = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    gtk_window_set_default_size(GTK_WINDOW(introView), 500, 500);
    gtk_window_set_decorated(GTK_WINDOW(introView), FALSE);
    gtk_window_set_position(GTK_WINDOW(introView), GTK_WIN_POS_CENTER_ALWAYS);

    // Tạo GtkstyleContextSignIn cho cửa sổ intro
    styleContextIntro = gtk_widget_get_style_context(introView);

    // Áp dụng các thuộc tính CSS tùy chỉnh cho cửa sổ intro
    gtk_style_context_add_class(styleContextIntro, "intro-window");

    // Đăng ký bộ chọn CSS
    GtkCssProvider *cssProvider = gtk_css_provider_new();
    gtk_css_provider_load_from_path(cssProvider, "assets\\css\\intro.css", NULL);
    gtk_style_context_add_provider(styleContextIntro, GTK_STYLE_PROVIDER(cssProvider),
                                   GTK_STYLE_PROVIDER_PRIORITY_USER);

    g_signal_connect(G_OBJECT(introView), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    //show logo app
    accessIntroLogo = gdk_pixbuf_new_from_file("assets\\image\\logo.png", NULL);
    introLogo = gtk_image_new_from_pixbuf(accessIntroLogo);
    gtk_container_add(GTK_CONTAINER(introView), introLogo);


    gtk_widget_show_all(introView);

    printf("Loading temp...\n");
    getAccountTemp();
    if(strlen(accountTemp) == 0)
    {
        printf("Sign in a new account\n",accountTemp);
        //change intro_window
        g_timeout_add_seconds(1, (GSourceFunc)gtk_widget_destroy, introView);
        g_timeout_add_seconds(1, (GSourceFunc)signInShow, introView);
    }
    else{
        printf("Accessing the account: %s\n",accountTemp);
        setUserName(accountTemp);
        //change intro_window
        g_timeout_add_seconds(1, (GSourceFunc)gtk_widget_destroy, introView);
        g_timeout_add_seconds(1, (GSourceFunc)homePageShow, introView);
    }


    gtk_main();
}
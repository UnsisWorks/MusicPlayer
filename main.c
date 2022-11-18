#include <gtk/gtk.h>
// #include <mysql.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
// #include "Cola.c"

GtkWidget *mainWindow, *initWindow, *box, *initLayout;

/**
 * It creates a window with a vertical box, which contains 5 buttons
 * 
 * @param app The GtkApplication instance.
 * @param user_data This is a pointer to any data you want to pass to the callback function.
 */
static void activate (GtkApplication *app, gpointer user_data) {
    GtkWidget *mainLayout, *controlsSection, *musicSection, *background;
    GtkWidget *timeMusic;
    GtkCssProvider *cssProvider;

    mainLayout = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    // mainLayout = gtk_layout_new(NULL, NULL);
    controlsSection = gtk_layout_new(NULL, NULL);
    musicSection = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_box_set_homogeneous(GTK_BOX(musicSection), FALSE);
    gtk_box_set_homogeneous(GTK_BOX(mainLayout), FALSE);
    cssProvider = gtk_css_provider_new();
    // gtk_style_context_add_class(gtk_widget_get_style_context(buttonAcer), "button");
        
    gtk_widget_set_name(GTK_WIDGET(musicSection), "music-section");
    gtk_widget_set_name(GTK_WIDGET(controlsSection), "controls-section");
    gtk_widget_set_name(GTK_WIDGET(mainLayout), "box");

    gtk_box_pack_start(GTK_BOX(mainLayout), musicSection, TRUE, FALSE, 20);
    gtk_box_pack_end(GTK_BOX(mainLayout), controlsSection, TRUE, FALSE, 20);

    // Set properties for winow
    mainWindow = gtk_application_window_new (app);
    gtk_window_set_position(GTK_WINDOW(mainWindow), GTK_WIN_POS_CENTER);
    gtk_window_set_title(GTK_WINDOW (mainWindow), "Music");
    // gtk_window_fullscreen(GTK_WINDOW(mainWindow));
    // gtk_window_set_resizable(GTK_WINDOW(mainWindow), FALSE);
    gtk_window_set_opacity(GTK_WINDOW(mainWindow), 0.95);
    gtk_widget_realize(mainWindow);

    // COMPONENTS FOR MUSIC SECTION
    timeMusic = gtk_scale_new_with_range(GTK_ORIENTATION_HORIZONTAL, 0, 100, 1);
    gtk_scale_set_value_pos(GTK_SCALE(timeMusic), 0);

    gtk_container_add(GTK_CONTAINER(controlsSection), timeMusic);

    // COMPONENTS FOR CONTROLS SECTION
    GtkWidget *title;
    title = gtk_label_new("Name");
    gtk_container_add(GTK_CONTAINER(musicSection), title);

    // Load CSS file
    gtk_css_provider_load_from_path(cssProvider, "./style.css", NULL);
    gtk_style_context_add_provider_for_screen(gdk_screen_get_default(),
                                            GTK_STYLE_PROVIDER(cssProvider),
                                            GTK_STYLE_PROVIDER_PRIORITY_USER);

    gtk_container_add(GTK_CONTAINER(mainWindow), mainLayout);
    gtk_widget_show_all (mainWindow);
}

// funtion main
int main (int argc, char **argv) {
    GtkApplication *app;
    int status;
    app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
    g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
    status = g_application_run (G_APPLICATION (app), argc, argv);
    g_object_unref (app);

    return status;
}

// Compiler gcc `pkg-config --cflags gtk+-3.0` -o main main.c `pkg-config --libs gtk+-3.0` 
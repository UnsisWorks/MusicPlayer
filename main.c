#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <pthread.h>

GtkWidget *mainWindow, *initWindow, *box, *initLayout;

int initSound(){

    if (!al_init()){
        fprintf(stderr, "failed to initialize allegro!\n");
        return -1;
    }

    if (!al_install_audio()){
        fprintf(stderr, "failed to initialize audio!\n");
        return -1;
    }

    if (!al_init_acodec_addon()){
        fprintf(stderr, "failed to initialize audio codecs!\n");
        return -1;
    }

    if (!al_reserve_samples(10)){
        fprintf(stderr, "failed to reserve samples!\n");
        return -1;
    }

    al_init_acodec_addon();

    ALLEGRO_SAMPLE_INSTANCE *sampleInstance;
    ALLEGRO_SAMPLE *sample = al_load_sample("./sound/sound.wav"); //sample always NULL
    sampleInstance = al_create_sample_instance(sample);
    al_set_sample_instance_playmode(sampleInstance, ALLEGRO_PLAYMODE_BIDIR);
    al_attach_sample_instance_to_mixer(sampleInstance, al_get_default_mixer());

    if (!sample){
        printf("Audio clip sample not loaded!\n");
        return -1;
    }

    // Play song
    // al_play_sample_instance(sampleInstance);

    al_rest(10.0);

    return 0;
}
// Function for thread
void *timer (void *data) {
    initSound();
}

/**
 * It creates a window with a vertical box, which contains 5 buttons
 * 
 * @param app The GtkApplication instance.
 * @param user_data This is a pointer to any data you want to pass to the callback function.
 */
static void activate (GtkApplication *app, gpointer user_data) {
    // Create and start threead for timer
    pthread_t initTimer;
    pthread_create(&initTimer, NULL, &timer, NULL);

    GtkWidget *controlsSection, *musicSection, *background, *fixed;
    GtkWidget *timeMusic;
    GtkCssProvider *cssProvider;

    background = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    fixed = gtk_fixed_new();
    // background = gtk_layout_new(NULL, NULL);
    controlsSection = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    musicSection = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_box_set_homogeneous(GTK_BOX(musicSection), FALSE);
    gtk_box_set_homogeneous(GTK_BOX(background), FALSE);
    cssProvider = gtk_css_provider_new();
    // gtk_style_context_add_class(gtk_widget_get_style_context(buttonAcer), "button");
        
    gtk_widget_set_name(GTK_WIDGET(musicSection), "music-section");
    gtk_widget_set_name(GTK_WIDGET(controlsSection), "controls-section");
    gtk_widget_set_name(GTK_WIDGET(background), "box");

    // Add main sections at window
    gtk_box_set_center_widget(GTK_BOX(background), fixed);
    gtk_fixed_put(GTK_FIXED(fixed), musicSection, 0, 0);
    gtk_fixed_put(GTK_FIXED(fixed), controlsSection, 0, 500);

    // Set properties for winow
    mainWindow = gtk_application_window_new(app);
    gtk_window_set_position(GTK_WINDOW(mainWindow), GTK_WIN_POS_CENTER);
    gtk_window_set_title (GTK_WINDOW (mainWindow), "Music");
    gtk_window_set_default_size (GTK_WINDOW (mainWindow), 200, 200);
    gtk_window_set_opacity(GTK_WINDOW(mainWindow), 0.90);
    gtk_window_maximize(GTK_WINDOW(mainWindow));
    

    // COMPONENTS FOR CONTROLS SECTION
    GtkWidget *buttonBefore, *buttonPlay, *buttonAfter;
    GtkWidget *buttBoxBefore, *buttBoxPlay, *buttBoxAfter, *boxForButtons;

    // Create buttons and box
    boxForButtons = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 25);

    buttonBefore = gtk_button_new_with_label("Ant");
    buttonPlay = gtk_button_new_with_label("Play");
    buttonAfter = gtk_button_new_with_label("Sig");

    buttBoxBefore = gtk_button_box_new(GTK_ORIENTATION_HORIZONTAL);
    buttBoxPlay = gtk_button_box_new(GTK_ORIENTATION_HORIZONTAL);
    buttBoxAfter = gtk_button_box_new(GTK_ORIENTATION_HORIZONTAL);

    gtk_container_add(GTK_CONTAINER(buttBoxBefore), buttonBefore);
    gtk_container_add(GTK_CONTAINER(buttBoxPlay), buttonPlay);
    gtk_container_add(GTK_CONTAINER(buttBoxAfter), buttonAfter);

    gtk_box_pack_start(GTK_BOX(boxForButtons), buttBoxBefore, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(boxForButtons), buttBoxPlay, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(boxForButtons), buttBoxAfter, TRUE, TRUE, 0);

    // Create time line for music
    timeMusic = gtk_scale_new_with_range(GTK_ORIENTATION_HORIZONTAL, 0, 100, 1);
    gtk_scale_set_draw_value(GTK_SCALE(timeMusic), TRUE);
    gtk_widget_set_size_request(GTK_WIDGET(timeMusic), 500, 50);

    // Add timr line and buttons at section the constrols
    gtk_box_pack_start(GTK_BOX(controlsSection), timeMusic, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(controlsSection), boxForButtons, TRUE, TRUE, 0);


    // COMPONENTS FOR MUSICS SECTION
    GtkWidget *title, *nameSongOne;
    GtkWidget *boxForSongs;

    boxForSongs = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
    gtk_widget_set_name(GTK_WIDGET(boxForSongs), "song");
    nameSongOne = gtk_label_new("Rolon de prueba en formato .wav");
    gtk_box_pack_start(GTK_BOX(boxForSongs), nameSongOne, TRUE, TRUE, 5);
    title = gtk_label_new("Name");
    gtk_style_context_add_class(gtk_widget_get_style_context(title), "title");
    gtk_container_add(GTK_CONTAINER(musicSection), title);
    gtk_container_add(GTK_CONTAINER(musicSection), boxForSongs);

    // Load CSS file
    gtk_css_provider_load_from_path(cssProvider, "./style.css", NULL);
    gtk_style_context_add_provider_for_screen(gdk_screen_get_default(),
                                            GTK_STYLE_PROVIDER(cssProvider),
                                            GTK_STYLE_PROVIDER_PRIORITY_USER);

    gtk_container_add(GTK_CONTAINER(mainWindow), background);
    gtk_widget_show_all (mainWindow);
}

// funtion main
int main (int argc, char **argv) {
    GtkApplication *app;
    int status;
    app = gtk_application_new ("org.gtk.music", G_APPLICATION_FLAGS_NONE);
    g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
    status = g_application_run (G_APPLICATION (app), argc, argv);
    g_object_unref (app);

    return status;
}

// Compiler gcc `pkg-config --cflags gtk+-3.0` -o main main.c `pkg-config --libs gtk+-3.0` 

// Compiler: gcc `pkg-config --cflags gtk+-3.0` main.c -I/home/monstruosoft/libs/usr/local/include/ -L/home/monstruosoft/libs/usr/local/lib/* -o main `pkg-config --libs gtk+-3.0`

// gcc `pkg-config --cflags gtk+-3.0` main.c -I/home/monstruosoft/libs/usr/local/include/ -L/home/monstruosoft/libs/usr/local/lib/ -lallegro -lallegro_primitives -lallegro_audio -lallegro_acodec -o main `pkg-config --libs gtk+-3.0` 
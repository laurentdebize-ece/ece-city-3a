#include "structures.h"
#include "../Bitmaps/bitmaps.h"

//Fonction permettant vérifiant l'installation d'Allegro
void installAllegro(){
    assert(al_init());
    assert(al_install_keyboard());//Clavier
    assert(al_install_mouse());//Souris
    assert(al_init_primitives_addon());
    al_init_font_addon();//Polices
    assert(al_init_ttf_addon());//Polices
    assert(al_init_image_addon());

}

///Fonction permettant la déclaration des pointeurs Allegro
void declarerAllegro(Simcity* simcity){
    simcity->allegro.display = NULL;
    simcity->allegro.queue = NULL;
    simcity->allegro.timer = NULL;
    simcity->allegro.chrono = NULL;
    simcity->allegro.fonts[0] = NULL;
}

///Fonction permettant l'initialisation des sources d'évènements Allegro
void registerEvents(Simcity* simcity){
    al_register_event_source(simcity->allegro.queue, al_get_display_event_source(simcity->allegro.display));//Ecran
    al_register_event_source(simcity->allegro.queue, al_get_mouse_event_source());//Souris
    al_register_event_source(simcity->allegro.queue, al_get_keyboard_event_source());//Clavier
    al_register_event_source(simcity->allegro.queue, al_get_timer_event_source(simcity->allegro.timer));//Timer
}

///Fonction permettant l'initialisation de l'écran allegro
void displayCreate(Simcity* simCity) {
    al_set_new_display_flags(ALLEGRO_WINDOWED);
    simCity->allegro.display = al_create_display(SCREEN_LARGEUR, SCREEN_HAUTEUR);
    al_set_window_title(simCity->allegro.display, "SimCity");
    al_set_window_position(simCity->allegro.display, 100, 0);
}

///Fonction permettant l'initialisation de la file d'évènements allegro
void queueCreate(Simcity* simcity){
    simcity->allegro.queue = al_create_event_queue();
}

///Fonction permettant l'initialisation des timers allegro
void timerCreate(Simcity* simcity){
    simcity->allegro.timer = al_create_timer(1/60.0f);//Initialisation du timer à 1/60sec
    simcity->allegro.chrono = al_create_timer(1);//Initialisation du chrono à 1sec
    al_start_timer(simcity->allegro.timer);//Lancement du timer
    al_start_timer(simcity->allegro.chrono);//Lancement du chrono
}

///Fonction permettant l'initialisation des polices allegro
void fontsCreate(Simcity* simcity) {
    simcity->allegro.fonts[0] =  al_load_font("../Sources/polices/barreCompteurs.ttf", 25, 0);//Chargement de la police de la barre des compteurs
}

///Fonction permettant l'initialisation des couleurs allegro
void colorCreate(Simcity* simcity) {
    simcity->allegro.color[BLACK] = al_map_rgb(0,0,0);//Noir
    simcity->allegro.color[WHITE] = al_map_rgb(255,255,255);//Blanc
}

///Fonction permettant l'initialisation générale d'Allegro
void initAllegroAll(Simcity* simcity){
    displayCreate(simcity);//Initialisation de l'écran
    queueCreate(simcity);//Initialisation de la file d'évènements
    timerCreate(simcity);//Initialisation des timers
    registerEvents(simcity);//Initialisation des sources d'évènements
    bitmapCreateAll(simcity);//Initialisation des bitmaps
    fontsCreate(simcity);//Initialisation des polices
    colorCreate(simcity);//Initialisation des couleurs
}

///Fonction permettant la libération de l'écran allegro
void libererDisplay(Simcity* simcity){
    al_destroy_display(simcity->allegro.display);
}

///Fonction permettant la libération des timers allegro
void libererTimer(Simcity* simcity){
    al_destroy_timer(simcity->allegro.timer);
    al_destroy_timer(simcity->allegro.chrono);
}

///Fonction permettant la libération de la file d'évènements allegro
void libererQueue(Simcity* simcity){
    al_destroy_event_queue(simcity->allegro.queue);
}

///Fonction permettant la libération des polices allegro
void libererFonts(Simcity* simcity) {
    al_destroy_font(simcity->allegro.fonts[0]);
}

///Fonction permettant la libération générale d'Allegro
void libererAll(Simcity* simcity){
    libererDisplay(simcity);//Libération de l'écran
    libererQueue(simcity);//Libération de la file d'évènements
    libererTimer(simcity);//Libération des timers
    libererBitmapAll(simcity);//Libération des bitmaps
    libererFonts(simcity);//Libération des polices
}
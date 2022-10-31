#include "structures.h"
#include "../Bitmaps/bitmaps.h"


void installAllegro(){
    assert(al_init());
    assert(al_install_keyboard());
    assert(al_install_mouse());
    assert(al_init_primitives_addon());
    al_init_font_addon();
    assert(al_init_ttf_addon());
    assert(al_init_image_addon());

}

void declarerAllegro(Simcity* simcity){
    simcity->allegro.display = NULL;
    simcity->allegro.queue = NULL;
    simcity->allegro.timer = NULL;
}

void registerEvents(Simcity* simcity){
    al_register_event_source(simcity->allegro.queue, al_get_display_event_source(simcity->allegro.display));
    al_register_event_source(simcity->allegro.queue, al_get_mouse_event_source());
    al_register_event_source(simcity->allegro.queue, al_get_keyboard_event_source());
    al_register_event_source(simcity->allegro.queue, al_get_timer_event_source(simcity->allegro.timer));
}

void displayCreate(Simcity* simCity) {
    al_set_new_display_flags(ALLEGRO_WINDOWED);
    simCity->allegro.display = al_create_display(SCREEN_LARGEUR, SCREEN_HAUTEUR);
    al_set_window_title(simCity->allegro.display, "SimCity");
    al_set_window_position(simCity->allegro.display, 100, 0);
}

void queueCreate(Simcity* simcity){
    simcity->allegro.queue = al_create_event_queue();
}

void timerCreate(Simcity* simcity){
    simcity->allegro.timer = al_create_timer(1/60.0f);
    simcity->allegro.chrono = al_create_timer(1);
    al_start_timer(simcity->allegro.timer);
    al_start_timer(simcity->allegro.chrono);
}

void initAllegroAll(Simcity* simcity){
    displayCreate(simcity);
    queueCreate(simcity);
    timerCreate(simcity);
    registerEvents(simcity);
    bitmapCreateAll(simcity);

}

void libererDisplay(Simcity* simcity){
    al_destroy_display(simcity->allegro.display);
}

void libererTimer(Simcity* simcity){
    al_destroy_timer(simcity->allegro.timer);
    al_destroy_timer(simcity->allegro.chrono);
}

void libererQueue(Simcity* simcity){
    al_destroy_event_queue(simcity->allegro.queue);
}

void libererAll(Simcity* simcity){
    libererDisplay(simcity);
    libererQueue(simcity);
    libererTimer(simcity);
    libererBitmapAll(simcity);
}
#include "bitmaps.h"
#include "../Structures/structures.h"

void bitmapCreateMap(Simcity* simcity){
    simcity->tabBitmap[BITMAP_MAP] = al_load_bitmap("../Sources/img/tiles.png");
}

void bitmapCreateMenuPrincipalIntro(Simcity* simcity){
    simcity->tabBitmap[BITMAP_MENU_PRINCIPAL_INTRO] = al_load_bitmap("../Sources/img/menuPrincipalIntro.png");
}

void bitmapCreateMenuPrincipal(Simcity* simcity){
    simcity->tabBitmap[BITMAP_MENU_PRINCIPAL] = al_load_bitmap("../Sources/img/menuPrincipal.png");
}

void bitmapCreateBoutonMenuPrincipal(Simcity* simcity){
    simcity->tabBitmap[BITMAP_BOUTTON_MENU_PRINCIPAL] = al_load_bitmap("../Sources/img/boutonMenuPrincipal.png");
}

void bitmapCreateToolbox (Simcity* simcity){
    simcity->tabBitmap[BITMAP_TOOLBOX] = al_load_bitmap("../Sources/img/boutonToolbox.png");
}

void bitmapCreateBarreCompteurs (Simcity* simcity) {
    simcity->tabBitmap[BITMAP_BARRECOMPTEURS] = al_load_bitmap("../Sources/img/barreCompteurs.png");
}

void bitmapCreateBoutonsPause(Simcity* simcity){
    simcity->tabBitmap[BITMAP_BOUTON_PAUSE] = al_load_bitmap("../Sources/img/boutonPause.png");
}

void bitmapCreateAll(Simcity* simcity){
    bitmapCreateMap(simcity);
    bitmapCreateMenuPrincipal(simcity);
    bitmapCreateMenuPrincipalIntro(simcity);
    bitmapCreateBoutonMenuPrincipal(simcity);
    bitmapCreateToolbox(simcity);
    bitmapCreateBarreCompteurs(simcity);
    bitmapCreateBoutonsPause(simcity);
}

void libererBitmapMap(Simcity* simcity){
    al_destroy_bitmap(simcity->tabBitmap[BITMAP_MAP]);
}

void libererBitmapMenuPrincipal(Simcity* simcity){
    al_destroy_bitmap(simcity->tabBitmap[BITMAP_MENU_PRINCIPAL]);
}

void libererBitmapMenuPrincipalIntro(Simcity* simcity){
    al_destroy_bitmap(simcity->tabBitmap[BITMAP_MENU_PRINCIPAL_INTRO]);
}

void libererBitmapBoutonMenuPrincipal(Simcity* simcity){
    al_destroy_bitmap(simcity->tabBitmap[BITMAP_BOUTTON_MENU_PRINCIPAL]);
}

void libererBitmapToolbox (Simcity* simcity){
    al_destroy_bitmap(simcity->tabBitmap[BITMAP_TOOLBOX]);
}

void libererBitmapBarreCompteurs (Simcity* simcity) {
    al_destroy_bitmap(simcity->tabBitmap[BITMAP_BARRECOMPTEURS]);
}

void libererBitmapBoutonPause (Simcity* simcity) {
    al_destroy_bitmap(simcity->tabBitmap[BITMAP_BOUTON_PAUSE]);
}

void libererBitmapAll(Simcity* simcity){
    libererBitmapMap(simcity);
    libererBitmapMenuPrincipal(simcity);
    libererBitmapMenuPrincipalIntro(simcity);
    libererBitmapBoutonMenuPrincipal(simcity);
    libererBitmapToolbox(simcity);
    libererBitmapBarreCompteurs(simcity);
    libererBitmapBoutonPause(simcity);
}


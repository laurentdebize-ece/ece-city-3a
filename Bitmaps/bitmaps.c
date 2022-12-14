#include "bitmaps.h"

/////////////////////////////////////// Création des différentes Bitmaps ///////////////////////////////////////

void bitmapCreateMap(Simcity* simcity){
    simcity->tabBitmap[BITMAP_MAP] = al_load_bitmap("../Sources/img/tiles.png");
}

void bitmapCreateFlechesMenuRegles (Simcity* simcity){
    simcity->tabBitmap[BITMAP_FLECHES_MENU_REGLES] = al_load_bitmap("../Sources/img/reglesJeu/FLECHES_MENU_REGLES.png");
}

void bitmapCreateRegle1 (Simcity* simcity){
    simcity->tabBitmap[BITMAP_REGLE_1] = al_load_bitmap("../Sources/img/reglesJeu/reglesJeu1.png");
}

void bitmapCreateRegle2 (Simcity* simcity){
    simcity->tabBitmap[BITMAP_REGLE_2] = al_load_bitmap("../Sources/img/reglesJeu/reglesJeu2.png");
}

void bitmapCreateFeu(Simcity* simcity){
    simcity->tabBitmap[BITMAP_FEU] = al_load_bitmap("../Sources/img/Feu.png");
}

void bitmapCreateTileRuine(Simcity* simcity){
    simcity->tabBitmap[BITMAP_TILE_RUINE] = al_load_bitmap("../Sources/img/tileRuine.png");
}

void bitmapCreateMenuPrincipalIntro(Simcity* simcity){
    simcity->tabBitmap[BITMAP_MENU_PRINCIPAL_INTRO] = al_load_bitmap("../Sources/img/menuPrincipalIntro.png");
}

void bitmapCreateBoutonAide(Simcity* simcity){
    simcity->tabBitmap[BITMAP_BOUTON_AIDE] = al_load_bitmap("../Sources/img/bouton_aide.png");
}

void bitmapCreateMenuPrincipal(Simcity* simcity){
    simcity->tabBitmap[BITMAP_MENU_PRINCIPAL] = al_load_bitmap("../Sources/img/menuPrincipal.png");
}

void bitmapCreateMenuCapitalisteCommuniste(Simcity* simcity){
    simcity->tabBitmap[BITMAP_MENU_COMMUNISTE_CAPITALISTE] = al_load_bitmap("../Sources/img/menu_COM_CAP.png");
}

void bitmapCreateBoutonsMenuCapitalisteCommuniste(Simcity* simcity){
    simcity->tabBitmap[BITMAP_BOUTONS_MENU_COMMUNISTE_CAPITALISTE] = al_load_bitmap("../Sources/img/boutons_menu_COM_CAP.png");
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

///Fonction regroupant la création de toutes les Bitmaps
void bitmapCreateAll(Simcity* simcity){
    bitmapCreateMap(simcity);
    bitmapCreateMenuPrincipal(simcity);
    bitmapCreateMenuPrincipalIntro(simcity);
    bitmapCreateBoutonMenuPrincipal(simcity);
    bitmapCreateToolbox(simcity);
    bitmapCreateBarreCompteurs(simcity);
    bitmapCreateBoutonsPause(simcity);
    bitmapCreateMenuCapitalisteCommuniste(simcity);
    bitmapCreateBoutonsMenuCapitalisteCommuniste(simcity);
    bitmapCreateBoutonAide(simcity);
    bitmapCreateTileRuine(simcity);
    bitmapCreateRegle1(simcity);
    bitmapCreateRegle2(simcity);
    bitmapCreateFeu(simcity);
    bitmapCreateFlechesMenuRegles(simcity);

}


/////////////////////////////////////// Libération des différentes Bitmaps ///////////////////////////////////////

void libererBitmapFlecheRegles (Simcity* simcity){
    al_destroy_bitmap(simcity->tabBitmap[BITMAP_FLECHES_MENU_REGLES]);
}

void libererBitmapRegle1 (Simcity* simcity){
    al_destroy_bitmap(simcity->tabBitmap[BITMAP_REGLE_1]);
}

void libererBitmapRegle2 (Simcity* simcity){
    al_destroy_bitmap(simcity->tabBitmap[BITMAP_REGLE_2]);
}

void libererBitmapMap(Simcity* simcity){
    al_destroy_bitmap(simcity->tabBitmap[BITMAP_MAP]);
}

void libererBitmapMenuPrincipal(Simcity* simcity){
    al_destroy_bitmap(simcity->tabBitmap[BITMAP_MENU_PRINCIPAL]);
}

void libererBitmapMenuCommunisteCapitaliste(Simcity* simcity){
    al_destroy_bitmap(simcity->tabBitmap[BITMAP_MENU_COMMUNISTE_CAPITALISTE]);
}

void libererBitmapBoutonsMenuCommunisteCapitaliste(Simcity* simcity){
    al_destroy_bitmap(simcity->tabBitmap[BITMAP_BOUTONS_MENU_COMMUNISTE_CAPITALISTE]);
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

void libererBitmapBoutonAide (Simcity* simcity){
    al_destroy_bitmap(simcity->tabBitmap[BITMAP_BOUTON_AIDE]);
}

void libererBitmapTileRuine (Simcity* simcity) {
    al_destroy_bitmap(simcity->tabBitmap[BITMAP_TILE_RUINE]);
}

void libererBitmapFeu (Simcity* simcity){
    al_destroy_bitmap(simcity->tabBitmap[BITMAP_FEU]);
}


///Fonction regroupant la libération de toutes les Bitmaps
void libererBitmapAll(Simcity* simcity){
    libererBitmapMap(simcity);
    libererBitmapMenuPrincipal(simcity);
    libererBitmapMenuPrincipalIntro(simcity);
    libererBitmapBoutonMenuPrincipal(simcity);
    libererBitmapToolbox(simcity);
    libererBitmapBarreCompteurs(simcity);
    libererBitmapBoutonPause(simcity);
    libererBitmapMenuCommunisteCapitaliste(simcity);
    libererBitmapBoutonsMenuCommunisteCapitaliste(simcity);
    libererBitmapBoutonAide(simcity);
    libererBitmapFeu(simcity);
    libererBitmapTileRuine(simcity);
    libererBitmapRegle1(simcity);
    libererBitmapRegle2(simcity);
    libererBitmapFlecheRegles(simcity);
}



#include "menuPrincipal.h"
#include "../../Structures/structures.h"

void initDataMenuPrincipal(Simcity* simcity){
    simcity->pages.menuPrincipal.tabSpriteMenu[INTRO].image = &simcity->tabBitmap[BITMAP_MENU_PRINCIPAL_INTRO];
    simcity->pages.menuPrincipal.tabSpriteMenu[INTRO].spriteX = 0;
    simcity->pages.menuPrincipal.tabSpriteMenu[INTRO].spriteY = 0;
    simcity->pages.menuPrincipal.tabSpriteMenu[INTRO].spriteLargeur = 1024;
    simcity->pages.menuPrincipal.tabSpriteMenu[INTRO].spriteHauteur = 768;

    simcity->pages.menuPrincipal.tabSpriteMenu[FOND].image = &simcity->tabBitmap[BITMAP_MENU_PRINCIPAL];
    simcity->pages.menuPrincipal.tabSpriteMenu[FOND].spriteX = 0;
    simcity->pages.menuPrincipal.tabSpriteMenu[FOND].spriteY = 0;
    simcity->pages.menuPrincipal.tabSpriteMenu[FOND].spriteLargeur = 1024;
    simcity->pages.menuPrincipal.tabSpriteMenu[FOND].spriteHauteur = 768;

    simcity->pages.menuPrincipal.tabSpriteMenu[LANCER].image = &simcity->tabBitmap[BITMAP_BOUTTON_MENU_PRINCIPAL];
    simcity->pages.menuPrincipal.tabSpriteMenu[LANCER].spriteX = 36;
    simcity->pages.menuPrincipal.tabSpriteMenu[LANCER].spriteY = 59;
    simcity->pages.menuPrincipal.tabSpriteMenu[LANCER].spriteLargeur = 500;
    simcity->pages.menuPrincipal.tabSpriteMenu[LANCER].spriteHauteur = 150;

    simcity->pages.menuPrincipal.tabSpriteMenu[LANCER_HOVER].image = &simcity->tabBitmap[BITMAP_BOUTTON_MENU_PRINCIPAL];
    simcity->pages.menuPrincipal.tabSpriteMenu[LANCER_HOVER].spriteX = 36;
    simcity->pages.menuPrincipal.tabSpriteMenu[LANCER_HOVER].spriteY = 219;
    simcity->pages.menuPrincipal.tabSpriteMenu[LANCER_HOVER].spriteLargeur = 500;
    simcity->pages.menuPrincipal.tabSpriteMenu[LANCER_HOVER].spriteHauteur = 160;

    simcity->pages.menuPrincipal.tabSpriteMenu[LANCER_CLIQUE].image = &simcity->tabBitmap[BITMAP_BOUTTON_MENU_PRINCIPAL];
    simcity->pages.menuPrincipal.tabSpriteMenu[LANCER_CLIQUE].spriteX = 36;
    simcity->pages.menuPrincipal.tabSpriteMenu[LANCER_CLIQUE].spriteY = 389;
    simcity->pages.menuPrincipal.tabSpriteMenu[LANCER_CLIQUE].spriteLargeur = 500;
    simcity->pages.menuPrincipal.tabSpriteMenu[LANCER_CLIQUE].spriteHauteur = 150;

    simcity->pages.menuPrincipal.tabSpriteMenu[CHARGER].image = &simcity->tabBitmap[BITMAP_BOUTTON_MENU_PRINCIPAL];
    simcity->pages.menuPrincipal.tabSpriteMenu[CHARGER].spriteX = 592;
    simcity->pages.menuPrincipal.tabSpriteMenu[CHARGER].spriteY = 59;
    simcity->pages.menuPrincipal.tabSpriteMenu[CHARGER].spriteLargeur = 500;
    simcity->pages.menuPrincipal.tabSpriteMenu[CHARGER].spriteHauteur = 150;

    simcity->pages.menuPrincipal.tabSpriteMenu[CHARGER_HOVER].image = &simcity->tabBitmap[BITMAP_BOUTTON_MENU_PRINCIPAL];
    simcity->pages.menuPrincipal.tabSpriteMenu[CHARGER_HOVER].spriteX = 592;
    simcity->pages.menuPrincipal.tabSpriteMenu[CHARGER_HOVER].spriteY = 219;
    simcity->pages.menuPrincipal.tabSpriteMenu[CHARGER_HOVER].spriteLargeur = 500;
    simcity->pages.menuPrincipal.tabSpriteMenu[CHARGER_HOVER].spriteHauteur = 160;

    simcity->pages.menuPrincipal.tabSpriteMenu[CHARGER_CLIQUE].image = &simcity->tabBitmap[BITMAP_BOUTTON_MENU_PRINCIPAL];
    simcity->pages.menuPrincipal.tabSpriteMenu[CHARGER_CLIQUE].spriteX = 592;
    simcity->pages.menuPrincipal.tabSpriteMenu[CHARGER_CLIQUE].spriteY = 389;
    simcity->pages.menuPrincipal.tabSpriteMenu[CHARGER_CLIQUE].spriteLargeur = 500;
    simcity->pages.menuPrincipal.tabSpriteMenu[CHARGER_CLIQUE].spriteHauteur = 150;

    simcity->pages.menuPrincipal.tabSpriteMenu[QUITTER].image = &simcity->tabBitmap[BITMAP_BOUTTON_MENU_PRINCIPAL];
    simcity->pages.menuPrincipal.tabSpriteMenu[QUITTER].spriteX = 1148;
    simcity->pages.menuPrincipal.tabSpriteMenu[QUITTER].spriteY = 59;
    simcity->pages.menuPrincipal.tabSpriteMenu[QUITTER].spriteLargeur = 500;
    simcity->pages.menuPrincipal.tabSpriteMenu[QUITTER].spriteHauteur = 150;

    simcity->pages.menuPrincipal.tabSpriteMenu[QUITTER_HOVER].image = &simcity->tabBitmap[BITMAP_BOUTTON_MENU_PRINCIPAL];
    simcity->pages.menuPrincipal.tabSpriteMenu[QUITTER_HOVER].spriteX = 1148;
    simcity->pages.menuPrincipal.tabSpriteMenu[QUITTER_HOVER].spriteY = 219;
    simcity->pages.menuPrincipal.tabSpriteMenu[QUITTER_HOVER].spriteLargeur = 500;
    simcity->pages.menuPrincipal.tabSpriteMenu[QUITTER_HOVER].spriteHauteur = 160;

    simcity->pages.menuPrincipal.tabSpriteMenu[QUITTER_CLIQUE].image = &simcity->tabBitmap[BITMAP_BOUTTON_MENU_PRINCIPAL];
    simcity->pages.menuPrincipal.tabSpriteMenu[QUITTER_CLIQUE].spriteX = 1148;
    simcity->pages.menuPrincipal.tabSpriteMenu[QUITTER_CLIQUE].spriteY = 389;
    simcity->pages.menuPrincipal.tabSpriteMenu[QUITTER_CLIQUE].spriteLargeur = 500;
    simcity->pages.menuPrincipal.tabSpriteMenu[QUITTER_CLIQUE].spriteHauteur = 150;

    simcity->pages.menuPrincipal.lancer = 0;
    simcity->pages.menuPrincipal.lancerHover = 0;
    simcity->pages.menuPrincipal.lancerClique = 0;
    simcity->pages.menuPrincipal.charger = 0;
    simcity->pages.menuPrincipal.chargerHover = 0;
    simcity->pages.menuPrincipal.chargerClique = 0;
    simcity->pages.menuPrincipal.quitter = 0;
    simcity->pages.menuPrincipal.quitterHover = 0;
    simcity->pages.menuPrincipal.quitterClique = 0;
    simcity->pages.menuPrincipal.menuPrincipalIntro = 1;
    simcity->pages.menuPrincipal.menuPrincipal = 0;
}

void calculHover(Simcity * simcity){
    if(simcity->allegro.event.mouse.x >= 262 && simcity->allegro.event.mouse.x <= 262 + simcity->pages.menuPrincipal.tabSpriteMenu[LANCER].spriteLargeur && simcity->allegro.event.mouse.y >= 80 && simcity->allegro.event.mouse.y <= 80 + simcity->pages.menuPrincipal.tabSpriteMenu[LANCER].spriteHauteur){
        simcity->pages.menuPrincipal.lancerHover = true;
    } else if(simcity->allegro.event.mouse.x >= 262 && simcity->allegro.event.mouse.x <= 262 + simcity->pages.menuPrincipal.tabSpriteMenu[CHARGER].spriteLargeur && simcity->allegro.event.mouse.y >= 310 && simcity->allegro.event.mouse.y <= 310 + simcity->pages.menuPrincipal.tabSpriteMenu[CHARGER].spriteHauteur){
        simcity->pages.menuPrincipal.chargerHover = true;
    } else if(simcity->allegro.event.mouse.x >= 262 && simcity->allegro.event.mouse.x <= 262 + simcity->pages.menuPrincipal.tabSpriteMenu[QUITTER].spriteLargeur && simcity->allegro.event.mouse.y >= 540 && simcity->allegro.event.mouse.y <= 540 + simcity->pages.menuPrincipal.tabSpriteMenu[QUITTER].spriteHauteur){
        simcity->pages.menuPrincipal.quitterHover = true;
    }else {
        simcity->pages.menuPrincipal.lancerHover = false;
        simcity->pages.menuPrincipal.chargerHover = false;
        simcity->pages.menuPrincipal.quitterHover = false;
    }
}

void detectionClique(Simcity * simcity){
    if (simcity->allegro.event.mouse.button == 1 && simcity->pages.menuPrincipal.menuPrincipalIntro){
        simcity->pages.menuPrincipal.menuPrincipalIntro = 0;
    }else if(simcity->allegro.event.mouse.button == 1 && simcity->allegro.event.mouse.x >= 262 && simcity->allegro.event.mouse.x <= 262 + simcity->pages.menuPrincipal.tabSpriteMenu[LANCER].spriteLargeur && simcity->allegro.event.mouse.y >= 80 && simcity->allegro.event.mouse.y <= 80 + simcity->pages.menuPrincipal.tabSpriteMenu[LANCER].spriteHauteur){
        simcity->pages.menuPrincipal.lancerClique = true;
        simcity->pages.menuPrincipal.menuPrincipal = 1;
    } else if(simcity->allegro.event.mouse.button == 1 && simcity->allegro.event.mouse.x >= 262 && simcity->allegro.event.mouse.x <= 262 + simcity->pages.menuPrincipal.tabSpriteMenu[CHARGER].spriteLargeur && simcity->allegro.event.mouse.y >= 310 && simcity->allegro.event.mouse.y <= 310 + simcity->pages.menuPrincipal.tabSpriteMenu[CHARGER].spriteHauteur){
        simcity->pages.menuPrincipal.chargerClique = true;
    } else if(simcity->allegro.event.mouse.button == 1 && simcity->allegro.event.mouse.x >= 262 && simcity->allegro.event.mouse.x <= 262 + simcity->pages.menuPrincipal.tabSpriteMenu[QUITTER].spriteLargeur && simcity->allegro.event.mouse.y >= 540 && simcity->allegro.event.mouse.y <= 540 + simcity->pages.menuPrincipal.tabSpriteMenu[QUITTER].spriteHauteur){
        simcity->pages.menuPrincipal.quitterClique = true;
        simcity->endGame = 1;
        simcity->pages.menuPrincipal.menuPrincipal = 1;
    } else {
        simcity->pages.menuPrincipal.lancerClique = false;
        simcity->pages.menuPrincipal.chargerClique = false;
        simcity->pages.menuPrincipal.quitterClique = false;
    }
}

void afficherMenuPrincipal(Simcity* simcity){
    if (simcity->pages.menuPrincipal.menuPrincipalIntro){
        al_draw_bitmap_region(*(simcity->pages.menuPrincipal.tabSpriteMenu[INTRO].image),
                              simcity->pages.menuPrincipal.tabSpriteMenu[INTRO].spriteX,
                              simcity->pages.menuPrincipal.tabSpriteMenu[INTRO].spriteY,
                              simcity->pages.menuPrincipal.tabSpriteMenu[INTRO].spriteLargeur,
                              simcity->pages.menuPrincipal.tabSpriteMenu[INTRO].spriteHauteur,
                              0,
                              0,
                              0);
    } else{
        al_draw_bitmap_region(*(simcity->pages.menuPrincipal.tabSpriteMenu[FOND].image),
                              simcity->pages.menuPrincipal.tabSpriteMenu[FOND].spriteX,
                              simcity->pages.menuPrincipal.tabSpriteMenu[FOND].spriteY,
                              simcity->pages.menuPrincipal.tabSpriteMenu[FOND].spriteLargeur,
                              simcity->pages.menuPrincipal.tabSpriteMenu[FOND].spriteHauteur,
                              0,
                              0,
                              0);

        al_draw_bitmap_region(*(simcity->pages.menuPrincipal.tabSpriteMenu[LANCER].image),
                              simcity->pages.menuPrincipal.tabSpriteMenu[LANCER].spriteX,
                              simcity->pages.menuPrincipal.tabSpriteMenu[LANCER].spriteY,
                              simcity->pages.menuPrincipal.tabSpriteMenu[LANCER].spriteLargeur,
                              simcity->pages.menuPrincipal.tabSpriteMenu[LANCER].spriteHauteur,
                              262,
                              80,
                              0);

        al_draw_bitmap_region(*(simcity->pages.menuPrincipal.tabSpriteMenu[CHARGER].image),
                              simcity->pages.menuPrincipal.tabSpriteMenu[CHARGER].spriteX,
                              simcity->pages.menuPrincipal.tabSpriteMenu[CHARGER].spriteY,
                              simcity->pages.menuPrincipal.tabSpriteMenu[CHARGER].spriteLargeur,
                              simcity->pages.menuPrincipal.tabSpriteMenu[CHARGER].spriteHauteur,
                              262,
                              310,
                              0);

        al_draw_bitmap_region(*(simcity->pages.menuPrincipal.tabSpriteMenu[QUITTER].image),
                              simcity->pages.menuPrincipal.tabSpriteMenu[QUITTER].spriteX,
                              simcity->pages.menuPrincipal.tabSpriteMenu[QUITTER].spriteY,
                              simcity->pages.menuPrincipal.tabSpriteMenu[QUITTER].spriteLargeur,
                              simcity->pages.menuPrincipal.tabSpriteMenu[QUITTER].spriteHauteur,
                              262,
                              540,
                              0);
        if(simcity->pages.menuPrincipal.lancerHover){
            al_draw_bitmap_region(*(simcity->pages.menuPrincipal.tabSpriteMenu[LANCER_HOVER].image),
                                  simcity->pages.menuPrincipal.tabSpriteMenu[LANCER_HOVER].spriteX,
                                  simcity->pages.menuPrincipal.tabSpriteMenu[LANCER_HOVER].spriteY,
                                  simcity->pages.menuPrincipal.tabSpriteMenu[LANCER_HOVER].spriteLargeur,
                                  simcity->pages.menuPrincipal.tabSpriteMenu[LANCER_HOVER].spriteHauteur,
                                  262,
                                  80,
                                  0);
        }
        if(simcity->pages.menuPrincipal.lancerClique){
            al_draw_bitmap_region(*(simcity->pages.menuPrincipal.tabSpriteMenu[LANCER_CLIQUE].image),
                                  simcity->pages.menuPrincipal.tabSpriteMenu[LANCER_CLIQUE].spriteX,
                                  simcity->pages.menuPrincipal.tabSpriteMenu[LANCER_CLIQUE].spriteY,
                                  simcity->pages.menuPrincipal.tabSpriteMenu[LANCER_CLIQUE].spriteLargeur,
                                  simcity->pages.menuPrincipal.tabSpriteMenu[LANCER_CLIQUE].spriteHauteur,
                                  262,
                                  80,
                                  0);
        }
        if(simcity->pages.menuPrincipal.chargerHover){
            al_draw_bitmap_region(*(simcity->pages.menuPrincipal.tabSpriteMenu[CHARGER_HOVER].image),
                                  simcity->pages.menuPrincipal.tabSpriteMenu[CHARGER_HOVER].spriteX,
                                  simcity->pages.menuPrincipal.tabSpriteMenu[CHARGER_HOVER].spriteY,
                                  simcity->pages.menuPrincipal.tabSpriteMenu[CHARGER_HOVER].spriteLargeur,
                                  simcity->pages.menuPrincipal.tabSpriteMenu[CHARGER_HOVER].spriteHauteur,
                                  262,
                                  310,
                                  0);
        }
        if(simcity->pages.menuPrincipal.chargerClique){
            al_draw_bitmap_region(*(simcity->pages.menuPrincipal.tabSpriteMenu[CHARGER_CLIQUE].image),
                                  simcity->pages.menuPrincipal.tabSpriteMenu[CHARGER_CLIQUE].spriteX,
                                  simcity->pages.menuPrincipal.tabSpriteMenu[CHARGER_CLIQUE].spriteY,
                                  simcity->pages.menuPrincipal.tabSpriteMenu[CHARGER_CLIQUE].spriteLargeur,
                                  simcity->pages.menuPrincipal.tabSpriteMenu[CHARGER_CLIQUE].spriteHauteur,
                                  262,
                                  310,
                                  0);
        }
        if(simcity->pages.menuPrincipal.quitterHover){
            al_draw_bitmap_region(*(simcity->pages.menuPrincipal.tabSpriteMenu[QUITTER_HOVER].image),
                                  simcity->pages.menuPrincipal.tabSpriteMenu[QUITTER_HOVER].spriteX,
                                  simcity->pages.menuPrincipal.tabSpriteMenu[QUITTER_HOVER].spriteY,
                                  simcity->pages.menuPrincipal.tabSpriteMenu[QUITTER_HOVER].spriteLargeur,
                                  simcity->pages.menuPrincipal.tabSpriteMenu[QUITTER_HOVER].spriteHauteur,
                                  262,
                                  540,
                                  0);
        }
        if(simcity->pages.menuPrincipal.quitterClique){
            al_draw_bitmap_region(*(simcity->pages.menuPrincipal.tabSpriteMenu[QUITTER_CLIQUE].image),
                                  simcity->pages.menuPrincipal.tabSpriteMenu[QUITTER_CLIQUE].spriteX,
                                  simcity->pages.menuPrincipal.tabSpriteMenu[QUITTER_CLIQUE].spriteY,
                                  simcity->pages.menuPrincipal.tabSpriteMenu[QUITTER_CLIQUE].spriteLargeur,
                                  simcity->pages.menuPrincipal.tabSpriteMenu[QUITTER_CLIQUE].spriteHauteur,
                                  262,
                                  540,
                                  0);
        }
    }
}


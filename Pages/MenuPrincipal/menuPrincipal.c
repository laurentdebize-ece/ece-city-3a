#include "menuPrincipal.h"

void initDataBoutonAide (Simcity* simcity){
    simcity->pages.menuPrincipal.tabSpriteMenu[AIDE].image = &simcity->tabBitmap[BITMAP_BOUTON_AIDE];
    simcity->pages.menuPrincipal.tabSpriteMenu[AIDE].spriteX = 20;
    simcity->pages.menuPrincipal.tabSpriteMenu[AIDE].spriteY = 34;
    simcity->pages.menuPrincipal.tabSpriteMenu[AIDE].spriteHauteur = 100;
    simcity->pages.menuPrincipal.tabSpriteMenu[AIDE].spriteLargeur = 100;
    simcity->pages.menuPrincipal.tabSpriteMenu[AIDE].screenX = 885;
    simcity->pages.menuPrincipal.tabSpriteMenu[AIDE].screenY = 30;

    simcity->pages.menuPrincipal.tabSpriteMenu[AIDE_HOVER].image = &simcity->tabBitmap[BITMAP_BOUTON_AIDE];
    simcity->pages.menuPrincipal.tabSpriteMenu[AIDE_HOVER].spriteX = 150;
    simcity->pages.menuPrincipal.tabSpriteMenu[AIDE_HOVER].spriteY = 34;
    simcity->pages.menuPrincipal.tabSpriteMenu[AIDE_HOVER].spriteHauteur = 105;
    simcity->pages.menuPrincipal.tabSpriteMenu[AIDE_HOVER].spriteLargeur = 110;
    simcity->pages.menuPrincipal.tabSpriteMenu[AIDE_HOVER].screenX = 885;
    simcity->pages.menuPrincipal.tabSpriteMenu[AIDE_HOVER].screenY = 30;

    simcity->pages.menuPrincipal.tabSpriteMenu[AIDE_CLIQUE].image = &simcity->tabBitmap[BITMAP_BOUTON_AIDE];
    simcity->pages.menuPrincipal.tabSpriteMenu[AIDE_CLIQUE].spriteX = 286;
    simcity->pages.menuPrincipal.tabSpriteMenu[AIDE_CLIQUE].spriteY = 34;
    simcity->pages.menuPrincipal.tabSpriteMenu[AIDE_CLIQUE].spriteHauteur = 100;
    simcity->pages.menuPrincipal.tabSpriteMenu[AIDE_CLIQUE].spriteLargeur = 100;
    simcity->pages.menuPrincipal.tabSpriteMenu[AIDE_CLIQUE].screenX = 885;
    simcity->pages.menuPrincipal.tabSpriteMenu[AIDE_CLIQUE].screenY = 30;
}




void initDataMenuCommunisteCapitaliste (Simcity* simcity) {
    simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[FOND2].image = &simcity->tabBitmap[BITMAP_MENU_COMMUNISTE_CAPITALISTE];
    simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[FOND2].spriteX = 0;
    simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[FOND2].spriteY = 0;
    simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[FOND2].spriteLargeur = 1024;
    simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[FOND2].spriteHauteur = 768;


    simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[CAPITALISTE].image = &simcity->tabBitmap[BITMAP_BOUTONS_MENU_COMMUNISTE_CAPITALISTE];
    simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[CAPITALISTE].spriteX = 783;
    simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[CAPITALISTE].spriteY = 80;
    simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[CAPITALISTE].spriteLargeur = 500;
    simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[CAPITALISTE].spriteHauteur = 150;
    simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[CAPITALISTE].screenX = 262;
    simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[CAPITALISTE].screenY= 145;



    simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[CAPITALISTE_HOVER].image = &simcity->tabBitmap[BITMAP_BOUTONS_MENU_COMMUNISTE_CAPITALISTE];
    simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[CAPITALISTE_HOVER].spriteX = 783;
    simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[CAPITALISTE_HOVER].spriteY = 254;
    simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[CAPITALISTE_HOVER].spriteLargeur = 500;
    simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[CAPITALISTE_HOVER].spriteHauteur = 155;
    simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[CAPITALISTE_HOVER].screenX = 262;
    simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[CAPITALISTE_HOVER].screenY= 145;

    simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[CAPITALISTE_CLIQUE].image = &simcity->tabBitmap[BITMAP_BOUTONS_MENU_COMMUNISTE_CAPITALISTE];
    simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[CAPITALISTE_CLIQUE].spriteX = 783;
    simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[CAPITALISTE_CLIQUE].spriteY = 428;
    simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[CAPITALISTE_CLIQUE].spriteLargeur = 500;
    simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[CAPITALISTE_CLIQUE].spriteHauteur = 150;
    simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[CAPITALISTE_CLIQUE].screenX = 262;
    simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[CAPITALISTE_CLIQUE].screenY= 145;


    simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[COMMUNISTE].image = &simcity->tabBitmap[BITMAP_BOUTONS_MENU_COMMUNISTE_CAPITALISTE];
    simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[COMMUNISTE].spriteX = 160;
    simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[COMMUNISTE].spriteY = 80;
    simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[COMMUNISTE].spriteLargeur = 500;
    simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[COMMUNISTE].spriteHauteur = 150;
    simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[COMMUNISTE].screenX = 262;
    simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[COMMUNISTE].screenY= 440;

    simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[COMMUNISTE_HOVER].image = &simcity->tabBitmap[BITMAP_BOUTONS_MENU_COMMUNISTE_CAPITALISTE];
    simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[COMMUNISTE_HOVER].spriteX = 160;
    simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[COMMUNISTE_HOVER].spriteY = 254;
    simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[COMMUNISTE_HOVER].spriteLargeur = 500;
    simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[COMMUNISTE_HOVER].spriteHauteur = 155;
    simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[COMMUNISTE_HOVER].screenX = 262;
    simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[COMMUNISTE_HOVER].screenY= 440;

    simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[COMMUNISTE_CLIQUE].image = &simcity->tabBitmap[BITMAP_BOUTONS_MENU_COMMUNISTE_CAPITALISTE];
    simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[COMMUNISTE_CLIQUE].spriteX = 160;
    simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[COMMUNISTE_CLIQUE].spriteY = 428;
    simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[COMMUNISTE_CLIQUE].spriteLargeur = 500;
    simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[COMMUNISTE_CLIQUE].spriteHauteur = 150;
    simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[COMMUNISTE_CLIQUE].screenX = 262;
    simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[COMMUNISTE_CLIQUE].screenY= 440;

    simcity->pages.menuCapitalisteCommuniste.capitalisteHover = 0;
    simcity->pages.menuCapitalisteCommuniste.capitalisteClique = 0;
    simcity->pages.menuCapitalisteCommuniste.communisteHover = 0;
    simcity->pages.menuCapitalisteCommuniste.communisteClique = 0;
    simcity->pages.menuCapitalisteCommuniste.menuCapitalisteCommuniste = 0;

    simcity->capitaliste = FALSE;
    simcity->communiste = FALSE;
}

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

void calculHoverBoutonAide (Simcity* simcity){
     if((float)simcity->allegro.event.mouse.x >= simcity->pages.menuPrincipal.tabSpriteMenu[AIDE_HOVER].screenX && (float)simcity->allegro.event.mouse.x <= simcity->pages.menuPrincipal.tabSpriteMenu[AIDE_HOVER].screenX + simcity->pages.menuPrincipal.tabSpriteMenu[AIDE_HOVER].spriteLargeur &&(float) simcity->allegro.event.mouse.y >= simcity->pages.menuPrincipal.tabSpriteMenu[AIDE_HOVER].screenY && (float)simcity->allegro.event.mouse.y <= simcity->pages.menuPrincipal.tabSpriteMenu[AIDE_HOVER].screenY+ simcity->pages.menuPrincipal.tabSpriteMenu[AIDE_HOVER].spriteHauteur){
        simcity->pages.menuPrincipal.aideHover = true;

    }else {
        simcity->pages.menuPrincipal.aideHover = false;
    }
    }


        void calculHoverComCap (Simcity* simcity){
    if((float)simcity->allegro.event.mouse.x >= simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[CAPITALISTE].screenX && (float)simcity->allegro.event.mouse.x <= simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[CAPITALISTE].screenX + simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[CAPITALISTE].spriteLargeur && (float)simcity->allegro.event.mouse.y >= simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[CAPITALISTE].screenY && (float)simcity->allegro.event.mouse.y <= simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[CAPITALISTE].screenY+ simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[CAPITALISTE].spriteHauteur){
        simcity->pages.menuCapitalisteCommuniste.capitalisteHover = true;

    } else if((float)simcity->allegro.event.mouse.x >= simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[COMMUNISTE].screenX && (float)simcity->allegro.event.mouse.x <= simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[COMMUNISTE].screenX + simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[COMMUNISTE].spriteLargeur && (float)simcity->allegro.event.mouse.y >= simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[COMMUNISTE].screenY && (float)simcity->allegro.event.mouse.y <= simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[COMMUNISTE].screenY + simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[COMMUNISTE].spriteHauteur){
        simcity->pages.menuCapitalisteCommuniste.communisteHover = true;

    } else {simcity->pages.menuCapitalisteCommuniste.capitalisteHover = false;
            simcity->pages.menuCapitalisteCommuniste.communisteHover = false;

    }
}

void calculHover(Simcity * simcity){
    if(simcity->allegro.event.mouse.x >= 262 && (float)simcity->allegro.event.mouse.x <= 262 + simcity->pages.menuPrincipal.tabSpriteMenu[LANCER].spriteLargeur && simcity->allegro.event.mouse.y >= 80 &&(float) simcity->allegro.event.mouse.y <= 80 + simcity->pages.menuPrincipal.tabSpriteMenu[LANCER].spriteHauteur){
        simcity->pages.menuPrincipal.lancerHover = true;
    } else if(simcity->allegro.event.mouse.x >= 262 && (float)simcity->allegro.event.mouse.x <= 262 + simcity->pages.menuPrincipal.tabSpriteMenu[CHARGER].spriteLargeur && simcity->allegro.event.mouse.y >= 310 && (float)simcity->allegro.event.mouse.y <= 310 + simcity->pages.menuPrincipal.tabSpriteMenu[CHARGER].spriteHauteur){
        simcity->pages.menuPrincipal.chargerHover = true;
    } else if(simcity->allegro.event.mouse.x >= 262 && (float)simcity->allegro.event.mouse.x <= 262 + simcity->pages.menuPrincipal.tabSpriteMenu[QUITTER].spriteLargeur && simcity->allegro.event.mouse.y >= 540 && (float)simcity->allegro.event.mouse.y <= 540 + simcity->pages.menuPrincipal.tabSpriteMenu[QUITTER].spriteHauteur){
        simcity->pages.menuPrincipal.quitterHover = true;
    }else {
        simcity->pages.menuPrincipal.lancerHover = false;
        simcity->pages.menuPrincipal.chargerHover = false;
        simcity->pages.menuPrincipal.quitterHover = false;
    }
}

void detectionCliqueBoutonAide (Simcity* simcity){
    if(simcity->allegro.event.mouse.button == 1 && (float)simcity->allegro.event.mouse.x >= simcity->pages.menuPrincipal.tabSpriteMenu[AIDE].screenX && (float)simcity->allegro.event.mouse.x <= simcity->pages.menuPrincipal.tabSpriteMenu[AIDE].screenX + simcity->pages.menuPrincipal.tabSpriteMenu[AIDE].spriteLargeur && (float)simcity->allegro.event.mouse.y >= simcity->pages.menuPrincipal.tabSpriteMenu[AIDE].screenY && (float)simcity->allegro.event.mouse.y <= simcity->pages.menuPrincipal.tabSpriteMenu[AIDE].screenY + simcity->pages.menuPrincipal.tabSpriteMenu[AIDE].spriteHauteur){
simcity->pages.menuPrincipal.aideClique = 1;

    }else { simcity->pages.menuPrincipal.aideClique = false;

    }
    }


void detectionCliqueMenuCapCom (Simcity* simcity){

    if(simcity->allegro.event.mouse.button == 1 && (float)simcity->allegro.event.mouse.x >= simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[CAPITALISTE].screenX && (float)simcity->allegro.event.mouse.x <= simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[CAPITALISTE].screenX + simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[CAPITALISTE].spriteLargeur && (float)simcity->allegro.event.mouse.y >= simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[CAPITALISTE].screenY && (float)simcity->allegro.event.mouse.y <= simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[CAPITALISTE].screenY + simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[CAPITALISTE].spriteHauteur){
        simcity->pages.menuCapitalisteCommuniste.capitalisteClique = 1;
        simcity->pages.menuCapitalisteCommuniste.menuCapitalisteCommuniste = 1;
        simcity->capitaliste = TRUE;
    }else if(simcity->allegro.event.mouse.button == 1 && (float)simcity->allegro.event.mouse.x >= simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[COMMUNISTE].screenX && (float)simcity->allegro.event.mouse.x <= simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[COMMUNISTE].screenX + simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[COMMUNISTE].spriteLargeur && (float)simcity->allegro.event.mouse.y >= simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[COMMUNISTE].screenY && (float)simcity->allegro.event.mouse.y <= simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[COMMUNISTE].screenY + simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[COMMUNISTE].spriteHauteur){
        simcity->pages.menuCapitalisteCommuniste.communisteClique = 1;
        simcity->pages.menuCapitalisteCommuniste.menuCapitalisteCommuniste = 1;
        simcity->communiste = TRUE;

    }else simcity->pages.menuCapitalisteCommuniste.communisteHover = false;
            simcity->pages.menuCapitalisteCommuniste.capitalisteHover = false;
    }

void detectionClique(Simcity * simcity){
    if (simcity->allegro.event.mouse.button == 1 && simcity->pages.menuPrincipal.menuPrincipalIntro){
        simcity->pages.menuPrincipal.menuPrincipalIntro = 0;
    }else if(simcity->allegro.event.mouse.button == 1 && simcity->allegro.event.mouse.x >= 262 && (float)simcity->allegro.event.mouse.x <= 262 + simcity->pages.menuPrincipal.tabSpriteMenu[LANCER].spriteLargeur && simcity->allegro.event.mouse.y >= 80 && (float)simcity->allegro.event.mouse.y <= 80 + simcity->pages.menuPrincipal.tabSpriteMenu[LANCER].spriteHauteur){
        simcity->pages.menuPrincipal.lancerClique = true;
        simcity->pages.menuPrincipal.menuPrincipal = 1;
    } else if(simcity->allegro.event.mouse.button == 1 && simcity->allegro.event.mouse.x >= 262 && (float)simcity->allegro.event.mouse.x <= 262 + simcity->pages.menuPrincipal.tabSpriteMenu[CHARGER].spriteLargeur && simcity->allegro.event.mouse.y >= 310 && (float)simcity->allegro.event.mouse.y <= 310 + simcity->pages.menuPrincipal.tabSpriteMenu[CHARGER].spriteHauteur){
        simcity->pages.menuPrincipal.chargerClique = true;
    } else if(simcity->allegro.event.mouse.button == 1 && simcity->allegro.event.mouse.x >= 262 && (float)simcity->allegro.event.mouse.x <= 262 + simcity->pages.menuPrincipal.tabSpriteMenu[QUITTER].spriteLargeur && simcity->allegro.event.mouse.y >= 540 && (float)simcity->allegro.event.mouse.y <= 540 + simcity->pages.menuPrincipal.tabSpriteMenu[QUITTER].spriteHauteur){
        simcity->pages.menuPrincipal.quitterClique = true;
        simcity->endGame = 1;
        simcity->pages.menuPrincipal.menuPrincipal = 1;
    } else {
        simcity->pages.menuPrincipal.lancerClique = false;
        simcity->pages.menuPrincipal.chargerClique = false;
        simcity->pages.menuPrincipal.quitterClique = false;
    }
}



void afficherMenuComCap (Simcity* simcity){
    al_draw_bitmap(*(simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[FOND2].image), 0,0,0);
    al_draw_bitmap_region(*(simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[CAPITALISTE].image), simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[CAPITALISTE].spriteX, simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[CAPITALISTE].spriteY, simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[CAPITALISTE].spriteLargeur, simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[CAPITALISTE].spriteHauteur, simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[CAPITALISTE].screenX, simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[CAPITALISTE].screenY,0);
    al_draw_bitmap_region(*(simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[COMMUNISTE].image), simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[COMMUNISTE].spriteX, simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[COMMUNISTE].spriteY, simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[COMMUNISTE].spriteLargeur, simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[COMMUNISTE].spriteHauteur, simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[COMMUNISTE].screenX, simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[COMMUNISTE].screenY,0);
    if(simcity->pages.menuCapitalisteCommuniste.communisteHover){
        al_draw_bitmap_region(*(simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[COMMUNISTE_HOVER].image), simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[COMMUNISTE_HOVER].spriteX, simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[COMMUNISTE_HOVER].spriteY, simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[COMMUNISTE_HOVER].spriteLargeur, simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[COMMUNISTE_HOVER].spriteHauteur, simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[COMMUNISTE_HOVER].screenX, simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[COMMUNISTE_HOVER].screenY,0);
    }  if(simcity->pages.menuCapitalisteCommuniste.capitalisteHover){
        al_draw_bitmap_region(*(simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[CAPITALISTE_HOVER].image), simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[CAPITALISTE_HOVER].spriteX, simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[CAPITALISTE_HOVER].spriteY, simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[CAPITALISTE_HOVER].spriteLargeur, simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[CAPITALISTE_HOVER].spriteHauteur, simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[CAPITALISTE_HOVER].screenX, simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[CAPITALISTE_HOVER].screenY,0);
    } if(simcity->pages.menuCapitalisteCommuniste.communisteClique){
        al_draw_bitmap_region(*(simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[COMMUNISTE_CLIQUE].image), simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[COMMUNISTE_CLIQUE].spriteX, simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[COMMUNISTE_CLIQUE].spriteY, simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[COMMUNISTE_CLIQUE].spriteLargeur, simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[COMMUNISTE_CLIQUE].spriteHauteur, simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[COMMUNISTE_CLIQUE].screenX, simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[COMMUNISTE_CLIQUE].screenY,0);
    } if(simcity->pages.menuCapitalisteCommuniste.capitalisteClique){
        al_draw_bitmap_region(*(simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[CAPITALISTE_CLIQUE].image), simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[CAPITALISTE_CLIQUE].spriteX, simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[CAPITALISTE_CLIQUE].spriteY, simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[CAPITALISTE_CLIQUE].spriteLargeur, simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[CAPITALISTE_CLIQUE].spriteHauteur, simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[CAPITALISTE_CLIQUE].screenX, simcity->pages.menuCapitalisteCommuniste.tabSpriteMenu[CAPITALISTE_CLIQUE].screenY,0);
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

        al_draw_bitmap_region(*(simcity->pages.menuPrincipal.tabSpriteMenu[AIDE].image),
                              simcity->pages.menuPrincipal.tabSpriteMenu[AIDE].spriteX,
                              simcity->pages.menuPrincipal.tabSpriteMenu[AIDE].spriteY,
                              simcity->pages.menuPrincipal.tabSpriteMenu[AIDE].spriteLargeur,
                              simcity->pages.menuPrincipal.tabSpriteMenu[AIDE].spriteHauteur,
                              simcity->pages.menuPrincipal.tabSpriteMenu[AIDE].screenX,
                              simcity->pages.menuPrincipal.tabSpriteMenu[AIDE].screenY,0);

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
        if(simcity->pages.menuPrincipal.aideHover){
            al_draw_bitmap_region(*(simcity->pages.menuPrincipal.tabSpriteMenu[AIDE_HOVER].image),
                                  simcity->pages.menuPrincipal.tabSpriteMenu[AIDE_HOVER].spriteX,
                                  simcity->pages.menuPrincipal.tabSpriteMenu[AIDE_HOVER].spriteY,
                                  simcity->pages.menuPrincipal.tabSpriteMenu[AIDE_HOVER].spriteLargeur,
                                  simcity->pages.menuPrincipal.tabSpriteMenu[AIDE_HOVER].spriteHauteur,
                                  simcity->pages.menuPrincipal.tabSpriteMenu[AIDE_HOVER].screenX,
                                  simcity->pages.menuPrincipal.tabSpriteMenu[AIDE_HOVER].screenY, 0);

        }
        if(simcity->pages.menuPrincipal.aideClique){
            al_draw_bitmap_region(*(simcity->pages.menuPrincipal.tabSpriteMenu[AIDE_CLIQUE].image),
                                  simcity->pages.menuPrincipal.tabSpriteMenu[AIDE_CLIQUE].spriteX,
                                  simcity->pages.menuPrincipal.tabSpriteMenu[AIDE_CLIQUE].spriteY,
                                  simcity->pages.menuPrincipal.tabSpriteMenu[AIDE_CLIQUE].spriteLargeur,
                                  simcity->pages.menuPrincipal.tabSpriteMenu[AIDE_CLIQUE].spriteHauteur,
                                  simcity->pages.menuPrincipal.tabSpriteMenu[AIDE_CLIQUE].screenX,
                                  simcity->pages.menuPrincipal.tabSpriteMenu[AIDE_CLIQUE].screenY, 0);

        }
    }
}


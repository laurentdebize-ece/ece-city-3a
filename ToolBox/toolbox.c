#include "toolbox.h"
#include "../Structures/structures.h"

void toolboxSpriteInit(Simcity* simcity){
    simcity->toolBox.tabSpriteToolBox[ROUTE_].image = &simcity->tabBitmap[BITMAP_TOOLBOX];
    simcity->toolBox.tabSpriteToolBox[ROUTE_].spriteLargeur = 35;
    simcity->toolBox.tabSpriteToolBox[ROUTE_].spriteHauteur = 35;
    simcity->toolBox.tabSpriteToolBox[ROUTE_].spriteX = 13;
    simcity->toolBox.tabSpriteToolBox[ROUTE_].spriteY = 15;
    simcity->toolBox.tabSpriteToolBox[ROUTE_].screenX = 11;
    simcity->toolBox.tabSpriteToolBox[ROUTE_].screenY = 20;

    simcity->toolBox.tabSpriteToolBox[ROUTE_HOVER].image = &simcity->tabBitmap[BITMAP_TOOLBOX];
    simcity->toolBox.tabSpriteToolBox[ROUTE_HOVER].spriteLargeur = 35;
    simcity->toolBox.tabSpriteToolBox[ROUTE_HOVER].spriteHauteur = 35;
    simcity->toolBox.tabSpriteToolBox[ROUTE_HOVER].spriteX = 12;
    simcity->toolBox.tabSpriteToolBox[ROUTE_HOVER].spriteY = 64;
    simcity->toolBox.tabSpriteToolBox[ROUTE_HOVER].screenX = 11;
    simcity->toolBox.tabSpriteToolBox[ROUTE_HOVER].screenY = 20;


    simcity->toolBox.tabSpriteToolBox[ROUTE_CLIQUE].image = &simcity->tabBitmap[BITMAP_TOOLBOX];
    simcity->toolBox.tabSpriteToolBox[ROUTE_CLIQUE].spriteLargeur = 35;
    simcity->toolBox.tabSpriteToolBox[ROUTE_CLIQUE].spriteHauteur = 35;
    simcity->toolBox.tabSpriteToolBox[ROUTE_CLIQUE].spriteX = 14;
    simcity->toolBox.tabSpriteToolBox[ROUTE_CLIQUE].spriteY = 116;
    simcity->toolBox.tabSpriteToolBox[ROUTE_CLIQUE].screenX = 11;
    simcity->toolBox.tabSpriteToolBox[ROUTE_CLIQUE].screenY = 20;


    simcity->toolBox.tabSpriteToolBox[MAISON_].image = &simcity->tabBitmap[BITMAP_TOOLBOX];
    simcity->toolBox.tabSpriteToolBox[MAISON_].spriteLargeur = 35;
    simcity->toolBox.tabSpriteToolBox[MAISON_].spriteHauteur = 35;
    simcity->toolBox.tabSpriteToolBox[MAISON_].spriteX = 63;
    simcity->toolBox.tabSpriteToolBox[MAISON_].spriteY = 14;
    simcity->toolBox.tabSpriteToolBox[MAISON_].screenX = 61;
    simcity->toolBox.tabSpriteToolBox[MAISON_].screenY = 20;

    simcity->toolBox.tabSpriteToolBox[MAISON_HOVER].image = &simcity->tabBitmap[BITMAP_TOOLBOX];
    simcity->toolBox.tabSpriteToolBox[MAISON_HOVER].spriteLargeur = 35;
    simcity->toolBox.tabSpriteToolBox[MAISON_HOVER].spriteHauteur = 35;
    simcity->toolBox.tabSpriteToolBox[MAISON_HOVER].spriteX = 62;
    simcity->toolBox.tabSpriteToolBox[MAISON_HOVER].spriteY = 64;
    simcity->toolBox.tabSpriteToolBox[MAISON_HOVER].screenX = 61;
    simcity->toolBox.tabSpriteToolBox[MAISON_HOVER].screenY = 20;

    simcity->toolBox.tabSpriteToolBox[MAISON_CLIQUE].image = &simcity->tabBitmap[BITMAP_TOOLBOX];
    simcity->toolBox.tabSpriteToolBox[MAISON_CLIQUE].spriteLargeur = 35;
    simcity->toolBox.tabSpriteToolBox[MAISON_CLIQUE].spriteHauteur = 35;
    simcity->toolBox.tabSpriteToolBox[MAISON_CLIQUE].spriteX = 62;
    simcity->toolBox.tabSpriteToolBox[MAISON_CLIQUE].spriteY = 116;
    simcity->toolBox.tabSpriteToolBox[MAISON_CLIQUE].screenX = 61;
    simcity->toolBox.tabSpriteToolBox[MAISON_CLIQUE].screenY = 20;

    simcity->toolBox.tabSpriteToolBox[ELEC].image = &simcity->tabBitmap[BITMAP_TOOLBOX];
    simcity->toolBox.tabSpriteToolBox[ELEC].spriteLargeur = 35;
    simcity->toolBox.tabSpriteToolBox[ELEC].spriteHauteur = 35;
    simcity->toolBox.tabSpriteToolBox[ELEC].spriteX = 107;
    simcity->toolBox.tabSpriteToolBox[ELEC].spriteY = 14;
    simcity->toolBox.tabSpriteToolBox[ELEC].screenX = 11;
    simcity->toolBox.tabSpriteToolBox[ELEC].screenY = 66;

    simcity->toolBox.tabSpriteToolBox[ELEC_HOVER].image = &simcity->tabBitmap[BITMAP_TOOLBOX];
    simcity->toolBox.tabSpriteToolBox[ELEC_HOVER].spriteLargeur = 35;
    simcity->toolBox.tabSpriteToolBox[ELEC_HOVER].spriteHauteur = 35;
    simcity->toolBox.tabSpriteToolBox[ELEC_HOVER].spriteX = 107;
    simcity->toolBox.tabSpriteToolBox[ELEC_HOVER].spriteY = 64;
    simcity->toolBox.tabSpriteToolBox[ELEC_HOVER].screenX = 11;
    simcity->toolBox.tabSpriteToolBox[ELEC_HOVER].screenY = 66;

    simcity->toolBox.tabSpriteToolBox[ELEC_CLIQUE].image = &simcity->tabBitmap[BITMAP_TOOLBOX];
    simcity->toolBox.tabSpriteToolBox[ELEC_CLIQUE].spriteLargeur = 35;
    simcity->toolBox.tabSpriteToolBox[ELEC_CLIQUE].spriteHauteur = 35;
    simcity->toolBox.tabSpriteToolBox[ELEC_CLIQUE].spriteX = 107;
    simcity->toolBox.tabSpriteToolBox[ELEC_CLIQUE].spriteY = 116;
    simcity->toolBox.tabSpriteToolBox[ELEC_CLIQUE].screenX = 11;
    simcity->toolBox.tabSpriteToolBox[ELEC_CLIQUE].screenY = 66;

    simcity->toolBox.tabSpriteToolBox[EAU].image = &simcity->tabBitmap[BITMAP_TOOLBOX];
    simcity->toolBox.tabSpriteToolBox[EAU].spriteLargeur = 35;
    simcity->toolBox.tabSpriteToolBox[EAU].spriteHauteur = 35;
    simcity->toolBox.tabSpriteToolBox[EAU].spriteX = 152;
    simcity->toolBox.tabSpriteToolBox[EAU].spriteY = 14;
    simcity->toolBox.tabSpriteToolBox[EAU].screenX = 61;
    simcity->toolBox.tabSpriteToolBox[EAU].screenY = 66;

    simcity->toolBox.tabSpriteToolBox[EAU_HOVER].image = &simcity->tabBitmap[BITMAP_TOOLBOX];
    simcity->toolBox.tabSpriteToolBox[EAU_HOVER].spriteLargeur = 35;
    simcity->toolBox.tabSpriteToolBox[EAU_HOVER].spriteHauteur = 35;
    simcity->toolBox.tabSpriteToolBox[EAU_HOVER].spriteX = 152;
    simcity->toolBox.tabSpriteToolBox[EAU_HOVER].spriteY = 64;
    simcity->toolBox.tabSpriteToolBox[EAU_HOVER].screenX = 61;
    simcity->toolBox.tabSpriteToolBox[EAU_HOVER].screenY = 66;

    simcity->toolBox.tabSpriteToolBox[EAU_CLIQUE].image = &simcity->tabBitmap[BITMAP_TOOLBOX];
    simcity->toolBox.tabSpriteToolBox[EAU_CLIQUE].spriteLargeur = 35;
    simcity->toolBox.tabSpriteToolBox[EAU_CLIQUE].spriteHauteur = 35;
    simcity->toolBox.tabSpriteToolBox[EAU_CLIQUE].spriteX = 152;
    simcity->toolBox.tabSpriteToolBox[EAU_CLIQUE].spriteY = 116;
    simcity->toolBox.tabSpriteToolBox[EAU_CLIQUE].screenX = 61;
    simcity->toolBox.tabSpriteToolBox[EAU_CLIQUE].screenY = 66;

    simcity->toolBox.tabSpriteToolBox[DETRUIRE].image = &simcity->tabBitmap[BITMAP_TOOLBOX];
    simcity->toolBox.tabSpriteToolBox[DETRUIRE].spriteLargeur = 35;
    simcity->toolBox.tabSpriteToolBox[DETRUIRE].spriteHauteur = 35;
    simcity->toolBox.tabSpriteToolBox[DETRUIRE].spriteX = 196;
    simcity->toolBox.tabSpriteToolBox[DETRUIRE].spriteY = 14;
    simcity->toolBox.tabSpriteToolBox[DETRUIRE].screenX = 11;
    simcity->toolBox.tabSpriteToolBox[DETRUIRE].screenY = 113;

    simcity->toolBox.tabSpriteToolBox[DETRUIRE_HOVER].image = &simcity->tabBitmap[BITMAP_TOOLBOX];
    simcity->toolBox.tabSpriteToolBox[DETRUIRE_HOVER].spriteLargeur = 35;
    simcity->toolBox.tabSpriteToolBox[DETRUIRE_HOVER].spriteHauteur = 35;
    simcity->toolBox.tabSpriteToolBox[DETRUIRE_HOVER].spriteX = 196;
    simcity->toolBox.tabSpriteToolBox[DETRUIRE_HOVER].spriteY = 64;
    simcity->toolBox.tabSpriteToolBox[DETRUIRE_HOVER].screenX = 11;
    simcity->toolBox.tabSpriteToolBox[DETRUIRE_HOVER].screenY = 113;

    simcity->toolBox.tabSpriteToolBox[DETRUIRE_CLIQUE].image = &simcity->tabBitmap[BITMAP_TOOLBOX];
    simcity->toolBox.tabSpriteToolBox[DETRUIRE_CLIQUE].spriteLargeur = 35;
    simcity->toolBox.tabSpriteToolBox[DETRUIRE_CLIQUE].spriteHauteur = 35;
    simcity->toolBox.tabSpriteToolBox[DETRUIRE_CLIQUE].spriteX = 196;
    simcity->toolBox.tabSpriteToolBox[DETRUIRE_CLIQUE].spriteY = 116;
    simcity->toolBox.tabSpriteToolBox[DETRUIRE_CLIQUE].screenX = 11;
    simcity->toolBox.tabSpriteToolBox[DETRUIRE_CLIQUE].screenY = 113;

    simcity->toolBox.tabSpriteToolBox[VUE1].image = &simcity->tabBitmap[BITMAP_TOOLBOX];
    simcity->toolBox.tabSpriteToolBox[VUE1].spriteLargeur = 35;
    simcity->toolBox.tabSpriteToolBox[VUE1].spriteHauteur = 35;
    simcity->toolBox.tabSpriteToolBox[VUE1].spriteX = 241;
    simcity->toolBox.tabSpriteToolBox[VUE1].spriteY = 14;
    simcity->toolBox.tabSpriteToolBox[VUE1].screenX = 11;
    simcity->toolBox.tabSpriteToolBox[VUE1].screenY = 160;

    simcity->toolBox.tabSpriteToolBox[VUE1_HOVER].image = &simcity->tabBitmap[BITMAP_TOOLBOX];
    simcity->toolBox.tabSpriteToolBox[VUE1_HOVER].spriteLargeur = 35;
    simcity->toolBox.tabSpriteToolBox[VUE1_HOVER].spriteHauteur = 35;
    simcity->toolBox.tabSpriteToolBox[VUE1_HOVER].spriteX = 241;
    simcity->toolBox.tabSpriteToolBox[VUE1_HOVER].spriteY = 64;
    simcity->toolBox.tabSpriteToolBox[VUE1_HOVER].screenX = 11;
    simcity->toolBox.tabSpriteToolBox[VUE1_HOVER].screenY = 160;

    simcity->toolBox.tabSpriteToolBox[VUE1_CLIQUE].image = &simcity->tabBitmap[BITMAP_TOOLBOX];
    simcity->toolBox.tabSpriteToolBox[VUE1_CLIQUE].spriteLargeur = 35;
    simcity->toolBox.tabSpriteToolBox[VUE1_CLIQUE].spriteHauteur = 35;
    simcity->toolBox.tabSpriteToolBox[VUE1_CLIQUE].spriteX = 241;
    simcity->toolBox.tabSpriteToolBox[VUE1_CLIQUE].spriteY = 116;
    simcity->toolBox.tabSpriteToolBox[VUE1_CLIQUE].screenX = 11;
    simcity->toolBox.tabSpriteToolBox[VUE1_CLIQUE].screenY = 160;

    simcity->toolBox.tabSpriteToolBox[VUE2].image = &simcity->tabBitmap[BITMAP_TOOLBOX];
    simcity->toolBox.tabSpriteToolBox[VUE2].spriteLargeur = 35;
    simcity->toolBox.tabSpriteToolBox[VUE2].spriteHauteur = 35;
    simcity->toolBox.tabSpriteToolBox[VUE2].spriteX = 292;
    simcity->toolBox.tabSpriteToolBox[VUE2].spriteY = 14;
    simcity->toolBox.tabSpriteToolBox[VUE2].screenX = 61;
    simcity->toolBox.tabSpriteToolBox[VUE2].screenY = 160;

    simcity->toolBox.tabSpriteToolBox[VUE2_HOVER].image = &simcity->tabBitmap[BITMAP_TOOLBOX];
    simcity->toolBox.tabSpriteToolBox[VUE2_HOVER].spriteLargeur = 35;
    simcity->toolBox.tabSpriteToolBox[VUE2_HOVER].spriteHauteur = 35;
    simcity->toolBox.tabSpriteToolBox[VUE2_HOVER].spriteX = 292;
    simcity->toolBox.tabSpriteToolBox[VUE2_HOVER].spriteY = 64;
    simcity->toolBox.tabSpriteToolBox[VUE2_HOVER].screenX = 61;
    simcity->toolBox.tabSpriteToolBox[VUE2_HOVER].screenY = 160;

    simcity->toolBox.tabSpriteToolBox[VUE2_CLIQUE].image = &simcity->tabBitmap[BITMAP_TOOLBOX];
    simcity->toolBox.tabSpriteToolBox[VUE2_CLIQUE].spriteLargeur = 35;
    simcity->toolBox.tabSpriteToolBox[VUE2_CLIQUE].spriteHauteur = 35;
    simcity->toolBox.tabSpriteToolBox[VUE2_CLIQUE].spriteX = 292;
    simcity->toolBox.tabSpriteToolBox[VUE2_CLIQUE].spriteY = 116;
    simcity->toolBox.tabSpriteToolBox[VUE2_CLIQUE].screenX = 61;
    simcity->toolBox.tabSpriteToolBox[VUE2_CLIQUE].screenY = 160;

    simcity->toolBox.tabSpriteToolBox[POMPIER].image = &simcity->tabBitmap[BITMAP_TOOLBOX];
    simcity->toolBox.tabSpriteToolBox[POMPIER].spriteLargeur = 35;
    simcity->toolBox.tabSpriteToolBox[POMPIER].spriteHauteur = 35;
    simcity->toolBox.tabSpriteToolBox[POMPIER].spriteX = 338;
    simcity->toolBox.tabSpriteToolBox[POMPIER].spriteY = 14;
    simcity->toolBox.tabSpriteToolBox[POMPIER].screenX = 61;
    simcity->toolBox.tabSpriteToolBox[POMPIER].screenY = 113;

    simcity->toolBox.tabSpriteToolBox[POMPIER_HOVER].image = &simcity->tabBitmap[BITMAP_TOOLBOX];
    simcity->toolBox.tabSpriteToolBox[POMPIER_HOVER].spriteLargeur = 35;
    simcity->toolBox.tabSpriteToolBox[POMPIER_HOVER].spriteHauteur = 35;
    simcity->toolBox.tabSpriteToolBox[POMPIER_HOVER].spriteX = 338;
    simcity->toolBox.tabSpriteToolBox[POMPIER_HOVER].spriteY = 64;
    simcity->toolBox.tabSpriteToolBox[POMPIER_HOVER].screenX = 61;
    simcity->toolBox.tabSpriteToolBox[POMPIER_HOVER].screenY = 113;

    simcity->toolBox.tabSpriteToolBox[POMPIER_CLIQUE].image = &simcity->tabBitmap[BITMAP_TOOLBOX];
    simcity->toolBox.tabSpriteToolBox[POMPIER_CLIQUE].spriteLargeur = 35;
    simcity->toolBox.tabSpriteToolBox[POMPIER_CLIQUE].spriteHauteur = 35;
    simcity->toolBox.tabSpriteToolBox[POMPIER_CLIQUE].spriteX = 338;
    simcity->toolBox.tabSpriteToolBox[POMPIER_CLIQUE].spriteY = 116;
    simcity->toolBox.tabSpriteToolBox[POMPIER_CLIQUE].screenX = 61;
    simcity->toolBox.tabSpriteToolBox[POMPIER_CLIQUE].screenY = 113;

    simcity->toolBox.tabSpriteToolBox[PAUSE].image = &simcity->tabBitmap[BITMAP_BOUTON_PAUSE];
    simcity->toolBox.tabSpriteToolBox[PAUSE].spriteLargeur = 35;
    simcity->toolBox.tabSpriteToolBox[PAUSE].spriteHauteur = 35;
    simcity->toolBox.tabSpriteToolBox[PAUSE].spriteX = 18;
    simcity->toolBox.tabSpriteToolBox[PAUSE].spriteY = 11;
    simcity->toolBox.tabSpriteToolBox[PAUSE].screenX = 111;
    simcity->toolBox.tabSpriteToolBox[PAUSE].screenY = 720;

    simcity->toolBox.tabSpriteToolBox[PAUSE_HOVER].image = &simcity->tabBitmap[BITMAP_BOUTON_PAUSE];
    simcity->toolBox.tabSpriteToolBox[PAUSE_HOVER].spriteLargeur = 35;
    simcity->toolBox.tabSpriteToolBox[PAUSE_HOVER].spriteHauteur = 35;
    simcity->toolBox.tabSpriteToolBox[PAUSE_HOVER].spriteX = 69;
    simcity->toolBox.tabSpriteToolBox[PAUSE_HOVER].spriteY = 11;
    simcity->toolBox.tabSpriteToolBox[PAUSE_HOVER].screenX = 111;
    simcity->toolBox.tabSpriteToolBox[PAUSE_HOVER].screenY = 720;

    simcity->toolBox.tabSpriteToolBox[PAUSE_CLIQUE].image = &simcity->tabBitmap[BITMAP_BOUTON_PAUSE];
    simcity->toolBox.tabSpriteToolBox[PAUSE_CLIQUE].spriteLargeur = 35;
    simcity->toolBox.tabSpriteToolBox[PAUSE_CLIQUE].spriteHauteur = 40;
    simcity->toolBox.tabSpriteToolBox[PAUSE_CLIQUE].spriteX = 123;
    simcity->toolBox.tabSpriteToolBox[PAUSE_CLIQUE].spriteY = 11;
    simcity->toolBox.tabSpriteToolBox[PAUSE_CLIQUE].screenX = 111;
    simcity->toolBox.tabSpriteToolBox[PAUSE_CLIQUE].screenY = 720;
}

void calculHoverToolBox(Simcity* simcity){
    if (simcity->allegro.event.mouse.x >= simcity->toolBox.tabSpriteToolBox[ROUTE_].screenX && simcity->allegro.event.mouse.x <= simcity->toolBox.tabSpriteToolBox[ROUTE_].screenX + simcity->toolBox.tabSpriteToolBox[ROUTE_].spriteLargeur && simcity->allegro.event.mouse.y >= simcity->toolBox.tabSpriteToolBox[ROUTE_].screenY && simcity->allegro.event.mouse.y <= simcity->toolBox.tabSpriteToolBox[ROUTE_].screenY + simcity->toolBox.tabSpriteToolBox[ROUTE_].spriteHauteur ){
        simcity->toolBox.routeHover = 1;
    }else if (simcity->allegro.event.mouse.x >= simcity->toolBox.tabSpriteToolBox[MAISON_].screenX && simcity->allegro.event.mouse.x <= simcity->toolBox.tabSpriteToolBox[MAISON_].screenX + simcity->toolBox.tabSpriteToolBox[MAISON_].spriteLargeur && simcity->allegro.event.mouse.y > simcity->toolBox.tabSpriteToolBox[MAISON_].screenY && simcity->allegro.event.mouse.y <= simcity->toolBox.tabSpriteToolBox[MAISON_].screenY + simcity->toolBox.tabSpriteToolBox[MAISON_].spriteHauteur ){
        simcity->toolBox.maisonHover = 1;
    }else if (simcity->allegro.event.mouse.x >= simcity->toolBox.tabSpriteToolBox[EAU].screenX && simcity->allegro.event.mouse.x <= simcity->toolBox.tabSpriteToolBox[EAU].screenX + simcity->toolBox.tabSpriteToolBox[EAU].spriteLargeur && simcity->allegro.event.mouse.y >= simcity->toolBox.tabSpriteToolBox[EAU].screenY && simcity->allegro.event.mouse.y <= simcity->toolBox.tabSpriteToolBox[EAU].screenY + simcity->toolBox.tabSpriteToolBox[EAU].spriteHauteur ){
        simcity->toolBox.eauHover = 1;
    }else if (simcity->allegro.event.mouse.x >= simcity->toolBox.tabSpriteToolBox[ELEC].screenX && simcity->allegro.event.mouse.x <= simcity->toolBox.tabSpriteToolBox[ELEC].screenX + simcity->toolBox.tabSpriteToolBox[ELEC].spriteLargeur && simcity->allegro.event.mouse.y >= simcity->toolBox.tabSpriteToolBox[ELEC].screenY && simcity->allegro.event.mouse.y <= simcity->toolBox.tabSpriteToolBox[ELEC].screenY + simcity->toolBox.tabSpriteToolBox[ELEC].spriteHauteur ){
        simcity->toolBox.elecHover = 1;
    }else if (simcity->allegro.event.mouse.x >= simcity->toolBox.tabSpriteToolBox[DETRUIRE].screenX && simcity->allegro.event.mouse.x <= simcity->toolBox.tabSpriteToolBox[DETRUIRE].screenX + simcity->toolBox.tabSpriteToolBox[DETRUIRE].spriteLargeur && simcity->allegro.event.mouse.y >= simcity->toolBox.tabSpriteToolBox[DETRUIRE].screenY && simcity->allegro.event.mouse.y <= simcity->toolBox.tabSpriteToolBox[DETRUIRE].screenY + simcity->toolBox.tabSpriteToolBox[DETRUIRE].spriteHauteur ){
        simcity->toolBox.detruireHover = 1;
    }else if (simcity->allegro.event.mouse.x >= simcity->toolBox.tabSpriteToolBox[VUE1].screenX && simcity->allegro.event.mouse.x <= simcity->toolBox.tabSpriteToolBox[VUE1].screenX + simcity->toolBox.tabSpriteToolBox[VUE1].spriteLargeur && simcity->allegro.event.mouse.y >= simcity->toolBox.tabSpriteToolBox[VUE1].screenY && simcity->allegro.event.mouse.y <= simcity->toolBox.tabSpriteToolBox[VUE1].screenY + simcity->toolBox.tabSpriteToolBox[VUE1].spriteHauteur ){
        simcity->toolBox.vue1Hover = 1;
    }else if (simcity->allegro.event.mouse.x >= simcity->toolBox.tabSpriteToolBox[VUE2].screenX && simcity->allegro.event.mouse.x <= simcity->toolBox.tabSpriteToolBox[VUE2].screenX + simcity->toolBox.tabSpriteToolBox[VUE2].spriteLargeur && simcity->allegro.event.mouse.y >= simcity->toolBox.tabSpriteToolBox[VUE2].screenY && simcity->allegro.event.mouse.y <= simcity->toolBox.tabSpriteToolBox[VUE2].screenY + simcity->toolBox.tabSpriteToolBox[VUE2].spriteHauteur ){
        simcity->toolBox.vue2Hover = 1;
    }else if (simcity->allegro.event.mouse.x >= simcity->toolBox.tabSpriteToolBox[POMPIER].screenX && simcity->allegro.event.mouse.x <= simcity->toolBox.tabSpriteToolBox[POMPIER].screenX + simcity->toolBox.tabSpriteToolBox[POMPIER].spriteLargeur && simcity->allegro.event.mouse.y >= simcity->toolBox.tabSpriteToolBox[POMPIER].screenY && simcity->allegro.event.mouse.y <= simcity->toolBox.tabSpriteToolBox[POMPIER].screenY + simcity->toolBox.tabSpriteToolBox[POMPIER].spriteHauteur ){
        simcity->toolBox.pompierHover = 1;
    } else if (simcity->allegro.event.mouse.x >= simcity->toolBox.tabSpriteToolBox[PAUSE].screenX && simcity->allegro.event.mouse.x <= simcity->toolBox.tabSpriteToolBox[PAUSE].screenX + simcity->toolBox.tabSpriteToolBox[PAUSE].spriteLargeur && simcity->allegro.event.mouse.y >= simcity->toolBox.tabSpriteToolBox[PAUSE].screenY && simcity->allegro.event.mouse.y <= simcity->toolBox.tabSpriteToolBox[PAUSE].screenY + simcity->toolBox.tabSpriteToolBox[PAUSE].spriteHauteur ){
        simcity->toolBox.pauseHover = 1;
    }else{
        simcity->toolBox.routeHover = 0;
        simcity->toolBox.maisonHover = 0;
        simcity->toolBox.elecHover = 0;
        simcity->toolBox.eauHover = 0;
        simcity->toolBox.detruireHover = 0;
        simcity->toolBox.vue1Hover = 0;
        simcity->toolBox.vue2Hover = 0;
        simcity->toolBox.pompierHover = 0;
        simcity->toolBox.pauseHover = 0;

    }

}

void detectionCliqueToolBox(Simcity* simcity){
    if (simcity->allegro.event.mouse.button == 1 && simcity->allegro.event.mouse.x >= simcity->toolBox.tabSpriteToolBox[ROUTE_].screenX && simcity->allegro.event.mouse.x <= simcity->toolBox.tabSpriteToolBox[ROUTE_].screenX + simcity->toolBox.tabSpriteToolBox[ROUTE_].spriteLargeur && simcity->allegro.event.mouse.y >= simcity->toolBox.tabSpriteToolBox[ROUTE_].screenY && simcity->allegro.event.mouse.y <= simcity->toolBox.tabSpriteToolBox[ROUTE_].screenY + simcity->toolBox.tabSpriteToolBox[ROUTE_].spriteHauteur ){
        simcity->toolBox.routeClique = 1;
        simcity->toolBox.routeEnMain = 1;
    }else if (simcity->allegro.event.mouse.button == 1 && simcity->allegro.event.mouse.x >= simcity->toolBox.tabSpriteToolBox[MAISON_].screenX && simcity->allegro.event.mouse.x <= simcity->toolBox.tabSpriteToolBox[MAISON_].screenX + simcity->toolBox.tabSpriteToolBox[MAISON_].spriteLargeur && simcity->allegro.event.mouse.y > simcity->toolBox.tabSpriteToolBox[MAISON_].screenY && simcity->allegro.event.mouse.y <= simcity->toolBox.tabSpriteToolBox[MAISON_].screenY + simcity->toolBox.tabSpriteToolBox[MAISON_].spriteHauteur ){
        simcity->toolBox.maisonClique = 1;
        simcity->toolBox.terrainVagueEnMain = 1;
    }else if (simcity->allegro.event.mouse.button == 1 && simcity->allegro.event.mouse.x >= simcity->toolBox.tabSpriteToolBox[EAU].screenX && simcity->allegro.event.mouse.x <= simcity->toolBox.tabSpriteToolBox[EAU].screenX + simcity->toolBox.tabSpriteToolBox[EAU].spriteLargeur && simcity->allegro.event.mouse.y >= simcity->toolBox.tabSpriteToolBox[EAU].screenY && simcity->allegro.event.mouse.y <= simcity->toolBox.tabSpriteToolBox[EAU].screenY + simcity->toolBox.tabSpriteToolBox[EAU].spriteHauteur ){
        simcity->toolBox.eauClique = 1;
        simcity->toolBox.eauEnMain = 1;
        simcity->toolBox.eauDroit = 1;
    }else if (simcity->allegro.event.mouse.button == 1 && simcity->allegro.event.mouse.x >= simcity->toolBox.tabSpriteToolBox[ELEC].screenX && simcity->allegro.event.mouse.x <= simcity->toolBox.tabSpriteToolBox[ELEC].screenX + simcity->toolBox.tabSpriteToolBox[ELEC].spriteLargeur && simcity->allegro.event.mouse.y >= simcity->toolBox.tabSpriteToolBox[ELEC].screenY && simcity->allegro.event.mouse.y <= simcity->toolBox.tabSpriteToolBox[ELEC].screenY + simcity->toolBox.tabSpriteToolBox[ELEC].spriteHauteur ){
        simcity->toolBox.elecClique = 1;
        simcity->toolBox.elecEnMain = 1;
        simcity->toolBox.elecDroit = 1;
    }else if (simcity->allegro.event.mouse.button == 1 && simcity->allegro.event.mouse.x >= simcity->toolBox.tabSpriteToolBox[DETRUIRE].screenX && simcity->allegro.event.mouse.x <= simcity->toolBox.tabSpriteToolBox[DETRUIRE].screenX + simcity->toolBox.tabSpriteToolBox[DETRUIRE].spriteLargeur && simcity->allegro.event.mouse.y >= simcity->toolBox.tabSpriteToolBox[DETRUIRE].screenY && simcity->allegro.event.mouse.y <= simcity->toolBox.tabSpriteToolBox[DETRUIRE].screenY + simcity->toolBox.tabSpriteToolBox[DETRUIRE].spriteHauteur ){
        simcity->toolBox.detruireClique = 1;
        simcity->toolBox.detruireEnMain = 1;
    }else if (simcity->allegro.event.mouse.button == 1 && simcity->allegro.event.mouse.x >= simcity->toolBox.tabSpriteToolBox[VUE1].screenX && simcity->allegro.event.mouse.x <= simcity->toolBox.tabSpriteToolBox[VUE1].screenX + simcity->toolBox.tabSpriteToolBox[VUE1].spriteLargeur && simcity->allegro.event.mouse.y >= simcity->toolBox.tabSpriteToolBox[VUE1].screenY && simcity->allegro.event.mouse.y <= simcity->toolBox.tabSpriteToolBox[VUE1].screenY + simcity->toolBox.tabSpriteToolBox[VUE1].spriteHauteur ){
        simcity->toolBox.vue1Clique = 1;
        simcity->toolBox.vue1EnMain = 1;
    }else if (simcity->allegro.event.mouse.button == 1 && simcity->allegro.event.mouse.x >= simcity->toolBox.tabSpriteToolBox[VUE2].screenX && simcity->allegro.event.mouse.x <= simcity->toolBox.tabSpriteToolBox[VUE2].screenX + simcity->toolBox.tabSpriteToolBox[VUE2].spriteLargeur && simcity->allegro.event.mouse.y >= simcity->toolBox.tabSpriteToolBox[VUE2].screenY && simcity->allegro.event.mouse.y <= simcity->toolBox.tabSpriteToolBox[VUE2].screenY + simcity->toolBox.tabSpriteToolBox[VUE2].spriteHauteur ){
        simcity->toolBox.vue2Clique = 1;
        simcity->toolBox.vue2EnMain = 1;
    }else if (simcity->allegro.event.mouse.button == 1 && simcity->allegro.event.mouse.x >= simcity->toolBox.tabSpriteToolBox[POMPIER].screenX && simcity->allegro.event.mouse.x <= simcity->toolBox.tabSpriteToolBox[POMPIER].screenX + simcity->toolBox.tabSpriteToolBox[POMPIER].spriteLargeur && simcity->allegro.event.mouse.y >= simcity->toolBox.tabSpriteToolBox[POMPIER].screenY && simcity->allegro.event.mouse.y <= simcity->toolBox.tabSpriteToolBox[POMPIER].screenY + simcity->toolBox.tabSpriteToolBox[POMPIER].spriteHauteur ){
        simcity->toolBox.pompierClique = 1;
        simcity->toolBox.pompierEnMain = 1;
        simcity->toolBox.pompierDroit = 1;
    }else if (simcity->allegro.event.mouse.button == 1 && simcity->allegro.event.mouse.x >= simcity->toolBox.tabSpriteToolBox[PAUSE].screenX && simcity->allegro.event.mouse.x <= simcity->toolBox.tabSpriteToolBox[PAUSE].screenX + simcity->toolBox.tabSpriteToolBox[PAUSE].spriteLargeur && simcity->allegro.event.mouse.y >= simcity->toolBox.tabSpriteToolBox[PAUSE].screenY && simcity->allegro.event.mouse.y <= simcity->toolBox.tabSpriteToolBox[PAUSE].screenY + simcity->toolBox.tabSpriteToolBox[PAUSE].spriteHauteur ){
        simcity->toolBox.pauseClique = 1;
        simcity->toolBox.pauseEnMain = 1;
    }else{
        simcity->toolBox.routeClique = 0;
        simcity->toolBox.maisonClique = 0;
        simcity->toolBox.elecClique = 0;
        simcity->toolBox.eauClique = 0;
        simcity->toolBox.detruireClique = 0;
        simcity->toolBox.vue1Clique = 0;
        simcity->toolBox.vue2Clique = 0;
        simcity->toolBox.pompierClique = 0;
        simcity->toolBox.pauseClique = 0;

        simcity->toolBox.routeEnMain = 0;
        simcity->toolBox.terrainVagueEnMain = 0;
        simcity->toolBox.eauEnMain = 0;
        simcity->toolBox.elecEnMain = 0;
        simcity->toolBox.detruireEnMain = 0;
        simcity->toolBox.vue1EnMain = 0;
        simcity->toolBox.vue2EnMain = 0;
        simcity->toolBox.pompierEnMain = 0;
        simcity->toolBox.pauseEnMain = 0;


    }

}

void afficherToolbox (Simcity* simcity){
    al_draw_filled_rectangle(0,0,111,220, al_map_rgb(105,105,105));
    al_draw_bitmap_region(*(simcity->toolBox.tabSpriteToolBox[ROUTE_].image),simcity->toolBox.tabSpriteToolBox[ROUTE_].spriteX,simcity->toolBox.tabSpriteToolBox[ROUTE_].spriteY,simcity->toolBox.tabSpriteToolBox[ROUTE_].spriteLargeur,simcity->toolBox.tabSpriteToolBox[ROUTE_].spriteHauteur,simcity->toolBox.tabSpriteToolBox[ROUTE_].screenX,simcity->toolBox.tabSpriteToolBox[ROUTE_].screenY,0);
    al_draw_bitmap_region(*(simcity->toolBox.tabSpriteToolBox[MAISON_].image),simcity->toolBox.tabSpriteToolBox[MAISON_].spriteX,simcity->toolBox.tabSpriteToolBox[MAISON_].spriteY,simcity->toolBox.tabSpriteToolBox[MAISON_].spriteLargeur,simcity->toolBox.tabSpriteToolBox[MAISON_].spriteHauteur,simcity->toolBox.tabSpriteToolBox[MAISON_].screenX,simcity->toolBox.tabSpriteToolBox[MAISON_].screenY,0);
    al_draw_bitmap_region(*(simcity->toolBox.tabSpriteToolBox[ELEC].image),simcity->toolBox.tabSpriteToolBox[ELEC].spriteX,simcity->toolBox.tabSpriteToolBox[ELEC].spriteY,simcity->toolBox.tabSpriteToolBox[ELEC].spriteLargeur,simcity->toolBox.tabSpriteToolBox[ELEC].spriteHauteur,simcity->toolBox.tabSpriteToolBox[ELEC].screenX,simcity->toolBox.tabSpriteToolBox[ELEC].screenY,0);
    al_draw_bitmap_region(*(simcity->toolBox.tabSpriteToolBox[EAU].image),simcity->toolBox.tabSpriteToolBox[EAU].spriteX,simcity->toolBox.tabSpriteToolBox[EAU].spriteY,simcity->toolBox.tabSpriteToolBox[EAU].spriteLargeur,simcity->toolBox.tabSpriteToolBox[EAU].spriteHauteur,simcity->toolBox.tabSpriteToolBox[EAU].screenX,simcity->toolBox.tabSpriteToolBox[EAU].screenY,0);
    al_draw_bitmap_region(*(simcity->toolBox.tabSpriteToolBox[DETRUIRE].image),simcity->toolBox.tabSpriteToolBox[DETRUIRE].spriteX,simcity->toolBox.tabSpriteToolBox[DETRUIRE].spriteY,simcity->toolBox.tabSpriteToolBox[DETRUIRE].spriteLargeur,simcity->toolBox.tabSpriteToolBox[DETRUIRE].spriteHauteur,simcity->toolBox.tabSpriteToolBox[DETRUIRE].screenX,simcity->toolBox.tabSpriteToolBox[DETRUIRE].screenY,0);
    al_draw_bitmap_region(*(simcity->toolBox.tabSpriteToolBox[VUE1].image),simcity->toolBox.tabSpriteToolBox[VUE1].spriteX,simcity->toolBox.tabSpriteToolBox[VUE1].spriteY,simcity->toolBox.tabSpriteToolBox[VUE1].spriteLargeur,simcity->toolBox.tabSpriteToolBox[VUE1].spriteHauteur,simcity->toolBox.tabSpriteToolBox[VUE1].screenX,simcity->toolBox.tabSpriteToolBox[VUE1].screenY,0);
    al_draw_bitmap_region(*(simcity->toolBox.tabSpriteToolBox[VUE2].image),simcity->toolBox.tabSpriteToolBox[VUE2].spriteX,simcity->toolBox.tabSpriteToolBox[VUE2].spriteY,simcity->toolBox.tabSpriteToolBox[VUE2].spriteLargeur,simcity->toolBox.tabSpriteToolBox[VUE2].spriteHauteur,simcity->toolBox.tabSpriteToolBox[VUE2].screenX,simcity->toolBox.tabSpriteToolBox[VUE2].screenY,0);
    al_draw_bitmap_region(*(simcity->toolBox.tabSpriteToolBox[POMPIER].image),simcity->toolBox.tabSpriteToolBox[POMPIER].spriteX,simcity->toolBox.tabSpriteToolBox[POMPIER].spriteY,simcity->toolBox.tabSpriteToolBox[POMPIER].spriteLargeur,simcity->toolBox.tabSpriteToolBox[POMPIER].spriteHauteur,simcity->toolBox.tabSpriteToolBox[POMPIER].screenX,simcity->toolBox.tabSpriteToolBox[POMPIER].screenY,0);
    al_draw_bitmap_region(*(simcity->toolBox.tabSpriteToolBox[PAUSE].image),simcity->toolBox.tabSpriteToolBox[PAUSE].spriteX,simcity->toolBox.tabSpriteToolBox[PAUSE].spriteY,simcity->toolBox.tabSpriteToolBox[PAUSE].spriteLargeur,simcity->toolBox.tabSpriteToolBox[PAUSE].spriteHauteur,simcity->toolBox.tabSpriteToolBox[PAUSE].screenX,simcity->toolBox.tabSpriteToolBox[PAUSE].screenY,0);

    if (simcity->toolBox.routeHover){
        al_draw_bitmap_region(*(simcity->toolBox.tabSpriteToolBox[ROUTE_HOVER].image),simcity->toolBox.tabSpriteToolBox[ROUTE_HOVER].spriteX,simcity->toolBox.tabSpriteToolBox[ROUTE_HOVER].spriteY,simcity->toolBox.tabSpriteToolBox[ROUTE_HOVER].spriteLargeur,simcity->toolBox.tabSpriteToolBox[ROUTE_HOVER].spriteHauteur,simcity->toolBox.tabSpriteToolBox[ROUTE_HOVER].screenX,simcity->toolBox.tabSpriteToolBox[ROUTE_HOVER].screenY,0);

    } else if (simcity->toolBox.maisonHover){
        al_draw_bitmap_region(*(simcity->toolBox.tabSpriteToolBox[MAISON_HOVER].image),simcity->toolBox.tabSpriteToolBox[MAISON_HOVER].spriteX,simcity->toolBox.tabSpriteToolBox[MAISON_HOVER].spriteY,simcity->toolBox.tabSpriteToolBox[MAISON_HOVER].spriteLargeur,simcity->toolBox.tabSpriteToolBox[MAISON_HOVER].spriteHauteur,simcity->toolBox.tabSpriteToolBox[MAISON_HOVER].screenX,simcity->toolBox.tabSpriteToolBox[MAISON_HOVER].screenY,0);

    }else if (simcity->toolBox.elecHover){
        al_draw_bitmap_region(*(simcity->toolBox.tabSpriteToolBox[ELEC_HOVER].image),simcity->toolBox.tabSpriteToolBox[ELEC_HOVER].spriteX,simcity->toolBox.tabSpriteToolBox[ELEC_HOVER].spriteY,simcity->toolBox.tabSpriteToolBox[ELEC_HOVER].spriteLargeur,simcity->toolBox.tabSpriteToolBox[ELEC_HOVER].spriteHauteur,simcity->toolBox.tabSpriteToolBox[ELEC_HOVER].screenX,simcity->toolBox.tabSpriteToolBox[ELEC_HOVER].screenY,0);

    }else if (simcity->toolBox.eauHover){
        al_draw_bitmap_region(*(simcity->toolBox.tabSpriteToolBox[EAU_HOVER].image),simcity->toolBox.tabSpriteToolBox[EAU_HOVER].spriteX,simcity->toolBox.tabSpriteToolBox[EAU_HOVER].spriteY,simcity->toolBox.tabSpriteToolBox[EAU_HOVER].spriteLargeur,simcity->toolBox.tabSpriteToolBox[EAU_HOVER].spriteHauteur,simcity->toolBox.tabSpriteToolBox[EAU_HOVER].screenX,simcity->toolBox.tabSpriteToolBox[EAU_HOVER].screenY,0);

    }else if (simcity->toolBox.detruireHover){
        al_draw_bitmap_region(*(simcity->toolBox.tabSpriteToolBox[DETRUIRE_HOVER].image),simcity->toolBox.tabSpriteToolBox[DETRUIRE_HOVER].spriteX,simcity->toolBox.tabSpriteToolBox[DETRUIRE_HOVER].spriteY,simcity->toolBox.tabSpriteToolBox[DETRUIRE_HOVER].spriteLargeur,simcity->toolBox.tabSpriteToolBox[DETRUIRE_HOVER].spriteHauteur,simcity->toolBox.tabSpriteToolBox[DETRUIRE_HOVER].screenX,simcity->toolBox.tabSpriteToolBox[DETRUIRE_HOVER].screenY,0);

    }else if (simcity->toolBox.vue1Hover){
        al_draw_bitmap_region(*(simcity->toolBox.tabSpriteToolBox[VUE1_HOVER].image),simcity->toolBox.tabSpriteToolBox[VUE1_HOVER].spriteX,simcity->toolBox.tabSpriteToolBox[VUE1_HOVER].spriteY,simcity->toolBox.tabSpriteToolBox[VUE1_HOVER].spriteLargeur,simcity->toolBox.tabSpriteToolBox[VUE1_HOVER].spriteHauteur,simcity->toolBox.tabSpriteToolBox[VUE1_HOVER].screenX,simcity->toolBox.tabSpriteToolBox[VUE1_HOVER].screenY,0);

    }else if (simcity->toolBox.vue2Hover){
        al_draw_bitmap_region(*(simcity->toolBox.tabSpriteToolBox[VUE2_HOVER].image),simcity->toolBox.tabSpriteToolBox[VUE2_HOVER].spriteX,simcity->toolBox.tabSpriteToolBox[VUE2_HOVER].spriteY,simcity->toolBox.tabSpriteToolBox[VUE2_HOVER].spriteLargeur,simcity->toolBox.tabSpriteToolBox[VUE2_HOVER].spriteHauteur,simcity->toolBox.tabSpriteToolBox[VUE2_HOVER].screenX,simcity->toolBox.tabSpriteToolBox[VUE2_HOVER].screenY,0);

    }else if (simcity->toolBox.pompierHover){
        al_draw_bitmap_region(*(simcity->toolBox.tabSpriteToolBox[POMPIER_HOVER].image),simcity->toolBox.tabSpriteToolBox[POMPIER_HOVER].spriteX,simcity->toolBox.tabSpriteToolBox[POMPIER_HOVER].spriteY,simcity->toolBox.tabSpriteToolBox[POMPIER_HOVER].spriteLargeur,simcity->toolBox.tabSpriteToolBox[POMPIER_HOVER].spriteHauteur,simcity->toolBox.tabSpriteToolBox[POMPIER_HOVER].screenX,simcity->toolBox.tabSpriteToolBox[POMPIER_HOVER].screenY,0);

    }else if (simcity->toolBox.pauseHover){
        al_draw_bitmap_region(*(simcity->toolBox.tabSpriteToolBox[PAUSE_HOVER].image),simcity->toolBox.tabSpriteToolBox[PAUSE_HOVER].spriteX,simcity->toolBox.tabSpriteToolBox[PAUSE_HOVER].spriteY,simcity->toolBox.tabSpriteToolBox[PAUSE_HOVER].spriteLargeur,simcity->toolBox.tabSpriteToolBox[PAUSE_HOVER].spriteHauteur,simcity->toolBox.tabSpriteToolBox[PAUSE_HOVER].screenX,simcity->toolBox.tabSpriteToolBox[PAUSE_HOVER].screenY,0);

    }else if (simcity->toolBox.routeClique){
        al_draw_bitmap_region(*(simcity->toolBox.tabSpriteToolBox[ROUTE_CLIQUE].image),simcity->toolBox.tabSpriteToolBox[ROUTE_CLIQUE].spriteX,simcity->toolBox.tabSpriteToolBox[ROUTE_CLIQUE].spriteY,simcity->toolBox.tabSpriteToolBox[ROUTE_CLIQUE].spriteLargeur,simcity->toolBox.tabSpriteToolBox[ROUTE_CLIQUE].spriteHauteur,simcity->toolBox.tabSpriteToolBox[ROUTE_CLIQUE].screenX,simcity->toolBox.tabSpriteToolBox[ROUTE_CLIQUE].screenY,0);

    }else if (simcity->toolBox.maisonClique){
        al_draw_bitmap_region(*(simcity->toolBox.tabSpriteToolBox[MAISON_CLIQUE].image),simcity->toolBox.tabSpriteToolBox[MAISON_CLIQUE].spriteX,simcity->toolBox.tabSpriteToolBox[MAISON_CLIQUE].spriteY,simcity->toolBox.tabSpriteToolBox[MAISON_CLIQUE].spriteLargeur,simcity->toolBox.tabSpriteToolBox[MAISON_CLIQUE].spriteHauteur,simcity->toolBox.tabSpriteToolBox[MAISON_CLIQUE].screenX,simcity->toolBox.tabSpriteToolBox[MAISON_CLIQUE].screenY,0);

    }else if (simcity->toolBox.eauClique){
        al_draw_bitmap_region(*(simcity->toolBox.tabSpriteToolBox[EAU_CLIQUE].image),simcity->toolBox.tabSpriteToolBox[EAU_CLIQUE].spriteX,simcity->toolBox.tabSpriteToolBox[EAU_CLIQUE].spriteY,simcity->toolBox.tabSpriteToolBox[EAU_CLIQUE].spriteLargeur,simcity->toolBox.tabSpriteToolBox[EAU_CLIQUE].spriteHauteur,simcity->toolBox.tabSpriteToolBox[EAU_CLIQUE].screenX,simcity->toolBox.tabSpriteToolBox[EAU_CLIQUE].screenY,0);

    }else if (simcity->toolBox.elecClique){
        al_draw_bitmap_region(*(simcity->toolBox.tabSpriteToolBox[ELEC_CLIQUE].image),simcity->toolBox.tabSpriteToolBox[ELEC_CLIQUE].spriteX,simcity->toolBox.tabSpriteToolBox[ELEC_CLIQUE].spriteY,simcity->toolBox.tabSpriteToolBox[ELEC_CLIQUE].spriteLargeur,simcity->toolBox.tabSpriteToolBox[ELEC_CLIQUE].spriteHauteur,simcity->toolBox.tabSpriteToolBox[ELEC_CLIQUE].screenX,simcity->toolBox.tabSpriteToolBox[ELEC_CLIQUE].screenY,0);

    }else if (simcity->toolBox.detruireClique){
        al_draw_bitmap_region(*(simcity->toolBox.tabSpriteToolBox[DETRUIRE_CLIQUE].image),simcity->toolBox.tabSpriteToolBox[DETRUIRE_CLIQUE].spriteX,simcity->toolBox.tabSpriteToolBox[DETRUIRE_CLIQUE].spriteY,simcity->toolBox.tabSpriteToolBox[DETRUIRE_CLIQUE].spriteLargeur,simcity->toolBox.tabSpriteToolBox[DETRUIRE_CLIQUE].spriteHauteur,simcity->toolBox.tabSpriteToolBox[DETRUIRE_CLIQUE].screenX,simcity->toolBox.tabSpriteToolBox[DETRUIRE_CLIQUE].screenY,0);

    }else if (simcity->toolBox.vue1Clique){
        al_draw_bitmap_region(*(simcity->toolBox.tabSpriteToolBox[VUE1_CLIQUE].image),simcity->toolBox.tabSpriteToolBox[VUE1_CLIQUE].spriteX,simcity->toolBox.tabSpriteToolBox[VUE1_CLIQUE].spriteY,simcity->toolBox.tabSpriteToolBox[VUE1_CLIQUE].spriteLargeur,simcity->toolBox.tabSpriteToolBox[VUE1_CLIQUE].spriteHauteur,simcity->toolBox.tabSpriteToolBox[VUE1_CLIQUE].screenX,simcity->toolBox.tabSpriteToolBox[VUE1_CLIQUE].screenY,0);

    }else if (simcity->toolBox.vue2Clique){
        al_draw_bitmap_region(*(simcity->toolBox.tabSpriteToolBox[VUE2_CLIQUE].image),simcity->toolBox.tabSpriteToolBox[VUE2_CLIQUE].spriteX,simcity->toolBox.tabSpriteToolBox[VUE2_CLIQUE].spriteY,simcity->toolBox.tabSpriteToolBox[VUE2_CLIQUE].spriteLargeur,simcity->toolBox.tabSpriteToolBox[VUE2_CLIQUE].spriteHauteur,simcity->toolBox.tabSpriteToolBox[VUE2_CLIQUE].screenX,simcity->toolBox.tabSpriteToolBox[VUE2_CLIQUE].screenY,0);

    }else if (simcity->toolBox.pompierClique){
        al_draw_bitmap_region(*(simcity->toolBox.tabSpriteToolBox[POMPIER_CLIQUE].image),simcity->toolBox.tabSpriteToolBox[POMPIER_CLIQUE].spriteX,simcity->toolBox.tabSpriteToolBox[POMPIER_CLIQUE].spriteY,simcity->toolBox.tabSpriteToolBox[POMPIER_CLIQUE].spriteLargeur,simcity->toolBox.tabSpriteToolBox[POMPIER_CLIQUE].spriteHauteur,simcity->toolBox.tabSpriteToolBox[POMPIER_CLIQUE].screenX,simcity->toolBox.tabSpriteToolBox[POMPIER_CLIQUE].screenY,0);
    }else if (simcity->toolBox.pauseClique){
        al_draw_bitmap_region(*(simcity->toolBox.tabSpriteToolBox[PAUSE_CLIQUE].image),simcity->toolBox.tabSpriteToolBox[PAUSE_CLIQUE].spriteX,simcity->toolBox.tabSpriteToolBox[PAUSE_CLIQUE].spriteY,simcity->toolBox.tabSpriteToolBox[PAUSE_CLIQUE].spriteLargeur,simcity->toolBox.tabSpriteToolBox[PAUSE_CLIQUE].spriteHauteur,simcity->toolBox.tabSpriteToolBox[PAUSE_CLIQUE].screenX,simcity->toolBox.tabSpriteToolBox[PAUSE_CLIQUE].screenY,0);
    }


}
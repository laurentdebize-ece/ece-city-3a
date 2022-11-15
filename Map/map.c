#include "map.h"
#include "../Structures/structures.h"


void initDataMap(Simcity* simcity){
    for (int x = 0; x < NBCELLULEX; ++x) {
        for (int y = 0; y < NBCELLULEY ; ++y) {
            simcity->map.mapTile[x][y].spriteLargeur = 20;
            simcity->map.mapTile[x][y].spriteHauteur = 20;
            simcity->map.mapTile[x][y].typeBloc = 0;
            simcity->map.mapTile[x][y].coordsXY.screenX = 110 + 20 * x;
            simcity->map.mapTile[x][y].coordsXY.screenY = 0 + 20 * y;
            simcity->map.mapTile[x][y].coordsXY.celluleX = x;
            simcity->map.mapTile[x][y].coordsXY.celluleY = y;

        }
    }
    bitmapSpriteInit(simcity);
    toolboxSpriteInit(simcity);
}

void toolboxSpriteInit(Simcity* simcity){
    simcity->toolBox.tabSpriteToolBox[TOOLBOX_FOND_GRIS].image = &simcity->tabBitmap[BITMAP_TOOLBOX];
    simcity->toolBox.tabSpriteToolBox[TOOLBOX_FOND_GRIS].spriteLargeur = 111;
    simcity->toolBox.tabSpriteToolBox[TOOLBOX_FOND_GRIS].spriteHauteur = 360;
    simcity->toolBox.tabSpriteToolBox[TOOLBOX_FOND_GRIS].spriteX = 388;
    simcity->toolBox.tabSpriteToolBox[TOOLBOX_FOND_GRIS].spriteY = 15;
    simcity->toolBox.tabSpriteToolBox[TOOLBOX_FOND_GRIS].screenX = 0;
    simcity->toolBox.tabSpriteToolBox[TOOLBOX_FOND_GRIS].screenY = 0;

    simcity->toolBox.tabSpriteToolBox[TOOLBOX_ROUTE].image = &simcity->tabBitmap[BITMAP_TOOLBOX];
    simcity->toolBox.tabSpriteToolBox[TOOLBOX_ROUTE].spriteLargeur = 35;
    simcity->toolBox.tabSpriteToolBox[TOOLBOX_ROUTE].spriteHauteur = 35;
    simcity->toolBox.tabSpriteToolBox[TOOLBOX_ROUTE].spriteX = 13;
    simcity->toolBox.tabSpriteToolBox[TOOLBOX_ROUTE].spriteY = 15;
    simcity->toolBox.tabSpriteToolBox[TOOLBOX_ROUTE].screenX = 15;
    simcity->toolBox.tabSpriteToolBox[TOOLBOX_ROUTE].screenY = 15;

    simcity->toolBox.tabSpriteToolBox[TOOLBOX_MAISON].image = &simcity->tabBitmap[BITMAP_TOOLBOX];
    simcity->toolBox.tabSpriteToolBox[TOOLBOX_MAISON].spriteLargeur = 36;
    simcity->toolBox.tabSpriteToolBox[TOOLBOX_MAISON].spriteHauteur = 36;
    simcity->toolBox.tabSpriteToolBox[TOOLBOX_MAISON].spriteX = 62;
    simcity->toolBox.tabSpriteToolBox[TOOLBOX_MAISON].spriteY = 14;
    simcity->toolBox.tabSpriteToolBox[TOOLBOX_MAISON].screenX = 65;
    simcity->toolBox.tabSpriteToolBox[TOOLBOX_MAISON].screenY = 15;

    simcity->toolBox.tabSpriteToolBox[TOOLBOX_ELEC].image = &simcity->tabBitmap[BITMAP_TOOLBOX];
    simcity->toolBox.tabSpriteToolBox[TOOLBOX_ELEC].spriteLargeur = 35;
    simcity->toolBox.tabSpriteToolBox[TOOLBOX_ELEC].spriteHauteur = 35;
    simcity->toolBox.tabSpriteToolBox[TOOLBOX_ELEC].spriteX = 107;
    simcity->toolBox.tabSpriteToolBox[TOOLBOX_ELEC].spriteY = 14;
    simcity->toolBox.tabSpriteToolBox[TOOLBOX_ELEC].screenX = 15;
    simcity->toolBox.tabSpriteToolBox[TOOLBOX_ELEC].screenY = 65;

    simcity->toolBox.tabSpriteToolBox[TOOLBOX_EAU].image = &simcity->tabBitmap[BITMAP_TOOLBOX];
    simcity->toolBox.tabSpriteToolBox[TOOLBOX_EAU].spriteLargeur = 35;
    simcity->toolBox.tabSpriteToolBox[TOOLBOX_EAU].spriteHauteur = 35;
    simcity->toolBox.tabSpriteToolBox[TOOLBOX_EAU].spriteX = 152;
    simcity->toolBox.tabSpriteToolBox[TOOLBOX_EAU].spriteY = 14;
    simcity->toolBox.tabSpriteToolBox[TOOLBOX_EAU].screenX = 65;
    simcity->toolBox.tabSpriteToolBox[TOOLBOX_EAU].screenY = 65;

    simcity->toolBox.tabSpriteToolBox[TOOLBOX_DEMOLIR].image = &simcity->tabBitmap[BITMAP_TOOLBOX];
    simcity->toolBox.tabSpriteToolBox[TOOLBOX_DEMOLIR].spriteLargeur = 35;
    simcity->toolBox.tabSpriteToolBox[TOOLBOX_DEMOLIR].spriteHauteur = 35;
    simcity->toolBox.tabSpriteToolBox[TOOLBOX_DEMOLIR].spriteX = 196;
    simcity->toolBox.tabSpriteToolBox[TOOLBOX_DEMOLIR].spriteY = 14;
    simcity->toolBox.tabSpriteToolBox[TOOLBOX_DEMOLIR].screenX = 15;
    simcity->toolBox.tabSpriteToolBox[TOOLBOX_DEMOLIR].screenY = 115;

    simcity->toolBox.tabSpriteToolBox[TOOLBOX_POMPIERS].image = &simcity->tabBitmap[BITMAP_TOOLBOX];
    simcity->toolBox.tabSpriteToolBox[TOOLBOX_POMPIERS].spriteLargeur = 35;
    simcity->toolBox.tabSpriteToolBox[TOOLBOX_POMPIERS].spriteHauteur = 35;
    simcity->toolBox.tabSpriteToolBox[TOOLBOX_POMPIERS].spriteX = 338;
    simcity->toolBox.tabSpriteToolBox[TOOLBOX_POMPIERS].spriteY = 14;
    simcity->toolBox.tabSpriteToolBox[TOOLBOX_POMPIERS].screenX = 65;
    simcity->toolBox.tabSpriteToolBox[TOOLBOX_POMPIERS].screenY = 115;


    simcity->toolBox.tabSpriteToolBox[TOOLBOX_NIVEAU1].image = &simcity->tabBitmap[BITMAP_TOOLBOX];
    simcity->toolBox.tabSpriteToolBox[TOOLBOX_NIVEAU1].spriteLargeur = 35;
    simcity->toolBox.tabSpriteToolBox[TOOLBOX_NIVEAU1].spriteHauteur = 35;
    simcity->toolBox.tabSpriteToolBox[TOOLBOX_NIVEAU1].spriteX = 241;
    simcity->toolBox.tabSpriteToolBox[TOOLBOX_NIVEAU1].spriteY = 14;
    simcity->toolBox.tabSpriteToolBox[TOOLBOX_NIVEAU1].screenX = 15;
    simcity->toolBox.tabSpriteToolBox[TOOLBOX_NIVEAU1].screenY = 165;

    simcity->toolBox.tabSpriteToolBox[TOOLBOX_NIVEAU2].image = &simcity->tabBitmap[BITMAP_TOOLBOX];
    simcity->toolBox.tabSpriteToolBox[TOOLBOX_NIVEAU2].spriteLargeur = 35;
    simcity->toolBox.tabSpriteToolBox[TOOLBOX_NIVEAU2].spriteHauteur = 35;
    simcity->toolBox.tabSpriteToolBox[TOOLBOX_NIVEAU2].spriteX = 292;
    simcity->toolBox.tabSpriteToolBox[TOOLBOX_NIVEAU2].spriteY = 14;
    simcity->toolBox.tabSpriteToolBox[TOOLBOX_NIVEAU2].screenX = 65;
    simcity->toolBox.tabSpriteToolBox[TOOLBOX_NIVEAU2].screenY = 165;





}


void bitmapSpriteInit(Simcity* simcity){

    simcity->map.spriteTile[HERBE].image = &simcity->tabBitmap[BITMAP_MAP];
    simcity->map.spriteTile[HERBE].spriteLargeur = 20;
    simcity->map.spriteTile[HERBE].spriteHauteur = 20;
    simcity->map.spriteTile[HERBE].spriteX = 32;
    simcity->map.spriteTile[HERBE].spriteY = 3;

    simcity->map.spriteTile[HOVER_TILE].image = &simcity->tabBitmap[BITMAP_MAP];
    simcity->map.spriteTile[HOVER_TILE].spriteLargeur = 20;
    simcity->map.spriteTile[HOVER_TILE].spriteHauteur = 20;
    simcity->map.spriteTile[HOVER_TILE].spriteX = 4;
    simcity->map.spriteTile[HOVER_TILE].spriteY = 3;

    simcity->map.spriteTile[TERRAIN_VAGUE].image = &simcity->tabBitmap[BITMAP_MAP];
    simcity->map.spriteTile[TERRAIN_VAGUE].spriteLargeur = 60;
    simcity->map.spriteTile[TERRAIN_VAGUE].spriteHauteur = 60;
    simcity->map.spriteTile[TERRAIN_VAGUE].spriteX = 135;
    simcity->map.spriteTile[TERRAIN_VAGUE].spriteY = 3;

    simcity->map.spriteTile[CABANE].image = &simcity->tabBitmap[BITMAP_MAP];
    simcity->map.spriteTile[CABANE].spriteLargeur = 60;
    simcity->map.spriteTile[CABANE].spriteHauteur = 60;
    simcity->map.spriteTile[CABANE].spriteX = 0;
    simcity->map.spriteTile[CABANE].spriteY = 0;

    simcity->map.spriteTile[MAISON].image = &simcity->tabBitmap[BITMAP_MAP];
    simcity->map.spriteTile[MAISON].spriteLargeur = 60;
    simcity->map.spriteTile[MAISON].spriteHauteur = 60;
    simcity->map.spriteTile[MAISON].spriteX = 59;
    simcity->map.spriteTile[MAISON].spriteY = 3;

    simcity->map.spriteTile[IMMEUBLE].image = &simcity->tabBitmap[BITMAP_MAP];
    simcity->map.spriteTile[IMMEUBLE].spriteLargeur = 60;
    simcity->map.spriteTile[IMMEUBLE].spriteHauteur = 60;
    simcity->map.spriteTile[IMMEUBLE].spriteX = 0;
    simcity->map.spriteTile[IMMEUBLE].spriteY = 0;

    simcity->map.spriteTile[GRATTE_CIEL].image = &simcity->tabBitmap[BITMAP_MAP];
    simcity->map.spriteTile[GRATTE_CIEL].spriteLargeur = 60;
    simcity->map.spriteTile[GRATTE_CIEL].spriteHauteur = 60;
    simcity->map.spriteTile[GRATTE_CIEL].spriteX = 0;
    simcity->map.spriteTile[GRATTE_CIEL].spriteY = 0;

    simcity->map.spriteTile[ROUTE].image = &simcity->tabBitmap[BITMAP_MAP];
    simcity->map.spriteTile[ROUTE].spriteLargeur = 20;
    simcity->map.spriteTile[ROUTE].spriteHauteur = 20;
    simcity->map.spriteTile[ROUTE].spriteX = 5;
    simcity->map.spriteTile[ROUTE].spriteY = 30;
}

void calculPositionSourisEnCelluleXY(Simcity* simcity) {
    for (int x = 0; x < NBCELLULEX; ++x) {
        for (int y = 0; y < NBCELLULEY; ++y) {
            if (simcity->allegro.coordonneesSourisX >= simcity->map.mapTile[x][y].coordsXY.screenX && simcity->allegro.coordonneesSourisX <= simcity->map.mapTile[x][y].coordsXY.screenX + simcity->map.mapTile[x][y].spriteLargeur){
                simcity->interactionExterieure.mouse.celluleXY.celluleX = x;
            }
            if (simcity->allegro.coordonneesSourisY >= simcity->map.mapTile[x][y].coordsXY.screenY && simcity->allegro.coordonneesSourisY <= simcity->map.mapTile[x][y].coordsXY.screenY + simcity->map.mapTile[x][y].spriteHauteur){
                simcity->interactionExterieure.mouse.celluleXY.celluleY = y;
            }
        }
    }
    if(simcity->allegro.event.mouse.button == 1 ){
        printf("x = %d, y = %d \n", simcity->interactionExterieure.mouse.celluleXY.celluleX, simcity->interactionExterieure.mouse.celluleXY.celluleY);
    }
}

void outOfBorder(Simcity* simcity){
    if(simcity->allegro.coordonneesSourisX >= 111 && simcity->allegro.coordonneesSourisX <= 1011 && simcity->allegro.coordonneesSourisY <= 700 && simcity->allegro.coordonneesSourisY > 0){
        simcity->outOfBorder = 1; // souris sur la map
    }else{
        simcity->outOfBorder = 0; // souris en dehors de la map
    }
}

void afficherToolbox (Simcity* simcity){
    al_draw_bitmap_region(*(simcity->toolBox.tabSpriteToolBox[TOOLBOX_FOND_GRIS].image), simcity->toolBox.tabSpriteToolBox[TOOLBOX_FOND_GRIS].spriteX, simcity->toolBox.tabSpriteToolBox[TOOLBOX_FOND_GRIS].spriteY, simcity->toolBox.tabSpriteToolBox[TOOLBOX_FOND_GRIS].spriteLargeur, simcity->toolBox.tabSpriteToolBox[TOOLBOX_FOND_GRIS].spriteHauteur, simcity->toolBox.tabSpriteToolBox[TOOLBOX_FOND_GRIS].screenX, simcity->toolBox.tabSpriteToolBox[TOOLBOX_FOND_GRIS].screenY, 0);
    al_draw_bitmap_region(*(simcity->toolBox.tabSpriteToolBox[TOOLBOX_ROUTE].image), simcity->toolBox.tabSpriteToolBox[TOOLBOX_ROUTE].spriteX, simcity->toolBox.tabSpriteToolBox[TOOLBOX_ROUTE].spriteY, simcity->toolBox.tabSpriteToolBox[TOOLBOX_ROUTE].spriteLargeur, simcity->toolBox.tabSpriteToolBox[TOOLBOX_ROUTE].spriteHauteur, simcity->toolBox.tabSpriteToolBox[TOOLBOX_ROUTE].screenX, simcity->toolBox.tabSpriteToolBox[TOOLBOX_ROUTE].screenY, 0);
    al_draw_bitmap_region(*(simcity->toolBox.tabSpriteToolBox[TOOLBOX_MAISON].image), simcity->toolBox.tabSpriteToolBox[TOOLBOX_MAISON].spriteX, simcity->toolBox.tabSpriteToolBox[TOOLBOX_MAISON].spriteY, simcity->toolBox.tabSpriteToolBox[TOOLBOX_MAISON].spriteLargeur, simcity->toolBox.tabSpriteToolBox[TOOLBOX_MAISON].spriteHauteur, simcity->toolBox.tabSpriteToolBox[TOOLBOX_MAISON].screenX, simcity->toolBox.tabSpriteToolBox[TOOLBOX_MAISON].screenY, 0);
    al_draw_bitmap_region(*(simcity->toolBox.tabSpriteToolBox[TOOLBOX_ELEC].image), simcity->toolBox.tabSpriteToolBox[TOOLBOX_ELEC].spriteX, simcity->toolBox.tabSpriteToolBox[TOOLBOX_ELEC].spriteY, simcity->toolBox.tabSpriteToolBox[TOOLBOX_ELEC].spriteLargeur, simcity->toolBox.tabSpriteToolBox[TOOLBOX_ELEC].spriteHauteur, simcity->toolBox.tabSpriteToolBox[TOOLBOX_ELEC].screenX, simcity->toolBox.tabSpriteToolBox[TOOLBOX_ELEC].screenY, 0);
    al_draw_bitmap_region(*(simcity->toolBox.tabSpriteToolBox[TOOLBOX_EAU].image), simcity->toolBox.tabSpriteToolBox[TOOLBOX_EAU].spriteX, simcity->toolBox.tabSpriteToolBox[TOOLBOX_EAU].spriteY, simcity->toolBox.tabSpriteToolBox[TOOLBOX_EAU].spriteLargeur, simcity->toolBox.tabSpriteToolBox[TOOLBOX_EAU].spriteHauteur, simcity->toolBox.tabSpriteToolBox[TOOLBOX_EAU].screenX, simcity->toolBox.tabSpriteToolBox[TOOLBOX_EAU].screenY, 0);
    al_draw_bitmap_region(*(simcity->toolBox.tabSpriteToolBox[TOOLBOX_DEMOLIR].image), simcity->toolBox.tabSpriteToolBox[TOOLBOX_DEMOLIR].spriteX, simcity->toolBox.tabSpriteToolBox[TOOLBOX_DEMOLIR].spriteY, simcity->toolBox.tabSpriteToolBox[TOOLBOX_DEMOLIR].spriteLargeur, simcity->toolBox.tabSpriteToolBox[TOOLBOX_DEMOLIR].spriteHauteur, simcity->toolBox.tabSpriteToolBox[TOOLBOX_DEMOLIR].screenX, simcity->toolBox.tabSpriteToolBox[TOOLBOX_DEMOLIR].screenY, 0);
    al_draw_bitmap_region(*(simcity->toolBox.tabSpriteToolBox[TOOLBOX_POMPIERS].image), simcity->toolBox.tabSpriteToolBox[TOOLBOX_POMPIERS].spriteX, simcity->toolBox.tabSpriteToolBox[TOOLBOX_POMPIERS].spriteY, simcity->toolBox.tabSpriteToolBox[TOOLBOX_POMPIERS].spriteLargeur, simcity->toolBox.tabSpriteToolBox[TOOLBOX_POMPIERS].spriteHauteur, simcity->toolBox.tabSpriteToolBox[TOOLBOX_POMPIERS].screenX, simcity->toolBox.tabSpriteToolBox[TOOLBOX_POMPIERS].screenY, 0);
    al_draw_bitmap_region(*(simcity->toolBox.tabSpriteToolBox[TOOLBOX_NIVEAU1].image), simcity->toolBox.tabSpriteToolBox[TOOLBOX_NIVEAU1].spriteX, simcity->toolBox.tabSpriteToolBox[TOOLBOX_NIVEAU1].spriteY, simcity->toolBox.tabSpriteToolBox[TOOLBOX_NIVEAU1].spriteLargeur, simcity->toolBox.tabSpriteToolBox[TOOLBOX_NIVEAU1].spriteHauteur, simcity->toolBox.tabSpriteToolBox[TOOLBOX_NIVEAU1].screenX, simcity->toolBox.tabSpriteToolBox[TOOLBOX_NIVEAU1].screenY, 0);
    al_draw_bitmap_region(*(simcity->toolBox.tabSpriteToolBox[TOOLBOX_NIVEAU2].image), simcity->toolBox.tabSpriteToolBox[TOOLBOX_NIVEAU2].spriteX, simcity->toolBox.tabSpriteToolBox[TOOLBOX_NIVEAU2].spriteY, simcity->toolBox.tabSpriteToolBox[TOOLBOX_NIVEAU2].spriteLargeur, simcity->toolBox.tabSpriteToolBox[TOOLBOX_NIVEAU2].spriteHauteur, simcity->toolBox.tabSpriteToolBox[TOOLBOX_NIVEAU2].screenX, simcity->toolBox.tabSpriteToolBox[TOOLBOX_NIVEAU2].screenY, 0);

}

void afficherMap(Simcity* simcity){
    al_clear_to_color(al_map_rgb(0,0,0));
    afficherToolbox(simcity);
    for (int x = 0; x < NBCELLULEX; ++x) {
        for (int y = 0; y < NBCELLULEY; ++y) {
            if (simcity->map.mapTile[x][y].typeBloc == 0){
                al_draw_bitmap_region(*(simcity->map.spriteTile[HERBE].image), simcity->map.spriteTile[HERBE].spriteX, simcity->map.spriteTile[HERBE].spriteY, simcity->map.spriteTile[HERBE].spriteLargeur, simcity->map.spriteTile[HERBE].spriteHauteur,simcity->map.mapTile[x][y].coordsXY.screenX,simcity->map.mapTile[x][y].coordsXY.screenY,0);
            }
            else if (simcity->map.mapTile[x][y].typeBloc == 1){
                al_draw_bitmap_region(*(simcity->map.spriteTile[TERRAIN_VAGUE].image), simcity->map.spriteTile[TERRAIN_VAGUE].spriteX, simcity->map.spriteTile[TERRAIN_VAGUE].spriteY, simcity->map.spriteTile[TERRAIN_VAGUE].spriteLargeur, simcity->map.spriteTile[TERRAIN_VAGUE].spriteHauteur,simcity->map.mapTile[x][y].coordsXY.screenX,simcity->map.mapTile[x][y].coordsXY.screenY,0);
            }
            else if (simcity->map.mapTile[x][y].typeBloc == 2){
                al_draw_bitmap_region(*(simcity->map.spriteTile[CABANE].image), simcity->map.spriteTile[CABANE].spriteX, simcity->map.spriteTile[CABANE].spriteY, simcity->map.spriteTile[CABANE].spriteLargeur, simcity->map.spriteTile[CABANE].spriteHauteur,simcity->map.mapTile[x][y].coordsXY.screenX,simcity->map.mapTile[x][y].coordsXY.screenY,0);
            }
            else if (simcity->map.mapTile[x][y].typeBloc == 3){
                al_draw_bitmap_region(*(simcity->map.spriteTile[MAISON].image), simcity->map.spriteTile[MAISON].spriteX, simcity->map.spriteTile[MAISON].spriteY, simcity->map.spriteTile[MAISON].spriteLargeur, simcity->map.spriteTile[MAISON].spriteHauteur,simcity->map.mapTile[x][y].coordsXY.screenX,simcity->map.mapTile[x][y].coordsXY.screenY,0);
            }
            else if (simcity->map.mapTile[x][y].typeBloc == 4){
                al_draw_bitmap_region(*(simcity->map.spriteTile[IMMEUBLE].image), simcity->map.spriteTile[IMMEUBLE].spriteX, simcity->map.spriteTile[IMMEUBLE].spriteY, simcity->map.spriteTile[IMMEUBLE].spriteLargeur, simcity->map.spriteTile[IMMEUBLE].spriteHauteur,simcity->map.mapTile[x][y].coordsXY.screenX,simcity->map.mapTile[x][y].coordsXY.screenY,0);
            }
            else if (simcity->map.mapTile[x][y].typeBloc == 5){
                al_draw_bitmap_region(*(simcity->map.spriteTile[GRATTE_CIEL].image), simcity->map.spriteTile[GRATTE_CIEL].spriteX, simcity->map.spriteTile[GRATTE_CIEL].spriteY, simcity->map.spriteTile[GRATTE_CIEL].spriteLargeur, simcity->map.spriteTile[GRATTE_CIEL].spriteHauteur,simcity->map.mapTile[x][y].coordsXY.screenX,simcity->map.mapTile[x][y].coordsXY.screenY,0);
            }
            else if (simcity->map.mapTile[x][y].typeBloc == 6){
                al_draw_bitmap_region(*(simcity->map.spriteTile[ROUTE].image), simcity->map.spriteTile[ROUTE].spriteX, simcity->map.spriteTile[ROUTE].spriteY, simcity->map.spriteTile[ROUTE].spriteLargeur, simcity->map.spriteTile[ROUTE].spriteHauteur,simcity->map.mapTile[x][y].coordsXY.screenX,simcity->map.mapTile[x][y].coordsXY.screenY,0);
            }
        }
    }
}

void afficherHoverMap(Simcity* simcity){
    for (int x = 0; x < NBCELLULEX ; ++x) {
        for (int y = 0; y < NBCELLULEY; ++y) {
            if (simcity->interactionExterieure.mouse.celluleXY.celluleX == simcity->map.mapTile[x][y].coordsXY.celluleX && simcity->interactionExterieure.mouse.celluleXY.celluleY == simcity->map.mapTile[x][y].coordsXY.celluleY){
                al_draw_bitmap_region(*(simcity->map.spriteTile[HOVER_TILE].image), simcity->map.spriteTile[HOVER_TILE].spriteX, simcity->map.spriteTile[HOVER_TILE].spriteY, simcity->map.spriteTile[HOVER_TILE].spriteLargeur, simcity->map.spriteTile[HOVER_TILE].spriteHauteur,simcity->map.mapTile[x][y].coordsXY.screenX,simcity->map.mapTile[x][y].coordsXY.screenY,0);
            }
        }
    }
}


// permet de savoir si on peut placer un terrain vague
int isTerrainVaguePossible(Simcity* simcity){
    if (simcity->toolBox.terrainVagueEnMain == 1 && simcity->outOfBorder && simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][simcity->interactionExterieure.mouse.celluleXY.celluleY].typeBloc == 0){
        for (int x = simcity->interactionExterieure.mouse.celluleXY.celluleX; x < simcity->interactionExterieure.mouse.celluleXY.celluleX + 3; ++x) {
            for (int y = simcity->interactionExterieure.mouse.celluleXY.celluleY; y < simcity->interactionExterieure.mouse.celluleXY.celluleY + 3; ++y) {
                if (simcity->map.mapTile[x][y].typeBloc != 0 || x > NBCELLULEX || y > NBCELLULEY){
                    return 0;
                }
            }
        }
        return 1;
    }
    return 0;
}

void poserTerrainVague(Simcity* simcity){
    if (simcity->allegro.event.mouse.button == 1 && isTerrainVaguePossible(simcity)){
        simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][simcity->interactionExterieure.mouse.celluleXY.celluleY].typeBloc = 1;
        for (int x = simcity->interactionExterieure.mouse.celluleXY.celluleX; x < simcity->interactionExterieure.mouse.celluleXY.celluleX + 3; ++x) {
            for (int y = simcity->interactionExterieure.mouse.celluleXY.celluleY; y < simcity->interactionExterieure.mouse.celluleXY.celluleY + 3; ++y) {
                if (simcity->interactionExterieure.mouse.celluleXY.celluleX == x && simcity->interactionExterieure.mouse.celluleXY.celluleY == y){
                    simcity->map.mapTile[x][y].typeBloc = 1;
                }else{
                    simcity->map.mapTile[x][y].typeBloc = -1; // permet de ne pas faire bug l'affchage des maisons
                }
            }
        }
    }

}

int isRoutePossible(Simcity* simcity){
    if (simcity->toolBox.routeEnMain == 1 && simcity->outOfBorder && simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][simcity->interactionExterieure.mouse.celluleXY.celluleY].typeBloc == 0){
        return 1;
    }
    return 0;
}

void poserRoute(Simcity* simcity){
    if (simcity->allegro.event.mouse.button == 1 && isRoutePossible(simcity)){
        simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][simcity->interactionExterieure.mouse.celluleXY.celluleY].typeBloc = 6;
    }
}
/*
 * void afficherSortIop(Dofus* dofus){
    for (int i = 0; i < NB_SORTS_IOP; ++i) {
        al_draw_bitmap_region(dofus->tabBitmap[BITMAP_SORTS],dofus->tabSortsIop[i].spriteSorts[i].spriteX,dofus->tabSortsIop[i].spriteSorts[i].spriteY,dofus->tabSortsIop[i].spriteSorts[i].spriteLargeur,dofus->tabSortsIop[i].spriteSorts[i].spriteHauteur,dofus->tabSortsIop[i].spriteSorts[i].screenXFixe,dofus->tabSortsIop[i].spriteSorts[i].screenYFixe,0);
        if (dofus->tabSortsIop[i].sortSelectionne == true){
            al_draw_bitmap_region(dofus->tabBitmap[BITMAP_SORTS],dofus->tabSortsIop[i].spriteSorts[i].spriteX,dofus->tabSortsIop[i].spriteSorts[i].spriteY,dofus->tabSortsIop[i].spriteSorts[i].spriteLargeur,dofus->tabSortsIop[i].spriteSorts[i].spriteHauteur,dofus->tabSortsIop[i].spriteSorts[i].screenX,dofus->tabSortsIop[i].spriteSorts[i].screenY,0);

        }
    }
}
void afficherSortMouvIop(Dofus* dofus){
    for (int i = 0; i < NB_SORTS_IOP; ++i) {
        if (dofus->tabSortsIop[i].sortSelectionne == true) {
            dofus->tabSortsIop[i].spriteSorts[i].screenX = dofus->allegro.event.mouse.x - dofus->tabSortsIop[i].offSetX;
            dofus->tabSortsIop[i].spriteSorts[i].screenY = dofus->allegro.event.mouse.y - dofus->tabSortsIop[i].offSetY;
        }
    }
}

 void cliqueSortIop(Dofus* dofus){
    for (int i = 0; i < NB_SORTS_IOP; ++i) {
        if (dofus->tabSortsIop[i].sortSelectionne == true){
            dofus->tabSortsIop[i].sortSelectionne = false;
            dofus->sortEnMain = false;
            dofus->sortlance = true;
            dofus->tabSortsIop[i].sortLance = true;
            initPositionSortMouvIop(dofus);
            break; // permet de lancer le sort
        }
        if (dofus->sortEnMain == false) {
            if (dofus->tabSortsIop[i].sortSelectionne != true && dofus->allegro.event.mouse.x <= dofus->tabSortsIop[i].spriteSorts[i].screenXFixe + dofus->tabSortsIop[i].spriteSorts[i].spriteLargeur && dofus->allegro.event.mouse.x >= dofus->tabSortsIop[i].spriteSorts[i].screenXFixe && dofus->allegro.event.mouse.y <= dofus->tabSortsIop[i].spriteSorts[i].screenYFixe + dofus->tabSortsIop[i].spriteSorts[i].spriteHauteur && dofus->allegro.event.mouse.y >= dofus->tabSortsIop[i].spriteSorts[i].screenYFixe) {
                dofus->tabSortsIop[i].sortSelectionne = true;
                dofus->sortEnMain = true;
                dofus->tabSortsIop[i].offSetX = dofus->allegro.event.mouse.x - dofus->tabSortsIop[i].spriteSorts[i].screenX;
                dofus->tabSortsIop[i].offSetY = dofus->allegro.event.mouse.y - dofus->tabSortsIop[i].spriteSorts[i].screenY;
                break; // selectionne le sort cliquer et suit la souris
            }
        }
    }
}



 */
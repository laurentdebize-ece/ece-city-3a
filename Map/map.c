#include "map.h"
#include "../Structures/structures.h"
#include "../Timers/timers.h"
#include "../Banque/banque.h"
#include "../Batiments//batiments.h"

void initDataMap(Simcity* simcity){
    for (int x = 0; x < NBCELLULEX; ++x) {
        for (int y = 0; y < NBCELLULEY ; ++y) {
            simcity->map.mapTile[x][y].spriteLargeur = 20;
            simcity->map.mapTile[x][y].spriteHauteur = 20;
            simcity->map.mapTile[x][y].typeBloc = TYPE_HERBE;
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
    simcity->toolBox.tabSpriteToolBox[TOOLBOX].image = &simcity->tabBitmap[BITMAP_TOOLBOX];
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
    al_draw_bitmap(*(simcity->toolBox.tabSpriteToolBox[TOOLBOX].image),0,0,0);
}

void afficherBarreCompteurs (Simcity* simcity) {
    al_draw_bitmap(simcity->tabBitmap[BITMAP_BARRECOMPTEURS],95, 620, 0);
}

void afficherMap(Simcity* simcity){
    al_clear_to_color(al_map_rgb(0,0,0));
    afficherToolbox(simcity);
    afficherBarreCompteurs(simcity);
    afficherTimerDate(*simcity);
    afficherArgent(*simcity);
    afficherNbHabitantsTot(*simcity);
    for (int x = 0; x < NBCELLULEX; ++x) {
        for (int y = 0; y < NBCELLULEY; ++y) {
            if (simcity->map.mapTile[x][y].typeBloc == TYPE_HERBE){
                al_draw_bitmap_region(*(simcity->map.spriteTile[HERBE].image), simcity->map.spriteTile[HERBE].spriteX, simcity->map.spriteTile[HERBE].spriteY, simcity->map.spriteTile[HERBE].spriteLargeur, simcity->map.spriteTile[HERBE].spriteHauteur,simcity->map.mapTile[x][y].coordsXY.screenX,simcity->map.mapTile[x][y].coordsXY.screenY,0);
            }
            else if (simcity->map.mapTile[x][y].typeBloc == TYPE_TERRAIN_VAGUE){
                al_draw_bitmap_region(*(simcity->map.spriteTile[TERRAIN_VAGUE].image), simcity->map.spriteTile[TERRAIN_VAGUE].spriteX, simcity->map.spriteTile[TERRAIN_VAGUE].spriteY, simcity->map.spriteTile[TERRAIN_VAGUE].spriteLargeur, simcity->map.spriteTile[TERRAIN_VAGUE].spriteHauteur,simcity->map.mapTile[x][y].coordsXY.screenX,simcity->map.mapTile[x][y].coordsXY.screenY,0);
            }
            else if (simcity->map.mapTile[x][y].typeBloc == TYPE_CABANE){
                al_draw_bitmap_region(*(simcity->map.spriteTile[CABANE].image), simcity->map.spriteTile[CABANE].spriteX, simcity->map.spriteTile[CABANE].spriteY, simcity->map.spriteTile[CABANE].spriteLargeur, simcity->map.spriteTile[CABANE].spriteHauteur,simcity->map.mapTile[x][y].coordsXY.screenX,simcity->map.mapTile[x][y].coordsXY.screenY,0);
            }
            else if (simcity->map.mapTile[x][y].typeBloc == TYPE_MAISON){
                al_draw_bitmap_region(*(simcity->map.spriteTile[MAISON].image), simcity->map.spriteTile[MAISON].spriteX, simcity->map.spriteTile[MAISON].spriteY, simcity->map.spriteTile[MAISON].spriteLargeur, simcity->map.spriteTile[MAISON].spriteHauteur,simcity->map.mapTile[x][y].coordsXY.screenX,simcity->map.mapTile[x][y].coordsXY.screenY,0);
            }
            else if (simcity->map.mapTile[x][y].typeBloc == TYPE_IMMEUBLE){
                al_draw_bitmap_region(*(simcity->map.spriteTile[IMMEUBLE].image), simcity->map.spriteTile[IMMEUBLE].spriteX, simcity->map.spriteTile[IMMEUBLE].spriteY, simcity->map.spriteTile[IMMEUBLE].spriteLargeur, simcity->map.spriteTile[IMMEUBLE].spriteHauteur,simcity->map.mapTile[x][y].coordsXY.screenX,simcity->map.mapTile[x][y].coordsXY.screenY,0);
            }
            else if (simcity->map.mapTile[x][y].typeBloc == TYPE_GRATTE_CIEL){
                al_draw_bitmap_region(*(simcity->map.spriteTile[GRATTE_CIEL].image), simcity->map.spriteTile[GRATTE_CIEL].spriteX, simcity->map.spriteTile[GRATTE_CIEL].spriteY, simcity->map.spriteTile[GRATTE_CIEL].spriteLargeur, simcity->map.spriteTile[GRATTE_CIEL].spriteHauteur,simcity->map.mapTile[x][y].coordsXY.screenX,simcity->map.mapTile[x][y].coordsXY.screenY,0);
            }
            else if (simcity->map.mapTile[x][y].typeBloc == TYPE_ROUTE){
                al_draw_bitmap_region(*(simcity->map.spriteTile[ROUTE].image), simcity->map.spriteTile[ROUTE].spriteX, simcity->map.spriteTile[ROUTE].spriteY, simcity->map.spriteTile[ROUTE].spriteLargeur, simcity->map.spriteTile[ROUTE].spriteHauteur,simcity->map.mapTile[x][y].coordsXY.screenX,simcity->map.mapTile[x][y].coordsXY.screenY,0);
            }
        }
    }
    afficherPrevisionRoute(simcity);
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
    if (simcity->toolBox.terrainVagueEnMain == 1 && simcity->outOfBorder && simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][simcity->interactionExterieure.mouse.celluleXY.celluleY].typeBloc == TYPE_HERBE){
        for (int x = simcity->interactionExterieure.mouse.celluleXY.celluleX; x < simcity->interactionExterieure.mouse.celluleXY.celluleX + 3; ++x) {
            for (int y = simcity->interactionExterieure.mouse.celluleXY.celluleY; y < simcity->interactionExterieure.mouse.celluleXY.celluleY + 3; ++y) {
                if (simcity->map.mapTile[x][y].typeBloc != TYPE_HERBE || x > NBCELLULEX || y >= NBCELLULEY){
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
        simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][simcity->interactionExterieure.mouse.celluleXY.celluleY].typeBloc = TYPE_TERRAIN_VAGUE;
        for (int x = simcity->interactionExterieure.mouse.celluleXY.celluleX; x < simcity->interactionExterieure.mouse.celluleXY.celluleX + 3; ++x) {
            for (int y = simcity->interactionExterieure.mouse.celluleXY.celluleY; y < simcity->interactionExterieure.mouse.celluleXY.celluleY + 3; ++y) {
                if (simcity->interactionExterieure.mouse.celluleXY.celluleX == x && simcity->interactionExterieure.mouse.celluleXY.celluleY == y){
                    simcity->map.mapTile[x][y].typeBloc = TYPE_TERRAIN_VAGUE;
                }else{
                    simcity->map.mapTile[x][y].typeBloc = -1; // permet de ne pas faire bug l'affchage des maisons
                }
            }
        }
    }

}

int isRoutePossible(Simcity* simcity){
    if (simcity->toolBox.routeEnMain == 1 && simcity->outOfBorder && simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][simcity->interactionExterieure.mouse.celluleXY.celluleY].typeBloc == TYPE_HERBE){
        return 1;
    }
    return 0;
}

void nbBlocRouteX(Simcity* simcity){
    simcity->map.compteurCheminsX = simcity->map.creationRouteX - simcity->interactionExterieure.mouse.celluleXY.celluleX;
    if (simcity->map.compteurCheminsX < 0){
        simcity->map.compteurCheminsX = -simcity->map.compteurCheminsX;
    }
}

void nbBlocRouteY(Simcity* simcity){
    simcity->map.compteurCheminsY = simcity->map.creationRouteY - simcity->interactionExterieure.mouse.celluleXY.celluleY;
    if (simcity->map.compteurCheminsY < 0){
        simcity->map.compteurCheminsY = -simcity->map.compteurCheminsY;
    }
}

int routePossibleChemin(Simcity* simcity){
    nbBlocRouteX(simcity);
    nbBlocRouteY(simcity);
    for (int x = 0; x < simcity->map.compteurCheminsX; ++x) {
        for (int y = 0; y < simcity->map.compteurCheminsY; ++y) {
            if (simcity->map.mapTile[x][y].typeBloc != TYPE_HERBE){
                return 0;
            }
        }
    }
    return 1;
}

void afficherPrevisionRoute(Simcity* simcity) {
    if (routePossibleChemin(simcity)) {
        if (simcity->map.creationRouteX < simcity->interactionExterieure.mouse.celluleXY.celluleX &&
            simcity->map.creationRouteY < simcity->interactionExterieure.mouse.celluleXY.celluleY){
            for (int x = simcity->map.creationRouteX; x <= simcity->map.creationRouteX + simcity->map.compteurCheminsX; ++x) {
                al_draw_bitmap_region(*(simcity->map.spriteTile[ROUTE].image), simcity->map.spriteTile[ROUTE].spriteX,
                                      simcity->map.spriteTile[ROUTE].spriteY, simcity->map.spriteTile[ROUTE].spriteLargeur,
                                      simcity->map.spriteTile[ROUTE].spriteHauteur,
                                      simcity->map.mapTile[x][simcity->interactionExterieure.mouse.celluleXY.celluleY - simcity->map.compteurCheminsY].coordsXY.screenX,
                                      simcity->map.mapTile[x][simcity->interactionExterieure.mouse.celluleXY.celluleY - simcity->map.compteurCheminsY].coordsXY.screenY,
                                      0);
            }
            for (int y = simcity->map.creationRouteY; y <= simcity->map.creationRouteY + simcity->map.compteurCheminsY; ++y) {
                al_draw_bitmap_region(*(simcity->map.spriteTile[ROUTE].image), simcity->map.spriteTile[ROUTE].spriteX,
                                      simcity->map.spriteTile[ROUTE].spriteY, simcity->map.spriteTile[ROUTE].spriteLargeur,
                                      simcity->map.spriteTile[ROUTE].spriteHauteur,
                                      simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][y].coordsXY.screenX,
                                      simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][y].coordsXY.screenY,
                                      0);
            }
        }else if (simcity->map.creationRouteX > simcity->interactionExterieure.mouse.celluleXY.celluleX &&
             simcity->map.creationRouteY < simcity->interactionExterieure.mouse.celluleXY.celluleY){
            for (int x = simcity->interactionExterieure.mouse.celluleXY.celluleX; x <= simcity->interactionExterieure.mouse.celluleXY.celluleX + simcity->map.compteurCheminsX; ++x) {
                al_draw_bitmap_region(*(simcity->map.spriteTile[ROUTE].image), simcity->map.spriteTile[ROUTE].spriteX,
                                      simcity->map.spriteTile[ROUTE].spriteY, simcity->map.spriteTile[ROUTE].spriteLargeur,
                                      simcity->map.spriteTile[ROUTE].spriteHauteur,
                                      simcity->map.mapTile[x][simcity->interactionExterieure.mouse.celluleXY.celluleY - simcity->map.compteurCheminsY].coordsXY.screenX,
                                      simcity->map.mapTile[x][simcity->interactionExterieure.mouse.celluleXY.celluleY - simcity->map.compteurCheminsY].coordsXY.screenY,
                                      0);
            }
            for (int y = simcity->map.creationRouteY; y <= simcity->map.creationRouteY + simcity->map.compteurCheminsY; ++y) {
                al_draw_bitmap_region(*(simcity->map.spriteTile[ROUTE].image), simcity->map.spriteTile[ROUTE].spriteX,
                                      simcity->map.spriteTile[ROUTE].spriteY, simcity->map.spriteTile[ROUTE].spriteLargeur,
                                      simcity->map.spriteTile[ROUTE].spriteHauteur,
                                      simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][y].coordsXY.screenX,
                                      simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][y].coordsXY.screenY,
                                      0);
            }
        }else if (simcity->map.creationRouteX > simcity->interactionExterieure.mouse.celluleXY.celluleX &&
                      simcity->map.creationRouteY > simcity->interactionExterieure.mouse.celluleXY.celluleY){
                for (int x = simcity->interactionExterieure.mouse.celluleXY.celluleX; x <= simcity->interactionExterieure.mouse.celluleXY.celluleX + simcity->map.compteurCheminsX; ++x) {
                    al_draw_bitmap_region(*(simcity->map.spriteTile[ROUTE].image), simcity->map.spriteTile[ROUTE].spriteX,
                                          simcity->map.spriteTile[ROUTE].spriteY, simcity->map.spriteTile[ROUTE].spriteLargeur,
                                          simcity->map.spriteTile[ROUTE].spriteHauteur,
                                          simcity->map.mapTile[x][simcity->interactionExterieure.mouse.celluleXY.celluleY + simcity->map.compteurCheminsY].coordsXY.screenX,
                                          simcity->map.mapTile[x][simcity->interactionExterieure.mouse.celluleXY.celluleY + simcity->map.compteurCheminsY].coordsXY.screenY,
                                          0);
                }
                for (int y = simcity->interactionExterieure.mouse.celluleXY.celluleY; y <= simcity->interactionExterieure.mouse.celluleXY.celluleY + simcity->map.compteurCheminsY; ++y) {
                    al_draw_bitmap_region(*(simcity->map.spriteTile[ROUTE].image), simcity->map.spriteTile[ROUTE].spriteX,
                                          simcity->map.spriteTile[ROUTE].spriteY, simcity->map.spriteTile[ROUTE].spriteLargeur,
                                          simcity->map.spriteTile[ROUTE].spriteHauteur,
                                          simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][y].coordsXY.screenX,
                                          simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][y].coordsXY.screenY,
                                          0);
                }
        }else if (simcity->map.creationRouteX < simcity->interactionExterieure.mouse.celluleXY.celluleX &&
                  simcity->map.creationRouteY > simcity->interactionExterieure.mouse.celluleXY.celluleY){
            for (int x = simcity->map.creationRouteX; x <= simcity->map.creationRouteX + simcity->map.compteurCheminsX; ++x) {
                al_draw_bitmap_region(*(simcity->map.spriteTile[ROUTE].image), simcity->map.spriteTile[ROUTE].spriteX,
                                      simcity->map.spriteTile[ROUTE].spriteY, simcity->map.spriteTile[ROUTE].spriteLargeur,
                                      simcity->map.spriteTile[ROUTE].spriteHauteur,
                                      simcity->map.mapTile[x][simcity->interactionExterieure.mouse.celluleXY.celluleY + simcity->map.compteurCheminsY].coordsXY.screenX,
                                      simcity->map.mapTile[x][simcity->interactionExterieure.mouse.celluleXY.celluleY + simcity->map.compteurCheminsY].coordsXY.screenY,
                                      0);
            }
            for (int y = simcity->interactionExterieure.mouse.celluleXY.celluleY; y <= simcity->interactionExterieure.mouse.celluleXY.celluleY + simcity->map.compteurCheminsY; ++y) {
                al_draw_bitmap_region(*(simcity->map.spriteTile[ROUTE].image), simcity->map.spriteTile[ROUTE].spriteX,
                                      simcity->map.spriteTile[ROUTE].spriteY, simcity->map.spriteTile[ROUTE].spriteLargeur,
                                      simcity->map.spriteTile[ROUTE].spriteHauteur,
                                      simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][y].coordsXY.screenX,
                                      simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][y].coordsXY.screenY,
                                      0);
            }
        }else if (simcity->map.creationRouteX < simcity->interactionExterieure.mouse.celluleXY.celluleX){
            for (int x = simcity->map.creationRouteX; x <= simcity->map.creationRouteX + simcity->map.compteurCheminsX; ++x) {
                al_draw_bitmap_region(*(simcity->map.spriteTile[ROUTE].image), simcity->map.spriteTile[ROUTE].spriteX,
                                      simcity->map.spriteTile[ROUTE].spriteY, simcity->map.spriteTile[ROUTE].spriteLargeur,
                                      simcity->map.spriteTile[ROUTE].spriteHauteur,
                                      simcity->map.mapTile[x][simcity->interactionExterieure.mouse.celluleXY.celluleY].coordsXY.screenX,
                                      simcity->map.mapTile[x][simcity->interactionExterieure.mouse.celluleXY.celluleY].coordsXY.screenY,
                                      0);
            }
        }else if (simcity->map.creationRouteX > simcity->interactionExterieure.mouse.celluleXY.celluleX){
            for (int x = simcity->interactionExterieure.mouse.celluleXY.celluleX; x <= simcity->interactionExterieure.mouse.celluleXY.celluleX + simcity->map.compteurCheminsX; ++x) {
                al_draw_bitmap_region(*(simcity->map.spriteTile[ROUTE].image), simcity->map.spriteTile[ROUTE].spriteX,
                                      simcity->map.spriteTile[ROUTE].spriteY, simcity->map.spriteTile[ROUTE].spriteLargeur,
                                      simcity->map.spriteTile[ROUTE].spriteHauteur,
                                      simcity->map.mapTile[x][simcity->interactionExterieure.mouse.celluleXY.celluleY].coordsXY.screenX,
                                      simcity->map.mapTile[x][simcity->interactionExterieure.mouse.celluleXY.celluleY].coordsXY.screenY,
                                      0);
            }
        }else if (simcity->map.creationRouteY > simcity->interactionExterieure.mouse.celluleXY.celluleY){
            for (int y = simcity->interactionExterieure.mouse.celluleXY.celluleY; y <= simcity->interactionExterieure.mouse.celluleXY.celluleY + simcity->map.compteurCheminsY; ++y) {
                al_draw_bitmap_region(*(simcity->map.spriteTile[ROUTE].image), simcity->map.spriteTile[ROUTE].spriteX,
                                      simcity->map.spriteTile[ROUTE].spriteY, simcity->map.spriteTile[ROUTE].spriteLargeur,
                                      simcity->map.spriteTile[ROUTE].spriteHauteur,
                                      simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][y].coordsXY.screenX,
                                      simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][y].coordsXY.screenY,
                                      0);
            }
        }else if (simcity->map.creationRouteY < simcity->interactionExterieure.mouse.celluleXY.celluleY){
            for (int y = simcity->map.creationRouteY; y <= simcity->map.creationRouteY + simcity->map.compteurCheminsY; ++y) {
                al_draw_bitmap_region(*(simcity->map.spriteTile[ROUTE].image), simcity->map.spriteTile[ROUTE].spriteX,
                                      simcity->map.spriteTile[ROUTE].spriteY, simcity->map.spriteTile[ROUTE].spriteLargeur,
                                      simcity->map.spriteTile[ROUTE].spriteHauteur,
                                      simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][y].coordsXY.screenX,
                                      simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][y].coordsXY.screenY,
                                      0);
            }
        }
    }
}

void poserRoute(Simcity *simcity){
    if (simcity->allegro.event.mouse.button == 1 && simcity->map.cliqueRoute) {
            if (routePossibleChemin(simcity)) {
                if (simcity->map.creationRouteX < simcity->interactionExterieure.mouse.celluleXY.celluleX && simcity->map.creationRouteY < simcity->interactionExterieure.mouse.celluleXY.celluleY) {
                    for (int x = simcity->map.creationRouteX; x <= simcity->map.creationRouteX + simcity->map.compteurCheminsX; ++x){
                        simcity->map.mapTile[x][simcity->interactionExterieure.mouse.celluleXY.celluleY - simcity->map.compteurCheminsY].typeBloc = TYPE_ROUTE;
                    }
                    for (int y = simcity->map.creationRouteY;y <= simcity->map.creationRouteY + simcity->map.compteurCheminsY; ++y) {
                        simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][y].typeBloc = TYPE_ROUTE;
                    }
                } else if (simcity->map.creationRouteX > simcity->interactionExterieure.mouse.celluleXY.celluleX && simcity->map.creationRouteY < simcity->interactionExterieure.mouse.celluleXY.celluleY) {
                    for (int x = simcity->interactionExterieure.mouse.celluleXY.celluleX; x <= simcity->interactionExterieure.mouse.celluleXY.celluleX + simcity->map.compteurCheminsX; ++x) {
                        simcity->map.mapTile[x][simcity->interactionExterieure.mouse.celluleXY.celluleY - simcity->map.compteurCheminsY].typeBloc = TYPE_ROUTE;
                    }
                    for (int y = simcity->map.creationRouteY; y <= simcity->map.creationRouteY + simcity->map.compteurCheminsY; ++y){
                        simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][y].typeBloc = TYPE_ROUTE;
                    }
                } else if (simcity->map.creationRouteX > simcity->interactionExterieure.mouse.celluleXY.celluleX && simcity->map.creationRouteY > simcity->interactionExterieure.mouse.celluleXY.celluleY) {
                    for (int x = simcity->interactionExterieure.mouse.celluleXY.celluleX; x <= simcity->interactionExterieure.mouse.celluleXY.celluleX + simcity->map.compteurCheminsX; ++x) {
                        simcity->map.mapTile[x][simcity->interactionExterieure.mouse.celluleXY.celluleY + simcity->map.compteurCheminsY].typeBloc = TYPE_ROUTE;
                    }
                    for (int y = simcity->interactionExterieure.mouse.celluleXY.celluleY; y <= simcity->interactionExterieure.mouse.celluleXY.celluleY + simcity->map.compteurCheminsY; ++y) {
                        simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][y].typeBloc = TYPE_ROUTE;
                    }
                } else if (simcity->map.creationRouteX < simcity->interactionExterieure.mouse.celluleXY.celluleX && simcity->map.creationRouteY > simcity->interactionExterieure.mouse.celluleXY.celluleY) {
                    for (int x = simcity->map.creationRouteX; x <= simcity->map.creationRouteX + simcity->map.compteurCheminsX; ++x) {
                        simcity->map.mapTile[x][simcity->interactionExterieure.mouse.celluleXY.celluleY + simcity->map.compteurCheminsY].typeBloc = TYPE_ROUTE;
                    }
                    for (int y = simcity->interactionExterieure.mouse.celluleXY.celluleY; y <= simcity->interactionExterieure.mouse.celluleXY.celluleY + simcity->map.compteurCheminsY; ++y) {
                        simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][y].typeBloc = TYPE_ROUTE;
                    }
                } else if (simcity->map.creationRouteX < simcity->interactionExterieure.mouse.celluleXY.celluleX) {
                    for (int x = simcity->map.creationRouteX; x <= simcity->map.creationRouteX + simcity->map.compteurCheminsX; ++x) { simcity->map.mapTile[x][simcity->interactionExterieure.mouse.celluleXY.celluleY].typeBloc = TYPE_ROUTE;
                    }
                } else if (simcity->map.creationRouteX > simcity->interactionExterieure.mouse.celluleXY.celluleX) {
                    for (int x = simcity->interactionExterieure.mouse.celluleXY.celluleX; x <= simcity->interactionExterieure.mouse.celluleXY.celluleX + simcity->map.compteurCheminsX; ++x) {
                        simcity->map.mapTile[x][simcity->interactionExterieure.mouse.celluleXY.celluleY].typeBloc = TYPE_ROUTE;
                    }
                } else if (simcity->map.creationRouteY < simcity->interactionExterieure.mouse.celluleXY.celluleY) {
                    for (int y = simcity->map.creationRouteY; y <= simcity->map.creationRouteY + simcity->map.compteurCheminsY; ++y) {
                        simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][y].typeBloc = TYPE_ROUTE;
                    }
                } else if (simcity->map.creationRouteY > simcity->interactionExterieure.mouse.celluleXY.celluleY) {
                    for (int y = simcity->interactionExterieure.mouse.celluleXY.celluleY; y <= simcity->interactionExterieure.mouse.celluleXY.celluleY + simcity->map.compteurCheminsY; ++y) {
                        simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][y].typeBloc = TYPE_ROUTE;
                    }
                }

                /*for (int y = simcity->map.creationRouteY; y <= simcity->map.creationRouteY + simcity->map.compteurCheminsY; ++y) {
                    simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][y].typeBloc = TYPE_ROUTE;
                }*/
            }
            simcity->map.cliqueRoute = 0;
        }

    if (simcity->allegro.event.mouse.button == 1 && isRoutePossible(simcity)) {
            simcity->map.creationRouteX = simcity->interactionExterieure.mouse.celluleXY.celluleX;
            simcity->map.creationRouteY = simcity->interactionExterieure.mouse.celluleXY.celluleY;
            simcity->map.cliqueRoute = 1;
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

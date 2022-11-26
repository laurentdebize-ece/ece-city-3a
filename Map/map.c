#include "map.h"
#include "../Timers/timers.h"
#include "../ToolBox/toolbox.h"

void initDataMap(Simcity* simcity){
    for (int x = 0; x < NBCELLULEX; ++x) {
        for (int y = 0; y < NBCELLULEY ; ++y) {
            simcity->map.mapTile[x][y].spriteLargeur = 20;
            simcity->map.mapTile[x][y].spriteHauteur = 20;
            simcity->map.mapTile[x][y].typeBloc = TYPE_HERBE;
            simcity->map.mapTile[x][y].coordsXY.screenX = 110 + 20 * (float)x;
            simcity->map.mapTile[x][y].coordsXY.screenY = 0 + 20 * (float)y;
            simcity->map.mapTile[x][y].coordsXY.celluleX = x;
            simcity->map.mapTile[x][y].coordsXY.celluleY = y;
            simcity->map.mapTile[x][y].typeElec = FALSE;
            simcity->map.mapTile[x][y].typeEau = FALSE;

        }
    }
    bitmapSpriteInit(simcity);
    toolboxSpriteInit(simcity);
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
    simcity->map.spriteTile[CABANE].spriteX = 135;
    simcity->map.spriteTile[CABANE].spriteY = 75;

    simcity->map.spriteTile[MAISON].image = &simcity->tabBitmap[BITMAP_MAP];
    simcity->map.spriteTile[MAISON].spriteLargeur = 60;
    simcity->map.spriteTile[MAISON].spriteHauteur = 60;
    simcity->map.spriteTile[MAISON].spriteX = 59;
    simcity->map.spriteTile[MAISON].spriteY = 3;

    simcity->map.spriteTile[IMMEUBLE].image = &simcity->tabBitmap[BITMAP_MAP];
    simcity->map.spriteTile[IMMEUBLE].spriteLargeur = 60;
    simcity->map.spriteTile[IMMEUBLE].spriteHauteur = 60;
    simcity->map.spriteTile[IMMEUBLE].spriteX = 59;
    simcity->map.spriteTile[IMMEUBLE].spriteY = 75;

    simcity->map.spriteTile[GRATTE_CIEL].image = &simcity->tabBitmap[BITMAP_MAP];
    simcity->map.spriteTile[GRATTE_CIEL].spriteLargeur = 60;
    simcity->map.spriteTile[GRATTE_CIEL].spriteHauteur = 60;
    simcity->map.spriteTile[GRATTE_CIEL].spriteX = 388;
    simcity->map.spriteTile[GRATTE_CIEL].spriteY = 147;

    simcity->map.spriteTile[ROUTE].image = &simcity->tabBitmap[BITMAP_MAP];
    simcity->map.spriteTile[ROUTE].spriteLargeur = 20;
    simcity->map.spriteTile[ROUTE].spriteHauteur = 20;
    simcity->map.spriteTile[ROUTE].spriteX = 5;
    simcity->map.spriteTile[ROUTE].spriteY = 30;

    simcity->map.spriteTile[ELEC_DROIT].image = &simcity->tabBitmap[BITMAP_MAP];
    simcity->map.spriteTile[ELEC_DROIT].spriteLargeur = 120;
    simcity->map.spriteTile[ELEC_DROIT].spriteHauteur = 80;
    simcity->map.spriteTile[ELEC_DROIT].spriteX = 5;
    simcity->map.spriteTile[ELEC_DROIT].spriteY = 147;

    simcity->map.spriteTile[ELEC_COTE].image = &simcity->tabBitmap[BITMAP_MAP];
    simcity->map.spriteTile[ELEC_COTE].spriteLargeur = 80;
    simcity->map.spriteTile[ELEC_COTE].spriteHauteur = 120;
    simcity->map.spriteTile[ELEC_COTE].spriteX = 202;
    simcity->map.spriteTile[ELEC_COTE].spriteY = 3;

    simcity->map.spriteTile[EAU_DROIT].image = &simcity->tabBitmap[BITMAP_MAP];
    simcity->map.spriteTile[EAU_DROIT].spriteLargeur = 120;
    simcity->map.spriteTile[EAU_DROIT].spriteHauteur = 80;
    simcity->map.spriteTile[EAU_DROIT].spriteX = 135;
    simcity->map.spriteTile[EAU_DROIT].spriteY = 147;

    simcity->map.spriteTile[EAU_COTE].image = &simcity->tabBitmap[BITMAP_MAP];
    simcity->map.spriteTile[EAU_COTE].spriteLargeur = 80;
    simcity->map.spriteTile[EAU_COTE].spriteHauteur = 120;
    simcity->map.spriteTile[EAU_COTE].spriteX = 288;
    simcity->map.spriteTile[EAU_COTE].spriteY = 3;

    simcity->map.spriteTile[POMPIER_DROIT].image = &simcity->tabBitmap[BITMAP_MAP];
    simcity->map.spriteTile[POMPIER_DROIT].spriteLargeur = 120;
    simcity->map.spriteTile[POMPIER_DROIT].spriteHauteur = 80;
    simcity->map.spriteTile[POMPIER_DROIT].spriteX = 263;
    simcity->map.spriteTile[POMPIER_DROIT].spriteY = 147;

    simcity->map.spriteTile[POMPIER_COTE].image = &simcity->tabBitmap[BITMAP_MAP];
    simcity->map.spriteTile[POMPIER_COTE].spriteLargeur = 80;
    simcity->map.spriteTile[POMPIER_COTE].spriteHauteur = 120;
    simcity->map.spriteTile[POMPIER_COTE].spriteX = 375;
    simcity->map.spriteTile[POMPIER_COTE].spriteY = 3;

    simcity->map.spriteTile[EAU_RESEAU].image = &simcity->tabBitmap[BITMAP_MAP];
    simcity->map.spriteTile[EAU_RESEAU].spriteLargeur = 20;
    simcity->map.spriteTile[EAU_RESEAU].spriteHauteur = 20;
    simcity->map.spriteTile[EAU_RESEAU].spriteX = 4;
    simcity->map.spriteTile[EAU_RESEAU].spriteY = 58;

    simcity->map.spriteTile[ELEC_RESEAU].image = &simcity->tabBitmap[BITMAP_MAP];
    simcity->map.spriteTile[ELEC_RESEAU].spriteLargeur = 20;
    simcity->map.spriteTile[ELEC_RESEAU].spriteHauteur = 20;
    simcity->map.spriteTile[ELEC_RESEAU].spriteX = 32;
    simcity->map.spriteTile[ELEC_RESEAU].spriteY = 30;
}

void calculPositionSourisEnCelluleXY(Simcity* simcity) {
    for (int x = 0; x < NBCELLULEX; ++x) {
        for (int y = 0; y < NBCELLULEY; ++y) {
            if ((float)simcity->allegro.coordonneesSourisX >= simcity->map.mapTile[x][y].coordsXY.screenX && (float)simcity->allegro.coordonneesSourisX <= simcity->map.mapTile[x][y].coordsXY.screenX + (float)simcity->map.mapTile[x][y].spriteLargeur){
                simcity->interactionExterieure.mouse.celluleXY.celluleX = x;
            }
            if ((float)simcity->allegro.coordonneesSourisY >= simcity->map.mapTile[x][y].coordsXY.screenY && (float)simcity->allegro.coordonneesSourisY <= simcity->map.mapTile[x][y].coordsXY.screenY + (float)simcity->map.mapTile[x][y].spriteHauteur){
                simcity->interactionExterieure.mouse.celluleXY.celluleY = y;
            }
        }
    }
}

void outOfBorder(Simcity* simcity){
    if(simcity->allegro.coordonneesSourisX >= 111 && simcity->allegro.coordonneesSourisX <= 1011 && simcity->allegro.coordonneesSourisY <= 700 && simcity->allegro.coordonneesSourisY > 0){
        simcity->outOfBorder = 1; // souris sur la map
    }else{
        simcity->outOfBorder = 0; // souris en dehors de la map
    }
}

void afficherBarreCompteurs (Simcity* simcity) {
    al_draw_bitmap(simcity->tabBitmap[BITMAP_BARRECOMPTEURS],95, 620, 0);
}

void afficherMap(Simcity* simcity){
    al_clear_to_color(al_map_rgb(0,0,0));
    afficherToolbox(simcity);
    afficherBarreCompteurs(simcity);
    afficherTimerDate(simcity);
    afficherArgent(simcity);
    afficherNbHabitantsTot(simcity);

    bool modeNiveauEau = simcity->toolBox.vue1EnMain;
    bool modeNiveauElectricite = simcity->toolBox.vue2EnMain;

    for (int x = 0; x < NBCELLULEX; ++x) {
        for (int y = 0; y < NBCELLULEY; ++y) {
            //permet de dessiner l'herbe de toute la map
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
            else if (simcity->map.mapTile[x][y].typeBloc == TYPE_ELEC_DROIT){
                al_draw_bitmap_region(*(simcity->map.spriteTile[ELEC_DROIT].image), simcity->map.spriteTile[ELEC_DROIT].spriteX, simcity->map.spriteTile[ELEC_DROIT].spriteY, simcity->map.spriteTile[ELEC_DROIT].spriteLargeur, simcity->map.spriteTile[ELEC_DROIT].spriteHauteur,simcity->map.mapTile[x][y].coordsXY.screenX, simcity->map.mapTile[x][y].coordsXY.screenY,0);
            }
            else if (simcity->map.mapTile[x][y].typeBloc == TYPE_ELEC_COTE){
                al_draw_bitmap_region(*(simcity->map.spriteTile[ELEC_COTE].image), simcity->map.spriteTile[ELEC_COTE].spriteX, simcity->map.spriteTile[ELEC_COTE].spriteY, simcity->map.spriteTile[ELEC_COTE].spriteLargeur, simcity->map.spriteTile[ELEC_COTE].spriteHauteur,simcity->map.mapTile[x][y].coordsXY.screenX,simcity->map.mapTile[x][y].coordsXY.screenY,0);
            }
            else if (simcity->map.mapTile[x][y].typeBloc == TYPE_EAU_DROIT){
                al_draw_bitmap_region(*(simcity->map.spriteTile[EAU_DROIT].image), simcity->map.spriteTile[EAU_DROIT].spriteX, simcity->map.spriteTile[EAU_DROIT].spriteY, simcity->map.spriteTile[EAU_DROIT].spriteLargeur, simcity->map.spriteTile[EAU_DROIT].spriteHauteur,simcity->map.mapTile[x][y].coordsXY.screenX,simcity->map.mapTile[x][y].coordsXY.screenY,0);
            }
            else if (simcity->map.mapTile[x][y].typeBloc == TYPE_EAU_COTE){
                al_draw_bitmap_region(*(simcity->map.spriteTile[EAU_COTE].image), simcity->map.spriteTile[EAU_COTE].spriteX, simcity->map.spriteTile[EAU_COTE].spriteY, simcity->map.spriteTile[EAU_COTE].spriteLargeur, simcity->map.spriteTile[EAU_COTE].spriteHauteur,simcity->map.mapTile[x][y].coordsXY.screenX,simcity->map.mapTile[x][y].coordsXY.screenY,0);
            }
            else if (simcity->map.mapTile[x][y].typeBloc == TYPE_POMPIER_DROIT){
                al_draw_bitmap_region(*(simcity->map.spriteTile[POMPIER_DROIT].image), simcity->map.spriteTile[POMPIER_DROIT].spriteX, simcity->map.spriteTile[POMPIER_DROIT].spriteY, simcity->map.spriteTile[POMPIER_DROIT].spriteLargeur, simcity->map.spriteTile[POMPIER_DROIT].spriteHauteur,simcity->map.mapTile[x][y].coordsXY.screenX,simcity->map.mapTile[x][y].coordsXY.screenY,0);
            }
            else if (simcity->map.mapTile[x][y].typeBloc == TYPE_POMPIER_COTE){
                al_draw_bitmap_region(*(simcity->map.spriteTile[POMPIER_COTE].image), simcity->map.spriteTile[POMPIER_COTE].spriteX, simcity->map.spriteTile[POMPIER_COTE].spriteY, simcity->map.spriteTile[POMPIER_COTE].spriteLargeur, simcity->map.spriteTile[POMPIER_COTE].spriteHauteur,simcity->map.mapTile[x][y].coordsXY.screenX,simcity->map.mapTile[x][y].coordsXY.screenY,0);
            }
            else if (simcity->map.mapTile[x][y].typeBloc == TYPE_RUINE){
                al_draw_bitmap(simcity->tabBitmap[BITMAP_TILE_RUINE], simcity->map.mapTile[x][y].coordsXY.screenX,simcity->map.mapTile[x][y].coordsXY.screenY,0);
            }
        }
    }

    if(modeNiveauEau){
        niveau1Eau(simcity);
    }
    if(modeNiveauElectricite == 1){
        niveau2Elec(simcity);
    }
    afficherPrevision(simcity);
    afficherIsFeu(simcity);
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

void afficherPrevision(Simcity* simcity){
    afficherPrevRoute(simcity);
    afficherPrevTerrainVague(simcity);
    afficherPrevElec(simcity);
    afficherPrevEau(simcity);
    afficherPrevPompier(simcity);
}

bool collerAlaRouteHab(Simcity* simcity){

    if (simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX - 1][simcity->interactionExterieure.mouse.celluleXY.celluleY].typeBloc == TYPE_ROUTE || simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][simcity->interactionExterieure.mouse.celluleXY.celluleY - 1].typeBloc == TYPE_ROUTE || simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX + 3][simcity->interactionExterieure.mouse.celluleXY.celluleY].typeBloc == TYPE_ROUTE || simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX + 2][simcity->interactionExterieure.mouse.celluleXY.celluleY - 1].typeBloc == TYPE_ROUTE || simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX + 3][simcity->interactionExterieure.mouse.celluleXY.celluleY + 2].typeBloc == TYPE_ROUTE || simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX + 2][simcity->interactionExterieure.mouse.celluleXY.celluleY + 3].typeBloc == TYPE_ROUTE || simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][simcity->interactionExterieure.mouse.celluleXY.celluleY + 3].typeBloc == TYPE_ROUTE || simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX - 1][simcity->interactionExterieure.mouse.celluleXY.celluleY + 2].typeBloc == TYPE_ROUTE || simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX + 1][simcity->interactionExterieure.mouse.celluleXY.celluleY - 1].typeBloc == TYPE_ROUTE || simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX - 1][simcity->interactionExterieure.mouse.celluleXY.celluleY + 1].typeBloc == TYPE_ROUTE || simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX + 1][simcity->interactionExterieure.mouse.celluleXY.celluleY + 3].typeBloc == TYPE_ROUTE || simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX + 3][simcity->interactionExterieure.mouse.celluleXY.celluleY + 1].typeBloc == TYPE_ROUTE){
               return true;
    }
    return false;

}

int isTerrainVaguePossible(Simcity* simcity){
    if (simcity->toolBox.terrainVagueEnMain == 1 && simcity->outOfBorder  && collerAlaRouteHab(simcity) && simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][simcity->interactionExterieure.mouse.celluleXY.celluleY].typeBloc == TYPE_HERBE){
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
    if (simcity->allegro.event.mouse.button == 1 && isTerrainVaguePossible(simcity) && isPayer(simcity,simcity->banque.prixTerrainVague)){
        simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][simcity->interactionExterieure.mouse.celluleXY.celluleY].typeBloc = TYPE_TERRAIN_VAGUE;
        for (int x = simcity->interactionExterieure.mouse.celluleXY.celluleX; x < simcity->interactionExterieure.mouse.celluleXY.celluleX + 3; ++x) {
            for (int y = simcity->interactionExterieure.mouse.celluleXY.celluleY; y < simcity->interactionExterieure.mouse.celluleXY.celluleY + 3; ++y) {
                simcity->graphe.grille[x][y].type = TYPE_TERRAIN_VAGUE;
                if (simcity->interactionExterieure.mouse.celluleXY.celluleX == x && simcity->interactionExterieure.mouse.celluleXY.celluleY == y){
                    simcity->graphe.grille[x][y].type = TYPE_TERRAIN_VAGUE;
                }else{
                    simcity->map.mapTile[x][y].typeBloc = -1; // permet de ne pas faire bug l'affchage des maisons
                }
            }
        }
        simcity->banque.achatTerrainVague = true;
        construireHabitation(simcity);
    }
}

void afficherPrevTerrainVague(Simcity* simcity){
    if (simcity->toolBox.terrainVagueEnMain && isTerrainVaguePossible(simcity)){
        al_draw_bitmap_region(*(simcity->map.spriteTile[TERRAIN_VAGUE].image), simcity->map.spriteTile[TERRAIN_VAGUE].spriteX, simcity->map.spriteTile[TERRAIN_VAGUE].spriteY, simcity->map.spriteTile[TERRAIN_VAGUE].spriteLargeur, simcity->map.spriteTile[TERRAIN_VAGUE].spriteHauteur,simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][simcity->interactionExterieure.mouse.celluleXY.celluleY].coordsXY.screenX,simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][simcity->interactionExterieure.mouse.celluleXY.celluleY].coordsXY.screenY,0);
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
    if (simcity->map.creationRouteX < simcity->interactionExterieure.mouse.celluleXY.celluleX && simcity->map.creationRouteY < simcity->interactionExterieure.mouse.celluleXY.celluleY) {
        for (int x = simcity->map.creationRouteX; x <= simcity->map.creationRouteX + simcity->map.compteurCheminsX; ++x){
            if (simcity->map.mapTile[x][simcity->interactionExterieure.mouse.celluleXY.celluleY - simcity->map.compteurCheminsY].typeBloc != TYPE_HERBE && simcity->map.mapTile[x][simcity->interactionExterieure.mouse.celluleXY.celluleY - simcity->map.compteurCheminsY].typeBloc != TYPE_ROUTE){
                return 0;
            }
        }
        for (int y = simcity->map.creationRouteY;y <= simcity->map.creationRouteY + simcity->map.compteurCheminsY; ++y) {
            if (simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][y].typeBloc != TYPE_HERBE && simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][y].typeBloc != TYPE_ROUTE){
                return 0;
            }
        }
    }else if (simcity->map.creationRouteX > simcity->interactionExterieure.mouse.celluleXY.celluleX && simcity->map.creationRouteY < simcity->interactionExterieure.mouse.celluleXY.celluleY) {
        for (int x = simcity->interactionExterieure.mouse.celluleXY.celluleX; x <= simcity->interactionExterieure.mouse.celluleXY.celluleX + simcity->map.compteurCheminsX; ++x) {
            if (simcity->map.mapTile[x][simcity->interactionExterieure.mouse.celluleXY.celluleY - simcity->map.compteurCheminsY].typeBloc != TYPE_HERBE && simcity->map.mapTile[x][simcity->interactionExterieure.mouse.celluleXY.celluleY - simcity->map.compteurCheminsY].typeBloc != TYPE_ROUTE){
                return 0;
            }
        }
        for (int y = simcity->map.creationRouteY; y <= simcity->map.creationRouteY + simcity->map.compteurCheminsY; ++y){
            if (simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][y].typeBloc != TYPE_HERBE && simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][y].typeBloc != TYPE_ROUTE){
                return 0;
            }
        }
    }else if (simcity->map.creationRouteX > simcity->interactionExterieure.mouse.celluleXY.celluleX && simcity->map.creationRouteY > simcity->interactionExterieure.mouse.celluleXY.celluleY) {
        for (int x = simcity->interactionExterieure.mouse.celluleXY.celluleX; x <= simcity->interactionExterieure.mouse.celluleXY.celluleX + simcity->map.compteurCheminsX; ++x) {
            if (simcity->map.mapTile[x][simcity->interactionExterieure.mouse.celluleXY.celluleY + simcity->map.compteurCheminsY].typeBloc != TYPE_HERBE && simcity->map.mapTile[x][simcity->interactionExterieure.mouse.celluleXY.celluleY + simcity->map.compteurCheminsY].typeBloc != TYPE_ROUTE){
                return 0;
            }
        }
        for (int y = simcity->interactionExterieure.mouse.celluleXY.celluleY; y <= simcity->interactionExterieure.mouse.celluleXY.celluleY + simcity->map.compteurCheminsY; ++y) {
            if (simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][y].typeBloc != TYPE_HERBE && simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][y].typeBloc != TYPE_ROUTE){
                return 0;
            }
        }
    }else if (simcity->map.creationRouteX < simcity->interactionExterieure.mouse.celluleXY.celluleX && simcity->map.creationRouteY > simcity->interactionExterieure.mouse.celluleXY.celluleY) {
        for (int x = simcity->map.creationRouteX; x <= simcity->map.creationRouteX + simcity->map.compteurCheminsX; ++x) {
            if (simcity->map.mapTile[x][simcity->interactionExterieure.mouse.celluleXY.celluleY + simcity->map.compteurCheminsY].typeBloc != TYPE_HERBE && simcity->map.mapTile[x][simcity->interactionExterieure.mouse.celluleXY.celluleY + simcity->map.compteurCheminsY].typeBloc != TYPE_ROUTE){
                return 0;
            }
        }
        for (int y = simcity->interactionExterieure.mouse.celluleXY.celluleY; y <= simcity->interactionExterieure.mouse.celluleXY.celluleY + simcity->map.compteurCheminsY; ++y) {
            if (simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][y].typeBloc != TYPE_HERBE && simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][y].typeBloc != TYPE_ROUTE){
                return 0;
            }
        }
    }else if (simcity->map.creationRouteX < simcity->interactionExterieure.mouse.celluleXY.celluleX) {
        for (int x = simcity->map.creationRouteX; x <= simcity->map.creationRouteX + simcity->map.compteurCheminsX; ++x) {
            if (simcity->map.mapTile[x][simcity->interactionExterieure.mouse.celluleXY.celluleY].typeBloc != TYPE_HERBE && simcity->map.mapTile[x][simcity->interactionExterieure.mouse.celluleXY.celluleY].typeBloc != TYPE_ROUTE){
                return 0;
            }
        }
    }else if (simcity->map.creationRouteX > simcity->interactionExterieure.mouse.celluleXY.celluleX) {
        for (int x = simcity->interactionExterieure.mouse.celluleXY.celluleX; x <= simcity->interactionExterieure.mouse.celluleXY.celluleX + simcity->map.compteurCheminsX; ++x) {
            if (simcity->map.mapTile[x][simcity->interactionExterieure.mouse.celluleXY.celluleY].typeBloc != TYPE_HERBE && simcity->map.mapTile[x][simcity->interactionExterieure.mouse.celluleXY.celluleY].typeBloc != TYPE_ROUTE){
                return 0;
            }
        }
    }else if (simcity->map.creationRouteY < simcity->interactionExterieure.mouse.celluleXY.celluleY) {
        for (int y = simcity->map.creationRouteY; y <= simcity->map.creationRouteY + simcity->map.compteurCheminsY; ++y) {
            if (simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][y].typeBloc != TYPE_HERBE && simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][y].typeBloc != TYPE_ROUTE){
                return 0;
            }
        }
    }else if (simcity->map.creationRouteY > simcity->interactionExterieure.mouse.celluleXY.celluleY) {
        for (int y = simcity->interactionExterieure.mouse.celluleXY.celluleY; y <= simcity->interactionExterieure.mouse.celluleXY.celluleY + simcity->map.compteurCheminsY; ++y) {
            if (simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][y].typeBloc != TYPE_HERBE && simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][y].typeBloc != TYPE_ROUTE){
                return 0;
            }
        }
    }
    return 1;
}

void afficherPrevRoute(Simcity* simcity) {
    if (routePossibleChemin(simcity) && simcity->map.cliqueRoute) {
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
                        simcity->graphe.grille[x][simcity->interactionExterieure.mouse.celluleXY.celluleY - simcity->map.compteurCheminsY].type = TYPE_ROUTE;
                    }
                    for (int y = simcity->map.creationRouteY;y <= simcity->map.creationRouteY + simcity->map.compteurCheminsY; ++y) {
                        simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][y].typeBloc = TYPE_ROUTE;
                        simcity->graphe.grille[simcity->interactionExterieure.mouse.celluleXY.celluleX][y].type = TYPE_ROUTE;

                    }
                } else if (simcity->map.creationRouteX > simcity->interactionExterieure.mouse.celluleXY.celluleX && simcity->map.creationRouteY < simcity->interactionExterieure.mouse.celluleXY.celluleY) {
                    for (int x = simcity->interactionExterieure.mouse.celluleXY.celluleX; x <= simcity->interactionExterieure.mouse.celluleXY.celluleX + simcity->map.compteurCheminsX; ++x) {
                        simcity->map.mapTile[x][simcity->interactionExterieure.mouse.celluleXY.celluleY - simcity->map.compteurCheminsY].typeBloc = TYPE_ROUTE;
                        simcity->graphe.grille[x][simcity->interactionExterieure.mouse.celluleXY.celluleY - simcity->map.compteurCheminsY].type = TYPE_ROUTE;
                    }
                    for (int y = simcity->map.creationRouteY; y <= simcity->map.creationRouteY + simcity->map.compteurCheminsY; ++y){
                        simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][y].typeBloc = TYPE_ROUTE;
                        simcity->graphe.grille[simcity->interactionExterieure.mouse.celluleXY.celluleX][y].type = TYPE_ROUTE;
                    }
                } else if (simcity->map.creationRouteX > simcity->interactionExterieure.mouse.celluleXY.celluleX && simcity->map.creationRouteY > simcity->interactionExterieure.mouse.celluleXY.celluleY) {
                    for (int x = simcity->interactionExterieure.mouse.celluleXY.celluleX; x <= simcity->interactionExterieure.mouse.celluleXY.celluleX + simcity->map.compteurCheminsX; ++x) {
                        simcity->map.mapTile[x][simcity->interactionExterieure.mouse.celluleXY.celluleY + simcity->map.compteurCheminsY].typeBloc = TYPE_ROUTE;
                        simcity->graphe.grille[x][simcity->interactionExterieure.mouse.celluleXY.celluleY + simcity->map.compteurCheminsY].type = TYPE_ROUTE;

                    }
                    for (int y = simcity->interactionExterieure.mouse.celluleXY.celluleY; y <= simcity->interactionExterieure.mouse.celluleXY.celluleY + simcity->map.compteurCheminsY; ++y) {
                        simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][y].typeBloc = TYPE_ROUTE;
                        simcity->graphe.grille[simcity->interactionExterieure.mouse.celluleXY.celluleX][y].type = TYPE_ROUTE;
                    }
                } else if (simcity->map.creationRouteX < simcity->interactionExterieure.mouse.celluleXY.celluleX && simcity->map.creationRouteY > simcity->interactionExterieure.mouse.celluleXY.celluleY) {
                    for (int x = simcity->map.creationRouteX; x <= simcity->map.creationRouteX + simcity->map.compteurCheminsX; ++x) {
                        simcity->map.mapTile[x][simcity->interactionExterieure.mouse.celluleXY.celluleY + simcity->map.compteurCheminsY].typeBloc = TYPE_ROUTE;
                        simcity->graphe.grille[x][simcity->interactionExterieure.mouse.celluleXY.celluleY + simcity->map.compteurCheminsY].type = TYPE_ROUTE;
                    }
                    for (int y = simcity->interactionExterieure.mouse.celluleXY.celluleY; y <= simcity->interactionExterieure.mouse.celluleXY.celluleY + simcity->map.compteurCheminsY; ++y) {
                        simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][y].typeBloc = TYPE_ROUTE;
                        simcity->graphe.grille[simcity->interactionExterieure.mouse.celluleXY.celluleX][y].type = TYPE_ROUTE;
                    }
                } else if (simcity->map.creationRouteX < simcity->interactionExterieure.mouse.celluleXY.celluleX) {
                    for (int x = simcity->map.creationRouteX; x <= simcity->map.creationRouteX + simcity->map.compteurCheminsX; ++x) {
                        simcity->map.mapTile[x][simcity->interactionExterieure.mouse.celluleXY.celluleY].typeBloc = TYPE_ROUTE;
                        simcity->graphe.grille[x][simcity->interactionExterieure.mouse.celluleXY.celluleY].type = TYPE_ROUTE;
                    }
                } else if (simcity->map.creationRouteX > simcity->interactionExterieure.mouse.celluleXY.celluleX) {
                    for (int x = simcity->interactionExterieure.mouse.celluleXY.celluleX; x <= simcity->interactionExterieure.mouse.celluleXY.celluleX + simcity->map.compteurCheminsX; ++x) {
                        simcity->map.mapTile[x][simcity->interactionExterieure.mouse.celluleXY.celluleY].typeBloc = TYPE_ROUTE;
                        simcity->graphe.grille[x][simcity->interactionExterieure.mouse.celluleXY.celluleY].type = TYPE_ROUTE;
                    }
                } else if (simcity->map.creationRouteY < simcity->interactionExterieure.mouse.celluleXY.celluleY) {
                    for (int y = simcity->map.creationRouteY; y <= simcity->map.creationRouteY + simcity->map.compteurCheminsY; ++y) {
                        simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][y].typeBloc = TYPE_ROUTE;
                        simcity->graphe.grille[simcity->interactionExterieure.mouse.celluleXY.celluleX][y].type = TYPE_ROUTE;
                    }
                } else if (simcity->map.creationRouteY > simcity->interactionExterieure.mouse.celluleXY.celluleY) {
                    for (int y = simcity->interactionExterieure.mouse.celluleXY.celluleY; y <= simcity->interactionExterieure.mouse.celluleXY.celluleY + simcity->map.compteurCheminsY; ++y) {
                        simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][y].typeBloc = TYPE_ROUTE;
                        simcity->graphe.grille[simcity->interactionExterieure.mouse.celluleXY.celluleX][y].type = TYPE_ROUTE;
                    }
                }
                simcity->banque.achatRoute = true;
                payerBanque(simcity);

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

////ICI METTRE LE SUCCESSEUR SI CONDITION REMPLIE
bool collerAlaRouteElec(Simcity* simcity){
    if (simcity->toolBox.elecDroit){
        for (int x = simcity->interactionExterieure.mouse.celluleXY.celluleX; x < simcity->interactionExterieure.mouse.celluleXY.celluleX + 6; ++x) {
            if (simcity->map.mapTile[x][simcity->interactionExterieure.mouse.celluleXY.celluleY - 1].typeBloc == TYPE_ROUTE || simcity->map.mapTile[x][simcity->interactionExterieure.mouse.celluleXY.celluleY + 4].typeBloc == TYPE_ROUTE ){
                return true;
            }
        }
        for (int y = simcity->interactionExterieure.mouse.celluleXY.celluleY; y < simcity->interactionExterieure.mouse.celluleXY.celluleY + 4; ++y) {
            if (simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX - 1][y].typeBloc == TYPE_ROUTE || simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX + 6][y].typeBloc == TYPE_ROUTE){
                return true;
            }
        }
        return false;
    }else if (!simcity->toolBox.elecDroit){
        for (int x = simcity->interactionExterieure.mouse.celluleXY.celluleX; x < simcity->interactionExterieure.mouse.celluleXY.celluleX + 4; ++x) {
            if (simcity->map.mapTile[x][simcity->interactionExterieure.mouse.celluleXY.celluleY - 1].typeBloc == TYPE_ROUTE || simcity->map.mapTile[x][simcity->interactionExterieure.mouse.celluleXY.celluleY + 6].typeBloc == TYPE_ROUTE ){
                return true;
            }
        }
        for (int y = simcity->interactionExterieure.mouse.celluleXY.celluleY; y < simcity->interactionExterieure.mouse.celluleXY.celluleY + 6; ++y) {
            if (simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX - 1][y].typeBloc == TYPE_ROUTE || simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX + 4][y].typeBloc == TYPE_ROUTE){
                return true;
            }
        }
        return false;
    }
}
bool collerAlaRouteEau(Simcity* simcity){
    if (simcity->toolBox.eauDroit == 1){
        for (int x = simcity->interactionExterieure.mouse.celluleXY.celluleX; x < simcity->interactionExterieure.mouse.celluleXY.celluleX + 6; ++x) {
            if (simcity->map.mapTile[x][simcity->interactionExterieure.mouse.celluleXY.celluleY - 1].typeBloc == TYPE_ROUTE || simcity->map.mapTile[x][simcity->interactionExterieure.mouse.celluleXY.celluleY + 4].typeBloc == TYPE_ROUTE ){
                return true;
            }
        }
        for (int y = simcity->interactionExterieure.mouse.celluleXY.celluleY; y < simcity->interactionExterieure.mouse.celluleXY.celluleY + 4; ++y) {
            if (simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX - 1][y].typeBloc == TYPE_ROUTE || simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX + 6][y].typeBloc == TYPE_ROUTE){
                return true;
            }
        }
        return false;
    }else if (simcity->toolBox.eauDroit == 0){
        for (int x = simcity->interactionExterieure.mouse.celluleXY.celluleX; x < simcity->interactionExterieure.mouse.celluleXY.celluleX + 4; ++x) {
            if (simcity->map.mapTile[x][simcity->interactionExterieure.mouse.celluleXY.celluleY - 1].typeBloc == TYPE_ROUTE || simcity->map.mapTile[x][simcity->interactionExterieure.mouse.celluleXY.celluleY + 6].typeBloc == TYPE_ROUTE ){
                return true;
            }
        }
        for (int y = simcity->interactionExterieure.mouse.celluleXY.celluleY; y < simcity->interactionExterieure.mouse.celluleXY.celluleY + 6; ++y) {
            if (simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX - 1][y].typeBloc == TYPE_ROUTE || simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX + 4][y].typeBloc == TYPE_ROUTE){
                return true;
            }
        }
        return false;
    }
    return false;
}
bool collerAlaRoutPompier(Simcity* simcity){
    if (simcity->toolBox.pompierDroit == 1){
        for (int x = simcity->interactionExterieure.mouse.celluleXY.celluleX; x < simcity->interactionExterieure.mouse.celluleXY.celluleX + 6; ++x) {
            if (simcity->map.mapTile[x][simcity->interactionExterieure.mouse.celluleXY.celluleY - 1].typeBloc == TYPE_ROUTE || simcity->map.mapTile[x][simcity->interactionExterieure.mouse.celluleXY.celluleY + 4].typeBloc == TYPE_ROUTE ){
                return true;
            }
        }
        for (int y = simcity->interactionExterieure.mouse.celluleXY.celluleY; y < simcity->interactionExterieure.mouse.celluleXY.celluleY + 4; ++y) {
            if (simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX - 1][y].typeBloc == TYPE_ROUTE || simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX + 6][y].typeBloc == TYPE_ROUTE){
                return true;
            }
        }
        return false;
    }else if (simcity->toolBox.pompierDroit == 0){
        for (int x = simcity->interactionExterieure.mouse.celluleXY.celluleX; x < simcity->interactionExterieure.mouse.celluleXY.celluleX + 4; ++x) {
            if (simcity->map.mapTile[x][simcity->interactionExterieure.mouse.celluleXY.celluleY - 1].typeBloc == TYPE_ROUTE || simcity->map.mapTile[x][simcity->interactionExterieure.mouse.celluleXY.celluleY + 6].typeBloc == TYPE_ROUTE ){
                return true;
            }
        }
        for (int y = simcity->interactionExterieure.mouse.celluleXY.celluleY; y < simcity->interactionExterieure.mouse.celluleXY.celluleY + 6; ++y) {
            if (simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX - 1][y].typeBloc == TYPE_ROUTE || simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX + 4][y].typeBloc == TYPE_ROUTE){
                return true;
            }
        }
        return false;
    }
    return false;
}
bool collerAlaRouteInfra(Simcity* simcity){
    if (simcity->toolBox.elecEnMain){
        return collerAlaRouteElec(simcity);
    } else if (simcity->toolBox.eauEnMain){
        return collerAlaRouteEau(simcity);
    }else if (simcity->toolBox.pompierEnMain){
        return collerAlaRoutPompier(simcity);
    }
}

int isElecPossible(Simcity* simcity){
    if (simcity->toolBox.elecEnMain == 1 && simcity->outOfBorder && collerAlaRouteInfra(simcity) && simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][simcity->interactionExterieure.mouse.celluleXY.celluleY].typeBloc == TYPE_HERBE){
        if (simcity->toolBox.elecDroit){
            for (int x = simcity->interactionExterieure.mouse.celluleXY.celluleX; x < simcity->interactionExterieure.mouse.celluleXY.celluleX + 6; ++x) {
                for (int y = simcity->interactionExterieure.mouse.celluleXY.celluleY; y < simcity->interactionExterieure.mouse.celluleXY.celluleY + 4; ++y) {
                    if (simcity->map.mapTile[x][y].typeBloc != TYPE_HERBE || x > NBCELLULEX || y >= NBCELLULEY){
                        return 0;
                    }
                }
            }
            return 1;
        }
        else if (!simcity->toolBox.elecDroit){
            for (int x = simcity->interactionExterieure.mouse.celluleXY.celluleX; x < simcity->interactionExterieure.mouse.celluleXY.celluleX + 4; ++x) {
                for (int y = simcity->interactionExterieure.mouse.celluleXY.celluleY; y < simcity->interactionExterieure.mouse.celluleXY.celluleY + 6; ++y) {
                    if (simcity->map.mapTile[x][y].typeBloc != TYPE_HERBE || x > NBCELLULEX || y >= NBCELLULEY){
                        return 0;
                    }
                }
            }
            return 1;
        }
        return 0;
        }
    return 0;
}

void poserElec(Simcity *simcity){
    if (simcity->allegro.event.mouse.button == 1 && simcity->toolBox.elecEnMain && isElecPossible(simcity) && isPayer(simcity,simcity->banque.prixElectricite)) {
        if (simcity->toolBox.elecDroit) {
            simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][simcity->interactionExterieure.mouse.celluleXY.celluleY].typeBloc = TYPE_ELEC_DROIT;
            for (int x = simcity->interactionExterieure.mouse.celluleXY.celluleX;
                 x < simcity->interactionExterieure.mouse.celluleXY.celluleX + 6; ++x) {
                for (int y = simcity->interactionExterieure.mouse.celluleXY.celluleY;
                     y < simcity->interactionExterieure.mouse.celluleXY.celluleY + 4; ++y) {
                    simcity->graphe.grille[x][y].type = TYPE_ELEC_DROIT;
                    if (simcity->interactionExterieure.mouse.celluleXY.celluleX == x &&
                        simcity->interactionExterieure.mouse.celluleXY.celluleY == y) {

                    } else {
                        simcity->map.mapTile[x][y].typeBloc = -2; // permet de ne pas faire bug l'affchage des maisons
                    }
                }
            }
            simcity->banque.achatElectricite = 1;
            construireInfrastructure(simcity);
        } else if (!simcity->toolBox.elecDroit) {
            simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][simcity->interactionExterieure.mouse.celluleXY.celluleY].typeBloc = TYPE_ELEC_COTE;
            for (int x = simcity->interactionExterieure.mouse.celluleXY.celluleX; x < simcity->interactionExterieure.mouse.celluleXY.celluleX + 4; ++x) {
                for (int y = simcity->interactionExterieure.mouse.celluleXY.celluleY; y < simcity->interactionExterieure.mouse.celluleXY.celluleY + 6; ++y) {
                    simcity->graphe.grille[x][y].type = TYPE_ELEC_COTE;
                    if (simcity->interactionExterieure.mouse.celluleXY.celluleX == x && simcity->interactionExterieure.mouse.celluleXY.celluleY == y) {
                    } else {
                        simcity->map.mapTile[x][y].typeBloc = -2; // permet de ne pas faire bug l'affchage des maisons
                    }
                }
            }
            simcity->banque.achatElectricite = 1;
            construireInfrastructure(simcity);
        }
    }
}

void afficherPrevElec(Simcity* simcity){
    if (simcity->toolBox.elecEnMain && isElecPossible(simcity)){
        if (simcity->toolBox.elecDroit){
            al_draw_bitmap_region(*(simcity->map.spriteTile[ELEC_DROIT].image), simcity->map.spriteTile[ELEC_DROIT].spriteX, simcity->map.spriteTile[ELEC_DROIT].spriteY, simcity->map.spriteTile[ELEC_DROIT].spriteLargeur, simcity->map.spriteTile[ELEC_DROIT].spriteHauteur,simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][simcity->interactionExterieure.mouse.celluleXY.celluleY].coordsXY.screenX,simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][simcity->interactionExterieure.mouse.celluleXY.celluleY].coordsXY.screenY,0);
        } else if(!simcity->toolBox.elecDroit){
            al_draw_bitmap_region(*(simcity->map.spriteTile[ELEC_COTE].image), simcity->map.spriteTile[ELEC_COTE].spriteX, simcity->map.spriteTile[ELEC_COTE].spriteY, simcity->map.spriteTile[ELEC_COTE].spriteLargeur, simcity->map.spriteTile[ELEC_COTE].spriteHauteur,simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][simcity->interactionExterieure.mouse.celluleXY.celluleY].coordsXY.screenX,simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][simcity->interactionExterieure.mouse.celluleXY.celluleY].coordsXY.screenY,0);
        }
    }
}

int isEauPossible(Simcity* simcity){
    if (simcity->toolBox.eauEnMain == 1 && collerAlaRouteInfra(simcity) && simcity->outOfBorder && simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][simcity->interactionExterieure.mouse.celluleXY.celluleY].typeBloc == TYPE_HERBE){
        if (simcity->toolBox.eauDroit){
            for (int x = simcity->interactionExterieure.mouse.celluleXY.celluleX; x < simcity->interactionExterieure.mouse.celluleXY.celluleX + 6; ++x) {
                for (int y = simcity->interactionExterieure.mouse.celluleXY.celluleY; y < simcity->interactionExterieure.mouse.celluleXY.celluleY + 4; ++y) {
                    if (simcity->map.mapTile[x][y].typeBloc != TYPE_HERBE || x > NBCELLULEX || y >= NBCELLULEY){
                        return 0;
                    }
                }
            }
            return 1;
        }
        else if (!simcity->toolBox.eauDroit){
            for (int x = simcity->interactionExterieure.mouse.celluleXY.celluleX; x < simcity->interactionExterieure.mouse.celluleXY.celluleX + 4; ++x) {
                for (int y = simcity->interactionExterieure.mouse.celluleXY.celluleY; y < simcity->interactionExterieure.mouse.celluleXY.celluleY + 6; ++y) {
                    if (simcity->map.mapTile[x][y].typeBloc != TYPE_HERBE || x > NBCELLULEX || y >= NBCELLULEY){
                        return 0;
                    }
                }
            }
            return 1;
        }
        return 0;
    }
    return 0;
}

void poserEau(Simcity *simcity){
    if (simcity->allegro.event.mouse.button == 1 && simcity->toolBox.eauEnMain && isEauPossible(simcity) && isPayer(simcity,simcity->banque.prixChateauEau)) {
        if (simcity->toolBox.eauDroit) {
                simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][simcity->interactionExterieure.mouse.celluleXY.celluleY].typeBloc = TYPE_EAU_DROIT;
            for (int x = simcity->interactionExterieure.mouse.celluleXY.celluleX;
                 x < simcity->interactionExterieure.mouse.celluleXY.celluleX + 6; ++x) {
                for (int y = simcity->interactionExterieure.mouse.celluleXY.celluleY;
                     y < simcity->interactionExterieure.mouse.celluleXY.celluleY + 4; ++y) {
                    simcity->graphe.grille[x][y].type = TYPE_EAU_DROIT;
                    if (simcity->interactionExterieure.mouse.celluleXY.celluleX == x &&
                        simcity->interactionExterieure.mouse.celluleXY.celluleY == y) {

                    } else {
                        simcity->map.mapTile[x][y].typeBloc = -2; // permet de ne pas faire bug l'affchage des maisons
                    }
                }
            }
            simcity->banque.achatChateauEau = 1;
            construireInfrastructure(simcity);
        } else if (!simcity->toolBox.eauDroit) {
            simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][simcity->interactionExterieure.mouse.celluleXY.celluleY].typeBloc = TYPE_EAU_COTE;
            for (int x = simcity->interactionExterieure.mouse.celluleXY.celluleX; x < simcity->interactionExterieure.mouse.celluleXY.celluleX + 4; ++x) {
                for (int y = simcity->interactionExterieure.mouse.celluleXY.celluleY; y < simcity->interactionExterieure.mouse.celluleXY.celluleY + 6; ++y) {
                    simcity->graphe.grille[x][y].type = TYPE_EAU_COTE;
                    if (simcity->interactionExterieure.mouse.celluleXY.celluleX == x && simcity->interactionExterieure.mouse.celluleXY.celluleY == y) {
                    } else {
                        simcity->map.mapTile[x][y].typeBloc = -2; // permet de ne pas faire bug l'affchage des maisons
                    }
                }
            }
            simcity->banque.achatChateauEau = 1;
            construireInfrastructure(simcity);
        }
    }
}

void afficherPrevEau(Simcity* simcity){
    if (simcity->toolBox.eauEnMain && isEauPossible(simcity)){
        if (simcity->toolBox.eauDroit){
            al_draw_bitmap_region(*(simcity->map.spriteTile[EAU_DROIT].image), simcity->map.spriteTile[EAU_DROIT].spriteX, simcity->map.spriteTile[EAU_DROIT].spriteY, simcity->map.spriteTile[EAU_DROIT].spriteLargeur, simcity->map.spriteTile[EAU_DROIT].spriteHauteur,simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][simcity->interactionExterieure.mouse.celluleXY.celluleY].coordsXY.screenX,simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][simcity->interactionExterieure.mouse.celluleXY.celluleY].coordsXY.screenY,0);
        } else if(!simcity->toolBox.eauDroit){
            al_draw_bitmap_region(*(simcity->map.spriteTile[EAU_COTE].image), simcity->map.spriteTile[EAU_COTE].spriteX, simcity->map.spriteTile[EAU_COTE].spriteY, simcity->map.spriteTile[EAU_COTE].spriteLargeur, simcity->map.spriteTile[EAU_COTE].spriteHauteur,simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][simcity->interactionExterieure.mouse.celluleXY.celluleY].coordsXY.screenX,simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][simcity->interactionExterieure.mouse.celluleXY.celluleY].coordsXY.screenY,0);
        }
    }
}

int isPompierPossible(Simcity* simcity){
    if (simcity->toolBox.pompierEnMain == 1 && collerAlaRouteInfra(simcity) && simcity->outOfBorder && simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][simcity->interactionExterieure.mouse.celluleXY.celluleY].typeBloc == TYPE_HERBE){
        if (simcity->toolBox.pompierDroit){
            for (int x = simcity->interactionExterieure.mouse.celluleXY.celluleX; x < simcity->interactionExterieure.mouse.celluleXY.celluleX + 6; ++x) {
                for (int y = simcity->interactionExterieure.mouse.celluleXY.celluleY; y < simcity->interactionExterieure.mouse.celluleXY.celluleY + 4; ++y) {
                    if (simcity->map.mapTile[x][y].typeBloc != TYPE_HERBE || x > NBCELLULEX || y >= NBCELLULEY){
                        return 0;
                    }
                }
            }
            return 1;
        }
        else if (!simcity->toolBox.pompierDroit){
            for (int x = simcity->interactionExterieure.mouse.celluleXY.celluleX; x < simcity->interactionExterieure.mouse.celluleXY.celluleX + 4; ++x) {
                for (int y = simcity->interactionExterieure.mouse.celluleXY.celluleY; y < simcity->interactionExterieure.mouse.celluleXY.celluleY + 6; ++y) {
                    if (simcity->map.mapTile[x][y].typeBloc != TYPE_HERBE || x > NBCELLULEX || y >= NBCELLULEY){
                        return 0;
                    }
                }
            }
            return 1;
        }
        return 0;
    }
    return 0;
}

void poserPompier(Simcity *simcity){
    if (simcity->allegro.event.mouse.button == 1 && simcity->toolBox.pompierEnMain && isPompierPossible(simcity) && isPayer(simcity,simcity->banque.prixPompier)) {
        if (simcity->toolBox.pompierDroit) {
            simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][simcity->interactionExterieure.mouse.celluleXY.celluleY].typeBloc = TYPE_POMPIER_DROIT;
            for (int x = simcity->interactionExterieure.mouse.celluleXY.celluleX;
                 x < simcity->interactionExterieure.mouse.celluleXY.celluleX + 6; ++x) {
                for (int y = simcity->interactionExterieure.mouse.celluleXY.celluleY;
                     y < simcity->interactionExterieure.mouse.celluleXY.celluleY + 4; ++y) {
                    simcity->graphe.grille[x][y].type = TYPE_POMPIER_DROIT;
                    if (simcity->interactionExterieure.mouse.celluleXY.celluleX == x &&
                        simcity->interactionExterieure.mouse.celluleXY.celluleY == y) {

                    } else {
                        simcity->map.mapTile[x][y].typeBloc = -3; // permet de ne pas faire bug l'affchage des maisons
                    }
                }
            }
            simcity->banque.achatPompier = 1;
        } else if (!simcity->toolBox.pompierDroit) {
            simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][simcity->interactionExterieure.mouse.celluleXY.celluleY].typeBloc = TYPE_POMPIER_COTE;
            for (int x = simcity->interactionExterieure.mouse.celluleXY.celluleX; x < simcity->interactionExterieure.mouse.celluleXY.celluleX + 4; ++x) {
                for (int y = simcity->interactionExterieure.mouse.celluleXY.celluleY; y < simcity->interactionExterieure.mouse.celluleXY.celluleY + 6; ++y) {
                    simcity->graphe.grille[x][y].type = TYPE_POMPIER_COTE;
                    if (simcity->interactionExterieure.mouse.celluleXY.celluleX == x && simcity->interactionExterieure.mouse.celluleXY.celluleY == y) {
                    } else {
                        simcity->map.mapTile[x][y].typeBloc = -2; // permet de ne pas faire bug l'affchage des maisons
                    }
                }
            }
            simcity->banque.achatPompier = 1;
        }
    }
}

void afficherPrevPompier(Simcity* simcity){
    if (simcity->toolBox.pompierEnMain && isPompierPossible(simcity)){
        if (simcity->toolBox.pompierDroit){
            al_draw_bitmap_region(*(simcity->map.spriteTile[POMPIER_DROIT].image), simcity->map.spriteTile[POMPIER_DROIT].spriteX, simcity->map.spriteTile[POMPIER_DROIT].spriteY, simcity->map.spriteTile[POMPIER_DROIT].spriteLargeur, simcity->map.spriteTile[POMPIER_DROIT].spriteHauteur,simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][simcity->interactionExterieure.mouse.celluleXY.celluleY].coordsXY.screenX,simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][simcity->interactionExterieure.mouse.celluleXY.celluleY].coordsXY.screenY,0);

        } else if(!simcity->toolBox.pompierDroit){
            al_draw_bitmap_region(*(simcity->map.spriteTile[POMPIER_COTE].image), simcity->map.spriteTile[POMPIER_COTE].spriteX, simcity->map.spriteTile[POMPIER_COTE].spriteY, simcity->map.spriteTile[POMPIER_COTE].spriteLargeur, simcity->map.spriteTile[POMPIER_COTE].spriteHauteur,simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][simcity->interactionExterieure.mouse.celluleXY.celluleY].coordsXY.screenX,simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][simcity->interactionExterieure.mouse.celluleXY.celluleY].coordsXY.screenY,0);
        }
    }
}

void poserBatiment(Simcity *simcity){
    poserTerrainVague(simcity);
    poserRoute(simcity);
    poserElec(simcity);
    poserEau(simcity);
    poserPompier(simcity);
    BFSEau(simcity);
    BFSElec(simcity);
}

void tournerBatiment(Simcity *simcity){
    if (simcity->allegro.event.mouse.button == 2 && simcity->toolBox.elecEnMain){
        simcity->toolBox.elecDroit = !simcity->toolBox.elecDroit;
    }
    if (simcity->allegro.event.mouse.button == 2 && simcity->toolBox.eauEnMain){
        simcity->toolBox.eauDroit = !simcity->toolBox.eauDroit;
    }
    if (simcity->allegro.event.mouse.button == 2 && simcity->toolBox.pompierEnMain){
        simcity->toolBox.pompierDroit = !simcity->toolBox.pompierDroit;
    }
}

void detruire(Simcity *simcity){
    if (simcity->allegro.event.mouse.button == 1 && simcity->toolBox.detruireEnMain == 1 && simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][simcity->interactionExterieure.mouse.celluleXY.celluleY].typeBloc == TYPE_MAISON || simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][simcity->interactionExterieure.mouse.celluleXY.celluleY].typeBloc == TYPE_TERRAIN_VAGUE || simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][simcity->interactionExterieure.mouse.celluleXY.celluleY].typeBloc == TYPE_CABANE || simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][simcity->interactionExterieure.mouse.celluleXY.celluleY].typeBloc == TYPE_IMMEUBLE || simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][simcity->interactionExterieure.mouse.celluleXY.celluleY].typeBloc == TYPE_GRATTE_CIEL){
        for (int x = simcity->interactionExterieure.mouse.celluleXY.celluleX; x < simcity->interactionExterieure.mouse.celluleXY.celluleX + 3 ; ++x) {
            for (int y = simcity->interactionExterieure.mouse.celluleXY.celluleY; y < simcity->interactionExterieure.mouse.celluleXY.celluleY + 3; ++y) {
                simcity->map.mapTile[x][y].typeBloc = TYPE_HERBE;
            }
        }
    }
    if (simcity->allegro.event.mouse.button == 1 && simcity->toolBox.detruireEnMain == 1 && simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][simcity->interactionExterieure.mouse.celluleXY.celluleY].typeBloc == TYPE_EAU_DROIT || simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][simcity->interactionExterieure.mouse.celluleXY.celluleY].typeBloc == TYPE_ELEC_DROIT || simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][simcity->interactionExterieure.mouse.celluleXY.celluleY].typeBloc == TYPE_POMPIER_DROIT){
        for (int x = simcity->interactionExterieure.mouse.celluleXY.celluleX; x < simcity->interactionExterieure.mouse.celluleXY.celluleX + 6 ; ++x) {
            for (int y = simcity->interactionExterieure.mouse.celluleXY.celluleY; y < simcity->interactionExterieure.mouse.celluleXY.celluleY + 4; ++y) {
                simcity->map.mapTile[x][y].typeBloc = TYPE_HERBE;
            }
        }
    }
    if (simcity->allegro.event.mouse.button == 1 && simcity->toolBox.detruireEnMain == 1 && simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][simcity->interactionExterieure.mouse.celluleXY.celluleY].typeBloc == TYPE_EAU_COTE || simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][simcity->interactionExterieure.mouse.celluleXY.celluleY].typeBloc == TYPE_ELEC_COTE || simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][simcity->interactionExterieure.mouse.celluleXY.celluleY].typeBloc == TYPE_POMPIER_COTE){
        for (int x = simcity->interactionExterieure.mouse.celluleXY.celluleX; x < simcity->interactionExterieure.mouse.celluleXY.celluleX + 4 ; ++x) {
            for (int y = simcity->interactionExterieure.mouse.celluleXY.celluleY; y < simcity->interactionExterieure.mouse.celluleXY.celluleY + 6; ++y) {
                simcity->map.mapTile[x][y].typeBloc = TYPE_HERBE;
            }
        }
    }

}

void cliquer(Simcity* simcity){
    for (int i = 0; i < NBR_MAX_HAB; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (simcity->outOfBorder && simcity->allegro.event.mouse.button == 1
            && simcity->tabHabitation[i].coordXY[j].celluleX == simcity->interactionExterieure.mouse.celluleXY.celluleX
            && simcity->tabHabitation[i].coordXY[j].celluleY == simcity->interactionExterieure.mouse.celluleXY.celluleY){
                printf("Habitation : %d\n", i);
            }
        }
    }
    for (int i = 0; i < NBR_MAX_INFRA; ++i) {
        for (int j = 0; j < 16; ++j) {
            if (simcity->outOfBorder && simcity->allegro.event.mouse.button == 1 && simcity->tabInfrastructure[i].coordXY[j].celluleX == simcity->interactionExterieure.mouse.celluleXY.celluleX && simcity->tabInfrastructure[i].coordXY[j].celluleY == simcity->interactionExterieure.mouse.celluleXY.celluleY){
                printf("Infrastructure : %d\n", i);
            }
        }
    }
}


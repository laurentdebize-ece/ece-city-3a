#ifndef ECE_CITY_3A_MAP_H
#define ECE_CITY_3A_MAP_H

#include "../Structures/structures.h"


void initDataMap(Simcity* simcity);
void bitmapSpriteInit(Simcity* simcity);

void calculPositionSourisEnCelluleXY(Simcity* simcity);
void outOfBorder(Simcity* simcity);


/////ICI pour modifier le tab sous jacent
void poserTerrainVague(Simcity* simcity);
void poserRoute(Simcity* simcity);
void poserElec(Simcity *simcity);
void poserBatiment(Simcity *simcity);


void tournerBatiment(Simcity *simcity);

void afficherPrevEau(Simcity* simcity);
void afficherPrevRoute(Simcity* simcity);
void afficherPrevTerrainVague(Simcity* simcity);
void afficherPrevElec(Simcity* simcity);
void afficherPrevPompier(Simcity* simcity);
void afficherPrevision(Simcity* simcity);
void afficherMap(Simcity* simcity);
void afficherHoverMap(Simcity* simcity);

void detruire(Simcity *simcity);
void ecrire_graphe(Simcity *simcity, char *nomFichier);

#endif
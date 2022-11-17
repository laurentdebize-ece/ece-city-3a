#ifndef ECE_CITY_3A_MAP_H
#define ECE_CITY_3A_MAP_H

#include "../Structures/structures.h"

void initDataMap(Simcity* simcity);
void bitmapSpriteInit(Simcity* simcity);
void calculPositionSourisEnCelluleXY(Simcity* simcity);
void outOfBorder(Simcity* simcity);
void afficherMap(Simcity* simcity);
void afficherHoverMap(Simcity* simcity);
void poserTerrainVague(Simcity* simcity);
void poserRoute(Simcity* simcity);
void poserElec(Simcity *simcity);
void tournerBatiment(Simcity *simcity);
void afficherPrevisionRoute(Simcity* simcity);
void afficherPrevTerrainVague(Simcity* simcity);
void poserBatiment(Simcity *simcity);

#endif
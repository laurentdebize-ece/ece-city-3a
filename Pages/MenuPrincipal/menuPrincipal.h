#ifndef ECE_CITY_3A_MENUPRINCIPAL_H
#define ECE_CITY_3A_MENUPRINCIPAL_H

#include "../../Structures/structures.h"

void initDataMenuPrincipal(Simcity* simcity);
void initDataMenuCommunisteCapitaliste (Simcity* simcity);
void calculHoverComCap (Simcity* simcity);
void detectionCliqueMenuCapCom (Simcity* simcity);
void calculHover(Simcity * simcity);
void detectionClique(Simcity * simcity);
void afficherMenuPrincipal(Simcity* simcity);
void afficherMenuComCap (Simcity* simcity);

#endif

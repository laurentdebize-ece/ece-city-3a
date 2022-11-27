#ifndef ECE_CITY_3A_BITMAPS_H
#define ECE_CITY_3A_BITMAPS_H

#include "../Structures/structures.h"


void bitmapCreateAll(Simcity* simcity);
void libererBitmapAll(Simcity* simcity);


void bitmapCreateFeu (Simcity* simcity);
void bitmapCreateMap(Simcity* simcity);
void bitmapCreateMenuPrincipalIntro(Simcity* simcity);
void bitmapCreateBoutonAide(Simcity* simcity);
void bitmapCreateMenuPrincipal(Simcity* simcity);
void bitmapCreateMenuCapitalisteCommuniste(Simcity* simcity);
void bitmapCreateBoutonsMenuCapitalisteCommuniste(Simcity* simcity);
void bitmapCreateBoutonMenuPrincipal(Simcity* simcity);
void bitmapCreateToolbox (Simcity* simcity);
void bitmapCreateBarreCompteurs (Simcity* simcity);
void bitmapCreateBoutonsPause(Simcity* simcity);
void bitmapCreateAll(Simcity* simcity);

void libererBitmapMap(Simcity* simcity);
void libererBitmapMenuPrincipal(Simcity* simcity);
void libererBitmapMenuCommunisteCapitaliste(Simcity* simcity);
void libererBitmapBoutonsMenuCommunisteCapitaliste(Simcity* simcity);
void libererBitmapMenuPrincipalIntro(Simcity* simcity);
void libererBitmapBoutonMenuPrincipal(Simcity* simcity);
void libererBitmapToolbox (Simcity* simcity);
void libererBitmapBarreCompteurs (Simcity* simcity);
void libererBitmapBoutonPause (Simcity* simcity);
void libererBitmapBoutonAide (Simcity* simcity);
void libererBitmapFeu (Simcity* simcity);


#endif

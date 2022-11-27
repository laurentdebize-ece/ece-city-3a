#ifndef ECE_CITY_3A_BOUCLESJEU_H
#define ECE_CITY_3A_BOUCLESJEU_H

#include <stdio.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include "../Structures/structures.h"
#include "../Map/map.h"
#include "../Pages/MenuPrincipal/menuPrincipal.h"
#include "time.h"
#include "../Timers/timers.h"
#include "../Batiments/batiments.h"
#include "../ToolBox/toolbox.h"
#include "../Banque/banque.h"
#include "../Batiments/batiments.h"

void initAll(Simcity* simcity);
void boucleTest(Simcity* simcity);
void boucletestMenuRegles(Simcity* simcity);
void boucletestMenuPrincipal(Simcity* simcity);
void boucletestMenuCommunisteCapitaliste(Simcity* simcity);

void lancerJeu();

#endif //ECE_CITY_3A_BOUCLESJEU_H

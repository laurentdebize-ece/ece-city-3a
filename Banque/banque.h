#ifndef ECE_CITY_3A_BANQUE_H
#define ECE_CITY_3A_BANQUE_H

#include "../Structures/structures.h"

#define SOLDEINITIAL 500000 //Solde initiale du jeu
#define IMPOT 10 //par habitant et par cycle
#define COUTCENTRALE 100000 //Coût de la centrale électrique
#define COUTCHATEAUEAU 100000 //Coût du château d'eau
#define COUTROUTE 10 //Coût de la route par unite de surface
#define COUTTERRAINVAGUE 1000 //Coût d'un terrain vague
#define COUTCASERNE 10000 //Coût d'une caserne de pompiers

void initBanque(Simcity* simcity);
bool isPayer(Simcity* simcity, int sommeARetirer);
void afficherArgent(Simcity* simcity);
void payerBanque(Simcity* simcity);
void recevoirImpots(Simcity* simcity, int nbHabitants);

#endif //ECE_CITY_3A_BANQUE_H

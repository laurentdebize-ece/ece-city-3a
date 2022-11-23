#ifndef ECE_CITY_3A_BATIMENTS_H
#define ECE_CITY_3A_BATIMENTS_H

#include "../Structures/structures.h"

#define NB_HABITANTS_TERRAINVAGUE 0
#define NB_HABITANTS_CABANE 10
#define NB_HABITANTS_MAISON 50
#define NB_HABITANTS_IMMEUBLE 100
#define NB_HABITANTS_GRATTECIEL 1000
#define NB_HABITANTS_RUINE 0
#define CAPACITE_EAU 5000
#define CAPACITE_ELECTRIQUE 5000

void initTabBatiments(Simcity* simcity);
void construireBatiment(Simcity* simcity);
void miseAJourDonneesBatiment(Simcity* simcity, Batiment* batiment);
void regressionBatiment(Simcity* simcity, Batiment* batiment);
void isEvolutionPossible(Simcity* simcity, Batiment* batiment);
void nombreHabitantsTot(Simcity* simcity);
void afficherNbHabitantsTot(Simcity simcity);
void construireHabitation(Simcity* simcity);
void construireInfrastructure(Simcity* simcity);

#endif //ECE_CITY_3A_BATIMENTS_H

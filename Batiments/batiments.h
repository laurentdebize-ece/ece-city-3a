#ifndef ECE_CITY_3A_BATIMENTS_H
#define ECE_CITY_3A_BATIMENTS_H

#include "../Structures/structures.h"

//Nombre d'habitants en fonction du type de batiment
#define NB_HABITANTS_TERRAINVAGUE 0
#define NB_HABITANTS_CABANE 10
#define NB_HABITANTS_MAISON 50
#define NB_HABITANTS_IMMEUBLE 100
#define NB_HABITANTS_GRATTECIEL 1000
#define NB_HABITANTS_RUINE 0

#define CAPACITE_EAU 5000 //Capacité du chateau d'eau
#define CAPACITE_ELECTRIQUE 5000 //Capacité de la centrale électrique


void initTabBatiments(Simcity* simcity);
void construireBatiment(Simcity* simcity);
void miseAJourDonneesHabitation(Simcity* simcity, Habitation* habitation);
void regressionHabitation(Simcity* simcity, Habitation* habitation);
void isEvolutionPossible(Simcity* simcity, Habitation* habitation);
void nombreHabitantsTot(Simcity* simcity);
void afficherNbHabitantsTot(Simcity simcity);
void construireHabitation(Simcity* simcity);
void construireInfrastructure(Simcity* simcity);

#endif //ECE_CITY_3A_BATIMENTS_H

#ifndef ECE_CITY_3A_BATIMENTS_H
#define ECE_CITY_3A_BATIMENTS_H

#include "../Structures/structures.h"
#include "../Graphe/graphe.h"

//Nombre d'habitants en fonction du type de batiment
#define NB_HABITANTS_TERRAINVAGUE 0
#define NB_HABITANTS_CABANE 10
#define NB_HABITANTS_MAISON 50
#define NB_HABITANTS_IMMEUBLE 100
#define NB_HABITANTS_GRATTECIEL 1000
#define NB_HABITANTS_RUINE 0

//Capacités en eau en fonction du type de batiment
#define CAPACITE_EAU_TERRAINVAGUE 0
#define CAPACITE_EAU_CABANE 10
#define CAPACITE_EAU_MAISON 50
#define CAPACITE_EAU_IMMEUBLE 100
#define CAPACITE_EAU_GRATTECIEL 1000
#define CAPACITE_EAU_RUINE 0

//Capacités en électricité en fonction du type de batiment
#define CAPACITE_ELEC_TERRAINVAGUE 0
#define CAPACITE_ELEC_CABANE 10
#define CAPACITE_ELEC_MAISON 50
#define CAPACITE_ELEC_IMMEUBLE 100
#define CAPACITE_ELEC_GRATTECIEL 1000
#define CAPACITE_ELEC_RUINE 0

//Capacités des infrastructures
#define CAPACITE_EAU 5000 //Capacité du chateau d'eau
#define CAPACITE_ELECTRIQUE 5000 //Capacité de la centrale électrique
#define CAPACITE_POMPIER 20 //Capacité de la caserne de pompiers


void initTabBatiments(Simcity* simcity);
void miseAJourDonneesHabitation(Simcity* simcity, Habitation* habitation);
void isRegressionPossible(Simcity* simcity, Habitation* habitation);
void regressionHabitation(Simcity* simcity, Habitation* habitation);
void isEvolutionPossible(Simcity* simcity, Habitation* habitation);
void nombreHabitantsTot(Simcity* simcity);
void afficherNbHabitantsTot(Simcity* simcity);
void construireHabitation(Simcity* simcity);
void construireInfrastructure(Simcity* simcity);
void isFeu(Habitation* habitation);
void afficherIsFeu(Simcity* simcity);
void eteindreFeuMettreRuine(Simcity* simcity, Habitation* habitation);

#endif //ECE_CITY_3A_BATIMENTS_H

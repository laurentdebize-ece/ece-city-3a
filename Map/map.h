#ifndef ECE_CITY_3A_MAP_H
#define ECE_CITY_3A_MAP_H

#include "../Structures/structures.h"

void initDataMap(Simcity* simcity);
void bitmapSpriteInit(Simcity* simcity);

void calculPositionSourisEnCelluleXY(Simcity* simcity);
void outOfBorder(Simcity* simcity);

int isElecPossible(Simcity* simcity);
int isRoutePossible(Simcity* simcity);
int isTerrainVaguePossible(Simcity* simcity);
int isEauPossible(Simcity* simcity);
int isPompierPossible(Simcity* simcity);


void poserTerrainVague(Simcity* simcity);
void poserRoute(Simcity* simcity);
void poserElec(Simcity *simcity);
void poserEau(Simcity *simcity);
void poserBatiment(Simcity *simcity);
void poserPompier(Simcity *simcity);


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

void cliquer(Simcity* simcity);


//Graphe
void BFSEau(Simcity* simcity);
void BFSElec(Simcity* simcity);
void *lire_graphe( Simcity *simcity);
void reset_couleur(Simcity *simcity);

//file BFS
CaseBFS defiler(t_file *f);
void enfiler(t_file *f,  CaseBFS *caseBFS);
int fileVide(t_file *f);

//liste d'adjacence pour stocker les habitations reliées aux CE
void clearListeAdj(ListeAdj *liste);
void insertionListeAdj(ListeAdj *listeAdj, Habitation *MaMaison, int distance);
ListeAdj *initListAdj();
void enfilerVoisin(Simcity *simcity, CaseBFS num, t_file *f);

//affichage des niveaux -1 et -2
void niveau1Eau(Simcity *simcity);
void afficherReseauEau(Simcity *simcity, int x, int y );
void niveau2Elec(Simcity *simcity);
void afficherReseauElec(Simcity *simcity, int x, int y );


#endif
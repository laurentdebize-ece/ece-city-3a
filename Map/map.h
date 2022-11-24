#ifndef ECE_CITY_3A_MAP_H
#define ECE_CITY_3A_MAP_H

#include "../Structures/structures.h"

/* Structure d'un maillon */
typedef struct maillon {

    CoordsXY num;
    struct maillon *suiv;
} t_maillon;

typedef t_maillon *pmaillon;

/* Structure d'une file */
typedef struct file {
    t_maillon *tete;
    t_maillon *queue;
} t_file;


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
CoordsXY *BFSEau(Simcity* simcity);
void *lire_graphe( Simcity *simcity);

#endif
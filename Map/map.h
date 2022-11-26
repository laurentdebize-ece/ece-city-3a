#ifndef ECE_CITY_3A_MAP_H
#define ECE_CITY_3A_MAP_H

#include "../Structures/structures.h"
typedef struct CaseBFS{
    int distance;
    CoordsXY coordsXy;
}CaseBFS;

/* Structure d'un maillon */
typedef struct maillon {
    CaseBFS caseBfs;
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
void isFeu(Simcity* simcity);
void afficherIsFeu (Simcity* simcity) ;

void detruire(Simcity *simcity);

void cliquer(Simcity* simcity);


//Graphe
void BFSEau(Simcity* simcity);
void *lire_graphe( Simcity *simcity);
void reset_couleur(Simcity *simcity);

CaseBFS defiler(t_file *f);
void enfiler(t_file *f,  CaseBFS *caseBFS);
int fileVide(t_file *f);

void clearListeAdj(ListeAdj *liste);
void insertionListeAdj(ListeAdj *listeAdj, Habitation *MaMaison, int distance);
ListeAdj *initListAdj();
void enfilerVoisin(Simcity *simcity, CaseBFS num, t_file *f);


struct AdjMaillon_t {
    Habitation *habitation;
    int distance;
    struct AdjMaillon_t *suiv;
};

typedef struct AdjacencyList {
    struct AdjMaillon_t *tete;
    struct AdjMaillon_t *queue;
} AdjacencyList;

AdjacencyList* allocListe();
void insertionAdjListe(AdjacencyList *listeAdj, Habitation *MaMaison, int distance);
void clearAdjListe(AdjacencyList *liste);

#endif
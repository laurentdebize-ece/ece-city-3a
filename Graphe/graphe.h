#ifndef ECE_CITY_3A_GRAPHE_H
#define ECE_CITY_3A_GRAPHE_H

#include "../Structures/structures.h"
#include "../Batiments/batiments.h"

/*

#define LIGNES 35
#define COLONNES 45

enum construction {route, chateau, centrale, terrain, cabane, maison, immeuble, gratteCiel};
// route = 1
// chateau = 2
// centrale = 3
// terrain = 4
// cabane = 5
// maison = 6
// immeuble = 7
// gratteCiel = 8

typedef struct {
    int x;
    int y;
} coordonnees;

/////SOMMET/////
typedef struct Cellule{
    struct Arc* arc;
    enum construction type;
    coordonnees coord;
}Cellule;
typedef struct Cellule *pCellule;

//////ARC/////
struct Arc{
    struct Arc *arc_suivant;
    int sommet;
};
typedef struct Arc *pArc;

//////GRAPHE/////
typedef struct Graphe {
    int ordre;
    Cellule grille[LIGNES][COLONNES];
}Graphe;
*/


//Graphe
void BFSEau(Simcity* simcity);
void BFSElec(Simcity* simcity);
void BFSPompier(Simcity* simcity);
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
void niveau2Elec(Simcity *simcity);
void niveau3Pompier(Simcity *simcity);

//calcul des capacités de chaque maison
void calculCapaciteElec(Simcity *simcity);
void calculCapaciteEau(Simcity *simcity);

void *lire_graphe(Simcity *simcity);
void recupdonne(Graphe *graphe);
//void ecrire_graphe(Graphe *graphe, char *nomFichier);



#endif //ECE_CITY_3A_GRAPHE_H

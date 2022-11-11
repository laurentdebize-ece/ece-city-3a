#ifndef ECE_CITY_3A_GRAPHE_H
#define ECE_CITY_3A_GRAPHE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

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

Graphe *lire_graphe(char *nomFichier);
pCellule *CreerArete( pCellule* Cellule, int s1, int s2);


#endif //ECE_CITY_3A_GRAPHE_H

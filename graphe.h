#ifndef MAIN_C_GRAPHE_H
#define MAIN_C_GRAPHE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

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

// cellule du tableau = sommet de la map
typedef struct {
    int id;
    enum construction type;
    coordonnees coord;
    int capacite;
} cellule;
typedef struct cellule *pCellule;

// liste chainée de cellules
typedef struct{
    int sommet;
    struct Arc *arc_suivant;
}Arc;
typedef struct Arc *pArc;

typedef struct {
    int ordre;
    pCellule *pCellule;
    cellule **grille;
}Graphe;

Graphe *lire_graphe(char *nomFichier);
pCellule *CreerArete( pCellule* cellule, int s1, int s2);


#endif //MAIN_C_GRAPHE_H

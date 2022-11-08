#include "graphe.h"
/*
 * Graphe *lire_graphe(char *nomFichier) {

    FILE *ifs = fopen(nomFichier, "r");
    int ordre;

    if (!ifs) {
        printf("Erreur de lecture fichier\n");
        exit(-1);
    }

    fscanf(ifs, "%d", &ordre);
    Graphe *graphe = (Graphe *) malloc(sizeof(Graphe));
    graphe->ordre = ordre;
    graphe->grille = (cellule **) malloc(sizeof(cellule*)*ordre);
    graphe->pCellule = (pCellule *) (cellule *) malloc(ordre * sizeof(cellule));
    for (int i = 0; i < ordre; ++i) {
        graphe->pCellule[i] = (pCellule) malloc( sizeof(pCellule));
    }
    for (int i = 0; i < ordre; ++i) {
        graphe->grille[i] = (cellule *) malloc(sizeof(pCellule) * ordre);
        for (int j = 0; j < ordre; ++j) {
            graphe->grille[i][j];
        }
    }
    // creer les aretes du graphe
    for (int i = 0; i < ordre; ++i) {
        for(int j = 0; j < ordre; ++j){
            int val;
            fscanf(ifs, "%d", &val);
            if(val != 0){
                graphe->pCellule = (pCellule *) CreerArete((pCellule *) graphe->pCellule, i, j);
            }
        }
    }
    return graphe;
}
*/
#include "graphe.h"
Graphe *lire_graphe(char *nomFichier) {

    FILE *ifs = fopen(nomFichier, "r");
    int ordre;

    if (!ifs) {
        printf("Erreur de lecture fichier\n");
        exit(-1);
    }

    fscanf(ifs, "%d", &ordre);

    Graphe *graphe = (Graphe *) malloc(sizeof(Graphe));
    graphe->grille = (cellule **) malloc(sizeof(int*)*ordre);
    graphe->pCellule = (pCellule *) malloc(ordre * sizeof(pCellule));
    for (int i = 0; i < ordre; ++i) {
        graphe->pCellule[i] = (pCellule) malloc( sizeof(pCellule));
    }
    return graphe;
}

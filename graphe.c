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
//// rien a lire dans le fichier texte donc il faut modif le fscanf pour juste creer nous meme
    for(int i = 0; i < ordre; i++) {
        fscanf(ifs, " %c", &graphe->pCellule[i]->id);
        printf("%c ", graphe->pSommet[i]->id);
    }
    printf("\n");
    for (int i = 0; i < ordre; ++i) {
        graphe->matrice[i] = (int*) malloc(sizeof(int)*ordre);
        for (int j = 0; j < ordre; ++j) {
            fscanf(ifs, "%d", &graphe->matrice[i][j]);
            printf("%d ", graphe->matrice[i][j]);
        }
        printf("\n");
    }
    graphe->ordre = ordre;
    // creer les aretes du graphe
    for (int i = 0; i < ordre; ++i) {
        for(int j = 0; j < ordre; ++j){
            int val;
            fscanf(ifs, "%d", &val);
            if(val != 0){
                graphe->pSommet = (pSommet *) CreerArete((pSommet *) graphe->pSommet, i, j, val);
            }
        }
    }
    return graphe;
}

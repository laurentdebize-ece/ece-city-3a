#include "graphe.h"

/*
 int main(){
 Graphe *g = lire_graphe("../ordre.txt");
 return 0;
 */
Graphe *lire_graphe( char *nomFichier){
    FILE *fichierO = fopen(nomFichier, "r");
    FILE *fichierM = fopen("../graphe_projet_ece_city.txt", "w");
    if (fichierO == NULL){
        printf("Erreur lors de l'ouverture du fichier ordre.txt");
        return NULL;
    }
    if (fichierM == NULL){
        printf("Erreur lors de l'ouverture du fichier matrice.txt");
        return NULL;
    }
    int ordre;
    fscanf(fichierO, "%d", &ordre);
    Graphe *graphe = (Graphe*)malloc(sizeof(Graphe));
    graphe->ordre = ordre;

    for (int i = 0; i < LIGNES ; i++){
        for(int j = 0; j < COLONNES; j++){
            graphe->grille[i][j].arc = NULL;
            graphe->grille[i][j].type = 0;
            fprintf(fichierM, "%d", graphe->grille[i][j].type);
        }
        fprintf(fichierM, "\n");
    }
    fclose(fichierO);
    fclose(fichierM);
    return graphe;
}

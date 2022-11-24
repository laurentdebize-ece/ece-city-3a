#include "graphe.h"

/*
int main() {
    Graphe *graphe = (Graphe*)malloc(sizeof(Graphe));
    graphe = lire_graphe(graphe, "../ordre.txt");
    recupdonne(graphe);
    return 0;
}
*/
/*
Graphe *lire_graphe( Graphe *graphe, char *nomFichier){
    FILE *fichierO = fopen(nomFichier, "r");
    FILE *fichierM = fopen("../ordre.txt", "w");
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
    graphe->ordre = ordre;


    for (int i = 0; i < NBCELLULEX ; i++){
        for(int j = 0; j < NBCELLULEY; j++){
            graphe->grille[i][j].arc = NULL;
            graphe->grille[i][j].type = 0;
            //fprintf(fichierM, "%d", graphe->grille[i][j].type);
        }
        // fprintf(fichierM, "\n");
    }


    //ecrire_graphe(graphe, "../matrice.txt");
    fclose(fichierO);
    fclose(fichierM);
    return graphe;
}*/
/*
void ecrire_graphe(Graphe *graphe, char *nomFichier){
    FILE *fichierM = fopen(nomFichier, "w");
    if (fichierM == NULL){
        printf("Erreur lors de l'ouverture du fichier matrice.txt");
        return;
    }
    for (int i = 0; i < NBCELLULEX ; i++){
        for(int j = 0; j < NBCELLULEY; j++){
            fprintf(fichierM, "%d", graphe->grille[i][j].type);
        }
        fprintf(fichierM, "\n");
    }
    fclose(fichierM);
}

void recupdonne(Graphe *graphe){
    int x, y, type;
    printf("coordonnees x : \n");
    scanf("%d", &x);
    printf("coordonnees y : \n");
    scanf("%d", &y);
    printf("type : \n");
    scanf("%d", &type);
    graphe->grille[x][y].type = type;

    ecrire_graphe(graphe, "../matrice.txt");

}
*/

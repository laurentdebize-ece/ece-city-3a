#include "graphe.h"

/*
int main() {
    Graphe *graphe = (Graphe*)malloc(sizeof(Graphe));
    graphe = lire_graphe(graphe, "../ordre.txt");
    recupdonne(graphe);
    return 0;
}

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
}

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

//reseau d'eau
void niveau1Eau(Simcity *simcity){

    for (int x = 0; x < NBCELLULEX; ++x) {
        for (int y = 0; y < NBCELLULEY; ++y) {
            if (simcity->map.mapTile[x][y].typeBloc == TYPE_HERBE){
                al_draw_bitmap_region(*(simcity->map.spriteTile[HERBE].image)
                        , simcity->map.spriteTile[HERBE].spriteX
                        , simcity->map.spriteTile[HERBE].spriteY
                        , simcity->map.spriteTile[HERBE].spriteLargeur
                        , simcity->map.spriteTile[HERBE].spriteHauteur
                        ,simcity->map.mapTile[x][y].coordsXY.screenX
                        ,simcity->map.mapTile[x][y].coordsXY.screenY
                        ,0);
            }
            if (simcity->map.mapTile[x][y].typeEau == 1 ){
                al_draw_bitmap_region(*(simcity->map.spriteTile[EAU_RESEAU].image)
                        , simcity->map.spriteTile[EAU_RESEAU].spriteX
                        , simcity->map.spriteTile[EAU_RESEAU].spriteY
                        , simcity->map.spriteTile[EAU_RESEAU].spriteLargeur
                        , simcity->map.spriteTile[EAU_RESEAU].spriteHauteur
                        ,simcity->map.mapTile[x][y].coordsXY.screenX
                        ,simcity->map.mapTile[x][y].coordsXY.screenY
                        ,0);

            }
        }
    }
}

//reseau d'electricite
void niveau2Elec(Simcity *simcity){
    for (int x = 0; x < NBCELLULEX; ++x) {
        for (int y = 0; y < NBCELLULEY; ++y) {
            if (simcity->map.mapTile[x][y].typeBloc == TYPE_HERBE){
                al_draw_bitmap_region(*(simcity->map.spriteTile[HERBE].image)
                        , simcity->map.spriteTile[HERBE].spriteX
                        , simcity->map.spriteTile[HERBE].spriteY
                        , simcity->map.spriteTile[HERBE].spriteLargeur
                        , simcity->map.spriteTile[HERBE].spriteHauteur
                        ,simcity->map.mapTile[x][y].coordsXY.screenX
                        ,simcity->map.mapTile[x][y].coordsXY.screenY
                        ,0);
            }
            if (simcity->map.mapTile[x][y].typeElec == 1){
                al_draw_bitmap_region(*(simcity->map.spriteTile[ELEC_RESEAU].image)
                        , simcity->map.spriteTile[ELEC_RESEAU].spriteX
                        , simcity->map.spriteTile[ELEC_RESEAU].spriteY
                        , simcity->map.spriteTile[ELEC_RESEAU].spriteLargeur
                        , simcity->map.spriteTile[ELEC_RESEAU].spriteHauteur
                        ,simcity->map.mapTile[x][y].coordsXY.screenX
                        ,simcity->map.mapTile[x][y].coordsXY.screenY
                        ,0);
            }
        }
    }
}

////GRAPHE ////
void *lire_graphe( Simcity *simcity){
    FILE *fichierM = fopen("../Graphe/ordre", "r");
    if (fichierM == NULL){
        printf("Erreur lors de l'ouverture du fichier matrice.txt");
        return NULL;
    }
    int ordre;
    fscanf(fichierM, "%d", &ordre);
    simcity->graphe.ordre = ordre;
    fclose(fichierM);
}

int fileVide(t_file *f) {
    return f->queue == NULL && f->tete == NULL;
}
void enfiler(t_file *f, CaseBFS *caseBFS) {

    pmaillon maillon = NULL;
    maillon = (pmaillon) malloc(sizeof(struct maillon));
    maillon->caseBfs = *caseBFS;
    if (fileVide(f)) {
        f->queue = f->tete = maillon;
    } else {
        f->queue->suiv = maillon;
        f->queue = maillon;
    }
};
CaseBFS defiler(t_file *f) {

    t_maillon *pMaillon = f->tete;

    if (f->queue == pMaillon) {
        f->queue = NULL;
        f->tete = NULL;
    } else {
        f->tete = f->tete->suiv;
    }
    CaseBFS numSommet = pMaillon->caseBfs;
    free(pMaillon);
    return numSommet;
};
void reset_couleur(Simcity *simcity) {
    for (int i = 0; i < NBCELLULEX; i++)
        for(int j = 0; j < NBCELLULEY; j ++)
            simcity->graphe.grille[i][j].couleur = 0 ;
}

//si on pose une nouvelle habitation, on refait le BFS et donc les nouveaux chemins possibles
//on doit donc avant ca clear la liste chainée pour pas avoir de doublons
void clearListeAdj(ListeAdj *liste){
    while(liste->premier != NULL){
        Element *aSupprimer = liste->premier;
        liste->premier = liste->premier->suivant;
        free(aSupprimer);
    }
}
void enfilerVoisin(Simcity *simcity, CaseBFS num, t_file *f){
    //je parcours tous les voisins de la case
    //si le voisin appartient bien au tableau et n'est pas de l'herbe et est marqué en Blanc
    //je l'enfile dans la file
    //je le marque en Gris
    if (num.coordsXy.celluleY-1 > 0 && simcity->graphe.grille[num.coordsXy.celluleX][num.coordsXy.celluleY-1].type != TYPE_HERBE
    && simcity->graphe.grille[num.coordsXy.celluleX][num.coordsXy.celluleY-1].couleur == 0){
        CaseBFS s1;
        s1.coordsXy.celluleX = num.coordsXy.celluleX;
        s1.coordsXy.celluleY = num.coordsXy.celluleY-1;
        if(simcity->graphe.grille[num.coordsXy.celluleX][num.coordsXy.celluleY-1].type == TYPE_POMPIER_DROIT
        || simcity->graphe.grille[num.coordsXy.celluleX][num.coordsXy.celluleY-1].type == TYPE_POMPIER_COTE
        ||simcity->graphe.grille[num.coordsXy.celluleX][num.coordsXy.celluleY-1].type == TYPE_EAU_COTE
        ||simcity->graphe.grille[num.coordsXy.celluleX][num.coordsXy.celluleY-1].type == TYPE_EAU_DROIT
        ||simcity->graphe.grille[num.coordsXy.celluleX][num.coordsXy.celluleY-1].type == TYPE_ELEC_COTE
        ||simcity->graphe.grille[num.coordsXy.celluleX][num.coordsXy.celluleY-1].type == TYPE_ELEC_DROIT){
            s1.distance = num.distance ;
        }else {
            s1.distance = num.distance + 1;
        }
        enfiler(f, &s1);
        simcity->graphe.grille[s1.coordsXy.celluleX][s1.coordsXy.celluleY].couleur = 1;
    }

    if (num.coordsXy.celluleY < NBCELLULEY && simcity->graphe.grille[num.coordsXy.celluleX][num.coordsXy.celluleY+1].type != TYPE_HERBE
    && simcity->graphe.grille[num.coordsXy.celluleX][num.coordsXy.celluleY+1].couleur == 0){
        CaseBFS s1;
        s1.coordsXy.celluleX = num.coordsXy.celluleX;
        s1.coordsXy.celluleY = num.coordsXy.celluleY+1;
        if(simcity->graphe.grille[num.coordsXy.celluleX][num.coordsXy.celluleY-1].type == TYPE_POMPIER_DROIT
           || simcity->graphe.grille[num.coordsXy.celluleX][num.coordsXy.celluleY-1].type == TYPE_POMPIER_COTE
           ||simcity->graphe.grille[num.coordsXy.celluleX][num.coordsXy.celluleY-1].type == TYPE_EAU_COTE
           ||simcity->graphe.grille[num.coordsXy.celluleX][num.coordsXy.celluleY-1].type == TYPE_EAU_DROIT
           ||simcity->graphe.grille[num.coordsXy.celluleX][num.coordsXy.celluleY-1].type == TYPE_ELEC_COTE
           ||simcity->graphe.grille[num.coordsXy.celluleX][num.coordsXy.celluleY-1].type == TYPE_ELEC_DROIT){
            s1.distance = num.distance ;
        }else {
            s1.distance = num.distance + 1;
        }
        enfiler(f, &s1);
        simcity->graphe.grille[s1.coordsXy.celluleX][s1.coordsXy.celluleY].couleur = 1;
    }

    if (num.coordsXy.celluleX-1 > 0 && simcity->graphe.grille[num.coordsXy.celluleX-1][num.coordsXy.celluleY].type != TYPE_HERBE
    && simcity->graphe.grille[num.coordsXy.celluleX-1][num.coordsXy.celluleY].couleur == 0){
        CaseBFS s1;
        s1.coordsXy.celluleX = num.coordsXy.celluleX-1;
        s1.coordsXy.celluleY = num.coordsXy.celluleY;
        if(simcity->graphe.grille[num.coordsXy.celluleX][num.coordsXy.celluleY-1].type == TYPE_POMPIER_DROIT
           || simcity->graphe.grille[num.coordsXy.celluleX][num.coordsXy.celluleY-1].type == TYPE_POMPIER_COTE
           ||simcity->graphe.grille[num.coordsXy.celluleX][num.coordsXy.celluleY-1].type == TYPE_EAU_COTE
           ||simcity->graphe.grille[num.coordsXy.celluleX][num.coordsXy.celluleY-1].type == TYPE_EAU_DROIT
           ||simcity->graphe.grille[num.coordsXy.celluleX][num.coordsXy.celluleY-1].type == TYPE_ELEC_COTE
           ||simcity->graphe.grille[num.coordsXy.celluleX][num.coordsXy.celluleY-1].type == TYPE_ELEC_DROIT){
            s1.distance = num.distance ;
        }else {
            s1.distance = num.distance + 1;
        }
        enfiler(f, &s1);
        simcity->graphe.grille[s1.coordsXy.celluleX][s1.coordsXy.celluleY].couleur = 1;
    }

    if (num.coordsXy.celluleX < NBCELLULEX && simcity->graphe.grille[num.coordsXy.celluleX+1][num.coordsXy.celluleY].type != TYPE_HERBE
    && simcity->graphe.grille[num.coordsXy.celluleX+1][num.coordsXy.celluleY].couleur == 0){
        CaseBFS s1;
        s1.coordsXy.celluleX = num.coordsXy.celluleX+1;
        s1.coordsXy.celluleY = num.coordsXy.celluleY;
        if(simcity->graphe.grille[num.coordsXy.celluleX][num.coordsXy.celluleY-1].type == TYPE_POMPIER_DROIT
             || simcity->graphe.grille[num.coordsXy.celluleX][num.coordsXy.celluleY-1].type == TYPE_POMPIER_COTE
             ||simcity->graphe.grille[num.coordsXy.celluleX][num.coordsXy.celluleY-1].type == TYPE_EAU_COTE
             ||simcity->graphe.grille[num.coordsXy.celluleX][num.coordsXy.celluleY-1].type == TYPE_EAU_DROIT
             ||simcity->graphe.grille[num.coordsXy.celluleX][num.coordsXy.celluleY-1].type == TYPE_ELEC_COTE
             ||simcity->graphe.grille[num.coordsXy.celluleX][num.coordsXy.celluleY-1].type == TYPE_ELEC_DROIT){
            s1.distance = num.distance ;
        }else {
            s1.distance = num.distance + 1;
        }
        enfiler(f, &s1);
        simcity->graphe.grille[s1.coordsXy.celluleX][s1.coordsXy.celluleY].couleur = 1;
    }
}
ListeAdj *initListAdj(){
    ListeAdj *listeAdj = malloc(sizeof(*listeAdj));
    listeAdj->premier = NULL;
    listeAdj->dernier = NULL;
    return listeAdj;
}
void insertionListeAdj(ListeAdj *listeAdj, Habitation *MaMaison, int distance){
    Element *nouveauMaillon = malloc(sizeof(Element));

    nouveauMaillon->MaMaison = MaMaison;
    nouveauMaillon->distanceAMonBatiment = distance;
    nouveauMaillon->suivant = NULL;

    if (listeAdj->premier == NULL){
        listeAdj->premier = nouveauMaillon;
    } else {
        listeAdj->dernier->suivant = nouveauMaillon;
    }
    listeAdj->dernier = nouveauMaillon;
}

//// BFS ////
void BFSEau(Simcity* simcity){
    //je recup l'ordre du graphe
    lire_graphe(simcity);
    // j'init la file
    t_file f ={NULL, NULL};
    // on parcourt tout le tableau de batiments
    for(int i = 0; i < NBR_MAX_INFRA ; ++i){ // remplacer 16 par la macro apres
        //je remets toutes les cases du plateau à Blanc
        reset_couleur(simcity);

        //si dans le tab de Batiments, on trouve un chateau d'eau : typeBatiment = 3
        if (simcity->tabInfrastructure[i].typeBatiment == 3) {
            CaseBFS departS = { .distance = 1, .coordsXy = simcity->tabInfrastructure[i].coordXY[0] };
            //on recup la liste d'adja dans la struct du bat pour lequel on lance le BFS
            ListeAdj* listeAdj = simcity->tabInfrastructure[i].adjacence;
            clearListeAdj(listeAdj);
            //on marque la case en Gris
            simcity->graphe.grille[simcity->tabInfrastructure[i].coordXY->celluleX][simcity->tabInfrastructure[i].coordXY->celluleY].couleur = 1;
            // on enfile dans notre queue la premiere case : s0 est identifié par les coordonnes de la case
            enfiler(&f, &departS);

            //tant que la file n'est pas vide :
            while(f.tete != NULL) {
                // je récupère les coordonnes du premier element de ma file
                CaseBFS num = defiler(&f);

                // si couleur == 2 on ne visite pas
                if (simcity->graphe.grille[num.coordsXy.celluleX][num.coordsXy.celluleY].couleur == 2)
                    continue;

                Cellule celluleActuelle = simcity->graphe.grille[num.coordsXy.celluleX][num.coordsXy.celluleY];
                //printf("coords %d %d %d \n", num.coordsXy.celluleX, num.coordsXy.celluleY, celluleActuelle.type);
                //enum TYPE_BLOC{TYPE_HERBE,TYPE_ROUTE,TYPE_TERRAIN_VAGUE,TYPE_CABANE,TYPE_MAISON,TYPE_IMMEUBLE,TYPE_GRATTE_CIEL, TYPE_ELEC_DROIT, TYPE_ELEC_COTE, TYPE_EAU_DROIT, TYPE_EAU_COTE, TYPE_POMPIER_DROIT, TYPE_POMPIER_COTE, NB_TYPE_BLOC};
                switch(celluleActuelle.type){

                    case TYPE_EAU_COTE :
                    case TYPE_EAU_DROIT :
                    {
                        enfilerVoisin(simcity, num, &f);
                    }
                        break;
                    case TYPE_ROUTE :
                    {
                        simcity->graphe.grille[num.coordsXy.celluleX][num.coordsXy.celluleY].eau = TRUE;
                        simcity->map.mapTile[num.coordsXy.celluleX][num.coordsXy.celluleY].typeEau = TRUE;
                        enfilerVoisin(simcity, num, &f);
                    }
                        break;
                    case TYPE_TERRAIN_VAGUE :
                    case TYPE_CABANE :
                    case TYPE_MAISON :
                    case TYPE_IMMEUBLE :
                    case TYPE_GRATTE_CIEL :
                    {
                        for (int i = 0; i < NBR_MAX_HAB; ++i) {
                            for (int j = 0; j < 8; ++j) {
                                if (simcity->tabHabitation[i].coordXY[j].celluleX == num.coordsXy.celluleX
                                    && simcity->tabHabitation[i].coordXY[j].celluleY == num.coordsXy.celluleY) {
                                    for (int k = 0; k < 8; ++k) {
                                        CoordsXY coords = simcity->tabHabitation[i].coordXY[k];
                                        simcity->graphe.grille[coords.celluleX][coords.celluleY].couleur = 2;
                                    }
                                    insertionListeAdj(listeAdj, &simcity->tabHabitation[i], num.distance);
                                }
                            }
                        }
                    }
                        break;
                }
                //je marque en Noir le sommet que j'ai fini de visiter
                simcity->graphe.grille[num.coordsXy.celluleX][num.coordsXy.celluleY].couleur = 2;
            }

            struct Element *actuel = listeAdj->premier;

            while (actuel != NULL)
            {
                //printf("Habitation %x | Distance %d \n", actuel->MaMaison, actuel->distanceAMonBatiment);
                actuel = actuel->suivant;
            }
        }
    }
    for(int i = 0; i < NBCELLULEX; i++){
        for(int j = 0; j < NBCELLULEY; j++){
            if(simcity->graphe.grille[i][j].eau == TRUE){
                //printf("eau %d %d \n", i, j);
            }
        }
    }
}
void BFSElec(Simcity* simcity){
    //je recup l'ordre du graphe
    lire_graphe(simcity);
    // j'init la file
    t_file f ={NULL, NULL};
    // on parcourt tout le tableau de batiments
    for(int i = 0; i < NBR_MAX_INFRA ; ++i){ // remplacer 16 par la macro apres
        //je remets toutes les cases du plateau à Blanc
        reset_couleur(simcity);

        //si dans le tab de Batiments, on trouve une centrale electrique : typeBatiment = 2
        if (simcity->tabInfrastructure[i].typeBatiment == 2) {
            CaseBFS departS = { .distance = 1, .coordsXy = simcity->tabInfrastructure[i].coordXY[0] };
            //on recup la liste d'adja dans la struct du bat pour lequel on lance le BFS
            ListeAdj* listeAdj = simcity->tabInfrastructure[i].adjacence;
            clearListeAdj(listeAdj);
            //on marque la case en Gris
            simcity->graphe.grille[simcity->tabInfrastructure[i].coordXY->celluleX][simcity->tabInfrastructure[i].coordXY->celluleY].couleur = 1;
            // on enfile dans notre queue la premiere case : s0 est identifié par les coordonnes de la case
            enfiler(&f, &departS);

            //tant que la file n'est pas vide :
            while(f.tete != NULL) {
                // je récupère les coordonnes du premier element de ma file
                CaseBFS num = defiler(&f);

                // si couleur == 2 on ne visite pas
                if (simcity->graphe.grille[num.coordsXy.celluleX][num.coordsXy.celluleY].couleur == 2)
                    continue;

                Cellule celluleActuelle = simcity->graphe.grille[num.coordsXy.celluleX][num.coordsXy.celluleY];
                //printf("coords %d %d %d \n", num.coordsXy.celluleX, num.coordsXy.celluleY, celluleActuelle.type);
                //enum TYPE_BLOC{TYPE_HERBE,TYPE_ROUTE,TYPE_TERRAIN_VAGUE,TYPE_CABANE,TYPE_MAISON,TYPE_IMMEUBLE,TYPE_GRATTE_CIEL, TYPE_ELEC_DROIT, TYPE_ELEC_COTE, TYPE_EAU_DROIT, TYPE_EAU_COTE, TYPE_POMPIER_DROIT, TYPE_POMPIER_COTE, NB_TYPE_BLOC};
                switch(celluleActuelle.type){

                    case TYPE_ELEC_COTE :
                    case TYPE_ELEC_DROIT :
                    {
                        enfilerVoisin(simcity, num, &f);
                    }
                        break;
                    case TYPE_ROUTE :
                    {
                        simcity->graphe.grille[num.coordsXy.celluleX][num.coordsXy.celluleY].elec = TRUE;
                        simcity->map.mapTile[num.coordsXy.celluleX][num.coordsXy.celluleY].typeElec = TRUE;
                        enfilerVoisin(simcity, num, &f);
                    }
                        break;
                    case TYPE_TERRAIN_VAGUE :
                    case TYPE_CABANE :
                    case TYPE_MAISON :
                    case TYPE_IMMEUBLE :
                    case TYPE_GRATTE_CIEL :
                    {
                        for (int i = 0; i < NBR_MAX_HAB; ++i) {
                            for (int j = 0; j < 8; ++j) {
                                if (simcity->tabHabitation[i].coordXY[j].celluleX == num.coordsXy.celluleX
                                    && simcity->tabHabitation[i].coordXY[j].celluleY == num.coordsXy.celluleY) {
                                    for (int k = 0; k < 8; ++k) {
                                        CoordsXY coords = simcity->tabHabitation[i].coordXY[k];
                                        simcity->graphe.grille[coords.celluleX][coords.celluleY].couleur = 2;
                                    }
                                    insertionListeAdj(listeAdj, &simcity->tabHabitation[i], num.distance);
                                }
                            }
                        }
                    }
                        break;
                }
                //je marque en Noir le sommet que j'ai fini de visiter
                simcity->graphe.grille[num.coordsXy.celluleX][num.coordsXy.celluleY].couleur = 2;
            }

            struct Element *actuel = listeAdj->premier;

            while (actuel != NULL)
            {
                //printf("Habitation %x | Distance %d \n", actuel->MaMaison, actuel->distanceAMonBatiment);
                actuel = actuel->suivant;
            }
        }
    }
    for(int i = 0; i < NBCELLULEX; i++){
        for(int j = 0; j < NBCELLULEY; j++){
            if(simcity->graphe.grille[i][j].elec == TRUE){
                //printf("elec %d %d \n", i, j);
            }
        }
    }
}
void BFSPompier(Simcity* simcity){
    //je recup l'ordre du graphe
    lire_graphe(simcity);
    // j'init la file
    t_file f ={NULL, NULL};
    // on parcourt tout le tableau de batiments
    for(int i = 0; i <NBR_MAX_INFRA ; ++i){ // remplacer 16 par la macro apres
        //je remets toutes les cases du plateau à Blanc
        reset_couleur(simcity);

        //si dans le tab de Batiments, on trouve une caserne de pompier : typebatiment = 4
        if (simcity->tabInfrastructure[i].typeBatiment == 4) { /////4
            CaseBFS departS = { .distance = 1, .coordsXy = simcity->tabInfrastructure[i].coordXY[0] };
            //on recup la liste d'adja dans la struct du bat pour lequel on lance le BFS
            ListeAdj* listeAdj = simcity->tabInfrastructure[i].adjacence;
            clearListeAdj(listeAdj);
            //on marque la case en Gris
            simcity->graphe.grille[simcity->tabInfrastructure[i].coordXY->celluleX][simcity->tabInfrastructure[i].coordXY->celluleY].couleur = 1;
            // on enfile dans notre queue la premiere case : s0 est identifié par les coordonnes de la case
            enfiler(&f, &departS);

            //tant que la file n'est pas vide :
            while(f.tete != NULL ) {
                // je récupère les coordonnes du premier element de ma file
                CaseBFS num = defiler(&f);

                // si couleur == 2 on ne visite pas
                if (simcity->graphe.grille[num.coordsXy.celluleX][num.coordsXy.celluleY].couleur == 2)
                    continue;

                Cellule celluleActuelle = simcity->graphe.grille[num.coordsXy.celluleX][num.coordsXy.celluleY];
                //printf("coords %d %d %d \n", num.coordsXy.celluleX, num.coordsXy.celluleY, celluleActuelle.type);
                //enum TYPE_BLOC{TYPE_HERBE,TYPE_ROUTE,TYPE_TERRAIN_VAGUE,TYPE_CABANE,TYPE_MAISON,TYPE_IMMEUBLE,TYPE_GRATTE_CIEL, TYPE_ELEC_DROIT, TYPE_ELEC_COTE, TYPE_EAU_DROIT, TYPE_EAU_COTE, TYPE_POMPIER_DROIT, TYPE_POMPIER_COTE, NB_TYPE_BLOC};
                switch(celluleActuelle.type){

                    case TYPE_POMPIER_COTE :
                    case TYPE_POMPIER_DROIT :
                    {
                        enfilerVoisin(simcity, num, &f);
                    }
                        break;
                    case TYPE_ROUTE :
                    {
                        simcity->graphe.grille[num.coordsXy.celluleX][num.coordsXy.celluleY].elec = TRUE;
                        simcity->map.mapTile[num.coordsXy.celluleX][num.coordsXy.celluleY].typeElec = TRUE;
                        enfilerVoisin(simcity, num, &f);
                    }
                        break;
                    case TYPE_TERRAIN_VAGUE :
                    case TYPE_CABANE :
                    case TYPE_MAISON :
                    case TYPE_IMMEUBLE :
                    case TYPE_GRATTE_CIEL :
                    {
                        for (int i = 0; i < NBR_MAX_HAB; ++i) {
                            for (int j = 0; j < 8; ++j) {
                                if (simcity->tabHabitation[i].coordXY[j].celluleX == num.coordsXy.celluleX
                                    && simcity->tabHabitation[i].coordXY[j].celluleY == num.coordsXy.celluleY) {
                                    for (int k = 0; k < 8; ++k) {
                                        CoordsXY coords = simcity->tabHabitation[i].coordXY[k];
                                        simcity->graphe.grille[coords.celluleX][coords.celluleY].couleur = 2;
                                    }
                                    insertionListeAdj(listeAdj, &simcity->tabHabitation[i], num.distance);
                                }
                            }
                        }
                    }
                        break;
                }
                //je marque en Noir le sommet que j'ai fini de visiter
                simcity->graphe.grille[num.coordsXy.celluleX][num.coordsXy.celluleY].couleur = 2;
            }

            struct Element *actuel = listeAdj->premier;

            while (actuel != NULL)
            {
                printf("Habitation %x | Distance %d \n", actuel->MaMaison, actuel->distanceAMonBatiment);

                if (actuel->distanceAMonBatiment > 20 && actuel->MaMaison->isFeu == TRUE) {
                    actuel->MaMaison->isFeu = TRUE;
                    actuel->MaMaison->isFeuRuine = TRUE;
                    //printf("L'habitation %d ne peut pas etre sauvee car elle se trouve a une distance de %d de la caserne \n", actuel->MaMaison, actuel->distanceAMonBatiment);
                }
                if (actuel->distanceAMonBatiment < 20 && actuel->MaMaison->isFeu == TRUE) {
                    actuel->MaMaison->isFeu = FALSE;
                    //printf("L'habitation %d va etre sauvee car elle se trouve a une distance de %d de la caserne \n", actuel->MaMaison, actuel->distanceAMonBatiment);
                }
                actuel = actuel->suivant;
            }
        }
    }
}


void calculCapaciteElec(Simcity* simcity){
    for(int i = 0; i < NBR_MAX_INFRA ; ++i){
        if (simcity->tabInfrastructure[i].typeBatiment == 2) {
            ListeAdj* listeAdj = simcity->tabInfrastructure[i].adjacence;
            struct Element *actuel = listeAdj->premier;
            while (actuel != NULL)
            {
              //  actuel->MaMaison->capaciteElec += 100;
                actuel = actuel->suivant;
            }
        }
    }
}
void calculCapaciteEau(Simcity* simcity){
    for(int i = 0; i < NBR_MAX_INFRA ; ++i){
        if (simcity->tabInfrastructure[i].typeBatiment == 3) {
            ListeAdj* listeAdj = simcity->tabInfrastructure[i].adjacence;
            struct Element *actuel = listeAdj->premier;
            while (actuel != NULL)
            {
               // actuel->MaMaison->capaciteEau += 100;
                actuel = actuel->suivant;
            }
        }
    }
}


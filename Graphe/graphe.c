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
    partiellementAlimenteEau(simcity);
    for (int x = 0; x < NBCELLULEX; ++x) {
        for (int y = 0; y < NBCELLULEY; ++y) {
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
    for (int i = 0; i < simcity->nbHabitations; ++i) {
        for (int j = 0; j < NBR_COORDS_XY_HAB; ++j) {
            if (simcity->interactionExterieure.mouse.celluleXY.celluleX == simcity->tabHabitation[i].coordXY[j].celluleX && simcity->interactionExterieure.mouse.celluleXY.celluleY == simcity->tabHabitation[i].coordXY[j].celluleY){
                al_draw_textf(simcity->allegro.fonts[1], simcity->allegro.color[WHITE], 2, 400, 0, "Hab n??%d", i + 1);
                al_draw_textf(simcity->allegro.fonts[1], simcity->allegro.color[WHITE], 2, 430, 0, "Hab : %d", simcity->tabHabitation[i].nbHabitants);
                al_draw_textf(simcity->allegro.fonts[1], simcity->allegro.color[WHITE], 2, 460, 0, "Eau : %d", simcity->tabHabitation[i].capaciteEauRecu);
            }
        }
        if (simcity->tabHabitation[i].partiellementEau == true){
            al_draw_rectangle(simcity->tabHabitation[i].coordXY[0].screenX,simcity->tabHabitation[i].coordXY[0].screenY,simcity->tabHabitation[i].coordXY[0].screenX+ 60, simcity->tabHabitation[i].coordXY[0].screenY + 60,
                              al_map_rgb(255,0,0), 3);
        }
    }
    for (int i = 0; i < simcity->nbInfrastructures; ++i) {
        for (int j = 0; j < NBR_COORDS_XY_INFRA; ++j) {
            if (simcity->interactionExterieure.mouse.celluleXY.celluleX == simcity->tabInfrastructure[i].coordXY[j].celluleX && simcity->interactionExterieure.mouse.celluleXY.celluleY == simcity->tabInfrastructure[i].coordXY[j].celluleY && simcity->tabInfrastructure[i].typeBatiment == 3){
                al_draw_textf(simcity->allegro.fonts[1], simcity->allegro.color[WHITE], 2, 400, 0, "Infra n??%d", i + 1);
                al_draw_textf(simcity->allegro.fonts[1], simcity->allegro.color[WHITE], 2, 430, 0, "Reste Eau: %d", (simcity->tabInfrastructure[i].capaciteEauMax - simcity->tabInfrastructure[i].capaciteEauDonne));
                for(int i = 0; i < simcity->nbHabitations; i++) {
                    if (simcity->tabHabitation[i].capaciteEauRecu != 0) {
                        al_draw_textf(simcity->allegro.fonts[1], simcity->allegro.color[WHITE], 2, 460 + i * 20, 0,
                                      "Hab : %d, eau : %d ", i, simcity->tabHabitation[i].capaciteEauRecu);
                    }
                }
            }
        }
    }

}

//reseau d'electricite
void niveau2Elec(Simcity *simcity){
    partiellementAlimenteElec(simcity);
    for (int x = 0; x < NBCELLULEX; ++x) {
        for (int y = 0; y < NBCELLULEY; ++y) {
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
    for (int i = 0; i < simcity->nbHabitations; ++i) {
        for (int j = 0; j < NBR_COORDS_XY_HAB; ++j) {
            if (simcity->interactionExterieure.mouse.celluleXY.celluleX == simcity->tabHabitation[i].coordXY[j].celluleX && simcity->interactionExterieure.mouse.celluleXY.celluleY == simcity->tabHabitation[i].coordXY[j].celluleY){
                al_draw_textf(simcity->allegro.fonts[1], simcity->allegro.color[WHITE], 2, 400, 0, "Hab n??%d", i + 1);
                al_draw_textf(simcity->allegro.fonts[1], simcity->allegro.color[WHITE], 2, 430, 0, "Hab : %d", simcity->tabHabitation[i].nbHabitants);
                al_draw_textf(simcity->allegro.fonts[1], simcity->allegro.color[WHITE], 2, 460, 0, "Elec : %d",simcity->tabHabitation[i].capaciteElectriqueRecu);
            }
        }
        if (simcity->tabHabitation[i].partiellementElec == true){
            al_draw_rectangle(simcity->tabHabitation[i].coordXY[0].screenX,simcity->tabHabitation[i].coordXY[0].screenY,simcity->tabHabitation[i].coordXY[0].screenX+ 60, simcity->tabHabitation[i].coordXY[0].screenY + 60,
                              al_map_rgb(255,0,0), 3);
        }
    }
    for (int i = 0; i < simcity->nbInfrastructures; ++i) {
        for (int j = 0; j < NBR_COORDS_XY_INFRA; ++j) {
            if (simcity->interactionExterieure.mouse.celluleXY.celluleX == simcity->tabInfrastructure[i].coordXY[j].celluleX && simcity->interactionExterieure.mouse.celluleXY.celluleY == simcity->tabInfrastructure[i].coordXY[j].celluleY && simcity->tabInfrastructure[i].typeBatiment == 2){
                al_draw_textf(simcity->allegro.fonts[1], simcity->allegro.color[WHITE], 2, 400, 0, "Infra n??%d", i + 1);
                al_draw_textf(simcity->allegro.fonts[1], simcity->allegro.color[WHITE], 2, 430, 0, "Reste Elec: %d", (simcity->tabInfrastructure[i].capaciteElectriqueMax - simcity->tabInfrastructure[i].capaciteElectriqueDonne));
                for(int i = 0; i < simcity->nbHabitations; i++) {
                    if (simcity->tabHabitation[i].capaciteElectriqueRecu != 0) {
                        al_draw_textf(simcity->allegro.fonts[1], simcity->allegro.color[WHITE], 2, 460 + i * 20, 0,
                                      "Hab : %d, elec : %d ", i, simcity->tabHabitation[i].capaciteElectriqueRecu);
                    }
                }
            }
        }
    }

}
//reseau de pompier
void niveau3Pompier(Simcity *simcity){

    for (int x = 0; x < NBCELLULEX; ++x) {
        for (int y = 0; y < NBCELLULEY; ++y) {
            if (simcity->map.mapTile[x][y].typePompier == 1){
                al_draw_bitmap_region(*(simcity->map.spriteTile[POMPIER_RESEAU].image)
                        , simcity->map.spriteTile[POMPIER_RESEAU].spriteX
                        , simcity->map.spriteTile[POMPIER_RESEAU].spriteY
                        , simcity->map.spriteTile[POMPIER_RESEAU].spriteLargeur
                        , simcity->map.spriteTile[POMPIER_RESEAU].spriteHauteur
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
//on doit donc avant ca clear la liste chain??e pour pas avoir de doublons
void clearListeAdj(ListeAdj *liste){
    while(liste->premier != NULL){
        Element *aSupprimer = liste->premier;
        liste->premier = liste->premier->suivant;
        free(aSupprimer);
    }
}
void enfilerVoisin(Simcity *simcity, CaseBFS num, t_file *f){
    //je parcours tous les voisins de la case
    //si le voisin appartient bien au tableau et n'est pas de l'herbe et est marqu?? en Blanc
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
        //je remets toutes les cases du plateau ?? Blanc
        reset_couleur(simcity);

        //si dans le tab de Batiments, on trouve un chateau d'eau : typeBatiment = 3
        if (simcity->tabInfrastructure[i].typeBatiment == 3) {
            CaseBFS departS = { .distance = 1, .coordsXy = simcity->tabInfrastructure[i].coordXY[0] };
            //on recup la liste d'adja dans la struct du bat pour lequel on lance le BFS
            ListeAdj* listeAdj = simcity->tabInfrastructure[i].adjacence;
            clearListeAdj(listeAdj);
            //on marque la case en Gris
            simcity->graphe.grille[simcity->tabInfrastructure[i].coordXY->celluleX][simcity->tabInfrastructure[i].coordXY->celluleY].couleur = 1;
            // on enfile dans notre queue la premiere case : s0 est identifi?? par les coordonnes de la case
            enfiler(&f, &departS);

            //tant que la file n'est pas vide :
            while(f.tete != NULL) {
                // je r??cup??re les coordonnes du premier element de ma file
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
                //printf("Chateau eau %d Habitation %x | Distance %d \n",i, actuel->MaMaison, actuel->distanceAMonBatiment);
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
        //je remets toutes les cases du plateau ?? Blanc
        reset_couleur(simcity);

        //si dans le tab de Batiments, on trouve une centrale electrique : typeBatiment = 2
        if (simcity->tabInfrastructure[i].typeBatiment == 2) {
            CaseBFS departS = { .distance = 1, .coordsXy = simcity->tabInfrastructure[i].coordXY[0] };
            //on recup la liste d'adja dans la struct du bat pour lequel on lance le BFS
            ListeAdj* listeAdj = simcity->tabInfrastructure[i].adjacence;
            clearListeAdj(listeAdj);
            //on marque la case en Gris
            simcity->graphe.grille[simcity->tabInfrastructure[i].coordXY->celluleX][simcity->tabInfrastructure[i].coordXY->celluleY].couleur = 1;
            // on enfile dans notre queue la premiere case : s0 est identifi?? par les coordonnes de la case
            enfiler(&f, &departS);

            //tant que la file n'est pas vide :
            while(f.tete != NULL) {
                // je r??cup??re les coordonnes du premier element de ma file
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
        //je remets toutes les cases du plateau ?? Blanc
        reset_couleur(simcity);

        //si dans le tab de Batiments, on trouve une caserne de pompier : typebatiment = 4
        if (simcity->tabInfrastructure[i].typeBatiment == 4) { /////4

            CaseBFS departS = { .distance = 1, .coordsXy = simcity->tabInfrastructure[i].coordXY[0] };
            //on recup la liste d'adja dans la struct du b??timent pour lequel on lance le BFS
            ListeAdj* listeAdj = simcity->tabInfrastructure[i].adjacence;
            clearListeAdj(listeAdj);
            //on marque la case en Gris
            simcity->graphe.grille[simcity->tabInfrastructure[i].coordXY->celluleX][simcity->tabInfrastructure[i].coordXY->celluleY].couleur = 1;
            // on enfile dans notre queue la premiere case : s0 est identifi?? par les coordonnes de la case
            enfiler(&f, &departS);

            //tant que la file n'est pas vide :
            while(f.tete != NULL ) {
                // je r??cup??re les coordonnes du premier element de ma file
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
                        if(num.distance < 20){
                            simcity->graphe.grille[num.coordsXy.celluleX][num.coordsXy.celluleY].pompier = TRUE;
                            simcity->map.mapTile[num.coordsXy.celluleX][num.coordsXy.celluleY].typePompier = TRUE;
                        }
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
                                    if(num.distance < CAPACITE_POMPIER){
                                        insertionListeAdj(listeAdj, &simcity->tabHabitation[i], num.distance);
                                        simcity->tabHabitation[i].pompier = TRUE;
                                    }
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
/*
                while (actuel != NULL)
                {
                    //printf("Habitation %x | Distance %d \n", actuel->MaMaison, actuel->distanceAMonBatiment);

                    if (actuel->distanceAMonBatiment > 20 && actuel->MaMaison->isFeu == TRUE) {
                        actuel->MaMaison->isFeuRuine = TRUE;
                        //printf("L'habitation %d ne peut pas etre sauvee car elle se trouve a une distance de %d de la caserne \n", actuel->MaMaison, actuel->distanceAMonBatiment);
                    }
                    if (actuel->distanceAMonBatiment < 20 && actuel->MaMaison->isFeu == TRUE) {
                        actuel->MaMaison->isFeu = FALSE;
                        //printf("L'habitation %d va etre sauvee car elle se trouve a une distance de %d de la caserne \n", actuel->MaMaison, actuel->distanceAMonBatiment);
                    }
                    actuel = actuel->suivant;
                }
*/
        }

    }

}

void partiellementAlimenteEau(Simcity* simcity){
    for (int i = 0; i < simcity->nbHabitations; ++i) { // parcours les habitation
        if (simcity->tabHabitation[i].capaciteEauMax == simcity->tabHabitation[i].capaciteEauRecu){ // si la capacite d'eau est max
            simcity->tabHabitation[i].partiellementEau = false; // pas de carence en eau
        }else{
            simcity->tabHabitation[i].partiellementEau = true; // habitation est en carence en Eau
        }
    }
}

void partiellementAlimenteElec(Simcity* simcity){
    for (int i = 0; i < simcity->nbHabitations; ++i) { // parcours les habs
        if (simcity->tabHabitation[i].capaciteElectriqueMax == simcity->tabHabitation[i].capaciteElectriqueRecu){ // si la capacite d'electricite est max
            simcity->tabHabitation[i].partiellementElec = false;// pas de carence d'electricite
        } else{
            simcity->tabHabitation[i].partiellementElec = true;// habitation est en carence d'Electricite
        }
    }
}

void calculCapaTotEau(Simcity* simcity){ // permet de savoir la capacite totale utilise de l'eau
    for (int i = 0; i < simcity->nbInfrastructures; ++i) {
        if (simcity->tabInfrastructure[i].typeBatiment == 3){
            simcity->capaciteTotEauUtilise += simcity->tabInfrastructure[i].capaciteEauDonne;
        }
    }
}

void calculCapaTotElec(Simcity* simcity){// permet de savoir la capacite totale utilise de l'electricite
    for (int i = 0; i < simcity->nbInfrastructures; ++i) {
        if (simcity->tabInfrastructure[i].typeBatiment == 2){
            simcity->capaciteTotElecUtilise += simcity->tabInfrastructure[i].capaciteElectriqueDonne;
        }
    }
}

void calculCapaciteEau(Simcity* simcity){

    for (int i = 0; i < simcity->nbInfrastructures; ++i) {
        if (simcity->tabInfrastructure[i].typeBatiment == 3) { //si on a un chateau d'eau
            simcity->capaciteTotEauUtilise = 0;
            while(simcity->tabInfrastructure[i].adjacence->premier != NULL) { //tant que la liste n'est pas vide
                if (simcity->tabInfrastructure[i].adjacence->premier->MaMaison->typeBatiment < 4 ){ // verifie que ce n'est pas un gratte ciel ni une ruine
                    if (simcity->tabInfrastructure[i].capaciteEauDonne < CAPACITE_EAU && (simcity->tabInfrastructure[i].capaciteEauMax - simcity->tabInfrastructure[i].capaciteEauDonne) >= simcity->tabInfrastructure[i].adjacence->premier->MaMaison->capaciteEauMax) { //si le chateau peut donner plus eau que ce qu'il manque ?? l'habitation
                        simcity->tabInfrastructure[i].capaciteEauDonne += (simcity->tabInfrastructure[i].adjacence->premier->MaMaison->capaciteEauMax - simcity->tabInfrastructure[i].adjacence->premier->MaMaison->capaciteEauRecu);
                        simcity->tabInfrastructure[i].adjacence->premier->MaMaison->capaciteEauRecu += (simcity->tabInfrastructure[i].adjacence->premier->MaMaison->capaciteEauMax - simcity->tabInfrastructure[i].adjacence->premier->MaMaison->capaciteEauRecu);

                    }//si la centrale ne peut pas donner plus d'electricit?? que ce qu'il manque ?? l'habitation
                    else if (simcity->tabInfrastructure[i].capaciteEauDonne < CAPACITE_EAU && (simcity->tabInfrastructure[i].capaciteEauMax - simcity->tabInfrastructure[i].capaciteEauDonne) <= (simcity->tabInfrastructure[i].adjacence->premier->MaMaison->capaciteEauMax - simcity->tabInfrastructure[i].adjacence->premier->MaMaison->capaciteEauRecu) && (simcity->tabInfrastructure[i].adjacence->premier->MaMaison->capaciteEauMax - simcity->tabInfrastructure[i].adjacence->premier->MaMaison->capaciteEauRecu) > 0) {
                        simcity->tabInfrastructure[i].adjacence->premier->MaMaison->capaciteEauRecu += (simcity->tabInfrastructure[i].capaciteEauMax - simcity->tabInfrastructure[i].capaciteEauDonne);
                        simcity->tabInfrastructure[i].capaciteEauDonne += (simcity->tabInfrastructure[i].capaciteEauMax - simcity->tabInfrastructure[i].capaciteEauDonne);
                    }

                    if(simcity->tabInfrastructure[i].adjacence->premier->MaMaison->capaciteEauRecu == simcity->tabInfrastructure[i].adjacence->premier->MaMaison->capaciteEauMax){
                        simcity->tabInfrastructure[i].adjacence->premier->MaMaison->eauMax = TRUE;
                    }

                    simcity->tabInfrastructure[i].adjacence->premier = simcity->tabInfrastructure[i].adjacence->premier->suivant; //on regarde la suivante
                }

            }
            calculCapaTotEau(simcity);
        }
    }
}

void calculCapaciteElec(Simcity* simcity){

    for (int i = 0; i < simcity->nbInfrastructures; ++i) {
        if (simcity->tabInfrastructure[i].typeBatiment == 2) { //si on a un chateau d'eau
            simcity->capaciteTotElecUtilise = 0;
            while(simcity->tabInfrastructure[i].adjacence->premier != NULL) { //tant que la liste n'est pas vide

                if (simcity->tabInfrastructure[i].capaciteElectriqueDonne < CAPACITE_ELECTRIQUE && (simcity->tabInfrastructure[i].capaciteElectriqueMax - simcity->tabInfrastructure[i].capaciteElectriqueDonne) >= simcity->tabInfrastructure[i].adjacence->premier->MaMaison->capaciteElectriqueMax){ //si le chateau peut donner plus eau que ce qu'il manque ?? l'habitation
                    simcity->tabInfrastructure[i].capaciteElectriqueDonne += (simcity->tabInfrastructure[i].adjacence->premier->MaMaison->capaciteElectriqueMax - simcity->tabInfrastructure[i].adjacence->premier->MaMaison->capaciteElectriqueRecu);
                    simcity->tabInfrastructure[i].adjacence->premier->MaMaison->capaciteElectriqueRecu += (simcity->tabInfrastructure[i].adjacence->premier->MaMaison->capaciteElectriqueMax - simcity->tabInfrastructure[i].adjacence->premier->MaMaison->capaciteElectriqueRecu);
                }
                else if (simcity->tabInfrastructure[i].capaciteEauDonne < CAPACITE_ELECTRIQUE && (simcity->tabInfrastructure[i].capaciteElectriqueMax - simcity->tabInfrastructure[i].capaciteElectriqueDonne) >= (simcity->tabInfrastructure[i].adjacence->premier->MaMaison->capaciteElectriqueMax - simcity->tabInfrastructure[i].adjacence->premier->MaMaison->capaciteElectriqueRecu) && (simcity->tabInfrastructure[i].adjacence->premier->MaMaison->capaciteElectriqueMax - simcity->tabInfrastructure[i].adjacence->premier->MaMaison->capaciteElectriqueRecu) > 0) { //si la centrale ne peut pas donner plus d'electricit?? que ce qu'il manque ?? l'habitation
                    simcity->tabInfrastructure[i].capaciteElectriqueDonne += (simcity->tabInfrastructure[i].adjacence->premier->MaMaison->capaciteElectriqueMax - simcity->tabInfrastructure[i].adjacence->premier->MaMaison->capaciteElectriqueRecu);
                    simcity->tabInfrastructure[i].adjacence->premier->MaMaison->capaciteElectriqueRecu += (simcity->tabInfrastructure[i].adjacence->premier->MaMaison->capaciteElectriqueMax - simcity->tabInfrastructure[i].adjacence->premier->MaMaison->capaciteElectriqueRecu);
                }

                if(simcity->tabInfrastructure[i].adjacence->premier->MaMaison->capaciteElectriqueRecu == simcity->tabInfrastructure[i].adjacence->premier->MaMaison->capaciteElectriqueMax){
                    simcity->tabInfrastructure[i].adjacence->premier->MaMaison->elecMax = TRUE;
                }
                simcity->tabInfrastructure[i].adjacence->premier = simcity->tabInfrastructure[i].adjacence->premier->suivant; //on regarde la suivante

            }
            calculCapaTotElec(simcity);
        }
    }
}


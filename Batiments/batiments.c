#include "batiments.h"

void initTabBatiments(Simcity* simcity) {
    for (int i = 0; i < NBR_MAX_BAT; ++i) {
        simcity->tabBatiments[i].typeBatiment = 0;
        simcity->tabBatiments[i].compteurEvolution = 0;
        simcity->tabBatiments[i].timerCree = 0;
        simcity->tabBatiments[i].dateCreation = -1;
        simcity->tabBatiments[i].timerBatiment = 0;
        simcity->tabBatiments[i].nbHabitants = 0;
        simcity->tabBatiments[i].capaciteElectrique = 0;
        simcity->tabBatiments[i].capaciteEau = 0;;
    }
    simcity->nbBatiments = 0;
}


void construireBatiment(Simcity* simcity) {
    if(simcity->banque.achatTerrainVague == 1) {
        simcity->tabBatiments[simcity->nbBatiments].typeBatiment = 1;
    }
    if(simcity->banque.achatElectricite == 1) {
        simcity->tabBatiments[simcity->nbBatiments].typeBatiment = 2;
        simcity->tabBatiments[simcity->nbBatiments].capaciteElectrique = CAPACITE_ELECTRIQUE;
    }
    if(simcity->banque.achatChateauEau == 1) {
        simcity->tabBatiments[simcity->nbBatiments].typeBatiment = 3;
        simcity->tabBatiments[simcity->nbBatiments].capaciteEau = CAPACITE_EAU;
    }
    simcity->tabBatiments[simcity->nbBatiments].dateCreation = (int) al_get_timer_count(simcity->allegro.chrono);
    if(simcity->tabBatiments[simcity->nbBatiments].dateCreation != -1) {
        simcity->tabBatiments[simcity->nbBatiments].timerCree = TRUE;
    } else {printf("ERREUR lancement timer batiment.\n");}
    simcity->nbBatiments++;
}

void nombreHabitantsTot(Simcity* simcity) {
    int nbHabitantsTot = 0;
    for (int i = 0; i < simcity->nbBatiments; ++i) {
        nbHabitantsTot += simcity->tabBatiments[i].nbHabitants;
    }
    simcity->nbHabitants = nbHabitantsTot;
}


void afficherNbHabitantsTot(Simcity simcity) {
    al_draw_textf(simcity.allegro.fonts[0], simcity.allegro.color[BLACK], 250, 725, 0, "%d",simcity.nbHabitants);
}
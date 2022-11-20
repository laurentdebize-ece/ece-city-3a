#include "batiments.h"

void initTabBatiments(Simcity* simcity) {
    for (int i = 0; i < NB_MAX_BATIMENTS; ++i) {
        simcity->tabBatiments[i].typeBatiment = 0;
        simcity->tabBatiments[i].compteurEvolution = 0;
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
    simcity->nbBatiments++;
}
/*
void evolutionBatiment(Simcity* simcity) {
    if(simcity->batiment.achatTerrainVague == 1) {
        if (simcity->batiment.compteurEvolution < 6){
            simcity->batiment.compteurEvolution++;
        }
        switch (simcity->batiment.compteurEvolution++) {
            case 1: //terrain vague
                simcity->batiment.nbHabitants = NB_HABITANTS_TERRAINVAGUE;
                break;
            case 2: //cabane
                simcity->batiment.nbHabitants = NB_HABITANTS_CABANE;
                break;
            case 3: //maison
                simcity->batiment.nbHabitants = NB_HABITANTS_MAISON;
                break;
            case 4: //immeuble
                simcity->batiment.nbHabitants = NB_HABITANTS_IMMEUBLE;
                break;
            case 5: //gratteciel
                simcity->batiment.nbHabitants = NB_HABITANTS_GRATTECIEL;
                break;
            case 6: //ruine
                simcity->batiment.nbHabitants = NB_HABITANTS_RUINE;
                break;
            default:
                printf("ERREUR evolution batiment.\n");
        }
    }
    afficherBatiment(simcity);
}
*/


void afficherNbHabitantsTot(Simcity simcity) {
    al_draw_textf(simcity.allegro.fonts[0], simcity.allegro.color[BLACK], 225, 725, 0, "%d",simcity.nbHabitant);
}
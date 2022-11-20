#include "batiments.h"

/*
void construireBatiment(Simcity* simcity) {
    simcity->nbBatiments++;
    simcity->batiment[simcity->nbBatiments].compteurEvolution = 0;
    simcity->batiment[simcity->nbBatiments].timerBatiment = 0;
    simcity->batiment[simcity->nbBatiments].nbHabitants = 0;
    simcity->batiment[simcity->nbBatiments].capaciteElectrique = 0;
    simcity->batiment[simcity->nbBatiments].capaciteEau = 0;
    if(simcity->batiment[simcity->nbBatiments].achatElectricite == 1) {
        simcity->batiment[simcity->nbBatiments].capaciteElectrique = CAPACITE_ELECTRIQUE;
    }
    if(simcity->batiment[simcity->nbBatiments].achatChateauEau == 1) {
        simcity->batiment[simcity->nbBatiments].capaciteEau = CAPACITE_EAU;
    }
    afficherBatiment(simcity);
}
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
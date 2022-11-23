#include "batiments.h"

void initTabBatiments(Simcity* simcity) {
    for (int i = 0; i < NBR_MAX_BAT; ++i) {
        simcity->tabHabitation[i].typeBatiment = 0;
        simcity->tabHabitation[i].compteurEvolution = 0;
        simcity->tabHabitation[i].timerCree = 0;
        simcity->tabHabitation[i].dateCreation = -1;
        simcity->tabHabitation[i].timerBatiment = 0;
        simcity->tabHabitation[i].nbHabitants = 0;
        simcity->tabHabitation[i].capaciteElectrique = 0;
        simcity->tabHabitation[i].capaciteEau = 0;
        for (int j = 0; j < NBR_MAX_BAT; ++j) {
            simcity->tabHabitation->coordXY[j].celluleX = 0;
            simcity->tabHabitation->coordXY[j].celluleY = 0;
        }
    }
    simcity->nbHabititations = 0;
}


void construireHabitation(Simcity* simcity) {
    if(simcity->banque.achatTerrainVague == 1) {
        simcity->tabHabitation[simcity->nbHabititations].typeBatiment = 1;
        simcity->tabHabitation[simcity->nbHabititations].coordXY[0].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX;
        simcity->tabHabitation[simcity->nbHabititations].coordXY[0].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY;
        
        simcity->tabHabitation[simcity->nbHabititations].coordXY[1].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX + 1;
        simcity->tabHabitation[simcity->nbHabititations].coordXY[1].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY;

        simcity->tabHabitation[simcity->nbHabititations].coordXY[2].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX + 2;
        simcity->tabHabitation[simcity->nbHabititations].coordXY[2].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY;

        simcity->tabHabitation[simcity->nbHabititations].coordXY[3].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX;
        simcity->tabHabitation[simcity->nbHabititations].coordXY[3].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY + 1;

        simcity->tabHabitation[simcity->nbHabititations].coordXY[4].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX + 2;
        simcity->tabHabitation[simcity->nbHabititations].coordXY[4].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY + 1;

        simcity->tabHabitation[simcity->nbHabititations].coordXY[5].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX ;
        simcity->tabHabitation[simcity->nbHabititations].coordXY[5].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY + 2;

        simcity->tabHabitation[simcity->nbHabititations].coordXY[6].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX + 1;
        simcity->tabHabitation[simcity->nbHabititations].coordXY[6].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY + 2;

        simcity->tabHabitation[simcity->nbHabititations].coordXY[7].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX + 2;
        simcity->tabHabitation[simcity->nbHabititations].coordXY[7].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY + 2;

        simcity->tabHabitation[simcity->nbHabititations].dateCreation = (int) al_get_timer_count(simcity->allegro.chrono);

    }
    if(simcity->tabHabitation[simcity->nbHabititations].dateCreation != -1) {
        simcity->tabHabitation[simcity->nbHabititations].timerCree = TRUE;
    } else {printf("ERREUR lancement timer batiment.\n");}
    simcity->nbHabititations++;
}

void construireInfrastructure(Simcity* simcity){
    if(simcity->banque.achatElectricite == 1) {
        simcity->tabInfrastructure[simcity->nbInfrastructures].typeBatiment = 2;
        simcity->tabInfrastructure[simcity->nbInfrastructures].capaciteElectrique = CAPACITE_ELECTRIQUE;

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[0].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[0].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY;

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[1].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX + 1;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[1].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY;

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[2].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX + 2;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[2].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY;

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[3].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX + 3;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[3].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY;

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[4].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[4].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY + 1;

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[5].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX + 3;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[5].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY + 1;

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[6].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[6].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY + 2;

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[7].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX + 3;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[7].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY + 2;

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[8].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[8].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY + 3;

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[9].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX + 3;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[9].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY + 3;

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[10].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX + 3;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[10].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY + 3;

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[11].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX + 3;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[11].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY + 3;

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[12].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX + 3;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[12].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY + 3;

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[13].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX + 3;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[13].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY + 3;

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[14].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX + 3;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[14].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY + 3;

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[15].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX + 3;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[15].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY + 3;







    }
    if(simcity->banque.achatChateauEau == 1) {
        simcity->tabInfrastructure[simcity->nbInfrastructures].typeBatiment = 3;
        simcity->tabInfrastructure[simcity->nbInfrastructures].capaciteEau = CAPACITE_EAU;
    }
}

void nombreHabitantsTot(Simcity* simcity) {
    int nbHabitantsTot = 0;
    for (int i = 0; i < simcity->nbHabititations; ++i) {
        nbHabitantsTot += simcity->tabHabitation[i].nbHabitants;
    }
    simcity->nbHabitants = nbHabitantsTot;
}


void afficherNbHabitantsTot(Simcity simcity) {
    al_draw_textf(simcity.allegro.fonts[0], simcity.allegro.color[BLACK], 250, 725, 0, "%d",simcity.nbHabitants);
}
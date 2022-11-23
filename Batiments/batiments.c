#include "batiments.h"

void initTabBatiments(Simcity* simcity) {
    for (int i = 0; i < NBR_MAX_BAT; ++i) {
        simcity->tabBatiments[i].typeBatiment = 0;
        simcity->tabBatiments[i].compteurEvolution = 0;
        simcity->tabBatiments[i].evolutionPossible = TRUE;
        simcity->tabBatiments[i].timerCree = 0;
        simcity->tabBatiments[i].dateCreation = -1;
        simcity->tabBatiments[i].timerBatiment = 0;
        simcity->tabBatiments[i].nbHabitants = 0;
        simcity->tabBatiments[i].capaciteElectrique = 0;
        simcity->tabBatiments[i].capaciteEau = 0;
        simcity->tabBatiments->coordXY.celluleX = 0;
        simcity->tabBatiments->coordXY.celluleY = 0;
    }
    simcity->nbBatiments = 0;
}


void construireBatiment(Simcity* simcity) {
    if(simcity->banque.achatTerrainVague == 1) {
        simcity->tabBatiments[simcity->nbBatiments].typeBatiment = 1;
        simcity->tabBatiments[simcity->nbBatiments].coordXY.celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX;
        simcity->tabBatiments[simcity->nbBatiments].coordXY.celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY;
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

void miseAJourDonneesBatiment(Simcity* simcity, Batiment* batiment) {
    switch (batiment->compteurEvolution) {
        case 0: { //terrain vague
            batiment->nbHabitants = NB_HABITANTS_TERRAINVAGUE;
            break;

        }
        case 1:{//cabane
            batiment->nbHabitants = NB_HABITANTS_CABANE;
            simcity->map.mapTile[batiment->coordXY.celluleX][batiment->coordXY.celluleY].typeBloc = TYPE_CABANE;
            break;
        }

        case 2:{//maison
            batiment->nbHabitants = NB_HABITANTS_MAISON;
            simcity->map.mapTile[batiment->coordXY.celluleX][batiment->coordXY.celluleY].typeBloc = TYPE_MAISON;
            break;
        }

        case 3:{//immeuble
            batiment->nbHabitants = NB_HABITANTS_IMMEUBLE;
            simcity->map.mapTile[batiment->coordXY.celluleX][batiment->coordXY.celluleY].typeBloc = TYPE_IMMEUBLE;
            break;
        }

        case 4: {//gratteciel
            batiment->nbHabitants = NB_HABITANTS_GRATTECIEL;
            simcity->map.mapTile[batiment->coordXY.celluleX][batiment->coordXY.celluleY].typeBloc = TYPE_GRATTE_CIEL;
            break;
        }

        case 5:{//ruine
            batiment->nbHabitants = NB_HABITANTS_RUINE;
            //simcity->map.mapTile[batiment->coordXY.celluleX][batiment->coordXY.celluleY].typeBloc = TYPE_RUINE;
            break;
        }

        default:
            printf("ERREUR evolution batiment.\n");
            break;
    }
}

void regressionBatiment(Simcity* simcity, Batiment* batiment) {
    if(batiment->compteurEvolution > 1 && batiment->compteurEvolution < 5) {
        batiment->compteurEvolution--;
    }
    else if(batiment->compteurEvolution == 1) {
        batiment->compteurEvolution = 5; //en ruine
    }
    miseAJourDonneesBatiment(simcity, batiment);
}

void isEvolutionPossible(Simcity* simcity, Batiment* batiment) {
    Batiment* batimentEvolue = batiment;
    batimentEvolue->compteurEvolution++;
    miseAJourDonneesBatiment(simcity, batimentEvolue);
    if(simcity->capaciteEauRestante < batimentEvolue->capaciteEau && simcity->capaciteElecRestante < batimentEvolue->capaciteElectrique) {
        batiment->evolutionPossible = FALSE;
    }else{batiment->evolutionPossible = TRUE;}
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
#include "batiments.h"
#include "../Map/map.h"

void initTabBatiments(Simcity* simcity) {
    for (int i = 0; i < NBR_MAX_HAB; ++i) {
        simcity->tabHabitation[i].typeBatiment = 0;
        simcity->tabHabitation[i].evolutionPossible = TRUE;
        simcity->tabHabitation[i].compteurEvolution = 0;
        simcity->tabHabitation[i].timerCree = 0;
        simcity->tabHabitation[i].dateCreation = -1;
        simcity->tabHabitation[i].timerBatiment = 0;
        simcity->tabHabitation[i].nbHabitants = 0;
        simcity->tabHabitation[i].capaciteElectriqueRecu = 0;
        simcity->tabHabitation[i].capaciteEauRecu = 0;
        simcity->tabHabitation[i].isFeu = FALSE;
        simcity->tabHabitation[i].isFeuRuine =FALSE;
        simcity->tabHabitation[i].pompier = FALSE;
        for (int j = 0; j < NBR_COORDS_XY_HAB; ++j) {
            simcity->tabHabitation[i].coordXY[j].celluleX = -1;
            simcity->tabHabitation[i].coordXY[j].celluleY = -1;
        }
    }
    simcity->nbHabitations = 0;//On initialise le nombre d'habitation
    simcity->capaciteTotEauUtilise = 0;
    simcity->capaciteTotEau = 0;
    simcity->capaciteEauRestante = 0;
    simcity->capaciteTotElecUtilise = 0;
    simcity->capaciteTotEau = 0;
    simcity->capaciteElecRestante = 0;
}

///Fonction permettant la construction d'une habitation
void construireHabitation(Simcity* simcity) {
    if(simcity->banque.achatTerrainVague == 1) {//Si on achète un terrain vague
        simcity->tabHabitation[simcity->nbHabitations].typeBatiment = 1;//le bâtiment est de type 1 (terrain vague)

        //On récupère les coordonnées du bâtiment
        simcity->tabHabitation[simcity->nbHabitations].coordXY[0].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX;
        simcity->tabHabitation[simcity->nbHabitations].coordXY[0].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY;
        simcity->tabHabitation[simcity->nbHabitations].coordXY[0].screenX = simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][simcity->interactionExterieure.mouse.celluleXY.celluleY].coordsXY.screenX;
        simcity->tabHabitation[simcity->nbHabitations].coordXY[0].screenY = simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][simcity->interactionExterieure.mouse.celluleXY.celluleY].coordsXY.screenY;

        simcity->tabHabitation[simcity->nbHabitations].coordXY[1].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX + 1;
        simcity->tabHabitation[simcity->nbHabitations].coordXY[1].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY;

        simcity->tabHabitation[simcity->nbHabitations].coordXY[2].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX + 2;
        simcity->tabHabitation[simcity->nbHabitations].coordXY[2].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY;

        simcity->tabHabitation[simcity->nbHabitations].coordXY[3].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX;
        simcity->tabHabitation[simcity->nbHabitations].coordXY[3].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY + 1;

        simcity->tabHabitation[simcity->nbHabitations].coordXY[4].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX + 2;
        simcity->tabHabitation[simcity->nbHabitations].coordXY[4].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY + 1;

        simcity->tabHabitation[simcity->nbHabitations].coordXY[5].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX ;
        simcity->tabHabitation[simcity->nbHabitations].coordXY[5].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY + 2;

        simcity->tabHabitation[simcity->nbHabitations].coordXY[6].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX + 1;
        simcity->tabHabitation[simcity->nbHabitations].coordXY[6].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY + 2;

        simcity->tabHabitation[simcity->nbHabitations].coordXY[7].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX + 2;
        simcity->tabHabitation[simcity->nbHabitations].coordXY[7].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY + 2;

        simcity->tabHabitation[simcity->nbHabitations].dateCreation = (int) al_get_timer_count(simcity->allegro.chrono);//On enregistre la date de création du batiment

        simcity->tabHabitation[simcity->nbHabitations].compteurEvolution = 0;//On initialise le compteur evolution à 0 (terrain vague)
    }
    if(simcity->tabHabitation[simcity->nbHabitations].dateCreation != -1) {//Si le batiment a été créé (s'il a une date de création)
        simcity->tabHabitation[simcity->nbHabitations].timerCree = TRUE;//Le timer est marqué comme créé
    } else {printf("ERREUR lancement timer batiment.\n");}//Message d'erreur si probleme dans la creation du batiment
    simcity->nbHabitations++;//on ajoute une habitation suplémentaire à notre nombre d'habitations
}

///Fonction permettant de construire une infrastructure
void construireInfrastructure(Simcity* simcity){

    if(simcity->banque.achatPompier == 1 && simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][simcity->interactionExterieure.mouse.celluleXY.celluleY].typeBloc == TYPE_POMPIER_COTE) {//Si on  achete caserne de pompier
        simcity->tabInfrastructure[simcity->nbInfrastructures].typeBatiment = 4;//On met le type de batiment à 4 (pompier)

        //On enregistre les coordonnées du batiment
        simcity->tabInfrastructure[simcity->nbInfrastructures].adjacence = initListAdj();
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[0].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[0].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY;

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[1].celluleX =
                simcity->interactionExterieure.mouse.celluleXY.celluleX + 1;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[1].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY;

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[2].celluleX =
                simcity->interactionExterieure.mouse.celluleXY.celluleX + 2;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[2].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY;

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[3].celluleX =
                simcity->interactionExterieure.mouse.celluleXY.celluleX + 3;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[3].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY;

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[4].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[4].celluleY =
                simcity->interactionExterieure.mouse.celluleXY.celluleY + 1;

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[5].celluleX =
                simcity->interactionExterieure.mouse.celluleXY.celluleX + 3;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[5].celluleY =
                simcity->interactionExterieure.mouse.celluleXY.celluleY + 1;

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[6].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[6].celluleY =
                simcity->interactionExterieure.mouse.celluleXY.celluleY + 2;

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[7].celluleX =
                simcity->interactionExterieure.mouse.celluleXY.celluleX + 3;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[7].celluleY =
                simcity->interactionExterieure.mouse.celluleXY.celluleY + 2;

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[8].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[8].celluleY =
                simcity->interactionExterieure.mouse.celluleXY.celluleY + 3;

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[9].celluleX =
                simcity->interactionExterieure.mouse.celluleXY.celluleX + 3;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[9].celluleY =
                simcity->interactionExterieure.mouse.celluleXY.celluleY + 3;

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[10].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[10].celluleY =
                simcity->interactionExterieure.mouse.celluleXY.celluleY + 4;

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[11].celluleX =
                simcity->interactionExterieure.mouse.celluleXY.celluleX + 3;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[11].celluleY =
                simcity->interactionExterieure.mouse.celluleXY.celluleY + 4;

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[12].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[12].celluleY =
                simcity->interactionExterieure.mouse.celluleXY.celluleY + 5;

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[13].celluleX =
                simcity->interactionExterieure.mouse.celluleXY.celluleX + 1;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[13].celluleY =
                simcity->interactionExterieure.mouse.celluleXY.celluleY + 5;

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[14].celluleX =
                simcity->interactionExterieure.mouse.celluleXY.celluleX + 2;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[14].celluleY =
                simcity->interactionExterieure.mouse.celluleXY.celluleY + 5;

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[15].celluleX =
                simcity->interactionExterieure.mouse.celluleXY.celluleX + 3;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[15].celluleY =
                simcity->interactionExterieure.mouse.celluleXY.celluleY + 5;
    }
    else if (simcity->banque.achatPompier == 1 && simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][simcity->interactionExterieure.mouse.celluleXY.celluleY].typeBloc == TYPE_POMPIER_DROIT){
        simcity->tabInfrastructure[simcity->nbInfrastructures].adjacence = initListAdj();
        simcity->tabInfrastructure[simcity->nbInfrastructures].typeBatiment = 4;

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[0].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[0].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY;

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[1].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX + 1;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[1].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY;

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[2].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX + 2;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[2].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY;

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[3].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX + 3;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[3].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY;

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[4].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX + 4;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[4].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY;

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[5].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX + 5;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[5].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY;

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[6].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[6].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY + 1;

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[7].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX + 5;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[7].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY + 1;

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[8].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[8].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY + 2;

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[9].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX + 5;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[9].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY + 2;

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[10].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[10].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY + 3;

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[11].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX + 1;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[11].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY + 3;

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[12].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX + 2;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[12].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY + 3;

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[13].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX + 3;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[13].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY + 3;

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[14].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX + 4;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[14].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY + 3;

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[15].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX + 5;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[15].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY + 3;
    }

    if(simcity->banque.achatElectricite == 1 && simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][simcity->interactionExterieure.mouse.celluleXY.celluleY].typeBloc == TYPE_ELEC_COTE) {//Si on achète une centrale électrique
    simcity->tabInfrastructure[simcity->nbInfrastructures].typeBatiment = 2;//On met le type de batiment à 2 (centrale électrique)
    simcity->tabInfrastructure[simcity->nbInfrastructures].capaciteElectriqueMax = CAPACITE_ELECTRIQUE;//On initialise sa capacité électrique de départ

    //On enregistre les coordonnées du batiment
    simcity->tabInfrastructure[simcity->nbInfrastructures].adjacence = initListAdj();
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

    simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[10].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX;
    simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[10].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY + 4;

    simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[11].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX + 3;
    simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[11].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY + 4;

    simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[12].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX ;
    simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[12].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY + 5;

    simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[13].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX + 1;
    simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[13].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY + 5;

    simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[14].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX + 2;
    simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[14].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY + 5;

    simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[15].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX + 3;
    simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[15].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY + 5;

    }
    else if (simcity->banque.achatElectricite == 1 && simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][simcity->interactionExterieure.mouse.celluleXY.celluleY].typeBloc == TYPE_ELEC_DROIT){
        simcity->tabInfrastructure[simcity->nbInfrastructures].adjacence = initListAdj();
        simcity->tabInfrastructure[simcity->nbInfrastructures].typeBatiment = 2;
        simcity->tabInfrastructure[simcity->nbInfrastructures].capaciteElectriqueMax = CAPACITE_ELECTRIQUE;

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[0].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[0].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY;

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[1].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX + 1;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[1].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY;

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[2].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX + 2;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[2].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY;

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[3].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX + 3;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[3].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY;

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[4].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX + 4;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[4].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY;

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[5].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX + 5;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[5].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY;

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[6].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[6].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY + 1;

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[7].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX + 5;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[7].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY + 1;

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[8].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[8].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY + 2;

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[9].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX + 5;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[9].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY + 2;

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[10].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[10].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY + 3;

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[11].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX + 1;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[11].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY + 3;

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[12].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX + 2;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[12].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY + 3;

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[13].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX + 3;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[13].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY + 3;

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[14].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX + 4;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[14].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY + 3;

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[15].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX + 5;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[15].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY + 3;
    }

    if(simcity->banque.achatChateauEau == 1 && simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][simcity->interactionExterieure.mouse.celluleXY.celluleY].typeBloc == TYPE_EAU_COTE) {

        simcity->tabInfrastructure[simcity->nbInfrastructures].adjacence = initListAdj();
        simcity->tabInfrastructure[simcity->nbInfrastructures].typeBatiment = 3;
        simcity->tabInfrastructure[simcity->nbInfrastructures].capaciteEauMax = CAPACITE_EAU;

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

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[10].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[10].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY + 4;

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[11].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX + 3;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[11].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY + 4;

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[12].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX ;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[12].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY + 5;

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[13].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX + 1;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[13].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY + 5;

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[14].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX + 2;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[14].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY + 5;

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[15].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX + 3;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[15].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY + 5;

    }
    else if (simcity->banque.achatChateauEau == 1 && simcity->map.mapTile[simcity->interactionExterieure.mouse.celluleXY.celluleX][simcity->interactionExterieure.mouse.celluleXY.celluleY].typeBloc == TYPE_EAU_DROIT){
        simcity->tabInfrastructure[simcity->nbInfrastructures].typeBatiment = 3;
        simcity->tabInfrastructure[simcity->nbInfrastructures].capaciteEauMax = CAPACITE_EAU;
        simcity->tabInfrastructure[simcity->nbInfrastructures].adjacence = initListAdj();

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[0].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[0].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY;

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[1].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX + 1;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[1].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY;

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[2].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX + 2;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[2].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY;

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[3].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX + 3;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[3].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY;

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[4].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX + 4;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[4].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY;

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[5].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX + 5;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[5].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY;

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[6].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[6].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY + 1;

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[7].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX + 5;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[7].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY + 1;

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[8].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[8].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY + 2;

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[9].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX + 5;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[9].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY + 2;

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[10].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[10].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY + 3;

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[11].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX + 1;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[11].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY + 3;

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[12].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX + 2;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[12].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY + 3;

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[13].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX + 3;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[13].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY + 3;

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[14].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX + 4;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[14].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY + 3;

        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[15].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX + 5;
        simcity->tabInfrastructure[simcity->nbInfrastructures].coordXY[15].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY + 3;

    }
    simcity->nbInfrastructures ++;
}

///mise a jour des habitations QUAND ILS EVOLUENT
void miseAJourDonneesHabitation(Simcity* simcity, Habitation* habitation) {
    switch (habitation->compteurEvolution) {
        case 0: { //terrain vague
            habitation->nbHabitants = NB_HABITANTS_TERRAINVAGUE;//On met à jour le nombre d'habitants
            habitation->capaciteEauMax = CAPACITE_EAU_TERRAINVAGUE;//On met à jour la capacité en eau
            habitation->capaciteElectriqueMax = CAPACITE_ELEC_TERRAINVAGUE;//On met à jour la capacité en électricité
            break;

        }
        case 1: {//cabane
            habitation->nbHabitants = NB_HABITANTS_CABANE;//On met à jour le nombre d'habitants
            habitation->capaciteEauMax = CAPACITE_EAU_CABANE;//On met à jour la capacité en eau
            habitation->capaciteElectriqueMax = CAPACITE_ELEC_CABANE;//On met à jour la capacité en électricité
            simcity->map.mapTile[habitation->coordXY->celluleX][habitation->coordXY->celluleY].typeBloc = TYPE_CABANE;//On affiche la tile correspondante
            break;
        }

        case 2:{//maison
            habitation->nbHabitants = NB_HABITANTS_MAISON;//On met à jour le nombre d'habitants
            habitation->capaciteEauMax = CAPACITE_EAU_MAISON;//On met à jour la capacité en eau
            habitation->capaciteElectriqueMax = CAPACITE_ELEC_MAISON;//On met à jour la capacité en électricité
            simcity->map.mapTile[habitation->coordXY->celluleX][habitation->coordXY->celluleY].typeBloc = TYPE_MAISON;//On affiche la tile correspondante
            break;
        }

        case 3:{//immeuble
            habitation->nbHabitants = NB_HABITANTS_IMMEUBLE;//On met à jour le nombre d'habitants
            habitation->capaciteEauMax = CAPACITE_EAU_IMMEUBLE;//On met à jour la capacité en eau
            habitation->capaciteElectriqueMax = CAPACITE_ELEC_IMMEUBLE;//On met à jour la capacité en électricité
            simcity->map.mapTile[habitation->coordXY->celluleX][habitation->coordXY->celluleY].typeBloc = TYPE_IMMEUBLE;//On affiche la tile correspondante
            break;
        }

        case 4: {//gratteciel
            habitation->nbHabitants = NB_HABITANTS_GRATTECIEL;//On met à jour le nombre d'habitants
            habitation->capaciteEauMax = CAPACITE_EAU_GRATTECIEL;//On met à jour la capacité en eau
            habitation->capaciteElectriqueMax = CAPACITE_ELEC_GRATTECIEL;//On met à jour la capacité en électricité
            simcity->map.mapTile[habitation->coordXY->celluleX][habitation->coordXY->celluleY].typeBloc = TYPE_GRATTE_CIEL;//On affiche la tile correspondante
            break;
        }

        case 5:{//ruine
            habitation->nbHabitants = NB_HABITANTS_RUINE;//On met à jour le nombre d'habitants
            habitation->capaciteEauMax = CAPACITE_EAU_RUINE;//On met à jour la capacité en eau
            habitation->capaciteElectriqueMax = CAPACITE_ELEC_RUINE;//On met à jour la capacité en électricité
            simcity->map.mapTile[habitation->coordXY->celluleX][habitation->coordXY->celluleY].typeBloc = TYPE_RUINE;//On affiche la tile correspondante
            break;
        }

        default:
            printf("ERREUR evolution batiment.\n");//Message d'erreur sur l'evolution du batiment
            break;
    }
}

///Fonction testant si le bâtiment doit régresser
void isRegressionPossible(Habitation* habitation) {
    if(habitation->compteurEvolution >= 1) {//Si ce n'est pas un terrain vague
        if(habitation->eauMax == FALSE || habitation->elecMax == FALSE) {//Si la capacité disponible en eau ou en électricité est inférieure à la capacité nécessaire àl'habitation
            habitation->regression = TRUE;//Evolution de l'habitation testée impossible
        }else{
            habitation->regression = FALSE;}//Evolution de l'habitation testée possible
    }
}

///Fonction permettant la régression de l'habitation
void regressionHabitation(Simcity* simcity, Habitation* habitation) {
    if(habitation->compteurEvolution > 1 && habitation->compteurEvolution < 5) {//Si le batiment n'est ni une cabane ni une ruine
        habitation->compteurEvolution--;//On repasse à l'évolution antérieure du batiment
    }
    else if(habitation->compteurEvolution == 1) {//Si le batiment est de type cabane
        habitation->compteurEvolution = 5;//Le batiment est en ruine
    }
    miseAJourDonneesHabitation(simcity, habitation);//On met à jour les données du batiment
    habitation->regression = FALSE;//On ne doit plus faire régresser le bâtiment

}

///Fonction testant si l'evolution du batiment est possible par rapport aux capacités
void isEvolutionPossible(Simcity* simcity, Habitation* habitation) {
    Habitation habitationEvolue = *habitation;//On crée une habitation tampon
    habitationEvolue.compteurEvolution++;//habitationEvolue à une evolution à 1 stade de plus que l'habitation qu'on teste
    switch (habitationEvolue.compteurEvolution) {//On teste le compteur évolution
        case 1 ://Si c'est une cabane
            habitationEvolue.capaciteEauMax = CAPACITE_EAU_CABANE;
            habitationEvolue.capaciteElectriqueMax = CAPACITE_ELEC_CABANE;
            break;
        case 2://Si c'est une maison
            habitationEvolue.capaciteEauMax = CAPACITE_EAU_MAISON;
            habitationEvolue.capaciteElectriqueMax = CAPACITE_ELEC_MAISON;
            break;
        case 3 ://Si c'est une immeuble
            habitationEvolue.capaciteEauMax = CAPACITE_EAU_IMMEUBLE;
            habitationEvolue.capaciteElectriqueMax = CAPACITE_ELEC_IMMEUBLE;
            break;
        case 4 ://Si c'est une gratte-ciel
            habitationEvolue.capaciteEauMax = CAPACITE_EAU_GRATTECIEL;
            habitationEvolue.capaciteElectriqueMax = CAPACITE_ELEC_GRATTECIEL;
            break;
    }
    simcity->capaciteEauRestante = simcity->capaciteTotEau - simcity->capaciteTotEauUtilise;//On met à jour la capacité d'eau restante dans le jeu
    simcity->capaciteElecRestante = simcity->capaciteTotElec - simcity->capaciteTotElecUtilise;//On met à jour la capacité d'électricité restante dans le jeu
    int eauBesoin = habitationEvolue.capaciteEauMax - habitation->capaciteEauMax;//On calcule l'eau supplémentaire dont aura besoin le bâtiment
    int elecBesoin = habitationEvolue.capaciteElectriqueMax - habitation->capaciteElectriqueMax;//On calcule l'électricité supplémentaire dont aura besoin le bâtiment
    if(simcity->capaciteEauRestante < eauBesoin || simcity->capaciteElecRestante < elecBesoin) {//Si la capacité d'eau ou d'électricité restantes sont inférieures à la quantité dont le bâtiment à besoin
        habitation->evolutionPossible = FALSE;//Evolution de l'habitation testée impossible
    }
    else{
        habitation->evolutionPossible = TRUE;
    }
}

///Fonction comptant le nombre d'habitants total de la ville
void nombreHabitantsTot(Simcity* simcity) {
    int nbHabitantsTot = 0;//Initialisation d'une variable tampon
    for (int i = 0; i < simcity->nbHabitations; ++i) {//On parcourt le tableau d'habitations
        nbHabitantsTot += simcity->tabHabitation[i].nbHabitants;//On ajoute à la variable tampon le nombre d'habitants de chaque habitation
    }
    simcity->nbHabitants = nbHabitantsTot;//On met à jour le nombre d'habitants total de la ville dans la structure du jeu
}
///Fonction affichant le nombre d'habitants total de la ville
void afficherNbHabitantsTot(Simcity* simcity) {
    al_draw_textf(simcity->allegro.fonts[0], simcity->allegro.color[BLACK], 250, 725, 0, "%d",simcity->nbHabitants);
}

///Fonction permettant d'éteindre une habitation en feu
void eteindreFeuMettreRuine(Simcity* simcity, Habitation* habitation) {
    if(habitation->isFeuRuine == TRUE) {//Si le bâtiment doit tomber en ruine
        habitation->isFeu = 0;//On éteint le feu
        habitation->isFeuRuine = FALSE;//Le bâtiment ne doit plus tomber en ruine
        habitation->compteurEvolution = 5;//On met le bâtiment au stade de ruine
        miseAJourDonneesHabitation(simcity, habitation);//On met à jour les données du bâtiment
    }
}
///Fonction permettant de mettre une habitation en feu
void isFeu (Habitation* habitation) {
        if(habitation->compteurEvolution >= 1 && habitation->compteurEvolution < 5) {//Si le bâtiment d'est ni un terrain vague ni une ruine
            if (rand() % 10 == 0) {//Il a une chance sur 10 de prendre feu
                habitation->isFeu = 1;//On déclare le bâtiment en feu
                habitation->evolutionPossible = FALSE;//Le bâtiment ne peut plus évoluer
            }
        }
}
///Fonction affichant le bâtiment en feu
void afficherIsFeu(Simcity* simcity) {
    for (int i = 0; i < simcity->nbHabitations; ++i) {//On parcourt le tableau d'habitations
        if (simcity->tabHabitation[i].isFeu == 1){//Si le bâtiment est déclaré en feu
            al_draw_bitmap((simcity->tabBitmap[BITMAP_FEU]),simcity->tabHabitation[i].coordXY[0].screenX, simcity->tabHabitation[i].coordXY[0].screenY, 0);//On affiche des flammes par dessus
        }
    }
}
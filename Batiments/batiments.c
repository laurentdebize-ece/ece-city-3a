#include "batiments.h"

///Fonction permettant l'initialisation des batiments
void initBatiments(Simcity* simcity) {
    //Initialisation de la structure habitation
    for (int i = 0; i < NBR_MAX_HAB; ++i) {//On parcourt le tableau
        simcity->tabHabitation[i].typeBatiment = 0;
        simcity->tabHabitation[i].evolutionPossible = TRUE;
        simcity->tabHabitation[i].compteurEvolution = 0;
        simcity->tabHabitation[i].timerCree = 0;
        simcity->tabHabitation[i].dateCreation = -1;
        simcity->tabHabitation[i].timerBatiment = 0;
        simcity->tabHabitation[i].nbHabitants = 0;
        simcity->tabHabitation[i].capaciteElectrique = 0;
        simcity->tabHabitation[i].capaciteEau = 0;
        for (int j = 0; j < NBR_COORDS_XY; ++j) {//On initialise les coordonnées
            simcity->tabHabitation->coordXY[j].celluleX = 0;
            simcity->tabHabitation->coordXY[j].celluleY = 0;
        }
    }
    simcity->nbHabitations = 0;//On initialise le nombre d'habitation

    //Initialisation de la structure infrastructure
    for (int i = 0; i < NBR_MAX_INFRA; ++i) {//On parcourt le tableau
        simcity->tabInfrastructure[i].typeBatiment = 0;
        simcity->tabInfrastructure[i].capaciteElectrique = 0;
        simcity->tabInfrastructure[i].capaciteEau = 0;
        for (int j = 0; j < NBR_COORDS_XY; ++j) {//On initialise les coordonnées
            simcity->tabInfrastructure->coordXY[j].celluleX = 0;
            simcity->tabInfrastructure->coordXY[j].celluleY = 0;
        }
    }
    simcity->nbInfrastructures = 0;//On initialise le nombre d'habitation
}

///Fonction permettant la construction d'une habitation
void construireHabitation(Simcity* simcity) {
    if(simcity->banque.achatTerrainVague == 1) {//Si on achète un terrain vague
        simcity->tabHabitation[simcity->nbHabitations].typeBatiment = 1;//le bâtiment est de type 1 (terrain vague)

        //On récupère les coordonnées du bâtiment
        simcity->tabHabitation[simcity->nbHabitations].coordXY[0].celluleX = simcity->interactionExterieure.mouse.celluleXY.celluleX;
        simcity->tabHabitation[simcity->nbHabitations].coordXY[0].celluleY = simcity->interactionExterieure.mouse.celluleXY.celluleY;

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
    if(simcity->tabHabitation[simcity->nbHabitations].dateCreation != -1) {//Si le batiment a été créé (si il a une date de création)
        simcity->tabHabitation[simcity->nbHabitations].timerCree = TRUE;//Le timer est marqué comme créé
    } else {printf("ERREUR lancement timer batiment.\n");}//Message d'erreur si probleme dans la creation du batiment
    simcity->nbHabitations++;//on ajoute une habitation suplémentaire au notre nombre d'habitation
}

///Fonction permettant la construction d'une infrastructure
void construireInfrastructure(Simcity* simcity){
    if(simcity->banque.achatElectricite == 1) {//Si on achète une centrale électrique
        simcity->tabInfrastructure[simcity->nbInfrastructures].typeBatiment = 2;//On met le type de batiment à 2 (centrale électrique)
        simcity->tabInfrastructure[simcity->nbInfrastructures].capaciteElectrique = CAPACITE_ELECTRIQUE;//On initialise sa capacité électrique de départ

        //On enregistre les coordonnées du batiment
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

    if(simcity->banque.achatChateauEau == 1) {//Si on achète un chateau d'eau
        simcity->tabInfrastructure[simcity->nbInfrastructures].typeBatiment = 3;//On met le type de batiment à 3 (chateau d'eau)
        simcity->tabInfrastructure[simcity->nbInfrastructures].capaciteEau = CAPACITE_EAU;//On initialise sa capacité d'eau de départ
    }
}

///Fonction permettant la mise à jour des informations des habitations
void miseAJourDonneesHabitation(Simcity* simcity, Habitation* habitation) {
    switch (habitation->compteurEvolution) {//On teste l'état d'évolution actuel du batiment
        case 0: { //terrain vague
            habitation->nbHabitants = NB_HABITANTS_TERRAINVAGUE;//On met à jour le nombre d'habitants
            break;

        }
        case 1:{//cabane
            habitation->nbHabitants = NB_HABITANTS_CABANE;//On met à jour le nombre d'habitants
            simcity->map.mapTile[habitation->coordXY->celluleX][habitation->coordXY->celluleY].typeBloc = TYPE_CABANE;//On affiche la tile correspondante
            break;
        }

        case 2:{//maison
            habitation->nbHabitants = NB_HABITANTS_MAISON;//On met à jour le nombre d'habitants
            simcity->map.mapTile[habitation->coordXY->celluleX][habitation->coordXY->celluleY].typeBloc = TYPE_MAISON;//On affiche la tile correspondante
            break;
        }

        case 3:{//immeuble
            habitation->nbHabitants = NB_HABITANTS_IMMEUBLE;//On met à jour le nombre d'habitants
            simcity->map.mapTile[habitation->coordXY->celluleX][habitation->coordXY->celluleY].typeBloc = TYPE_IMMEUBLE;//On affiche la tile correspondante
            break;
        }

        case 4: {//gratteciel
            habitation->nbHabitants = NB_HABITANTS_GRATTECIEL;//On met à jour le nombre d'habitants
            simcity->map.mapTile[habitation->coordXY->celluleX][habitation->coordXY->celluleY].typeBloc = TYPE_GRATTE_CIEL;//On affiche la tile correspondante
            break;
        }

        case 5:{//ruine
            habitation->nbHabitants = NB_HABITANTS_RUINE;//On met à jour le nombre d'habitants
            //simcity->map.mapTile[habitation->coordXY->celluleX][habitation->coordXY->celluleY].typeBloc = TYPE_RUINE;//On affiche la tile correspondante
            break;
        }

        default:
            printf("ERREUR evolution batiment.\n");//Message d'erreur sur l'evolution du batiment
            break;
    }
}

///Fonction permettant la régression de l'habitation
void regressionHabitation(Simcity* simcity, Habitation* habitation) {
    if(habitation->compteurEvolution > 1 && habitation->compteurEvolution < 5) {//Si le batiment n'est ni un terrain vague ni une ruine
        habitation->compteurEvolution--;//On repasse à l'évolution antérieur du batiment
    }
    else if(habitation->compteurEvolution == 1) {//Si le batiment est de type terrain vague
        habitation->compteurEvolution = 5;//Le batiment est en ruine
    }
    miseAJourDonneesHabitation(simcity, habitation);//On met a jour les données du batiment
}

///Fonction testant si l'evolution du batiment est possible
void isEvolutionPossible(Simcity* simcity, Habitation* habitation) {
    Habitation* habitationEvolue = habitation;//Création d'une variable tampon habitationEvolue
    habitationEvolue->compteurEvolution++;//habitationEvolue à une evolution à 1 stade de plus que l'habitation qu'on teste
    miseAJourDonneesHabitation(simcity, habitationEvolue);//On met à jour les données de habitationEvolue
    if(simcity->capaciteEauRestante < habitationEvolue->capaciteEau || simcity->capaciteElecRestante < habitationEvolue->capaciteElectrique){//Si la capacité disponible en eau ou en électricité est inférieure à la capacité nécessaire àl'habitation
        habitation->evolutionPossible = FALSE;//Evolution de l'habitation testée impossible
    }else{habitation->evolutionPossible = TRUE;}//Evolution de l'habitation testée possible
}

///Fonction comptant le nombre d'habitants total de la ville
void nombreHabitantsTot(Simcity* simcity) {
    int nbHabitantsTot = 0;//Initialisation d'une variable tampon
    for (int i = 0; i < simcity->nbHabitations; ++i) {//On parcourt le tableau d'habitations
        nbHabitantsTot += simcity->tabHabitation[i].nbHabitants;//On ajoute à la variable tampon le nombre d'habitants de chaque habitation
    }
    simcity->nbHabitants = nbHabitantsTot;//On met a jour le nombre d'habitant total de la ville dans la structure du jeu
}

///Fonction affichant le nombre d'habitants total de la ville
void afficherNbHabitantsTot(Simcity simcity) {
    al_draw_textf(simcity.allegro.fonts[0], simcity.allegro.color[BLACK], 250, 725, 0, "%d",simcity.nbHabitants);
}
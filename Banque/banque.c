#include "banque.h"

///Fonction permettant l'initialisation de la structure banque
void initBanque(Simcity* simcity){
    simcity->argent = SOLDEINITIAL;//Initialisation du solde initial

    //Initialisation des coûts des différentes infrastructures
    simcity->banque.prixTerrainVague = COUTTERRAINVAGUE;
    simcity->banque.prixChateauEau = COUTCHATEAUEAU;
    simcity->banque.prixElectricite = COUTCENTRALE;
    simcity->banque.prixPompier = COUTCASERNE;
    simcity->banque.prixRoute = COUTROUTE;
}

///Fonction permettant d'afficher l'argent restant au joueur
void afficherArgent(Simcity* simcity) {
    al_draw_textf(simcity->allegro.fonts[0], simcity->allegro.color[BLACK], 440, 725, 0, " %d", simcity->argent);
}

bool isPayer(Simcity* simcity, int sommeARetirer){
    if (simcity->argent - sommeARetirer < 0){
        return false;
    }else{
        return true;
    }
}

///Fonction permettant de retirer de l'agent
void retirerArgent(Simcity* simcity, int sommeARetirer){
    if (isPayer(simcity,sommeARetirer)){//Si on paye
        simcity->argent -= sommeARetirer;//On met à jour l'argent du jeu avec la somme retirée
    }
}

///Fonction permettant d'acheter une infrastructure
void payerBanque(Simcity* simcity){
    if (simcity->banque.achatTerrainVague == 1){//Si on achète un terrain vague
        retirerArgent(simcity,simcity->banque.prixTerrainVague);//On retire la somme d'argent correspondante
        simcity->banque.achatTerrainVague = false;//Fin de l'action "acheter un terrain vague"
    }else if(simcity->banque.achatPompier == 1){//Si on achète une caserne de pompiers
        retirerArgent(simcity,simcity->banque.prixPompier);//On retire la somme d'argent correspondante
        simcity->banque.achatPompier = false;//Fin de l'action "acheter une caserne de pompiers"

    }else if(simcity->banque.achatChateauEau == 1){//Si on achète un château d'eau
        retirerArgent(simcity,simcity->banque.prixChateauEau);//On retire la somme d'argent correspondante
        simcity->banque.achatChateauEau = false;//Fin de l'action "acheter un château d'eau"

    }else if(simcity->banque.achatElectricite == 1){//Si on achète une centrale électrique
        retirerArgent(simcity,simcity->banque.prixElectricite);//On retire la somme d'argent correspondante
        simcity->banque.achatElectricite = false;//Fin de l'action "acheter une centrale électrique"
    }else if(simcity->banque.achatRoute == 1){//Si on achète une route
        retirerArgent(simcity,simcity->banque.prixRoute * (simcity->map.compteurCheminsX + simcity->map.compteurCheminsY + 1));//On retire la somme d'argent correspondante
        simcity->banque.achatRoute = false;//Fin de l'action "acheter une route"
    }
}

///Fonction permettant de recevoir les impôts
void recevoirImpots(Simcity* simcity, int nbHabitants) {
    simcity->argent += (nbHabitants * IMPOT);//On met à jour l'argent du jeu en ajoutant le prix de l'impôt * le nombre d'habitants du bâtiment
}



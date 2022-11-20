#include "banque.h"
/*
void recevoirImpots(Simcity* simcity) {
    int impotTot = 0;
    if(simcity->batiment->cycleFini == 1) { // a mettre dans la fonction d'amelirotation du batiment directement ????
        impotTot = simcity->batiment->nbHabitants * IMPOT;
        simcity->argent += impotTot;
    }
}
*/
void initBanque(Simcity* simcity){
    simcity->argent = SOLDEINITIAL;
    simcity->banque.prixTerrainVague = COUTTERRAINVAGUE;
    simcity->banque.prixChateauEau = COUTCHATEAUEAU;
    simcity->banque.prixElectricite = COUTCENTRALE;
    simcity->banque.prixPompier = COUTCASERNE;
    simcity->banque.prixRoute = COUTROUTE;
}

void afficherArgent(Simcity simcity) {
    al_draw_textf(simcity.allegro.fonts[0], simcity.allegro.color[BLACK], 440, 725, 0, " %d", simcity.argent);
}

bool isPayer(Simcity* simcity, int sommeARetirer){
    if (simcity->argent - sommeARetirer < 0){
        return false;
    }else{
        return true;
    }
}

void retirerArgent(Simcity* simcity, int sommeARetirer){
    if (isPayer(simcity,sommeARetirer)){
        simcity->argent -= sommeARetirer;
    }
}

void payerBanque(Simcity* simcity){
    if (simcity->banque.achatTerrainVague == 1){
        retirerArgent(simcity,simcity->banque.prixTerrainVague);
        simcity->banque.achatTerrainVague = false;
    }else if(simcity->banque.achatPompier == 1){
        retirerArgent(simcity,simcity->banque.prixPompier);
        simcity->banque.achatPompier = false;

    }else if(simcity->banque.achatChateauEau == 1){
        retirerArgent(simcity,simcity->banque.prixChateauEau);
        simcity->banque.achatChateauEau = false;

    }else if(simcity->banque.achatElectricite == 1){
        retirerArgent(simcity,simcity->banque.prixElectricite);
        simcity->banque.achatElectricite = false;
    }else if(simcity->banque.achatRoute == 1){
        retirerArgent(simcity,simcity->banque.prixRoute * (simcity->map.compteurCheminsX + simcity->map.compteurCheminsY + 1));
        simcity->banque.achatRoute = false;
    }
}
#include "banque.h"
/*      !!! PAS LE PLUS PRATIQUE JE PENSE !!!
void initBanqueEtPrix(Simcity* simcity) {
    simcity->argent = SOLDEINITIAL;
    simcity->habitation.prixTerrainVague = PRIX_TERRAIN_VAGUE;
    ...
}

void payerBanque(Simcity* simcity) {
    switch (simcity->action) {
        case 1: //achat d'un terrain vague
            simcity->argent -= COUTTERRAINVAGUE;
            break;
        case 2: //achat d'une route
            simcity->argent -= COUTROUTE;
            break;
        case 3: //achat d'une centrale electrique
            simcity->argent -= COUTCENTRALE;
            break;
        case 4: //achat d'un chateau d'eau
            simcity->argent -= COUTCHATEAUEAU;
            break;
        case 5: //achat d'une caserne
            simcity->argent -= COUTCASERNE;
            break;
        default :
            printf("ERREUR numero action.\n");
            break;
    }
}

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
    simcity->batiment.prixTerrainVague = COUTTERRAINVAGUE;
    simcity->batiment.prixChateauEau = COUTCHATEAUEAU;
    simcity->batiment.prixElectricite = COUTCENTRALE;
    simcity->batiment.prixPompier = COUTCASERNE;
    simcity->batiment.prixRoute = COUTROUTE;
}

void afficherArgent(Simcity simcity) {
    al_draw_textf(simcity.allegro.fonts[0], simcity.allegro.color[BLACK], 325, 725, 0, " %d", simcity.argent);
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
        retirerArgent(simcity,simcity->batiment.prixTerrainVague);
        simcity->banque.achatTerrainVague = false;
    }else if(simcity->banque.achatPompier == 1){
        retirerArgent(simcity,simcity->batiment.prixPompier);
        simcity->banque.achatPompier = false;

    }else if(simcity->banque.achatChateauEau == 1){
        retirerArgent(simcity,simcity->batiment.prixChateauEau);
        simcity->banque.achatChateauEau = false;

    }else if(simcity->banque.achatElectricite == 1){
        retirerArgent(simcity,simcity->batiment.prixElectricite);
        simcity->banque.achatElectricite = false;
    }else if(simcity->banque.achatRoute == 1){
        retirerArgent(simcity,simcity->batiment.prixRoute * (simcity->map.compteurCheminsX + simcity->map.compteurCheminsY + 1));
        simcity->banque.achatRoute = false;
    }
}
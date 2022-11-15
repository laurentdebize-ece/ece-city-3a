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
void afficherArgent(Simcity simcity) {
    al_draw_text(simcity.allegro.fonts[0], simcity.allegro.color[BLACK], 375, 725, 0, "20003");
}

 /*
 !!! PLUTOT FAIRE CA JE PENSE !!!
    # plus réutilisable et facile d'utilisation

void retirerArgent(Simcity* simcity, int sommeARetirer){
    simcity->argent -= sommeARetirer;
}

void payerBanque(Simcity* simcity){
    if (simcity->habitation.achatTerrainVague){
        retirerArgent(simcity,simcity->habitation.prixTerrainVague);
    }else if(simcity->habitation.achatPompier){
        retirerArgent(simcity,simcity->habitation.prixPompier);
    }else if(simcity->habitation.achatChateauEau){
        retirerArgent(simcity,simcity->habitation.prixChateauEau);
    }else if(simcity->habitation.achatElectricite){
        retirerArgent(simcity,simcity->habitation.prixElectricite);
    }
}
 */
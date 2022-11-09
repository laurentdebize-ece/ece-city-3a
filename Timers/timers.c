#include "timers.h"
/*
void timerDate(Simcity* simcity) {
    int compteurTimer = al_get_timer_count(simcity->allegro.chrono);
    if (compteurTimer%15 == 0) {
        simcity->mois++;
    }
    if (compteurTimer%180 == 0) {
        simcity->annee++;
    }
    if (simcity->mois % 12 == 0) {
        simcity->mois = 0;
    }
}

void timerTempsJeu(Simcity* simcity) {
    int compteurTempsJeu = al_get_timer_count(simcity->allegro.chrono);
    if (compteurTempsJeu%60 == 0) {
        simcity->minutes++;
        simcity->secondes = 0;
    }
}

void timerBatiment(Simcity* simcity) {
    for (int i = 0; i < simcity->nbBatiments; ++i) {
        if(simcity->batiment[i].timerBatiment % 15 == 0) {
            simcity->batiment[i].compteurEvolution++;
        }
    }
}
 */
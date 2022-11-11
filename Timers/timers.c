#include "timers.h"

void initCompteurs(Simcity* simcity) {
    simcity->timers.mois = 1;
    simcity->timers.annee = 2040;
    simcity->timers.minutes = 0;
    simcity->timers.secondes = 0;
    simcity->timers.zeroDevantMinutes = TRUE;
    simcity->timers.zeroDevantSecondes = TRUE;
}
/*
void timerDate(Simcity* simcity) {
    long long compteurTimer = al_get_timer_count(simcity->allegro.chrono);
    if (compteurTimer%15 == 0) {
        simcity->timers.mois++;
    }
    if (compteurTimer%180 == 0) {
        simcity->timers.annee++;
    }
    printf("%d/%d ", simcity->timers.mois, simcity->timers.annee);
    //if (simcity->mois % 12 == 0) {
    //    simcity->mois = 0;
    //}
}

void timerTempsJeu(Simcity* simcity) {
    long long compteurTempsJeu = al_get_timer_count(simcity->allegro.chrono);
    if (compteurTempsJeu%60 == 0) {
        simcity->timers.minutes++;
        simcity->timers.secondes = 0;
    }
    if(simcity->timers.minutes >= 10) {
        simcity->timers.zeroDevantMinutes = FALSE;
    } else {simcity->timers.zeroDevantMinutes = TRUE;}
    if(simcity->timers.secondes >= 10) {
        simcity->timers.zeroDevantSecondes = FALSE;
    } else {simcity->timers.zeroDevantSecondes = TRUE;}
}

void timerBatiment(Simcity* simcity) {
    for (int i = 0; i < simcity->nbBatiments; ++i) {
        if(simcity->batiment[i].timerBatiment % 15 == 0) {
            simcity->batiment[i].compteurEvolution++;
        }
    }
}*/

void afficherTimerDate(Simcity simcity) {
    al_draw_text(simcity.allegro.fonts[0], simcity.allegro.color[BLACK], 775, 725, 0, "MAY 2022");
    //al_draw_textf(simcity.allegro.fonts[0], simcity.allegro.color[WHITE], 775, 725, 0, "%d/%d", simcity.mois, simcity.annee);
    /*switch(simcity.timers.mois) {
        case 1 :
            al_draw_textf(simcity.allegro.fonts[0], simcity.allegro.color[WHITE], 775, 725, 0, "JANV %d", simcity.timers.annee);
            break;
        case 2 :
            al_draw_textf(simcity.allegro.fonts[0], simcity.allegro.color[WHITE], 775, 725, 0, "FEV %d", simcity.timers.annee);
            break;
        case 3 :
            al_draw_textf(simcity.allegro.fonts[0], simcity.allegro.color[WHITE], 775, 725, 0, "MARS %d", simcity.timers.annee);
            break;
        case 4 :
            al_draw_textf(simcity.allegro.fonts[0], simcity.allegro.color[WHITE], 775, 725, 0, "AVR %d", simcity.timers.annee);
            break;
        case 5 :
            al_draw_textf(simcity.allegro.fonts[0], simcity.allegro.color[WHITE], 775, 725, 0, "MAI %d", simcity.timers.annee);
            break;
        case 6 :
            al_draw_textf(simcity.allegro.fonts[0], simcity.allegro.color[WHITE], 775, 725, 0, "JUIN %d", simcity.timers.annee);
            break;
        case 7 :
            al_draw_textf(simcity.allegro.fonts[0], simcity.allegro.color[WHITE], 775, 725, 0, "JUIL %d", simcity.timers.annee);
            break;
        case 8 :
            al_draw_textf(simcity.allegro.fonts[0], simcity.allegro.color[WHITE], 775, 725, 0, "AOUT %d", simcity.timers.annee);
            break;
        case 9 :
            al_draw_textf(simcity.allegro.fonts[0], simcity.allegro.color[WHITE], 775, 725, 0, "SEPT %d", simcity.timers.annee);
            break;
        case 10 :
            al_draw_textf(simcity.allegro.fonts[0], simcity.allegro.color[WHITE], 775, 725, 0, "OCT %d", simcity.timers.annee);
            break;
        case 11 :
            al_draw_textf(simcity.allegro.fonts[0], simcity.allegro.color[WHITE], 775, 725, 0, "NOV %d", simcity.timers.annee);
            break;
        case 12 :
            al_draw_textf(simcity.allegro.fonts[0], simcity.allegro.color[WHITE], 775, 725, 0, "DEC %d", simcity.timers.annee);
            break;
        default:
            printf("ERREUR numero mois.\n");
            break;
    }*/
}

void afficherTimerTempsJeu(Simcity simcity) {
    al_draw_textf(simcity.allegro.fonts[0], simcity.allegro.color[BLACK], 550, 725, 0, "%lld", al_get_timer_count(simcity.allegro.chrono));
    /*
    if(simcity.timers.zeroDevantMinutes == TRUE && simcity.timers.zeroDevantSecondes == TRUE) {
        al_draw_textf(simcity.allegro.fonts[0], simcity.allegro.color[BLACK], 550, 725, 0, "0%d : 0%d", simcity.timers.minutes, simcity.timers.secondes);
    }
    else if(simcity.timers.zeroDevantMinutes == TRUE && simcity.timers.zeroDevantSecondes == FALSE) {
        al_draw_textf(simcity.allegro.fonts[0], simcity.allegro.color[BLACK], 550, 725, 0, "0%d : %d", simcity.timers.minutes, simcity.timers.secondes);
    }
    else if(simcity.timers.zeroDevantMinutes == FALSE && simcity.timers.zeroDevantSecondes == TRUE) {
        al_draw_textf(simcity.allegro.fonts[0], simcity.allegro.color[BLACK], 550, 725, 0, "%d : 0%d", simcity.timers.minutes, simcity.timers.secondes);
    }
    else if(simcity.timers.zeroDevantMinutes == FALSE && simcity.timers.zeroDevantSecondes == FALSE) {
        al_draw_textf(simcity.allegro.fonts[0], simcity.allegro.color[BLACK], 550, 725, 0, "%d : %d", simcity.timers.minutes, simcity.timers.secondes);
    }
     */
}
#include "timers.h"
#include "../Map/map.h"

///Fonction permettant l'initialisation des compteurs du jeu
void initCompteurs(Simcity* simcity) {
    //Initialisation de la date fictive
    simcity->timers.mois = 1;
    simcity->timers.annee = 2070;

    //Initialisation du temps de jeu
    simcity->timers.minutes = 0;
    simcity->timers.secondes = 0;
    simcity->timers.zeroDevantMinutes = TRUE;
    simcity->timers.zeroDevantSecondes = TRUE;

    simcity->pause = 0;//Initialisation de la pause
}

///Fonction permettant de mettre à jour la date fictive
void timerDate(Simcity* simcity) {
    long long compteurChrono = al_get_timer_count(simcity->allegro.chrono);//Récupération de la valeur du chrono (1sec)
    long long compteurTimer = al_get_timer_count(simcity->allegro.timer);//Récupération de la valeur du timer (1/60sec)
    bool modulo60 = FALSE;//Initialisation d'un booléen test modulo60
    if (compteurTimer%60 == 0) {//Si le timer est modulo 60
        modulo60 = TRUE;//Le booléen test modulo60 est vrai
    } else {modulo60 = FALSE;}
    if (compteurChrono%15 == 0 && modulo60 == TRUE) {//Si le chrono est modulo 15 (=toutes les 15sec) et que le timer est modulo 60 (on change de seconde)
        simcity->timers.mois++;//On passe au mois suivant (donc 1mois=15sec)
    }
    if (compteurChrono%180 == 0 &&  modulo60 == TRUE) {//Si le chrono est modulo 180 (=toutes les 180sec) et que le timer est modulo 60 (on change de seconde)
        simcity->timers.annee++;//On passe à l'année suivante (au bout de 12 mois soit 12*15sec)
    }
    if (simcity->timers.mois % 13 == 0) {//Si on arrive au 13e mois
        simcity->timers.mois = 1;//On repasse au 1er mois (janvier)
    }
}

///Fonction permettant de mettre à jour le temps de jeu
void timerTempsJeu(Simcity* simcity) {
    long long compteurChrono = al_get_timer_count(simcity->allegro.chrono);//Récupération de la valeur du chrono (1sec)
    long long compteurTimer = al_get_timer_count(simcity->allegro.timer);//Récupération de la valeur du timer (1/60sec)
    bool modulo60 = FALSE;//Initialisation d'un booléen test modulo60
    if (compteurTimer%60 == 0) {//Si le timer est modulo 60
        modulo60 = TRUE;//Le booléen test modulo60 est vrai
    } else {modulo60 = FALSE;}
    int secondes = (int)compteurChrono;//Initialisation d'une variable seconde égale aux secondes actuelles depuis le lancement du jeu
    int tampSecondes;//Initialisation d'une variable tampon
    //printf("min %d\n", simcity->timers.minutes);
    tampSecondes = secondes - (60*simcity->timers.minutes);//On réinitialise la variable tampon toutes les minutes
    simcity->timers.secondes = tampSecondes;//On met à jour les secondes dans la structure du jeu
    if (compteurChrono%60 == 0 &&  modulo60 == TRUE) {//Si le chrono est modulo 60 (= toutes les 60sec) et que le timer est modulo 60 (on change de seconde)
        simcity->timers.minutes++;//On met à jour les minutes dans la structure du jeu
    }
    if(simcity->timers.minutes >= 10) {//Si minutes supérieures ou égal à 10
        simcity->timers.zeroDevantMinutes = FALSE;//On met le booléen de paramétrage d'affichage des minutes à 0
    } else {simcity->timers.zeroDevantMinutes = TRUE;}
    if(simcity->timers.secondes >= 10) {//Si secondes supérieures ou égal à 10
        simcity->timers.zeroDevantSecondes = FALSE;//On met le booléen de paramétrage d'affichage des secondes à 0
    } else {simcity->timers.zeroDevantSecondes = TRUE;}
}

///Fonction permettant de mettre à jour le timer des bâtiments
void timerBatiment(Simcity* simcity) {
    long long compteurChrono = al_get_timer_count(simcity->allegro.chrono);//Récupération de la valeur du chrono (1sec)
    long long compteurTimer = al_get_timer_count(simcity->allegro.timer);//Récupération de la valeur du timer (1/60sec)
    bool modulo60 = FALSE;//Initialisation d'un booléen test modulo60
    if (compteurTimer%60 == 0) {//Si le timer est modulo 60
        modulo60 = TRUE;//Le booléen test modulo60 est vrai
    } else {modulo60 = FALSE;}
    for (int i = 0; i < simcity->nbHabitations; ++i) {//On parcourt le tableau d'habitations
        if(simcity->tabHabitation[i].timerCree == TRUE) {//Si le bâtiment est créé
            simcity->tabHabitation[i].timerBatiment = (int)compteurChrono - simcity->tabHabitation[i].dateCreation;
            if(simcity->pause == 0 && simcity->tabHabitation[i].timerBatiment % 15 == 0 && modulo60 == TRUE) {//Si on n'est pas en pause, toutes les 15 secondes
                if(simcity->tabHabitation[i].compteurEvolution == 5) {//Si le bâtiment est une ruine
                    simcity->tabHabitation[i].compteurEvolution = 0;//On met le bâtiment à l'état de terrain vague
                    simcity->tabHabitation[i].evolutionPossible = TRUE;//L'évolution du bâtiment est possible
                }
                if(simcity->communiste == TRUE) {//Si on joue en mode communiste
                   isEvolutionPossible(simcity, &simcity->tabHabitation[i]);//On teste si l'évolution est possible par rapport aux capacités
                }
                //printf(" - %d\n", simcity->tabHabitation[i].evolutionPossible);
                if(simcity->tabHabitation[i].evolutionPossible == TRUE) {//Si l'évolution est possible
                    if(simcity->tabHabitation[i].compteurEvolution < 4) {//Si le bâtiment n'est pas une ruine et n'est pas un gratte-ciel
                        simcity->tabHabitation[i].compteurEvolution++;//Le bâtiment passe à l'évolution supérieure
                        miseAJourDonneesHabitation(simcity, &simcity->tabHabitation[i]);//On met à jour les données du bâtiment
                    }
                }
                /*isRegressionPossible(simcity, &simcity->tabHabitation[i]);//On teste si le bâtiment doit régresser
                if(simcity->tabHabitation[i].regression == TRUE) {//S'il doit régresser
                    regressionHabitation(simcity, &simcity->tabHabitation[i]);//On le fait régresser
                }*/

                //Boucle test pompier
                for(int l = 0; l < simcity->nbHabitations; ++l){
                    if(simcity->tabHabitation[l].isFeu == TRUE && simcity->tabHabitation[l].pompier == TRUE) {//Si en feu et dans la zone pompiers
                        simcity->tabHabitation[l].isFeu = FALSE;//On éteint le feu
                        simcity->tabHabitation[l].evolutionPossible = TRUE;//on relance l'évolution
                    }
                    else if(simcity->tabHabitation[l].isFeu == TRUE && simcity->tabHabitation[l].pompier == FALSE) {//Si en feu et pas dans la zone pompiers
                        simcity->tabHabitation[l].isFeuRuine = TRUE;//La maiso, doit tomber en ruine
                        eteindreFeuMettreRuine(simcity, &simcity->tabHabitation[i]);//On met la maison en ruine
                    }
                }
                BFSEau(simcity);
                BFSElec(simcity);
                BFSPompier(simcity);
                calculCapaciteEau(simcity);
                calculCapaciteElec(simcity);
                isFeu(&simcity->tabHabitation[i]);//On met en feu les habitations
                recevoirImpots(simcity, simcity->tabHabitation[i].nbHabitants);//On reçoit les impôts
            }
        }
    }
}

///Fonction permettant d'afficher la date fictive
void afficherTimerDate(Simcity* simcity) {
    switch(simcity->timers.mois) {//On teste le mois dans lequel on est
        case 1 ://Janvier
            al_draw_textf(simcity->allegro.fonts[0], simcity->allegro.color[BLACK], 820, 725, 0, "JANV %d", simcity->timers.annee);
            break;
        case 2 ://Février
            al_draw_textf(simcity->allegro.fonts[0], simcity->allegro.color[BLACK], 820, 725, 0, "FEV %d", simcity->timers.annee);
            break;
        case 3 ://Mars
            al_draw_textf(simcity->allegro.fonts[0], simcity->allegro.color[BLACK], 820, 725, 0, "MARS %d", simcity->timers.annee);
            break;
        case 4 ://Avril
            al_draw_textf(simcity->allegro.fonts[0], simcity->allegro.color[BLACK], 820, 725, 0, "AVR %d", simcity->timers.annee);
            break;
        case 5 ://Mai
            al_draw_textf(simcity->allegro.fonts[0], simcity->allegro.color[BLACK], 820, 725, 0, "MAI %d", simcity->timers.annee);
            break;
        case 6 ://Juin
            al_draw_textf(simcity->allegro.fonts[0], simcity->allegro.color[BLACK], 820, 725, 0, "JUIN %d", simcity->timers.annee);
            break;
        case 7 ://Juillet
            al_draw_textf(simcity->allegro.fonts[0], simcity->allegro.color[BLACK], 820, 725, 0, "JUIL %d", simcity->timers.annee);
            break;
        case 8 ://Août
            al_draw_textf(simcity->allegro.fonts[0], simcity->allegro.color[BLACK], 820, 725, 0, "AOUT %d", simcity->timers.annee);
            break;
        case 9 ://Septembre
            al_draw_textf(simcity->allegro.fonts[0], simcity->allegro.color[BLACK], 820, 725, 0, "SEPT %d", simcity->timers.annee);
            break;
        case 10 ://Octobre
            al_draw_textf(simcity->allegro.fonts[0], simcity->allegro.color[BLACK], 820, 725, 0, "OCT %d", simcity->timers.annee);
            break;
        case 11 ://Novembre
            al_draw_textf(simcity->allegro.fonts[0], simcity->allegro.color[BLACK], 820, 725, 0, "NOV %d", simcity->timers.annee);
            break;
        case 12 ://Décembre
            al_draw_textf(simcity->allegro.fonts[0], simcity->allegro.color[BLACK], 820, 725, 0, "DEC %d", simcity->timers.annee);
            break;
        default:
            printf("ERREUR numero mois.\n");//Message d'erreur de la date fictive
            break;
    }
}

///Focntion permettant d'afficher le temps de jeu
void afficherTimerTempsJeu(Simcity* simcity) {
    //Test pour les paramètres d'affichage permettant d'afficher des 0 devant les minutes et les secondes si celles-ci sont inférieures à 10
    if(simcity->timers.zeroDevantMinutes == TRUE && simcity->timers.zeroDevantSecondes == TRUE) {
        al_draw_textf(simcity->allegro.fonts[0], simcity->allegro.color[BLACK], 640, 727, 0, "0%d : 0%d", simcity->timers.minutes, simcity->timers.secondes);
    }
    else if(simcity->timers.zeroDevantMinutes == TRUE && simcity->timers.zeroDevantSecondes == FALSE) {
        al_draw_textf(simcity->allegro.fonts[0], simcity->allegro.color[BLACK], 640, 727, 0, "0%d : %d", simcity->timers.minutes, simcity->timers.secondes);
    }
    else if(simcity->timers.zeroDevantMinutes == FALSE && simcity->timers.zeroDevantSecondes == TRUE) {
        al_draw_textf(simcity->allegro.fonts[0], simcity->allegro.color[BLACK], 640, 727, 0, "%d : 0%d", simcity->timers.minutes, simcity->timers.secondes);
    }
    else if(simcity->timers.zeroDevantMinutes == FALSE && simcity->timers.zeroDevantSecondes == FALSE) {
        al_draw_textf(simcity->allegro.fonts[0], simcity->allegro.color[BLACK], 640, 727, 0, "%d : %d", simcity->timers.minutes, simcity->timers.secondes);
    }
}

///Fonction permettant la mise en pause à partir du clavier
void pauseTimerClavier(Simcity* simcity){
     if (simcity->allegro.event.keyboard.keycode == ALLEGRO_KEY_ESCAPE && simcity->pause){//Si la touche "escape" est enfoncée et que le jeu est en pause
        simcity->pause = !simcity->pause;//Le jeu reprend
        al_start_timer(simcity->allegro.chrono);//On relance le chrono
    }else if (simcity->allegro.event.keyboard.keycode == ALLEGRO_KEY_ESCAPE && !simcity->pause){//Si la touche "escape" est enfoncée et que le jeu n'est pas en pause
         simcity->pause = !simcity->pause;//Le jeu est en pause
         al_stop_timer(simcity->allegro.chrono);//On arrête le chrono
     }
}

///Fonction permettant la mise en pause à partir de la souris
void pauseTimerSouris(Simcity* simcity){
    if (!simcity->pause && simcity->toolBox.pauseEnMain){//Si le jeu n'est pas en pause et que l'on clique sur le bouton pause
        simcity->pause = !simcity->pause;//Le jeu est en pause
        al_stop_timer(simcity->allegro.chrono);//On arrête le chrono
    }else if (simcity->pause && simcity->toolBox.pauseEnMain){//Si le jeu est en pause et que l'on clique sur le bouton pause
        simcity->pause = !simcity->pause;//Le jeu reprend
        al_start_timer(simcity->allegro.chrono);//On relance le chrono
    }
}
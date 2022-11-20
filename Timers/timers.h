#ifndef ECE_CITY_3A_TIMERS_H
#define ECE_CITY_3A_TIMERS_H

#include "../Structures/structures.h"

void initCompteurs(Simcity* simcity);
void timerDate(Simcity* simcity);
void timerTempsJeu(Simcity* simcity);
void timerBatiment(Simcity* simcity);
void afficherTimerDate (Simcity simcity);
void afficherTimerTempsJeu(Simcity simcity);
void pauseTimerClavier(Simcity* simcity);
void pauseTimerSouris(Simcity* simcity);

#endif //ECE_CITY_3A_TIMERS_H

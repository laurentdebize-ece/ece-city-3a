#include <stdio.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include "Structures/structures.h"
#include "Map/map.h"
#include "Pages/MenuPrincipal/menuPrincipal.h"
#include "time.h"
#include "Timers/timers.h"
#include "Batiments/batiments.h"
#include "ToolBox/toolbox.h"
#include "Banque/banque.h"


void initAll(Simcity* simcity){
    srand(time(NULL));
    installAllegro();
    declarerAllegro(simcity);
    initAllegroAll(simcity);
    initDataMap(simcity);
    initDataMenuPrincipal(simcity);
    initCompteurs(simcity);
    initBanque(simcity);
}

void boucleTest(Simcity* simcity){

    while (!simcity->endGame) {

        al_wait_for_event(simcity->allegro.queue, &simcity->allegro.event);


        switch (simcity->allegro.event.type) {

            case ALLEGRO_EVENT_DISPLAY_CLOSE:{
                simcity->endGame = true;
                break;
            }
            case ALLEGRO_EVENT_MOUSE_AXES:{
                simcity->allegro.coordonneesSourisX = simcity->allegro.event.mouse.x;
                simcity->allegro.coordonneesSourisY = simcity->allegro.event.mouse.y;
                calculPositionSourisEnCelluleXY(simcity);
                calculHoverToolBox(simcity);
                outOfBorder(simcity);
                simcity->dessin = true;
                break;
            }
            case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:{
                switch (simcity->allegro.event.mouse.button) {
                    case 1:{
                        poserBatiment(simcity);
                        detruire(simcity);
                        detectionCliqueToolBox(simcity);
                        simcity->dessin = true;
                        break;
                    }
                    case 2:{
                        tournerBatiment(simcity);
                        simcity->dessin = true;
                        break;
                    }
                }
                break;
            }
            case ALLEGRO_EVENT_MOUSE_BUTTON_UP:{

                break;
            }
            case ALLEGRO_EVENT_TIMER:{
                timerDate(simcity);
                timerTempsJeu(simcity);
                payerBanque(simcity);
                /*for (int i = 0; i < simcity->nbBatiments; ++i) {
                    timerBatiment(simcity);
                    evolutionBatiment(simcity);
                }*/
                simcity->dessin = true;

                if (simcity->dessin) {
                    afficherMap(simcity);
                    if (simcity->outOfBorder){
                        afficherHoverMap(simcity);
                    }
                    //afficherTimerDate(*simcity);
                    afficherTimerTempsJeu(*simcity);
                    al_flip_display();
                    simcity->dessin = false;
                }
                break;
            }
        }
    }
}

void boucletestMenuPrincipal(Simcity* simcity){
    while (!simcity->pages.menuPrincipal.menuPrincipal) {

        al_wait_for_event(simcity->allegro.queue, &simcity->allegro.event);


        switch (simcity->allegro.event.type) {

            case ALLEGRO_EVENT_DISPLAY_CLOSE:{
                simcity->endGame = true;
                simcity->pages.menuPrincipal.menuPrincipal = true;
                break;
            }
            case ALLEGRO_EVENT_MOUSE_AXES:{
                simcity->allegro.coordonneesSourisX = simcity->allegro.event.mouse.x;
                simcity->allegro.coordonneesSourisY = simcity->allegro.event.mouse.y;
                calculHover(simcity);
                simcity->dessin = true;
                break;
            }
            case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:{
                switch (simcity->allegro.event.mouse.button) {
                    case 1:{
                        calculHover(simcity);
                        detectionClique(simcity);
                        simcity->dessin = true;
                        break;
                    }
                }
                break;
            }
            case ALLEGRO_EVENT_MOUSE_BUTTON_UP:{
                break;
            }
            case ALLEGRO_EVENT_TIMER:{

                simcity->dessin = true;

                if (simcity->dessin) {
                    afficherMenuPrincipal(simcity);
                    al_flip_display();
                    simcity->dessin = false;
                }
                break;
            }
        }
    }
}

// main antoine pour tester ses fonctions
void mainAntoine() {
    Simcity simcity = {0};
    initAll(&simcity);
    boucletestMenuPrincipal(&simcity);
    //simcity.toolBox.routeEnMain = 1;
    //simcity.toolBox.terrainVagueEnMain = 1;

    boucleTest(&simcity);
    libererAll(&simcity);

}

// appeler son main afin de tester les fonctions
int main(){
    mainAntoine();
    //mainNoemie();
    return 0;
}
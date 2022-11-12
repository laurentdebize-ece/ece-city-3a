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


void initAll(Simcity* simcity){
    srand(time(NULL));
    installAllegro();
    declarerAllegro(simcity);
    initAllegroAll(simcity);
    initDataMap(simcity);
    initDataMenuPrincipal(simcity);
    initCompteurs(simcity);
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
                outOfBorder(simcity);
                simcity->dessin = true;
                break;
            }
            case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:{
                switch (simcity->allegro.event.mouse.button) {
                    case 1:{
                        poserTerrainVague(simcity);
                        poserRoute(simcity);
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
    /*simcity.map.mapTile[0][0].typeBloc = 2;
    simcity.map.mapTile[0][1].typeBloc = 4;
    simcity.map.mapTile[0][2].typeBloc = 4;
    simcity.map.mapTile[1][0].typeBloc = 4;
    simcity.map.mapTile[1][1].typeBloc = 4;
    simcity.map.mapTile[1][2].typeBloc = 4;
    simcity.map.mapTile[2][0].typeBloc = 4;
    simcity.map.mapTile[2][1].typeBloc = 4;
    simcity.map.mapTile[2][2].typeBloc = 4;*/
    //simcity.toolBox.routeEnMain = 1;
    simcity.toolBox.routeEnMain = 1;
    boucleTest(&simcity);
    libererAll(&simcity);

}

// appeler son main afin de tester les fonctions
int main(){
    mainAntoine();
    //mainNoemie();
    return 0;
}
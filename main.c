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
#include "Batiments/batiments.h"


void initAll(Simcity* simcity){
    srand(time(NULL));
    installAllegro();
    declarerAllegro(simcity);
    initAllegroAll(simcity);
    initDataMap(simcity);
    initDataMenuPrincipal(simcity);
    initCompteurs(simcity);
    initBanque(simcity);
    initTabBatiments(simcity);
    initDataMenuCommunisteCapitaliste(simcity);
    initDataBoutonAide(simcity);

}

void boucleTest(Simcity* simcity){

    /*al_set_timer_count(simcity->allegro.timer, 0);
    al_set_timer_count(simcity->allegro.chrono, 0);*/

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
            case ALLEGRO_EVENT_KEY_DOWN:{
                switch (simcity->allegro.event.keyboard.keycode) {
                    case ALLEGRO_KEY_ESCAPE:{
                        pauseTimerClavier(simcity);
                        break;
                    }
                }
                break;
            }
            case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:{
                switch (simcity->allegro.event.mouse.button) {
                    case 1:{
                        detruire(simcity);
                        poserBatiment(simcity);
                        detectionCliqueToolBox(simcity);
                        pauseTimerSouris(simcity);
                        //cliquer(simcity);
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
                timerBatiment(simcity);
                nombreHabitantsTot(simcity);
                simcity->dessin = true;

                if (simcity->dessin) {
                    afficherMap(simcity);
                    if (simcity->outOfBorder){
                        afficherHoverMap(simcity);
                    }
                   afficherTimerTempsJeu(simcity);
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
                calculHoverBoutonAide(simcity);
                simcity->dessin = true;
                break;
            }
            case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:{
                switch (simcity->allegro.event.mouse.button) {
                    case 1:{
                        calculHover(simcity);
                        detectionClique(simcity);
                        calculHoverBoutonAide(simcity);
                        detectionCliqueBoutonAide(simcity);
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


void boucletestMenuCommunisteCapitaliste(Simcity* simcity){
    while (!simcity->pages.menuCapitalisteCommuniste.menuCapitalisteCommuniste) {

        al_wait_for_event(simcity->allegro.queue, &simcity->allegro.event);


        switch (simcity->allegro.event.type) {

            case ALLEGRO_EVENT_DISPLAY_CLOSE:{
                simcity->endGame = true;
                simcity->pages.menuCapitalisteCommuniste.menuCapitalisteCommuniste = true;
                break;
            }
            case ALLEGRO_EVENT_MOUSE_AXES:{
                simcity->allegro.coordonneesSourisX = simcity->allegro.event.mouse.x;
                simcity->allegro.coordonneesSourisY = simcity->allegro.event.mouse.y;
                calculHoverComCap(simcity);
                simcity->dessin = true;
                break;
            }
            case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:{
                switch (simcity->allegro.event.mouse.button) {
                    case 1:{
                        calculHoverComCap(simcity);
                        detectionCliqueMenuCapCom(simcity);
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
                    afficherMenuComCap(simcity);
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
    boucletestMenuCommunisteCapitaliste(&simcity);
    //simcity.toolBox.routeEnMain = 1;
    //simcity.toolBox.terrainVagueEnMain = 1;
    boucleTest(&simcity);
    libererAll(&simcity);
    printf("test");

}

// appeler son main afin de tester les fonctions
int main(){
    mainAntoine();
    //mainNoemie();
    return 0;
}
#include <stdio.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include "Structures/structures.h"
#include "Map/map.h"

void initAll(Simcity* simcity){
    srand(time(NULL));
    installAllegro();
    declarerAllegro(simcity);
    initAllegroAll(simcity);
    initDataMap(simcity);
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
                simcity->dessin = true;
                break;
            }
            case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:{
                switch (simcity->allegro.event.mouse.button) {
                    case 1:{
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
                    afficherMap(simcity);
                    afficherHoverMap(simcity);
                    al_flip_display();
                    simcity->dessin = false;
                }
                break;
            }
        }
    }
}

int main() {
    Simcity simcity = {0};
    initAll(&simcity);
    boucleTest(&simcity);
    libererAll(&simcity);

    return 0;
}
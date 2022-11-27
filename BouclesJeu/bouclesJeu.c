#include "bouclesJeu.h"

///Fonction permettant l'initialisation de la structure du jeu
void initAll(Simcity* simcity) {
    srand(time(NULL));//Initialisation de la fréquence du rand

    //Initilisations Allegro
    installAllegro();
    declarerAllegro(simcity);
    initAllegroAll(simcity);

    //Initialisation des données des différentes pages du jeu
    initDataMap(simcity);
    initDataMenuPrincipal(simcity);
    initDataMenuCommunisteCapitaliste(simcity);
    initDataBoutonAide(simcity);
    initDataMenuRegles(simcity);

    initCompteurs(simcity);//Initialisation des compteurs du jeu
    initBanque(simcity);//Initialisation de la banque
    initTabBatiments(simcity);//Initialisation des bâtiments

}

void boucleTest(Simcity* simcity){
    while (!simcity->endGame) {//Tant que le jeu est en cours

        al_wait_for_event(simcity->allegro.queue, &simcity->allegro.event);


        switch (simcity->allegro.event.type) {//On teste le type d'évènement

            case ALLEGRO_EVENT_DISPLAY_CLOSE:{//Evènement "Fermer écran"
                simcity->endGame = true;//Fin du jeu
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
                    case ALLEGRO_KEY_ESCAPE:{//Evènement "Touche échap enfoncé"
                        pauseTimerClavier(simcity);//On met en pause le jeu
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

void boucletestMenuRegles(Simcity* simcity){
    while (!simcity->pages.menuRegles.menuRegles) {

        al_wait_for_event(simcity->allegro.queue, &simcity->allegro.event);


        switch (simcity->allegro.event.type) {

            case ALLEGRO_EVENT_DISPLAY_CLOSE:{
                simcity->endGame = true;
                simcity->pages.menuRegles.menuRegles = true;
                break;
            }
            case ALLEGRO_EVENT_MOUSE_AXES:{
                simcity->allegro.coordonneesSourisX = simcity->allegro.event.mouse.x;
                simcity->allegro.coordonneesSourisY = simcity->allegro.event.mouse.y;
                calculHoverFlechesMenuRegles(simcity);
                simcity->dessin = true;
                break;
            }
            case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:{
                switch (simcity->allegro.event.mouse.button) {
                    case 1:{
                        calculHoverFlechesMenuRegles(simcity);
                        detectionCliqueMenuRegles(simcity);
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
                    afficherMenuAide(simcity);
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
                simcity->pages.menuCapitalisteCommuniste.menuCapitalisteCommuniste = true;
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
                        if (simcity->pages.menuPrincipal.aideClique == true){
                            boucletestMenuRegles(simcity);

                        }
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
                simcity->pages.menuPrincipal.menuPrincipal = true;
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


///Fonction permettant le lancement de la partie
void lancerPartie() {
    //Initialisation de la structure du jeu
    Simcity simcity = {0};
    initAll(&simcity);

    //Lancement des différentes pages du jeu
    boucletestMenuPrincipal(&simcity);
    boucletestMenuCommunisteCapitaliste(&simcity);
    boucleTest(&simcity);

    //Libération de la structure du jeu
    libererAll(&simcity);
}
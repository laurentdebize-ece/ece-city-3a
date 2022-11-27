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

///Fonction contenant la boucle générale de la partie une fois qu'elle est lancée
void boucleTest(Simcity* simcity){
    while (!simcity->endGame) {//Tant que le jeu est en cours

        al_wait_for_event(simcity->allegro.queue, &simcity->allegro.event);


        switch (simcity->allegro.event.type) {//On teste le type d'évènement

            case ALLEGRO_EVENT_DISPLAY_CLOSE:{//Evènement "Fermer écran"
                simcity->endGame = true;//Fin du jeu
                break;
            }
            case ALLEGRO_EVENT_MOUSE_AXES:{//Evènement dépendant de la position de la souris
                simcity->allegro.coordonneesSourisX = simcity->allegro.event.mouse.x;//Récupération des coordonnées de la souris selon l'axe X
                simcity->allegro.coordonneesSourisY = simcity->allegro.event.mouse.y;//Récupération des coordonnées de la souris selon l'axe Y
                calculPositionSourisEnCelluleXY(simcity);//Calcul des coordonnées de la souris
                calculHoverToolBox(simcity);//Test pour savoir si la souris passe sur la ToolBox
                outOfBorder(simcity);//Si la souris est hors de la map
                simcity->dessin = true;//On met à jour la page
                break;
            }
            case ALLEGRO_EVENT_KEY_DOWN:{//Evènement dépendant du clavier
                switch (simcity->allegro.event.keyboard.keycode) {
                    case ALLEGRO_KEY_ESCAPE:{//Evènement "Touche échap enfoncé"
                        pauseTimerClavier(simcity);//On met en pause le jeu
                        break;
                    }
                }
                break;
            }
            case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:{//Evènement dépendant du clic de la souris
                switch (simcity->allegro.event.mouse.button) {
                    case 1:{//Si clic gauche
                        detruire(simcity);//Si destruction, détruire le bâtiment correspondant
                        poserBatiment(simcity);//Si poser bâtiment, poser bâtiment aux coordonnées
                        detectionCliqueToolBox(simcity);//Si sur la ToolBox on détecte et fait l'action correspondante
                        pauseTimerSouris(simcity);//Si sur bouton pause on met en pause le jeu
                        simcity->dessin = true;//On met à jour la page
                        break;
                    }
                    case 2:{//Si clic droit
                        tournerBatiment(simcity);//On tourne le bâtiment de 90 degrés
                        simcity->dessin = true;//On met à jour la page
                        break;
                    }
                }
                break;
            }
            case ALLEGRO_EVENT_MOUSE_BUTTON_UP:{
                break;
            }
            case ALLEGRO_EVENT_TIMER:{//Evènement dépendant du timer
                timerDate(simcity);//Timer de la date fictive
                timerTempsJeu(simcity);//Timer du temps de jeu
                payerBanque(simcity);//Acheter à la banque
                timerBatiment(simcity);//Timer propre à chaque bâtiment
                nombreHabitantsTot(simcity);//Calcul du nombre d'habitants de la ville
                calculCapaciteEau(simcity);
                // ici : calculCapaciteElectricite(simcity);
                simcity->dessin = true;//On met à jour la page

                if (simcity->dessin) {//Si on doit mettre à jour la page
                    afficherMap(simcity);//On affiche la map
                    if (simcity->outOfBorder){//Si on est dans la map
                        afficherHoverMap(simcity);//On affiche le contour de la map
                    }
                    afficherTimerTempsJeu(simcity);//On affiche le timer temps de jeu
                    al_flip_display();//On rafraichi l'affichage
                    simcity->dessin = false;//On ne doit pas mettre à jour la page
                }
                break;
            }
        }
    }
}

///Fonction permettant de lancer le menu des règles du jeu
void boucletestMenuRegles(Simcity* simcity){
    while (!simcity->pages.menuRegles.menuRegles) {//Si on est sur la page Menu règles du jeu

        al_wait_for_event(simcity->allegro.queue, &simcity->allegro.event);

        switch (simcity->allegro.event.type) {//On teste le type d'évènement

            case ALLEGRO_EVENT_DISPLAY_CLOSE:{//Evènement "Fermer écran"
                simcity->endGame = true;//On met fin au jeu
                simcity->pages.menuRegles.menuRegles = true;//On quitte le menu règles du jeu
                break;
            }
            case ALLEGRO_EVENT_MOUSE_AXES:{//Evènement dépendant des coordonnées de la souris
                simcity->allegro.coordonneesSourisX = simcity->allegro.event.mouse.x;//Récupération des coordonnées de la souris selon l'axe X
                simcity->allegro.coordonneesSourisY = simcity->allegro.event.mouse.y;//Récupération des coordonnées de la souris selon l'axe Y
                calculHoverFlechesMenuRegles(simcity);//On regarde si la souris est sur les boutons du menu des règles du jeu
                simcity->dessin = true;//On met à jour la page
                break;
            }
            case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:{//Evènement dépendant du clic de la souris
                switch (simcity->allegro.event.mouse.button) {
                    case 1:{//Clic gauche
                        calculHoverFlechesMenuRegles(simcity);//Si la souris est sur les boutons du menu des règles du jeu
                        detectionCliqueMenuRegles(simcity);//On regarde si on clique sur les boutons
                        simcity->dessin = true;//On met à jour la page
                        break;
                    }
                }
                break;
            }
            case ALLEGRO_EVENT_MOUSE_BUTTON_UP:{
                break;
            }
            case ALLEGRO_EVENT_TIMER:{//Evènement dépendant du timer

                simcity->dessin = true;//On met à jour la page

                if (simcity->dessin) {//Si on doit mettre à jour la page
                    afficherMenuAide(simcity);//On affiche le menu Aide (Règles du jeu)
                    al_flip_display();//On rafraichi l'affichage
                    simcity->dessin = false;//On ne doit pas mettre à jour la page
                }
                break;
            }
        }
    }
}

///Fonction permettant de lancer le menu principal du jeu
void boucletestMenuPrincipal(Simcity* simcity){
    while (!simcity->pages.menuPrincipal.menuPrincipal) {//Si on est sur la page Menu principal

        al_wait_for_event(simcity->allegro.queue, &simcity->allegro.event);

        switch (simcity->allegro.event.type) {//On teste le type d'évènement

            case ALLEGRO_EVENT_DISPLAY_CLOSE:{//Evènement "Fermer écran"
                simcity->endGame = true;//Fin du jeu
                simcity->pages.menuPrincipal.menuPrincipal = true;//On quitte le menu principal
                simcity->pages.menuCapitalisteCommuniste.menuCapitalisteCommuniste = true;//On ne peut pas aller dans le menu Capitaliste et Communiste
                break;
            }
            case ALLEGRO_EVENT_MOUSE_AXES:{//Evènement dépendant des coordonnées de la souris
                simcity->allegro.coordonneesSourisX = simcity->allegro.event.mouse.x;//Récupération des coordonnées de la souris selon l'axe X
                simcity->allegro.coordonneesSourisY = simcity->allegro.event.mouse.y;//Récupération des coordonnées de la souris selon l'axe Y
                calculHover(simcity);//Test pour savoir où est la souris sur le menu
                calculHoverBoutonAide(simcity);//Test pour savoir si la souris est sur le bouton Aide
                simcity->dessin = true;//On met à jour la page
                break;
            }
            case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:{//Evènement dépendant du clic de la souris
                switch (simcity->allegro.event.mouse.button) {
                    case 1:{//Clic gauche
                        calculHover(simcity);
                        detectionClique(simcity);
                        calculHoverBoutonAide(simcity);//Si la souris est sur le bouton aide
                        detectionCliqueBoutonAide(simcity);//Si la souris clic sur le bouton aide
                        if (simcity->pages.menuPrincipal.aideClique == true){//Si on a cliqué sur aide
                            boucletestMenuRegles(simcity);//On affiche le menu Règles du jeu
                        }
                        simcity->dessin = true;//On met à jour la page
                        break;
                    }
                }
                break;
            }
            case ALLEGRO_EVENT_MOUSE_BUTTON_UP:{
                break;
            }
            case ALLEGRO_EVENT_TIMER:{//Evènement dépendant du timer

                simcity->dessin = true;//On met à jour la page

                if (simcity->dessin) {//Si on doit mettre à jour la page
                    afficherMenuPrincipal(simcity);//On affiche le menu principal
                    al_flip_display();//On rafraichi l'affichage
                    simcity->dessin = false;//On ne met pas à jour la page
                }
                break;
            }
        }
    }
}

///Fonction permettant de lancer le Communiste et Capitaliste
void boucletestMenuCommunisteCapitaliste(Simcity* simcity){
    while (!simcity->pages.menuCapitalisteCommuniste.menuCapitalisteCommuniste) {

        al_wait_for_event(simcity->allegro.queue, &simcity->allegro.event);

        switch (simcity->allegro.event.type) {

            case ALLEGRO_EVENT_DISPLAY_CLOSE:{//Evènement "Fermer écran"
                simcity->endGame = true;//On met fin au jeu
                simcity->pages.menuCapitalisteCommuniste.menuCapitalisteCommuniste = true;//On quitte le menu Capitaliste et Communiste
                simcity->pages.menuPrincipal.menuPrincipal = true;//On ne peut pas aller dans le menu principal
                break;
            }
            case ALLEGRO_EVENT_MOUSE_AXES:{//Evènement dépendant de la position de la souris
                simcity->allegro.coordonneesSourisX = simcity->allegro.event.mouse.x;//Récupération des coordonnées de la souris selon l'axe X
                simcity->allegro.coordonneesSourisY = simcity->allegro.event.mouse.y;//Récupération des coordonnées de la souris selon l'axe Y
                calculHoverComCap(simcity);//Test permettant de savoir où est la souris sur le menu
                simcity->dessin = true;//On doit mettre à jour la page
                break;
            }
            case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:{//Evènement dépendant du clic de la souris
                switch (simcity->allegro.event.mouse.button) {
                    case 1:{//Clic gauche
                        detectionCliqueMenuCapCom(simcity);//Détection du clic
                        simcity->dessin = true;//On doit mettre à jour la page
                        break;
                    }
                }
                break;
            }
            case ALLEGRO_EVENT_MOUSE_BUTTON_UP:{
                break;
            }
            case ALLEGRO_EVENT_TIMER:{//Evènement dépendant du timer

                simcity->dessin = true;//On doit mettre à jour la page

                if (simcity->dessin) {//Si on doit mettre à jour la page
                    afficherMenuComCap(simcity);//On affiche le menu Capitaliste et Communiste
                    al_flip_display();//On rafraichi l'affichage
                    simcity->dessin = false;//On ne met plus à jour l'affichage
                }
                break;
            }
        }
    }
}


///Fonction permettant le lancement de la partie
void lancerJeu() {
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
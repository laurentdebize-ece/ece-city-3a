#ifndef ECE_CITY_3A_STRUCTURES_H
#define ECE_CITY_3A_STRUCTURES_H


#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_audio.h>

#define NBCELLULEX 45 //const pour la map
#define NBCELLULEY 35 //const pour la map

#define SCREEN_LARGEUR 1024 //const taille écran large
#define SCREEN_HAUTEUR 768 //const taille écran haut

#define NBR_MAX_HAB 50 //const nombre max de batiments possible
#define NBR_MAX_INFRA 15 //const nombre max de batiments possible
#define NBR_COORDS_XY_HAB 8 //const taille du contour d'une habitation
#define NBR_COORDS_XY_INFRA 16 //const taille du contour d'une infrastructure


enum BITMAP{BITMAP_MAP, BITMAP_TOOLBOX,BITMAP_BARRECOMPTEURS, BITMAP_BOUTON_PAUSE ,BITMAP_MENU_PRINCIPAL_INTRO, BITMAP_MENU_PRINCIPAL, BITMAP_MENU_COMMUNISTE_CAPITALISTE, BITMAP_BOUTONS_MENU_COMMUNISTE_CAPITALISTE, BITMAP_BOUTON_AIDE, BITMAP_FEU, BITMAP_BOUTTON_MENU_PRINCIPAL, BITMAP_REGLES1, BITMAP_REGLES2, NB_BITMAP};
enum SPRITE_MAP {HERBE, HOVER_TILE,  ROUTE, TERRAIN_VAGUE, CABANE, MAISON, IMMEUBLE, GRATTE_CIEL,ELEC_DROIT, ELEC_COTE, EAU_DROIT, EAU_COTE, POMPIER_DROIT, POMPIER_COTE,NB_SPRITE_MAP};
enum SPRITE_MENU_PRINCIPAL {INTRO , FOND,LANCER, LANCER_HOVER, LANCER_CLIQUE, CHARGER, CHARGER_HOVER, CHARGER_CLIQUE, QUITTER, QUITTER_HOVER, QUITTER_CLIQUE, AIDE, AIDE_HOVER, AIDE_CLIQUE, NB_SPRITE_MENU_PRINCIPAL};
enum SPRITE_MENU_COMMUNISTE_CAPITALISTE {FOND2, COMMUNISTE, COMMUNISTE_HOVER, COMMUNISTE_CLIQUE, CAPITALISTE, CAPITALISTE_HOVER, CAPITALISTE_CLIQUE ,NB_SPRITE_MENU_COMMUNISTE_CAPITALISTE};
enum SPRITE_REGLES_JEU {REGLES1, REGLES2, BOUTON_PREC, BOUTON_SUIV, BOUTON_MENU, NB_SPRITE_REGLES_JEU};

enum SPRITE_BOITE_A_OUTIL {ROUTE_, ROUTE_HOVER, ROUTE_CLIQUE,MAISON_, MAISON_HOVER, MAISON_CLIQUE,ELEC, ELEC_HOVER, ELEC_CLIQUE, EAU, EAU_HOVER, EAU_CLIQUE, DETRUIRE, DETRUIRE_HOVER, DETRUIRE_CLIQUE, VUE1, VUE1_HOVER, VUE1_CLIQUE,VUE2, VUE2_HOVER, VUE2_CLIQUE, POMPIER, POMPIER_HOVER, POMPIER_CLIQUE, PAUSE, PAUSE_HOVER, PAUSE_CLIQUE, NB_SPRITE_TOOL_BOX};
enum COLOR{ BLACK, WHITE, ORANGE};
enum TYPE_BLOC{TYPE_HERBE,TYPE_ROUTE,TYPE_TERRAIN_VAGUE,TYPE_CABANE,TYPE_MAISON,TYPE_IMMEUBLE,TYPE_GRATTE_CIEL, TYPE_ELEC_DROIT, TYPE_ELEC_COTE, TYPE_EAU_DROIT, TYPE_EAU_COTE, TYPE_POMPIER_DROIT, TYPE_POMPIER_COTE, NB_TYPE_BLOC};

typedef struct ListeAdj ListeAdj;
typedef struct Element Element;


typedef struct {
    ALLEGRO_DISPLAY* display;//Ecran
    ALLEGRO_EVENT_QUEUE* queue;//File d'évènements
    ALLEGRO_FONT* fonts[5];//Tableau qui contient toutes les polices
    ALLEGRO_EVENT event;//Evènement

    //Coordonnées de la souris
    int coordonneesSourisX;
    int coordonneesSourisY;

    ALLEGRO_TIMER* timer;//Timer 1
    ALLEGRO_TIMER* chrono;//Timer 2
    int compteurSecondes; //Permet de savoir le nombre de secondes écoulées pour le chrono
    int compteur;
    ALLEGRO_SAMPLE* music[10];//Tableau qui contient tous les sons du jeu
    ALLEGRO_COLOR color[3];//Tableau qui contient toutes les couleurs du jeu

} Allegro;

typedef struct {
    ALLEGRO_BITMAP** image;//pointeur sur sprite de skin de personnages
    int spriteX, spriteY, spriteHauteur, spriteLargeur;//Position de l'image dans le sprite
    int screenX, screenY, screenXFixe, screenYFixe;//Position sur l'écran

} Bitmap;

typedef struct {
    int screenX, screenY; //Position sur l'écran
    int celluleX, celluleY; //Position transcrite en cellule (en fonction des tailles de tuile)

} CoordsXY;

typedef struct {
    CoordsXY celluleXY;
    int clic;
    bool outOfMapBorders;
    bool boolChangementDeCelluleIso;
    bool boolCliqueDeplacement;

} Souris;

typedef struct {
    bool tabTouches[10];//Permet de connaître quelle touche est enfoncée
    bool tab;

} Clavier;

typedef struct {
    Clavier keyboard;
    Souris mouse;
    int compteurTimer;
    int nbSecondes;
    int chronoTour;
} InteractionExterieure;

typedef struct {
    Bitmap tabSpriteMenu[NB_SPRITE_MENU_PRINCIPAL];
    bool menuPrincipalIntro;
    bool menuPrincipal; //permet de rester dans la boucle de cette page
    bool lancer;
    bool lancerHover;
    bool lancerClique;
    bool charger;
    bool chargerHover;
    bool chargerClique;
    bool quitter;
    bool quitterHover;
    bool quitterClique;
    bool aide;
    bool aideHover;
    bool aideClique;

} PageMenuPrincipal;

typedef struct PageMenuCapitalisteCommuniste {
    Bitmap tabSpriteMenu[NB_SPRITE_MENU_COMMUNISTE_CAPITALISTE];
    bool menuCapitalisteCommuniste;
    bool capitalisteHover;
    bool capitalisteClique;
    bool communisteHover;
    bool communisteClique;
} PageMenuCapitalisteCommuniste;
/*
typedef struct {
    Bitmap tabSpriteMenu[NB_SPRITE_REGLES_JEU];
    bool menuReglesJeu;
    bool ReglesJeu1;
    bool ReglesJeu2;
    bool retourMenuCLique;
    bool retourMenuHover;
    bool precedentClique;
    bool precedentHover;
    bool suivantClique;
    bool suivantHover;
}PageReglesJeu;*/

typedef struct {
    PageMenuPrincipal menuPrincipal;
    PageMenuCapitalisteCommuniste menuCapitalisteCommuniste;
    //PageReglesJeu reglesJeu;
}Pages;

typedef struct {
    CoordsXY coordsXY;
    int spriteLargeur, spriteHauteur;
    int spriteHalfLargeur, spriteHalfHauteur;
    int typeBloc; //Proviendra du .txt qui permet de charger la map (1 = herbe, 2 = maison, 3 = immeuble,...)

} Tile;

typedef struct {
    Tile mapTile[NBCELLULEX][NBCELLULEY];//Tableau à 2 dimensions de Tuiles qui permet de générer la map
    CoordsXY Origine;
    Bitmap spriteTile[NB_SPRITE_MAP]; //Permet de connaître les tuiles et leur position dans le .png
    bool cliqueRoute;
    int compteurCheminsX, compteurCheminsY;
    int creationRouteX, creationRouteY;
} Map;

typedef struct {
    Bitmap tabSpriteToolBox[NB_SPRITE_TOOL_BOX];//Tableau regroupant les sprites de la ToolBox
    bool pauseEnMain;
    bool terrainVagueEnMain;
    bool routeEnMain;
    bool pompierEnMain;
    bool detruireEnMain;
    bool elecEnMain;
    bool eauEnMain;
    bool vue1EnMain;
    bool vue2EnMain;

    bool routeHover;
    bool maisonHover;
    bool elecHover;
    bool eauHover;
    bool detruireHover;
    bool vue1Hover;
    bool vue2Hover;
    bool pompierHover;
    bool pauseHover;

    bool routeClique;
    bool maisonClique;
    bool elecClique;
    bool eauClique;
    bool detruireClique;
    bool vue1Clique;
    bool vue2Clique;
    bool pompierClique;
    bool pompierDroit;
    bool elecDroit;
    bool eauDroit;
    bool pauseClique;

} ToolBox;



typedef struct {
    CoordsXY coordXY[NBR_COORDS_XY_HAB];//Coordonnées du bâtiment
    int typeBatiment;//Type de bâtiment (ici 1 car habitation)
    int nbHabitants;//Nombre d'habitants actuel

    //Variables relatives à l'état d'évolution du bâtiment
    int compteurEvolution;//Etat d'évolution actuelle
    bool evolutionPossible;//Test "est-ce que le bâtiment peut évoluer ?"
    bool regression;//Régression du bâtiment

    //Variables relatives aux prix des différentes infrastructures
    int prixTerrainVague;
    int prixPompier;
    int prixChateauEau;
    int prixElectricite;
    int prixRoute;

    //Variables relatives au timer du bâtiment
    int timerBatiment;//Timer du bâtiment (=temps écoulé depuis sa création)
    bool timerCree;//Timer du bâtiment lancé (=bâtiment créé)
    int dateCreation;//Date de création du bâtiment

    bool isFeu;//Test "le bâtiment est eb feu ?"

    int capaciteElectriqueMax;//correspond a combien d'elec elle a besoin
    int capaciteEauMax;//correspond a combien d'eau elle a besoin

    int capaciteElectriqueRecu;//quantité d'électricité reçue
    int capaciteEauRecu;//quantité d'eau reçue

} Habitation;

typedef struct {
    CoordsXY coordXY[NBR_COORDS_XY_INFRA];
    int typeBatiment;
    int capaciteElectrique;
    int capaciteEau;
    bool enFeu;
    ListeAdj *adjacence;//liste des adjacents du batiment (centrale ou chateau)
} Batiment;

///liste chainée pour les adjacences depuis la centrale

struct Element{

    int distanceAMonBatiment;
    Habitation* MaMaison;//habitation sur laquelle pointe mon element de ma liste chainée d'adjacence de la centrale
    struct Element *suivant;
};


//structure de controle pour prendre le 1er element

struct ListeAdj {
    Element *premier;
    Element *dernier;
};

typedef struct {
    //Variables relatives à la date fictive
    int mois;//Mois actuel
    int annee;//Année actuelle

    //Variables relatives au temps de jeu
    int secondes;//Secondes actuelles
    int minutes;//Minutes de jeu actuelles
    int dateLancementTempsJeu;//Date à laquelle la partie commence
    bool zeroDevantMinutes;//Paramétrage de l'affichage du temps de jeu
    bool zeroDevantSecondes;//Paramétrage de l'affichage du temps de jeu

}Timers;

typedef struct {
    //Action d'acheter un batiment
    bool achatTerrainVague;
    bool achatPompier;
    bool achatChateauEau;
    bool achatElectricite;
    bool achatRoute;

    //Prix des batiments
    int prixTerrainVague;
    int prixPompier;
    int prixChateauEau;
    int prixElectricite;
    int prixRoute;

}Banque;


/////SOMMET/////
typedef struct Cellule{

    int *pointeursurHabitation;
    int *pointeursurBatiment;

    CoordsXY coordsXYCellule;
    struct Cellule* suivant;
    enum TYPE_BLOC type;
    int couleur;
    //si ma case = maison, alors pointeur vers structurs maison posée dessus
    Habitation habitation;
    Batiment batiment;

}Cellule;
typedef struct Cellule *pCellule;

//////ARC/////
struct Arc{
    struct Arc *arc_suivant;
    int sommet;///type
};
typedef struct Arc *pArc;

//////GRAPHE/////
typedef struct Graphe {
    int ordre;
    Cellule grille[NBCELLULEX][NBCELLULEY];
}Graphe;

typedef struct {
    Allegro allegro;// Contient tous les éléments ALLEGRO
    ALLEGRO_BITMAP* tabBitmap[NB_BITMAP];
    InteractionExterieure interactionExterieure;
    Map map;//carte du jeu
    Pages pages;
    ToolBox toolBox;
    Timers timers;
    Habitation tabHabitation[NBR_MAX_HAB];//Tableau contenant toutes les habitations et leurs informations
    Batiment tabInfrastructure[NBR_MAX_INFRA];//Tableau contenant toutes les infrastructures et leurs informations
    Banque banque;
    Graphe graphe;

    int argent;//Argent total du joueur
    int nbHabitations;//Nombre d'habitations de la ville
    int nbInfrastructures;//Nombre d'infrastructures de la ville
    int nbHabitants;//Nombre d'habitants de la ville
    int capaciteEauRestante;//Capacité en eau disponible
    int capaciteElecRestante;//Capacité en électricité disponible

    bool dessin;
    bool endGame;
    bool outOfBorder;
    bool pause;

    //Mode de jeu
    bool capitaliste;
    bool communiste;

} Simcity;


void installAllegro();
void declarerAllegro(Simcity* simcity);
void registerEvents(Simcity* simcity);
void displayCreate(Simcity* simCity);
void queueCreate(Simcity* simcity);
void timerCreate(Simcity* simcity);
void fontsCreate(Simcity* simcity);
void colorCreate(Simcity* simcity);
void initAllegroAll(Simcity* simcity);
void libererDisplay(Simcity* simcity);
void libererTimer(Simcity* simcity);
void libererQueue(Simcity* simcity);
void libererFonts(Simcity* simcity);
void libererAll(Simcity* simcity);


#endif

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

enum BITMAP{BITMAP_MAP, BITMAP_MENU_PRINCIPAL_INTRO, BITMAP_MENU_PRINCIPAL, BITMAP_BOUTTON_MENU_PRINCIPAL,NB_BITMAP};
enum SPRITE_MAP {HERBE, HOVER_TILE, ROUTE, TERRAIN_VAGUE, CABANE, MAISON, IMMEUBLE, GRATTE_CIEL, NB_SPRITE_MAP};
enum SPRITE_MENU_PRINCIPAL { INTRO , FOND,LANCER, LANCER_HOVER, LANCER_CLIQUE, CHARGER, CHARGER_HOVER, CHARGER_CLIQUE, QUITTER, QUITTER_HOVER, QUITTER_CLIQUE,NB_SPRITE_MENU_PRINCIPAL};
enum{HABITATION,NIVEAU1, NIVEAU2,NB_SPRITE_TOOL_BOX};

typedef struct {
    ALLEGRO_DISPLAY* display;
    ALLEGRO_EVENT_QUEUE* queue;
    ALLEGRO_FONT* fonts[5];
    ALLEGRO_EVENT event;
    int coordonneesSourisX;
    int coordonneesSourisY;
    ALLEGRO_TIMER* timer;
    ALLEGRO_TIMER* chrono;
    int compteurSecondes; //Permet de savoir le nombre de secondes écoulées pour le chrono
    int compteur;
    ALLEGRO_SAMPLE* music[10]; //tableau qui contient tous les sons du jeu

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

} PageMenuPrincipal;

typedef struct {
    PageMenuPrincipal menuPrincipal;
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
    int compteurChemins;

} Map;

typedef struct {
    Bitmap tabSpriteToolBox[NB_SPRITE_TOOL_BOX];
    bool terrainVagueEnMain;
    bool routeEnMain;
} ToolBox;

typedef struct {
    bool achatTerrainVague;
    bool achatPompier;
    bool achatChateauEau;
    bool achatElectricite;
    int prixTerrainVague;
    int prixPompier;
    int prixChateauEau;
    int prixElectricite;
    int timerBatiment;
    int compteurEvolution;
    int nbHabitants;
} Batiment;

typedef struct {
    Allegro allegro;// Contient tous les éléments ALLEGRO
    ALLEGRO_BITMAP* tabBitmap[NB_BITMAP];
    InteractionExterieure interactionExterieure;
    Map map; //carte du jeu
    Pages pages;
    ToolBox toolBox;
    Batiment batiment;
    bool dessin;
    bool endGame;
    bool outOfBorder;
    int argent;
    int mois;
    int annee;
    int nbBatiments; //a mettre a jour a chaque fois qu'on cree un batiment
    Batiment tabBatiment; //remplir le tableau avec le nouveau batiment a chaque fois qu'il est crée

} Simcity;


void installAllegro();
void declarerAllegro(Simcity* simcity);
void registerEvents(Simcity* simcity);
void displayCreate(Simcity* simCity);
void queueCreate(Simcity* simcity);
void timerCreate(Simcity* simcity);
void initAllegroAll(Simcity* simcity);
void libererDisplay(Simcity* simcity);
void libererTimer(Simcity* simcity);
void libererQueue(Simcity* simcity);
void libererAll(Simcity* simcity);


#endif

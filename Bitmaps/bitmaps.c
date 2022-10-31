#include "bitmaps.h"
#include "../Structures/structures.h"

void bitmapCreateMap(Simcity* simcity){
    simcity->tabBitmap[BITMAP_MAP] = al_load_bitmap("../Sources/img/tiles.png");
}

void bitmapCreateAll(Simcity* simcity){
    bitmapCreateMap(simcity);
}

void libererBitmapMap(Simcity* simcity){
    al_destroy_bitmap(simcity->tabBitmap[BITMAP_MAP]);
}

void libererBitmapAll(Simcity* simcity){
    libererBitmapMap(simcity);
}


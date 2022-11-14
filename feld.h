#ifndef FELD_H
#define FELD_H

#include <SDL2/SDL.h>
#include "conf.h"

#define FELDDIMENSION 32

// Nur vorübergehend
#define FELD_LUFT 0
#define FELD_GRAS 1
#define FELD_DRECK 2
#define FELD_STEIN 3
#define FELD_HOLZ 4
#define FELD_SAND 5
#define FELD_WASSER 6

typedef struct Feld {
    int x;
    int y;
    SDL_Texture *textur;
} Feld;

extern int feld_erzeugen(int x, int y, SDL_Texture *textur);
extern int feld_entfernen(Feld *feld);

#endif

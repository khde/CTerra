#ifndef WELT_H
#define WELT_H

#include "feld.h"
#include "conf.h"
#include "vektor.h"

#define CHUNKDIMENSION 64
#define CHUNKANZAHL 9

typedef struct Chunk {
    Koordinate koordinate;
    Feld felder[CHUNKDIMENSION];
} Chunk;

typedef struct Welt {
    Chunk chunks[CHUNKANZAHL];
} Welt;

extern Welt welt_laden(const char *pfad);
extern int welt_speichern(const char *pfad);
extern int welt_akktualisieren(void);
extern int welt_zeichnen(void);

#endif

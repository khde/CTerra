#ifndef EINGABE_H
#define EINGABE_H

#include <stdbool.h>

typedef struct EingabeTastatur {
    bool links;
    bool rechts;
    bool springen;
    bool ducken;
} EingabeTastatur;

typedef struct EingabeMaus {
    bool links;
    bool rechts;
    int x;
    int y;
} EingabeMaus;

typedef struct Eingabe {
    EingabeTastatur tastatur;
    EingabeMaus maus;
} Eingabe;

int verarbeiteEingabe(Eingabe *eingabe);

#endif

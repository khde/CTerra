#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

#include "conf.h"
#include "spielschleife.h"
#include "eingabe.h"
#include "welt.h"


int cterra(int argc, char *argv[]) {
    SDL_Window *fenster;
    SDL_Renderer *renderer;
    
    if (SDL_Init(SDL_INIT_EVERYTHING)) {
        fprintf(stderr, "Init SDL Fehler!\n");
        return EXIT_FAILURE;
    }
    
    fenster = SDL_CreateWindow(TITEL,
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            FENSTERB,
            FENSTERH,
            SDL_WINDOW_SHOWN);
    
    if (fenster == NULL) {
        fprintf(stderr, "Init Fenster Fehler!\n");
        return EXIT_FAILURE;
    }
    
    renderer = SDL_CreateRenderer(fenster,
            -1, 
            SDL_RENDERER_ACCELERATED);
    
    if (renderer == NULL) {
        fprintf(stderr, "Init Renderer Fehler!\n");
        return EXIT_FAILURE;
    }
    
    int laufend = 1;
    while (laufend) {
        Eingabe eingabe = {0};
        
        // Erste Eingabe
        laufend = verarbeiteEingabe(&eingabe);
        
        // Dann Rendern und Logik
        laufend = spielschleife(renderer, &eingabe);
        
        SDL_RenderPresent(renderer);
    }
    
    SDL_DestroyWindow(fenster);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    
    return EXIT_SUCCESS;
}

#include <SDL2/SDL.h>
#include "eingabe.h"
#include "steuerung.h"


int verarbeiteEingabe(Eingabe *eingabe) {
    //SDL_PumpEvents();
    SDL_GetMouseState(&(eingabe->maus.x), &(eingabe->maus.y));
    
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                return 0;
                
            case SDL_MOUSEBUTTONDOWN:
                switch (event.button.button) {
                    case SDL_BUTTON_LEFT:
                        eingabe->maus.links = true;
                        break;
                    case SDL_BUTTON_RIGHT:
                        eingabe->maus.rechts = true;
                        break;
                }
            break;
            
            case SDL_MOUSEBUTTONUP:
                switch (event.button.button) {
                    case SDL_BUTTON_LEFT:
                        eingabe->maus.links = false;
                        break;
                    case SDL_BUTTON_RIGHT:
                        eingabe->maus.rechts = false;
                        break;
                }
            break;
            
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {
                    case LINKS:
                        eingabe->tastatur.links = true;
                        break;
                    case RECHTS:
                        eingabe->tastatur.rechts = true;
                        break;
                    case SPRINGEN:
                        eingabe->tastatur.springen = true;
                        break;
                    case DUCKEN:
                        eingabe->tastatur.ducken = true;
                        break;
                }
            break;
            
            case SDL_KEYUP: 
                switch (event.key.keysym.sym) {
                    case LINKS:
                        eingabe->tastatur.links = false;
                        break;
                    case RECHTS:
                        eingabe->tastatur.rechts = false;
                        break;
                    case SPRINGEN:
                        eingabe->tastatur.springen = false;
                        break;
                    case DUCKEN:
                        eingabe->tastatur.ducken = false;
                        break;
                }
            break;
        }
    }
    return 1;
}

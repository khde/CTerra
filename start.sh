#!/bin/bash

gcc main.c welt.c cterra.c feld.c eingabe.c -o cterra -Wall -lSDL2 && ./cterra

echo %$

#ifndef PERSO_H_
#define PERSO_H_
#include "SDL/SDL_image.h"
#include "SDL/SDL.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Perso
{
SDL_Surface *surPerso;
SDL_Rect position;
int score;
int damage;
int life;
int state;
}Perso;


void initialiser(Perso *p);
void afficher(Perso *p, SDL_Surface *ecran2);

#endif /* PERSO_H_ */



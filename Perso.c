#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Perso.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL.h"
//surPerso = surface perso
void initialiser(Perso *p)
{
 p->surPerso = IMG_Load("Perso.png");
 p->position.x = 400;
 p->position.y = 400;
 p->life = 3;
 p->score = 0;
 p->damage = 10;
 p->state = 1 ;
}
void afficher(Perso *p,SDL_Surface *ecran2)
{
SDL_BlitSurface(p->surPerso, NULL, ecran2, &p->position);
}


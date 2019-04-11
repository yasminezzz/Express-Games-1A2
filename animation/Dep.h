#ifndef DEP_H_
#define DEP_H_
#include "SDL/SDL_image.h"
#include "SDL/SDL.h"
#include <stdio.h>
#include "Perso.h"
#include <stdlib.h>
		#include "Constants.h"

void deplacer (Perso *p, SDL_Surface *ecran2);
//void deplacer2(Perso *p, SDL_Surface *ecran2);
void fixerDirectionSprite( Perso *sprite, int direction );
void miseAJourSprite( Perso *sprite );
//void dessinerSprite( Perso *sprite, SDL_Surface *destination );
#endif /* DEP_H_ */

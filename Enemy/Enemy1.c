#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdlib.h>
#include <stdio.h>
#include "Enemy1.h"

void Initialize_Enemy1(Enemy1 *E1)
{
	E1->Enemy_Picture_R = IMG_Load("Enemy1_R.png");
	E1->Enemy_Picture_L = IMG_Load("Enemy1_L.png");
	E1->Enemy_Position.x = 400; // à voir
	E1->Enemy_Position.y = 50; // à voir
	E1->Life = 100;
	E1->Damage = 10;
	E1->State = 1;
	E1->R=1;
	E1->L=0;
}

/**-------------------------------------------------------------------------------------------------**/

void Display_Enemy1_R(Enemy1 *E1, SDL_Surface *Destination)
{
	SDL_BlitSurface(E1->Enemy_Picture_R, NULL, Destination, &E1->Enemy_Position);
}

void Display_Enemy1_L(Enemy1 *E1, SDL_Surface *Destination)
{
	SDL_BlitSurface(E1->Enemy_Picture_L, NULL, Destination, &E1->Enemy_Position);
}

/**-------------------------------------------------------------------------------------------------**/


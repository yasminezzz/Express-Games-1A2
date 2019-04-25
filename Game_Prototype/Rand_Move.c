#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdlib.h>
#include <stdio.h>
#include "Enemy1.h"
#include "Rand_Move.h"

void Random_Movement(Enemy1 *E1, SDL_Surface *Destination)
{
	SDL_Rect Rep;

	Rep=E1->GP;
	if(E1->Life!=0)
	{
		if(E1->R==1)
		{
			if(E1->Enemy_Position.x==E1->C.x+300)
			{
				E1->R=0;
				E1->L=1;
				E1->Enemy_Position.x=E1->Enemy_Position.x-2;
				Display_Enemy1_L(E1,Destination);
			}
			else
			{
				E1->Enemy_Position.x=E1->Enemy_Position.x+2;
				Display_Enemy1_R(E1,Destination);
			}
		}
		else if(E1->L==1)
		{
			if(E1->Enemy_Position.x==E1->C.x-300)
			{
				E1->R=1;
				E1->L=0;
				E1->Enemy_Position.x=E1->Enemy_Position.x+2;
				Display_Enemy1_R(E1,Destination);
			}
			else
			{
				E1->Enemy_Position.x=E1->Enemy_Position.x-2;
				Display_Enemy1_L(E1,Destination);
			}
		}
		E1->GP.x=E1->Enemy_Position.x;
		E1->GP.y=E1->Enemy_Position.y+10;
	}
	else
	{
		SDL_BlitSurface(E1->DImg,NULL,Destination,&Rep);
	}
}
























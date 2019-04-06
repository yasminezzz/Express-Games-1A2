#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdlib.h>
#include <stdio.h>
#include "Enemy1.h"
#include "Rand_Move.h"

void Random_Movement(Enemy1 *E1, SDL_Surface *Destination)
{

		if(E1->R==1)
		{
			if(E1->Enemy_Position.x==1000)
			{
				E1->R=0;
				E1->L=1;
				E1->Enemy_Position.x=E1->Enemy_Position.x-1;
				Display_Enemy1_L(E1,Destination);
			}
			else
			{
				E1->Enemy_Position.x=E1->Enemy_Position.x+1;
				Display_Enemy1_R(E1,Destination);
			}
		}
		else if(E1->L==1)
		{
			if(E1->Enemy_Position.x==50)
			{
				E1->R=1;
				E1->L=0;
				E1->Enemy_Position.x=E1->Enemy_Position.x+1;
				Display_Enemy1_R(E1,Destination);
			}
			else
			{
				E1->Enemy_Position.x=E1->Enemy_Position.x-1;
				Display_Enemy1_L(E1,Destination);
			}
		}

}
























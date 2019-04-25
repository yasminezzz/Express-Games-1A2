#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdlib.h>
#include <stdio.h>
#include "Characters.h"
#include "Rand_Move.h"
#include "Background.h"
#include "GameMechanics.h"



int Collision_Enemy(Cha *Ch, Enemy1 *E1)
{
	int Case=0;

	if((Ch->MCP.x+40==E1->Enemy_Position.x)&&(Ch->MCP.y+60>E1->Enemy_Position.y))
		Case=1;
	else if((Ch->MCP.y+60==E1->Enemy_Position.y)&&(Ch->MCP.x+40>E1->Enemy_Position.x)&&(Ch->MCP.x<E1->Enemy_Position.x+40))
		Case=2;
	else if((Ch->MCP.x==E1->Enemy_Position.x+40)&&(Ch->MCP.y+60>E1->Enemy_Position.y))
		Case=3;
	return Case;

}

int Collision_World_Obj(Cha *Ch, WO *WOS)
{
	int Case=0;

	if((Ch->MCP.x+40==WOS->GR1P.x)&&(Ch->MCP.y+60>WOS->GR1P.y))
		Case=1;
	else if((Ch->MCP.y+60>=WOS->GR1P.y)&&(Ch->MCP.x+40>WOS->GR1P.x)&&(Ch->MCP.x+20<WOS->GR1P.x+1900))
		{
		Case=2;
		}
	else if((Ch->MCP.x==WOS->GR1P.x+40)&&(Ch->MCP.y+60>WOS->GR1P.y))
		Case=3;
	return Case;
}

void Jump(Cha *Ch, Enemy1 *E1, SDL_Rect OMCP, WO *WOS)
{
	if(Ch->MaxJ==1)
	{
		Ch->MCP.y=Ch->MCP.y-6;
		if(Ch->MCP.y==OMCP.y-180)
		{
			Ch->MaxJ=0;
		}
	}
	else if(Ch->MinJ!=1)
	{
		Ch->MCP.y=Ch->MCP.y+6;
		if(Collision_World_Obj(Ch,WOS)==2)
		{
			Ch->MinJ=1;
		}
	}
	else if((Ch->MinJ==1)&&(Collision_World_Obj(Ch,WOS)==0))
	{
		Ch->MinJ=0;
	}
}

void ScrollR(SDL_Rect *P)
{
	P->x=P->x+4;
}

void ScrollL(SDL_Rect *P)
{
	P->x=P->x-4;
}
























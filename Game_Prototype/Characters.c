#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdlib.h>
#include <stdio.h>
#include "Characters.h"

/*
typedef struct Character
{
	SDL_Surface *Img;
	SDL_Rect MCP;
	int MS;
	int Health;
	int Score;
	int JH;
	int MaxJ;
	int MinJ;
}Cha;
*/




void Init_Character(Cha *Ch)
{
	Ch->Img=IMG_Load("WR1.png");
	Ch->MCP.x=150;
	Ch->MCP.y=500;
	Ch->MS=4;
	Ch->Health=100;
	Ch->Score=0;
	Ch->JH=300;
	Ch->MaxJ=0;
	Ch->MinJ=0;
	Ch->DIR=1;
}

void Display_Character(Cha *Ch, SDL_Surface *Screen)
{
	SDL_BlitSurface(Ch->Img,NULL,Screen,&Ch->MCP);
}

void Move_CharR(Cha *Ch)
{
	Ch->MCP.x=Ch->MCP.x+Ch->MS;
}

void Move_CharL(Cha *Ch)
{
	Ch->MCP.x=Ch->MCP.x-Ch->MS;
}

void Anim_CharR(Cha *Ch, SDL_Surface *Screen, int *NC)
{
	switch(*NC)
	{
		case(0):
		{
			Ch->Img=IMG_Load("WR1.png");
		}
		break;
		case(3):
		{
			Ch->Img=IMG_Load("WR2.png");
		}
		break;
		case(6):
		{
			Ch->Img=IMG_Load("WR3.png");
		}
		break;
		case(9):
		{
			Ch->Img=IMG_Load("WR4.png");
		}
		break;
		case(12):
		{
			Ch->Img=IMG_Load("WR5.png");
		}
		break;
		case(15):
		{
			Ch->Img=IMG_Load("WR6.png");
		}
		break;
		case(18):
		{
			Ch->Img=IMG_Load("WR7.png");
		}
		break;
		case(21):
		{
			Ch->Img=IMG_Load("WR8.png");
		}
		break;
		case(24):
		{
			Ch->Img=IMG_Load("WR9.png");
		}
		break;
		case(27):
		{
			Ch->Img=IMG_Load("WR10.png");
		}
		break;
		case(30):
		{
			Ch->Img=IMG_Load("WR11.png");
		}
		break;
	}
	*NC=*NC+1;
	if(*NC==32)
	*NC=0;
}


void Anim_CharL(Cha *Ch, SDL_Surface *Screen, int *NC)
{
	switch(*NC)
	{
		case(0):
		{
			Ch->Img=IMG_Load("WL1.png");
		}
		break;
		case(3):
		{
			Ch->Img=IMG_Load("WL2.png");
		}
		break;
		case(6):
		{
			Ch->Img=IMG_Load("WL3.png");
		}
		break;
		case(9):
		{
			Ch->Img=IMG_Load("WL4.png");
		}
		break;
		case(12):
		{
			Ch->Img=IMG_Load("WL5.png");
		}
		break;
		case(15):
		{
			Ch->Img=IMG_Load("WL6.png");
		}
		break;
		case(18):
		{
			Ch->Img=IMG_Load("WL7.png");
		}
		break;
		case(21):
		{
			Ch->Img=IMG_Load("WL8.png");
		}
		break;
		case(24):
		{
			Ch->Img=IMG_Load("WL9.png");
		}
		break;
		case(27):
		{
			Ch->Img=IMG_Load("WL10.png");
		}
		break;
		case(30):
		{
			Ch->Img=IMG_Load("WL11.png");
		}
		break;
	}
	*NC=*NC+1;
	if(*NC==32)
	*NC=0;
}


















#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdlib.h>
#include <stdio.h>
#include "Background.h"









void Init_All_Objs(WO *WOS)
{
	WOS->GR1=IMG_Load("GR1.png");
	WOS->GR1P.x=0;
	WOS->GR1P.y=524;
}


void Init_BG(BGS *BG)
{
	BG->Background=IMG_Load("GBG.png");
	BG->BGP.x=0;
	BG->BGP.y=0;
}

void Display_All_World_Objects(WO *WOS, SDL_Surface *Screen)
{
	SDL_Rect Rep1;

	Rep1=WOS->GR1P;
	SDL_BlitSurface(WOS->GR1,NULL,Screen,&Rep1);
}

void Display_BG(BGS *BG,SDL_Surface *Screen)
{
	SDL_Rect Rep;

	Rep=BG->BGP;
	SDL_BlitSurface(BG->Background,NULL,Screen,&Rep);
}

SDL_Surface* Anim_Background0(SDL_Surface *Image, SDL_Surface *Screen, SDL_Rect BGP, int *NB)
{
	switch(*NB)
	{
		case(0):
		{
			Image=IMG_Load("1.jpg");
		}
		break;
		case(10):
		{
			Image=IMG_Load("2.jpg");
		}
		break;
		case(20):
		{
			Image=IMG_Load("3.jpg");
		}
		break;
		case(30):
		{
			Image=IMG_Load("4.jpg");
		}
		break;
		case(40):
		{
			Image=IMG_Load("5.jpg");
		}
		break;
		case(50):
		{
			Image=IMG_Load("6.jpg");
		}
		break;
		case(60):
		{
			Image=IMG_Load("7.jpg");
		}
		break;
		case(70):
		{
			Image=IMG_Load("8.jpg");
		}
		break;
		case(80):
		{
			Image=IMG_Load("9.jpg");
		}
		break;
		case(90):
		{
			Image=IMG_Load("10.jpg");
		}
		break;
		case(100):
		{
			Image=IMG_Load("11.jpg");
		}
		break;
		case(110):
		{
			Image=IMG_Load("12.jpg");
		}
		break;
		case(120):
		{
			Image=IMG_Load("13.jpg");
		}
		break;
		case(130):
		{
			Image=IMG_Load("14.jpg");
		}
		break;
		case(140):
		{
			Image=IMG_Load("15.jpg");
		}
		break;
		case(150):
		{
			Image=IMG_Load("16.jpg");
		}
		break;
		case(160):
		{
			Image=IMG_Load("17.jpg");
		}
		break;
		case(170):
		{
			Image=IMG_Load("18.jpg");
		}
		break;
		case(180):
		{
			Image=IMG_Load("19.jpg");
		}
		break;
		case(190):
		{
			Image=IMG_Load("20.jpg");
		}
		break;
		case(200):
		{
			Image=IMG_Load("21.jpg");
		}
		break;
		case(210):
		{
			Image=IMG_Load("22.jpg");
		}
		break;
		case(220):
		{
			Image=IMG_Load("23.jpg");
		}
		break;
		case(230):
		{
			Image=IMG_Load("24.jpg");
		}
		break;
	}
	SDL_BlitSurface(Image,NULL,Screen,&BGP);
	*NB=*NB+1;
	if(*NB==230)
	*NB=0;
	return Image;
}


void Anim_PlayB(SDL_Surface *Button, SDL_Surface *Screen, SDL_Rect Pos, int *NP)
{
	switch(*NP)
	{
		case(0):
		{
			Button=IMG_Load("P1.png");
			SDL_BlitSurface(Button,NULL,Screen,&Pos);
		}
		break;
		case(1):
		{
			Button=IMG_Load("P2.png");
			SDL_BlitSurface(Button,NULL,Screen,&Pos);
		}
		break;
		case(2):
		{
			Button=IMG_Load("P3.png");
			SDL_BlitSurface(Button,NULL,Screen,&Pos);
		}
		break;
		case(3):
		{
			Button=IMG_Load("P4.png");
			SDL_BlitSurface(Button,NULL,Screen,&Pos);
		}
		break;
		case(4):
		{
			Button=IMG_Load("P5.png");
			SDL_BlitSurface(Button,NULL,Screen,&Pos);
		}
		break;
		case(5):
		{
			Button=IMG_Load("P6.png");
			SDL_BlitSurface(Button,NULL,Screen,&Pos);
		}
		break;
		case(6):
		{
			Button=IMG_Load("P7.png");
			SDL_BlitSurface(Button,NULL,Screen,&Pos);
		}
		break;
		case(7):
		{
			Button=IMG_Load("P8.png");
			SDL_BlitSurface(Button,NULL,Screen,&Pos);
		}
		break;
	}
	*NP=*NP+1;
	if(*NP==7)
	*NP=0;
}



void Anim_SetsB(SDL_Surface *Button, SDL_Surface *Screen, SDL_Rect Pos, int *NS)
{
	switch(*NS)
	{
		case(0):
		{
			Button=IMG_Load("S1.png");
			SDL_BlitSurface(Button,NULL,Screen,&Pos);
		}
		break;
		case(1):
		{
			Button=IMG_Load("S2.png");
			SDL_BlitSurface(Button,NULL,Screen,&Pos);
		}
		break;
		case(2):
		{
			Button=IMG_Load("S3.png");
			SDL_BlitSurface(Button,NULL,Screen,&Pos);
		}
		break;
		case(3):
		{
			Button=IMG_Load("S4.png");
			SDL_BlitSurface(Button,NULL,Screen,&Pos);
		}
		break;
		case(4):
		{
			Button=IMG_Load("S5.png");
			SDL_BlitSurface(Button,NULL,Screen,&Pos);
		}
		break;
		case(5):
		{
			Button=IMG_Load("S6.png");
			SDL_BlitSurface(Button,NULL,Screen,&Pos);
		}
		break;
		case(6):
		{
			Button=IMG_Load("S7.png");
			SDL_BlitSurface(Button,NULL,Screen,&Pos);
		}
		break;
		case(7):
		{
			Button=IMG_Load("S8.png");
			SDL_BlitSurface(Button,NULL,Screen,&Pos);
		}
		break;
	}
	*NS=*NS+1;
	if(*NS==7)
	*NS=0;
}


void Anim_QuitB(SDL_Surface *Button, SDL_Surface *Screen, SDL_Rect Pos, int *NQ)
{
	switch(*NQ)
	{
		case(0):
		{
			Button=IMG_Load("Q1.png");
			SDL_BlitSurface(Button,NULL,Screen,&Pos);
		}
		break;
		case(1):
		{
			Button=IMG_Load("Q2.png");
			SDL_BlitSurface(Button,NULL,Screen,&Pos);
		}
		break;
		case(2):
		{
			Button=IMG_Load("Q3.png");
			SDL_BlitSurface(Button,NULL,Screen,&Pos);
		}
		break;
		case(3):
		{
			Button=IMG_Load("Q4.png");
			SDL_BlitSurface(Button,NULL,Screen,&Pos);
		}
		break;
		case(4):
		{
			Button=IMG_Load("Q5.png");
			SDL_BlitSurface(Button,NULL,Screen,&Pos);
		}
		break;
		case(5):
		{
			Button=IMG_Load("Q6.png");
			SDL_BlitSurface(Button,NULL,Screen,&Pos);
		}
		break;
		case(6):
		{
			Button=IMG_Load("Q7.png");
			SDL_BlitSurface(Button,NULL,Screen,&Pos);
		}
		break;
		case(7):
		{
			Button=IMG_Load("Q8.png");
			SDL_BlitSurface(Button,NULL,Screen,&Pos);
		}
		break;
	}
	*NQ=*NQ+1;
	if(*NQ==7)
	*NQ=0;
}

























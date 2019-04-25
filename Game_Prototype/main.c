#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdlib.h>
#include <stdio.h>
#include "Rand_Move.h"
#include "Background.h"
#include "Characters.h"
#include "GameMechanics.h"


int main(int argc, char *argv[])
{
	WO WOS;
	Cha MC;
	Enemy1 E1;
	BGS BG;
	SDL_Surface *Screen=NULL,*Background0=NULL,*Play1=NULL,*Play2=NULL,*Play3=NULL,*Sets1=NULL,*Sets2=NULL,*Sets3=NULL,*Quit1=NULL,*Quit2=NULL,*Quit3=NULL,*Title=NULL;
	SDL_Rect PBG0,PP,PS,PQ,PT,OMCP;
	SDL_Event Event,Event1;
	int Exit=0,GamePlay=1;
	int *NP=NULL,*NS=NULL,*NQ=NULL,*NB=NULL,*NC=NULL;
	SDL_Init(SDL_INIT_VIDEO);

	Screen=SDL_SetVideoMode(1200,700,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
	SDL_WM_SetCaption("The Way Back",NULL);

	Play1=IMG_Load("P.png");
	Play3=IMG_Load("P0.png");
	Sets1=IMG_Load("S.png");
	Sets3=IMG_Load("S0.png");
	Quit1=IMG_Load("Q.png");
	Quit3=IMG_Load("Q0.png");
	Title=IMG_Load("Title.png");


	PS.x=150;
	PS.y=350;
	PQ.x=750;
	PQ.y=350;
	PP.x=450;
	PP.y=230;
	PT.x=300;
	PT.y=0;
	PBG0.x=0;
	PBG0.y=0;

	NC=malloc(sizeof(int));
	NP=malloc(sizeof(int));
	NS=malloc(sizeof(int));
	NQ=malloc(sizeof(int));
	NB=malloc(sizeof(int));
	*NP=0;
	*NS=0;
	*NQ=0;
	*NB=0;
	*NC=0;

	Init_Character(&MC);
	Init_BG(&BG);
	Initialize_Enemy1(&E1);
	Init_All_Objs(&WOS);
	while(Exit!=1)
	{
		SDL_PollEvent(&Event);
		switch(Event.type)
		{
			case SDL_QUIT:
				Exit=1;
			break;
		}
		SDL_FillRect(Screen, NULL, SDL_MapRGB(Screen->format, 255, 255, 255));
		Background0=Anim_Background0(Background0,Screen,PBG0,NB);
		SDL_BlitSurface(Title,NULL,Screen,&PT);
		if((Event.motion.y>PP.y+35)&&(Event.motion.y<PP.y+265)&&(Event.motion.x>PP.x+35)&&(Event.motion.x<PP.x+265))
		{
				Anim_PlayB(Play2,Screen,PP,NP);
				SDL_BlitSurface(Sets1,NULL,Screen,&PS);
				SDL_BlitSurface(Quit1,NULL,Screen,&PQ);
				if(Event.button.button==SDL_BUTTON_LEFT)
				{
					if(Event.type==SDL_MOUSEBUTTONDOWN)
					{
						SDL_BlitSurface(Play3,NULL,Screen,&PP);
						SDL_BlitSurface(Sets1,NULL,Screen,&PS);
						SDL_BlitSurface(Quit1,NULL,Screen,&PQ);
						SDL_Flip(Screen);
						SDL_Delay(300);
					}
					else if(Event.type==SDL_MOUSEBUTTONUP)
					{
						SDL_EnableKeyRepeat(10, 10);
						while(GamePlay!=0)
						{
							SDL_PollEvent(&Event1);
							SDL_FillRect(Screen, NULL, SDL_MapRGB(Screen->format, 255, 255, 255));
							Display_BG(&BG,Screen);
							Display_All_World_Objects(&WOS,Screen);
							if(Collision_Enemy(&MC,&E1)==1||Collision_Enemy(&MC,&E1)==2||Collision_Enemy(&MC,&E1)==3)
							{
								SDL_BlitSurface(E1.DImg,NULL,Screen,&E1.GP);
								E1.Life=0;
							}
							else
	 						{
								Random_Movement(&E1,Screen);
							}
							Display_Character(&MC,Screen);
							Jump(&MC,&E1,OMCP,&WOS);
							SDL_Flip(Screen);
							switch(Event1.type)
							{
								case SDL_KEYDOWN:
								{
									switch(Event1.key.keysym.sym)
									{
										case SDLK_UP:
										{
											if(MC.MinJ==1)
											{
												MC.MaxJ=1;
												MC.MinJ=0;
												OMCP.y=MC.MCP.y;
											}
											else if(MC.DIR==1)
											{
												MC.Img=IMG_Load("WR1.png");
											}
											else
											{
												MC.Img=IMG_Load("WL1.png");
											}
										}
										break;
										case SDLK_RIGHT:
										{
											if(MC.MCP.x>=800)
											{
												if(BG.BGP.x+3800>0)
												{
													ScrollL(&BG.BGP);
													ScrollL(&WOS.GR1P);
													ScrollL(&E1.Enemy_Position);
													ScrollL(&E1.C);
													ScrollL(&E1.GP);
												}
											}
											else
											{
												Move_CharR(&MC);
											}
											if(MC.MinJ==1)
											{
												Anim_CharR(&MC,Screen,NC);
											}
											else
											{
												MC.Img=IMG_Load("WR1.png");
											}
											MC.DIR=1;
										}
										break;
										case SDLK_LEFT:
										{
											if(MC.MCP.x<=400)
											{
												if(BG.BGP.x<0)
												{
													ScrollR(&BG.BGP);
													ScrollR(&WOS.GR1P);
													ScrollR(&E1.Enemy_Position);
													ScrollR(&E1.C);
													ScrollR(&E1.GP);
												}
											}
											else
											{
												Move_CharL(&MC);
											}
											if(MC.MinJ==1)
											{
												Anim_CharL(&MC,Screen,NC);
											}
											else
											{
												MC.Img=IMG_Load("WL1.png");
											}
											MC.DIR=0;
										}
										break;
										case SDLK_ESCAPE:
										{
											GamePlay=0;
										}
										break;
									}
								}
								break;
								case SDL_KEYUP:
								{
									switch(Event1.key.keysym.sym)
									{
										case SDLK_UP:
										{
											if(MC.MinJ==1)
											{
												MC.Img=IMG_Load("SR1.png");
												if(MC.DIR==0)
												{
													MC.Img=IMG_Load("SL1.png");
												}
											}
											
										}
										break;
										case SDLK_RIGHT:
										{
											*NC=0;
											if(MC.MinJ==1)
											{
												MC.Img=IMG_Load("SR1.png");
											}
											else
											{
												MC.Img=IMG_Load("WR1.png");
											}	
										}
										break;
										case SDLK_LEFT:
										{
											*NC=0;
											if(MC.MinJ==1)
											{
												MC.Img=IMG_Load("SL1.png");
											}
											else
											{
												MC.Img=IMG_Load("WL1.png");
											}
										}
										break;
									}
								}
								break;
								case SDL_QUIT:
								{
									GamePlay=0;
									Exit=1;
								}
								break;
							}
						}
						GamePlay=1;
					}
				}				
		}
		else if((Event.motion.y>PS.y+35)&&(Event.motion.y<PS.y+265)&&(Event.motion.x>PS.x+35)&&(Event.motion.x<PS.x+265))
		{
				SDL_BlitSurface(Play1,NULL,Screen,&PP);
				Anim_SetsB(Sets2,Screen,PS,NS);
				SDL_BlitSurface(Quit1,NULL,Screen,&PQ);
				if(Event.button.button==SDL_BUTTON_LEFT)
				{
					//if(Event.type==SDL_MOUSEBUTTONDOWN)
					//{
						SDL_BlitSurface(Play1,NULL,Screen,&PP);
						SDL_BlitSurface(Sets3,NULL,Screen,&PS);
						SDL_BlitSurface(Quit1,NULL,Screen,&PQ);
						SDL_Flip(Screen);
						SDL_Delay(300);
					//}
					//else if(Event.type==SDL_MOUSEBUTTONUP)
					//{
					//}
				}
		}
		else if((Event.motion.y>PQ.y+35)&&(Event.motion.y<PQ.y+265)&&(Event.motion.x>PQ.x+35)&&(Event.motion.x<PQ.x+265))
		{
			SDL_BlitSurface(Play1,NULL,Screen,&PP);
			SDL_BlitSurface(Sets1,NULL,Screen,&PS);
			Anim_QuitB(Quit2,Screen,PQ,NQ);
			if(Event.button.button==SDL_BUTTON_LEFT)
			{
				if(Event.type==SDL_MOUSEBUTTONDOWN)
				{
					SDL_BlitSurface(Play1,NULL,Screen,&PP);
					SDL_BlitSurface(Sets1,NULL,Screen,&PS);
					SDL_BlitSurface(Quit3,NULL,Screen,&PQ);
					SDL_Flip(Screen);
					SDL_Delay(300);
				}
				else if(Event.type==SDL_MOUSEBUTTONUP)
				{
					Exit=1;
				}
			}
		}
		else
		{
			SDL_BlitSurface(Play1,NULL,Screen,&PP);
			SDL_BlitSurface(Sets1,NULL,Screen,&PS);
			SDL_BlitSurface(Quit1,NULL,Screen,&PQ);
		}

		SDL_Flip(Screen);
	}
	free(NP);
	free(NS);
	free(NQ);
	free(NB);
	SDL_FreeSurface(Title);
	SDL_FreeSurface(Screen);
	SDL_FreeSurface(Background0);
	SDL_FreeSurface(Play1);
	SDL_FreeSurface(Play2);
	SDL_FreeSurface(Play3);
	SDL_FreeSurface(Sets1);
	SDL_FreeSurface(Sets2);
	SDL_FreeSurface(Sets3);
	SDL_FreeSurface(Quit1);
	SDL_FreeSurface(Quit2);
	SDL_FreeSurface(Quit3);
	SDL_QUIT;
	return EXIT_SUCCESS;
}


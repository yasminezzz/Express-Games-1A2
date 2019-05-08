#include <SDL/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_image.h>
#include "bounding.h"
int main()
{
 SDL_Surface *ecran = NULL, *imageDeFond = NULL, *ninjad = NULL,*ninjag= NULL,*sh=NULL;
    SDL_Rect positionFond, positionninja1,positionninja2,positionsh;
int i=0,continuer=1;
SDL_Event event;

    
    positionFond.x = 0;
    positionFond.y = 0;
    positionninja1.x = 50;
    positionninja1.y = 425;
 positionninja2.x =900;
    positionninja2.y = 425;
positionsh.x=900;
positionsh.y=450; 
    SDL_Init(SDL_INIT_VIDEO);
    ecran = SDL_SetVideoMode(2000, 600, 32, SDL_HWSURFACE);
    SDL_WM_SetCaption("Chargement d'images en SDL", NULL);
    imageDeFond = IMG_Load("background.png");
    
    ninjad = IMG_Load("1.png");
ninjag = IMG_Load("2.png");
  sh=IMG_Load("sh.png");

SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
 SDL_BlitSurface(ninjad, NULL, ecran, &positionninja1);
SDL_BlitSurface(ninjag, NULL, ecran, &positionninja2);
    SDL_Flip(ecran);
SDL_EnableKeyRepeat(10, 10);
  while (continuer)
{

SDL_PollEvent(&event);
        switch(event.type)
{case SDL_QUIT:
continuer=0;
break;
case SDL_KEYDOWN:
{

switch(event.key.keysym.sym)
{
case  SDLK_RIGHT:
positionninja1.x +=10;
break;
case  SDLK_LEFT:
positionninja1.x -=10;

break;
}
}
}

 SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
if (check_collision(&positionsh,&positionninja1 )==false && i==0)
{if(positionninja2.x-positionninja1.x<600)
{
if((positionsh.x - positionninja1.x)>0)

positionsh.x-=30;

}

SDL_BlitSurface(sh, NULL, ecran, &positionsh); 
}
if (check_collision(&positionsh,&positionninja1 )==true)
i=1;
SDL_BlitSurface(ninjad, NULL, ecran, &positionninja1);
SDL_BlitSurface(ninjag, NULL, ecran, &positionninja2);
 SDL_Flip(ecran);

}
SDL_FreeSurface(ninjag);
SDL_FreeSurface(sh);
SDL_FreeSurface(ninjad);
}

#include <stdio.h>
#include <stdlib.h>
#include "obstacle2.h"

#include <SDL/SDL_image.h> 
void init()
{ 
 SDL_Surface *ecran = NULL, *imageDeFond = NULL, *sapin = NULL;
    SDL_Rect positionFond, positionSapin;

    positionFond.x = 0;
    positionFond.y = 0;
    positionSapin.x = 500;
    positionSapin.y = 260;
}
void affichage (SDL_Surface *ecran,SDL_Surface *imageDeFond,SDL_Surface *sapin,SDL_Rect positionFond, SDL_Rect positionSapin)
{
int continuer=0;
SDL_Event event;
    SDL_Init(SDL_INIT_VIDEO);

    SDL_WM_SetIcon(IMG_Load("sdl_icone.bmp"), NULL);

    ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE);
    SDL_WM_SetCaption("Chargement d'images en SDL", NULL);

    imageDeFond = IMG_Load("lac_en_montagne.bmp");
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);

    /* Chargement d'un PNG avec IMG_Load
    Celui-ci est automatiquement rendu transparent car les informations de
    transparence sont codées à l'intérieur du fichier PNG */
    sapin = IMG_Load("sapin.png");
    SDL_BlitSurface(sapin, NULL, ecran, &positionSapin);

    SDL_Flip(ecran);
     while (continuer) 
    {
        SDL_WaitEvent(&event); 
        switch(event.type) 
        {
            case SDL_QUIT: 
                continuer = 0; 
                break;
        }
    }

    SDL_FreeSurface(imageDeFond);
    SDL_FreeSurface(sapin);
    SDL_Quit();
}
int collision(SDL_Rect* rect1,SDL_Rect* rect2)
{
	if(rect1->y >= rect2->y + rect2->h)
		return 0;
	if(rect1->x >= rect2->x + rect2->w)
		return 0;
	if(rect1->y + rect1->h <= rect2->y)
		return 0;
	if(rect1->x + rect1->w <= rect2->x)
		return 0;
	return 1;
}
int Collision(int x,int y,cercle C)
{
   int d2 = (x-C.x)*(x-C.x) + (y-C.y)*(y-C.y);
   if (d2>C.rayon*C.rayon)
      return 0;
   else
      return 1;
}

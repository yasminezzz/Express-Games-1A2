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


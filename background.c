#include<stdio.h>
#include<stdlib.h>
#include <SDL/SDL.h>
#include"background.h"
#include <SDL/SDL_image.h>
int initialiser_background(SDL_Surface *ecran,SDL_Surface *imageDeFond,SDL_Rect *positionFond)
{
imageDeFond = NULL;
ecran=NULL;
  positionFond->x = 0;
    positionFond->y = 0;
  if (SDL_Init(SDL_INIT_VIDEO) == -1) 
    {
        fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError());
        exit(EXIT_FAILURE); 
    } 
  return EXIT_SUCCESS;
}
int afficher_background(SDL_Surface *ecran,SDL_Surface *imageDeFond,SDL_Rect positionFond)
{ 



SDL_Surface *icon=NULL;

ecran = SDL_SetVideoMode(1200,800, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
if (ecran==NULL)
{
 fprintf(stderr, "Impossible de charger le mode vidéo : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);

}
icon=IMG_Load("sdl_icone.bmp");
SDL_WM_SetIcon(icon, NULL);
SDL_WM_SetCaption("nom du jeu", NULL);
 imageDeFond = IMG_Load("background.png");
SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
SDL_Flip(ecran);

}

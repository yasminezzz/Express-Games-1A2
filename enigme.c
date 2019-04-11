#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <string.h>
#include <SDL/SDL_ttf.h>
#include "SDL.h"
#include "enigme.h"
/**************************/
void initialiser (enigme *e)
{
e->image = IMG_Load("enigme template.png");
e->pos.x = 0;// valeur exacte ou elle va etre afficher sur le background
e->pos.y = 0;
e->question = '';//strcopy copier chaine vide //strcopy de la question statique
e->reponse = '';//strcopy la reponse
e->resultat = 0;
}
/*****************************/
void afficher(enigme *e)
{
    SDL_Surface *ecran = NULL, *texte = NULL, *fond = NULL;
    SDL_Rect position;
    SDL_Event event;
    TTF_Font *police = NULL;
    SDL_Color couleurNoire = {0, 0, 0};
    int continuer = 1;

    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Enigme statique", NULL);

    fond = IMG_Load("enigme template.png");

    police = TTF_OpenFont("times.ttf",30); /*chargement police*/
    /* random [1 10] récuperer le num 
char ch1[];


*/
    texte = TTF_RenderText_Blended(police, "Which is the largest pyramid in Egypt?\n1.The Great Pyramid of Giza\n2.Pyramid of Khafre", couleurNoire); /*ecriture en mode blended dans SDL_Surface*/
//on ne peux pas ecrire une reponse dans le jeu, changer en qcm

    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
        }

        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));

        position.x = 0;
        position.y = 0;
        SDL_BlitSurface(fond, NULL, ecran, &position); /* Blit du fond */

        position.x = 200;
        position.y = 200;
        SDL_BlitSurface(texte, NULL, ecran, &position); /* Blit du texte */
        SDL_Flip(ecran);
    }

    TTF_CloseFont(police);
    TTF_Quit();

    SDL_FreeSurface(texte);
    SDL_Quit();

    return EXIT_SUCCESS;
   
 }
 
 /**********************/
int resolution(enigme *e,int reponse)
{
while (continuer)
{
    SDL_WaitEvent(&event);
    switch(event.type)
    {
        case SDL_QUIT:
            continuer = 0;
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
                case SDLK_1: /* sauvegarder reponse 1 */
                   reponse=1;
			continuer=0;
                    break;
            }
  case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
                case SDLK_1: /* sauvegarder reponse 2 */
                   reponse=2;
		continuer=0;
                    break;
            }
            break;
    }
}
return reponse;
}
/*****************************/

void aleatoire(enigme *e)
{



}
/************/
int reponse_verif(int score, int reponse)
{
if (reponse==1)
score=1;
else if (reponse!=1)
score=0;
return score;
}


//randomize un nombre qui va correspondre a une ligne, fscanf cette ligne 
//comparer la reponse dans la meme ligne

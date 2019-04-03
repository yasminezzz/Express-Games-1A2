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
e->pos.x = XPe;
e->pos.y = YPe;
e->question = '';
e->reponse = '';
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
    
    texte = TTF_RenderText_Blended(police, "I do not breathe, but I run and jump. I do not eat, but I swim and stretch.\nI do not drink, but I sleep and stand. I do not think, but I grow and play.\nI do not see, but you see me every day. Who am I?", couleurNoire); /*ecriture en mode blended dans SDL_Surface*/

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
int resolution(enigme *e, int score)
{
SDL_Event event;
    char im[100], im1[100], im2[100], im3[100];
    SDL_Surface *image = NULL,*image1 = NULL,*image2 = NULL,*image3 = NULL;
    SDL_Rect positionim;
    positionim.x =  0 ;
    positionim.y =  0 ;
    sprintf(im,"reponse/%d.png",score);/* composes a string with the same text that would be printed if format was used on printf */
    image= IMG_Load(im);
    sprintf(im1,"reponse/%d/1.png",score); 
    sprintf(im2,"reponse/%d/2.png",score);
    sprintf(im3,"reponse/%d/3.png",score);
    image1= IMG_Load(im1);
    image2= IMG_Load(im2);
    image3= IMG_Load(im3);
    SDL_BlitSurface(image,NULL,ecran,&positionim);
    SDL_Flip(ecran);
    int continuer =1;
    int i=0;



    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
        case SDL_QUIT:
            continuer=0;
            break;

        case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {

            case SDLK_RETURN:
                if(i>=1 && i<=3)
                {

                    if (i==1 && d%3==1)
                    {
                        good(ecran);
                        continuer=0;
                    }
                    else if (i==2 && d%3==2)
                    {
                        good(ecran);
                        continuer=0;
                    }
                    else if (i==3 && d%3==0)
                    {
                        good(ecran);
                        continuer=0;
                    }
                    else
                    {
                        solution(ecran,score);
                        continuer=0;
                    }
                }
                break;

            case SDLK_DOWN:
                i++;
                if(i==4)
                {
                    i=1;
                }
                if(i==1)
                {
                    SDL_BlitSurface(image1,NULL, ecran, &positionim);
                    SDL_Flip(ecran);
                    SDL_Delay(500);
                }
                if(i==2)
                {
                    SDL_BlitSurface(image2,NULL, ecran, &positionim);
                    SDL_Flip(ecran);
                    SDL_Delay(500);
                }
                if(i==3)
                {
                    SDL_BlitSurface(image3,NULL, ecran, &positionim);
                    SDL_Flip(ecran);
                    SDL_Delay(500);
                }
                ;
                break;
            case SDLK_UP:
                i--;
                if(i==0)
                {
                    i=3;
                }
                if(i==4)
                {
                    i=1;
                }
                if(i==1)
                {
                    SDL_BlitSurface(image1,NULL, ecran, &positionim);
                    SDL_Flip(ecran);
                    SDL_Delay(500);
                }
                if(i==2)
                {
                    SDL_BlitSurface(image2,NULL, ecran, &positionim);
                    SDL_Flip(ecran);
                    SDL_Delay(500);
                }
                if(i==3)
                {
                    SDL_BlitSurface(image3,NULL, ecran, &positionim);
                    SDL_Flip(ecran);
                    SDL_Delay(500);
                }
                break;
            }
        }
        //SDL_BlitSurface(image,NULL,ecran,&positionim);
        SDL_Flip(ecran);
    }

}
 

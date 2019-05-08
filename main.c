#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <math.h>
int main(int argc, char *argv[])
{
    SDL_Surface *ecran = NULL, *texte = NULL;
    SDL_Rect position;
    SDL_Event event;
    TTF_Font *police = NULL;
    SDL_Color couleurNoire = {0, 0, 0}, couleurBlanche = {255, 255, 255};
    int continuer = 1;
int i=0;
    int tempsActuel = 0, tempsPrecedent = 0;
float compteurs = 0.0;
float compteurm = 0.0;
char seconde[40] = "";
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    ecran = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Gestion du texte avec SDL_ttf", NULL);

    /* Chargement de la police */
    police = TTF_OpenFont("angelina.TTF", 30);

    /* Initialisation du temps et du texte */
   // tempsActuel = SDL_GetTicks();
    //sprintf(seconde, "Temps : %f : %f",compteurm,compteurs);
    //texte = TTF_RenderText_Shaded(police, seconde, couleurNoire, couleurBlanche);

    while (continuer)
    {
       
  
SDL_PollEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
        }

        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));

     tempsActuel = SDL_GetTicks();
        if (tempsActuel - tempsPrecedent >= 100)
        {
i++;
if (i%590==0)
{

compteurm+=1;
compteurs=0;
}
compteurs += 0.1;
sprintf(seconde, "Temps : %0.0f : %0.0f",compteurm, compteurs);

            SDL_FreeSurface(texte); 
            texte = TTF_RenderText_Shaded(police, seconde, couleurNoire, couleurBlanche);
            tempsPrecedent = tempsActuel; 
          
        }

        position.x = 20;
        position.y = 10;
        SDL_BlitSurface(texte, NULL, ecran, &position); 
        SDL_Flip(ecran);
    }

    TTF_CloseFont(police);
    TTF_Quit();

    SDL_FreeSurface(texte);
    SDL_Quit();

    return EXIT_SUCCESS;
}

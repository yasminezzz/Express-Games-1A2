#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdlib.h>
#include <stdio.h>
#include "Enemy1.h"
#include "Rand_Move.h"

void pause(Enemy1 *E1, SDL_Surface *Screen)
{
    int continuer = 1;
    SDL_Event event;

    while (continuer)
    {
        SDL_PollEvent(&event);
	SDL_FillRect(Screen, NULL, SDL_MapRGB(Screen->format, 255, 255, 255));
	Random_Movement(E1,Screen);
	SDL_Flip(Screen);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
        }
    }
}

 
int main(int argc, char *argv[])
{
    SDL_Surface *Screen=NULL;
    Enemy1 E1;

    

    SDL_Init(SDL_INIT_VIDEO);
    Screen = SDL_SetVideoMode(1200, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Ma super fenêtre SDL !", NULL);
    SDL_FillRect(Screen, NULL, SDL_MapRGB(Screen->format, 255, 255, 255));
    
    Initialize_Enemy1(&E1);
    Display_Enemy1_R(&E1,Screen);

    SDL_Flip(Screen);
    pause(&E1,Screen); //boucle pour fermer la fenetre
    free(E1.Enemy_Picture_R);
    free(E1.Enemy_Picture_L);
    SDL_Quit();
 
    return EXIT_SUCCESS;
}

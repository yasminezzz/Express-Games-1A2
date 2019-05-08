#include <SDL/SDL.h>
#include "life.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_image.h>
#include "text.h"
#include <SDL/SDL_ttf.h>
int main(int argc, char *argv[])
{
char path_font [500] ="Ubuntu-Title.ttf";
TTF_Font *police = NULL;
Text txt;
 SDL_Surface *lifebar=NULL;
    SDL_Surface *ecran = NULL, *imageDeFond = NULL, *sapin = NULL,*sapin2= NULL, *zozor = NULL;
    SDL_Rect positionZozor;
int continuer=1,score=0;
SDL_Event event;
SDL_Rect positionlifebar,positionFond, positionSapin,positionSapin2;
float life=10;
    positionlifebar.x = 10;
    positionlifebar.y = 20;
    positionFond.x = 0;
    positionFond.y = 0;
    positionSapin.x = 500;
    positionSapin.y = 300;
 positionSapin2.x =300;
    positionSapin2.y = 300;
 
    SDL_Init(SDL_INIT_VIDEO);
init_text(&txt,path_font);
 

    ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE);
    SDL_WM_SetCaption("Chargement d'images en SDL", NULL);
    imageDeFond = IMG_Load("lac_en_montagne.bmp");
    //SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
    sapin = IMG_Load("sapin.png");
sapin2 = IMG_Load("sapin.png");
  zozor = SDL_LoadBMP("zozor.bmp");
SDL_SetColorKey(zozor, SDL_SRCCOLORKEY, SDL_MapRGB(zozor->format, 0, 0, 255));
 positionZozor.x = ecran->w / 2 - zozor->w / 2;
    positionZozor.y = ecran->h / 2 - zozor->h / 2;

    //SDL_BlitSurface(sapin, NULL, ecran, &positionSapin);
    SDL_Flip(ecran);
  
  SDL_EnableKeyRepeat(10, 10); 
     while (continuer)
    {if(positionZozor.y>300)
life-=1;
if(positionZozor.x>500)
score+=10;
else if (positionZozor.x<300)
score-=10;
 update_txt(&txt,score);
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
 case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_UP: // Flèche haut
                        positionZozor.y--;
                        break;
                    case SDLK_DOWN: // Flèche bas
                        positionZozor.y++;
                        break;
                    case SDLK_RIGHT: // Flèche droite
                        positionZozor.x++;
                        break;
                    case SDLK_LEFT: // Flèche gauche
                        positionZozor.x--;
                        break;
                }
                break;       
         }

SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
SDL_BlitSurface(sapin, NULL, ecran, &positionSapin);
SDL_BlitSurface(sapin2, NULL, ecran, &positionSapin2);
 SDL_BlitSurface(zozor, NULL, ecran, &positionZozor);
display_life(life,ecran,lifebar,&positionlifebar); 
displayText(txt,ecran); 
      SDL_Flip(ecran);
    }
freeText(&txt);
    SDL_FreeSurface(zozor);
    SDL_FreeSurface(imageDeFond);
    SDL_FreeSurface(lifebar);
    SDL_Quit();

    return EXIT_SUCCESS;
}

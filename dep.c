#include "SDL/SDL_image.h"
#include "SDL/SDL.h"
#include <stdio.h>
#include <stdlib.h>
#include "dep.h"
#include "Perso.h"

void deplacer(Perso *p, SDL_Surface *ecran2)
{
Uint8 *keystates = SDL_GetKeyState(NULL );
SDL_FillRect(ecran2, NULL, SDL_MapRGB(ecran2->format, 255, 255, 255));
SDL_Event event;
SDL_PollEvent(&event);
if(keystates[SDLK_RIGHT] )
{
p->position.x=p->position.x+2;
afficher(p,ecran2);
}
if(keystates[SDLK_LEFT])
{
p->position.x=p->position.x-2;
afficher(p,ecran2);
}
if(keystates[SDLK_UP])
{
p->position.y=p->position.y-2;
afficher(p,ecran2);
}
if(keystates[SDLK_DOWN])
{
p->position.y=p->position.y+2;
afficher(p,ecran2);


}
}
void deplacer2(Perso *p, SDL_Surface *ecran2)
{
int x,y;
SDL_FillRect(ecran2, NULL, SDL_MapRGB(ecran2->format, 255, 255, 255));
SDL_Event event;
SDL_PollEvent(&event);
if(SDL_MOUSEBUTTONUP)
{
x = event.button.x;
y = event.button.y;
}

if(x>p->position.x)
{
p->position.x=p->position.x+1;

afficher(p,ecran2);
}
else if(x<p->position.x)
{
p->position.x=p->position.x-1;
afficher(p,ecran2);
}
else{
}
}


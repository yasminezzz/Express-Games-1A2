#include<stdlib.h>
#include<stdio.h>
#include<SDL/SDL.h>
#include"bounding.h"

void update_score(SDL_Rect *personnage, SDL_Rect *ennemi, int stage,int *score )
{
if (check_collision(*personnage, *ennemi)==1)
{
if (stage==1)
*score+=15;
if (stage==2)
*score+=30;
if (stage==3)
*score+=45;
}
} 
void update_vie(SDL_Rect *personnage,SDL_Rect *ennemi,SDL_Rect *obstacle,SDL_Rect *life_pickup,int stage,float *vie)
{
if (check_collision(*personnage, *ennemi)==1)
{
if (stage==1)
*vie-=0.5;
if (stage==2)
*vie-=1;
if (stage==3)
*vie-=2;
}
if (check_collision(*personnage, *obstacle)==1)
*vie-=2;
if (check_collision(*personnage, *life_pickup)==1)
*vie+=1;
}
//cette fonction doit etre procedee par SDL_PollEvent
void time()
{
int tempsPrecedent=0,tempsActuel=0;
tempsActuel = SDL_GetTicks();
if (tempsActuel - tempsPrecedent > 30) 
tempsPrecedent = tempsActuel;
}





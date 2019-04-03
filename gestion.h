#ifndef __include_gestion_h__
#define __include_gestion_h__
#include<SDL/SDL.h>


void update_score(SDL_Rect *personnage, SDL_Rect *ennemi, int stage,int *score );
void update_vie(SDL_Rect *personnage,SDL_Rect *ennemi,SDL_Rect *obstacle,SDL_Rect *life_pickup,int stage,float *vie)
void time();



#endif

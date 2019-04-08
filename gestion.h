#ifndef __include_gestion_h__
#define __include_gestion_h__
#include<SDL/SDL.h>

void update_score(perso* P,Enemy1 E, int stage);
void update_vie(perso* P,Enemy1 E,SDL_Rect *obstacle,SDL_Rect *life_pickup,int stage);
void time();



#endif

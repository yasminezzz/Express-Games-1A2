#ifndef OBSTACLE_H_INCLUDED
#define OBSTACLE_H_INCLUDED
#include <SDL/SDL.h>
typedef struct Cercle
{
   int x,y;
   int rayon;
}cercle;

void init ();
void affichage ();
int collision(SDL_Rect* rect1,SDL_Rect* rect2);
int Collision(int x,int y,cercle C);


#endif // OBSTACLE_H_INCLUDED

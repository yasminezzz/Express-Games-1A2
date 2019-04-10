int collision(SDL_Rect* rect1,SDL_Rect* rect2)
{
	if(rect1->y >= rect2->y + rect2->h)
		return 0;
	if(rect1->x >= rect2->x + rect2->w)
		return 0;
	if(rect1->y + rect1->h <= rect2->y)
		return 0;
	if(rect1->x + rect1->w <= rect2->x)
		return 0;
	return 1;
}
int Collision(int x,int y,cercle C)
{
   int d2 = (x-C.x)*(x-C.x) + (y-C.y)*(y-C.y);
   if (d2>C.rayon*C.rayon)
      return 0;
   else
      return 1;
}

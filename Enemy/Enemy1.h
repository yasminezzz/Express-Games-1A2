#ifndef ENEMY1_H_
#define ENEMY1_H_

typedef struct Enemy1 {
	SDL_Surface *Enemy_Picture_R;
	SDL_Surface *Enemy_Picture_L;
	SDL_Rect Enemy_Position;
	int Life;
	int Damage;
	int State;
	int R;
	int L;
} Enemy1;

void Initialize_Enemy1(Enemy1 *E1);
void Display_Enemy1_R(Enemy1 *E1, SDL_Surface *Destination);
void Display_Enemy1_L(Enemy1 *E1, SDL_Surface *Destination);


#endif /* ENEMY1_H_ */

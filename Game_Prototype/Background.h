#ifndef BACKGROUND_H_
#define BACKGROUND_H_

typedef struct Background {
	SDL_Surface* Background;
	SDL_Rect BGP;
}BGS;

typedef struct world_objects {
	SDL_Surface *GR1;
	SDL_Rect GR1P;
}WO;

void Init_All_Objs(WO *WOS);
void Init_BG(BGS *BG);
void Display_All_World_Objects(WO *WOS, SDL_Surface *Screen);
void Display_BG(BGS *BG,SDL_Surface *Screen);
SDL_Surface* Anim_Background0(SDL_Surface *Image, SDL_Surface *Screen, SDL_Rect BGP, int *NB);
void Anim_PlayB(SDL_Surface *Button, SDL_Surface *Screen, SDL_Rect Pos, int *NP);
void Anim_SetsB(SDL_Surface *Button, SDL_Surface *Screen, SDL_Rect Pos, int *NS);
void Anim_QuitB(SDL_Surface *Button, SDL_Surface *Screen, SDL_Rect Pos, int *NQ);

#endif /* BACKGROUND_H_ */

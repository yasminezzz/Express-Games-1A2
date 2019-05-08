#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "text.h"



int main()
{

char path_font [500] ="Ubuntu-Title.ttf";	

	int continuer = 1;
	SDL_Event event;
	Text txt;
	SDL_Surface *screen=NULL;
	TTF_Font *police = NULL;
	

	int it = 0;
 screen = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	it = init_text(&txt, path_font);

	if(it == -1)
	{
		continuer = 0;	
	}

	//Appui continu sur les touches
	SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY,SDL_DEFAULT_REPEAT_INTERVAL);

	// GAME LOOP
	while(continuer) 
	{
		/*********************** INPUT ************************/
		if (SDL_PollEvent(&event)) 
		{				
		switch (event.type) 
	{
		case SDL_QUIT:
			continuer=0;
			break;	
	}
SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
		
}

		update_txt(&txt,3000);
	
		displayText(txt,screen);
		
		SDL_Flip(screen);
		
	}
        freeText(&txt);
  SDL_Quit();
	
	return(0);
}


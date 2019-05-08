#include <SDL/SDL.h>
#include "life.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_image.h>
void display_life(float life,SDL_Surface *screen,SDL_Surface *lifebar,SDL_Rect *positionlifebar)
{

if (life==10)
{lifebar=IMG_Load("life bars.png");
SDL_BlitSurface(lifebar,NULL,screen,positionlifebar);
}
if (life==9)
{lifebar=IMG_Load("11.png");

SDL_BlitSurface(lifebar,NULL,screen,positionlifebar);

}
if (life==8)
{lifebar=IMG_Load("10.png");
SDL_BlitSurface(lifebar,NULL,screen,positionlifebar);
}
if (life==7)
{lifebar=IMG_Load("9.png");
SDL_BlitSurface(lifebar,NULL,screen,positionlifebar);
}
if (life==6)
{lifebar=IMG_Load("8.png");
SDL_BlitSurface(lifebar,NULL,screen,positionlifebar);
}
if (life==5)
{lifebar=IMG_Load("7.png");
SDL_BlitSurface(lifebar,NULL,screen,positionlifebar);
}
if (life==4)
{lifebar=IMG_Load("6.png");
SDL_BlitSurface(lifebar,NULL,screen,positionlifebar);
}
if (life==3)
{lifebar=IMG_Load("5.png");
SDL_BlitSurface(lifebar,NULL,screen,positionlifebar);
}
if (life==2)
{lifebar=IMG_Load("4.png");
SDL_BlitSurface(lifebar,NULL,screen,positionlifebar);
}
if (life==1)
{lifebar=IMG_Load("3.png");
SDL_BlitSurface(lifebar,NULL,screen,positionlifebar);
}
/*if (life==0)
{lifebar=IMG_Load("0life.png");
SDL_BlitSurface(lifebar,NULL,screen,positionlifebar);
}*/

SDL_Flip(screen);

}



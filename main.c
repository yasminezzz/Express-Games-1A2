//Express-Games-1A2 Guys this is the menu ive had problems updoaling the main.c



//The headers
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_mixer.h>
#include <assert.h>
int main(int argc, char *argv[])
{
    SDL_Surface *ecran = NULL, *imageDeFond = NULL, *title = NULL,*Credits = NULL , *Credits2 = NULL , *Settings3 = NULL, *Credits3 = NULL , *Play = NULL , *Settings = NULL , *Quit = NULL , *Set = NULL , *Play2 = NULL , *Settings2 = NULL , *Quit2 = NULL ;

    SDL_Rect positionFond,positionPlay,positionSettings,positionQuit,positiontitle,positionCredits;
int mouse;

//Title
positiontitle.x = 0;
positiontitle.y = 0;
//Fond
positionFond.x = 0;
positionFond.y = 0;
//PLAY
positionPlay.x = 330;
positionPlay.y = 200;
positionPlay.w = 140;  
positionPlay.h = 100;
//SETTINGS
positionSettings.x = 330;
positionSettings.y = 300;
positionSettings.w = 140;
positionSettings.h = 100; 
//QUIT
positionQuit.x = 330;
    positionQuit.y = 390;
positionQuit.w = 140;
positionQuit.h = 100;
 //Credits 
positionCredits.x = 330;
positionCredits.y = 500;
positionCredits.w = 140;
positionCredits.h = 100;
    SDL_Init(SDL_INIT_VIDEO);
//music
Mix_Chunk *click = NULL;
Mix_OpenAudio(44100,AUDIO_S16SYS,1,4096);
Mix_Music *music;
music = Mix_LoadMUS("music2.ogg");
click = Mix_LoadWAV("click.wav");
Mix_PlayMusic(music,-1);

 
    ecran = SDL_SetVideoMode(800,600, 32, SDL_HWSURFACE);
    SDL_WM_SetCaption("Seeking treasures", NULL);
Set = IMG_Load("fond.jpg");
Credits = IMG_Load("Credits.png");
Credits2 = IMG_Load("Credits2.png");
 Credits3 = IMG_Load("Credits_page.png");
Settings3 = IMG_Load("Settings_page.png");
    imageDeFond = IMG_Load("fond.jpg");
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
 title = IMG_Load("title.png");
SDL_BlitSurface(title, NULL, ecran, &positiontitle);
Play = IMG_Load("Play.png");

    SDL_BlitSurface(Play, NULL, ecran, &positionPlay);
 
    
Settings = IMG_Load("Settings.png");

    SDL_BlitSurface(Settings, NULL, ecran, &positionSettings);
    SDL_Flip(ecran);
Quit = IMG_Load("Quit.png");

    SDL_BlitSurface(Quit, NULL, ecran, &positionQuit);
 SDL_BlitSurface(Credits, NULL , ecran, &positionCredits);
    SDL_Flip(ecran);
    

Play2 = IMG_Load("Play2.png");
Settings2 = IMG_Load("Settings2.png");
Quit2 = IMG_Load("Quit2.png");
																																																																																								
    int continuer = 1;
    SDL_Event event;
 
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
        break ;
case SDL_KEYUP:
if(event.key.keysym.sym ==SDLK_ESCAPE)
{
continuer = 0;
}
if(event.key.keysym.sym ==SDLK_F1)
{
SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format,255 ,255,255));
SDL_BlitSurface(imageDeFond,NULL,ecran,&positionFond);
SDL_Flip(ecran);
}
if(event.key.keysym.sym ==SDLK_F2)
{
SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format,255 ,255,255));
SDL_BlitSurface(imageDeFond,NULL,ecran,&positionFond);
SDL_Flip(ecran);
}
break;
case SDL_MOUSEMOTION:
if((event.motion.x>positionPlay.x)&&(event.motion.x<positionPlay.x + positionPlay.w)&&(event.motion.y>positionPlay.y)&&(event.motion.y<positionPlay.y + positionPlay.h))
{
mouse=1;
}
if((event.motion.x>positionSettings.x)&&(event.motion.x<positionSettings.x + positionSettings.w)&&(event.motion.y>positionSettings.y)&&(event.motion.y<positionSettings.y + positionSettings.h))
{
mouse=2;
}
if((event.motion.x>positionQuit.x)&&(event.motion.x<positionQuit.x + positionQuit.w)&&(event.motion.y>positionQuit.y)&&(event.motion.y<positionQuit.y + positionQuit.h))
{
mouse=3;
}
if((event.motion.x>positionCredits.x)&&(event.motion.x<positionCredits.x + positionCredits.w)&&(event.motion.y>positionCredits.y)&&(event.motion.y<positionCredits.y + positionCredits.h))
{
mouse=4;
}
break;
case SDL_MOUSEBUTTONUP:
if((event.button.button == SDL_BUTTON_LEFT)&&(mouse == 1))
{

SDL_BlitSurface(Play2, NULL, ecran, &positionPlay);
SDL_Flip(ecran);
Mix_PlayChannel(-1, click, 0);
SDL_Delay(500);
SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format,255 ,255,255));
SDL_BlitSurface(imageDeFond,NULL,ecran,&positionFond);
SDL_Flip(ecran);
} 
if((event.button.button == SDL_BUTTON_LEFT)&&(mouse == 2))
{
SDL_BlitSurface(Settings2, NULL, ecran, &positionSettings);
SDL_Flip(ecran);
Mix_PlayChannel(-1, click, 0);
SDL_Delay(500);
SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format,255 ,255,255));
SDL_BlitSurface(Settings3,NULL,ecran,&positionFond);
SDL_Flip(ecran);
} 
if((event.button.button == SDL_BUTTON_LEFT) && (mouse == 3))
{
SDL_BlitSurface(Quit2, NULL, ecran, &positionQuit);
SDL_Flip(ecran);
Mix_PlayChannel(-1, click, 0);
SDL_Delay(500);
continuer = 0;
}
if((event.button.button == SDL_BUTTON_LEFT) && (mouse == 4))
{
SDL_BlitSurface(Credits2, NULL, ecran, &positionCredits);
SDL_Flip(ecran);
Mix_PlayChannel(-1, click, 0);
SDL_Delay(500);
SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format,255 ,255,255));
SDL_BlitSurface(Credits3,NULL,ecran,&positionFond);
SDL_Flip(ecran);
}
break ;
}
}
Mix_FreeMusic(music);
Mix_FreeChunk (click);
Mix_CloseAudio();
SDL_FreeSurface(imageDeFond);
SDL_FreeSurface(Play);
SDL_FreeSurface(Settings);
SDL_FreeSurface(Quit);
SDL_FreeSurface(Play2);
SDL_FreeSurface(Settings2);
SDL_FreeSurface(Settings3);
SDL_FreeSurface(Quit2);
SDL_FreeSurface(title);
SDL_FreeSurface(Credits);
SDL_FreeSurface(Credits2);
SDL_FreeSurface(Credits3);
SDL_Quit();
 
    return EXIT_SUCCESS;
}

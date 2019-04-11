

    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>
    #include "SDL/SDL.h"
    #include "Constants.h"
    #include "Perso.h"
    #include "Dep.h"


    void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip)
{
    SDL_Rect offset;

    //Recuperation des coordonnées
    offset.x = x;
    offset.y = y;

    //On blitte la surface
    SDL_BlitSurface( source, clip, destination, &offset );
}

    int main()
    {

        SDL_Surface *ecran;
        SDL_Event event;
        int continuer = 0;
        Uint32 temps_courant, prochain_rendu = 0;

        int bgX = 0, bgY = 0;
        SDL_Surface *background = NULL;
        
        /* déclaration personnage principal et aide */
        Perso personnage, aide;
        
    
        if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0)
        {
            fprintf(stderr, "Echec d'initialisation de SDL.\n");
            return 1;
        }
        
        
        /* On fixe le mode d'affichage à 640*480*16 plein ecran.*/
        ecran = SDL_SetVideoMode(640, 480, 16, SDL_HWSURFACE | SDL_DOUBLEBUF);
        if ( ecran == NULL )
        {
            fprintf(stderr, "Echec de changement du mode video : %s.\n", SDL_GetError());
            return 1;
        }
        


        /* On charge le personnage avec l'image p2.png*/
        if ( !chargerSprite( &personnage, "p2.png" ) )
        {
            SDL_Quit();
            return 1;
        }

     /* On charge le sprite controlable avec l'image pecheur.bmp */
        if ( !chargerSprite( &aide, "pokemon.png" ) )
        {
            SDL_Quit();
            return 1;
        }
       


        bgX -= 2;
        //
        background  = loadBmp( "background.png" );
    if ( !background )
        return 0;




        //LoadImage("background.png");
 
        //Si le fond est allé trop loin
        if( bgX <= -background->w )
        {
            //On le remet à zero
            bgX = 0;
        }
        apply_surface( bgX, bgY, background, ecran , NULL);
        apply_surface( bgX + background->w, bgY, background, ecran , NULL);
        
        // on place le sprite que l'on controle au milieu
        personnage.position.x = 60;
        personnage.position.y = 360;
        fixerDirectionSprite( &personnage, DIRECTION_BAS );
        fixerDirectionSprite( &personnage, AUCUNE_DIRECTION );

        // on place le sprite que l'on controle au milieu
        aide.position.x = 0;
        aide.position.y = 360;
        fixerDirectionSprite( &aide, DIRECTION_BAS );
        fixerDirectionSprite( &aide, AUCUNE_DIRECTION );

        while (!continuer)
        {
            while (SDL_PollEvent(&event))
            {
                switch (event.type)
                {
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym)
                    {
                    case SDLK_ESCAPE:
                        continuer = 1;
                        break;
                        
                    // on deplace le sprite au clavier
                    case SDLK_UP:
                        fixerDirectionSprite( &personnage, DIRECTION_HAUT );
                        fixerDirectionSprite( &aide, DIRECTION_HAUT );
                        break;
                    
                    case SDLK_RIGHT:
                        fixerDirectionSprite( &personnage, DIRECTION_DROITE );
                        fixerDirectionSprite( &aide, DIRECTION_DROITE );
                        break;
                    
                    case SDLK_DOWN:
                        fixerDirectionSprite( &personnage, DIRECTION_BAS );
                        fixerDirectionSprite( &aide, DIRECTION_BAS );
                        break;
                    
                    case SDLK_LEFT:
                        fixerDirectionSprite( &personnage, DIRECTION_GAUCHE );
                        fixerDirectionSprite( &aide, DIRECTION_GAUCHE );
                        break;
                    
                    default:
                        printf("Une touche à été pressée.\n");
                    }
                    break;
                
                case SDL_KEYUP:
                    switch (event.key.keysym.sym)
                    {
                    // on deplace le sprite au clavier
                    case SDLK_UP:
                        if (personnage.direction == DIRECTION_HAUT)
                            fixerDirectionSprite( &personnage, AUCUNE_DIRECTION );
                            fixerDirectionSprite( &aide, AUCUNE_DIRECTION );
                        break;
                    
                    case SDLK_RIGHT:
                        if (personnage.direction == DIRECTION_DROITE)
                            fixerDirectionSprite( &personnage, AUCUNE_DIRECTION );
                            fixerDirectionSprite( &aide, AUCUNE_DIRECTION );
                        break;
                    
                    case SDLK_DOWN:
                        if (personnage.direction == DIRECTION_BAS)
                            fixerDirectionSprite( &personnage, AUCUNE_DIRECTION );
                            fixerDirectionSprite( &aide, AUCUNE_DIRECTION );
                        break;
                    
                    case SDLK_LEFT:
                        if (personnage.direction == DIRECTION_GAUCHE)
                            fixerDirectionSprite( &personnage, AUCUNE_DIRECTION );
                            fixerDirectionSprite( &aide, AUCUNE_DIRECTION );
                        break;
                        
                    default:
                        ;
                    }
                    break;

                case SDL_QUIT:
                    continuer = 1;
                    break;
                
                default:
                    ;
                }
            }
            
            /* On recupère le temps écoulé en mili-secondes */
            temps_courant = SDL_GetTicks();
            
            /* On regarde s'il est temps d'effectuer le prochain rendu */
            if (temps_courant > prochain_rendu)
            {
                /* un rendu toutes les 20 milli-secondes = 50 images par secondes */
                prochain_rendu = temps_courant + 20;
                
                /* on met à jour le "jeu" */

                
                // puis les positions des sprites
                miseAJourSprite( &personnage );
                miseAJourSprite( &aide );
            
                /* On dessine la scene */
                
                /* On efface l'écran */
                SDL_FillRect(ecran, NULL, 0);

                /* On dessine les sprites à l'écran */
                dessinerSprite( &personnage, ecran );
                dessinerSprite( &aide, ecran );
                            
                /* On met à jour de la zone d'affichage de la fenetre */
                SDL_UpdateRect(ecran, 0, 0, 0, 0);
            }

                       SDL_Flip(ecran);
            
        }


        supprimerSprite( &personnage );
        supprimerSprite( &aide );
        SDL_Quit();
        return 0;
    }




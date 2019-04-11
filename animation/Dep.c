		#include <stdio.h>
		#include <stdlib.h>
		#include <string.h>
		#include "Perso.h"
		#include "SDL/SDL_image.h"
		#include "SDL/SDL.h"
		#include "Perso.h"
		#include "Constants.h"

	void fixerDirectionSprite( Perso *sprite, int direction )
					{
					    // On affecte la direction au sprite
					    sprite->direction = direction;
					    
					    // on affecte l'animation correcpondant à la direction au sprite
					    if (direction != AUCUNE_DIRECTION)
					    {
					        sprite->anim = 1;
					        switch (direction)
					        {
					        case DIRECTION_HAUT:
					            sprite->orientation = HAUT;
					            break;
					            
					        case DIRECTION_DROITE:
					            sprite->orientation = DROITE;
					            break;

					        case DIRECTION_BAS:
					            sprite->orientation = BAS;
					            break;

					        case DIRECTION_GAUCHE:
					            sprite->orientation = GAUCHE;
					            break;

					        default:
					            ;
					        }
					    }
					    else
					        // si le sprite est areté, on ne l'anime pas
					        sprite->anim = 0;

					    // on met la première animation
					    sprite->anim_courante = 0;
					    sprite->temps_anim_courante = 0;

					    // on regle la source de l'image à copier
					    sprite->source.y = sprite->orientation * sprite->hauteur;
					    sprite->source.x = sprite->anim_courante * sprite->largeur;
					}



				void miseAJourSprite( Perso *sprite )
				{
				    // le sprite vas vers le haut
				    if (sprite->direction & DIRECTION_HAUT)
				    {
				        // on monte et on faut attention a ne pas sortie de l'ecran
				        sprite->position.y -= sprite->vitesse;
				        if (sprite->position.y < 0)
				            sprite->position.y = 0;
				    }
				    else if (sprite->direction & DIRECTION_DROITE)
				    {
				        // on va à droite et on fait attention a ne pas sortie de l'ecran
				        sprite->position.x += sprite->vitesse;  
				        if (sprite->position.x + sprite->largeur > LARGEUR_ECRAN)   
				            sprite->position.x = LARGEUR_ECRAN - sprite->largeur;
				    }
				    else if (sprite->direction & DIRECTION_BAS)
				    {
				        // on descend et on faut attention a ne pas sortie de l'ecran
				        sprite->position.y += sprite->vitesse;  
				        if (sprite->position.y + sprite->hauteur > HAUTEUR_ECRAN)
				            sprite->position.y = HAUTEUR_ECRAN - sprite->hauteur;
				    }
				    else if (sprite->direction & DIRECTION_GAUCHE)
				    {
				        // on va à gauche et on fait attention a ne pas sortie de l'ecran
				        sprite->position.x -= sprite->vitesse;  
				        if (sprite->position.x < 0)
				            sprite->position.x = 0;
				    }
				}

				void deplacer(Perso *p, SDL_Surface *ecran2)
				    {
				    	 Uint32 temps_courant, prochain_rendu = 0;
			    Uint8 *keystates = SDL_GetKeyState(NULL );
			  
			    SDL_FillRect(ecran2, NULL, SDL_MapRGB(ecran2->format, 180, 255, 255));
			  
			    if(keystates[SDLK_RIGHT] )
			    {
			        fixerDirectionSprite( p, DIRECTION_DROITE );
			    }
			    if(keystates[SDLK_LEFT])
			    {
			        fixerDirectionSprite( p, DIRECTION_GAUCHE );
			    }
			    if(keystates[SDLK_UP])
			    {
			        fixerDirectionSprite( p, DIRECTION_HAUT );
			    }
			    if(keystates[SDLK_DOWN])
			    {
			        fixerDirectionSprite( p, DIRECTION_BAS );
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
			            miseAJourSprite( p );
			        
			            /* On dessine la scene */
			            
			            /* On efface l'écran */
			            SDL_FillRect(ecran2, NULL, 0);

			            /* On dessine les sprites à l'écran */
			            dessinerSprite( p, ecran2 );
			                        
			            /* On met à jour de la zone d'affichage de la fenetre */
			            SDL_UpdateRect(ecran2, 0, 0, 0, 0);
			        }
				    }
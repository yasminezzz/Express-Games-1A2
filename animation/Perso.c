		#include <stdio.h>
		#include <stdlib.h>
		#include <string.h>
		#include "Perso.h"
		#include "SDL/SDL_image.h"
		#include "SDL/SDL.h"
		#include "Perso.h"
		#include "Constants.h"

SDL_Surface *loadBmp(const char *fichier)
{
    SDL_Surface *image;

    /* Chargement du bitmap "fichier" en memoire dans la surface image */
    image = IMG_Load(fichier);
//SDL_LoadImage(fichier);
    if ( image == NULL )
    {
        fprintf(stderr, "Echec de chargement du fichier %s : %s.\n", fichier, SDL_GetError());
        return NULL;
    }
    
    /* Verification du format de l'image */
    if ( (image->w != 128) || (image->h != 128) )
    if ( image == NULL )
    {
        fprintf(stderr, "L'image du fichier %s doit être de taille 96*128 pixels.\n", fichier);
        SDL_FreeSurface(image);
        return NULL;
    }
    
    return image;
}



int chargerSprite( Perso *sprite, const char *image )
{
    sprite->image = loadBmp( image );
    if ( !sprite->image )
        return 0;
        


    // On definit d'abord les propriétés du sprite :
    
    // le sprite n'est pas animé par defaut
    sprite->anim = 0;

    // on commence par la première animation
    sprite->anim_courante = 0;

    // le sprite dispose de trois animations
    sprite->total_anims = 4;

    // par défaut, le sprite est tourné vers le bas
    sprite->orientation = BAS;

    // chaque animation dure 5 affichages
    sprite->temps_anim = 85;

    // Le temps qu'il reste à afficher l'animation courante
    sprite->temps_anim_courante = 0;

    // On definit ensuite les dimentions du sprite.
    sprite->largeur = 64;
    sprite->hauteur = 64;
    
    sprite->source.x = sprite->anim_courante * sprite->largeur;
    sprite->source.y = sprite->orientation * sprite->hauteur;
    sprite->source.w = sprite->largeur;
    sprite->source.h = sprite->hauteur;

    sprite->position.x = 0;
    sprite->position.y = 0;
    sprite->position.w = sprite->largeur;
    sprite->position.h = sprite->hauteur;
    
    // on definit enfin la vitesse et la direction du sprite
    sprite->vitesse = 2;
    sprite->direction = AUCUNE_DIRECTION;
    
    return 1;
}

void supprimerSprite( Perso *sprite )
{
    SDL_FreeSurface( sprite->image );
}

void dessinerSprite( Perso *sprite, SDL_Surface *destination )
{
    /* si le sprite est animé, on gere l'animation */
    if (sprite->anim)
    {
        // on decremente le temps restant à l'animation courante
        sprite->temps_anim_courante--;
        // et on regarde s'il est temps de changer d'animation
        if ( sprite->temps_anim_courante <= 0 )
        {
            // s'il faut changer, on passe à l'animation suivante
            sprite->anim_courante++;
            // si on était à la dernière animation, on repasse à la première
            if (sprite->anim_courante >= sprite->total_anims)
                sprite->anim_courante = 0;
            
            // on regle la source à copier
            sprite->source.x = sprite->largeur * sprite->anim_courante;
            sprite->temps_anim_courante = sprite->temps_anim;
        }
    }
    
    // enfin, on dessine le sprite à l'ecran
    SDL_BlitSurface( sprite->image, &sprite->source, destination, &sprite->position );
}

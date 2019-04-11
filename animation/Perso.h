	#ifndef PERSO_H_
	#define PERSO_H_
	#include "SDL/SDL_image.h"
	#include "SDL/SDL.h"
	#include <stdio.h>
	#include <stdlib.h>
		#include "Constants.h"


	typedef struct Perso
	{

		SDL_Rect position;
		
		SDL_Surface *image;
		
		SDL_Rect source;
		
		// taille du sprite

	    int largeur;
	    int hauteur;
	    
	    // pour le déplacement
	    
	    // direction dans laquelle se deplace le sprite
	    int direction;
	    
	    // vitesse du sprite
	    int vitesse;
	    
	    // pour la gestion des animations
	    
	    // si le sprite est anime
	    int anim;
	    
	    // direction dans laquelle est orienté le sprite
	    int orientation;

	    // animation courante du sprite
	    int anim_courante;

	    // le temps que dure une animation
	    int temps_anim;

	    // le temps de l'animation courante
	    int temps_anim_courante;

	    // nombre d'animations du sprite
	    int total_anims;


		int score;

		int damage;

		int life;

		int state;

	}Perso;


	SDL_Surface *loadBmp(const char *fichier);
	int chargerSprite( Perso *sprite, const char *image );
	void supprimerSprite( Perso *sprite );
	void dessinerSprite( Perso *sprite, SDL_Surface *destination );
	void initialiser(Perso *p);
	void afficher(Perso *p, SDL_Surface *ecran2 );

	#endif /* PERSO_H_ */
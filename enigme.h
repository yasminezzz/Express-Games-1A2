#ifndef ENIGME_H
#define ENIGME_H

typedef struct enigme {
	SDL_Rect pos;
	SDL_Surface image;
	char question[200];
	int reponse; 
	int resultat;
	}
void initialiser (enigme *e);
void afficher(enigme *e);
int resolution(enigme *e, int reponse);
void aleatoire(enigme *e);
int reponse_verif(int score, int reponse);
#endif

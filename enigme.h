#ifndef ENIGME_H
#define ENIGME_H

typedef struct enigme {
	SDL_Rect pos;
	SDL_Surface image;
	char question;
	char reponse;
	int resultat;
	}
void initialiser (enigme *e);
void afficher(enigme *e);
int resolution(enigme *e, int score);
enigme aleatoire(enigme *e);

#endif

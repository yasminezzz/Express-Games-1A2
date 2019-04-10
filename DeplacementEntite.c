void deplacer_monstre(int carte[][NB_BLOCS_HAUTEUR]  , SDL_Rect *posM , SDL_Rect pos  ){// posM désigne la position  du monstre
 
SDL_Rect  diff  ;// diff c'est la différence entre la monstre et le singe "joueur"
int nbr =0 ,a=0 ;
srand(time(NULL)); // initialisation du générateur aléatoir
nbr=(rand() % 4) ;
 
diff.x= posM->x - pos.x  ;
diff.y=  posM->y - pos.y  ;
a=abs(diff.x)+abs(diff.y) ;
 
if(a > 10){
switch (nbr){
case HAUT :
      if(posM->y+1!=NB_BLOCS_HAUTEUR)
      if(carte [posM->x][posM->y+1]!=MUR && carte [posM->x][posM->y+1]!=CAISSE && carte [posM->x][posM->y+1]!=BANANE ) posM->y++ ;
       break ;
case BAS :
      if(posM->y-1)
      if(carte [posM->x][posM->y-1]!=MUR && carte [posM->x][posM->y-1]!=CAISSE  && carte [posM->x][posM->y-1]!=CAISSE) posM->y-- ;
      break ;
case DROITE  :
      if(posM->x +1!=NB_BLOCS_LARGEUR)
      if(carte [posM->x +1][posM->y]!=MUR && carte [posM->x +1][posM->y]!=CAISSE && carte [posM->x +1][posM->y]!=BANANE ) posM->x++ ;
      break ;
case GAUCHE :
      if(posM->x-1)
      if(carte [posM->x-1][posM->y]!=MUR && carte [posM->x-1][posM->y]!=CAISSE && carte [posM->x -1][posM->y]!=CAISSE  ) posM->x-- ;
      break ;
}
}
else {
if(diff.x )
{
if(diff.x < 0){
      if(posM->x +1!=NB_BLOCS_LARGEUR)
      if(carte [posM->x +1][posM->y]!=MUR && carte [posM->x +1][posM->y]!=CAISSE  ) posM->x++ ;
    }
if(diff.x > 0){
      if(posM->x-1)
      if(carte [posM->x-1][posM->y]!=MUR && carte [posM->x-1][posM->y]!=CAISSE  ) posM->x-- ;
}
}
else if(diff.y){
if(diff.y < 0){
if(posM->x+1!=NB_BLOCS_HAUTEUR)
      if(carte [posM->x][posM->y+1]!=MUR && carte [posM->x][posM->y+1]!=CAISSE  ) posM->y++ ;
}
if(diff.y > 0){
if(posM->y-1)
      if(carte [posM->x][posM->y-1]!=MUR && carte [posM->x][posM->y-1]!=CAISSE  ) posM->y-- ;
}
 
}
 
}
}

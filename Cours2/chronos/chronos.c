/*=========================================================*/
/*=========================================================*/
/*	par Hugues Saulnier  */
/*=========================================================*/
#include "chronos.h"
/*=========================================================*/

#include<stdlib.h>
#include<time.h>

/*=========================================================*/
/*		DEFINITION DE LA STRUCTURE PRIV�E			*/
/*      REPR�SENTANT L'�TAT D'UN CHRONOM�TRE         */

struct chrono{

    /* GARDERA LE  TEMPS CUMUL� JUSQU'� DATE EN TICK */
	double tick_cumul;

	/* GARDERA LA MARQUE TEMPORELLE DE LA DERNI�RE */
	/* ACTION init,start,stop, reset , get  EN TICK */
	double tick_initial; 

	/* LE CHRONO FONCTIONNE OU NON */
	int on_off_ ;
};

/*---------------------------------------------------*/
/* STRAT�GIE
	on assure un suivi au malloc : 
	champs  cumul et marche � 0, temps initial � clock; 
*/
struct chrono* init_chrono(void){
	
	struct chrono* lui = malloc( sizeof(struct chrono));
	/* si on a obtenu de la m�moire */
	if (lui != NULL){
	
		lui-> tick_cumul = 0;
	
		lui-> tick_initial = clock();		
	
		lui-> on_off_ = 0;
	}
	return lui ;	
}
/*-----------------------------------------------------*/
/* STRAT�GIE
	  on lib�re le struc obtenu en  allocation programm�e 
*/
void free_chrono (struct chrono* lui){ 
	free(lui); 
}
/*-----------------------------------------------------*/
/* STRAT�GIE  le champs on_off_ vaudra  1
	s il marche, on ajoute le temps, on garde ce temps d'action  
*/
void start_chrono (struct chrono* lui){ 
	/*s'il marche d�j�, on cumule le temps */
	if (lui->on_off_ ){
		lui->tick_cumul += (clock() - lui->tick_initial);
	}
	/* lors de cette action, on r�serve son temps d'arriv�e */
	lui->tick_initial = clock();
	/* il est en marche */
	lui->on_off_ =  1;
}
/*---------------------------------------------------*/
/* STRAT�GIE  le champs on_off_ vaudra  0
	s il marche, on ajoute le temps, on garde ce temps d'action  
*/

/*on l'arr�te, les commentaires sont identiques � la pr�c�dente  */
void stop_chrono (struct chrono* lui){ 
	if (lui->on_off_ ){
		lui->tick_cumul += (clock() - lui->tick_initial);
	}
	lui->tick_initial = clock();
	lui->on_off_ = 0;
}
/*---------------------------------------------------*/
/* STRAT�GIE le temps cumul� est mis � 0
	   on garde le temps d'action  
*/
void reset_chrono(struct chrono* lui){
	lui->tick_cumul = 0;
	lui->tick_initial = clock();
}
/*---------------------------------------------------*/
/* STRAT�GIE  	
	s il marche, on ajoute le temps, on garde ce temps d'action  
	on retourne le temps cumul� en secondes 
*/
double get_chrono(struct chrono* lui){ 
	if (lui->on_off_ ){
		lui->tick_cumul += (clock() - lui->tick_initial);
	}
	lui->tick_initial = clock();

	/* on retourne le temps cumul� en tocs   */
	return (lui->tick_cumul /CLOCKS_PER_SEC);
}
/*---------------------------------------------------*/
/* STRAT�GIE
	retourne la diff�rence entre le temps actuel et
	le temps inscrit dans le chronom�tre lors de la 
	derni�re m�thode prise en compte.
	Ce temps est en clocs on le divise pour obtenir des secondes.
*/
double toc_chrono( struct chrono* lui){ 
	return ((clock() - lui->tick_initial) /CLOCKS_PER_SEC) ;
}
/*---------------------------------------------------*/
/* STRAT�GIE
	retourne directement le champ on_off_
*/
int get_etat( struct chrono* lui){ 
	return lui->on_off_  ;
}
/*---------------------------------------------------*/

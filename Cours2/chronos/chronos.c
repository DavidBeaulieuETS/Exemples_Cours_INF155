/*=========================================================*/
/*=========================================================*/
/*	par Hugues Saulnier  */
/*=========================================================*/
#include "chronos.h"
/*=========================================================*/

#include<stdlib.h>
#include<time.h>

/*=========================================================*/
/*		DEFINITION DE LA STRUCTURE PRIVÉE			*/
/*      REPRÉSENTANT L'ÉTAT D'UN CHRONOMÈTRE         */

struct chrono{

    /* GARDERA LE  TEMPS CUMULÉ JUSQU'À DATE EN TICK */
	double tick_cumul;

	/* GARDERA LA MARQUE TEMPORELLE DE LA DERNIÈRE */
	/* ACTION init,start,stop, reset , get  EN TICK */
	double tick_initial; 

	/* LE CHRONO FONCTIONNE OU NON */
	int on_off_ ;
};

/*---------------------------------------------------*/
/* STRATÉGIE
	on assure un suivi au malloc : 
	champs  cumul et marche à 0, temps initial à clock; 
*/
struct chrono* init_chrono(void){
	
	struct chrono* lui = malloc( sizeof(struct chrono));
	/* si on a obtenu de la mémoire */
	if (lui != NULL){
	
		lui-> tick_cumul = 0;
	
		lui-> tick_initial = clock();		
	
		lui-> on_off_ = 0;
	}
	return lui ;	
}
/*-----------------------------------------------------*/
/* STRATÉGIE
	  on libère le struc obtenu en  allocation programmée 
*/
void free_chrono (struct chrono* lui){ 
	free(lui); 
}
/*-----------------------------------------------------*/
/* STRATÉGIE  le champs on_off_ vaudra  1
	s il marche, on ajoute le temps, on garde ce temps d'action  
*/
void start_chrono (struct chrono* lui){ 
	/*s'il marche déjà, on cumule le temps */
	if (lui->on_off_ ){
		lui->tick_cumul += (clock() - lui->tick_initial);
	}
	/* lors de cette action, on réserve son temps d'arrivée */
	lui->tick_initial = clock();
	/* il est en marche */
	lui->on_off_ =  1;
}
/*---------------------------------------------------*/
/* STRATÉGIE  le champs on_off_ vaudra  0
	s il marche, on ajoute le temps, on garde ce temps d'action  
*/

/*on l'arrête, les commentaires sont identiques à la précédente  */
void stop_chrono (struct chrono* lui){ 
	if (lui->on_off_ ){
		lui->tick_cumul += (clock() - lui->tick_initial);
	}
	lui->tick_initial = clock();
	lui->on_off_ = 0;
}
/*---------------------------------------------------*/
/* STRATÉGIE le temps cumulé est mis à 0
	   on garde le temps d'action  
*/
void reset_chrono(struct chrono* lui){
	lui->tick_cumul = 0;
	lui->tick_initial = clock();
}
/*---------------------------------------------------*/
/* STRATÉGIE  	
	s il marche, on ajoute le temps, on garde ce temps d'action  
	on retourne le temps cumulé en secondes 
*/
double get_chrono(struct chrono* lui){ 
	if (lui->on_off_ ){
		lui->tick_cumul += (clock() - lui->tick_initial);
	}
	lui->tick_initial = clock();

	/* on retourne le temps cumulé en tocs   */
	return (lui->tick_cumul /CLOCKS_PER_SEC);
}
/*---------------------------------------------------*/
/* STRATÉGIE
	retourne la différence entre le temps actuel et
	le temps inscrit dans le chronomètre lors de la 
	dernière méthode prise en compte.
	Ce temps est en clocs on le divise pour obtenir des secondes.
*/
double toc_chrono( struct chrono* lui){ 
	return ((clock() - lui->tick_initial) /CLOCKS_PER_SEC) ;
}
/*---------------------------------------------------*/
/* STRATÉGIE
	retourne directement le champ on_off_
*/
int get_etat( struct chrono* lui){ 
	return lui->on_off_  ;
}
/*---------------------------------------------------*/

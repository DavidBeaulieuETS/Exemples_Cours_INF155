/*****************************************************************************
	Par        : David Baulieu
	Revise le  : A12
	Fichier    : test_chronos.c
	Objectifs  : Démontrer l'usage d'un module externe et l'utilisation de nouveaux types.
	Note	   : Vous remarquerez que l'usage de nouveau types implique l'usage de fonctions spécialisés.		
*****************************************************************************/


/* Inclure au projet les librairies */
#include <stdlib.h>		/* Module Standart */
#include <stdio.h>		/* Module Entrées - Sorties */
#include "chronos.h"


/****************************************************************************/
/*							DEFINITIONS DES CONSTANTES						*/
/****************************************************************************/

#define MAX_TEMPS 10000

/****************************************************************************/
/*							PROGRAMME PRINCIPAL								*/
/****************************************************************************/
int main(void)
{
	int i,j;
	/* On créé deux variable du type chronos */
	t_chrono chronometre_1;
	t_chrono chronometre_2;

	/* On initialise les deux chronomètres */
	chronometre_1 = init_chrono();
	chronometre_2 = init_chrono();

	/* On démare les deux chronomètres */
	start_chrono(chronometre_1);
	start_chrono(chronometre_2);

	/* On perd du temps */
	for(i=0; i<MAX_TEMPS; ++i){
		for(j=0; j<MAX_TEMPS; ++j){
		}
	}

	/* On affiche les valeus des deux chronomètres */
	printf("Get chronos apres la premiere boucle\n");
	printf("Temps du chrono 1 : %f\n",get_chrono(chronometre_1));
	printf("Temps du chrono 2 : %lf\n\n",get_chrono(chronometre_2));

	/* On arrête le chronomètre 1 */
	stop_chrono(chronometre_1);

	/* On perd du temps */
	for(i=0; i<MAX_TEMPS; ++i){
		for(j=0; j<MAX_TEMPS; ++j){
		}
	}
	
	/* On arrête le chronomètre 2 */
	stop_chrono(chronometre_2);

	/* On affiche les valeus des deux chronomètres */
	printf("Get chronos apres la deuxieme boucle\n");
	printf("Temps du chrono 1 : %lf\n",get_chrono(chronometre_1));
	printf("Temps du chrono 2 : %lf\n\n",get_chrono(chronometre_2));


	system("pause");	  /*Ajoute une pause à la fenetre console */
	return EXIT_SUCCESS;  /*Permet de terminer le programme proprement*/
}
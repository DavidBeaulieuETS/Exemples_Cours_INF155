/*****************************************************************************************
	Par        :	David Beaulieu
	Revise le  :	H 2024
	Fichier    :	tableauAvecBoucle.c
	Objectifs  :	Fichier exemple pour expliquer la manipilation de tableau avec les boucles
	Note	   :	NA
*****************************************************************************************/


/****************************************************************************************
*                            AJOUT DES MODULES ET LIBRAIRIES                            *
****************************************************************************************/
#include <stdlib.h>					
#include <stdio.h>				
#include <math.h>

/****************************************************************************************
*                               DÉFINITION DES CONSTANTES                               *
****************************************************************************************/
#define TAILLE 10

/****************************************************************************************
*								DÉCLARATION DES FONCTIONS								*
****************************************************************************************/

/*
	NOM	:			entierAleatoire
	DEF :			Génére un nombre entier aléatoire compris entre
					les valeur min et max
	PARAMETRES :	min : Valeur minimum généré
					max : Valeur maximum généré
	RETOUR :		Un entier aléatoire
	SPÉCIFICATION : Le générateur aléatoire doit être initialisé avant l'appel.
*/
int entierAleatoire(int min, int max);


/****************************************************************************/
/*							PROGRAMME PRINCIPAL								*/
/****************************************************************************/
int main(void) {

	//Déclaration des variables
	int i; 
	int listeA[TAILLE] = {34,78,54,12,0,45,56,90,55,28};
	int listeB[TAILLE];

	//Initialisation du générateur pseudo-aléatoire
	srand((unsigned int)time(NULL));
	rand();

	//Exemple de boucle d'initialisation des éléments d'un tableau avec une valeur statique
	for (i = 0; i < TAILLE; i++) {

		listeB[i] = 0;
	}

	//Exemple de boucle d'initialisation des éléments d'un tableau avec une valeur dynamique
	for (i = 0; i < TAILLE; i++) {

		listeB[i] = i;
	}


	//Exemple de boucle d'initialisation des éléments d'un tableau avec les valeurs d'un autre tableau (une copie !)
	for (i = 0; i < TAILLE; i++) {

		listeB[i] = listeA[i];
	}


	//Exemple de boucle d'initialisation des éléments d'un tableau avec une valeur aléatoire ou le résultat d'une fonction
	for (i = 0; i < TAILLE; i++) {

		listeB[i] = entierAleatoire(-10, 10);
	}


	//Exemple de boucle qui permet l'affichage des éléments du tableau
	for (i = 0; i < TAILLE; i++) {

		printf("\x90l\x82ment %d = %d \n", i, listeB[i]);
	}

	return EXIT_SUCCESS;
}






/****************************************************************************/
/*							DEFINITION DES FONCTIONS						*/
/****************************************************************************/
/*
	NOM	:			entierAleatoire
	DEF :			Génére un nombre entier aléatoire compris entre
					les valeur min et max
	PARAMETRES :	min : Valeur minimum généré
					max : Valeur maximum généré
	RETOUR :		Un entier aléatoire
	SPÉCIFICATION : Le générateur aléatoire doit être initialisé avant l'appel.
*/
int entierAleatoire(int min, int max) {

	return min + (int)(rand() / (RAND_MAX + 0.001) * (max - min + 1));
}

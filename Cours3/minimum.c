/*****************************************************************************************
	Par        : David Beaulieu
	Revise le  : H2025
	Fichier    : minimum.c
	Objectifs  : Faire une démonstration de fonction
	Note	   : 		

	NOTE DE L'ENSEIGNANT : Les commentaires de ce module sont des explications, ils ne
						   représentent pas vraiment ce qui est attendu de vous lors
						   de la remise de vos travaux pratiques.

*****************************************************************************************/


/****************************************************************************************
*                            AJOUT DES MODULES ET LIBRAIRIES                            *
****************************************************************************************/
#include <stdlib.h>		// Librairie Standard
#include <stdio.h>		// Librairie Entrer - Sortie

/****************************************************************************************
*								DÉCLARATION DES FONCTIONS								*
****************************************************************************************/
/*
	MINIMUM 
	DEF : Fonction qui retourne le minimum de deux entiers recu en paramètre
	PARAMETRES :	- Première valeur que l'on veut comparer (TYPE : int)
					- Deuxième valeur que l'on veut comparer (TYPE : int)
	RETOUR : valeur minimum. (TYPE: int)
	SPÉCIFICATION : NA
*/
int minimum (int, int);  /* Ici on peut mettre ou pas le nom des paramètre formel */

/****************************************************************************************
*                           DÉFINITION DU PROGRAMME PRINCIPALE                          *
****************************************************************************************/
int main(void)
{
	int variableA = 0;			// Une des valeurs à comparer
	int variableB = 0;			// L'autre valeur à comparer
	int resultat = 0;			// Résultat de la fonction

	// Acquisition des valeurs
	printf("Entrez une premiere valeur : ");
	scanf("%i",&variableA);

	printf("\nEntrez une deuxieme valeur : ");
	scanf("%i",&variableB);
	printf("\n");

	// Appel de la fonction minimum
	resultat = minimum(variableA,variableB);

	printf ("\nLa valeur minimum entrez est : %i\n\n",resultat);
	
	system("pause");	  						// Ajoute une pause à la console
	return EXIT_SUCCESS;  						// Permets de terminer le programme proprement
}

/****************************************************************************************
*									DÉFINITION DES FONCTIONS							*
****************************************************************************************/
/*
	MINIMUM 
	DEF : Fonction qui retourne le minimum de deux entiers recu en paramètre
	PARAMETRES :	- Première valeur que l'on veut comparer (TYPE : int)
					- Deuxième valeur que l'on veut comparer (TYPE : int)
	RETOUR : valeur minimum. (TYPE: int)
*/
int minimum (int valA, int valB)
{
	if (valA >= valB) {

		return  valB;		// Le return permet d'associer une valeur de retour à la fct.
    }
	else{					// Il a aussi pour effet de quitter la fct.
		return  valA;
    }
}
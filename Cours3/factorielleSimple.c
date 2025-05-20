/*****************************************************************************************
	Par        : David Beaulieu
	Revise le  : 
	Fichier    : factorielleSimple.c
	Objectifs  : Faire une démonstration de fonction et de passage par valeur
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
*                               DÉFINITION DES CONSTANTES                               *
****************************************************************************************/

/****************************************************************************************
*								DÉCLARATION DES FONCTIONS								*
****************************************************************************************/
/*
	FACTORIELLE 
	DEF : Fonction qui calcul le factorielle d'un nombre.
	PARAMETRES :	- Valeur que l'on veut calculer ls factorielle (TYPE: int)
	RETOUR : resultat (TYPE: unsigned long int)
*/
unsigned long int factorielle (int facto);

/****************************************************************************************
*                           DÉFINITION DU PROGRAMME PRINCIPALE                          *
****************************************************************************************/
int main(void)
{

	int valeur = 0;
	unsigned long int resultat = 0;

	// Acquisation des valeurs
	printf("Entrez une valeur pour le calcul du factorielle : ");
	scanf("%i",&valeur);

	// Appel de la fonction
	resultat = factorielle (valeur);

	printf ("\nLe factorielle de %i est %lu\n\n",valeur,resultat);
	
	system("pause");	  		        // Ajoute une pause à la fenêtre console
	return EXIT_SUCCESS;  		        // Permet de terminer le programme proprement
}

/****************************************************************************************
/									DEFINITION DES FONCTIONS							*
****************************************************************************************/
/*
	FACTORIELLE 
	DEF : Fonction qui calcul le factorielle d'un nombre.
	PARAMETRES :	- Valeur que l'on veut calculer ls factorielle (TYPE: int)
	RETOUR : resultat (TYPE: int)
*/
unsigned long int factorielle (int facto)
{
	unsigned long int resultatLocal = 1;

	while (facto > 0)
	{
		resultatLocal = resultatLocal * facto;
		facto = facto - 1;
	}
	return resultatLocal;
}
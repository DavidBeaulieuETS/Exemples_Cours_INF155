/*****************************************************************************
	Par        : David Beaulieu
	Revisé le  : H 2025
	Fichier    : pyramide.c
	Objectifs  : Permet d'afficher dans la console une pyramide d'étoiles
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
*                           DÉFINITION DU PROGRAMME PRINCIPALE                          *
****************************************************************************************/
int main (void)
{
	int ligne = 0;		// Taille en ligne de la pyramide
	int colonne = 0;	// Taille en colonne de la pyramide
	int nbEtoile = 0;	// Taille de la base de la pyramide
	setbuf(stdout, 0);        // Permet d'afficher les printfs en mode débug avec Clion

	// Acisition du nombre d'étoile au clavier qui définit aussi la base de la pyramide
	printf("Entrez un nombre d'etoile : ");
	scanf("%i",&nbEtoile);
	printf("\n");

	// On itère chacune des lignes jusqu'a la base d'étoiles voulue
	for(ligne = 1 ; ligne <= nbEtoile; ++ligne)
	{
		// Le numéro de la ligne est égal au nombre d'étoile à afficher
        // On inscrit chacune des étoiles pour la ligne donnée
		for (colonne = ligne; colonne > 0; --colonne)
		{
			printf("*");
		}

		// Saut de ligne
		printf("\n");
	}

	printf("\n\n");
	return EXIT_SUCCESS;  		        // Permet de terminer le programme proprement
}






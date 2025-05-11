/*****************************************************************************
	Par        : David Beaulieu
	Revise le  : 2025
	Fichier    : utilisationFonction.c
	Objectifs  :	Donner un d'utilisation de fonction dans les modules standard.
					Avec le calcul d'un hypothéneuse

	NOTE DE L'ENSEIGNANT : Les commentaires de ce module sont des explications, ils ne
						   représentent pas vraiment ce qui est attendu de vous lors
						   de la remise de vos travaux pratiques.
*****************************************************************************************/

/****************************************************************************************
*                            AJOUT DES MODULES ET LIBRAIRIES                            *
****************************************************************************************/
#include <stdlib.h>		// Librairie Standart
#include <stdio.h>		// Librairie Entrer - Sortie
#include <math.h>		// Librairie de fonction mathématique

/****************************************************************************************
*                           DÉFINITION DU PROGRAMME PRINCIPALE                          *
****************************************************************************************/
int main(void)
{
	double base = 12.6;
	double hauteur = 34.89;
	double tempo;
	double hyp;

	setbuf(stdout, 0);        // Permet d'afficher les printfs en mode débug avec Clion

    // Calcul de l'hypothénuse
	tempo = pow(base,2) + pow(hauteur,2);
	hyp = sqrt(tempo); 

	printf("la valeur de l'hypothenuse = %.3lf\n\n",hyp);

	system("pause");	  				// Ajoute une pause à la fenêtre console
	return EXIT_SUCCESS;  		        // Permet de terminer le programme proprement
}



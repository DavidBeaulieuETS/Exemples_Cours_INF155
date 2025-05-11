/*****************************************************************************
	Par        : David Beaulieu
	Revise le  : H 2025
	Fichier    : ExempleDeTrace
	Objectifs  : Expliquer comment faire une trace - avec la Conjecture de Syracuse
	Note	   : https://fr.wikipedia.org/wiki/Conjecture_de_Syracuse
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
#define CONST 3

/****************************************************************************************
*                           DÉFINITION DU PROGRAMME PRINCIPALE                          *
****************************************************************************************/
int main (void)
{
	int x = CONST;
	int y = 1;
	
	// On boucle tant que x est différent de 1.
	while (x != 1)
	{
		// Si x est un multiple de 2, alors on divise x par 2 et multiplie y * x.
		if (x % 2 == 0){
			x = x / 2;
			y = y * x;           // Calcule un produit cumulatif dans y à chaque fois que x est pair
		}                        // Facultatif au calcul de la conjoncture de Syracruse
        // Sinon, on le multiplie par 3 et on lui additionne 1. (3x + 1)
		else
		{
   			x = x * CONST + 1;
		}
		printf("Valeur de x : %i \t\t\tValeur de y %i\n", x,y); 
		// Le printf ne sert qu'a valider notre réponse */
	}

	return EXIT_SUCCESS;  		        // Permet de terminer le programme proprement
}







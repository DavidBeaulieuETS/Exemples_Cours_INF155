/*****************************************************************************
	Par        : David Beaulieu
	Revise le  : 01/07/11
	Fichier    : Exemple de trace
	Objectifs  : Expliquer comment faire une trace - En passant c'est � l'examen.
	Note	   : 		
*****************************************************************************/
/*
QUESTION: Pour chaque it�ration de la boucle faite la trace de la variable x et y.
*/

/* Inclure au projet les librairies */
#include <stdlib.h>		/* Librairie Standart */
#include <stdio.h>		/* Librairie Entrer - Sortie */


/****************************************************************************/
/*							DEFINITIONS DES CONSTANTES						*/
/****************************************************************************/

#define CONST 3

/****************************************************************************/
/*							PROGRAMME PRINCIPAL								*/
/****************************************************************************/
int main (void)
{

	int x = CONST;
	int y = 1;
	
	/* NDE : On boucle tant que x est diff�rent de 1. */
	/* NDE : Belle exemple de l'utilisation du while Vs le for */
	while (x != 1)
	{
		/* NDE : 	Si x est un multiple de 2, alors on divise x par 2.
				Sinon, on le multiplie par 3 et on lui additionne 1. */
		if (x % 2 == 0){
			x = x / 2;
			y = y * x;
		}
		else
		{
   			x = x * CONST + 1;
		}
		printf("Valeur de x : %i \t\t\tValeur de y %i\n", x,y); 
		/* Ici le printf ne sert qu�a valider notre r�ponse */
	}

	system("pause");	  
	return EXIT_SUCCESS;
}







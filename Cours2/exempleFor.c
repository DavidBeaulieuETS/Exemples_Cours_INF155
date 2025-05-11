/*****************************************************************************
	Par        : David Beaulieu
	Revise le  : 
	Fichier    : Exemple_3.c
	Objectifs  : Montrer la boucle for
	Note	   : 		
*****************************************************************************/


/* Inclure au projet les librairies */
#include <stdlib.h>		/* Librairie Standart */
#include <stdio.h>		/* Librairie Entrer - Sortie */


/****************************************************************************/
/*							DEFINITIONS DES CONSTANTES						*/
/****************************************************************************/

#define BORNE_MIN 3
#define BORNE_MAX 100



/****************************************************************************/
/*							PROGRAMME PRINCIPAL								*/
/****************************************************************************/
int main(void)
{
	int i;
	int somme;
		
	somme = 0; /* Essayez de ne pas initialiser cette variable !! */

	/* On fait la somme des eniters de l'interval */
	/* Essayez de faire la m�me chose avec un for ?? */
	for(i = BORNE_MIN; i<=BORNE_MAX; i++ )
	{
		if( i%2 == 0 )
		{
			somme = somme + i;
		}
	}
	printf ("la somme des entiers pair de l'interval %i a %i est %i\n\n",BORNE_MIN,BORNE_MAX,somme);

	/* On peut faire la m�me chose avec un While */

	somme = 0;
	while (i < BORNE_MAX)
	{
		if(i%2 == 0)
		{
			somme = somme + i;
		}
	
	i++;
	}
 


	system("pause");	  /*Ajoute une pause � la fenetre console */
	return EXIT_SUCCESS;  /*Permet de terminer le programme proprement*/
}

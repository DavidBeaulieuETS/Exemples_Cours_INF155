/*****************************************************************************
	Par        : David Beaulieu
	Revise le  : A12
	Fichier    : gen_alea.c
	Objectifs  : Donner un exemple de l'utilisation des fonction de pseudo-al�atoire
	Note	   : 		
*****************************************************************************/

#include <stdlib.h>		/* NDE : module Standart */
#include <stdio.h>		/* NDE : module Entrer - Sortie */
#include <time.h>

#define NB_NOMBRE 20
#define MIN 1
#define MAX 1000

/****************************************************************************/
/*							PROGRAMME PRINCIPAL								*/
/****************************************************************************/
int main(void)
{
	int i, nombre_entier;
	double nombre_reel;

	/* Essayer de mettre la ligne suivante dans une des boucles */

	srand(time(NULL));	/* Initialise le générateur pseudo-al�atoire avec le temps courant de l'horloge */
	printf("Valeur de time : %u \n\n",time(NULL));

	//srand(1234);		/* Initialise le g�n�rateur pseudo-al�atoire avec un eniter */

	printf("Valeur du RAND_MAX %i\n\n",RAND_MAX);

	/* Affiche la s�rie de nombre pseudo-al�atoire de la fonction rand()*/
	printf("FONCTION RAND()\n");
	for(i=0; i < NB_NOMBRE; ++i)
	{
		printf("%i\n" ,rand());
	}

	system("pause");

	/* Affiche la s�rie de nombre entier pseudo-al�atoire de la fonction rand() born� par un calcul*/
	printf("\n\nNOMBRE ENTIER AVEC BORNE\n");
	for(i=0; i < NB_NOMBRE; ++i)
	{
		nombre_entier = (MIN + (int)(rand() / (RAND_MAX + 0.005) * (MAX - MIN + 1)));

		printf("%i\n" ,nombre_entier);
	}

	system("pause");

	/* Affiche la s�rie de nombre reel pseudo-al�atoire de la fonction rand() born� par un calcul*/
	printf("\n\nNOMBRE REEL AVEC BORNE\n");
	for(i=0; i < NB_NOMBRE; ++i)
	{
		nombre_reel = ((double)MIN + ((double)rand() / ((double)RAND_MAX + 0.005) * ((double)MAX - (double)MIN + 1.0)));

		printf("%.3lf\n" ,nombre_reel);
	}

	system("pause");	  
	return EXIT_SUCCESS; 
}
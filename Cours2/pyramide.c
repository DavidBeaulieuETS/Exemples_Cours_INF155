/*****************************************************************************
	Par        : David Beaulieu
	Revise le  : 01/07/11
	Fichier    : Pyramide d'�toile
	Objectifs  : Expliquer comment faire un pseudo-code.
	Note	   : 		
*****************************************************************************/

/* Inclure au projet les librairies */
#include <stdlib.h>		/* Librairie Standart */
#include <stdio.h>		/* Librairie Entrer - Sortie */


/****************************************************************************/
/*							DEFINITIONS DES CONSTANTES						*/
/****************************************************************************/

/****************************************************************************/
/*							PROGRAMME PRINCIPAL								*/
/****************************************************************************/
int main (void)
{

	int ligne = 0;
	int colonne = 0;
	int nbEtoile = 0;

	/*Acisition du nombre d'étoile au clavier*/
	printf("Entrez un nombre d'etoile : ");
	scanf("%i",&nb_etoile);

	/* le nombre d'étoile est égal au nombre de ligne */
	ligne = nb_etoile;
	
	/* on itère chacune des lignes */
	while (ligne > 0)
	{
		/* le numéro de la ligne est �gal au nombre d'�toile */
		colonne = ligne;
		
		/*On inscrit chacune des �toiles pour la ligne donn�e */
		while (colonne > 0)
		{
			printf("*");
			colonne = colonne - 1;
		}

		/* Saut de ligne */
		printf("\n");
		/* D�cr�mente le nombre de ligne */
		ligne = ligne - 1;
	}

	printf("\n\n");
	system("pause");	  /*Ajoute une pause � la fenetre console */
	return EXIT_SUCCESS;  /*Permet de terminer le programme proprement*/
}






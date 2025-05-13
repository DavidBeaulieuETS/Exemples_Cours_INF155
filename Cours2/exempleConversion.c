/*****************************************************************************
	Par        : David Beaulieu
	Revise le  : A12
	Fichier    : exempleConversion.c
	Objectifs  : Donner un exemple des trois types de ocnversions
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
*                           DÉFINITION DU PROGRAMME PRINCIPALE                          *
****************************************************************************************/
int main(void)
{
	char caract = 0;
	unsigned char uCaract = 100;
	int entier = 20 ;
	unsigned long int uLong = 0;
    double reel = 23.45;
    double resultat = 34.66;

    setbuf(stdout, 0);        // Permet d'afficher les printfs en mode débug avec Clion


     entier = reel + resultat ;






	printf("Exemple de conversion \n*************************\n\n");
	
	/**** Conversion intégral ****/
	printf("/**** Conversion integral ****/\n");
	printf("\nun u char : %i \n", uCaract);
	entier = (int)uCaract;
	printf("un u char dans un entier : %i\n\n",entier);
		
	system("pause");

	/**** Conversion conforme ****/
	printf("\n\n/**** Conversion conforme ****/\n");
	entier = -5;
	printf("\nUn int    : %i \n", entier);
	uLong = (unsigned long int)entier;
	printf("Un entier negatif dans un u long : %lu\n",uLong);
	printf("Le meme u long afficher comme un int  : %i\n\n",(int)uLong);

	system("pause");

	printf("\n\n/**** Conversion degradente ****/\n");
	uLong = 50000;
	printf("Un u long : %lu\n",uLong);
	caract = (char)uLong;
	printf("Un u long dans un char : %i\n", caract);
	printf("Le meme char afficher comme un u long : %ul\n\n",(unsigned long int)caract);
	
	system("pause");	  				// Ajoute une pause à la fenêtre console
	return EXIT_SUCCESS;  		        // Permet de terminer le programme proprement
}
/****************************************************************************************
	Auteur  : David Beaulieu
	Date    : 9 janvier 2022
	Fichier : type_et_io.c

	Description: Programme exemple pour l'aquisition et l'affichage 
				des types de bases.

	NOTE DE L'ENSEIGNANT : Les commentaires de ce module sont des explications, ils ne
						   représentent pas vraiment ce qui est attendu de vous lors
						   de la remise de vos travaux pratiques.

*****************************************************************************************/

/****************************************************************************************
*                               COMMANDE DU PRÉPROCESSEUR                               *
****************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>		/* Librairie Standart */
#include <stdio.h>		/* Librairie Entrer - Sortie */

/****************************************************************************************
*                               DÉFINTION DES CONSTANTES                                *
****************************************************************************************/


/****************************************************************************************
*                           DÉFINTION DU PRGORAMME PRINCIPALE                           *
****************************************************************************************/
int main(void)
{
	// Déclaration des variables
	char caractere = 0;
	int entier = 0;
	double reel = 0;

	printf("\nEssayez differents formats pour les differents types saisis.\n\n ");

	// Aquisisition d'un Char
	printf("\nSaisisez un char : ");
	fflush(stdin);    	// Dès que l'on saisi un caractère, on doit s'assurer qu'il n'y a rien dans le
						// tampon du clavier.
	scanf("%c",&caractere);
	printf("\nLa valeur saisie : %c \n",caractere);

	system("pause");	/* NDE : Ajoute une pause à la fenetre console */

	// Aquisisition d'un entier
	printf("\nSaisisez un entier : ");
	scanf("%i",&entier);
	printf("\nLa valeur saisie : %i \n",entier);

	system("pause");	/* NDE : Ajoute une pause à la fenetre console */

	// Aquisisition d'un double
	printf("\nSaisisez un double : ");
	scanf("%lf",&reel);
	printf("\nLa valeur saisie : %f \n",reel);

	system("pause");	  /* NDE : Ajoute une pause à la fenetre console */
	return EXIT_SUCCESS;  /* NDE : Permet de terminer le programme proprement*/
}
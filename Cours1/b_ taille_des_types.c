/****************************************************************************************
	Auteur  : David Beaulieu
	Date    : 9 janvier 2022
	Fichier : taille_des_types.c

	Description: Programme permet d'afficher la taille des types de bases.

	NOTE DE L'ENSEIGNANT : Les commentaires de ce module sont des explications, ils ne
						   représentent pas vraiment ce qui est attendu de vous lors
						   de la remise de vos travaux pratiques.

*****************************************************************************************/


/****************************************************************************************
*                               COMMANDE DU PRÉPROCESSEUR                               *
****************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>		/* NDE : Librairie Standart */
#include <stdio.h>		/* NDE : Librairie Entrer - Sortie */
#include <limits.h>		/* NDE : Pour les limites des types entiers. */
#include <float.h>		/* NDE : Pour les limites des types reels. */


/****************************************************************************************
*                               DÉFINTION DES CONSTANTES                                *
****************************************************************************************/

/****************************************************************************************
*                           DÉFINTION DU PRGORAMME PRINCIPALE                           *
****************************************************************************************/
int main(void)
{
	/* *** Taille des types entiers *** */
	printf("Un %18s va de %12i a %10i et est de %i octet\n", "char", CHAR_MIN, CHAR_MAX, sizeof(char));
	printf("Un %18s va de %12u a %10u et est de %i octet\n", "unsigned char", 0, UCHAR_MAX, sizeof(unsigned char));
	printf("Un %18s va de %12i a %10i et est de %i octet\n", "short int", SHRT_MIN, SHRT_MAX, sizeof(short int));
	printf("Un %18s va de %12u a %10u et est de %i octet\n", "unsigned short int", 0, USHRT_MAX, sizeof(unsigned short int));
	printf("Un %18s va de %12i a %10i et est de %i octet\n", "int", INT_MIN, INT_MAX, sizeof(int));
	printf("Un %18s va de %12u a %10u et est de %i octet\n", "unsigned int", 0, UINT_MAX, sizeof(unsigned int));
	printf("Un %18s va de %12li a %10li et est de %i octet\n", "long int", LONG_MIN, LONG_MAX, sizeof(long int));
	printf("Un %18s va de %12u a %10lu et est de %i octet\n", "unsigned long int", 0, ULONG_MAX, sizeof(unsigned long int));

	system("pause");	  /*Ajoute une pause à la fenetre console */

	/* *** Taille des types réel *** */
	printf("\n\nUn %11s va de %12e a %10e et est de %i octet\n", "float", FLT_MIN, FLT_MAX, sizeof(float));
	printf("Un %11s va de %12e a %10e et est de %i octet\n", "double", DBL_MIN, DBL_MAX, sizeof(double));
	printf("Un %11s va de %12e a %10e et est de %i octet\n\n", "long double", LDBL_MIN, LDBL_MAX, sizeof(long double));

	return EXIT_SUCCESS;  /*Permet de terminer le programme proprement*/
}
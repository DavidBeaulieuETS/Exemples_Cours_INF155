/****************************************************************************************
	Auteur  : David Beaulieu
	Date    : 9 janvier 2022
	Fichier : attribution_des_cotes.c

	Description: Programme qui permet l'attribution des cote selon une note entrée au clavier

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
*                               DÉFINITION DES CONSTANTES                                *
****************************************************************************************/


/****************************************************************************************
*                           DÉFINITION DU PROGRAMME PRINCIPALE                           *
****************************************************************************************/
int main(void)
{	
	int notes = 0;
	
	// Demande au clavier de la note obtenue 
	printf("Entrez votre note : ");
	scanf("%i",&notes);
	
	printf("\nVous obtenez un : ");

	if(notes < 60)
		printf("Echec\n");
	else if (notes >= 60 && notes < 65)
		printf("D\n");

	else if (notes >= 65 && notes < 75)
		printf("C\n");

	else if (notes >= 75 && notes < 90)
		printf("B\n");

	else if (notes >= 90 && notes < 100)
		printf("A\n");
	else if (notes == 100 )
		printf("Parfait!!!\n");

	/*On fini souvent cette expression par un else (valeur par défault)*/

	system("pause");	  /*Ajoute une pause à la fenetre console */
	return EXIT_SUCCESS;  /*Permet de terminer le programme proprement*/
}

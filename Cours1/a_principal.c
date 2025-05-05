/****************************************************************************************
    Auteur  : David Beaulieu
    Date    : 9 janvier 2022
    Fichier : principal.c

    Description: Programme test Hello World !!

    NOTE DE L'ENSEIGNANT : Les commentaires de ce module sont des explications, ils ne
                           représentent pas vraiment ce qui est attendu de vous lors
                           de la remise de vos travaux pratiques.

*****************************************************************************************/


/****************************************************************************************
*                               COMMANDE DU PRÉPROCESSEUR                               *
****************************************************************************************/
#define     _CRT_SECURE_NO_WARNINGS
#include    <stdio.h>
#include    <stdlib.h>

/****************************************************************************************
*                               DÉFINITION DES CONSTANTES                                *
****************************************************************************************/

/****************************************************************************************
*                           DÉFINITION DU PROGRAMME PRINCIPALE                           *
****************************************************************************************/
int main(void)
{
	printf("Mon Hello World !!!\n");
	system("pause");

	return EXIT_SUCCESS;		/* Permet de terminer le programme proprement */
}
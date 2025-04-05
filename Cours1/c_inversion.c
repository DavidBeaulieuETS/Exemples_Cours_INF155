/****************************************************************************************
	Auteur  : David Beaulieu
	Date    : 9 janvier 2022
	Fichier : principal.c

	Description: Exemple d'inversion entre deux variables

	NOTE DE L'ENSEIGNANT : Les commentaires de ce module sont des explications, ils ne
						   repr�sentent pas vraiment ce qui est attendu de vous lors
						   de la remise de vos travaux pratiques.

*****************************************************************************************/


/****************************************************************************************
*                               COMMANDE DU PR�PROCESSEUR                               *
****************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

/****************************************************************************************
*                               D�FINTION DES CONSTANTES                                *
****************************************************************************************/

/****************************************************************************************
*                           D�FINTION DU PRGORAMME PRINCIPALE                           *
****************************************************************************************/
int main(void)
{
	int var_a = 33;
	int var_b = 22;
	int temporaire = 0;
	
	//Affichage de l'�tat initiale 
	printf("Etat Initiale\n");
	printf("Contenu de la variable A : %i\n", var_a);
	printf("Contenu de la variable B : %i\n\n", var_b);

	system("pause");

	// Op�rations d'inversion 
	temporaire = var_a;
	var_a = var_b;
	var_b = temporaire;

	//Affichage de l'�tat finale
	printf("Etat Final\n");
	printf("Contenu de la variable A : %i\n", var_a);
	printf("Contenu de la variable B : %i\n\n", var_b);

	system("pause");
	return EXIT_SUCCESS;
}
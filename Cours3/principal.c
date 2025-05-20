/*****************************************************************************************
	Par        : David Beaulieu
	Revise le  : H2025
	Fichier    : Principal.c
	Objectifs  : Ce module sert contexte au module jeuxHasard.c
	Note	   : Inclure jeuxHasard.h et jeuxHasard.c dans votre projet

NOTE DE L'ENSEIGNANT : Les commentaires de ce module sont des explications, ils ne
						   représentent pas vraiment ce qui est attendu de vous lors
						   de la remise de vos travaux pratiques.

*****************************************************************************************/


/****************************************************************************************
*                            AJOUT DES MODULES ET LIBRAIRIES                            *
****************************************************************************************/
#include <stdlib.h>			/* Module Standart */
#include <stdio.h>			/* Module Entrer - Sortie */
#include <time.h>			/* Module utile pour la fonction time() */
#include "jeuxHasard.h"		/* On inclut le module (Remarquez les guillements anglais !) */


/****************************************************************************************
*                           DÉFINITION DU PROGRAMME PRINCIPALE                          *
****************************************************************************************/
int main(void)
{

	int i = 0;
	int choixUtilisateur = 0;
	srand(time(NULL));	/* Initialisation du générateur aléatoire */
						/* Il est très important de ne pas refaire l'initialisation du   */
						/* On doit le faire seulement UNE FOIS dans le main() c'est tout */
	
	do
	{
		/* Affiche le menu principal et demande le choix de jeux */
		afficherMenu();
		choixUtilisateur = aquisitionClavier(0,3);

		/* Comparaison des choix */
		if (choixUtilisateur == CHOIX_PF)
		{
			lancerPileFace();
			system("pause");
		}
		else if (choixUtilisateur == CHOIX_DE)
		{
			lancerDe();
			system("pause");
		}
		else if (choixUtilisateur == CHOIX_RPC)
		{
			jeuxRochePapierCiseau();
			system("pause");
		}
		else if (choixUtilisateur == QUITTER)
		{
			printf("\n\nMerci !\n\n");
		}

	}while(choixUtilisateur != QUITTER);		// On boucle tant que l'utilisateur ne veux pas quitter

	system("pause");	  						// Ajoute une pause à la console
	return EXIT_SUCCESS;  						// Permets de terminer le programme proprement
}
/*****************************************************************************
	Par        : David Beaulieu
	Revise le  : H 2025
	Fichier    : genAlea.c
	Objectifs  : Donner un exemple de l'utilisation des fonctions de pseudo-aléatoire		
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
#include <time.h>       // Libairie de gestion du temps 
/****************************************************************************************
*                               DÉFINITION DES CONSTANTES                               *
****************************************************************************************/
#define NB_NOMBRE 10         // Quantité de nombre aléatoire à afficher
#define MIN 1                // Valeur minimum des nombres aléatoires à afficher
#define MAX 1000             // Valeur maximum des nombres aléatoires à afficher

/****************************************************************************************
*                           DÉFINITION DU PROGRAMME PRINCIPALE                          *
****************************************************************************************/
int main(void)
{
    // Déclaration des variables
    int i, nombreEntier;
	double nombreReel;
    setbuf(stdout, 0);        // Permet d'afficher les printfs en mode débug avec Clion

    // Initialise le générateur pseudo-aléatoire avec le temps courant de l'horloge
	//srand(time(NULL));
    rand();
	printf("Valeur de time : %lld \n\n",time(NULL));    // affiche la valeur du temps courant, inutile pour l'initialisation


    // Initialise le générateur pseudo-aléatoire avec un eniter, ceci n'est pas toujours conseillé
	srand(1234);

    // Permet de connaitre la valeur maximum générer par rand
	printf("Valeur du RAND_MAX %i\n\n",RAND_MAX);

	// Affiche la série de nombre pseudo-aléatoire de la fonction rand()
	printf("FONCTION RAND()\n");
	for(i=0; i < NB_NOMBRE; ++i)
	{
		printf("%i\n" ,rand());
	}

	system("pause");                    // Ajoute une pause à la fenêtre console

	// Affiche la série de nombre entier pseudo-aléatoire de la fonction rand() borné par un calcul
	printf("\n\nNOMBRE ENTIER AVEC BORNE\n");
	for(i=0; i < NB_NOMBRE; ++i)
	{
		nombreEntier = (MIN + (int)(rand() / (RAND_MAX + 0.005) * (MAX - MIN + 1)));

		printf("%i\n" ,nombreEntier);
	}

	system("pause");                    // Ajoute une pause à la fenêtre console

	// Affiche la série de nombre reel pseudo-aléatoire de la fonction rand() borné par un calcul
	printf("\n\nNOMBRE REEL AVEC BORNE\n");
	for(i=0; i < NB_NOMBRE; ++i)
	{
		nombreReel = ((double)MIN + ((double)rand() / ((double)RAND_MAX + 0.005) * ((double)MAX - (double)MIN + 1.0)));

		printf("%.3lf\n" ,nombreReel);
	}

	system("pause");                    // Ajoute une pause à la fenêtre console
	return EXIT_SUCCESS; 
}
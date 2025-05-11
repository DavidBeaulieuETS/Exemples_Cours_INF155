/*****************************************************************************
	Par        : David Beaulieu
	Revise le  : 
	Fichier    : exempleWhile.c
	Objectifs  : Montrer la boucle while en fesant la somme des chiffres d'un nombre.
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
*                               DÉFINITION DES CONSTANTES                               *
****************************************************************************************/
#define NOMBRE 356789  		// Nombre avec lequel on veut faire la somme des chiffres
							// Faire attention que la valeur de NOMBRE entrer dans un type entier long

/****************************************************************************************
*                           DÉFINITION DU PROGRAMME PRINCIPALE                          *
****************************************************************************************/
int main(void)
{
	long int nombre;
	int somme;
	int chiffre;

    setbuf(stdout, 0);        // Permet d'afficher les printfs en mode débug avec Clion

	// Initialisation des variables
	nombre = NOMBRE;
	somme = 0; 						// Contient la somme des chiffre, Essayez de ne pas initialiser cette variable !!

    // Répète les instruction tant que la valeur de nombre est plus grande de 0
	while (nombre > 0)
	{
		chiffre = nombre % 10;		// Prend l'unité du nombre

		somme = somme + chiffre;	// Fait la somme

		nombre = nombre / 10;		// Réduit le nombre de son unit� */
	}

	printf ("\nLa somme des chiffres du nombre : %i est : %i\n\n",NOMBRE,somme);

    // Comment on pourait modifier ce code pour obtenir aussi le nombre de chiffre dans le nombre ?

	system("pause");	  				// Ajoute une pause à la fenêtre console
	return EXIT_SUCCESS;  		        // Permet de terminer le programme proprement
}
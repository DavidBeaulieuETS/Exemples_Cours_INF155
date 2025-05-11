/*****************************************************************************
	Par        : David Beaulieu
	Revise le  : E 2025
	Fichier    : exempleFor.c
	Objectifs  : Montrer l'utilisation de la boucle for
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
#define BORNE_MIN 3
#define BORNE_MAX 100

/****************************************************************************************
*                           DÉFINITION DU PROGRAMME PRINCIPALE                          *
****************************************************************************************/
int main(void)
{
	int nombre;		// Itérateur des nombres de l'intervalle
	int somme;		// Contient la somme des chiffres pair du nombre
		
	somme = 0;		// Essayez de ne pas initialiser cette variable !!

	setbuf(stdout, 0);        // Permet d'afficher les printfs en mode débug avec Clion

	// On fait la somme des entiers de l'intervalle
	// La boucle for permet de d'itérer les nombre de BORNE_MIN à BORNE_MAX
	for(nombre = BORNE_MIN; nombre<=BORNE_MAX; nombre++ )
	{
		// Le modulo 2 du nombre permet d'identifier si le nombre est pair ou impair
		// Le résultat du module de 2 du nombre est égale a 1 quand le nombre est impair et
		// égale à 1 quand le nombre est pair
		if( nombre % 2 == 0 )
		{
			somme = somme + nombre;		// Fait la somme des nombre pair uniquement
		}
	}
	printf ("La somme des entiers pair de l'intervalle %i a %i est %i\n\n",BORNE_MIN,BORNE_MAX,somme);

	// Peut-on faire la même chose avec une boucle while ??

	system("pause");	  		        // Ajoute une pause à la fenêtre console
	return EXIT_SUCCESS;  						// Permet de terminer le programme proprement
}

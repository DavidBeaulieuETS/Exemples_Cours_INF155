/*****************************************************************************************
	Par        :	David Beaulie
	Revise le  :	H 2025
	Fichier    :	manipulationTableau.c
	Objectifs  :	Fichier exemple pour expliquer la manipulation des tableaux 1D
	Note	   :	NA
*****************************************************************************************/

/****************************************************************************************
*                            AJOUT DES MODULES ET LIBRAIRIES                            *
****************************************************************************************/
#include <stdlib.h>					
#include <stdio.h>				
#include <math.h>

/****************************************************************************************
*                               DÉFINITION DES CONSTANTES                               *
****************************************************************************************/
#define TAILLE 3
#define NB_NOTES 8

/****************************************************************************************
*                           DÉFINITION DU PROGRAMME PRINCIPALE                          *
****************************************************************************************/
int main(void) {

	//Déclaration des variables
	int valeurTest = 0;

	//Déclaration d'un tableau exemple A
	//type identifiant[taille]= {valeur1, valeur2, ... };
	//int coordonnee[3];
	//ou bien 
	int coordonnee[TAILLE];

	//Déclaration d'un tableau exemple B
	//type identifiant[taille]= {valeur1, valeur2, ... };
	double notes[NB_NOTES] = { 70, 89, 72, 65, 12, 77, 81, 78 };


	//Assignation de valeur dans les case du tableau 
	coordonnee[0] = 28;
	coordonnee[1] = 12;
	coordonnee[2] = 7;
	
	//Erreur d'indice !!!
	//coordonnee[160] = 666;
	//coordonnee[1.5] = 666;
		 
	// Exemple d'un tableau dans un printf
	//printf("Valeur a l'indice 3 du tableau notes : %lf\n", notes[3]);

	// Exemples d'opération avec un tableau
	valeurTest = coordonnee[0] + coordonnee[1];
	notes[7] = notes[7] + 100;
	
	//Erreur d'indice 
	//valeurTest = coordonnee[3] + 10;
	
	//Erreur de type
	//notes[0] = 73.3333;

	printf("Valeur a l'indice 7 du tableau notes : %lf\n", notes[7]);

	// Exemple de condition avec des tableaux
	if (coordonnee[1] == notes[4]) {

		printf("Les 2 tableau on une valeur en commun !!\n");
	}

	//Exemple de donner UN ÉLÉMENT de tableau à une fonction
	valeurTest = pow(coordonnee[2], 2);


	//
	//  AFFICHAGE D'UN TABLEAU.
	//
	//  printf ne peut savoir combien de case il y a dans votre tableau.
	//  vous devez afficher les cases une par une.
	//
	for (int i = 0; i < NB_NOTES; i++)
	{
		printf("%0.1lf ", notes[i]);
	}
	printf("\n");


	system("pause");
	return EXIT_SUCCESS;
}
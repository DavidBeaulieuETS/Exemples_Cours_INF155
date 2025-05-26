/*****************************************************************************************
	Par        :	David Beaulieu
	Revise le  :	H 2024
	Fichier    :	tableauFonction.c
	Objectifs  :	Fichier exemple pour expliquer la manipilation de tableau avec les fonctions
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
#define TAILLE 10

/****************************************************************************************
*								DÉCLARATION DES FONCTIONS								*
****************************************************************************************/

/*
	NOM	:			reelAleatoire
	DEF :			Génére un nombre reel aléatoire compris entre
					les valeur min et max
	PARAMETRES :	min : Valeur minimum généré
					max : Valeur maximum généré
	RETOUR :		Un reel aléatoire
	SPÉCIFICATION : Le générateur aléatoire doit être initialisé avant l'appel.
*/
double reelAleatoire(double min, double max);

/*
	NOM	:			afficherTableauEntier
	DEF :			Fonction qui permet d'afficher un tableau de 
	PARAMETRES :	tableau[] : le tableau à afficher
					nbElements : le nombre d'élément du tableau reçu.
	RETOUR :		Aucun
*/
void afficherTableauEntier(int tableau[], int nbElements);

/*
	NOM :			afficherTableauReel
	DEF :			Fonction qui permet d'afficher un tableau de 
	PARAMETRES :	tableau[] : le tableau à afficher
	nbElements :	le nombre d'élément du tableau reçu.
	RETOUR :		Aucun
*/
void afficherTableauReel(double tableau[], int nbElements);

/*
	NOM	:			incrementerTableauEntier
	DEF :			Fonction qui permet d'incrémenter d'une valeur tous les
					éléments du tableau
	PARAMETRES :	tableau[] : le tableau à incrémenter
					nbElements : le nombre d'élément du tableau reçu.
					incrément : la veleur d'incrément des éléments
	RETOUR :		Aucun
*/
void incrementerTableauEntier(int tableau[], int nbElements, int increment);

/*
	NOM	:			initTableauEntier
	DEF :			Fonction qui permet d'initialiser les éléments d'un tableau à une valeur statique
	PARAMETRES :	tableau[] : le tableau à initilaiser
					nbElements : le nombre d'élément du tableau reçu.
					valeur : la valeur d'initialisation.
	RETOUR :		Aucun
*/
void initTableauEntier(int tableau[], int nbElements, int valeur);

/*
	NOM	:			compterValeurPair 
	DEF :			Fonction qui permet de compter le nombre de valeur pair dans un tableau 
	PARAMETRES :	tableau[] : le tableau à initilaiser
					nbElements : le nombre d'élément du tableau reçu.
	RETOUR :		Aucun
*/
int compterValeurPair(int tableau[], int nbElements);

/*
	NOM	:			initTableauAlea
	DEF :			Fonction qui permet d'initialiser les éléments d'un tableau avec des valeurs aléatoire
	PARAMETRES :	tableau[] : le tableau à initilaiser
					nbElements : le nombre d'élément du tableau reçu.
					valeur : la valeur d'initialisation.
	RETOUR :		Aucun
*/
void initTableauAleaReel(double tableau[], int nbElements, double min, double max);





/****************************************************************************************
*                           DÉFINITION DU PROGRAMME PRINCIPALE                          *
****************************************************************************************/
int main(void) {

	//Déclaration des variables
	int valeurTest = 0;
	int listeA[TAILLE] = { 34,78,54,12,44,45,56,90,55,28 };
	int listeB[TAILLE];
	double tab[TAILLE];

	//Initialisation du générateur pseudo-aléatoire
	srand((unsigned int)time(NULL));
	rand();


	//Exemple d'initialisation d'un tableau avec fonction
	initTableauEntier(listeB, TAILLE, 0);
	afficherTableauEntier(listeB, TAILLE);

	//Erreur d'appel du parametre de type tableau
	//initTableauEntier(listeB[0], TAILLE, 0);
	//initTableauEntier(listeB[TAILLE], TAILLE, 0);


	//Exemple d'appel d'un fonction avec un tableau
	afficherTableauEntier(listeA, TAILLE);				//On affiche 
	incrementerTableauEntier(listeA, TAILLE, 100);		//On incrémente
	afficherTableauEntier(listeA, TAILLE);				//Et on affiche le m�me tableau !!


	//Exemple d'appel de fonction avec retour dans une variable 
	valeurTest = compterValeurPair(listeA, TAILLE);
	printf("\nValeur de valeurTest = %d \n", valeurTest);


	//Exemple d'appel de fonction avec retour dans un élément de tableau.
	listeB[9] = compterValeurPair(listeA, TAILLE);
	printf("\nValeur de listeB[9] = %d \n\n", listeB[9]);

	//Exemple d'initialisation et affichage avec des tableau de type double
	initTableauAleaReel(tab, TAILLE, -1.0 , 1.0);
	afficherTableauReel(tab, TAILLE);

	//Test qui démontre une erreur
	//int* tableauLocal = initTableauEntierErreur(TAILLE, 666);
	//tableauLocal[3] = 0;
	//afficherTableauEntier(tableauLocal, TAILLE);

	return EXIT_SUCCESS;
}

/****************************************************************************************
/									DEFINITION DES FONCTIONS							*
****************************************************************************************/
/*
	NOM	:			reelAleatoire
	DEF :			Génére un nombre reel aléatoire compris entre
					les valeur min et max
	PARAMETRES :	min : Valeur minimum généré
					max : Valeur maximum généré
	RETOUR :		Un reel aléatoire
	SPÉCIFICATION : Le générateur aléatoire doit être initialisé avant l'appel.
*/
double reelAleatoire(double min, double max) {

	return ((double)min + ((double)rand() / ((double)RAND_MAX + 0.001) * ((double)max - (double)min + 1.0)));
}

/*
	NOM	:			afficherTableauEntier
	DEF :			Fonction qui permet d'afficher un tableau de
	PARAMETRES :	tableau[] : le tableau à afficher
					nbElements : le nombre d'élément du tableau reçu.
	RETOUR :		Aucun
*/
void afficherTableauEntier(int tableau[], int nbElements) {

	int i; 

	for (i = 0; i < nbElements; i++) {

		printf("Element %d = %d \n", i, tableau[i]);
	}
	printf("\n");  
}

/*
	NOM :			afficherTableauReel
	DEF :			Fonction qui permet d'afficher un tableau de
	PARAMETRES :	tableau[] : le tableau à afficher
	nbElements :	le nombre d'élément du tableau reçu.
	RETOUR :		Aucun
*/
void afficherTableauReel(double tableau[], int nbElements) {

	int i;

	for (i = 0; i < nbElements; i++) {

		printf("Element %d = %lf \n", i, tableau[i]);
	}
	printf("\n");
}

/*
	NOM	:			incrementerTableauEntier
	DEF :			Fonction qui permet d'incrémenter d'une valeur tous les
					éléments du tableau
	PARAMETRES :	tableau[] : le tableau à incrémenter
					nbElements : le nombre d'élément du tableau reçu.
					incrément : la veleur d'incrément des éléments
	RETOUR :		Aucun
*/
void incrementerTableauEntier(int tableau[], int nbElements, int increment) {

	int i;

	for (i = 0; i < nbElements; i++) {

		tableau[i] = tableau[i] + increment;
	}
}

/*
	NOM	:			initTableauEntier
	DEF :			Fonction qui permet d'initialiser les éléments d'un tableau à une valeur statique
	PARAMETRES :	tableau[] : le tableau à initilaiser
					nbElements : le nombre d'élément du tableau reçu.
					valeur : la valeur d'initialisation.
	RETOUR :		Aucun
*/
void initTableauEntier(int tableau[], int nbElements, int valeur) {
	
	int i;

	for (i = 0; i < nbElements; i++) {

		tableau[i] = valeur;
	}
}

/*
	NOM	:			compterValeurPair
	DEF :			Fonction qui permet de compter le nombre de valeur pair dans un tableau
	PARAMETRES :	tableau[] : le tableau à initilaiser
					nbElements : le nombre d'élément du tableau reçu.
	RETOUR :		Aucun
*/
int compterValeurPair(int tableau[], int nbElements) {

	int i;
	int compteur = 0;

	for (i = 0; i < nbElements; i++) {

		if (tableau[i] % 2 == 0) {
			compteur = compteur + 1;
		}
	}
	return compteur;
}

/*
	NOM	:			initTableauAlea
	DEF :			Fonction qui permet d'initialiser les éléments d'un tableau avec des valeurs aléatoire
	PARAMETRES :	tableau[] : le tableau à initilaiser
					nbElements : le nombre d'élément du tableau reçu.
					valeur : la valeur d'initialisation.
	RETOUR :		Aucun
*/
void initTableauAleaReel(double tableau[], int nbElements, double min, double max) {

	int i;

	for (i = 0; i < nbElements; i++) {

		tableau[i] = reelAleatoire(min, max);
	}
}

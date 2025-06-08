/*****************************************************************************************
	Par        : David Beaulieu
	Revise le  : H2025
	Fichier    : algoFouille.c
	Objectifs  : Démonstration des algorithme de fouille
	Note	   :

	NOTE DE L'ENSEIGNANT : Les commentaires de ce module sont des explications, ils ne
						   représentent pas vraiment ce qui est attendu de vous lors
						   de la remise de vos travaux pratiques.

/****************************************************************************************
*                            AJOUT DES MODULES ET LIBRAIRIES                            *
****************************************************************************************/
#include <stdlib.h>		/* Librairie Standart */
#include <stdio.h>		/* Librairie Entrer - Sortie */
#include <time.h>	    /* Module utile pour la fonction time() */

/****************************************************************************************
*                               DÉFINITION DES CONSTANTES                               *
****************************************************************************************/
// Valeur retourné quand une valeur n'est pas trouvé lors de la fouille
#define ELEMENT_NON_TROUVER -1

// Nombre d'élément des tableaux 1D à trier
#define NB_ELEMENT 10

// Intervalle des valeurs contenues dans les tableaux
#define VALEUR_MIN 1
#define VALEUR_MAX 1100
/****************************************************************************************
*								DÉCLARATION DES FONCTIONS								*
****************************************************************************************/
/*
	fouille Sequentielle
	Effectue une recherche séquentiel d'une valeur spécifique dans un tableau d'entier 1D
	PARAMETRES :	tableau : Le tableau ou l'on fait la fouille
					taille : La taille du tableau ou l'on fait la fouille
					element : L'élément (la valeur) rechercher dans le tableau
	RETOUR :		L'indice du tableau ou se trouve la première valeur chercher dans le tableau, -1 si la valeur n'est pas trouvé
	SPÉCIFICATION : Aucune
*/
long fouilleSequentielle(int tableau[], long taille, int element);

/*
	fouille Binaire
	Effectue une recherche binaire d'une valeur spécifique dans un tableau d'entier 1D
	PARAMETRES :	tableau : Le tableau ou l'on fait la fouille
					taille : La taille du tableau ou l'on fait la fouille
					element : L'élément (la valeur) rechercher dans le tableau
	RETOUR :		L'indice du tableau ou se trouve la première valeur chercher dans le tableau, -1 si la valeur n'est pas trouvé
	SPÉCIFICATION : Aucune
*/
long fouilleBinaire(int tableau[], long taille, int element);

/*
	remplirTableauAlea
	DEF : Initialise les valeurs d'une tableau 1D d'entier avec des nombres aléatoires
	PARAMETRES :    tableau[] : Le tableau à initialiser
					nbElement : La taille du tableau à initialiser
					min : La valeur minimum des valeurs aléatoires générées
					max : La valeur maximum des valeurs aléatoires générées
	RETOUR :        Aucun
	SPÉCIFICATION : Le générateur aléatoire doit être initialisé
*/
void remplirTableauAlea(int tableau[], long nbElement, int min, int max);

/*
	afficher tableau
	DEF : Affiche les valeurs d'un tableau 1D d'entier dans la console
	PARAMETRES :    tab[] : Le tableau à afficher
					nbElement : Le nombre d'élément du tableau
	RETOUR :        Aucun
	SPÉCIFICATION : Aucune
*/
void afficherTableau(int tab [], long nbElement);

/*
	tri Selection
	DEF : Tri un tableau 1D d'entier avec l'algorithme du tri par sélection
	PARAMETRES :    tableau[] : Le tableau à trier
					taille : La taille du tableau à trier
	RETOUR :        Aucun
	SPÉCIFICATION : Aucune
*/
void triSelection(int tableau[], long taille);

/*
	permuter entier
	Fonction qui recoit deux référence d'entier et en permute le contenue
	PARAMETRES :	entierA, référence du premier entier à permuter
					entierA, référence du premier entier à permuter
	RETOUR :		Aucun
	SPÉCIFICATION : Aucune
*/
void permuterEntier(int * entierA, int * entierB);

/*
	entier alea
	Fonction qui retourne un entier aleatoire dans un intervalle donné.
	PARAMETRES :	min, valeur minimum de l'intervalle
					max, valeur maximum de l'intervalle
	RETOUR :		un entier aléatoire
	SPÉCIFICATION : Aucune
*/
int entierAlea (int min, int max);

/****************************************************************************************
*                           DÉFINITION DU PROGRAMME PRINCIPALE                          *
****************************************************************************************/
int main(void) {

	srand(time(NULL));	                		// Initialisation du générateur aléatoire
	setbuf(stdout, 0);        // Permet d'afficher les printfs en mode débug avec Clion

	int tableauTest[NB_ELEMENT];        		// Tableau qui servira de test au tri
	long indiceRetour;							// Indice ou se trouve l'élément dans le tableau
    int valeurRechercher = VALEUR_MAX + 1;		// Valeur que l'on veut rechercher dans le tableau

	//*** Préparation pour la fouille Séquentielle ***

	// Initialise le tableau avec des valeur aléatoire
	remplirTableauAlea(tableauTest,NB_ELEMENT,VALEUR_MIN,VALEUR_MAX);

	// Place la valeur rechercher dans le tableau à une position aléatoire
	tableauTest[entierAlea(0,NB_ELEMENT - 1)] = valeurRechercher;

    // Affiche le tableau non trié
	afficherTableau(tableauTest,NB_ELEMENT);

	printf("Le resultat de la recherche sequentielle = %li\n\n",fouilleSequentielle(tableauTest,NB_ELEMENT, valeurRechercher));

    //*** Préparation pour la fouille Binaire ***

	// Initialise le tableau avec des valeur aléatoire
	remplirTableauAlea(tableauTest,NB_ELEMENT,VALEUR_MIN,VALEUR_MAX);

	// Place la valeur rechercher dans le tableau à une position aléatoire
	tableauTest[entierAlea(0,NB_ELEMENT - 1)] = valeurRechercher;

	// Affiche le tableau non trié
	afficherTableau(tableauTest,NB_ELEMENT);

	printf("Le resultat de la recherche sequentiel = %li\n\n",fouilleBinaire(tableauTest,NB_ELEMENT, valeurRechercher));



	return EXIT_SUCCESS;
}


/****************************************************************************************
*                               DÉFINITION DES FONCTIONS                                *
****************************************************************************************/

/*
	fouille Sequentielle
	Effectue une recherche séquentiel d'une valeur spécifique dans un tableau d'entier 1D
	PARAMETRES :	tableau : Le tableau ou l'on fait la fouille
					taille : La taille du tableau ou l'on fait la fouille
					element : L'élément (la valeur) rechercher dans le tableau
	RETOUR :		L'indice du tableau ou se trouve la première valeur chercher dans le tableau, -1 si la valeur n'est pas trouvé
	SPÉCIFICATION : Aucune
*/
long fouilleSequentielle(int tableau[], long taille, int element) {

  	long i;		// Itératieur qui parcours le tableau

    // Parcours tout les éléments du tableau
	for (i = 0; i < taille; i++) {

        // Si on trouve l'élément, la fonction retourne l'indice courant
		if (tableau[i] == element) {
			return i;
		}
	}
    // Si la boucle se complète, ceci indique que l'élément n'est pas dans le tableau
	return ELEMENT_NON_TROUVER;
}

/*
	fouille Binaire
	Effectue une recherche binaire d'une valeur spécifique dans un tableau d'entier 1D
	PARAMETRES :	tableau : Le tableau ou l'on fait la fouille
					taille : La taille du tableau ou l'on fait la fouille
					element : L'élément (la valeur) rechercher dans le tableau
	RETOUR :		L'indice du tableau ou se trouve la première valeur chercher dans le tableau, -1 si la valeur n'est pas trouvé
	SPÉCIFICATION : Aucune
*/
long fouilleBinaire(int tableau[], long taille, int element){

	long debut = 0;					// Indice du début de la zone de recherche
	long fin = taille - 1;			// Indice de la fin de la zone de recherche
	long milieu;					// Indice du milieu de la zone de recherche

    // Tanque l'indice de début ne s'inverse pas avec l'indice de la fin
	while (debut <= fin) {

        // Place le milieu en fonction de la zone de recherche
		milieu = (debut + fin) / 2;

        // Si l'élément recherché est au milieu de la zone, on retourne cet indice
		if (tableau[milieu] == element) {

			return milieu;
		}
        // Si l'élément est plus grand que la valeur du point milieu on ajuste l'indice de début de la zone
		else if (tableau[milieu] < element) {

			debut = milieu + 1;
		}
		// Sinon l'élément est plus petie que la valeur du point milieu on ajuste l'indice de fin de la zone
		else {

			fin = milieu - 1;
		}
	}

	// Si la boucle se complète, ceci indique que l'élément n'est pas dans le tableau
	return ELEMENT_NON_TROUVER; 
}

/****************************************************************************************
/									DEFINITION DES FONCTIONS							*
****************************************************************************************/
/*
	remplirTableauAlea
	DEF : Initialise les valeurs d'une tableau 1D d'entier avec des nombres aléatoires
	PARAMETRES :    tableau[] : Le tableau à initialiser
					nbElement : La taille du tableau à initialiser
					min : La valeur minimum des valeurs aléatoires générées
					max : La valeur maximum des valeurs aléatoires générées
	RETOUR :        Aucun
	SPÉCIFICATION : Le générateur aléatoire doit être initialisé
*/
void remplirTableauAlea(int tableau[], long nbElement, int min, int max) {

	long i;                                   // Itérateur des éléments du tableau
	for (i = 0; i < nbElement; i++) {
		tableau[i] = entierAlea(min, max);    // Pour chaque case du tableau on attribut la valeur aléatpoire
	}
}

/*
	afficher tableau
	DEF : Affiche les valeurs d'un tableau 1D d'entier dans la console
	PARAMETRES :    tab[] : Le tableau à afficher
					nbElement : Le nombre d'élément du tableau
	RETOUR :        Aucun
	SPÉCIFICATION : Aucun
*/
void afficherTableau(int tab [], long nbElement){

	long i;    // Itérateur des éléments du tableau

	for (i = 0; i < nbElement; ++i){
		printf("%i\t", tab[i]);
	}
	printf("\n");
}

/*
	permuter entier
	Fonction qui recoit deux référence d'entier et en permute le contenue
	PARAMETRES :	entierA : référence du premier entier à permuter
					entierA : référence du premier entier à permuter
	RETOUR :		Aucun
	SPÉCIFICATION : Aucune
*/
void permuterEntier(int * entierA, int * entierB){

	int tempo;     // Variable temporaire utile à la permutation

	// Effectue la permutation des contenues pointé par les références
	tempo = *entierA;
	*entierA = *entierB;
	*entierB = tempo;
}

/*
	entier alea
	DEF : Fonction qui retourne un entier aleatoire dans un intervalle donné.
	PARAMETRES :	min : valeur minimum de l'intervalle
					max : valeur maximum de l'intervalle
	RETOUR :		un entier aléatoire
	SPÉCIFICATION :
*/
int entierAlea (int min, int max)
{
	return min + (int)(rand() / (RAND_MAX + 0.005) * (max - min + 1));
}

/*
	tri Selection
	DEF : Tri un tableau 1D d'entier avec l'algorithme du tri par sélection
	PARAMETRES :    tableau[] : Le tableau à trier
					taille : La taille du tableau à trier
	RETOUR :        Aucun
	SPÉCIFICATION : Aucune
*/
void triSelection(int tableau[], long taille) {

	long i;
	long j;
	long positionMin;

	// Parcours les éléments du tableau
	for (i = 0; i < taille - 1; i++) {

		// Initialise la valeur min avec l’élément courant
		positionMin = i;

		// Cherche le minimum dans le segment supérieur du tableau non trié
		for (j = i + 1; j < taille; j++) {

			// Si une valeur plus petit est trouvée on la remplace
			if (tableau[j] < tableau[positionMin]) {
				positionMin = j;
			}
		}

		// Permute la valeur min trouvée avec l’élément courant
		permuterEntier(&tableau[i],&tableau[positionMin]);
	}
}

/*****************************************************************************
	Par        : David Beaulieu
	Revise le  : 
	Fichier    : diviseurPremier.c
	Objectifs  : Tester si un entier positif N est premier.
				 Compter le nombre de diviseurs premiers d'un entier N.
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
#define TEST 5		// Valeur test de la fonction

#define VRAI 1		// Indique si le nombre est premier
#define FAUX 0		// Indique que le nombre n'est pas premier

/****************************************************************************************
*								DÉCLARATION DES FONCTIONS								*
****************************************************************************************/
/*
	EST PREMIER
	DEF : 			Fonction qui retourne vrais si le nombre est premier faux sinon.
	PARAMETRES :	Nombre à tester.
	RETOUR : 		VRAI si le nombre est premier, FAUX sinon (TYPE: int)
	SPÉCIFICATION : Valeur positive seulement.
*/
int estPremier (int);

/*
	AFFICHE DIV PREMIER
	DEF : 			Fonction qui affiche tous les nombre premier d'un interval.
	PARAMETRES :	- Borne inférieur de l'interval (TYPE : int)
					- Borne supérieur de l'interval (TYPE : int)
	RETOUR : 		Aucun
	SPÉCIFICATION : Les borne ne doivent pas être inversé.
*/
void afficheDivPremier (int, int);

/****************************************************************************************
*                           DÉFINITION DU PROGRAMME PRINCIPALE                          *
****************************************************************************************/
int main(void)
{

	int inferieur = 0;
	int superieur = 0;

	setbuf(stdout, 0);        // Permet d'afficher les printfs en mode débug avec Clion
	// Appel de fonction avec une constante comme paramètre
	// On teste la fonction est premier
	if(estPremier(TEST) == VRAI)
		printf("\n\nLa valeur de %i est premier\n\n",TEST);
	else
		printf("\n\nLa valeur de %i n'est pas premier\n\n",TEST);



	system("pause");	  /*Ajoute une pause � la fenetre console */

	/* NDE :  Appel de fonction avec des valeurs aquis au clavier  comme param�tre */
	/* NDE :  On teste la fonction est premier */
	printf("\n\nEntrez une borne inferieur : ");
	scanf("%i",&inferieur);
	
	printf("\nEntrez une borne superieur : ");
	scanf("%i",&superieur);
	
	
	printf("\n Les nombres premier sont : ");
	afficheDivPremier(inferieur,superieur);
	
	system("pause");	  /*Ajoute une pause � la fenetre console */
	return EXIT_SUCCESS;  /*Permet de terminer le programme proprement*/
}

/****************************************************************************************
/									DEFINITION DES FONCTIONS							*
****************************************************************************************/

/*
	EST PREMIER
	DEF : 			Fonction qui retourne vrais si le nombre est premier faux sinon.
	PARAMETRES :	Nombre à tester.
	RETOUR : 		VRAI si le nombre est premier, FAUX sinon (TYPE: int)
	SPÉCIFICATION : Valeur positive seulement.
*/
int estPremier (int valeur)
{
	int nb_diviseur = 0;
	int i;

	// Itère sur tous les diviseurs du nombre */
	for (i = 1; i <= valeur; ++i)
	{	
		// i est est un diviseur propre
		if (valeur % i == 0)
		{
			nb_diviseur = nb_diviseur + 1;		// On compte un nouveau diviseur
		}
	}

	if (nb_diviseur == 2){
		return VRAI;			// Le nombre est premier
    }
	else{
		return FAUX;			// Le nombre n'est pas premier
	}
}

/*
	AFFICHE DIV PREMIER
	DEF : 			Fonction qui affiche tous les nombre premier d'un interval.
	PARAMETRES :	- Borne inférieur de l'interval (TYPE : int)
					- Borne supérieur de l'interval (TYPE : int)
	RETOUR : 		Aucun
	SPÉCIFICATION : Les borne ne doivent pas être inversé.
*/
void afficheDivPremier (int borne_inf ,int borne_sup)
{
	int i ;
	// Teste toutes les valeurs de l'intervalle
	for(i = borne_inf; i <= borne_sup; ++i){
		if(estPremier(i) == VRAI){
			printf("%i ",i); 		// Affiche le nombre s'il est premier
		}
	}
	printf("\n");
}
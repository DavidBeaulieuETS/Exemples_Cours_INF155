/*****************************************************************************************
	Par        : David Beaulieu
	Revise le  : 
	Fichier    : factorielleVersion2.c
	Objectifs  : Faire une démonstration de fonction et de passage par valeur
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

/****************************************************************************************
*								DÉCLARATION DES FONCTIONS								*
****************************************************************************************/
/*
	FACTORIELLE 
	DEF : Fonction qui calcul le factorielle d'un nombre.
	PARAMETRES :	- Valeur que l'on veut calculer ls factorielle (TYPE: int)
	RETOUR : resultat (TYPE: unsigned long int)
*/
unsigned long int factorielle (int facto);

/****************************************************************************************
*                           DÉFINITION DU PROGRAMME PRINCIPALE                          *
****************************************************************************************/
int main(void)
{
	int i;
	int valeurDebut = 0;
	int valeurFin = 0;
	unsigned long int resultat = 0;

	// Acquisation des valeurs
	printf("Determiner la plage de valeurs de calcul du factorielle \n");
	printf("Entrez la premiere valeur de la plage  : ");
	scanf("%i",&valeurDebut);

	printf("\nEntrez la derniere valeur de la plage  : ");
	scanf("%i",&valeurFin);

    // Parcours de la plage de valeur de calcul
	for (i = valeurDebut; i <= valeurFin; i++){
		resultat = factorielle (i);											// Appel de la fonction avec une variable
        printf("\nLa valeur du factorielle de %i est : %lu",i,resultat);	// Affichage du résultat courant
    }

	printf("\n");
	system("pause");	  		        // Ajoute une pause à la fenêtre console
	return EXIT_SUCCESS;  		        // Permet de terminer le programme proprement
}

/****************************************************************************************
/									DEFINITION DES FONCTIONS							*
****************************************************************************************/

/*
	FACTORIELLE 
	DEF : Fonction qui calcul le factorielle d'un nombre.
	PARAMETRES :	- Valeur que l'on veut calculer ls factorielle (TYPE: int)
	RETOUR : resultat (TYPE: int)
*/
unsigned long int factorielle (int facto)
{
	unsigned long int resultat = 1;

	while (facto > 0)
	{
		resultat = resultat * facto;
		facto = facto - 1;
	}
	
	return resultat;
}
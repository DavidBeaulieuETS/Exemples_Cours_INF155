/*****************************************************************************************
	Par        : David Beaulieu
	Revise le  : H2025
	Fichier    : passValeurVsRef.c
	Objectifs  : Ce programme teste les parametres dans une fonction.
	Note	   :
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
	PASSAGE VALEUR
	DEF : 			Cette fonction additionne 1 au parametre formel nb1.
					Elle sert a presenter le passage par valeur - copie.
	PARAMETRES : 	nb1 : Le parametre formel a incrementer.
	RETOUR : Aucun
*/
void passageValeur(int nb1);

/*
	PASSAGE REFERENCE
	DEF : 			Cette fonction additionne 1 au parametre formel nb1.
					Elle sert a presenter le passage par référence - pointeur.
	PARAMETRES : 	nb1 : Le parametre formel a incrementer.
	RETOUR : Aucun
*/
void passageReference(int * nb1);

/****************************************************************************************
*                           DÉFINITION DU PROGRAMME PRINCIPALE                          *
****************************************************************************************/
int main(void)
{
	int nb1 = 10;

	printf("Ce programme verifie si on peut modifier les parametres.\n");

	/*	On affiche la valeur de nb1 avant et apres l'appel afin de bien
		voir que l'appel n'a pas modifie le contenu de la variable nb1.		*/
	printf("** Test avec un passage par valeur **\n");
	printf("Valeur de nb1 : %i\n", nb1);
	passageValeur(nb1);
	printf("Valeur de nb1 : %i\n\n", nb1);

	/*		 Une variable est toujours passee par COPIE (valeur).			*/
	/*		 A moins de passer l'adresse (comme dans scanf), on ne peut		*/
	/*		 jamais modifier une variable dans une fonction	en la passant	*/
	/*		 en parametre.													*/

	printf("** Test avec un passage par reference **\n");
	printf("Valeur de nb1 : %i\n", nb1);
	passageReference(&nb1);
	printf("Valeur de nb1 : %i\n\n", nb1);

	return EXIT_SUCCESS;  		        // Permet de terminer le programme proprement
}

/****************************************************************************************
/									DEFINITION DES FONCTIONS							*
****************************************************************************************/
/*
	PASSAGE VALEUR
	DEF : 			Cette fonction additionne 1 au parametre formel nb1.
					Elle sert a presenter le passage par valeur - copie.
	PARAMETRES : 	nb1 : Le parametre formel a incrementer.
	RETOUR : Aucun
*/
void passageValeur(int nb1){
  nb1++;
}

/*
	PASSAGE REFERENCE
	DEF : 			Cette fonction additionne 1 au parametre formel nb1.
					Elle sert a presenter le passage par référence - pointeur.
	PARAMETRES : 	nb1 : Le parametre formel a incrementer.
	RETOUR : Aucun
*/
void passageReference(int * nb1){
  (*nb1)++;     // ou bien cette ligne *nb1 = *nb1 + 1;
}
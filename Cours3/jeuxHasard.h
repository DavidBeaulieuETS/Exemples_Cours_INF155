/*****************************************************************************************
	Par        : David Beaulieu
	Revise le  : H2025
	Fichier    : jeuxHasard.h
	Objectifs  : Ce module propose des fonctions de jeux de hasard.
					- Une fonction pour simuler un jeu de pile ou face avec l'ordinateur.
					- Une fonction pour jouer au dé avec l'ordinateur.
					- Une fonction pour simuler un jeux de roche/papier/siceaux.
	Note	   : Ce module sert de démonstration aux module et aux fonction aléatoire.
*****************************************************************************/


/****************************************************************************************
*                            AJOUT DES MODULES ET LIBRAIRIES                            *
****************************************************************************************/
#include <stdlib.h>		// Librairie Standard
#include <stdio.h>		// Librairie Entrer - Sortie

/****************************************************************************************
*                               DÉFINITION DES CONSTANTES                               *
****************************************************************************************/
#define QUITTER		0
#define CHOIX_PF	1
#define CHOIX_DE	2
#define CHOIX_RPC	3

/****************************************************************************************
*							DÉFINITION DES FONCTIONS PUBLIQUES							*
****************************************************************************************/
/*
	AFFICHER MENU
	Fonction qui affiche le menu de présentation des jeux de hasard.
	PARAMETRES : Aucun
	RETOUR : Aucun
	SPÉCIFICATION : Efface l'écran précédent.
*/
void afficherMenu(void);

/*
	AQUISITION CLAVIER
	Fonction qui demande un entier au clavier. La fonction redemande la valeur tant 
	quelle n'est pas comprise dans une intervalle donnée.
	PARAMETRES :	- min : valeur minimum de l'intervalle (TYPE: int)
					- max : valeur maximum de l'intervalle (TYPE: int)
	RETOUR :		- Une valeur aquisitione au clavier comprise dans l'interval. (TYPE: int)
	SPÉCIFICATION : Il n'y a pas d'autre façon de sortir de la fonction que d'entrez une valeur correcte.
*/
int aquisitionClavier(int min, int max);

/*
	LANCER PILE FACE
	Permet de simuler un jeu de pile ou face avec l'ordinateur. On choisi soit le coté
	pile ou le coté face et la fonction simule le lancer. Elle nous informe si on est gagnant
	ou bien perdant.
	PARAMETRES : Aucun
	RETOUR : Aucun
	SPÉCIFICATION :
*/
void lancerPileFace(void);

/*
	LANCER DÉ
	Permet de simuler une partie de dé avec l'ordinateur. Deux dé à six face sont
	lancé et c'est le plus haut des deux qui gagne, une égalité donne une partie null.
	PARAMETRES : Aucun
	RETOUR : Aucun
	SPÉCIFICATION :
*/
void lancerDe(void);

/*
	JEUX ROCHE PAPIER CISEAU
	Permet de simuler un jeux de roche papier ciseau avec l'ordinateur. L'utilisateur choisi
	un des trois artéfacte et la fonction en sélectionne un aléatoirement.
	PARAMETRES : Aucun
	RETOUR : Aucun
	SPÉCIFICATION :
*/
void jeuxRochePapierCiseau(void);

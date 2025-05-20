/*****************************************************************************************
	Par        : David Beaulieu
	Revise le  : H2025
	Fichier    : jeuxHasard.c
	Objectifs  : Ce module propose des fonctions de jeux de hasard.
					- Une fonction pour simuler un jeu de pile ou face avec l'ordinateur.
					- Une fonction pour jouer au dé avec l'ordinateur.
					- Une fonction pour simuler un jeux de roche/papier/ciseau.
	Note	   : Ce module sert de démonstration aux module et aux fonction al�atoire.

	NOTE DE L'ENSEIGNANT : Les commentaires de ce module sont des explications, ils ne
						   représentent pas vraiment ce qui est attendu de vous lors
						   de la remise de vos travaux pratiques.

*****************************************************************************************/


/****************************************************************************************
*                            AJOUT DES MODULES ET LIBRAIRIES                            *
****************************************************************************************/
#include <stdlib.h>				// Librairie Standard
#include <stdio.h>				// Librairie Entrer - Sortie
#include "jeuxHasard.h"			// Il faut inclure le .h associer au point .c*

/****************************************************************************************
*                               DÉFINITION DES CONSTANTES                               *
****************************************************************************************/
/* Constantes du Pile ou Face */ 
#define PILE 1
#define FACE 2

/* Constante du jeux de dé */
#define NB_FACE 6

/* Constante du jeux Roche, Papier, Ciseau */
#define ROCHE 1
#define PAPIER 2
#define CISEAU 3



/****************************************************************************************
*							DÉCLARATION DES FONCTIONS PRIVÉES							*
****************************************************************************************/
/*
	ENTIER ALEA
	Fonction qui retourne un entier aleatoire dans un intervalle donné.

	PARAMETRES :	- min, valeur minimum de l'intervalle (TYPE: int)
					- max, valeur maximum de l'intervalle (TYPE: int)
	RETOUR :		- un entier aléatoire (TYPE: int)
	SPÉCIFICATION :
*/
static int entierAlea (int min, int max);


/****************************************************************************************
*							DÉFINITION DES FONCTIONS PUBLIQUE							*
****************************************************************************************/
/*
	AFFICHER MENU
	Fonction qui affiche le menu de présentation des jeux de hasard.
	PARAMETRES : Aucun
	RETOUR : Aucun
	SPÉCIFICATION : Efface l'écran précédent.
*/
void afficherMenu(void)
{
	system("cls");		/* Commande de nettoyage de la console */
	
	printf("*************************************\n");
	printf("*			JEUX DE HASARD\n");
	printf("*************************************\n");
	printf("*\n");
	printf("* 1 - Jeux de Piles ou Faces.\n");
	printf("* 2 - Jeux de de a n face.\n");
	printf("* 3 - Roche papier ciseau.\n");
	printf("* 0 - Quitter.\n");
	printf("*\n");
	printf("* Entrez votre choix : ");
}

/*
	AQUISITION CLAVIER
	Fonction qui demande un entier au clavier. La fonction redemande la valeur tant 
	quelle n'est pas comprise dans une intervalle donnée.
	PARAMETRES :	- min : valeur minimum de l'intervalle (TYPE: int)
					- max : valeur maximum de l'intervalle (TYPE: int)
	RETOUR :		- Une valeur aquisitioné au clavier comprise dans l'interval. (TYPE: int)
	SPÉCIFICATION : Il n'y a pas d'autre façon de sortir de la fonction que d'entrez une valeur correcte.
*/
int aquisitionClavier(int min, int max)
{
	int choix;
	do
	{	
		scanf("%i",&choix);
		if(choix > max || choix < min)
		{
			printf("Votre choix est invalide !!\n");
			printf("Entrez un nouveau choix : ");
		}
	}while(choix > max || choix < min);		/* Continue tant que le choix n'est pas valide*/
	
	return choix;
}

/*
	LANCER PILE FACE
	Permet de simuler un jeu de pile ou face avec l'ordinateur. On choisi soit le coté 
	pile ou le coté face et la fonction simule le lancer. Elle nous informe si on est gagnant
	ou bien perdant.
	PARAMETRES : Aucun
	RETOUR : Aucun
	SPÉCIFICATION : 
*/
void lancerPileFace(void)
{
	int choix = 0;
	int choixOrdi = 0;

	printf("Entrez votre choix?\n 1 : PILE\n 2 : FACE\n ");
	
	/* Choix de l'utilisateur */
	choix = aquisitionClavier(PILE,FACE);
	/* Simulation du lancé */
	choixOrdi = entierAlea(PILE,FACE);
	
	/* Comparaison des résultats */
	if(choix == choixOrdi)
		printf("\nBRAVO vous avez juste!!!\n\n");
	else
		printf("\nVous n'avez pas fait le bon choix!!\n\n");
}

/*
	LANCER DÉ
	Permet de simuler une partie de dé avec l'ordinateur. Deux dé a six face sont 
	lancé et c'est le plus haut des deux qui gagne, une égalité donne une partie null. 
	PARAMETRES : Aucun
	RETOUR : Aucun
	SPÉCIFICATION :
*/
void lancerDe(void)
{
	int de;
	int deOrdi;

	/* Simulation du lancer des deux dé */
	de = entierAlea(1,NB_FACE);
	deOrdi = entierAlea(1,NB_FACE);

	/* Comparaison des résultats */
	if(de > deOrdi)
	{
		printf("\nVous avez remporter le match!\n");
	}
	else if(de < deOrdi)
	{
		printf("\nVous avez perdu le match!\n");
	}
	else
	{
		printf("Match null!!\n");
	}
	/* Affichage des résultats */
	printf("Votre D : %i\n",de);
	printf("Le D ordi : %i\n\n",deOrdi);

}

/*
	JEUX ROCHE PAPIER CISEAU
	Permet de simuler un jeux de roche papier ciseau avec l'ordinateur. L'utilisateur choisi
	un des trois artéfacte et la fonction en sélectionne un aléatoirement. 
	PARAMETRES : Aucun
	RETOUR : Aucun
	SPÉCIFICATION :
*/
void jeuxRochePapierCiseau(void)
{
	int choix;
	int choixOrdi;
	/* Choix de l'utilisateur */
	printf("\nEntrez un choix : \n1 : ROCHE\n2 : PAPIER\n3 : CISEAU\n");
	choix = aquisitionClavier(ROCHE,CISEAU);
	/* Choix de l'ordinateur */
	choixOrdi = entierAlea(ROCHE,CISEAU);
	
	/* Cas ou l'utilisateur remporte sur l'ordinateur */
	if(choix == ROCHE && choixOrdi == CISEAU)
	{
		printf("\nVous remportez le match!!\n");
		printf("Vous : ROCHE\nOrdinateur : CISEAU\n\n");
	}
	else if (choix == PAPIER && choixOrdi == ROCHE)
	{
		printf("\nVous remportez le match!!\n");
		printf("Vous : PAPIER\nOrdinateur : ROCHE\n\n");
	}
	else if (choix == CISEAU && choixOrdi == PAPIER)
	{
		printf("\nVous remportez le match!!\n");
		printf("Vous : SICEAU\nOrdinateur : PAPIER\n\n");
	}
	/*Cas ou l'ordinateur remporte la partie */
	else if (choixOrdi == ROCHE && choix == CISEAU)
	{
		printf("\nL'ordinateur a remporter le match!!\n");
		printf("Vous : CISEAU\nOrdinateur : ROCHE\n\n");
	}
	else if (choixOrdi == PAPIER && choix == ROCHE)
	{
		printf("\nL'ordinateur a remporter le match!!\n");
		printf("Vous : ROCHE\nOrdinateur : PAPIER\n\n");
	}
	else if (choixOrdi == CISEAU && choix == PAPIER)
	{
		printf("\nL'ordinateur a remporter le match!!\n");
		printf("Vous : PAPIER\nOrdinateur : CISEAU\n\n");
	}
	else
	{
		printf("\nMatch Null!!\n");
	}
	
}


/****************************************************************************************
*							DÉFINITION DES FONCTIONS PRIVÉE								*
****************************************************************************************/
/*
	ENTIER ALEA
	Fonction qui retourne un entier aleatoire dans un intervalle donné.

	PARAMETRES :	- min, valeur minimum de l'intervalle (TYPE: int)
					- max, valeur maximum de l'intervalle (TYPE: int)
	RETOUR :		- un entier aléatoire (TYPE: int)
	SPÉCIFICATION : 
*/
static int entierAlea (int min, int max)
{
	return min + (int)(rand() / (RAND_MAX + 0.005) * (max - min + 1));
}
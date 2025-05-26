/*****************************************************************************
	Par        : David Beaulieu
	Revise le  : H2025
	Fichier    : inclinaisonFonction.c
	Objectifs  :
    Note	   :
*****************************************************************************************/

/****************************************************************************************
*                            AJOUT DES MODULES ET LIBRAIRIES                            *
****************************************************************************************/
#include <stdlib.h>		// Librairie Standard
#include <stdio.h>		// Librairie Entrer - Sortie
#include <math.h>		// Ajout de la librairie mathématique

/****************************************************************************************
*                               DÉFINITION DES CONSTANTES                               *
****************************************************************************************/
/* Constante pour l'inclinaison d’une rampe d'accès */
#define LIM_SEC 15			// Valeur limite d'angle de la zone sécurisé
#define LIM_OPE 25			// Valeur limite d'angle de la zone opérationnelle
#define LIM_SUR 55			// Valeur limite d'angle de la zone de surveillance
#define MAX_ANGLE 180		// Valeur maximale de l'angle

/****************************************************************************************
*                               DÉCLARATION DES FONCTIONS"                               *
****************************************************************************************/
/*
	NOM	: analyse Pente
	DEF : Affiche un rapport sur l'analyse de la pente selon la longueur et hauteur de celle ci
	PARAMETRES :		hauteur (double)
						longueur (double)
	RETOUR :			Aucun
	SPÉCIFICATION :		La longueur doit être strictement positive et plus grand zéro
*/

void analysePente (double hauteur, double longueur);

/*
	NOM	: analyse Pente Avec Angle
	DEF : Affiche un rapport sur l'analyse de la pente selon la longueur et hauteur de celle ci
			ET on retourne la valeur de l'angle de la pente
	PARAMETRES :		hauteur (double)
						longueur (double)
	RETOUR :			l'angle de la pente (double)
	SPÉCIFICATION :		La longueur doit être strictement positive et plus grand zéro
*/
double analysePenteAvecAngle (double hauteur, double longueur);

/* Fonction de test */
void testAnalysePenteAvecAngle(void);

/****************************************************************************************
*                           DÉFINITION DU PROGRAMME PRINCIPALE                          *
****************************************************************************************/

int main(void) {

	setbuf(stdout, 0);		    // Permets d'afficher les printf en mode débug avec Clion

	double l = 0.0;
	double inclinaison = 0;
#if 0

	//Test des longueurs de pente de 5 à 35 m pour un pas de 5 m avec un hauteur fixe de 5m
	for (l = 5; l <= 35; l += 5) {
		analysePente(5,l);
	}
	printf("\n\n** Test avec retour** \n");
	inclinaison = analysePenteAvecAngle(20,33);
	printf("\navec une inclinaison de : %lf\n",inclinaison);
#endif

	// lancer la fonction de test unitaire
	testAnalysePenteAvecAngle();


	return EXIT_SUCCESS;  		        // Permet de terminer le programme proprement
}


/****************************************************************************************
/									DEFINITION DES FONCTIONS							*
****************************************************************************************/
/*
	NOM	: analyse Pente
	DEF : Affiche un rapport sur l'analyse de la pente selon la longueur et hauteur de celle ci
	PARAMETRES :		hauteur (double)
						longueur (double)
	RETOUR :			Aucun
	SPÉCIFICATION :		La longueur doit être strictement positive et plus grand zéro
*/
void analysePente (double hauteur, double longueur) {

	double angle;

	// Valide si la longueur saisie est plus grande que zéro
	if (longueur > 0) {

		// Calcul de l'angle
		angle = atan(hauteur / longueur) * MAX_ANGLE / M_PI;

		// Analyse de l'angle
		if (angle < 0 || angle > MAX_ANGLE) {
			printf("Erreur : L'angle doit etre compris entre 0 et 180 degres \n");
		}
		else if (angle < LIM_SEC) {
			printf("Zone securisee : Fonctionnement normal \n");
		}
		else if (angle < LIM_OPE) {
			printf("Zone operationnelle : Fonctionnement correct \n");
		}
		else if (angle < LIM_SUR) {
			printf("Zone de surveillance : attention a l'effort mecanique \n");
		}
		else {
			printf("Zone critique : Corrigez la pente de la rampe \n");
		}
	}
}


/*
	NOM	: analyse Pente Avec Angle
	DEF : Affiche un rapport sur l'analyse de la pente selon la longueur et hauteur de celle ci
			ET on retourne la valeur de l'angle de la pente
	PARAMETRES :		hauteur (double)
						longueur (double)
	RETOUR :			l'angle de la pente (double)
	SPÉCIFICATION :		La longueur doit être strictement positive et plus grand zéro
*/
double analysePenteAvecAngle (double hauteur, double longueur) {

	double angle = 0;

	// Valide si la longueur saisie est plus grande que zéro
	if (longueur > 0) {

		// Calcul de l'angle
		angle = atan(hauteur / longueur) * MAX_ANGLE / M_PI;

		// Analyse de l'angle
		if (angle < 0 || angle > MAX_ANGLE) {
			printf("Erreur : L'angle doit etre compris entre 0 et 180 degres \n");
		}
		else if (angle < LIM_SEC) {
			printf("Zone securisee : Fonctionnement normal \n");
		}
		else if (angle < LIM_OPE) {
			printf("Zone operationnelle : Fonctionnement correct \n");
		}
		else if (angle < LIM_SUR) {
			printf("Zone de surveillance : attention a l'effort mecanique \n");
		}
		else {
			printf("Zone critique : Corrigez la pente de la rampe \n");
		}


	}
	return angle;
}


/* Fonction de test */
void testAnalysePenteAvecAngle(void) {

	double h;
	double l;
	double a;

	h = 2;
	l = -4;
	printf("\nTest 1 \n");
	a = analysePenteAvecAngle(h,l);
	printf("Pour une hauteur de %0.2lf et une longueur de %0.2lf l'angle est de : %0.2lf\n",h,l,a);

	h = 10;
	l = 10;
	printf("\nTest 2 \n");
	a = analysePenteAvecAngle(h,l);
	printf("Pour une hauteur de %0.2lf et une longueur de %0.2lf l'angle est de : %0.2lf\n",h,l,a);

	h = 100;
	l = 1;
	printf("\nTest 3 \n");
	a = analysePenteAvecAngle(h,l);
	printf("Pour une hauteur de %0.2lf et une longueur de %0.2lf l'angle est de : %0.2lf\n",h,l,a);

	h = 1;
	l = 100;
	printf("\nTest 4 \n");
	a = analysePenteAvecAngle(h,l);
	printf("Pour une hauteur de %0.2lf et une longueur de %0.2lf l'angle est de : %0.2lf\n",h,l,a);

}
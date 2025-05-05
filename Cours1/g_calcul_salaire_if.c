/****************************************************************************************
	Auteur  : David Beaulieu
	Date    : 9 janvier 2022
	Fichier : calcul_salaire.c

	Description: Programme qui calcul un salaire annuel selon un maximum d'heure par semaine

	NOTE DE L'ENSEIGNANT : Les commentaires de ce module sont des explications, ils ne
						   représentent pas vraiment ce qui est attendu de vous lors
						   de la remise de vos travaux pratiques.

*****************************************************************************************/

/****************************************************************************************
*                               COMMANDE DU PRÉPROCESSEUR                               *
****************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/****************************************************************************************
*                               DÉFINITION DES CONSTANTES                                *
****************************************************************************************/
//Nombre d'heures maximale avant majoration
#define MAX_HEURES 40.0

//Montant à multiplier au taux pour le majorer
#define MAJORATION 1.5

/****************************************************************************************
*                           DÉFINITION DU PROGRAMME PRINCIPALE                           *
****************************************************************************************/
int main(void)
{
    //VARIABLES

    //Sert à la saisie du  taux horaire
	double taux;

    //Sert à la saisie du nombre d'heures
	double nb_heures;

	//sert à retenir le calcul du salaire
	double salaire;
      
	//sollicitation du taux horaire
	printf("\n\nEntrez le taux horaire svp : ");
	scanf("%lf", &taux);

	//sollicitation du nombre d'heures travaillees
	printf("\n\nEntrez le nombre d\'heures travaillees : ");
	scanf("%lf", &nb_heures);

	//calculs du salaire avec ou sans majoration
	if (nb_heures <= MAX_HEURES) {

		salaire = taux * nb_heures;
	 }	   
	else {

		salaire = MAX_HEURES * taux + (nb_heures - MAX_HEURES) * taux * MAJORATION;
	 }
		  

    //affichage du salaire
	printf("\n\nVotre salaire de brut est : %0.2lf \n\n", salaire);

	return EXIT_SUCCESS;
}

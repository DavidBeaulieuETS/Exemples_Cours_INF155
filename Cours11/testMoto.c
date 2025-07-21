/*****************************************************************************************
Par        : David Beaulieu
    Revise le  :
    Fichier    :
    Objectifs  :
    Note	   :
*****************************************************************************************/

/****************************************************************************************
*                            AJOUT DES MODULES ET LIBRAIRIES                            *
****************************************************************************************/
#include <stdlib.h>		// Librairie Standard
#include <stdio.h>		// Librairie Entrée - Sortie
#include <windows.h>    // Librairie des commandes de windows

#include "mMoto.h"

/****************************************************************************************
*                           DÉFINITION DU PROGRAMME PRINCIPALE                          *
****************************************************************************************/
int main(void)
{
    SetConsoleOutputCP(CP_UTF8);        // Définit l'encodage de sortie de la console à UTF-8
    setbuf(stdout, 0);		            // Permets d'afficher les printf en mode débug avec Clion

    t_garage monGarage;
    t_garage * garageFiltre;
    t_moto maMoto;

    remplirGarage(&monGarage);

    // Test de chercher Moto
    printf("\n=== Test de chercher Moto === \n");
    if (chercherMoto(&monGarage,1164,ROUTE,&maMoto)){
        afficherMoto(&maMoto);
    }
    else {
      printf("\n=== Aucune moto ne correspond aux critères ===\n");
    }

    // Test de filtre moto
    printf("\n=== Test de filtre Moto === \n");
    garageFiltre = filtreMotoMarque(&monGarage,"Yamaha");
    if (garageFiltre != NULL){
        afficherGarage(garageFiltre);
    }
    else {
        printf("\n=== Aucune moto ne correspond aux critères ===\n");
    }

    // Test de trier garage
    printf("\n=== Test de trier garage === \n");
    trierGarageAnnee(&monGarage);
    afficherGarage(&monGarage);


    return EXIT_SUCCESS;  		        // Permet de terminer le programme proprement
}

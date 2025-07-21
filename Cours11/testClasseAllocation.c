/*****************************************************************************************
    Par        : David Beaulieu
    Revise le  : H2025
    Fichier    : testClasseAllocation.c
    Objectifs  : Démonstration des différentes classe d'allocation en C
    Note	   :
*****************************************************************************************/

/****************************************************************************************
*                            AJOUT DES MODULES ET LIBRAIRIES                            *
****************************************************************************************/
#include <stdlib.h>		// Librairie Standard
#include <stdio.h>		// Librairie Entrée - Sortie
#include <windows.h>    // Librairie des commandes de windows

#include "mClasseAllocation.h"


/****************************************************************************************
*                           DÉFINITION DU PROGRAMME PRINCIPALE                          *
****************************************************************************************/
int main(void)
{
    SetConsoleOutputCP(CP_UTF8);        // Définit l'encodage de sortie de la console à UTF-8
    setbuf(stdout, 0);		            // Permets d'afficher les printf en mode débug avec Clion


    // Exemple de déclaration auto
    printf("Exemple de déclaration auto\n");
    exempleLocal();
    //printf("Affiche la variable z après la fonction %lf\n",z);

    // Exemple de déclaration register
    printf("\nExemple de déclaration register\n");
    exempleRegister();

    // Exemple de déclaration static
    printf("\nExemple de déclaration static\n");
    for (int i = 0; i < 4; ++i) {
        exempleStatic();
    }

    // Exemple de déclaration extern
    printf("\nExemple de déclaration extern\n");
    for (int i = 0; i < 4; ++i) {
        exempleExtern();
    }
    //printf("Utilisation extern à l'intérieur du module : %i",compteurGlobal);
    //printf("Utilisation extern à l'intérieur du module (static) : %i",compteurGlobalPrive);

    //Appel impossible d'une fonction privée
    //exempleFonctionPrivee();

    return EXIT_SUCCESS;  		        // Permet de terminer le programme proprement
}

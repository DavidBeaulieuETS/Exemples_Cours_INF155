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
#include <math.h>       // Librairie de fonctions mathématique
#include <time.h>		// Librairie de gestion du temps, inclut lafonction time()
#include <ctype.h>      // Librairie de classification et de manipulation de caractères
#include <string.h>     // Librairie pour manipuler des chaines de caractères
#include <windows.h>    // Librairie des commandes de windows

/****************************************************************************************
*                               DÉFINITION DES CONSTANTES                               *
****************************************************************************************/

/****************************************************************************************
*                           DÉFINITION DES STRUCTURES ET TYPES                          *
****************************************************************************************/

/****************************************************************************************
*								DÉCLARATION DES FONCTIONS								*
****************************************************************************************/
/*
    NOM	:
    DESCRIPTION :
    PARAMETRES :
    RETOUR :
    SPÉCIFICATION :
*/


/****************************************************************************************
*                           DÉFINITION DU PROGRAMME PRINCIPALE                          *
****************************************************************************************/
int main(void)
{
    SetConsoleOutputCP(CP_UTF8);        // Définit l'encodage de sortie de la console à UTF-8
    setbuf(stdout, 0);		            // Permets d'afficher les printf en mode débug avec Clion

    int i;
    int taille;
    char * tab = NULL;



    for (i = 0; i<1000; i++){
        tab = (char*)malloc(1000000000 * sizeof(char));
        printf("%p\n",tab);
    }
    system("pause");
    for (i = 0; i<1000; i++){
        tab = (char*)malloc(1000000000 * sizeof(char));
        printf("%p\n",tab);
    }
    system("pause");
    return EXIT_SUCCESS;  		        // Permet de terminer le programme proprement
}
//  chaine[strcspn(chaine, "\n")] = '\0';  nettoyer les \n laissés par fgets,
/****************************************************************************************
/									DÉFINITION DES FONCTIONS							*
****************************************************************************************/
/*
    NOM	:
    DESCRIPTION :
    PARAMETRES :
    RETOUR :
    SPÉCIFICATION :
*/


/****************************************************************************************
/							DÉFINITION DES FONCTIONS DE TEST							*
****************************************************************************************/
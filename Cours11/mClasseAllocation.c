/*****************************************************************************************
    Par        : David Beaulieu
    Revise le  : H2025
    Fichier    : mClasseAllocation
    Objectifs  : Démonstration des différentes classe d'allocation en C
    Note	   :
*****************************************************************************************/

/****************************************************************************************
*                            AJOUT DES MODULES ET LIBRAIRIES                            *
****************************************************************************************/
#include <stdlib.h>		// Librairie Standard
#include <stdio.h>		// Librairie Entrée - Sortie

#include "mClasseAllocation.h"

/****************************************************************************************
*                               DÉFINITION DES CONSTANTES                               *
****************************************************************************************/
#define UNE_CONSTANTE_PRIVEE 1;

/****************************************************************************************
*                          DÉCLARATION DES VARIABLES GLOBALES                           *
****************************************************************************************/
int compteurGlobal = 0;
static int compteurGlobalPrive = 0;

/****************************************************************************************
*								DÉCLARATION DES FONCTIONS PRIVÉES					    *
****************************************************************************************/
static void exempleFonctionPrivee();


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
void exempleLocal(){

  auto int x = 10;
  double y = 20.0;  // auto par défaut
  auto double z;

  z = x + y;
  printf("Affiche la variable z durant la fonction %lf\n",z);
}

void exempleRegister(){

  register int memoireCpu = 11;
  memoireCpu++;

    printf("Contenu de memoireCpu %d\n",memoireCpu);

    //printf("Adresse de memoireCpu %p\n",&memoireCpu);
}

void exempleStatic(){

  static int compteurInterne = 0;

  compteurInterne++;

  printf("Nombre d'appel fonction %d\n",compteurInterne);

}

void exempleExtern() {

    compteurGlobal++;
    compteurGlobalPrive++;

    // tentative d'une variable static local
    //compteurInterne++;

    printf("Utilisation extern à l'intérieur du module  : %i\n",compteurGlobal);
    printf("Utilisation extern à l'intérieur du module (static) : %i\n",compteurGlobalPrive);
}

static void exempleFonctionPrivee(){

    printf("Cette fonction est privée au module !!\n");
}


/****************************************************************************************
/							DÉFINITION DES FONCTIONS DE TEST							*
****************************************************************************************/
/*****************************************************************************************
    Par        : David Beaulieu
    Revise le  : H2025
    Fichier    : mClasseAllocation
    Objectifs  : Démonstration des différentes classe d'allocation en C
    Note	   :
*****************************************************************************************/
#ifndef MCLASSEALLOCATION_H
#define MCLASSEALLOCATION_H

/****************************************************************************************
*                               DÉFINITION DES CONSTANTES                               *
****************************************************************************************/
#define UNE_CONSTANTE_PUBLIQUE 1;




/****************************************************************************************
*								DÉCLARATION DES FONCTIONS								*
****************************************************************************************/
/*
    Exemple d'utilisation de la classe d'allocation local
*/
void exempleLocal();

/*
    Exemple d'utilisation de la classe d'allocation register
*/
void exempleRegister();

/*
    Exemple d'utilisation de la classe d'allocation static
*/
void exempleStatic();

/*
    Exemple d'utilisation de la classe d'allocation extern
*/
void exempleExtern();

#endif //MCLASSEALLOCATION_H

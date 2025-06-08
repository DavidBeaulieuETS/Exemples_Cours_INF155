/*****************************************************************************************
    Par        : Francis Bourdeau
    Revisé par : David Beaulieu
    Revise le  : H 2025
    Fichier    : stringh.c
    Objectifs  : Ce module contient des exemples afin de montrer comment utiliser la libraire string.h
    Note	   :

    NOTE DE L'ENSEIGNANT : Les commentaires de ce module sont des explications, ils ne
                           représentent pas vraiment ce qui est attendu de vous lors
                           de la remise de vos travaux pratiques.

/****************************************************************************************
*                            AJOUT DES MODULES ET LIBRAIRIES                            *
****************************************************************************************/
#include <stdlib.h>		/* Librairie Standart */
#include <stdio.h>		/* Librairie Entrer - Sortie */
#include <string.h>     /* Librairie pour manipuler des chaines de caractères */

/****************************************************************************************
*                               DÉFINITION DES CONSTANTES                               *
****************************************************************************************/
#define TAILLE_CHAINE       80

/****************************************************************************************
*								DÉCLARATION DES FONCTIONS								*
****************************************************************************************/

/****************************************************************************************
*                           DÉFINITION DU PROGRAMME PRINCIPALE                          *
****************************************************************************************/
int main(void)
{
    setbuf(stdout, 0);		                 // Permets d'afficher les printf en mode débug avec Clion

    char une_chaine[TAILLE_CHAINE] = "Voici une chaine de test.";
    char autre_chaine[TAILLE_CHAINE] = "Voici une deuxieme chaine de test";
    char chaine3[TAILLE_CHAINE];
    int nb_lettre;


    //
    //  strlen permet de compter le nombre de symbole d'une chaine.
    //         il detecte le 1er '\0'
    //
    nb_lettre = strlen(une_chaine);

    //
    // strcmp permet de comparer deux chaines ensembles lettres par lettres.
    //          elle retourne 0, lorsque les deux chaines sont pareils.
    //
    if(strcmp(une_chaine, autre_chaine) == 0)
        printf("Lorsque strcmp retourne 0, les chaines sont pareils!\n");
    
    else
        printf("Avant la copie, les chaines ne sont pas pareils!\n");


    //
    // strcpy(dest, src) : Copie une chaine à l'intérieur d'une autre.
    //          
    //
    strcpy(autre_chaine, une_chaine);
    if(strcmp(une_chaine, autre_chaine) == 0)
        printf("Apres la copie, les chaines sont pareils!\n");
    
    //
    // strncpy(chaine3, une_chaine) : Copie les n premiers caractère à l'intérieur d'une autre.
    //                                Attentions, vous devez ajoutez vous même le '\0'
    strncpy(chaine3, une_chaine, 5);
    chaine3[5] = '\0';
    if(strcmp(une_chaine, autre_chaine) == 0)
        printf("%s\n", chaine3);
    
    return 0;
}
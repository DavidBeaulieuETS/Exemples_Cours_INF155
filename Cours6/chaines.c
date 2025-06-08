/*****************************************************************************************
    Par        : Francis Bourdeau
    Revisé par : David Beaulieu
    Revise le  : H 2025
    Fichier    : chaines.c
    Objectifs  : Ce module contient un exemple afin de montrer comment déclarer, coder et utiliser
    les chaines de caractères.
    Note	   :

    NOTE DE L'ENSEIGNANT : Les commentaires de ce module sont des explications, ils ne
                           représentent pas vraiment ce qui est attendu de vous lors
                           de la remise de vos travaux pratiques.

/****************************************************************************************
*                            AJOUT DES MODULES ET LIBRAIRIES                            *
****************************************************************************************/
#include <stdlib.h>		/* Librairie Standart */
#include <stdio.h>		/* Librairie Entrer - Sortie */

/****************************************************************************************
*                               DÉFINITION DES CONSTANTES                               *
****************************************************************************************/
#define TAILLE_CHAINE       25

/****************************************************************************************
*								DÉCLARATION DES FONCTIONS								*
****************************************************************************************/


/****************************************************************************************
*                           DÉFINITION DU PROGRAMME PRINCIPALE                          *
****************************************************************************************/
int main(void)
{
    setbuf(stdout, 0);		          // Permets d'afficher les printf en mode débug avec Clion

    int i;                            // Itérateur pour la chaine de caractère

    //
    //  Une chaine de caractère est un tableau de char qui doit obligatoiremment
    //  ce terminer par le caractère '\0'.
    //  Par exemple, si on veut contenir la chaine salut, on a besoin d'un tableau de 
    //  6 caractères (5 lettres + 1 '\0');
    //

    
    //
    // On peut initialiser une chaine lors de sa déclaration.
    //
    char chaine[6] = "salut";


    //
    // L'utilisateur peut entrée une chaine au clavier.
    // Il ne doit pas dépasser la capacité du tableau sous risque de
    // corrompre la mémoire après le tableau.
    //
    char uneChaine[TAILLE_CHAINE];
    printf("Entrer du texte ayant moins de 25 caracteres (pas d'espaces)\n");
    scanf("%s", uneChaine);
    fflush(stdin);                                // Permet de vider la mémoire du clavier

    //
    // On peut réafficher la chaine avec un printf.
    //
    printf("Vous avez entrer :\n");
    printf("%s\n", uneChaine);

    printf("\n\n");

    //
    // Pour saisir des chaines ayant des espaces, utiliser gets
    //
    printf("Entrer du texte ayant moins de 25 caracteres\n");
    gets(uneChaine);
    printf("Vous avez entrer :\n");
    printf("%s\n", uneChaine);


    //
    //  Contrairement aux tableaux, une fonctions n'a pas besoin de recevoir un
    //  la taille de la chaine de caractère car elle cherche le caractere '\0'
    //
    printf("\n\n");
    printf("Affichons une chaines lettre par lettre :\n");
    
    i = 1;
    printf("%c", chaine[0]);
    while(chaine[i] != '\0')
    {
        printf(", %c", chaine[i]);
        i++;
    }
    printf("\n\n");

    return 0;
}
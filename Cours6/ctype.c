/*****************************************************************************************
    Par        : Francis Bourdeau
    Revisé par : David Beaulieu
    Revise le  : H 2025
    Fichier    : ctype.c
    Objectifs  : Ce module montre comment utiliser les fonctions du module ctype.h
    Note	   :

    NOTE DE L'ENSEIGNANT : Les commentaires de ce module sont des explications, ils ne
                           représentent pas vraiment ce qui est attendu de vous lors
                           de la remise de vos travaux pratiques.

/****************************************************************************************
*                            AJOUT DES MODULES ET LIBRAIRIES                            *
****************************************************************************************/
#include <stdlib.h>		/* Librairie Standart */
#include <stdio.h>		/* Librairie Entrer - Sortie */
#include <ctype.h>      /* Librairie de classification et de manipulation de caractères */

/****************************************************************************************
*                               DÉFINITION DES CONSTANTES                               *
****************************************************************************************/

/****************************************************************************************
*								DÉCLARATION DES FONCTIONS								*
****************************************************************************************/

/****************************************************************************************
*                           DÉFINITION DU PROGRAMME PRINCIPALE                          *
****************************************************************************************/
int main(void)
{
    setbuf(stdout, 0);		                 // Permets d'afficher les printf en mode débug avec Clion
    char symbole1;
    char symbole2;

    //
    // Puisque la casse est importante, on peut vérifier si une lettre est une
    // minuscle ou une majuscule.
    //
    symbole1 = 'e';
    symbole2 = 'T';
    if(islower(symbole1))
        printf("%c est une minuscule\n", symbole1);
    
    if(!islower(symbole2))
        printf("%c n'est pas une minuscule\n", symbole2);
 
     if(isupper(symbole2))
        printf("%c est une majuscule\n", symbole2);
    
    if(!isupper(symbole1))
        printf("%c n'est pas une majuscule\n", symbole1); 
    
    printf("\n\n\n");
    
    //
    // On peut convertir des symboles d'une case à l'autre.
    //
    printf("%c est maintenant ", symbole1);
    symbole1 = toupper(symbole1);
    printf("une majuscule : %c\n", symbole1);

    printf("%c est maintenant ", symbole2);
    symbole2 = tolower(symbole2);
    printf("une minuscule : %c\n", symbole2);

    symbole2 = '9';
    printf("%c n'est pas affecte ", symbole2);
    symbole2 = tolower(symbole2);
    printf("par les symboles de conversions : %c\n", symbole2);

    printf("\n\n\n");

    //
    //  Il existe plein d'autres fonctions qui déterminent le groupe
    //  auquel appartient un caractère.
    //      voir : http://www.cplusplus.com/reference/cctype/
    //
    printf("isalpha('A')  :: %i\n", isalpha('A'));
    printf("isalpha('a')  :: %i\n", isalpha('a'));
    printf("isalpha('5')  :: %i\n", isalpha('5'));
    printf("isalpha(' ')  :: %i\n", isalpha(' '));
    printf("isalpha('\\n') :: %i\n", isalpha('\n'));
    printf("\n");
    printf("isdigit('A')  :: %i\n", isdigit('A'));
    printf("isdigit('a')  :: %i\n", isdigit('a'));
    printf("isdigit('5')  :: %i\n", isdigit('5'));
    printf("isdigit(' ')  :: %i\n", isdigit(' '));
    printf("isdigit('\\n') :: %i\n", isdigit('\n'));
    printf("\n");
    printf("isspace('A')   :: %i\n", isspace('A'));
    printf("isspace('a')   :: %i\n", isspace('a'));
    printf("isspace('5')   :: %i\n", isspace('5'));
    printf("isspace(' ')   :: %i\n", isspace(' '));
    printf("isspace('\\n')  :: %i\n", isspace('\n'));
    printf("\n");
    printf("iscntrl('A')   :: %i\n", iscntrl('A'));
    printf("iscntrl('a')   :: %i\n", iscntrl('a'));
    printf("iscntrl('5')   :: %i\n", iscntrl('5'));
    printf("iscntrl(' ')   :: %i\n", iscntrl(' '));
    printf("iscntrl('\\n')  :: %i\n", iscntrl('\n'));
}
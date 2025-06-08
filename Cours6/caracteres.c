/*****************************************************************************************
    Par        : Francis Bourdeau 
    Revisé par : David Beaulieu
    Revise le  : H 2025
    Fichier    : caracteres.c
    Objectifs  : Démonstration sur le type char
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

/****************************************************************************************
*								DÉCLARATION DES FONCTIONS								*
****************************************************************************************/
/*
    afficher Caracteres
    Cette fonction affiche tout les caractères présents entre les deux caractères reçu.
    Paramètre 
    PARAMETRES :	premierCaractere : Le premier caractère à afficher.
                    dernierCaractere : Le premier caractère à afficher.
    RETOUR :		Aucun
    SPÉCIFICATION : Aucune
*/
void afficherCaracteres(unsigned char premierCaractere,
                         unsigned char dernierCaractere);


/****************************************************************************************
*                           DÉFINITION DU PROGRAMME PRINCIPALE                          *
****************************************************************************************/
int main(void)
{
    setbuf(stdout, 0);		                 // Permets d'afficher les printf en mode débug avec Clion
    char caractereRegulier;
    unsigned char caractereEtendu;
    
    /*
     *  Le type char est utilisé pour représenter les caractères. 
     *  Ce type admet des valeurs entre -128 et 127. 
     *  Comme le montre la table ASCII, les valeurs négatives ne sont pas utilis�es.
     *  On peut donc représenter 127 caractères, soit la table ASCII standard.
     */
     
     
     /*
     *  Le type unsigned char n'admet pas les valeurs négatives.
     *  Il y a donc plus d'espace pour les valeurs positive (de 0 à 255).
     *  On peut donc représenter 127 caractères, soit la table ASCII standard.
     *  Et on peut aussi représenter la table ASCII atendue, soit les valeurs de 128 à 255.
     */

    char symbole1;      // Pour les tests.
    char symbole2;

    // On peut toujours représenter un caractère par son symbole entre apostrophe.
    printf("Voici les lettres majuscules dans la table ASCII :\n");
    afficherCaracteres('A', 'Z');
    system("pause");
    printf("\n\n");

    // On peut également représenter les caractères par leurs numéros.
    printf("Voici les lettres minuscule dans la table ASCII :\n");
    afficherCaracteres(97, 122);
    system("pause");
    printf("\n\n");

    // Il en va de même pour les chiffres.
    // ATTENTION : Il faut utiliser leur symbole ou leurs code ('0' --> 48)
    printf("Voici les chiffre dans la table ASCII :\n");
    afficherCaracteres(48, '9');
    system("pause");
    printf("\n\n");

    // Section de la table ACII étendue
    printf("Voici une section de la table ASCII etendue :\n");
    afficherCaracteres(130, 144);
    system("pause");
    printf("\n\n");

    // La comparaison de caractère se fait en fonction de la table ASCII.
    symbole1 = 'A';
    symbole2 = 'C';
    if(symbole1 < symbole2)
        printf("'A' est avant 'C' dans la table ASCII.\n");

    // Il faut donc faire attention à l'ordre de présentation des types
    // de caractère.
    symbole1 = 'a';
    symbole2 = 'Z';
    if(symbole1 > symbole2)
        printf("'a' est apres 'Z' ... ce n'est pas l'ordre alphabetique!.\n");
    
    // On peut même comparer des lettres et des nombres, car on compare leurs symobles.
    symbole1 = '9';
    symbole2 = 'a';
    if(symbole1 < symbole2)
        printf("'9' est avant 'a'\n");
    
    // On en conclu que la casse est extrement importante dans la comparaison des 
    // des caracteres.
    symbole1 = 'A';
    symbole2 = 'a';
    if(symbole1 == symbole2)
        printf("FAUX! 'A' et 'a' ne sont pas les memes symboles.\n");
    else if(symbole1 != symbole2)
        printf("'A' et 'a' ne sont pas les memes symboles.\n");

    if(symbole1 < symbole2)
        printf("Les majuscules pr\x82\c\x8a\de les minuscules.\n");
    return 0;
}

/****************************************************************************************
*                               DÉFINITION DES FONCTIONS                                *
****************************************************************************************/
void afficherCaracteres(unsigned char premierCaractere, unsigned char dernierCaractere)
{
    unsigned char unCaractere;     // Les caracteres à afficher.

    // On affiche tout les caractères dans l'intervalle reçue.
    for( unCaractere = premierCaractere; unCaractere <= dernierCaractere; unCaractere++)
    {
        printf("Code ASCII: %i\t\t", unCaractere);
        printf("Caractere: %c\n", unCaractere);
    }
}

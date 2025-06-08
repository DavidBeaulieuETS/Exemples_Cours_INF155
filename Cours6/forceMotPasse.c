/*****************************************************************************************
    Par        : Francis Bourdeau
    Revisé par : David Beaulieu
    Revise le  : H 2025
    Fichier    : forceMotPasse.c
    Objectifs  : Ce module contient un exemple de parcours de chaine de caractères.
                 On attribue un point par type de caractère contenu dans un mot de passe.
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
#include <string.h>     /* Librairie pour manipuler des chaines de caractères */

/****************************************************************************************
*                               DÉFINITION DES CONSTANTES                               *
****************************************************************************************/

/****************************************************************************************
*								DÉCLARATION DES FONCTIONS								*
****************************************************************************************/
/*
    forceMotPasse

    Cette fonction permet déterminer la force d'un mot de passe (entre 0 et 3) en attribuant
    un point par type de caractères présent dans le mot de passe 
    Les types de caractères acceptés sont :
        - les minuscules
        - les majuscules
        - les chiffres

    Paramètres:
        - mot_passe : Le mot de passe à analyser

    Retour: 
        - La force du mot de passe.
*/
int forceMotPasse(char mot_passe[]);

/****************************************************************************************
*                           DÉFINITION DU PROGRAMME PRINCIPALE                          *
****************************************************************************************/
int main(void)
{
    setbuf(stdout, 0);		                 // Permets d'afficher les printf en mode débug avec Clion

    int no_test;
    int prediction;
    int resultat;

    char mot_passe1[] = "Salut123!";
    char mot_passe2[] = "[] {} ()";
    char mot_passe3[] = "";


    printf("--- TEST FORCE MOT PASSE ---\n");
    printf("\n");

    no_test = 1;
    prediction = 3;
    resultat = forceMotPasse(mot_passe1);
    printf("Test no%i - mdp: %s\n", no_test, mot_passe1);
    printf("\tattendue : %i\n", prediction);
    printf("\t obtenue : %i\n", resultat);
    printf("\n");

    no_test = 2;
    prediction = 0;
    resultat = forceMotPasse(mot_passe2);
    printf("Test no%i - mdp: %s\n", no_test, mot_passe2);
    printf("\tattendue : %i\n", prediction);
    printf("\t obtenue : %i\n", resultat);
    printf("\n");


    no_test = 3;
    prediction = 0;
    resultat = forceMotPasse(mot_passe2);
    printf("Test no%i - mdp: %s\n", no_test, mot_passe3);
    printf("\tattendue : %i\n", prediction);
    printf("\t obtenue : %i\n", resultat);
    printf("\n");

    return EXIT_SUCCESS;
}

int forceMotPasse(char mot_passe[])
{
    // Chaque catégorie n'a pas encore été rencontré.
    int majuscule_trouvee = 0;
    int minuscule_trouvee = 0;
    int chiffre_trouvee = 0;

    // On anlyse les symboles un par un.
    int longueur = strlen(mot_passe);
    for(int i=0; i < longueur; i++)
    {

        // Extraction du symbole courant.
        char symbole = mot_passe[i];

        // On vérifie si le symbole actuelle est une majuscule
        if (isupper(symbole))
            majuscule_trouvee = 1;

        // On vérifie si le symbole actuelle est une minusucle
        if (islower(symbole))
            minuscule_trouvee = 1;

        // On vérifie si le symbole actuelle est un chiffre
        if (isdigit(symbole))
            chiffre_trouvee = 1;

    }

    //On additionne toutes les catégories trouvées pour établir le pointage 
    //du mot de passe.
    return majuscule_trouvee + minuscule_trouvee + chiffre_trouvee;
}

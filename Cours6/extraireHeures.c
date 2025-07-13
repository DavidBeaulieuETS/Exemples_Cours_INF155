/*****************************************************************************************
    Par        : Francis Bourdeau
    Revisé par : David Beaulieu
    Revise le  : H 2025
    Fichier    : extraireHeures.c
    Objectifs  : Ce module contient un exemple de parcours de chaine de caractères.
                    On tente de trouver une séquence de 5 caractères représentant une heure.
                    ex : 11h45.
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
// Les heures seront toujours définit sur 5 symboles.
#define LONGUEUR_HEURE  5


/****************************************************************************************
*								DÉCLARATION DES FONCTIONS								*
****************************************************************************************/
/*
    estHeureValide

    Cette fonction permet déterminer si une chaine de caractères est une heure valide.
    On suppose que la chaine reçue possède 5 caractères.
    Les deux premiers symboles doivent former un nombre entre 0 et 23.
    Le troisième symbole doit être un h.
    Les deux dernier symboles doivent former un nombre entre 0 et 59.

    Paramètres:
        - chaine : L'heure à analyser

    Retour: 
        - 1 si la chaine reçue est une heure valide, 0 sinon.
*/
int estHeureValide(char chaine[]);
void testHeureEstValide(void);



/*
    extraire Heure

    Cette fonction tente de trouver une chaine de caractère qui représente une
    heure valide.

    Paramètres:
        - chaine        : La chaine à analyser
        - heureTrouver : Une référence vers une chaine de caractère dans laquelle on 
                          inscrit l'heure trouvée.

    Retour: 
        L'indice où l'heure est trouvée dans la chaine.
        -1 si aucune heure n'est trouvée.

*/
int extraireHeure(char chaine[], char heureTrouver[]);
void testExtraireHeure(void);

/****************************************************************************************
*                           DÉFINITION DU PROGRAMME PRINCIPALE                          *
****************************************************************************************/
int main(void)
{
    setbuf(stdout, 0);		                 // Permets d'afficher les printf en mode débug avec Clion

    //testHeureEstValide();
    testExtraireHeure();

    return EXIT_SUCCESS;
}


/****************************************************************************************
*                               DÉFINITION DES FONCTIONS                                *
****************************************************************************************/
/*
    est Heure Valide

    Cette fonction permet déterminer si une chaine de caractères est une heure valide.
    On suppose que la chaine reçue possède 5 caractères.
    Les deux premiers symboles doivent former un nombre entre 0 et 23.
    Le troisième symbole doit être un h.
    Les deux dernier symboles doivent former un nombre entre 0 et 59.

    Paramètres:
        - chaine : L'heure à analyser

    Retour: 
        - 1 si la chaine reçue est une heure valide, 0 sinon.
*/
int estHeureValide(char chaine[])
{
    int est_valide = 1;     //On suppose que l'heure reçue est ok.

    //On cherche une erreur dans le premier caractère
    if(!('0' <= chaine[0] && chaine[0] <= '2') )
        est_valide = 0;

    //On cherche une erreur dans le second caractère
    if(!('0' <= chaine[1] && chaine[1] <= '9') )
        est_valide = 0;

    //On cherche une erreur dans le troisième caractère
    if(chaine[2] != 'h')
        est_valide = 0;

    //On cherche une erreur dans le quatrième caractère
    if(!('0' <= chaine[3] && chaine[3] <= '5') )
        est_valide = 0;


    //On cherche une erreur dans le cinquième caractère
    if(!('0' <= chaine[4] && chaine[4] <= '9') )
        est_valide = 0;

    return est_valide;
}

/*
    extraire Heure

    Cette fonction tente de trouver une chaine de caractère qui représente une
    heure valide.

    Paramètres:
        - chaine        : La chaine à analyser
        - heureTrouver : Une référence vers une chaine de caractère dans laquelle on
                          inscrit l'heure trouvée.

    Retour:
        L'indice où l'heure est trouvée dans la chaine.
        -1 si aucune heure n'est trouvée.

*/
int extraireHeure(char chaine[], char heureTrouver[])
{
    char section_courante[LONGUEUR_HEURE+1];

    //On suppose qu'on ne trouvera pas d'heure dans la chaine.
    int resultat = -1;
    heureTrouver[0]    = '\0';

    // 
    // On parcours de tous les symboles d'une chaîne
    //
    int longueurChaine = strlen(chaine);
    for (int i=0; i < longueurChaine-LONGUEUR_HEURE+1; i++)
    {
        //On extrait la section représentant potentiellement une heure.
        strncpy(section_courante, chaine + i, LONGUEUR_HEURE);
        section_courante[LONGUEUR_HEURE] = '\0';

        //On déterminer s'il s'agit d'une heure valide
        if(estHeureValide(section_courante))
        {
            //si c'est le cas, on modifie notre hypothèse initale et on retourne l'heure trouvée.
            resultat = i;
            strcpy(heureTrouver, section_courante);
            heureTrouver[LONGUEUR_HEURE] = '\0';
        }
    }

    return resultat;
}

/****************************************************************************************
*                          DÉFINITION DES FONCTIONS DE TEST                             *
****************************************************************************************/
void testExtraireHeure(void)
{
    char* chaine1 = "Notez qu'a 11h45, vous aurez votre rendez-vous.";
    char* chaine2 = "Vous n'avez pas de rendez-vous ajourd'hui.";
    char  heure[LONGUEUR_HEURE + 1] = {'\0'};


    int no_test;
    int prediction;
    int resultat;
    
    printf("--- TEST EXTRAIRE HEURE ---\n");
    printf("\n");


    no_test = 1;
    prediction = 11;
    resultat = extraireHeure(chaine1, heure);
    printf("Test no%i - %s\n", no_test, chaine1);
    printf("\tattendue : %i - %s\n", prediction, "11h45");
    printf("\t obtenue : %i - %s\n", resultat, heure);
    printf("\n");

    no_test = 2;
    prediction = -1;
    resultat = extraireHeure(chaine2, heure);
    printf("Test no%i - %s\n", no_test, chaine2);
    printf("\tattendue : %i %s\n", prediction, "");
    printf("\t obtenue : %i %s\n", resultat, heure);
    printf("\n");

}

void testHeureEstValide(void)
{
    int no_test;
    int prediction;
    int resultat;

    char chaine1[] = "Notez";
    char chaine2[] = "11+45";
    char chaine3[] = "59h99";
    char chaine4[] = "11h45";


    printf("--- TEST HEURE EST VALIDE ---\n");
    printf("\n");


    no_test = 1;
    prediction = 0;
    resultat = estHeureValide(chaine1);
    printf("Test no%i - heure: %s\n", no_test, chaine1);
    printf("\tattendue : %i\n", prediction);
    printf("\t obtenue : %i\n", resultat);
    printf("\n");

    no_test = 2;
    prediction = 0;
    resultat = estHeureValide(chaine2);
    printf("Test no%i - heure : %s\n", no_test, chaine2);
    printf("\tattendue : %i\n", prediction);
    printf("\t obtenue : %i\n", resultat);
    printf("\n");

    no_test = 3;
    prediction = 0;
    resultat = estHeureValide(chaine3);
    printf("Test no%i - heure : %s\n", no_test, chaine3);
    printf("\tattendue : %i\n", prediction);
    printf("\t obtenue : %i\n", resultat);
    printf("\n");

    no_test = 4;
    prediction = 1;
    resultat = estHeureValide(chaine4);
    printf("Test no%i - heure : %s\n", no_test, chaine4);
    printf("\tattendue : %i\n", prediction);
    printf("\t obtenue : %i\n", resultat);
    printf("\n");

}
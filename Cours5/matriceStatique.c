/*****************************************************************************************
    Par        : David Beaulieu
    Revise le  : H2025
    Fichier    : tableau2dStatique.c
    Objectifs  : Démonstration de l'utilisation des tableaux 2D Statique (Matrice)
    Note	   :

    NOTE DE L'ENSEIGNANT : Les commentaires de ce module sont des explications, ils ne
                           représentent pas vraiment ce qui est attendu de vous lors
                           de la remise de vos travaux pratiques.

/****************************************************************************************
*                            AJOUT DES MODULES ET LIBRAIRIES                            *
****************************************************************************************/
#include <stdlib.h>			/* Module Standart */
#include <stdio.h>			/* Module Entrée - Sortie */
#include <time.h>			/* Module utile pour la fonction time() */

/****************************************************************************************
*                               DÉFINITION DES CONSTANTES                               *
****************************************************************************************/
// Taille de matrice de démonstration
#define NB_LIGNE      3
#define NB_COLONNE    5

// Intervalle de valeur attribué à la matrice
#define VALEUR_MIN    -10
#define VALEUR_MAX    10

/****************************************************************************************
*								DÉCLARATION DES FONCTIONS								*
****************************************************************************************/

/*
    Déclaration de fonction
    En C, un tableau 2D statique est défini comme un tableau 1D contenant des sous-sections de tableaux,
    ou chaque tableau interne contient les éléments du tableau 2D.
    Lorsque vous passez un tableau 2D statique en tant que paramètre à une fonction, il est passé en tant que pointeur.
    Il est cependant obligatoire d'indiquer la taille des sous-sections - donc la taille des colonnes.
*/

/*
    init Matrice
    DEF : Initialise les valeurs d'une matrice d'entier avec une valeur spécifique
    PARAMETRES :    matrice[][NB_COLONNE] : La matrice d'entier à initialiser
                    nbLigne : Le nombre de ligne de la matrice
                    nbColonne : Le nombre de colonne de la matrice
                    valeur : La valeur d'initialisation
    RETOUR :        Aucun
    SPÉCIFICATION : Aucun
*/
void initMatrice(int matrice[][NB_COLONNE], int nbLigne, int nbColonne, int valeur);

/*
    init Matrice Alea
    DEF : Initialise les valeurs d'une matrice d'entier avec des nombres aléatoires
    PARAMETRES :    matrice[][NB_COLONNE] : La matrice d'entier à initialiser
                    nbLigne : Le nombre de ligne de la matrice
                    nbColonne : Le nombre de colonne de la matrice
    RETOUR :        Aucun
    SPÉCIFICATION : Le générateur aléatoire doit être initialisé
*/
void initMatriceAlea(int matrice[][NB_COLONNE], int nbLigne, int nbColonne);

/*
    afficher Matrice
    DEF : Affiche la matrice reçu dans la console
    PARAMETRES :    matrice[][NB_COLONNE] : La matrice d'entier à afficher
                    nbLigne : Le nombre de ligne de la matrice
                    nbColonne : Le nombre de colonne de la matrice
    RETOUR :        Aucun
    SPÉCIFICATION : Aucun
*/
void afficherMatrice(int matrice[][NB_COLONNE], int nbLigne, int nbColonne);

/*
    afficher Adresse Matrice
    DEF : Affiche la matrice l'adresse des cases d'une matrice dans la console
    PARAMETRES :    matrice[][NB_COLONNE] : La matrice d'entier à afficher les adresses
                    nbLigne : Le nombre de ligne de la matrice
                    nbColonne : Le nombre de colonne de la matrice
    RETOUR :        Aucun
    SPÉCIFICATION : Aucun
*/
void afficherAdresseMatrice(int matrice[][NB_COLONNE], int nbLigne, int nbColonne);

/*
    ENTIER ALEA
    Fonction qui retourne un entier aleatoire dans un intervalle donné.

    PARAMETRES :	min, valeur minimum de l'intervalle
                    max, valeur maximum de l'intervalle
    RETOUR :		un entier aléatoire
    SPÉCIFICATION :
*/
int entierAlea (int min, int max);

/****************************************************************************************
*                           DÉFINITION DU PROGRAMME PRINCIPALE                          *
****************************************************************************************/
int main(void)
{
    srand(time(NULL));	                // Initialisation du générateur aléatoire
    setbuf(stdout, 0);        // Permet d'afficher les printfs en mode débug avec Clion

    // Déclaration d'un tableau statique
    int uneMatrice[NB_LIGNE][NB_COLONNE];

    // Initialisation avec une valeur spécifique la valeur 22
    initMatrice(uneMatrice,NB_LIGNE,NB_COLONNE, 22);

    // Modifie une case de la matrice
    uneMatrice[1][3] = 33;

    // Affiche la matrice initialisée
    afficherMatrice(uneMatrice,NB_LIGNE,NB_COLONNE);


    // Initialisation de la matrice avec des valeurs aléatoires
    initMatriceAlea(uneMatrice,NB_LIGNE,NB_COLONNE);
    // Affiche la matrice initialisée avec des valeurs aéatoires
    afficherMatrice(uneMatrice,NB_LIGNE,NB_COLONNE);

    // On affiche les adresses de chaque case de la matrice
    afficherAdresseMatrice(uneMatrice,NB_LIGNE,NB_COLONNE);

    return EXIT_SUCCESS;  						// Permets de terminer le programme proprement
}


/****************************************************************************************
/									DEFINITION DES FONCTIONS							*
****************************************************************************************/

/*
    init Matrice
    DEF : Initialise les valeurs d'une matrice d'entier avec une valeur spécifique
    PARAMETRES :    matrice[][NB_COLONNE] : La matrice d'entier à initialiser
                    nbLigne : Le nombre de ligne de la matrice
                    nbColonne : Le nombre de colonne de la matrice
                    valeur : La valeur d'initialisation
    RETOUR :        Aucun
    SPÉCIFICATION : Aucun
*/
void initMatrice(int matrice[][NB_COLONNE], int nbLigne, int nbColonne, int valeur) {

    int i;            //Itérateur des lignes
    int j;            //Itérateur des colonnes

    // Pour chaque ligne de la matrice
    for (i = 0; i < nbLigne; i++) {

        // Pour chaque colonne de la matrice
        for (j = 0; j < nbColonne; j++) {

            matrice[i][j] = valeur;    // Pour chaque case de la matrice on attribut la valeur
        }
    }
}

/*
    init Matrice Alea
    DEF : Initialise les valeurs d'une matrice d'entier avec des nombres aléatoires
    PARAMETRES :    matrice[][NB_COLONNE] : La matrice d'entier à initialiser
                    nbLigne : Le nombre de ligne de la matrice
                    nbColonne : Le nombre de colonne de la matrice
    RETOUR :        Aucun
    SPÉCIFICATION : Le générateur aléatoire doit être initialisé
*/
void initMatriceAlea(int matrice[][NB_COLONNE], int nbLigne, int nbColonne) {

    int i;            //Itérateur des lignes
    int j;            //Itérateur des colonnes

    // Pour chaque ligne de la matrice
    for (i = 0; i < nbLigne; i++) {

        // Pour chaque colonne de la matrice
        for (j = 0; j < nbColonne; j++) {

            matrice[i][j] = entierAlea(VALEUR_MIN,VALEUR_MAX );    // Pour chaque case de la matrice on attribut une valeur aléatoire
        }
    }
}


/*
    afficher Matrice
    DEF : Affiche la matrice reçu dans la console
    PARAMETRES :    matrice[][NB_COLONNE] : La matrice d'entier à afficher
                    nbLigne : Le nombre de ligne de la matrice
                    nbColonne : Le nombre de colonne de la matrice
    RETOUR :        Aucun
    SPÉCIFICATION : Aucun
*/
void afficherMatrice(int matrice[][NB_COLONNE], int nbLigne, int nbColonne) {

    int ligne;        //Itérateur des lignes
    int colonne;      //Itérateur des colonnes

    // Pour chaque ligne de la matrice
    for (ligne = 0; ligne < nbLigne; ligne++) {
        // Pour chaque colonne de la matrice
        for (colonne = 0; colonne < nbColonne; colonne++) {

            printf("%i\t", matrice[ligne][colonne]);        // Affiche la valeur de la case spécifique
        }
        printf("\n");                                 // Une fois les colonnes d'une ligne affichée fait un saut de ligne
    }                                                       // pour représenter les valeurs sous forme de matrice

    printf("\n");
}

/*
    afficher Adresse Matrice
    DEF : Affiche la matrice l'adresse des cases d'une matrice dans la console
    PARAMETRES :    matrice[][NB_COLONNE] : La matrice d'entier à afficher les adresses
                    nbLigne : Le nombre de ligne de la matrice
                    nbColonne : Le nombre de colonne de la matrice
    RETOUR :        Aucun
    SPÉCIFICATION : Aucun
*/
void afficherAdresseMatrice(int matrice[][NB_COLONNE], int nbLigne, int nbColonne) {

    int ligne;        //Itérateur des lignes
    int colonne;      //Itérateur des colonnes

    // Pour chaque ligne de la matrice
    for (ligne = 0; ligne < nbLigne; ligne++) {
        // Pour chaque colonne de la matrice
        for (colonne = 0; colonne < nbColonne; colonne++) {

            printf("%p\t", &matrice[ligne][colonne]);       // Affiche l'adresse de la case spécifique
        }
        printf("\n");                                       // Une fois les colonnes d'une ligne affichée fait un saut de ligne
    }                                                             // pour représenter les valeurs sous forme de matrice
    printf("\n");
}

/*
    entier alea
    DEF : Fonction qui retourne un entier aleatoire dans un intervalle donné.
    PARAMETRES :	min, valeur minimum de l'intervalle
                    max, valeur maximum de l'intervalle
    RETOUR :		un entier aléatoire
    SPÉCIFICATION :
*/
int entierAlea (int min, int max)
{
    return min + (int)(rand() / (RAND_MAX + 0.005) * (max - min + 1));
}
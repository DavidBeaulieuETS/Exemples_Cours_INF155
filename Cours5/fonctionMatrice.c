/*****************************************************************************************
    Par        : David Beaulieu
    Revise le  : H2025
    Fichier    : fonctionMatrice.c
    Objectifs  : Démonstration de fonctions qui manipule des tableaux 2d (Matrice)
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

// Permet de sélectioner l'exemple à compiler dans le main
// 1 = Le premier exemple avec la comparaison des matrices
// 2 = Le deuxième exemple avec la sélection de valeur dans une matrice
#define EXEMPLE_COMPILER 2

// Taille de matrice de démonstration
#define NB_LIGNE      5
#define NB_COLONNE    4

// Intervalle de valeur attribué à la matrice
#define VALEUR_MIN    -10
#define VALEUR_MAX    10

/****************************************************************************************
*								DÉCLARATION DES FONCTIONS								*
****************************************************************************************/

/*
    Déclaration de fonction
    En C, un tableau 2D (matrice) statique est défini comme un tableau 1D contenant des sous-sections de tableaux,
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
    copierTableau
    DEF : Copie les valeurs d'un tableau source dans un tableau destination
    PARAMETRES :    tableauSrc[] : Le tableau à copier
                    tableauDest[] : Le tableau qui recevra les valeurs à copier
                    nbElement : La taille des deux tableaux
    RETOUR :        Aucun
    SPÉCIFICATION : Les deux tableaux doivent être définit avec la même taille
*/
void copierTableau(int tableauSrc[], int tableauDest[], long nbElement);


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
    afficher tableau
    DEF : Affiche les valeurs d'un tableau 1D d'entier dans la console
    PARAMETRES :    tab[] : Le tableau à afficher
                    nbElement : Le nombre d'élément du tableau
    RETOUR :        Aucun
    SPÉCIFICATION : Aucun
*/
void afficherTableau(int tab [], int nbElement);

/*
    ENTIER ALEA
    Fonction qui retourne un entier aleatoire dans un intervalle donné.

    PARAMETRES :	min, valeur minimum de l'intervalle
                    max, valeur maximum de l'intervalle
    RETOUR :		un entier aléatoire
    SPÉCIFICATION :
*/
int entierAlea (int min, int max);

/*
    egalité matrice
    DEF : Valide si 2 matrices sont identiques ou non
    PARAMETRES :    matriceA[][NB_COLONNE] : La première matrice à comparer
                    matriceB[][NB_COLONNE] : La deuxième matrice à comparer
                    nbLigne : Le nombre de ligne des matrices
                    nbColonne : Le nombre de colonne des matrices
    RETOUR :        1 si les matrice sont identiques, 0 sinon
    SPÉCIFICATION : On présume que les 2 matrices on la même taille
*/
int egaliteMatrice(int matriceA[][NB_COLONNE],int matriceB[][NB_COLONNE], int nbLigne, int nbColonne);

/*
    selection valeur
    DEF : Permet de sélectioner des valeurs dans une matrice selon une valeur limite inférieur.
          La fonction retourne un tableu 1D contenant ces valeurs, ansi que le nombre de valeur sélectionée
    PARAMETRES :    matrice[][NB_COLONNE] : La matrice d'entier à afficher les adresses
                    valeursSelection[] : Un tableau 1D qui contiendra les valeurs de la matrice sélectionées
                    nbLigne : Le nombre de ligne de la matrice
                    nbColonne : Le nombre de colonne de la matrice
                    valeurLimite : La limite inférieur des valeurs à sélectioner
                    taille : La référence de la varaiable qui contiendra la taille du tableau 1d
    RETOUR :        Aucun
    SPÉCIFICATION : On présume que le tableau 1D sera de taille nbLigne * nbColonne
*/
void selectionValeur(int matrice[][NB_COLONNE], int valeursSelection [], int nbLigne, int nbColonne, int valeurLimite,int * taille);

/****************************************************************************************
*                           DÉFINITION DU PROGRAMME PRINCIPALE                          *
****************************************************************************************/
int main(void)
{
    srand(time(NULL));	                // Initialisation du générateur aléatoire
    setbuf(stdout, 0);        // Permet d'afficher les printfs en mode débug avec Clion

    // Exemple 1 - Comparaison de matrice
#if (EXEMPLE_COMPILER == 1)

    // Déclaration des matrice de même taille
    int uneMatrice[NB_LIGNE][NB_COLONNE];
    int uneAutreMatrice[NB_LIGNE][NB_COLONNE];

    // On assigne la même valeur aux 2 matrices
    initMatrice(uneMatrice,NB_LIGNE,NB_COLONNE,18);
    initMatrice(uneAutreMatrice,NB_LIGNE,NB_COLONNE,18);

    // Ceci est une erreur pour copier une matrice en C
    // uneAutreMatrice = uneMatrice;

    // change une valeur dans une des matrice
    // uneMatrice[2][3] = 0;

    // Ceci est une erreur pour comparer des matrices
    // if (uneAutreMatrice == uneMatrice) {


    if (egaliteMatrice (uneMatrice,uneAutreMatrice,NB_LIGNE,NB_COLONNE) == 1){
      printf("Les matrices sont identiques !\n");
    }
    else {
        printf("Les matrices ne sont pas identiques !\n");
    }

#endif

    // Exemple 2 - Sélection de valeur
#if (EXEMPLE_COMPILER == 2)

    // Déclaration des variables
    int uneMatrice[NB_LIGNE][NB_COLONNE];                // Matrice contenant les valeurs à sélectioner
    int tableauValeurSelection[NB_LIGNE * NB_COLONNE];   // Tableau 1D qui contient uniquement les valeurs sélectionées
    int nbValeurs;                                       // Le nombre de valeur sélectionées

    // Initialisation de la matrice
    initMatriceAlea(uneMatrice,NB_LIGNE,NB_COLONNE);

    // Sélectione les valeurs dans la matrice qui sont plus grand qu'un valeur spécifique
    selectionValeur(uneMatrice,tableauValeurSelection,NB_LIGNE,NB_COLONNE,-11,&nbValeurs);

    // Affiche la matrice et le tableau 1D
    afficherMatrice(uneMatrice,NB_LIGNE,NB_COLONNE);
    afficherTableau(tableauValeurSelection, nbValeurs);
#endif

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
void initMatriceAlea(int matrice[][NB_COLONNE], int nbLigne, int nbColonne){

    int i;            //Itérateur des lignes
    int j;            //Itérateur des colonnes

    // Pour chaque ligne de la matrice
    for (i = 0; i < nbLigne; i++) {

        // Pour chaque colonne de la matrice
        for (j = 0; j < nbColonne; j++) {

            matrice[i][j] = entierAlea(VALEUR_MIN , VALEUR_MAX);    // Pour chaque case de la matrice on attribut une valeur aléatoire
        }
    }
}

/*
    copierTableau
    DEF : Copie les valeurs d'un tableau source dans un tableau destination
    PARAMETRES :    tableauSrc[] : Le tableau à copier
                    tableauDest[] : Le tableau qui recevra les valeurs à copier
                    nbElement : La taille des deux tableaux
    RETOUR :        Aucun
    SPÉCIFICATION : Les deux tableaux doivent être définit avec la même taille
*/
void copierTableau(int tableauSrc[], int tableauDest[], long nbElement){

    long i;                                    // Itérateur des éléments du tableau
    for (i = 0; i < nbElement; i++) {

        tableauDest[i] = tableauSrc[i];        // Copie valeur par valeur les étéments du tableau
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
    afficher tableau
    DEF : Affiche les valeurs d'un tableau 1D d'entier dans la console
    PARAMETRES :    tab[] : Le tableau à afficher
                    nbElement : Le nombre d'élément du tableau
    RETOUR :        Aucun
    SPÉCIFICATION : Aucun
*/
void afficherTableau(int tab [], int nbElement){

  int i;    // Itérateur des éléments du tableau

  for (i = 0; i < nbElement; ++i){
    printf("%i\t", tab[i]);
  }
    printf("\n");
}

/*
    entier alea
    DEF : Fonction qui retourne un entier aleatoire dans un intervalle donné.
    PARAMETRES :	min : valeur minimum de l'intervalle
                    max : valeur maximum de l'intervalle
    RETOUR :		un entier aléatoire
    SPÉCIFICATION :
*/
int entierAlea (int min, int max)
{
    return min + (int)(rand() / (RAND_MAX + 0.005) * (max - min + 1));
}

/*
    egalité matrice
    DEF : Valide si 2 matrices sont identiques ou non
    PARAMETRES :    matriceA[][NB_COLONNE] : La première matrice à comparer
                    matriceB[][NB_COLONNE] : La deuxième matrice à comparer
                    nbLigne : Le nombre de ligne des matrices
                    nbColonne : Le nombre de colonne des matrices
    RETOUR :        1 si les matrice sont identiques, 0 sinon
    SPÉCIFICATION : On présume que les 2 matrices on la même taille
*/
int egaliteMatrice(int matriceA[][NB_COLONNE],int matriceB[][NB_COLONNE], int nbLigne, int nbColonne){

    int i;            //Itérateur des lignes
    int j;            //Itérateur des colonnes
    int idem;         // 1 si les matrices sont identique 0 sinon

    idem = 1;         // On présume que les matrice sont identique

    // Pour chaque ligne de la matrice
    for (i = 0; i < nbLigne; i++) {

        // Pour chaque colonne de la matrice
        for (j = 0; j < nbColonne; j++) {

            // Si on trouve un élément différent les matrice ne sont pas identique
            if (matriceA[i][j] != matriceB[i][j]){
              idem = 0;
            }

        }
    }
    return idem;
}

/*
    selection valeur
    DEF : Permet de sélectioner des valeurs dans une matrice qui sont plus grand ou égale à une valeur limite inférieur.
          La fonction retourne un tableu 1D contenant ces valeurs, ansi que le nombre de valeur sélectionée
    PARAMETRES :    matrice[][NB_COLONNE] : La matrice d'entier à afficher les adresses
                    valeursSelection[] : Un tableau 1D qui contiendra les valeurs de la matrice sélectionées
                    nbLigne : Le nombre de ligne de la matrice
                    nbColonne : Le nombre de colonne de la matrice
                    valeurLimite : La limite inférieur des valeurs à sélectioner
                    taille : La référence de la varaiable qui contiendra la taille du tableau 1d
    RETOUR :        Aucun
    SPÉCIFICATION : On présume que le tableau 1D sera de taille nbLigne * nbColonne
*/
void selectionValeur(int matrice[][NB_COLONNE], int valeursSelection [], int nbLigne, int nbColonne, int valeurLimite,int * taille){

    int i;            //Itérateur des lignes
    int j;            //Itérateur des colonnes

    *taille = 0;      //Initialise la taille du tableau 1D à 0;

    // Pour chaque ligne de la matrice
    for (i = 0; i < nbLigne; i++) {

        // Pour chaque colonne de la matrice
        for (j = 0; j < nbColonne; j++) {

            // Si on trouve un élément qui est plus grand ou égale de la valeur limite inférieur
            if (matrice[i][j] >= valeurLimite){

                valeursSelection[*taille] = matrice[i][j];    // Ajoute au tableau 1D la valeur trouvé
                (*taille) += 1;                               // Incrémente la taille du tableau
            }
        }
    }
}
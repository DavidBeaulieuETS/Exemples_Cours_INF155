/*****************************************************************************************
    Par        : David Beaulieu
    Revise le  : H2025
    Fichier    : algoTris.c
    Objectifs  : Démonstration des algorithme de tris
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
// Permet de sélectioner le tri utilisée dans l'exemple
// 1 - tri par sélection
// 2 - tri par insertion
// 3 - tri bulle
#define TRI_UTILISER 3

// Permet d'afficher toute les itérations d'un tri
// 0 = Aucun affichage
// 1 = affichage est effectué
#define AFFICHAGE_ITERATION  1

// Nombre d'élément des tableaux 1D à trier
#define NB_ELEMENT 10

// Intervalle des valeurs contenues dans les tableaux
#define VALEUR_MIN 1
#define VALEUR_MAX 100

/****************************************************************************************
*								DÉCLARATION DES FONCTIONS								*
****************************************************************************************/
/*
    tri Selection
    DEF : Tri un tableau 1D d'entier avec l'algorithme du tri par sélection
    PARAMETRES :    tableau[] : Le tableau à trier
                    taille : La taille du tableau à trier
    RETOUR :        Aucun
    SPÉCIFICATION : Aucune
*/
void triSelection(int tableau[], long taille);

/*
    tri Insertion
    DEF : Tri un tableau 1D d'entier avec l'algorithme du tri par insertion
    PARAMETRES :    tableau[] : Le tableau à trier
                    taille : La taille du tableau à trier
    RETOUR :        Aucun
    SPÉCIFICATION : Aucune
*/
void triInsersion(int tableau[], long taille);

/*
    tri Bulle
    DEF : Tri un tableau 1D d'entier avec l'algorithme du tri bulle
    PARAMETRES :    tableau[] : Le tableau à trier
                    taille : La taille du tableau à trier
    RETOUR :        Aucun
    SPÉCIFICATION : Aucune
*/
void triBulle(int tableau[], long taille);

/*
    remplirTableauAlea
    DEF : Initialise les valeurs d'une tableau 1D d'entier avec des nombres aléatoires
    PARAMETRES :    tableau[] : Le tableau à initialiser
                    nbElement : La taille du tableau à initialiser
                    min : La valeur minimum des valeurs aléatoires générées
                    max : La valeur maximum des valeurs aléatoires générées
    RETOUR :        Aucun
    SPÉCIFICATION : Le générateur aléatoire doit être initialisé
*/
void remplirTableauAlea(int tableau[], long nbElement, int min, int max);

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
    afficher tableau
    DEF : Affiche les valeurs d'un tableau 1D d'entier dans la console
    PARAMETRES :    tab[] : Le tableau à afficher
                    nbElement : Le nombre d'élément du tableau
    RETOUR :        Aucun
    SPÉCIFICATION : Aucune
*/
void afficherTableau(int tab [], long nbElement);

/*
    permuter entier
    Fonction qui recoit deux référence d'entier et en permute le contenue
    PARAMETRES :	entierA, référence du premier entier à permuter
                    entierA, référence du premier entier à permuter
    RETOUR :		Aucun
    SPÉCIFICATION : Aucune
*/
void permuterEntier(int * entierA, int * entierB);

/*
    entier alea
    Fonction qui retourne un entier aleatoire dans un intervalle donné.
    PARAMETRES :	min, valeur minimum de l'intervalle
                    max, valeur maximum de l'intervalle
    RETOUR :		un entier aléatoire
    SPÉCIFICATION : Aucune
*/
int entierAlea (int min, int max);

/****************************************************************************************
*                           DÉFINITION DU PROGRAMME PRINCIPALE                          *
****************************************************************************************/
int main(void) {

    srand(time(NULL));	                // Initialisation du générateur aléatoire
    setbuf(stdout, 0);        // Permet d'afficher les printfs en mode débug avec Clion

    int tableauTest[NB_ELEMENT];        // Tableau qui servira de test au tri

    // Initialise le tableau avec des valeur aléatoire
    remplirTableauAlea(tableauTest,NB_ELEMENT,VALEUR_MIN,VALEUR_MAX);

    // Affiche le tableau non trié
    afficherTableau(tableauTest,NB_ELEMENT);

    // Tri le tableau selon l'algorithme sélectioné
    #if TRI_UTILISER == 1

        triSelection(tableauTest,NB_ELEMENT);
    #elif TRI_UTILISER == 2

        triInsersion(tableauTest,NB_ELEMENT);
    #elif TRI_UTILISER == 3

        triBulle(tableauTest,NB_ELEMENT);
    #endif

    // Affiche le tableau trié
    afficherTableau(tableauTest,NB_ELEMENT);

    return EXIT_SUCCESS;
}



/****************************************************************************************
/									DEFINITION DES FONCTIONS							*
****************************************************************************************/
/*
    tri Selection
    DEF : Tri un tableau 1D d'entier avec l'algorithme du tri par sélection
    PARAMETRES :    tableau[] : Le tableau à trier
                    taille : La taille du tableau à trier
    RETOUR :        Aucun
    SPÉCIFICATION : Aucune
*/
void triSelection(int tableau[], long taille) {

    long i;
    long j;
    long positionMin;

    // Parcours les éléments du tableau
    for (i = 0; i < taille - 1; i++) {

        // Initialise la valeur min avec l’élément courant
        positionMin = i;

        // Cherche le minimum dans le segment supérieur du tableau non trié
        for (j = i + 1; j < taille; j++) {

            // Si une valeur plus petit est trouvée on la remplace
            if (tableau[j] < tableau[positionMin]) {
                positionMin = j;
            }
        }

        // Permute la valeur min trouvée avec l’élément courant
        permuterEntier(&tableau[i],&tableau[positionMin]);

        // Ceci n'est pas nécessaire au tri, cet affichage est pour la démonstration
        #if AFFICHAGE_ITERATION == 1
            afficherTableau(tableau,taille);
        #endif
    }
}

/*
    tri Insertion
    DEF : Tri un tableau 1D d'entier avec l'algorithme du tri par insertion
    PARAMETRES :    tableau[] : Le tableau à trier
                    taille : La taille du tableau à trier
    RETOUR :        Aucun
    SPÉCIFICATION : Aucune
*/
void triInsersion(int tableau[], long taille) {

    long i;                //Itérateur de la section
    long j;                //Itérateur de la section
    int valeurInsertion;   //Valeur à insérer

    // Parcours du tableau à trier
    // Débute à 1 parceque on considère l'élément 0 comme trié
    for (i = 1; i < taille; i++) {

        valeurInsertion = tableau[i];    // Conserve en mémoire la valeur de la position i à inséré
        j = i - 1;                       // Initialise l'itérateur d'insertion (j) à la position précédente de (i)

        // Tanque la position de l'insertion n'est pas trouvé et que on est dans le tableau
        while (j >= 0 && tableau[j] > valeurInsertion) {

            tableau[j + 1] = tableau[j];    // Décale la valeur de la position j vers la droite du tableau
            j--;                            // Décrémente l'itérateur j
        }

        // Insère la valeur à insérer courante dans le tableau à la position j + 1
        // Le + 1 vient du fait que la boucle précédente arrête quand la valeur est égale ou plus petite ou
        // que l'itérateur j = -1
        tableau[j + 1] = valeurInsertion;

        // Ceci n'est pas nécessaire au tri, cet affichage est pour la démonstration
        #if AFFICHAGE_ITERATION == 1
            afficherTableau(tableau,taille);
        #endif
    }
}

/*
    tri Bulle
    DEF : Tri un tableau 1D d'entier avec l'algorithme du tri bulle
    PARAMETRES :    tableau[] : Le tableau à trier
                    taille : La taille du tableau à trier
    RETOUR :        Aucun
    SPÉCIFICATION : Aucune
*/
void triBulle(int tableau[], long taille) {

    long i;
    long j;
    int tempo;
    
    // Pour tous les éléments triés du tableau en commençant à la fin
    for (i = taille - 1; i >= 0; i--) {
        
        // Pour les éléments du tableau non triés en commençant au début
        for (j = 0; j < i; j++) {
            
            // Si l'élément suivant est plus grand que l'élément courant
            if (tableau[j] > tableau[j + 1]) {
                // Permute l'élément courant avec l'élément suivant
                permuterEntier(&tableau[j],&tableau[j + 1]);

                // Ceci n'est pas nécessaire au tri, cet affichage est pour la démonstration
                #if AFFICHAGE_ITERATION == 1
                    afficherTableau(tableau,taille);
                #endif
            }
        }
    }
    // Inspiration : https://www.youtube.com/watch?v=lyZQPjUT5B4&ab_channel=AlgoRythmics
}

/*
    remplirTableauAlea
    DEF : Initialise les valeurs d'une tableau 1D d'entier avec des nombres aléatoires
    PARAMETRES :    tableau[] : Le tableau à initialiser
                    nbElement : La taille du tableau à initialiser
                    min : La valeur minimum des valeurs aléatoires générées
                    max : La valeur maximum des valeurs aléatoires générées
    RETOUR :        Aucun
    SPÉCIFICATION : Le générateur aléatoire doit être initialisé
*/
void remplirTableauAlea(int tableau[], long nbElement, int min, int max) {

    long i;                                   // Itérateur des éléments du tableau
    for (i = 0; i < nbElement; i++) {
        tableau[i] = entierAlea(min, max);    // Pour chaque case du tableau on attribut la valeur aléatpoire
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
    afficher tableau
    DEF : Affiche les valeurs d'un tableau 1D d'entier dans la console
    PARAMETRES :    tab[] : Le tableau à afficher
                    nbElement : Le nombre d'élément du tableau
    RETOUR :        Aucun
    SPÉCIFICATION : Aucun
*/
void afficherTableau(int tab [], long nbElement){

    long i;    // Itérateur des éléments du tableau

    for (i = 0; i < nbElement; ++i){
        printf("%i\t", tab[i]);
    }
    printf("\n");
}

/*
    permuter entier
    Fonction qui recoit deux référence d'entier et en permute le contenue
    PARAMETRES :	entierA : référence du premier entier à permuter
                    entierA : référence du premier entier à permuter
    RETOUR :		Aucun
    SPÉCIFICATION : Aucune
*/
void permuterEntier(int * entierA, int * entierB){

  int tempo;     // Variable temporaire utile à la permutation

  // Effectue la permutation des contenues pointé par les références
  tempo = *entierA;
  *entierA = *entierB;
  *entierB = tempo;
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
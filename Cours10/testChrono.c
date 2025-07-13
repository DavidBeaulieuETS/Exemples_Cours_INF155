/*****************************************************************************************
Par        : David Beaulieu
    Revise le  :
    Fichier    :
    Objectifs  :
    Note	   :
*****************************************************************************************/

/****************************************************************************************
*                            AJOUT DES MODULES ET LIBRAIRIES                            *
****************************************************************************************/
#include <stdlib.h>		// Librairie Standard
#include <stdio.h>		// Librairie Entrée - Sortie
#include <time.h>		// Librairie de gestion du temps, inclut lafonction time()
#include <windows.h>    // Librairie des commandes de windows
#include "t_chrono.h"  // Module d'implémentation d'un chronomètre



#define AFFICHE_TOK 0   //Affiche les temps des itérations dans le tri bulles
                        // 1 les tok du chrono sont affichés, 0 les tok ne sont pas affiché
/****************************************************************************************
*								DÉCLARATION DES FONCTIONS								*
****************************************************************************************/

/*
    NOM         : initTableauAleatoire
    DEF         : Alloue et initialise un tableau d'entiers avec des valeurs aléatoires dans [0, maxValeur]
    PARAMETRES  :
        - taille    : nombre d'éléments à allouer et remplir
        - maxValeur : valeur maximale possible générée
    RETOUR      : pointeur vers le tableau alloué et rempli, ou NULL si échec d'allocation
*/
int * initTableauAleatoire(int taille, int maxValeur);

/*
    NOM         : triBulles
    DEF         : Trie un tableau d'entiers en ordre croissant selon l'algorithme du tri à bulles
    PARAMETRES  :
        - tab    : pointeur vers le tableau à trier
        - taille : nombre d'éléments dans le tableau
    RETOUR      : aucun
*/
void triBulles(int* tab, int taille, t_chrono chrono);

/****************************************************************************************
*                           DÉFINITION DU PROGRAMME PRINCIPALE                          *
****************************************************************************************/
int main() {

    SetConsoleOutputCP(CP_UTF8);        // Définit l'encodage de sortie de la console à UTF-8
    setbuf(stdout, 0);		            // Permets d'afficher les printf en mode débug avec Clion
    srand((unsigned)time(NULL));        // Initialisation du générateur aléatoire

    int taille = 1000000;        // Taille du tableau (modulable)                 **Pour référence :
    int maxValeur = 100000;      // Valeur max aléatoire                            Début du tri à bulles sur 1000000 éléments...
    int * tableau;               // Tableau à tirer                                 Tri terminé.
                                                                                //  Temps écoulé : 2187.832000 secondes
    // Création et remplissage aléatoire du tableau
    tableau = initTableauAleatoire(taille, maxValeur);

    // Création et initialisation du chrono
    t_chrono chrono = initChrono();

    if (tableau == NULL || chrono == NULL){
        printf("** Erreur d'allocation !! \n");
        return EXIT_FAILURE;
    }

    printf("Début du tri à bulles sur %d éléments...\n", taille);
    startChrono(chrono);

    triBulles(tableau, taille, chrono);

    stopChrono(chrono);
    printf("Tri terminé.\n");

    // Affichage du temps mesuré
    printf("Temps écoulé : %.6f secondes\n", getChrono(chrono));

    // Nettoyage
    freeChrono(chrono);
    free(tableau);

    return EXIT_SUCCESS;
}


/*
    NOM         : initTableauAleatoire
    DEF         : Alloue et initialise un tableau d'entiers avec des valeurs aléatoires dans [0, maxValeur]
    PARAMETRES  :
        - taille    : nombre d'éléments à allouer et remplir
        - maxValeur : valeur maximale possible générée
    RETOUR      : pointeur vers le tableau alloué et rempli, ou NULL si échec d'allocation
    SPÉCIFICATION :
        - L'utilisateur doit libérer la mémoire retournée
        - Chaque élément est initialisé indépendamment avec rand() % (maxValeur + 1)
*/
int * initTableauAleatoire(int taille, int maxValeur) {
    // Allocation dynamique d'un tableau d'entiers de taille 'taille'
    int* tableau = malloc(taille * sizeof(int));

    // Vérification que l'allocation a réussi
    if (tableau != NULL) {
        // Initialisation de chaque élément avec une valeur aléatoire dans [0, maxValeur]
        for (int i = 0; i < taille; i++) {
            tableau[i] = rand() % (maxValeur + 1);
        }
    }

    // Retourne le pointeur vers le tableau alloué (ou NULL en cas d'échec)
    return tableau;
}

/*
    NOM         : triBulles
    DEF         : Trie un tableau d'entiers en ordre croissant selon l'algorithme du tri à bulles
    PARAMETRES  :
        - tab    : pointeur vers le tableau à trier
        - taille : nombre d'éléments dans le tableau
    RETOUR      : aucun
    SPÉCIFICATION :
        - Implémentation classique du tri à bulles en O(n²)
        - Modifie le tableau en place
*/
void triBulles(int* tab, int taille, t_chrono chrono) {
    int temp;
    for (int i = 0; i < taille - 1; i++) {
        for (int j = 0; j < taille - 1 - i; j++) {
            if (tab[j] > tab[j + 1]) {
                temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
            }
        }
        if (AFFICHE_TOK) {
            printf(" .. %.6f .. \n", tocChrono(chrono));
        }

    }
}

// Affiche un tableau d'entiers
void afficherTableau(int* tab, int taille) {
    for (int i = 0; i < taille; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");
}

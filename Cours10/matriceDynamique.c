/****************************************************************************************
    Auteur  : David Beaulieu
    Date    : 24 mai 2014
    Fichier : 2_tab2d_dynamique.c

    Ce module contient un exemple afin de montrer comment d�clarer, coder et utiliser
    les tableau 2D Dynamique

    NOTE DE L'ENSEIGNANT : Les commentaires de ce module sont des explications, ils ne
                           repr�sentent pas vraiment ce qui est attendu de vous lors
                           de la remise de vos travaux pratiques.

*****************************************************************************************/
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/****************************************************************************************
*                               D�FINTION DES CONSTANTES                                *
****************************************************************************************/


/****************************************************************************************
*                               D�CLARATION DES FONCTIONS                               *
****************************************************************************************/


//
//  Prototype de fonction
//  On utilise le type ** pour repr�senter un tableau 2D dynamique


// Allocation de la m�moire du tableau selon la stat�gie 1 
// Cette strat�gie donnera un tableau 2D discontinue en m�moire
int** creer_matrice_S1(int nb_ligne, int nb_colonne);

// Allocation de la m�moire du tableau selon la stat�gie 2 
// Cette strat�gie donnera un tableau 2D continue en m�moire
int** creer_matrice_S2(int nb_ligne, int nb_colonne);

// Initialisation des valeurs d'un tableau 2D dynamique avec un valeur unique.
int** init_matrice_valeur(int** matrice, int nb_ligne, int nb_colonne, int valeur);

// Initialisation des valeurs d'un tableau 2D dynamique avec un valeur incr�mental (compteur).
int** init_matrice_indice(int** matrice, int nb_ligne, int nb_colonne);

// Affiche les valeurs d'un tableau 2D dynamique
void afficher_matrice(int** matrice, int nb_ligne, int nb_colonne);

// Affiche les adresses des cases d'un tableau 2D dynamique
void afficher_adresse_matrice(int** matrice, int nb_ligne, int nb_colonne);


/****************************************************************************************
*                           D�FINTION DU PRGORAMME PRINCIPALE                           *
****************************************************************************************/
int main(void)
{
    // D�claration des pointeurs ** 
    // Ne tableau n'existe pas en m�moire � ce point !!
    int** une_matrice = NULL;
    int** une_autre_matrice = NULL;

    // On cr�er un premier tableau 2d selon la strat�gie 1 - discontinue
    une_matrice = creer_matrice_S1(5, 4);

    // On cr�er un autre tableau 2d selon la strat�gie 2 - continue
    une_autre_matrice = creer_matrice_S2(3, 6);
  
     // On initialise les valeurs des deux tableau - attention au taille !
     une_matrice = init_matrice_indice(une_matrice, 5, 4);
     une_autre_matrice = init_matrice_valeur(une_autre_matrice, 3, 6, 777);

     // On affiche le premier tableau 2D discontinue
     printf("\nUn premier tableau : \n");
     afficher_matrice(une_matrice, 5, 4);
     printf("\nle meme tableau avec les adresses discontinues : \n");
     afficher_adresse_matrice(une_matrice, 5, 4);

     // On affiche le deuxi�me tableau 2D continue
     printf("\nUn deuxieme tableau : \n");
     afficher_matrice(une_autre_matrice, 3, 6);
     printf("\nle meme tableau avec les adresses continues : \n");
     afficher_adresse_matrice(une_autre_matrice, 3, 6);
}


// Allocation de la m�moire du tableau selon la stat�gie 1 
// Cette strat�gie donnera un tableau 2D discontinue en m�moire
int** creer_matrice_S1(int nb_ligne, int nb_colonne) {

    int** matrice = NULL;

    // Cr�ation du tableau des lignes
    matrice = (int**)malloc(nb_ligne * sizeof(int*));

    if (matrice != NULL) {

        // Cr�ation des tableau des colonnes
        for (int i = 0; i < nb_ligne; i++) {

            matrice[i] = (int*)malloc(nb_colonne * sizeof(int));

            if (matrice[i] == NULL) {
                return NULL;
            }
        }

    }
    else {
        return NULL;
    }

    return matrice;
}


// Allocation de la m�moire du tableau selon la stat�gie 2 
// Cette strat�gie donnera un tableau 2D continue en m�moire
int** creer_matrice_S2(int nb_ligne, int nb_colonne) {

    int* vecteur = NULL;
    int** matrice;

    matrice = (int**)malloc(nb_ligne * sizeof(int*));

    //On cr�er toute les case de la matrice de facon lin�aire.
    vecteur = (int*)malloc(nb_ligne * nb_colonne * sizeof(int));


    if (vecteur != NULL) {

        //On assigne la case de chaque d�but de ligne dans le tableau de la matrice
        for (int i = 0; i < nb_ligne; i++) {

            matrice[i] = &vecteur[i * nb_colonne];
        }
    }
    else {

        return NULL;
    }
    return matrice;
}

// Initialisation des valeurs d'un tableau 2D dynamique avec un valeur unique.
int** init_matrice_valeur(int** matrice, int nb_ligne, int nb_colonne, int valeur) {

    for (int i = 0; i < nb_ligne; i++) {

        for (int j = 0; j < nb_colonne; j++) {

            matrice[i][j] = valeur;
        }
    }
    return matrice;
}

// Initialisation des valeurs d'un tableau 2D dynamique avec un valeur incr�mental (compteur).
int** init_matrice_indice(int** matrice, int nb_ligne, int nb_colonne) {

    int indice = 1;

    for (int i = 0; i < nb_ligne; i++) {

        for (int j = 0; j < nb_colonne; j++) {

            matrice[i][j] = indice;
            indice++;
        }
    }
    return matrice;
}

// Affiche les valeurs d'un tableau 2D dynamique
void afficher_matrice(int** matrice, int nb_ligne, int nb_colonne) {

    for (int ligne = 0; ligne < nb_ligne; ligne++) {

        for (int colonne = 0; colonne < nb_colonne; colonne++) {

            printf("%i\t", matrice[ligne][colonne]);

        }
        printf("\n");
    }
}

// Affiche les adresses des cases d'un tableau 2D dynamique
void afficher_adresse_matrice(int** matrice, int nb_ligne, int nb_colonne) {

    for (int ligne = 0; ligne < nb_ligne; ligne++) {

        for (int colonne = 0; colonne < nb_colonne; colonne++) {

            printf("%p\t", &matrice[ligne][colonne]);
        }
        printf("\n");
    }
}
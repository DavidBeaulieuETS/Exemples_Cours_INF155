/****************************************************************************************
    Auteur  : David Beaulieu
    Date    : 24 mai 2014
    Fichier : matriceDynamique.c

    Ce module contient un exemple afin de montrer comment déclarer, coder et utiliser
    les tableau 2D Dynamique

    NOTE DE L'ENSEIGNANT : Les commentaires de ce module sont des explications, ils ne
                           représentent pas vraiment ce qui est attendu de vous lors
                           de la remise de vos travaux pratiques.

/****************************************************************************************
*                            AJOUT DES MODULES ET LIBRAIRIES                            *
****************************************************************************************/
#include <stdlib.h>		// Librairie Standard
#include <stdio.h>		// Librairie Entrée - Sortie
#include <windows.h>    // Librairie des commandes de windows

/****************************************************************************************
*								DÉCLARATION DES FONCTIONS								*
****************************************************************************************/
//
//  Note sur les prototypes de fonction
//  On utilise le type ** pour représenter un tableau 2D dynamique
//  On remarque que par rapport au tableau 2D statique l'entête de fonction n'a pas besoin
//  de la valeur de la taille en colonne

/*
    L'exemple suivant propose 2 stratégies d'initialisation dynamique de matrice
    S1 : Un tableau de int * de taille ligne, qui pointe vers des tableaux de int indépendant de taille colonne.
    S2 : Un grand tableau de int de taille ligne * colonne avec un tableau de int * de taille ligne qui pointe à
            chaque case de début de ligne dans le grand tableau de int.
*/


/*
    NOM	        : creerMatriceS1
    DESCRIPTION : Alloue dynamiquement une matrice d'entiers à deux dimensions,
                  de `nbLigne` lignes et `nbColonne` colonnes. Libère la mémoire en cas d'échec.
    PARAMETRES  :
        - nbLigne   : nombre de lignes à allouer.
        - nbColonne : nombre de colonnes par ligne.
    RETOUR      :
        - Un pointeur vers la matrice allouée (int**).
        - NULL si une allocation échoue.
*/
int ** creerMatriceS1(int nbLigne, int nbColonne);

/*
    NOM	        : libererMatriceS1
    DESCRIPTION : Libère toute la mémoire allouée pour une matrice d'entiers
                  créée avec la fonction creerMatriceS1, puis met le pointeur à NULL.
    PARAMETRES  :
        - matrice  : adresse du pointeur vers la matrice à libérer (int***).
        - nbLigne  : nombre de lignes allouées dans la matrice.
    RETOUR      : Aucun (void).
*/
void libererMatriceS1(int*** matrice, int nbLigne);

/*
    NOM         : creerMatriceS2
    DEF         : Alloue dynamiquement une matrice d'entiers de dimensions nbLigne x nbColonne
                  en utilisant une allocation contiguë pour les données (vecteur) et un tableau
                  de pointeurs vers le début de chaque ligne.
    PARAMETRES  :
        - nbLigne   : nombre de lignes de la matrice à créer
        - nbColonne : nombre de colonnes de la matrice à créer
    RETOUR      :
        - pointeur vers un tableau de pointeurs (int**) représentant la matrice
        - NULL si l'allocation mémoire échoue
*/
int** creerMatriceS2(int nbLigne, int nbColonne);

/*
    NOM         : libererMatriceS2
    DEF         : Libère la mémoire allouée pour une matrice créée par creerMatriceS2
    PARAMETRES  :
        - matrice : pointeur vers le tableau de pointeurs représentant la matrice
    RETOUR      : aucun
*/
void libererMatriceS2(int** matrice);

/*
    NOM         : initMatriceIndice
    DEF         : Initialise une matrice 2D dynamique avec des valeurs incrémentales
                  à partir de 1, en parcourant la matrice ligne par ligne.
    PARAMETRES  :
        - matrice  : pointeur vers le tableau de pointeurs représentant la matrice
        - nbLigne  : nombre de lignes de la matrice
        - nbColonne: nombre de colonnes de la matrice
    RETOUR         :  Aucun
*/
void initMatriceIndice(int** matrice, int nbLigne, int nbColonne);

/*
    NOM         : afficherMatrice
    DEF         : Affiche à la console les valeurs contenues dans une matrice 2D dynamique
                  formatées en tableau, avec des tabulations entre les éléments.
    PARAMETRES  :
        - matrice  : pointeur vers le tableau de pointeurs représentant la matrice
        - nbLigne  : nombre de lignes de la matrice
        - nbColonne: nombre de colonnes de la matrice
    RETOUR      : aucun
*/
void afficherMatrice(int** matrice, int nbLigne, int nbColonne);

/*
    NOM         : afficherAdresseMatrice
    DEF         : Affiche à la console les adresses mémoire des cases de la matrice 2D dynamique
                  afin de visualiser leur organisation en mémoire.
    PARAMETRES  :
        - matrice  : pointeur vers le tableau de pointeurs représentant la matrice
        - nbLigne  : nombre de lignes de la matrice
        - nbColonne: nombre de colonnes de la matrice
    RETOUR      : aucun
    SPÉCIFICATION :
*/
void afficherAdresseMatrice(int** matrice, int nbLigne, int nbColonne);



/****************************************************************************************
*                           DÉFINITION DU PROGRAMME PRINCIPALE                          *
****************************************************************************************/
int main(void)
{
    SetConsoleOutputCP(CP_UTF8);        // Définit l'encodage de sortie de la console à UTF-8
    setbuf(stdout, 0);		            // Permets d'afficher les printf en mode débug avec Clion

    // Déclaration des pointeurs **
    // La matrice n'existe pas en mémoire à ce point !!
    int** uneMatrice = NULL;
    int** uneAutreMatrice = NULL;

    // On créer une première matrice selon la stratégie 1 - discontinue
    uneMatrice = creerMatriceS1(5, 4);

    // On créer une autre matrice selon la stratégie 2 - contiguë
    uneAutreMatrice = creerMatriceS2(3, 5);
  
     // On initialise les valeurs des deux tableau - attention au taille !
     initMatriceIndice(uneMatrice, 5, 4);
     initMatriceIndice(uneAutreMatrice, 3, 5);


     // On affiche les infos de la première matrice discontinue en adresse
     printf("\n** Première matrice : \n");
     afficherMatrice(uneMatrice, 5, 4);
     printf("\n** Les adresses discontinues de la matrice :  \n");
     afficherAdresseMatrice(uneMatrice, 5, 4);

    // On affiche les infos de la deuxième matrice continue en adresse
     printf("\n** Deuxième matrice : \n");
     afficherMatrice(uneAutreMatrice, 3, 5);
     printf("\n** Les adresses continue de la matrice : \n");
     afficherAdresseMatrice(uneAutreMatrice, 3, 5);


     libererMatriceS1(&uneMatrice,5);
}

/****************************************************************************************
/									DÉFINITION DES FONCTIONS							*
****************************************************************************************/
/*
    NOM	        : creerMatriceS1
    DESCRIPTION : Alloue dynamiquement une matrice d'entiers à deux dimensions,
                  de `nbLigne` lignes et `nbColonne` colonnes. Libère la mémoire en cas d'échec.
    PARAMETRES  :
        - nbLigne   : nombre de lignes à allouer.
        - nbColonne : nombre de colonnes par ligne.
    RETOUR      :
        - Un pointeur vers la matrice allouée (int**).
        - NULL si une allocation échoue.
    SPÉCIFICATION :
        - Utilise un tableau de pointeurs pour représenter les lignes.
        - Chaque ligne est un tableau dynamique d'entiers.
        - En cas d'échec pendant l’allocation des lignes, libère la mémoire déjà allouée.
        - L’appelant est responsable de libérer la mémoire si la création réussit.
*/
int** creerMatriceS1(int nbLigne, int nbColonne) {

    int** matrice = NULL; // Pointeur vers la matrice (tableau de pointeurs)

    // Création du tableau de pointeurs vers chaque ligne
    matrice = (int**)malloc(nbLigne * sizeof(int*));

    // Vérifie si l'allocation des lignes a réussi
    if (matrice != NULL) {

        // Allocation de chaque ligne (tableau de colonnes)
        for (int i = 0; i < nbLigne; i++) {

            matrice[i] = (int*)malloc(nbColonne * sizeof(int));

            // Si une allocation de ligne échoue, on libère les lignes précédemment allouées
            if (matrice[i] == NULL) {
                for (int j = 0; j < i; j++) {
                    free(matrice[j]); // Libère chaque ligne déjà allouée
                }
                free(matrice); // Libère le tableau principal de pointeurs
                return NULL;   // Échec de malloc → on retourne NULL
            }
        }

    } else {
        return NULL; // Échec de malloc pour le tableau de lignes
    }

    return matrice; // Matrice allouée avec succès
}

/*
    NOM	        : libererMatriceS1
    DESCRIPTION : Libère toute la mémoire allouée pour une matrice d'entiers
                  créée avec la fonction creerMatriceS1, puis met le pointeur à NULL.
    PARAMETRES  :
        - matrice  : adresse du pointeur vers la matrice à libérer (int***).
        - nbLigne  : nombre de lignes allouées dans la matrice.
    RETOUR      : Aucun (void).
    SPÉCIFICATION :
        - Parcourt chaque ligne et libère son tableau.
        - Libère ensuite le tableau principal de pointeurs.
        - Met le pointeur de matrice à NULL pour éviter les accès invalides.
*/
void libererMatriceS1(int*** matrice, int nbLigne) {

    if (matrice != NULL && *matrice != NULL) {

        // Libération de chaque ligne allouée
        for (int i = 0; i < nbLigne; i++) {
            free((*matrice)[i]);
        }

        // Libération du tableau de pointeurs
        free(*matrice);

        // Mise à NULL du pointeur de la matrice
        *matrice = NULL;
    }
}

/*
    NOM         : creerMatriceS2
    DEF         : Alloue dynamiquement une matrice d'entiers de dimensions nbLigne x nbColonne
                  en utilisant une allocation contiguë pour les données (vecteur) et un tableau
                  de pointeurs vers le début de chaque ligne.
    PARAMETRES  :
        - nbLigne   : nombre de lignes de la matrice à créer
        - nbColonne : nombre de colonnes de la matrice à créer
    RETOUR      :
        - pointeur vers un tableau de pointeurs (int**) représentant la matrice
        - NULL si l'allocation mémoire échoue
    SPÉCIFICATION :
        - La fonction alloue un bloc mémoire unique pour toutes les données (optimisant la
          gestion mémoire et la localisation des accès)
        - Chaque élément matrice[i] pointe sur le début de la i-ème ligne dans ce bloc
        - En cas d'échec de l'allocation du bloc de données, retourne NULL
        - L'appelant est responsable de libérer la mémoire du vecteur et du tableau de pointeurs
          (attention, la fonction ne gère pas la libération)
*/
int** creerMatriceS2(int nbLigne, int nbColonne) {

    int* vecteur = NULL;
    int** matrice;

    matrice = (int**)malloc(nbLigne * sizeof(int*));  // allocation tableau de pointeurs pour chaque ligne

    // On crée toutes les cases de la matrice de façon linéaire dans un seul bloc mémoire contigu
    vecteur = (int*)malloc(nbLigne * nbColonne * sizeof(int));

    if (vecteur != NULL) {

        // On assigne à chaque pointeur de ligne l'adresse de son début dans le vecteur
        for (int i = 0; i < nbLigne; i++) {
            matrice[i] = &vecteur[i * nbColonne];
        }
    }
    else {
        // Allocation du vecteur échouée, on retourne NULL
        return NULL;
    }
    return matrice;
}

/*
    NOM         : libererMatriceS2
    DEF         : Libère la mémoire allouée pour une matrice créée par creerMatriceS2
    PARAMETRES  :
        - matrice : pointeur vers le tableau de pointeurs représentant la matrice
    RETOUR      : aucun
    SPÉCIFICATION :
        - Libère d’abord le bloc de données linéaires pointé par matrice[0]
        - Puis libère le tableau de pointeurs
        - Ne fait rien si matrice est NULL
*/
void libererMatriceS2(int** matrice) {
    if (matrice != NULL) {
        free(matrice[0]);  // libération du vecteur contigu
        free(matrice);     // libération du tableau de pointeurs
    }
}

/*
    NOM         : initMatriceIndice
    DEF         : Initialise une matrice 2D dynamique avec des valeurs incrémentales
                  à partir de 1, en parcourant la matrice ligne par ligne.
    PARAMETRES  :
        - matrice  : pointeur vers le tableau de pointeurs représentant la matrice
        - nbLigne  : nombre de lignes de la matrice
        - nbColonne: nombre de colonnes de la matrice
    RETOUR      : Aucun
    SPÉCIFICATION :
        - Remplit la matrice avec des valeurs successives (1, 2, 3, ...)
        - L'initialisation se fait en parcourant la matrice en ordre naturel (ligne-colonne)
*/
void initMatriceIndice(int** matrice, int nbLigne, int nbColonne) {

    int indice = 1;  // Compteur initialisé à 1

    // Parcours de chaque ligne
    for (int i = 0; i < nbLigne; i++) {

        // Parcours de chaque colonne dans la ligne courante
        for (int j = 0; j < nbColonne; j++) {

            matrice[i][j] = indice;  // Affecte la valeur courante à la case
            indice++;                // Incrémente le compteur pour la prochaine case
        }
    }
}

/*
    NOM         : afficherMatrice
    DEF         : Affiche à la console les valeurs contenues dans une matrice 2D dynamique
                  formatées en tableau, avec des tabulations entre les éléments.
    PARAMETRES  :
        - matrice  : pointeur vers le tableau de pointeurs représentant la matrice
        - nbLigne  : nombre de lignes de la matrice
        - nbColonne: nombre de colonnes de la matrice
    RETOUR      : aucun
    SPÉCIFICATION :
        - Affiche les valeurs ligne par ligne, chaque valeur séparée par une tabulation
        - Termine chaque ligne par un saut de ligne
*/
void afficherMatrice(int** matrice, int nbLigne, int nbColonne) {

    // Parcours de chaque ligne
    for (int ligne = 0; ligne < nbLigne; ligne++) {

        // Parcours de chaque colonne dans la ligne courante
        for (int colonne = 0; colonne < nbColonne; colonne++) {

            printf("%i\t", matrice[ligne][colonne]);  // Affiche la valeur avec une tabulation
        }
        printf("\n");  // Retour à la ligne après chaque ligne affichée
    }
}

/*
    NOM         : afficherAdresseMatrice
    DEF         : Affiche à la console les adresses mémoire des cases de la matrice 2D dynamique
                  afin de visualiser leur organisation en mémoire.
    PARAMETRES  :
        - matrice  : pointeur vers le tableau de pointeurs représentant la matrice
        - nbLigne  : nombre de lignes de la matrice
        - nbColonne: nombre de colonnes de la matrice
    RETOUR      : aucun
    SPÉCIFICATION :
        - Affiche les adresses des cases, séparées par des tabulations, ligne par ligne
        - Utile pour comprendre la disposition mémoire, surtout avec l’allocation contiguë S2
*/
void afficherAdresseMatrice(int** matrice, int nbLigne, int nbColonne) {

    // Parcours de chaque ligne
    for (int ligne = 0; ligne < nbLigne; ligne++) {

        // Parcours de chaque colonne dans la ligne courante
        for (int colonne = 0; colonne < nbColonne; colonne++) {

            // Affiche l'adresse mémoire de la case courante avec tabulation
            printf("%p\t", &matrice[ligne][colonne]);
        }
        printf("\n");  // Retour à la ligne après chaque ligne affichée
    }
}

/****************************************************************************************
    Auteur  : David Beaulieu
    Date    : 24 mai 2014
    Fichier : fonction_tableau.c
 
    Ce module contient un exemple afin de montrer comment déclarer, coder et utiliser
    les tableau et les fonctions.

    NOTE DE L'ENSEIGNANT : Les commentaires de ce module sont des explications, ils ne 
                           représentent pas vraiment ce qui est attendu de vous lors
                           de la remise de vos travaux pratiques.

*****************************************************************************************/
#include <stdlib.h>		// Librairie Standard
#include <stdio.h>		// Librairie Entrée - Sortie

/****************************************************************************************
*                               DÉFINITION DES CONSTANTES                               *
****************************************************************************************/
#define TAILLE_TABLEAU      5

/****************************************************************************************
*								DÉCLARATION DES FONCTIONS								*
****************************************************************************************/


//
//      Note sur les prototypes de fonction
//      On utilise les [] ou un pointeur * pour montrer que l'on reçoit un tableau.
//      On doit TOUJOURS passer la taille d'un tableau en paramètre.
//      On utilise JAMAIS une constante comme paramètre formel.
//


/*
    NOM	        : initialiserTableau
    DESCRIPTION : Alloue dynamiquement un tableau de `nbElement` entiers,
                  et initialise chaque case avec la valeur spécifiée.
    PARAMETRES  :
        - nbElement  : le nombre d’éléments à allouer dans le tableau.
        - valeur     : la valeur à assigner à chaque élément du tableau.
    RETOUR      :
        - Un pointeur vers le tableau nouvellement alloué et initialisé.
        - NULL si l’allocation échoue.
*/
int * initialiserTableau(int nbElement, int valeur);

/*
    NOM	        : copierTableau
    DESCRIPTION : Alloue dynamiquement un nouveau tableau d'entiers et copie
                  tous les éléments du tableau source dedans.
    PARAMETRES  :
        - tableauSource : pointeur vers le tableau d’origine à copier.
        - taille        : nombre d’éléments à copier.
    RETOUR      :
        - Un pointeur vers le nouveau tableau contenant les mêmes éléments.
        - NULL si l’allocation échoue.
*/
int * copierTableau(int * tableauSource, int taille);

/*
    NOM	        : ajouterElement
    DESCRIPTION : Crée un nouveau tableau contenant tous les éléments de
                  `tableauSource`, avec un élément supplémentaire ajouté à la fin.
                  Le compteur `nbElement` est mis à jour pour refléter la nouvelle taille.
    PARAMETRES  :
        - tableauSource : pointeur vers le tableau original à copier.
        - nbElement     : pointeur vers le nombre d’éléments dans le tableau source.
                          Ce nombre sera incrémenté si l'ajout réussit.
        - elementAjouter : valeur entière à ajouter à la fin du tableau.
    RETOUR      :
        - Un pointeur vers le nouveau tableau contenant tous les éléments,
          y compris celui ajouté.
        - NULL si l’allocation échoue.
*/
int * ajouterElement(const int * tableauSource, int * nbElement, int elementAjouter);

/*
    NOM	        : afficherInfoTableau
    DESCRIPTION : Affiche le contenu d’un tableau d'entiers ainsi que l'adresse
                  mémoire de chaque élément. Très utile pour visualiser la disposition
                  mémoire et tester la continuité des données en RAM.
    PARAMETRES  :
        - unTableau : pointeur vers le tableau à afficher.
        - nbElement : nombre d’éléments dans le tableau.
    RETOUR      : Aucun (fonction de type void).
*/
void afficherInfoTableau(int * unTableau, int nbElement);


/****************************************************************************************
*                           DÉFINITION DU PROGRAMME PRINCIPALE                          *
****************************************************************************************/
int main(void)
{
    setbuf(stdout, 0);		            // Permets d'afficher les printf en mode débug avec Clion

    int * monTableau;
    int * autreTableau;
    int * uneCopieTableau;
    int taille;
    int valeur;

    //Aquisition des valeurs par Scanf pour prouver le coté dynamique
    printf("Entrez la taille du tableau 1 : ");
    scanf("%i", &taille);
    printf("\nEntrez la valeur d'initialisation du tableau 1 : ");
    scanf("%i", &valeur);
    printf("\n\n");

    //Initialise un premier tableau
    monTableau = initialiserTableau(taille, valeur);
    printf("Tableau 1:\n");
    afficherInfoTableau(monTableau, taille);

    //Copie dans un autre tableau
    //uneCopieTableau = copierTableau(monTableau,taille);

    //Exemple de shadow copie
    uneCopieTableau = monTableau;

    printf("Copie du tableau 1:\n");
    afficherInfoTableau(uneCopieTableau, taille);

    //Exemple de modification du tableau copié.
    printf("** Exemple de modification du tableau **\n");
    uneCopieTableau[taille/2] = 0;
    printf("Tableau 1:\n");
    afficherInfoTableau(monTableau, taille);
    printf("Copie du tableau 1:\n");
    afficherInfoTableau(uneCopieTableau, taille);

    //Ajouter un élément au tableau
    autreTableau = ajouterElement(monTableau, &taille, 888);

    printf("\n\nTableau avec une valeur en plus :\n");
    afficherInfoTableau(autreTableau, taille);

    // Libère la mémoire allouée
    free(monTableau);
    free(autreTableau);
    free(uneCopieTableau);

}

/****************************************************************************************
/									DÉFINITION DES FONCTIONS							*
****************************************************************************************/
/*
    NOM	        : initialiser_tableau
    DESCRIPTION : Alloue dynamiquement un tableau de `nb_element` entiers,
                  et initialise chaque case avec la valeur spécifiée.
    PARAMETRES  :
        - nb_element : le nombre d’éléments à allouer dans le tableau.
        - valeur     : la valeur à assigner à chaque élément du tableau.
    RETOUR      :
        - Un pointeur vers le tableau nouvellement alloué et initialisé.
        - NULL si l’allocation échoue.
    SPÉCIFICATION :
        - Utilise malloc pour allouer dynamiquement le tableau.
        - Chaque élément du tableau est initialisé avec la valeur spécifiée.
        - L’appelant est responsable de libérer la mémoire avec free().
*/
int * initialiserTableau(int nbElement, int valeur)
{
    int* unTableau = NULL; // Pointeur pour contenir l'adresse du tableau alloué.

    // Allocation dynamique de nb_element entiers.
    unTableau = (int*)malloc(nbElement * sizeof(int));

    // Vérifie si l'allocation a échoué.
    if (unTableau == NULL) {
        return NULL; // Échec de malloc : on retourne NULL.
    }

    int i; // Itérateur pour parcourir les indices du tableau.

    // Initialisation de chaque case avec la valeur spécifiée.
    for(i = 0; i < nbElement; i++)
    {
        unTableau[i] = valeur;
    }

    return unTableau; // Retourne le pointeur vers le tableau initialisé.
}

/*
    NOM	        : copierTableau
    DESCRIPTION : Alloue dynamiquement un nouveau tableau d'entiers et copie
                  tous les éléments du tableau source dedans.
    PARAMETRES  :
        - tableauSource : pointeur vers le tableau d’origine à copier.
        - taille        : nombre d’éléments à copier.
    RETOUR      :
        - Un pointeur vers le nouveau tableau contenant les mêmes éléments.
        - NULL si l’allocation échoue.
    SPÉCIFICATION :
        - Le tableau retourné a exactement `taille` éléments.
        - Chaque élément est copié individuellement depuis `tableauSource`.
        - L'appelant est responsable de libérer le tableau retourné avec `free()`.
        - Le tableau source reste inchangé.
*/
int * copierTableau(int * tableauSource, int taille) {

    int * nouveauTableau = NULL; // Pointeur vers le nouveau tableau à retourner

    // Allocation dynamique d’un tableau de la même taille que le source
    nouveauTableau = (int*)malloc(taille * sizeof(int));

    // Vérifie si l’allocation a échoué
    if (nouveauTableau == NULL) {
        return NULL; // Échec de malloc : on retourne NULL.
    }

    // Copie des éléments du tableau source dans le nouveau tableau
    for (int i = 0; i < taille; ++i){
        nouveauTableau[i] = tableauSource[i];
    }

    return nouveauTableau; // Retourne le nouveau tableau copié
}

/*
    NOM	        : ajouterElement
    DESCRIPTION : Crée un nouveau tableau contenant tous les éléments de
                  `tableauSource`, avec un élément supplémentaire ajouté à la fin.
                  Le compteur `nbElement` est mis à jour pour refléter la nouvelle taille.
    PARAMETRES  :
        - tableauSource : pointeur vers le tableau original à copier.
        - nbElement     : pointeur vers le nombre d’éléments dans le tableau source.
                          Ce nombre sera incrémenté si l'ajout réussit.
        - elementAjouter : valeur entière à ajouter à la fin du tableau.
    RETOUR      :
        - Un pointeur vers le nouveau tableau contenant tous les éléments,
          y compris celui ajouté.
        - NULL si l’allocation échoue.
    SPÉCIFICATION :
        - Alloue dynamiquement un nouveau tableau de taille (*nbElement + 1).
        - Copie tous les éléments de `tableauSource` dans le nouveau tableau.
        - Ajoute `elementAjouter` à la fin.
        - Incrémente *nbElement pour refléter le nouvel état.
        - L'appelant est responsable de libérer la mémoire du tableau retourné.
*/
int * ajouterElement(const int * tableauSource, int * nbElement, int elementAjouter) {

    int i; // Itérateur pour la boucle de copie
    int* tableauRetour = NULL; // Pointeur vers le nouveau tableau alloué

    // Allocation d’un nouveau tableau avec une case de plus
    tableauRetour = (int*)malloc((*nbElement + 1) * sizeof(int));

    // Vérifie si l’allocation a échoué
    if (tableauRetour == NULL)
    {
        return NULL; // Allocation échouée → retourne NULL
    }

    // Copie des éléments existants dans le nouveau tableau
    for (i = 0; i < *nbElement; i++)
    {
        tableauRetour[i] = tableauSource[i];
    }

    // Ajout du nouvel élément à la fin
    tableauRetour[*nbElement] = elementAjouter;

    // Mise à jour du compteur d’éléments
    *nbElement = *nbElement + 1;

    // Retour du nouveau tableau contenant l’élément ajouté
    return tableauRetour;
}

/*
    NOM	        : afficherInfoTableau
    DESCRIPTION : Affiche le contenu d’un tableau d'entiers ainsi que l'adresse
                  mémoire de chaque élément. Très utile pour visualiser la disposition
                  mémoire et tester la continuité des données en RAM.
    PARAMETRES  :
        - unTableau : pointeur vers le tableau à afficher.
        - nbElement : nombre d’éléments dans le tableau.
    RETOUR      : Aucun (fonction de type void).
    SPÉCIFICATION :
        - Parcourt le tableau de la première à la dernière case.
        - Pour chaque élément, affiche sa valeur et son adresse mémoire.
        - Sépare les éléments par une tabulation pour plus de lisibilité.
*/
void afficherInfoTableau(int * unTableau, int nbElement)
{
    int i;  // Itérateur pour consulter chaque case du tableau.

    // Affichage de la valeur et de l’adresse de chaque case du tableau.
    for(i = 0; i < nbElement; i++)
    {
        printf("%i\t%p\n", unTableau[i], &unTableau[i] );
    }

    printf("\n"); // Saut de ligne pour finir proprement l'affichage
}


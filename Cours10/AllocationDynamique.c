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
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/****************************************************************************************
*                               DÉFINTION DES CONSTANTES                                *
****************************************************************************************/
#define TAILLE_TABLEAU      5

/****************************************************************************************
*                               DÉCLARATION DES FONCTIONS                               *
****************************************************************************************/


//
//  Prototype de fonction
//      On utilise les [] ou un pointeur pour montrer que l'on reçoit un tableau.
//      On doit TOUJOURS passer la taille d'un tableau en paramètre.
//      On utilise JAMAIS une constante comme paramètre formel.
//
void afficher_tableau(int un_tableau[], int nb_element);

int* initialiser_tableau(int nb_element, int valeur);


int* ajouterElement(const int* tableau_source, int* nb_element, int element_a_ajouter);


/****************************************************************************************
*                           DÉFINTION DU PRGORAMME PRINCIPALE                           *
****************************************************************************************/
int main(void)
{
    
    int * mon_tableau;
    int * autre_tableau;
    int taille;
    int valeur;

    //Aquisition des valeurs par Scanf pour prouver le coté dynamique
    printf("Entrez la taille du tableau 1 : ");
    scanf("%i", &taille);
    printf("\nEntrez la valeur d'initialisation du tableau 1 : ");
    scanf("%i", &valeur);
    printf("\n\n");

    mon_tableau = initialiser_tableau(taille, valeur);


    printf("Tableau 1:\n");
    afficher_tableau(mon_tableau, taille);

    autre_tableau = ajouterElement(mon_tableau, &taille, 666);

    printf("\n\nTableau 2:\n");
    afficher_tableau(autre_tableau, taille);

    // Libère la mémoire alloué
    free(mon_tableau);
    free(autre_tableau);

}


// Créer un nouveau tableau, l'initialise et retourne la valeur 
int* initialiser_tableau(int nb_element, int valeur)
{
    
    int* un_tableau = NULL;
    un_tableau = (int*)malloc(nb_element * sizeof(int));
    
    if (un_tableau == NULL) {

        return NULL;
    }
    

    int i;          // Iterateur pour initialiser chaque case du tableau.

    for(i = 0; i < nb_element; i++)
    {
        un_tableau[i] = valeur;
    }

    return un_tableau;
}


int* ajouterElement(const int* tableau_source, int *nb_element, int element_a_ajouter) {


    int i;
    int* tableauRetour = NULL;

    tableauRetour = (int*)malloc((*nb_element + 1) * sizeof(int));


    if (tableauRetour == NULL)
    {
        return NULL;
    }

   
    for (i = 0; i < *nb_element; i++)
    {
        tableauRetour[i] = tableau_source[i];
    }

    tableauRetour[*nb_element] = element_a_ajouter;

    *nb_element = *nb_element + 1;

    return tableauRetour;

}









void afficher_tableau(int un_tableau[], int nb_element)
{
    int i;          // Iterateur pour consulter chaque case du tableau.

    // On affiche chaque case du tableau.
    for(i = 0; i < nb_element; i++)
    {
        printf("%i ", un_tableau[i]);
    }
    printf("\n");
}
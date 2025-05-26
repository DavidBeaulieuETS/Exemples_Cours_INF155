/****************************************************************************************
    Auteur  : David Beaulieu
    Date    : H 2025
    Fichier : adresseTableau.c
 
    Ce module contient un exemple afin de montrer comment accéder aux différents
    éléments d'un tableau.

    NOTE DE L'ENSEIGNANT : Les commentaires de ce module sont des explications, ils ne 
                           représentent pas vraiment ce qui est attendu de vous lors
                           de la remise de vos travaux pratiques.

*****************************************************************************************/
#include <stdio.h>

/****************************************************************************************
*                               DÉFINTION DES CONSTANTES                                *
****************************************************************************************/
#define TAILLE 5

/****************************************************************************************
*                               DÉCLARATION DES FONCTIONS                               *
****************************************************************************************/


/****************************************************************************************
*                           DÉFINTION DU PRGORAMME PRINCIPALE                           *
****************************************************************************************/
int main(void)
{
    
    int tableau[TAILLE] = {1, -20, 3, 40, 5};
    int i;

    printf("\ntableau : %p\n", tableau);            //Affiche l'adresse du tableau = première case
    printf("tableau[0] : %i\n\n", tableau[0]);      //Affiche la valeur de la première case

    printf("&tableau[0] : %p\n", &tableau[0]);        //Affiche l'adresse du tableau = première case
    printf("&tableau[1] : %p\n\n", &tableau[1]);      //Affiche l'adresse de la deuxième case



    printf("tableau + 3 : %p\n", tableau + 3);
    printf("*(tableau + 3) : %i\n", *(tableau+3));
    printf("Tableau[3] : %i\n\n",tableau[3]);

    //
    //  AFFICHAGE DES ADDRESSE D'UN TABLEAU.

    for(i = 0; i < TAILLE; i++)
    {
        printf("%p  ", &tableau[i]);
    }
    printf("\n\n");
}

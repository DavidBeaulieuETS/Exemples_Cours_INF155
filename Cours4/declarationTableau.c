/****************************************************************************************
    Auteur  : Francis Bourdeau
    Revisé par : David Beaulieu
    Date    : H 2204
    Fichier : declarationTableau.c
 
    Ce module contient un exemple afin de montrer comment déclarer les tableau.

    NOTE DE L'ENSEIGNANT : Les commentaires de ce module sont des explications, ils ne 
                           représentent pas vraiment ce qui est attendu de vous lors
                           de la remise de vos travaux pratiques.

*****************************************************************************************/
#include <stdio.h>

/****************************************************************************************
*                               DÉFINTION DES CONSTANTES                                *
****************************************************************************************/


/****************************************************************************************
*                               DÉCLARATION DES FONCTIONS                               *
****************************************************************************************/


/****************************************************************************************
*                           DÉFINTION DU PRGORAMME PRINCIPALE                           *
****************************************************************************************/
int main(void)
{
    //
    //  Tableau contenant des valeurs non-initialisé.
    //      contenu : ?  ?  ?  ?  ?
    int tableau[5];                    
    
    //
    //  Tableau contenant seulement des 0.
    //      contenu : 0  0  0  0  0
    int tableau_vide[5] = {0};        
    
    //
    //  On essaie de créer un tableau contenant seulement des 2.
    //      contenu : 2  0  0  0  0
    //
    //  Seule la premiere case vaut 2, les autres cases valent 0.
    //
    int tableau_errone[5] = {2};       

    //
    //  On insère les trois première valeurs dans le tableau.
    //      contenu : 5  -3  12  0  0
    //
    //  Les autres cases valent 0.
    //
    int tableau_mi_initialise[5] = {5, -3, 12};       
    

    //
    //  Pour initialiser complétement un tableau,
    //  on fournit l'ensemble de ces valeurs.
    //
    //  contenu : 1 10 -2 20 666
    int tableau_initialise[5] = {1, 10, -2, 20, 666};

}

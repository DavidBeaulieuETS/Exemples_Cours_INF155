/*****************************************************************************
    Par        : David Beaulieu
    Revisé le  : E 2025
    Fichier    : afficheBinaire.c
    Objectifs  : Programme qui affiche la valeur d'un entier en binnaire
    Note	   :

    NOTE DE L'ENSEIGNANT : Les commentaires de ce module sont des explications, ils ne
                           représentent pas vraiment ce qui est attendu de vous lors
                           de la remise de vos travaux pratiques.
*****************************************************************************************/

/****************************************************************************************
*                            AJOUT DES MODULES ET LIBRAIRIES                            *
****************************************************************************************/
#include <stdlib.h>		// Librairie Standard
#include <stdio.h>		// Librairie Entrer - Sortie

/****************************************************************************************
*                           DÉFINITION DU PROGRAMME PRINCIPALE                          *
****************************************************************************************/
int main(void)
{
    //Définition des variables
    unsigned int valeur;        // Valeur à afficher
    int nbBits;                // Nombre de bits du type de la valeur à afficher
    int i;                     // Itérateur de bits

    nbBits = sizeof(int) * 8;    // Détermine le nombre de bits du type

    //Demande l'entier à l'utilisateur
    printf("Entrez un nombre a afficher en binaire : ");
    scanf("%u",&valeur);

    //Parcours les bits de l'entier
    for(i = nbBits-1 ; i>=0; --i){
        printf("%i", (valeur >> i) & 1);        // Fait un décalage à droite pour mettre le bit à afficher
    }                                           // complètement à droite et effectue un masque avec la valeur 1
                                                // pour retirer la partie de gauche du nombre
    printf("\n");
    system("pause");	  		        // Ajoute une pause à la fenêtre console
    return EXIT_SUCCESS;  		        // Permet de terminer le programme proprement
}

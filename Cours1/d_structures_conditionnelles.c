/****************************************************************************************
    Auteur  : Francis Bourdeau
    Date    : 27 avril 2014
    Fichier : entrees.c
 
    Ce module contient un exemple afin de montrer comment écrires des structures
    conditionnelles.

    NOTE DE L'ENSEIGNANT : Les commentaires de ce module sont des explications, ils ne 
                           représentent pas vraiment ce qui est attendu de vous lors 
                           de la remise de vos travaux pratiques.

*****************************************************************************************/
#include <stdio.h>

/****************************************************************************************
*                               DÉFINTION DES CONSTANTES                                *
****************************************************************************************/
#define NB_PIECE_VIE        100

#define BANANE              1
#define GRAPPE_BANANE       2
#define BANANE_VERTE        3

/****************************************************************************************
*                           DÉFINTION DU PRGORAMME PRINCIPALE                           *
****************************************************************************************/
int main(void)
{
    int valeur = 10;            // Variable qui sera utilisée pour évaluer des conditions
    int resultat = 0;           // Variable qui contiendra le résultat d'une expression
                                // booleenne.
    int nb_piece;               // Variables utilisé lors d'un exemple.
    int objet; 

    //
    // Opérateur logiques: Formulation de condition.
    //
    resultat = (valeur == 10);      // == : test d'égalité
    resultat = (valeur != 10);      // != : test d'inégalité
    resultat = (valeur > 10);       // >  : plus grand
    resultat = (valeur >= 10);      // >= : plus grand ou égale
    resultat = (valeur < 8);        // <  : plus petit
    resultat = (valeur <= 10);      // <= : plus petit ou égale.

    // Tout ces opérateurs peuvent être utilisé pour créer une condition dans une 
    // structure conditionnelle.


    //
    //  Exemple : structure conditionnelle de base (if seul)
    //
   
    nb_piece = 100;
    
    //            On un joueur gagne une vie lorsqu'il à ammasser 100 pieces. 
    //            Si ce n'est pas le cas, on fait rien.
    if (nb_piece == 100)
    {
        printf("Bravo, vous gagnez une vie");
    }
   


    //
    //  Exemple : structure conditionnelle de base (if - else)
    //
   
    nb_piece = 90;

    //            Un joueur gagne une vie lorsqu'il à ammasser 100 pieces. 
    //            Si ce n'est pas le cas, on affiche le nombre de pièce qu'il lui manque.
    if (nb_piece == NB_PIECE_VIE)
    {
        printf("Bravo, vous gagnez une vie");
    }
    else
    {
        printf("Vous avez %i pieces.\n");
        printf("Il vous en manque %i avant de gagner une vie.\n", NB_PIECE_VIE-nb_piece);
    }
   


    //
    //  Exemple : structure conditionnelle de base (if - elseif - else if)
    //

    objet = BANANE;
    nb_piece = 50;

    // On ajuste le nombre de pièce du en fonction du type d'objet ammassé. 
    if (objet == BANANE )
    {
        nb_piece = nb_piece + 1;
    }
    else if(objet == GRAPPE_BANANE)
    {
        nb_piece = nb_piece + 10;
    }
    else if(objet == BANANE_VERTE)
    {
        nb_piece = 0;
    }
    else
    {
        printf("ERREUR : Objet non-existant (%i)\n", objet);
    }

    return 0;
}
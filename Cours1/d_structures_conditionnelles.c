/****************************************************************************************
    Auteur  : Francis Bourdeau
    Date    : 27 avril 2014
    Fichier : entrees.c
 
    Ce module contient un exemple afin de montrer comment �crires des structures
    conditionnelles.

    NOTE DE L'ENSEIGNANT : Les commentaires de ce module sont des explications, ils ne 
                           repr�sentent pas vraiment ce qui est attendu de vous lors 
                           de la remise de vos travaux pratiques.

*****************************************************************************************/
#include <stdio.h>

/****************************************************************************************
*                               D�FINTION DES CONSTANTES                                *
****************************************************************************************/
#define NB_PIECE_VIE        100

#define BANANE              1
#define GRAPPE_BANANE       2
#define BANANE_VERTE        3

/****************************************************************************************
*                           D�FINTION DU PRGORAMME PRINCIPALE                           *
****************************************************************************************/
int main(void)
{
    int valeur = 10;            // Variable qui sera utilis�e pour �valuer des conditions
    int resultat = 0;           // Variable qui contiendra le r�sultat d'une expression
                                // booleenne.
    int nb_piece;               // Variables utilis� lors d'un exemple.
    int objet; 

    //
    // Op�rateur logiques: Formulation de condition.
    //
    resultat = (valeur == 10);      // == : test d'�galit�
    resultat = (valeur != 10);      // != : test d'in�galit�
    resultat = (valeur > 10);       // >  : plus grand
    resultat = (valeur >= 10);      // >= : plus grand ou �gale
    resultat = (valeur < 8);        // <  : plus petit
    resultat = (valeur <= 10);      // <= : plus petit ou �gale.

    // Tout ces op�rateurs peuvent �tre utilis� pour cr�er une condition dans une 
    // structure conditionnelle.


    //
    //  Exemple : structure conditionnelle de base (if seul)
    //
   
    nb_piece = 100;
    
    //            On un joueur gagne une vie lorsqu'il � ammasser 100 pieces. 
    //            Si ce n'est pas le cas, on fait rien.
    if (nb_piece == 100)
    {
        printf("Bravo, vous gagnez une vie");
    }
   


    //
    //  Exemple : structure conditionnelle de base (if - else)
    //
   
    nb_piece = 90;

    //            Un joueur gagne une vie lorsqu'il � ammasser 100 pieces. 
    //            Si ce n'est pas le cas, on affiche le nombre de pi�ce qu'il lui manque.
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

    // On ajuste le nombre de pi�ce du en fonction du type d'objet ammass�. 
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
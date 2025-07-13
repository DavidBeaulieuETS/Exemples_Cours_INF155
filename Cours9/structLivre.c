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
#include <math.h>       // Librairie de fonctions mathématique
#include <time.h>		// Librairie de gestion du temps, inclut lafonction time()
#include <ctype.h>      // Librairie de classification et de manipulation de caractères
#include <string.h>     // Librairie pour manipuler des chaines de caractères
#include <windows.h>    // Librairie des commandes de windows

/****************************************************************************************
*                               DÉFINITION DES CONSTANTES                               *
****************************************************************************************/

/****************************************************************************************
*                                  DÉFINITION DES TYPES                                 *
****************************************************************************************/

// Enregistrement qui définit un livre dans un système d'une librairie
// Elle regroupe les principales informations nécessaires pour cataloguer et gérer
// les stocks de livres (titre, auteur, année, prix, inventaire).
typedef struct livre {
    char titre[100];       // Le titre du livre (max 99 caractères + fin de chaîne '\0')
    char auteur[100];      // Le nom de l'auteur (max 99 caractères + fin de chaîne '\0')
    int annee;             // L'année de publication du livre
    double prix;           // Le prix du livre (peut inclure des décimales)
    int nbInventaire;      // Le nombre d'unité disponible en inventaire
}t_livre;

/****************************************************************************************
*								DÉCLARATION DES FONCTIONS								*
****************************************************************************************/
/*
    NOM	: afficherLivre
    DESCRIPTION : Cette fonction affiche à l'écran les informations détaillées d’un livre.
    PARAMETRES : unLivre (t_livre) : Le livre à afficher
    RETOUR : Aucun
*/
void afficherLivre(t_livre unLivre);


/****************************************************************************************
*                           DÉFINITION DU PROGRAMME PRINCIPALE                          *
****************************************************************************************/
int main(void)
{
    SetConsoleOutputCP(CP_UTF8);        // Définit l'encodage de sortie de la console à UTF-8
    setbuf(stdout, 0);		            // Permets d'afficher les printf en mode débug avec Clion

    //Exemple de déclaration de variables de l'enregistrement livre
    t_livre monLivre;
    t_livre monMeileurLivre;
    t_livre mesLivres[5];

    //Exemple d'assignation de valeur au livre
    monLivre.annee = 2002;
    monLivre.prix = 23.55;
    monLivre.nbInventaire = 6;
    strcpy(monLivre.titre, "Un super titre");
    strcpy(monLivre.auteur , "John Doe");



    afficherLivre(monLivre);

    return EXIT_SUCCESS;  		        // Permet de terminer le programme proprement
}

/****************************************************************************************
/									DEFINITION DES FONCTIONS							*
****************************************************************************************/
/*
    NOM	: afficherLivre
    DESCRIPTION : Cette fonction affiche à l'écran les informations détaillées d’un livre.
    PARAMETRES : unLivre (t_livre) : Le livre à afficher
    RETOUR : Aucun
*/
void afficherLivre(t_livre unLivre)
{
    printf("Titre : %s \n",unLivre.titre);
    printf("Auteur : %s \n",unLivre.auteur);
    printf("Année de publication : %i \n",unLivre.annee);
    printf("Prix : %0.2lf \n",unLivre.prix);
    printf("Quantité inventaire : %i \n",unLivre.nbInventaire);
}


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
#define MAX_CHAINE 100
/****************************************************************************************
*                                  DÉFINITION DES TYPES                                 *
****************************************************************************************/
/*
    Cette structure représente un auteur dans un système de gestion de livres.
    Elle regroupe les informations essentielles permettant d'identifier et de
    classifier un auteur : son nom, son année de naissance et son pays d'origine.
*/

typedef struct auteur {
    char nom[MAX_CHAINE];            // Nom complet de l’auteur (max 99 caractères + '\0')
    int anneeNaissance;              // Année de naissance de l’auteur (ex. : 1965)
    char paysOrigine[MAX_CHAINE];    // Pays d’origine (ex. : "Canada", "France")
} t_auteur;


// Enregistrement qui définit un livre dans un système d'une librairie
// Elle regroupe les principales informations nécessaires pour cataloguer et gérer
// les stocks de livres (titre, auteur, année, prix, inventaire).
typedef struct livre {
    char titre[MAX_CHAINE];       // Le titre du livre (max 99 caractères + fin de chaîne '\0')
    t_auteur auteur;              // L'auteur du livre
    int annee;                    // L'année de publication du livre
    double prix;                  // Le prix du livre (peut inclure des décimales)
    int nbInventaire;             // Le nombre d'unitée disponible en inventaire
}t_livre;

/****************************************************************************************
*								DÉCLARATION DES FONCTIONS								*
****************************************************************************************/


/*
    NOM	: aquisitionInfoAuteur
    DESCRIPTION :
        Cette fonction permet d'acquérir les informations de base d'un auteur via l'entrée
        utilisateur : son nom, son année de naissance et son pays d'origine.
    PARAMETRES :  unAuteur (t_auteur*) : pointeur vers la structure auteur à remplir
    RETOUR : Aucun
*/
void aquisitionInfoAuteur(t_auteur * unAuteur);

/*
    NOM	: afficherLivre
    DESCRIPTION : Cette fonction affiche à l'écran les informations détaillées d’un livre.
    PARAMETRES : unLivre (const t_livre*) : pointeur constant vers un livre à afficher
    RETOUR : Aucun
*/
void afficherAuteur(t_auteur * unAuteur);

/*
    NOM : aquisitionInfoLivre
    DESCRIPTION :
        Cette fonction demande à l'utilisateur d'entrer les informations d’un livre
        (titre, auteur, année, prix, quantité en stock) et les enregistre dans la struct.
    PARAMETRES :
            unLivre (t_livre*) : pointeur vers un livre à remplir
    RETOUR :
            Aucun
*/
void aquisitionInfoLivre(t_livre * unLivre);

/*
    NOM	: afficherLivre
    DESCRIPTION : Cette fonction affiche à l'écran les informations détaillées d’un livre.
    PARAMETRES : unLivre (const t_livre*) : pointeur constant vers un livre à afficher
    RETOUR : Aucun
*/
void afficherLivre(const t_livre * unLivre);

/****************************************************************************************
*                           DÉFINITION DU PROGRAMME PRINCIPALE                          *
****************************************************************************************/
int main(void)
{
    SetConsoleOutputCP(CP_UTF8);        // Définit l'encodage de sortie de la console à UTF-8
    setbuf(stdout, 0);		            // Permets d'afficher les printf en mode débug avec Clion

    // Déclaration d'une variable de type t_livre
    t_livre monLivre;

    aquisitionInfoLivre(&monLivre);        // Remplit les infos du livre via saisie clavier
    afficherLivre(&monLivre);              // Affiche les infos du livre

    return EXIT_SUCCESS;  		           // Permet de terminer le programme proprement
}

/****************************************************************************************
/									DEFINITION DES FONCTIONS							*
****************************************************************************************/

/*
    NOM	: aquisitionInfoAuteur
    DESCRIPTION :
        Cette fonction permet d'acquérir les informations de base d'un auteur via l'entrée
        utilisateur : son nom, son année de naissance et son pays d'origine.
        Elle stocke ces données directement dans la structure pointée.
        Elle utilise `fgets` pour lire les chaînes de caractères et `scanf` pour les données numériques.
    PARAMETRES :  unAuteur (t_auteur*) : pointeur vers la structure auteur à remplir
    RETOUR : Aucun
*/
void aquisitionInfoAuteur(t_auteur * unAuteur){

    printf(" ** Entrez le nom de l'auteur : ");
    fgets(unAuteur->nom,MAX_CHAINE,stdin);

    printf(" ** Entrez l'année de naissance de l'auteur : ");
    scanf("%i", &unAuteur->anneeNaissance);

    fflush(stdin);                                                // Permet de vider la mémoire du clavier
    printf(" ** Entrez le pays d'origine de l'auteur : ");
    fgets(unAuteur->paysOrigine,MAX_CHAINE,stdin);

}

/*
    NOM	: afficherAuteur
    DESCRIPTION :
        Fonction qui affiche les informations d’un auteur : son nom, son pays d’origine
        et son année de naissance, dans un format lisible pour l’utilisateur.
    PARAMETRES : unAuteur (t_auteur*) : pointeur vers la structure auteur à afficher
    RETOUR : Aucun
    SPÉCIFICATION :
*/
void afficherAuteur(t_auteur * unAuteur){

  printf("%s, est née au : %s en %i\n",unAuteur->nom, unAuteur->paysOrigine, unAuteur->anneeNaissance);

}

/*
    NOM : aquisitionInfoLivre
    DESCRIPTION :
        Cette fonction demande à l'utilisateur d'entrer les informations d’un livre
        (titre, auteur, année, prix, quantité en stock) et les enregistre dans la struct.
    PARAMETRES :
            unLivre (t_livre*) : pointeur vers un livre à remplir
    RETOUR :
            Aucun
*/
void aquisitionInfoLivre(t_livre * unLivre){

    t_auteur monAuteur;

    printf("Entrez le titre du livre : ");
    fgets(unLivre->titre,MAX_CHAINE,stdin);

    aquisitionInfoAuteur(&monAuteur);
    unLivre->auteur = monAuteur;

    //aquisitionInfoAuteur(&unLivre->auteur);

    printf("Entrez l'année de publication : ");
    scanf("%i", &unLivre->annee);

    printf("Entrez le prix du livre : ");
    scanf("%lf", &unLivre->prix);

    printf("Entrez le nombre de libre en inventaire : ");
    scanf("%i", &unLivre->nbInventaire);
}


/*
    NOM	: afficherLivre
    DESCRIPTION : Cette fonction affiche à l'écran les informations détaillées d’un livre.
    PARAMETRES : unLivre (const t_livre*) : pointeur constant vers un livre à afficher
    RETOUR : Aucun
*/
void afficherLivre(const t_livre * unLivre)
{
    printf("Titre : %s \n",unLivre->titre);
    afficherAuteur(&unLivre->auteur);
    printf("Année de publication : %i \n",unLivre->annee);
    printf("Prix : %0.2lf \n",unLivre->prix);
    printf("Quantité inventaire : %i \n",unLivre->nbInventaire);
}



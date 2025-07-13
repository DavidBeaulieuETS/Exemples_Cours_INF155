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

// Enregistrement qui définit un livre dans un système d'une librairie
// Elle regroupe les principales informations nécessaires pour cataloguer et gérer
// les stocks de livres (titre, auteur, année, prix, inventaire).
typedef struct livre {
    char titre[MAX_CHAINE];       // Le titre du livre (max 99 caractères + fin de chaîne '\0')
    char auteur[MAX_CHAINE];      // Le nom de l'auteur (max 99 caractères + fin de chaîne '\0')
    int annee;                    // L'année de publication du livre
    double prix;                  // Le prix du livre (peut inclure des décimales)
    int nbInventaire;             // Le nombre d'unitée disponible en inventaire
}t_livre;

/****************************************************************************************
*								DÉCLARATION DES FONCTIONS								*
****************************************************************************************/
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
    NOM	: retirerLivreInventaire
    DESCRIPTION :
        Cette fonction simule la vente ou la sortie d’un livre de l’inventaire.
        Si l’inventaire est vide, la fonction retourne 0. Sinon, elle décrémente le
        compteur d’inventaire et retourne la nouvelle valeur.
    PARAMETRES :
            unLivre (t_livre*) : pointeur vers un livre dont on veut retirer un exemplaire
    RETOUR :
            int : nouvelle quantité restante, ou 0 si aucun exemplaire disponible
*/
int retirerLivreInventaire(t_livre * unLivre);

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
    retirerLivreInventaire(&monLivre);     // Retire un exemplaire du stock (si disponible)
    afficherLivre(&monLivre);              // Réaffiche l’état du livre après retrait

    return EXIT_SUCCESS;  		           // Permet de terminer le programme proprement
}

/****************************************************************************************
/									DEFINITION DES FONCTIONS							*
****************************************************************************************/

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

    printf("Entrez le titre du livre : ");
    fgets(unLivre->titre,MAX_CHAINE,stdin);

    printf("Entrez le nom de l'auteur : ");
    fgets(unLivre->auteur,MAX_CHAINE,stdin);

    printf("Entrez l'année de publication : ");
    scanf("%i", &unLivre->annee);

    printf("Entrez le prix du livre : ");
    scanf("%lf", &unLivre->prix);

    printf("Entrez le nombre de libre en inventaire ");
    scanf("%i", &unLivre->nbInventaire);
}

/*
    NOM	: retirerLivreInventaire
    DESCRIPTION :
        Cette fonction simule la vente ou la sortie d’un livre de l’inventaire.
        Si l’inventaire est vide, la fonction retourne 0. Sinon, elle décrémente le
        compteur d’inventaire et retourne la nouvelle valeur.
    PARAMETRES :
            unLivre (t_livre*) : pointeur vers un livre dont on veut retirer un exemplaire
    RETOUR :
            int : nouvelle quantité restante, ou 0 si aucun exemplaire disponible
*/
int retirerLivreInventaire(t_livre * unLivre){

  if (unLivre->nbInventaire == 0){
    return 0;
  }
  else {
    unLivre->nbInventaire--;
    return unLivre->nbInventaire;
  }
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
    printf("Auteur : %s \n",unLivre->auteur);
    printf("Année de publication : %i \n",unLivre->annee);
    printf("Prix : %0.2lf \n",unLivre->prix);
    printf("Quantité inventaire : %i \n",unLivre->nbInventaire);
}


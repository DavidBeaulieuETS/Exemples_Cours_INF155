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
#include <string.h>     // Librairie pour manipuler des chaines de caractères

#include "mLivre.h"

/****************************************************************************************
*                               DÉFINITION DES CONSTANTES                               *
****************************************************************************************/


/****************************************************************************************
/									DEFINITION DES FONCTIONS							*
****************************************************************************************/



/*
    NOM	: initLivre
    DESCRIPTION :
        Cette fonction alloue dynamiquement de la mémoire pour un livre
        et demande à l’utilisateur de saisir ses informations (titre, auteur,
        année, prix, inventaire). Elle retourne un pointeur vers la structure remplie.
    PARAMETRES :
            Aucun
    RETOUR :
            t_livre * : pointeur vers une structure de type t_livre initialisée
    SPÉCIFICATION :
            - Allocation dynamique de mémoire
            - Lecture des champs via l’entrée standard (stdin)
            - Utilisation de fgets pour les chaînes et scanf pour les valeurs numériques
*/
t_livre * initLivre(){

    t_livre * unLivre = NULL;
    unLivre = (t_livre *)malloc(1 * sizeof(t_livre));

    if(unLivre != NULL){
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
    return unLivre;
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
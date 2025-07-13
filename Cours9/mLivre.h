/*****************************************************************************************
    Par        : David Beaulieu
    Revise le  :
    Fichier    :
    Objectifs  :
    Note	   :
*****************************************************************************************/
#ifndef MLIVRE_H
#define MLIVRE_H

/****************************************************************************************
*                               DÉFINITION DES CONSTANTES                               *
****************************************************************************************/
#define MAX_CHAINE 100

/****************************************************************************************
*                                  DÉFINITION DES TYPES                                 *
****************************************************************************************/
/*
    Enregistrement qui définit un livre dans un système d'une librairie
    Elle regroupe les principales informations nécessaires pour cataloguer et gérer
    les stocks de livres (titre, auteur, année, prix, inventaire).
 */
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
    NOM	:
    DESCRIPTION :
    PARAMETRES :
    RETOUR :
    SPÉCIFICATION :
*/
t_livre * initLivre();

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


int ajouterLivreInventaire(t_livre * livre);


/*
    NOM	: afficherLivre
    DESCRIPTION : Cette fonction affiche à l'écran les informations détaillées d’un livre.
    PARAMETRES : unLivre (const t_livre*) : pointeur constant vers un livre à afficher
    RETOUR : Aucun
*/
void afficherLivre(const t_livre * unLivre);

#endif //MLIVRE_H

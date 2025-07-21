/*****************************************************************************************
    Par        : David Beaulieu
    Revise le  : H2025
    Fichier    : mMoto.H
    Objectifs  : Fichier de démonstration pour la manipulation des enregistrements
    Note	   :
*****************************************************************************************/
#ifndef MSERIE_H
#define MSERIE_H

/****************************************************************************************
*                               DÉFINITION DES CONSTANTES                               *
****************************************************************************************/
#define MAX_CHAINE 60
#define MAX_MOTO 20

/****************************************************************************************
*                           DÉFINITION DES STRUCTURES ET TYPES                          *
****************************************************************************************/
// Représente les différentes catégories de motos possibles
typedef enum typeDeMoto {
  SPORT,         // Motos sportives, légères et puissantes, conçues pour la performance
  ROUTE,         // Motos standards ou customs, idéales pour la route et les balades tranquilles
  VOYAGE,        // Grosses routières confortables pour les longues distances
  TOUT_TERRAIN   // Motos capables de sortir de la route : chemins, boue, aventures!
} t_type;

// Représente une moto avec ses caractéristiques principales
typedef struct moto {
  char marque[MAX_CHAINE];  // Marque du fabricant (ex: Honda, Yamaha)
  char model[MAX_CHAINE];   // Nom du modèle (ex: CB750, ZRX1200R)
  int annee;                // Année de fabrication (ex: 2004)
  int cylindree;            // Cylindrée en cm3, ex: 1164 pour une ZRX1200R
  t_type type;              // Type de moto selon l’usage (voir t_type)
} t_moto;

// Représente un garage contenant un ensemble de motos
typedef struct garage {
  t_moto tableauMoto[MAX_MOTO];  // Tableau statique contenant les motos du garage
  int nbMoto;                    // Nombre actuel de motos dans le garage
} t_garage;

/****************************************************************************************
*								DÉCLARATION DES FONCTIONS								*
****************************************************************************************/
/*
    NOM         : chercherMoto
    DESCRIPTION : Cherche une moto dans un garage qui correspond exactement à une cylindrée et un type donné.
    PARAMETRES  :
    - garage : pointeur constant vers un t_garage à inspecter
    - cylindree : la cylindrée (en cc) recherchée
    - type : le type de moto recherché (enum t_type)
    - motoTrouvee : pointeur vers une structure t_moto où sera copiée la moto trouvée
    RETOUR      :
    - 1 si une moto correspondante est trouvée
    - 0 sinon
*/
int chercherMoto(const t_garage* garage, int cylindree, t_type type, t_moto * motoTrouvee);

/*
    NOM         : filtreMotoMarque
    DESCRIPTION : Filtre les motos du garage selon une marque donnée et retourne un nouveau garage contenant uniquement celles-ci.
    PARAMETRES  :
    - garage : pointeur vers le garage source
    - marque : chaîne de caractères représentant la marque à filtrer
    RETOUR      :
    - Pointeur vers un nouveau t_garage contenant les motos filtrées
    - NULL si aucune moto correspondante ou échec d'allocation
*/
t_garage* filtreMotoMarque(const t_garage* garage, char * marque);

/*
    NOM         : trierGarageAnnee
    DESCRIPTION : Trie les motos d’un garage par ordre croissant d’année de fabrication.
    PARAMETRES  :
    - garage : pointeur vers le garage à trier
    RETOUR      : Aucun
*/
void trierGarageAnnee(t_garage* garage);
/*
    NOM         : afficherMoto
    DEF         : Affiche les informations d'une moto donnée.
    PARAMÈTRES  :
        - t_moto* moto : un pointeur vers la moto à afficher
    RETOUR      : Aucun
*/
void remplirGarage(t_garage* garage);

/*
    NOM         : afficherGarage
    DEF         : Affiche toutes les motos contenues dans un garage.
    PARAMÈTRES  :
    - t_garage* garage : un pointeur vers le garage à afficher
    RETOUR      : Aucun
*/
void afficherMoto(t_moto* moto);

/*
    NOM         : remplirGarage
    DESCRIPTION : Remplit un garage avec un ensemble prédéfini de motos réelles.
    PARAMETRES  :
        - t_garage* garage : Pointeur vers un garage à initialiser (et à remplir).
    RETOUR      : Aucun
*/
void afficherGarage(t_garage* garage);

#endif //MSERIE_H

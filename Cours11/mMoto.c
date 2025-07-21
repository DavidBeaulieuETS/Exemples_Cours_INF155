/*****************************************************************************************
    Par        : David Beaulieu
    Revise le  : H2025
    Fichier    : mMoto.c
    Objectifs  : Fichier de démonstration pour la manipulation des enregistrements
    Note	   :
*****************************************************************************************/

/****************************************************************************************
*                            AJOUT DES MODULES ET LIBRAIRIES                            *
****************************************************************************************/
#include <stdlib.h>		// Librairie Standard
#include <stdio.h>		// Librairie Entrée - Sortie
#include <string.h>     // Librairie pour manipuler des chaines de caractères
#include <windows.h>    // Librairie des commandes de windows

#include "mMoto.h"

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
    SPÉCIFICATION : La recherche est linéaire. En cas de succès, la première moto correspondante est retournée.
*/
int chercherMoto(const t_garage* garage, int cylindree, t_type type, t_moto * motoTrouvee){

    int i;

    for(i = 0; i < garage->nbMoto; ++i){

        // Vérifie si les deux critères sont satisfaits
        if(garage->tableauMoto[i].cylindree == cylindree && garage->tableauMoto[i].type == type){

            // Copie la moto trouvée dans le pointeur fourni
            (*motoTrouvee) = garage->tableauMoto[i];
            return 1;
        }
    }
    return 0;
}

/*
    NOM         : filtreMotoMarque
    DESCRIPTION : Filtre les motos du garage selon une marque donnée et retourne un nouveau garage contenant uniquement celles-ci.
    PARAMETRES  :
        - garage : pointeur vers le garage source
        - marque : chaîne de caractères représentant la marque à filtrer
    RETOUR      :
        - Pointeur vers un nouveau t_garage contenant les motos filtrées
        - NULL si aucune moto correspondante ou échec d'allocation
    SPÉCIFICATION : Alloue dynamiquement un nouveau garage. Doit être libéré par l'appelant avec `free()`.
*/
t_garage* filtreMotoMarque(const t_garage* garage, char * marque){

    int i;
    int nbMotoTrouvee = 0;

    // Allocation d’un nouveau garage vide
    t_garage * nouveauGarage = (t_garage *)malloc(sizeof(t_garage));

    if(nouveauGarage != NULL){
        nouveauGarage->nbMoto = 0;

        for(i = 0; i < garage->nbMoto; ++i){

            // Compare la marque (strcmp retourne 0 si identiques)
            if(strcmp(garage->tableauMoto[i].marque, marque) == 0){

                // Copie la moto dans le nouveau garage
                nouveauGarage->tableauMoto[nbMotoTrouvee] = garage->tableauMoto[i];
                nbMotoTrouvee++;
                nouveauGarage->nbMoto = nbMotoTrouvee;
            }
        }
    }

    // Retourne le garage filtré seulement s’il contient des motos
    if (nouveauGarage != NULL && nbMotoTrouvee != 0){
        return nouveauGarage;
    } else {
        // Rien trouvé ou erreur
        return NULL;
    }
}


/*
    NOM         : trierGarageAnnee
    DESCRIPTION : Trie les motos d’un garage par ordre croissant d’année de fabrication.
    PARAMETRES  :
        - garage : pointeur vers le garage à trier
    RETOUR      : Aucun
    SPÉCIFICATION : Utilise le tri par sélection. Modifie directement le contenu du garage.
*/
void trierGarageAnnee(t_garage* garage){

    int i, j;
    int anneeMin;
    int posAnneeMin;
    t_moto motoTempo;

    for (i = 0; i < garage->nbMoto - 1; ++i){

        // Hypothèse : la plus petite année est à la position i
        anneeMin = garage->tableauMoto[i].annee;
        posAnneeMin = i;

        // Cherche une année plus petite dans la suite du tableau
        for(j = i; j < garage->nbMoto; ++j){

            if(garage->tableauMoto[j].annee < anneeMin){
                anneeMin = garage->tableauMoto[j].annee;
                posAnneeMin = j;
            }
        }

        // Échange les deux motos si nécessaire
        motoTempo = garage->tableauMoto[posAnneeMin];
        garage->tableauMoto[posAnneeMin] = garage->tableauMoto[i];
        garage->tableauMoto[i] = motoTempo;
    }
}


/*
    NOM         : afficherMoto
    DEF         : Affiche les informations d'une moto donnée.
    PARAMÈTRES  :
        - t_moto* moto : un pointeur vers la moto à afficher
    RETOUR      : Aucun
    SPÉCIFICATION :
        - Affiche la marque, le modèle, l’année, la cylindrée, et le type (sous forme de texte).
*/
void afficherMoto(t_moto* moto) {

    const char* typeMoto[] = {"Sport", "Route", "Voyage", "Tout-terrain"};

    printf("Marque     : %s\n", moto->marque);
    printf("Modèle     : %s\n", moto->model);
    printf("Année      : %d\n", moto->annee);
    printf("Cylindrée  : %d cc\n", moto->cylindree);
    printf("Type       : %s\n", typeMoto[moto->type]);
    printf("--------------------------\n");
}

/*
    NOM         : afficherGarage
    DEF         : Affiche toutes les motos contenues dans un garage.
    PARAMÈTRES  :
        - t_garage* garage : un pointeur vers le garage à afficher
    RETOUR      : Aucun
    SPÉCIFICATION :
        - Parcourt le tableau de motos et les affiche une par une.
*/
void afficherGarage(t_garage* garage) {
    printf("=== CONTENU DU GARAGE (%d motos) ===\n", garage->nbMoto);
    for (int i = 0; i < garage->nbMoto; i++) {
        printf("Moto #%d\n", i + 1);
        afficherMoto(&garage->tableauMoto[i]);
    }
}

/*
    NOM         : remplirGarage
    DESCRIPTION : Remplit un garage avec un ensemble prédéfini de motos réelles.
    PARAMETRES  :
        - t_garage* garage : Pointeur vers un garage à initialiser (et à remplir).
    RETOUR      : Aucun
*/
void remplirGarage(t_garage* garage) {
    garage->nbMoto = 19;
    t_moto motos[] = {
        {"Yamaha", "MT-07", 2022, 689, SPORT},
        {"Kawasaki", "Z650", 2022, 649, SPORT},
        {"Honda", "Africa Twin", 2020, 1084, TOUT_TERRAIN},
        {"BMW", "R1250GS", 2020, 1254, VOYAGE},
        {"Suzuki", "V-Strom 650", 2022, 645, VOYAGE},
        {"Ducati", "Multistrada V4", 2023, 1158, VOYAGE},
        {"Harley-Davidson", "Street Glide", 2023, 1746, ROUTE},
        {"KTM", "690 Enduro R", 2022, 690, TOUT_TERRAIN},
        {"Triumph", "Tiger 900", 2023, 888, TOUT_TERRAIN},
        {"Yamaha", "Tracer 9 GT", 2022, 890, VOYAGE},
        {"BMW", "S1000RR", 2023, 999, SPORT},
        {"Honda", "CB500X", 2022, 471, VOYAGE},
        {"Royal Enfield", "Himalayan", 2022, 411, TOUT_TERRAIN},
        {"Suzuki", "Hayabusa", 2020, 1340, SPORT},
        {"Indian", "Scout Bobber", 2021, 1133, ROUTE},
        {"Ducati", "Scrambler Icon", 2021, 803, TOUT_TERRAIN},
        {"KTM", "1290 Super Adventure R", 2023, 1301, VOYAGE},
        {"Moto Guzzi", "V85 TT", 2023, 853, TOUT_TERRAIN},
        {"Kawasaki", "ZRX1200R", 2004, 1164, ROUTE}
    };

    for (int i = 0; i < garage->nbMoto; i++) {
        garage->tableauMoto[i] = motos[i];
    }
}




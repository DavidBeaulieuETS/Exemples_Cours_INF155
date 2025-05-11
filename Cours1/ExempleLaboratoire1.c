/****************************************************************************************
    Auteur  : David Beaulieu
    Date    : 2025
    Fichier : ExempleLaboratoire1.c

    Description : Exemple présenté lors du laboratoire 1

    NOTE DE L'ENSEIGNANT : Les commentaires de ce module sont des explications, ils ne
                               représentent pas vraiment ce qui est attendu de vous lors
                               de la remise de vos travaux pratiques.

****************************************************************************************/

#include <locale.h>
#include <stdio.h>              // Ajout de la librairie standard d'entrée sortie
                                // Permet d'utiliser les fonctions printf et scanf

// Déclaration des constantes
#define RECETTE_CIMENT 350      // Quantité de ciment nécessaire pour faire 1m3 de béton
#define RECETTE_SABLE 680       // Quantité de sable nécessaire pour faire 1m3 de béton
#define RECETTE_GRAVIER 1175    // Quantité de gravier nécessaire pour faire 1m3 de béton

#define MODELE 1                // Indique quelle section de l'algorithme on veut compiler

// Programme principal
int main(void) {
    double qtCiment;        // Quantité de ciment entrée par l'utilisateur
    double qtSable;         // Quantité de sable entrée par l'utilisateur
    double qtGravier;       // Quantité de gravier entrée par l'utilisateur

    double volumeCiment;    // Volume de béton en fonction du ciment
    double volumeSable;     // Volume de béton en fonction du sable
    double volumeGravier;   // Volume de béton en fonction du gravier

    setbuf(stdout, 0);      // Permet d'afficher les printfs en mode débug avec Clion

    //Saisie des valeurs
    printf("Entrez votre quantite de ciment : ");
    scanf("%lf",&qtCiment);

    printf("Entrez votre quantite de sable : ");
    scanf("%lf",&qtSable);

    printf("Entrez votre quantite de gravier : ");
    scanf("%lf",&qtGravier);

    //Calcul des volumes
    volumeCiment = qtCiment / RECETTE_CIMENT;
    volumeSable = qtSable / RECETTE_SABLE;
    volumeGravier = qtGravier / RECETTE_GRAVIER;


#if MODELE == 1         //Permet de mettre la section du modèle 1 en commentaire

    //Modèle de structure conditionelle 1 - avec des if imbriqués
    if (volumeCiment < volumeSable) {
        if (volumeCiment < volumeGravier ) {
            printf("Le volume total de beton est : %0.2lf",volumeCiment);
        }
        else {
            printf("Le volume total de beton est : %0.2lf",volumeGravier);
        }
    }
    else {
        if (volumeSable < volumeGravier ) {
            printf("Le volume total de beton est : %0.2lf",volumeSable);
        }
        else {
            printf("Le volume total de beton est : %0.2lf",volumeGravier);
        }
    }
#endif

#if MODELE == 2         //Permet de mettre la section du modèle 1 en commentaire

    //Modèle de structure conditionelle 2 - avec des else if
    if (volumeCiment < volumeSable && volumeCiment < volumeGravier) {
        printf("Le volume total de beton est : %0.2lf",volumeCiment);
    }
    else if (volumeSable < volumeCiment && volumeSable < volumeGravier ) {
        printf("Le volume total de beton est : %0.2lf",volumeSable);
    }
    else {
        printf("Le volume total de beton est : %0.2lf",volumeGravier);
    }
#endif

    // Affichage des 3 valeurs de volume
    printf("\n\nLe volume de ciment = %lf \nLe volume de sable = %lf \n le volume de gravier = %lf",volumeCiment, volumeSable,volumeGravier);

}


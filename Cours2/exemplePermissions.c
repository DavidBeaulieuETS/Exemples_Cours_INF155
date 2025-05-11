/****************************************************************************************
    Auteur  : David Beaulieu
    Date    : 2025
    Fichier : exemplePermissions.c

    Description: Exemple d'utilisation pour les opérateur Binaire

    NOTE DE L'ENSEIGNANT : Les commentaires de ce module sont des explications, ils ne
                           représentent pas vraiment ce qui est attendu de vous lors
                           de la remise de vos travaux pratiques.

*****************************************************************************************/

/****************************************************************************************
*                            AJOUT DES MODULES ET LIBRAIRIES                            *
****************************************************************************************/
#include <stdlib.h>		// Librairie Standard
#include <stdio.h>		// Librairie Entrer - Sortie

/****************************************************************************************
*                               DÉFINITION DES CONSTANTES                               *
****************************************************************************************/
// Définition des permissions des fichiers avec des bits
#define READ    0b100       //L'utilisateur peut lire le fichier
#define WRITE   0b010       //L'utilisateur peut éditer le fichier
#define EXECUTE 0b001       //L'utilisateur peut exécuter le fichier

/****************************************************************************************
*                           DÉFINITION DU PROGRAMME PRINCIPALE                          *
****************************************************************************************/
int main(void) {
    unsigned char userGeneral;      //Utilisateur général peut consulter et éditer les fichiers
    unsigned char userAdmin;        //Utilisateur admin peut consulter éditer et exécuter les fichiers

    setbuf(stdout, 0);        // Permet d'afficher les printfs en mode débug avec Clion


    //Crée les permissions de l'utilisateur général -> 0b110
    userGeneral = READ | WRITE;

    //Crée les permissions de l'utilisateur admin -> 0b111
    userAdmin = EXECUTE | userGeneral;

    //Révoque la permission de l'utilisateur admin en exécution
    userAdmin = userAdmin & ~EXECUTE;            //On aurait pu aussi faire : userAdmin &= ~EXECUTE;

    system("pause");                    //Arret dans la console

    //Valide la possibilité de l'utilisateur admin de d'executer le fichier
    if (userAdmin & EXECUTE) {
        printf("L'utilisateur peut executer.\n");
    }
    else {
        printf("L'utilisateur peut PAS executer.\n");
    }

    system("pause");            //Arrêt dans la console

    //Remet la permission à l'utilisateur admin d'exécuté
    userAdmin |= EXECUTE;               //On aurait pu aussi faire :  userAdmin = userAdmin | EXECUTE;

    //Valide la possibilité de l'utilisateur admin de d'executer le fichier
    if (userAdmin & EXECUTE) {
        printf("L'utilisateur peut executer.\n");
    }
    else {
        printf("L'utilisateur peut PAS executer.\n");
    }

    system("pause");	  		// Ajoute une pause à la fenêtre console
    return EXIT_SUCCESS;  		        // Permet de terminer le programme proprement
}
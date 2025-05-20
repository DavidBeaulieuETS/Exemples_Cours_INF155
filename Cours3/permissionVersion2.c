/*****************************************************************************
    Par        : David Beaulieu
    Revisé le  : H2025
    Fichier    : permissionVersion2.c
    Objectifs  :
    Note	   :

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
*								DÉCLARATION DES FONCTIONS								*
****************************************************************************************/
/*
    valider Permission Execute
    DEF : Fonction qui permet de valider si un utilisateur peut executer
    PARAMETRES :	- Usager dont on veut tester sa permission (TYPE : unsigned char)

    RETOUR : Aucun
*/
void validerPermissionExecute(unsigned char usager);

/*
    afficher Binaire
    DEF :           Fonction qui affiche une valeur en binaire
    PARAMETRES :	- Valeur à afficher en binaire  (TYPE : unsigned char)

    RETOUR : Aucun
*/
void afficherBinaire(unsigned char usager);

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

    printf("\nPermission de l'utilisateur general : ");
    afficherBinaire(userGeneral);
    printf("\nPermission de l'utilisateur admin : ");
    afficherBinaire(userAdmin);

    //Révoque la permission de l'utilisateur admin en exécution
    userAdmin = userAdmin & ~EXECUTE;           //On aurait pu aussi faire : userAdmin &= ~EXECUTE;

    system("pause");                            //Arret dans la console

    //Valide la possibilité de l'utilisateur admin de d'executer le fichier
    printf("\nPermission de l'utilisateur admin : ");
    afficherBinaire(userAdmin);
    validerPermissionExecute(userAdmin);

    system("pause");            //Arrêt dans la console

    //Remet la permission à l'utilisateur admin d'exécuté
    userAdmin |= EXECUTE;               //On aurait pu aussi faire :  userAdmin = userAdmin | EXECUTE;

    //Valide la possibilité de l'utilisateur admin de d'executer le fichier
    printf("\nPermission de l'utilisateur admin : ");
    afficherBinaire(userAdmin);
    validerPermissionExecute(userAdmin);

    system("pause");	  		        // Ajoute une pause à la fenêtre console
    return EXIT_SUCCESS;  		        // Permet de terminer le programme proprement
}


/****************************************************************************************
*									DÉFINITION DES FONCTIONS							*
****************************************************************************************/
/*
    valider Permission Execute
    DEF : Fonction qui permet de valider si un utilisateur peut executer
    PARAMETRES :	- Usager dont on veut tester sa permission (TYPE : unsigned char)

    RETOUR : Aucun
*/
void validerPermissionExecute(unsigned char usager){

    if (usager & EXECUTE) {
        printf("L'utilisateur peut executer.\n");
    }
    else {
        printf("L'utilisateur peut PAS executer.\n");
    }
}

/*
    afficher Binaire
    DEF : Fonction qui affiche une valeur en binaire
    PARAMETRES :	- Valeur à afficher en binaire  (TYPE : unsigned char)

    RETOUR : Aucun
*/
void afficherBinaire(unsigned char valeurAafficher){

    int nbBits;                    // Nombre de bits du type de la valeur à afficher
    int i;                         // Itérateur de bits

    nbBits = sizeof(int) * 8;      // Détermine le nombre de bits du type

    //Parcours les bits de l'entier
    for(i = nbBits-1 ; i>=0; --i){
        printf("%i", (valeurAafficher >> i) & 1);       // Fait un décalage à droite pour mettre le bit à afficher
    }                                                   // complètement à droite et effectue un masque avec la valeur 1
                                                        // pour retirer la partie de gauche du nombre
    printf("\n");
}
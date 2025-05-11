/*****************************************************************************
    Par        : David Beaulieu
    Revisé le  : H2025
    Fichier    : trouverNombre.c
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
#include <time.h>       // Libairie de gestion du temps

/****************************************************************************************
*                               DÉFINITION DES CONSTANTES                               *
****************************************************************************************/
#define MIN 1                         // Valeur minimum du nombre mystère
#define MAX 10                        // Valeur maximum du nombre mystère
#define NOMBRE_ESSAIT_MAX 3           // Nombre d'essais maximum

/****************************************************************************************
*                           DÉFINITION DU PROGRAMME PRINCIPALE                          *
****************************************************************************************/
int main(void)
{
    // Déclaration des variables
    int nombreMystere;
    int nombreUtilisateur;
    int nombreEssaitCourant = 0;
    setbuf(stdout, 0);        // Permet d'afficher les printfs en mode débug avec Clion

    // Initialise le générateur pseudo-aléatoire avec le temps courant de l'horloge
    srand(time(NULL));
    rand();

    // Détermine le nombre mystère
    nombreMystere = (MIN + (int)(rand() / (RAND_MAX + 0.005) * (MAX - MIN + 1)));

    do
    {
        // Demande un nombre au clavier à l'utilisateur
        printf("\nEntrez un nombre au clavier : ");
        scanf("%i", &nombreUtilisateur);

        // Comptabilise le nombre d'essait
        nombreEssaitCourant++;

        // Détermine ou se situe le nombre entré par l'utilisateur par rapport au nombre mystère
        if (nombreUtilisateur < nombreMystere){
            printf("\nLe nombre entrez est trop petit\n");
        }
        else if (nombreUtilisateur > nombreMystere){
            printf("\nLe nombre entrez est trop grand\n");
        }
    // Redemande un nouveau nombre si le nombre n'est pas trouvé et si le nombre d'essait le permet
    }while(nombreUtilisateur != nombreMystere && nombreEssaitCourant <= NOMBRE_ESSAIT_MAX);

    // Affiche la conclusion du jeux
    if (nombreEssaitCourant > NOMBRE_ESSAIT_MAX){
        printf("Votre nombre d'essait est depasse !!\nLe nombre mystere etait : %i\n",nombreMystere);
    }
    else{
        printf("Bravo vous avez trouvez le nombre mystere !!\n");
    }

    return EXIT_SUCCESS;  		        // Permet de terminer le programme proprement
}
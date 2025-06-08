/*****************************************************************************************
    Par : David Beaulieu
    Revise le  : H 2025
    Fichier    : valider saisie.c
    Objectifs  : Exemple de fonction de validation d'une saisie au clavier
    Note	   :

    NOTE DE L'ENSEIGNANT : Les commentaires de ce module sont des explications, ils ne
                           représentent pas vraiment ce qui est attendu de vous lors
                           de la remise de vos travaux pratiques.

/****************************************************************************************
*                            AJOUT DES MODULES ET LIBRAIRIES                            *
****************************************************************************************/
#include <stdlib.h>		/* Librairie Standart */
#include <stdio.h>		/* Librairie Entrer - Sortie */
#include <ctype.h>      /* Librairie de classification et de manipulation de caractères */
/****************************************************************************************
*                               DÉFINITION DES CONSTANTES                               *
****************************************************************************************/

/****************************************************************************************
*								DÉCLARATION DES FONCTIONS								*
****************************************************************************************/
/*
    valider saisi
    Cette fonction
    Paramètre
    PARAMETRES :

    RETOUR :		1 si un valeur a été saisi, 0 si l'utilisateur à quitté
    SPÉCIFICATION : Aucune
*/
int validerSaisi(int valeurMin, int valeurMax, int * valeurSaisi);

/****************************************************************************************
*                           DÉFINITION DU PROGRAMME PRINCIPALE                          *
****************************************************************************************/
int main(void){

    int valeurClavier = 0;

    if (validerSaisi(22,44,&valeurClavier)){

        printf("\n Vous avez saisie la valeur : %i\n",valeurClavier);
    }
    else{
        printf("\n Vous avez quitter le programme !\n");
    }

    return EXIT_SUCCESS;
}

/*
    valider saisi
    Cette fonction
    Paramètre
    PARAMETRES :

    RETOUR :		1 si un valeur a été saisi, 0 si l'utilisateur à quitté
    SPÉCIFICATION : Aucune
*/
int validerSaisi(int valeurMin, int valeurMax, int * valeurSaisi){

    int continuerSaisie = 1;
    char caractereTempo;
    int valeurTempo;

    do {
        printf("Entrez un entier compris entre %d et %d (ou 'Q' pour quitter) : ", valeurMin, valeurMax);

        caractereTempo = getchar();
        if(tolower(caractereTempo) != 'q'){

            ungetc(caractereTempo, stdin);
            scanf("%d", &valeurTempo);
            if (valeurTempo >= valeurMin && valeurTempo <= valeurMax) {
                *valeurSaisi = valeurTempo;
                return 1;
            } else {
                printf("\n Valeur non valide !! ");
            }
        }
    } while (tolower(caractereTempo) != 'q');

    return 0;
}




















/*
Oui, on peut modifier le code pour pouvoir quitter en entrant la touche 'q' . Il faut utiliser la fonction getchar() pour lire la saisie de l'utilisateur car scanf() attend un entier. voici un exemple de code C qui permet de quitter en entrant 'q' :

Copy code
#include <stdio.h>

int main() {
    int val;
    int min = 5;
    int max = 10;
    char input;

    do {
        printf("Entrez un entier compris entre %d et %d (ou 'q' pour quitter) : ", min, max);
        input = getchar();
        if(input != 'q'){
            ungetc(input, stdin);
            scanf("%d", &val);
            if (val >= min && val <= max) {
                printf("Valeur saisie : %d\n", val);
                break;
            } else {
                printf("Valeur non valide, veuillez reessayer\n");
            }
        }
    } while (input != 'q');

    return 0;
}
La fonction ungetc() permet de remettre le caractère lu par getchar() dans le flux d'entrée pour que scanf() puisse le lire. Ainsi, si l'utilisateur entre 'q', la boucle s'arrête. Sinon, si l'utilisateur entre un entier qui se trouve entre min et max, la boucle s'arrête également.


 */
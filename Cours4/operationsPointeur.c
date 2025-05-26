/*****************************************************************************************
    Par        : David Beaulieu
    Revise le  : H2025
    Fichier    : operationsPointeur.c
    Objectifs  :
    Note	   :
*****************************************************************************************/

/****************************************************************************************
*                            AJOUT DES MODULES ET LIBRAIRIES                            *
****************************************************************************************/
#include <stdlib.h>		// Librairie Standard
#include <stdio.h>		// Librairie Entrer - Sortie

/*
    afficher Binaire
    DEF : Fonction qui affiche une valeur en binaire
    PARAMETRES :	- Valeur à afficher en binaire  (TYPE : unsigned long int)

    RETOUR : Aucun
*/
void afficherBinaire(unsigned long int valeurAafficher);


/****************************************************************************************
*                           DÉFINITION DU PROGRAMME PRINCIPALE                          *
****************************************************************************************/
int main(void)
{
    setbuf(stdout, 0);		    // Permets d'afficher les printf en mode débug avec Clion
    unsigned long int espace = 0;           // Un espace mémoire assez grand pour tester
    unsigned long int * ptrEspace = NULL;   // Un pointeur vers cette espace

    unsigned char octet = 0;                // Un espace le plus petit 1 octet
    unsigned char * ptrOctet = NULL;        // Le pointeur le plus petit 1 octet

    int nbOctet = sizeof(espace);           // La taille en octet de cette espace mémoire

    espace = 386500129;                     // Met une valeur démo dans la variable
    afficherBinaire(espace);
    printf("Le nombre d'octet de l'espace %i : \n",nbOctet);
    printf("L'adresse de l'espace : %p, et la valeur est : %lu\n\n",&espace,espace);

    printf("La valeur du pointeur ptrEspace (avant) : %p\n", ptrEspace);
    ptrEspace = &espace;                    //Assigne l'adresse de espace au pointeur
    printf("La valeur du pointeur ptrEspace (apres) : %p, et la valeur pointer %lu\n\n", ptrEspace,*ptrEspace);

    printf("La valeur du pointeur ptrEspace (avant + 1) : %p, et la valeur pointer %lu\n", ptrEspace,*ptrEspace);
    ptrEspace = ptrEspace + 1;              //Incérmenter l'adress du pointeur  aussi faire ptrEspace++
    (*ptrEspace)++;                         //Incrémente le contenue pointé à la nouvelle adresse
    printf("La valeur du pointeur ptrEspace (apres + 1) : %p, et la valeur pointer %lu\n\n", ptrEspace,*ptrEspace);

    ptrEspace--;                    // Revenir a l'adresse d'origine
    ptrOctet = (unsigned char *)ptrEspace;

    printf("La valeur du pointeur ptrEspace (avant) : %p\n", ptrEspace);
    printf("La valeur du pointeur ptrOctet (avant) : %p\n", ptrOctet);
    ptrOctet++;                    //Incérmenter l'adress du pointeur
    printf("La valeur du pointeur ptrOctet (apres) : %p, et la valeur pointer %i\n\n", ptrOctet,*ptrOctet);
    afficherBinaire(espace);
    afficherBinaire(*ptrOctet);

    ptrOctet++;                    //Incérmenter l'adress du pointeur
    printf("La valeur du pointeur ptrOctet (apres) : %p, et la valeur pointer %i\n\n", ptrOctet,*ptrOctet);
    afficherBinaire(espace);
    afficherBinaire(*ptrOctet);

    ptrOctet++;                    //Incérmenter l'adress du pointeur
    printf("La valeur du pointeur ptrOctet (apres) : %p, et la valeur pointer %i\n\n", ptrOctet,*ptrOctet);
    afficherBinaire(espace);
    afficherBinaire(*ptrOctet);


    return EXIT_SUCCESS;  		        // Permet de terminer le programme proprement
}

/****************************************************************************************
/									DEFINITION DES FONCTIONS							*
****************************************************************************************/
/*
    afficher Binaire
    DEF : Fonction qui affiche une valeur en binaire
    PARAMETRES :	- Valeur à afficher en binaire  (TYPE : unsigned long int)

    RETOUR : Aucun
*/
void afficherBinaire(unsigned long int valeurAafficher){

    int nbBits;                    // Nombre de bits du type de la valeur à afficher
    int i;                         // Itérateur de bits

    nbBits = sizeof(unsigned long int) * 8;      // Détermine le nombre de bits du type

    //Parcours les bits de l'entier
    for(i = nbBits-1 ; i>=0; --i){
        printf("%i", (valeurAafficher >> i) & 1);       // Fait un décalage à droite pour mettre le bit à afficher
        if (i % 8 == 0) {
            printf(" ");
        }
    }                                                   // complètement à droite et effectue un masque avec la valeur 1
    // pour retirer la partie de gauche du nombre
    printf("\n");
}



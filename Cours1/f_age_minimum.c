/****************************************************************************************
    Auteur  : David Beaulieu
    Date    : 9 janvier 2022
    Fichier : age_minimum.c

    Description: Validation de l'age minimum. Exemple d'un if-else. 

    NOTE DE L'ENSEIGNANT : Les commentaires de ce module sont des explications, ils ne
                           repr�sentent pas vraiment ce qui est attendu de vous lors
                           de la remise de vos travaux pratiques.

*****************************************************************************************/

/****************************************************************************************
*                               COMMANDE DU PR�PROCESSEUR                               *
****************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h> 

/****************************************************************************************
*                               D�FINTION DES CONSTANTES                                *
****************************************************************************************/
#define AGE_MAJEUR 18

/****************************************************************************************
*                           D�FINTION DU PRGORAMME PRINCIPALE                           *
****************************************************************************************/
int main(void)
{

    int age_courant;

	// Affichage � l'�cran de la question.
    printf("Entrez votre age : ");
    
	// Attente de l'aquisition au clavier.
	scanf("%i", & age_courant);
    
	// Validation de l'age entr�
	if (age_courant >= AGE_MAJEUR)
	{
		// Afichage du r�sultat si la comparaison est vrais.
		printf("\n Voulez-vous une biere ?? \n\n");
	}
    else
    {	// Afichage du r�sultat si la comparaison est fausse. 
		printf("\n Vous n'avez pas le droit d'acheter de l'alcool !!! \n\n");
    }

	
    system("pause");
    return EXIT_SUCCESS;
}




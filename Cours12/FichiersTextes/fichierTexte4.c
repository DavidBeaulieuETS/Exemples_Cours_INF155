/******************************************************************************
	Par        : Frederick Henri, modifié par David Beaulieu
	Revise le  : H2025
	Fichier    : FICHIER TEXTE 4.C
	References : Philippe Drix, chapitre XV
				 Harbison & Steele, chapitre 15

	Objectifs : Un autre exemple de lecture et d'ecriture dans les
				fichiers textes.

	A noter : NDE signifie "Note de l'enseignant" et souligne les commentaires
			  qui ne devraient pas faire normalement partie du code (outre des
			  raisons pedagogiques).

	Il touche aux notions suivantes :
		- Fichiers (Drix, chapitre XV)
******************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/******************************************************************************
							CONSTANTES DE COMPILATION
******************************************************************************/
#define NOM_FICHIER_SOURCE		"../../Cours12/FichiersTextes/M_L_King.txt"
#define NOM_FICHIER_DESTINATION	"../../Cours12/FichiersTextes/dreams.txt"
#define TAILLE_TAMPON			1024
#define CHAINE_CHERCHEE			"I have a dream"




/******************************************************************************
							FONCTION MAIN()
******************************************************************************/
int main(void)
{
	FILE * fichier_source;		/* Pour lire le texte. */
	FILE * fichier_destination;	/* Pour ecrire le texte. */
	char tampon[TAILLE_TAMPON];	/* Pour lire dans le fichier. */

	/*	On ouvre le fichier source. */
	fichier_source = fopen(NOM_FICHIER_SOURCE, "rt");
	if (fichier_source == NULL)
	{
		printf("Impossible d'ouvrir le fichier source.\n");
		return EXIT_FAILURE;
	}


	/*	On lit le fichier source ligne par ligne. */
	while (fgets(tampon, TAILLE_TAMPON, fichier_source) != NULL)
		printf("%s", tampon);
	printf("\n\n");
	

	/*	On se replace au debut du fichier source. */
	fseek(fichier_source, 0, SEEK_SET);


	/*	On ouvre le fichier destination. */
	fichier_destination = fopen(NOM_FICHIER_DESTINATION, "wt");
	if (fichier_destination == NULL)
	{
		printf("Impossible d'ouvrir le fichier destination.\n");
		fclose(fichier_source);
		return EXIT_FAILURE;
	}


	/*	On extrait du fichier source les lignes qui commencent par
		CHAINE_CHERCHEE.
	*/
	while(fgets(tampon, TAILLE_TAMPON, fichier_source))
		if (strncmp(tampon, CHAINE_CHERCHEE, strlen(CHAINE_CHERCHEE)) == 0)
			fputs(tampon, fichier_destination);


	fclose(fichier_source);
	fclose(fichier_destination);

	return EXIT_SUCCESS;
}
/******************************************************************************
	Par        : Frederick Henri, modifié par David Beaulieu
	Revise le  : H2025
	Fichier    : FICHIER TEXTE 2.C
	References : Philippe Drix, chapitre XV
				 Harbison & Steele, chapitre 15

	Objectifs : Ce programme affiche le contenu d'un fichier texte.

	A noter : NDE signifie "Note de l'enseignant" et souligne les commentaires
			  qui ne devraient pas faire normalement partie du code (outre des
			  raisons pedagogiques).

	Il touche aux notions suivantes :
		- Fichiers (Drix, chapitre XV)
******************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/******************************************************************************
						CONSTANTES DE COMPILATION
******************************************************************************/
#define NOM_FICHIER			"../../Cours12/fichiersTextes/FichierHello.c"
#define TAILLE_LIGNE		1024


/******************************************************************************
							FONCTION MAIN()
******************************************************************************/
int main(void)
{
	FILE * fichier;					/* Pointeur du fichier a lire. */
	char ligne_texte[TAILLE_LIGNE];	/* Pour lire dans le fichier. */


	/*	Ouverture du fichier en mode lecture texte (Read Text). */
	if ((fichier = fopen(NOM_FICHIER, "rt")) == NULL)
	{
		printf("Impossible d'ouvrir le fichier %s.\n", NOM_FICHIER);
		system("pause");
		return EXIT_FAILURE;
	}


	/*	Lecture et affichage du contenu du fichier. */
	while (fgets(ligne_texte, TAILLE_LIGNE, fichier) != NULL) {
		printf("%s", ligne_texte);
	}
		
	/*	On afiche que le fichier est termine. */
	if (feof(fichier)) {
		printf("\n<FIN DU FICHIER>");
	}
	else {
		printf("\n<ERREUR LORS DE LA LECTURE>");
	}
		
	printf("\n\n");


	/* Fermeture du fichier. */
	fclose(fichier);

	return EXIT_SUCCESS; 
}
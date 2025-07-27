/******************************************************************************
	Par        : Frederick Henri, modifié par David Beaulieu
	Revise le  : H2025
	Fichier    : FICHIER BINAIRE 2.C
	References : Philippe Drix, chapitre XV
				 Harbison & Steele, chapitre 15

	Objectifs : Ce programme presente l'ecriture en bloc avec le fwrite.

	A noter : NDE signifie "Note de l'enseignant" et souligne les commentaires
			  qui ne devraient pas faire normalement partie du code (outre des
			  raisons pedagogiques).

	Il touche aux notions suivantes :
		- Fichiers (Drix, chapitre XV)
******************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

/******************************************************************************
							CONSTANTES DE COMPILATION
******************************************************************************/
#define NOM_FICHIER		"../../Cours12/FichiersBinaires/Binaire.bin"
#define NB_POINTS		10




/******************************************************************************
							DEFINITIONS DE TYPES
******************************************************************************/
typedef struct
{
	double x, y, z;
} t_point;




/******************************************************************************
								FONCTION MAIN()
******************************************************************************/
int main(void)
{
	FILE * fichier;					/* Pointeur vers le fichier a traiter. */
	int i;							/* Pour iterer sur les ecritures. */
	t_point tab_points[NB_POINTS];	/* Pour inserer et lire. */


	/*	On ouvre le fichier en lecture et ecriture binaire. */
	if ((fichier = fopen(NOM_FICHIER, "w+b")) == NULL)
	{
		fprintf(stderr, "Impossible d'ouvrir le fichier %s.\n", NOM_FICHIER);
		return EXIT_FAILURE;
	}


	/*	On remplit le tableau de points quelconque. */
	for (i = 0; i < NB_POINTS; ++i)
	{
		tab_points[i].x = i;
		tab_points[i].y = i;
		tab_points[i].z = i;
	}

	//ici !!!

	/*	On ecrit le tableau EN ENTIER d'un seul coup. */
	fwrite(tab_points, sizeof(t_point), NB_POINTS, fichier);


	/*	On referme le fichier. */
	fclose(fichier);


	return EXIT_SUCCESS;
}
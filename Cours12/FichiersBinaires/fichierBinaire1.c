/******************************************************************************
	Par        : Frederick Henri, modifié par David Beaulieu
	Revise le  : H2025
	Fichier    : FICHIER BINAIRE 1.C
	References : Philippe Drix, chapitre XV
				 Harbison & Steele, chapitre 15

	Objectifs : Ce programme ecrit 10000 double dans un fichier texte et
				fait de	meme dans un fichier binaire.

	A noter : NDE signifie "Note de l'enseignant" et souligne les commentaires
			  qui ne devraient pas faire normalement partie du code (outre des
			  raisons pedagogiques).

	Il touche aux notions suivantes :
		- Fichiers (Drix, chapitre XV)
******************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <float.h>


/******************************************************************************
						CONSTANTES DE COMPILATION
******************************************************************************/
#define NOM_FICHIER_TEXTE	"../../Cours12/FichiersBinaires/Texte.txt"
#define NOM_FICHIER_BINAIRE	"../../Cours12/FichiersBinaires/Binaire.bin"


/******************************************************************************
							FONCTION MAIN()
******************************************************************************/
int main(void)
{
	FILE * fichier_texte;	/* Pointeur vers le fichier texte. */
	FILE * fichier_binaire;	/* Pointeur vers le fichier binaire. */
	double valeur;
	int i;


	/*	On cree le fichier texte en mode ecriture texte (Write Text). */
	if ((fichier_texte = fopen(NOM_FICHIER_TEXTE, "wt")) == NULL)
	{
		printf("Impossible de creer le fichier %s.\n", NOM_FICHIER_TEXTE);
		return EXIT_FAILURE;
	}


	/*	On cree le fichier binaire en mode ecriture binaire (Write Binary). */
	if ((fichier_binaire = fopen(NOM_FICHIER_BINAIRE, "wb")) == NULL)
	{
		printf("Impossible de creer le fichier %s.\n", NOM_FICHIER_BINAIRE);
		fclose(fichier_texte);
		return EXIT_FAILURE;
	}


	/*	On ecrit 10 double dans les deux fichiers. */
	valeur = DBL_MAX;
	for (i = 0; i < 10; ++i)
	{
		fprintf(fichier_texte, "%f\n", valeur);
		fwrite(&valeur, sizeof(double), 1, fichier_binaire);
	}


	/*	On ferme les deux fichiers. */
	fclose(fichier_texte);
	fclose(fichier_binaire);

	return EXIT_SUCCESS; 
}
/******************************************************************************
	Par        : Frederick Henri, modifié par David Beaulieu
	Revise le  : H2025
	Fichier    : FICHIER BINAIRE 4.C
	References : Philippe Drix, chapitre XV
				 Harbison & Steele, chapitre 15

	Objectifs : Ce programme presente la lecture en bloc dans un fichier
				binaire. La lecture est cependant effectuee dans un tampon
				dont la taille est limitee.

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
#define NOM_FICHIER		"../../Cours12/FichiersBinaires/Doubles.bin"
#define NB_DOUBLES		 1000
#define TAILLE_TAMPON	  256

/******************************************************************************
							FONCTION MAIN()
******************************************************************************/
int main(void)
{
	FILE * fichier;					/* Le fichier de test. */
	double ecrivain;				/* Pour ecrire dans le fichier. */
	double tampon[TAILLE_TAMPON];	/* Pour lire dans le fichier. */
	int nb_lus, i;


	/*	On ouvre le fichier en ecriture binaire. */
	if ((fichier = fopen(NOM_FICHIER, "wb")) == NULL)
	{
		fprintf(stderr, "Impossible d'ouvrir le fichier %s en ecriture.\n",
				NOM_FICHIER);
		return EXIT_FAILURE;
	}


	/*	On ecrit NB_DOUBLES dans le fichier. */
	for (ecrivain = 0; ecrivain < NB_DOUBLES; ++ecrivain)
		fwrite(&ecrivain, sizeof(double), 1, fichier);

	/*	On ferme le fichier. */
	fclose(fichier);


	/*	On ouvre le fichier en lecture binaire. */
	if ((fichier = fopen(NOM_FICHIER, "rb")) == NULL)
	{
		fprintf(stderr, "Impossible d'ouvrir le fichier %s en lecture.\n",
				NOM_FICHIER);
		return EXIT_FAILURE;
	}


	/*	On lit tant que le fread reussit a lire qqch. */
	while ((nb_lus = fread(tampon, sizeof(double), TAILLE_TAMPON, fichier)) > 0)
		for (i = 0; i < nb_lus; ++i)
			printf("%.0f\n", tampon[i]);

	/*	On ferme le fichier. */
	fclose(fichier);


	return EXIT_SUCCESS;
}
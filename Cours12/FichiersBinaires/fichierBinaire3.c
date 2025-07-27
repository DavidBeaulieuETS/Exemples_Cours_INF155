/******************************************************************************
	Par        : Frederick Henri, modifié par David Beaulieu
	Revise le  : H2025
	Fichier    : FICHIER BINAIRE 3.C
	References : Philippe Drix, chapitre XV
				 Harbison & Steele, chapitre 15

	Objectifs : Ce programme presente le fseek et le ftell. Il introduit
				egalement la lecture en bloc (dans un espace allouee par
				allocation programmee).

	A noter : Ce programme utilise le fichier cree par FICHIER BINAIRE2.C.

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
#define NOM_FICHIER		"../../Cours12/FichiersBinaires/Points.bin"

/******************************************************************************
								DEFINITIONS DE TYPE
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
	FILE * fichier;			/* Pointeur vers le fichier a lire. */
	long taille;			/* La taille du fichier. */
	int nb_points;			/* Nombre de points du fichier. */
	t_point * tab;			/* Pour charger les points en memoire. */
	int i;


	/*	On ouvre le fichier en lecture et ecriture binaire. */
	if ((fichier = fopen(NOM_FICHIER, "rb")) == NULL)
	{
		fprintf(stderr, "Impossible d'ouvrir le fichier %s.\n", NOM_FICHIER);
		return EXIT_FAILURE;
	}


	/*	On positionne le curseur de fichier � la fin du fichier. */
	fseek(fichier, 0, SEEK_END);


	/*	On calcule la distance en octets entre le debut du fichier et la
		position courante du curseur. Cette valeur correspond a la taille du
		fichier!
	*/
	taille = ftell(fichier);


	/*	On en deduit le nombre de points dans le fichier. */
	nb_points = taille / sizeof(t_point);


	/*	On alloue la memoire necessaire pour conserver tous les points. */
	tab = (t_point *) malloc(sizeof(t_point) * nb_points);
	if (tab == NULL)
	{
		printf("Impossible d'allouer la memoire.\n");
		fclose(fichier);
		return EXIT_FAILURE;
	}


	/*	On lit tous les points (apres avoir replace le curseur). */
	fseek(fichier, 0, SEEK_SET);
	fread(tab, sizeof(t_point), nb_points, fichier);

	/*	On ferme le fichier. */
	fclose(fichier);


	/*	On affiche tous les points. */
	for (i = 0; i < nb_points; ++i)
		printf("(%f, %f, %f)\n", tab[i].x, tab[i].y, tab[i].z);
	printf("\n");


	/*	On libere la memoire. */
	free(tab);


	return EXIT_SUCCESS;
}
/******************************************************************************
	Par        : Frederick Henri, modifié par David Beaulieu
	Revise le  : H2025
	Fichier    : FICHIER TEXTE 3.C
	References : Philippe Drix, chapitre XV
				 Harbison & Steele, chapitre 15

	Objectifs : Ce programme lit un fichier contenant des points
				dans l'espace. Le format du fichier doit etre :
					nombre de points
					x1 y1 z1
					x2 y2 z2
					...

				Le programme ne valide pas le nombre de points.

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
#define NOM_FICHIER	"../../Cours12/FichiersTextes/Points.txt"




/******************************************************************************
							DEFINITIONS DE TYPES
******************************************************************************/
typedef struct
{
	double x;
	double y;
	double z;
} t_point;


/******************************************************************************
							FONCTION MAIN()
******************************************************************************/
int main(void)
{
	FILE * fichier;				/* Pointeur vers le fichier a lire. */
	int nb_points = 0;			/* Nombre de points dans le fichier. */
	t_point * tab;				/* Pour conserver les points. */
	int i;
	//double patch_VC = 0;	/* Patch pour fscanf VC++ 6.0. */

	/*	On ouvre le fichier en mode lecture texte (Read Text). */
	if ((fichier = fopen(NOM_FICHIER, "rt")) == NULL)
	{
		printf("Impossible d'ouvrir le fichier %s.\n", NOM_FICHIER);
		return EXIT_FAILURE;
	}


	/*	On lit le nombre de points. */
	fscanf(fichier, "%i", &nb_points);


	/*	On alloue la memoire pour charger les points. */
	tab = (t_point *) malloc(sizeof(t_point) * nb_points);
	if (tab == NULL)
	{
		printf("Impossible de charger les points en memoire.\n");
		fclose(fichier);
		return EXIT_FAILURE;
	}


	/*	On charge les points en memoire. */
	for (i = 0; i < nb_points; ++i)
	{
		fscanf(fichier, "%lf", &(tab[i].x));
		fscanf(fichier, "%lf", &(tab[i].y));
		fscanf(fichier, " z=%lf", &(tab[i].z));

        // ou bien
		//fscanf(fichier, "%lf %lf z=%lf", &(tab[i].x),&(tab[i].y),&(tab[i].z));
        // Voir la valeur de retour de scanf
		//printf("Retour du %i fscanf = %i \n",i,fscanf(fichier, "%lf %lf z=%lf", &(tab[i].x),&(tab[i].y),&(tab[i].z)));
	}



	/*	NDE : Ici, on pourrait realiser des operations sur les donnees lues. */
	/*  Voir les valeur dans le débuger pour tester */


	/*	On libere la memoire. */
	free(tab);


	/* On ferme le fichier. */
	fclose(fichier);

	return EXIT_SUCCESS; 
}

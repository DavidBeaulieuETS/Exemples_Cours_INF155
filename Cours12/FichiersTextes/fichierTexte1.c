/******************************************************************************
	Par        : Frederick Henri, modifié par David Beaulieu
	Revise le  : H2025
	Fichier    : FICHIER TEXTE 1.C
	References : Philippe Drix, chapitre XV
				 Harbison & Steele, chapitre 15

	Objectifs : Ce programme cree un fichier contenant un programme	C
				affichant "Hello world!".

	A noter : NDE signifie "Note de l'enseignant" et souligne les commentaires
			  qui ne devraient pas faire normalement partie du code (outre des
			  raisons pedagogiques).

	Il touche aux notions suivantes :
		- Fichiers (Drix, chapitre XV)
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>


/******************************************************************************
							CONSTANTES DE COMPILATION
******************************************************************************/

/* NDE: Essayer de modifier l'extension du fichier pour .txt ou autres*/ 
#define NOM_FICHIER	"../../Cours12/FichiersTextes/FichierHello.c"


/******************************************************************************
							FONCTION MAIN()
******************************************************************************/
int main(void)
{
	FILE * fichier;		/* Pointeur vers le fichier a traiter. */

	/*	On ouvre/cree le fichier en mode ecriture texte (Write Text).		*/
	/* Si le fichier n'est pas dans le repertoire de travail on le creer	*/
	if ((fichier = fopen(NOM_FICHIER, "wt")) == NULL)
	{
		printf("Impossible de creer le fichier %s.\n", NOM_FICHIER);
		return EXIT_FAILURE;
	}


	/* On ecrit le programme dans le fichier. */
	fprintf(fichier, "#include <stdio.h>\n");
	fprintf(fichier, "#include <stdlib.h>\n\n");
	fprintf(fichier, "/***** Programme Principal ******/\n");
	fprintf(fichier, "int main(void)\n");
	fprintf(fichier, "{\n");
	fprintf(fichier, "\tprintf(\"Hello world!\\n\");\n");
	fprintf(fichier, "\treturn EXIT_SUCCESS;\n");
	fprintf(fichier, "}");


	/* On ferme le fichier. */
	fclose(fichier);

	return EXIT_SUCCESS; 
}




/******************************************************************************
/* NDE : Voici la definition de FILE dans stdio.h :
	struct _iobuf
	{
		char *_ptr;
	    int   _cnt;
        char *_base;
        int   _flag;
        int   _file;
        int   _charbuf;
        int   _bufsiz;
        char *_tmpfname;
	};

	typedef struct _iobuf FILE;

	A quoi servent chacun des champs ? Il n'Est pas obligatoire de la savoir,
	il suffit de n'utiliser que les fonctions offertes par stdio.h et celles-ci
	se chargent de modifier ou consulter les bons champs.
******************************************************************************/
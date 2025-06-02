/*****************************************************************************
	Par        : David Baulieu
	Revise le  :
	Fichier    : SourceStructure.c
	Objectifs  : Exercices des strutures imbriqué 
	Note	   :
*****************************************************************************/


/* Inclure au projet les librairies */
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>		/* Librairie Standart */
#include <stdio.h>		/* Librairie Entrer - Sortie */
#include <stdbool.h>
#include <string.h>

/****************************************************************************/
/*							DEFINITIONS DES CONSTANTES						*/
/****************************************************************************/

// Code de l'avertissement parental 
enum CODE_PARENTAL {G, P13, P18};

// Saisson de diffusion d'une saison
enum SAISON {AUT, HIVERS, ETE};
/****************************************************************************/
/*							DEFINITIONS DES TYPES ET STRUCTURES				*/
/****************************************************************************/
typedef struct t_episode {

	char* nom;
	int duree;
	int nb_acteur;
	char** noms_acteurs;
	int code_parental;

}t_episode;

typedef struct t_saison {

	int saison;
	int annee;
	int nb_episode;
	t_episode* tableau_episode;

}t_saison;

typedef struct t_serie {

	char* nom;
	char* producteur;
	int nb_saison;
	t_saison* tableau_saison;

}t_serie;



typedef t_serie* ptr_serie;


/****************************************************************************/
/*							DECLARATION DES FONCTIONS						*/
/****************************************************************************/
// Fonction qui ne fait rien 
// Elle sert uniquement de canvas pour tester et démontrer les expressions
// des strutures
void test_expression_structure(void);

// Du point de vue d’un diffuseur, deux séries sont considérées comme identiques quand 
// elles ont le même nombre de saisons et le même producteur.  
bool serie_identique(t_serie serie_1, t_serie serie_2);

int duree_total_saison(t_saison saison);

/*
t_episode* liste_episode_P18(t_serie serie);
*/
/****************************************************************************/
/*                           PROGRAMME PRINCIPALE                           */
/****************************************************************************/
int main(void) {

	t_serie serie;

	int somme = duree_total_saison(serie.tableau_saison[2]);


	return EXIT_SUCCESS;

}


/****************************************************************************/
/*							DEFINITION DES FONCTIONS						*/
/****************************************************************************/

// Fonction qui ne fait rien 
// Elle sert uniquement de canvas pour tester et démontrer les expressions
// des strutures
void test_expression_structure(void) {

	t_serie serie;

	ptr_serie pointeur_serie;

	serie.nom;				//char*

	serie.tableau_saison;	//t_saison *

	serie.tableau_saison[2].annee;	//int

	serie.tableau_saison[7].tableau_episode[4];		//t_episode

	serie.tableau_saison[3].tableau_episode[1].duree;	//int

	serie.tableau_saison[1].tableau_episode[2].noms_acteurs; // char**

	serie.tableau_saison[1].tableau_episode[0].noms_acteurs[1]; // char*

	pointeur_serie->producteur; //char*
	pointeur_serie->tableau_saison[2].nb_episode; // int 
}


bool serie_identique(t_serie serie_1, t_serie serie_2) {

	if (serie_1.nb_saison == serie_2.nb_saison &&
		strcmp(serie_1.producteur,serie_2.producteur) == 0) {

		return true;
	}
	return false;
}

int duree_total_saison(t_saison saison) {

	int somme_durees = 0;

	for (int i = 0; i < saison.nb_episode; i++) {

		somme_durees = somme_durees + saison.tableau_episode[i].duree;
	}
	return somme_durees;
}

t_episode* episode_18p(t_saison saison, int * nb_episode_trouvee) {

	//crer un tableau de t_episode au pire cas  
	t_episode* tableau_final = (t_episode*)malloc(sizeof(t_episode) * saison.nb_episode);

	int pos_episode = 0;

	for (int i = 0; i < saison.nb_episode; i++) {

		if (saison.tableau_episode[i].code_parental == P18) {
			
			tableau_final[pos_episode] = saison.tableau_episode[i];
			pos_episode++;
		}
	}

	//redimentionne le tableau selon pos_episode

	*nb_episode_trouvee = pos_episode;


	return tableau_final;
}
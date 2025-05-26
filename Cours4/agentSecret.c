/*****************************************************************************************
    Par        : David Beaulieu
    Revise le  : H 2025
    Fichier    : agentSecret.c
    Objectifs  : Présenter un exemple de passage en paramètres
    Note	   :
*****************************************************************************************/

/****************************************************************************************
*                            AJOUT DES MODULES ET LIBRAIRIES                            *
****************************************************************************************/
#include <stdlib.h>		// Librairie Standard
#include <stdio.h>		// Librairie Entrer - Sortie

/****************************************************************************************
*                               DÉFINITION DES CONSTANTES                               *
****************************************************************************************/

/****************************************************************************************
*								DÉCLARATION DES FONCTIONS								*
****************************************************************************************/
/*
    NOM	: echanger codes secret
    DEF : permet à deux agents de s'échanger un code secret si un des deux
            agent arrivent avec un code de 0 l'échange est un échec.
    PARAMETRES :    premier code (int *)
                    deuxième code (int *)
    RETOUR :        1 si l'échange est un succes, 0 sinon.
*/
int echangerCodesSecret(int * code1, int * code2);

/****************************************************************************************
*                           DÉFINITION DU PROGRAMME PRINCIPALE                          *
****************************************************************************************/
int main(void)
{
    setbuf(stdout, 0);		    // Permets d'afficher les printf en mode débug avec Clion
    int codeAgent1 = 1234;
    int codeAgent2 = 5678;
    int missionAccomplie;

    //Les deux agents partent en mission
    printf("Le code de l'agent 1 : %i\n",codeAgent1);
    printf("Le code de l'agent 2 : %i\n\n\n",codeAgent2);

    //Les deux agents se rencontre
    missionAccomplie = echangerCodesSecret(&codeAgent1,&codeAgent2);

    //Les deux agents reviennent de mission
    if (missionAccomplie == 1){
        printf("La est un succes !!!\n");
        printf("Le code de l'agent 1 : %i\n",codeAgent1);
        printf("Le code de l'agent 2 : %i\n",codeAgent2);
    }
    else{
        printf("La mission a echouer !!");
    }
    return EXIT_SUCCESS;  		        // Permet de terminer le programme proprement
}

/****************************************************************************************
/									DEFINITION DES FONCTIONS							*
****************************************************************************************/
/*
    NOM	: echanger codes secret
    DEF : permet à deux messager de s'échanger un code secret si un des deux
            messager arrivent avec un code de 0 l'échange est un échec.
    PARAMETRES :    premier code (int *)
                    deuxième code (int *)
    RETOUR :        1 si l'échange est un succes, 0 sinon.
    SPÉCIFICATION :
*/
int echangerCodesSecret(int * code1, int * code2){

  int tempo;

  // Si les 2 agents on des codes à échanger
  if (*code1 != 0 && *code2 != 0){
      //Permute les valeurs pointées
      tempo = *code1;
      *code1 = *code2;
      *code2 = tempo;

      return 1;    // Retourne un succes
  }
  return 0;        // Retourn un échec
}
/*****************************************************************************************
    Par        : David Beaulieu
    Revise le  :
    Fichier    :
    Objectifs  :
    Note	   :
*****************************************************************************************/

/****************************************************************************************
*                            AJOUT DES MODULES ET LIBRAIRIES                            *
****************************************************************************************/
#include <stdlib.h>		// Librairie Standard
#include <stdio.h>		// Librairie Entrée - Sortie
#include <math.h>       // Librairie de fonctions mathématique
#include <time.h>		// Librairie de gestion du temps, inclut lafonction time()
#include <ctype.h>      // Librairie de classification et de manipulation de caractères
#include <string.h>     // Librairie pour manipuler des chaines de caractères
#include <windows.h>    // Librairie des commandes de windows
#include "t_chrono.h"   // Module d'implémentation d'un chronomètre

/****************************************************************************************
*                               DÉFINITION DES CONSTANTES                               *
****************************************************************************************/
#define MAX_CHAINE 100
#define NB_QUESTIONS_MAX 10
#define NB_CHOIX 3

/****************************************************************************************
*                           DÉFINITION DES STRUCTURES ET TYPES                          *
****************************************************************************************/
typedef struct question {
  char question[MAX_CHAINE];             // L’énoncé de la question
  char reponse[3][MAX_CHAINE];           // Trois choix de réponses
  int indiceReponse;                     // Indice de la bonne réponse (0-2)
  int succes;                            // 1 si bonne réponse la dernière fois
  double dernierTempsReponse;            // Temps de réponse (pour stats ?)
} t_question;

/****************************************************************************************
*								DÉCLARATION DES FONCTIONS								*
****************************************************************************************/
/*
    NOM         : initialiserQuestions
    DEF         : Crée et initialise un ensemble de questions statiques pour faire des tests
*/
int initialiserQuestions(t_question* tabQuestions[]);

/*
    NOM         : ajouterQuestion
    DEF         : Ajoute une nouvelle question au tableau de pointeurs
*/
void ajouterQuestion(t_question* tableau[], int* nbActuelles);

/*
    NOM         : retirerQuestionParIndice
    DEF         : Supprime une question à un indice donné, libère la mémoire, et décale les suivantes
*/
void retirerQuestionParIndice(t_question* tabQuestions[], int* nbActuelles, int indice);

/*
    NOM         : melangerQuestions
    DEF         : Mélange aléatoirement les questions dans le tableau de pointeurs
*/
void melangerQuestions(t_question* tabQuestions[], int nbQuestion);

/*
    NOM         : poserUneQuestion
    DEF         : Affiche une question et ses choix, mesure le temps de réponse, enregistre le résultat.
*/
void poserUneQuestion(t_question * question);

/*
    NOM         : calculerScore
    DEF         : Calcule le score total à partir d’un tableau de questions
*/
int calculerScore(t_question* tab[], int nb);


/*
    NOM         : afficherQuestions
    DEF         : Permet d'afficher les questions d'un tableau de questions
 */
void afficherQuestions(t_question* tabQuestions[], int nbQuestion);

/****************************************************************************************
*                           DÉFINITION DU PROGRAMME PRINCIPALE                          *
****************************************************************************************/
int main() {

    SetConsoleOutputCP(CP_UTF8);        // Définit l'encodage de sortie de la console à UTF-8
    setbuf(stdout, 0);		            // Permets d'afficher les printf en mode débug avec Clion
    srand(time(NULL));	                // Initialisation du générateur aléatoire

    t_question * tableauQuestions[NB_QUESTIONS_MAX];


    int nombreDeQuestion = initialiserQuestions(tableauQuestions);

    for (int i = 0; i < nombreDeQuestion; ++i){


        poserUneQuestion(tableauQuestions[i]);
    }

    printf("\n **** votre score est de %i sur %i\n", calculerScore(tableauQuestions,nombreDeQuestion) , nombreDeQuestion);


    //Test ajouter question
    ajouterQuestion(tableauQuestions, &nombreDeQuestion);

    //Test retirer la questions 2
    //retirerQuestionParIndice(tableauQuestions, &nombreDeQuestion, 2);

    //Test de mélanger les questions
    //melangerQuestions(tableauQuestions, nombreDeQuestion);


    //afficherQuestions(tableauQuestions, nombreDeQuestion);

    return EXIT_SUCCESS;
}

/****************************************************************************************
/									DÉFINITION DES FONCTIONS							*
****************************************************************************************/
/*
    NOM         : ajouterQuestion
    DEF         : Ajoute une nouvelle question au tableau de pointeurs
    PARAMETRES  :
        - t_question* tableau[] : tableau de pointeurs vers questions
        - int* nbActuelles : nombre actuel de questions (sera incrémenté si succès)
    RETOUR      : Aucun
    SPÉCIFICATION :
        - Alloue dynamiquement une nouvelle t_question
        - Lit les données via stdin (scanf / fgets)
        - Ne dépasse pas la taille maximale du tableau
        - Initialise les champs `succes` à 0 et `dernierTempsReponse` à 0
*/
void ajouterQuestion(t_question* tableau[], int* nbActuelles) {

    int rep ;

    if (*nbActuelles >= NB_QUESTIONS_MAX) {
        printf("Limite de questions atteinte (%d).\n", NB_QUESTIONS_MAX);
    }

    t_question* nouvelle = (t_question*)malloc(sizeof(t_question));
    if (nouvelle == NULL) {
        printf("Erreur d’allocation mémoire.\n");
    }

    // Saisie de la question
    fflush(stdin);                                // Permet de vider la mémoire du clavier
    printf("Entrez l'énoncé de la question : ");
    fgets(nouvelle->question, MAX_CHAINE, stdin);
    nouvelle->question[strcspn(nouvelle->question, "\n")] = '\0';  // enlever '\n'

    // Saisie des réponses
    for (int i = 0; i < NB_CHOIX; i++) {
        printf("Choix %i : ", i);
        fgets(nouvelle->reponse[i], MAX_CHAINE, stdin);
        nouvelle->reponse[i][strcspn(nouvelle->reponse[i], "\n")] = '\0';  // enlever '\n'
    }

    // Saisie de l’indice de la bonne réponse

    printf("Indice de la bonne réponse [0 - 2] : ");
    scanf("%d", &rep);

    nouvelle->indiceReponse = rep;

    nouvelle->succes = 0;
    nouvelle->dernierTempsReponse = 0;

    tableau[*nbActuelles] = nouvelle;
    (*nbActuelles)++;

}

/*
    NOM         : melangerQuestions
    DEF         : Mélange aléatoirement les questions dans le tableau de pointeurs
    PARAMETRES  :
        - t_question* tabQuestions[] : tableau de pointeurs vers les questions
        - int nb : nombre de questions dans le tableau
    RETOUR      : aucun
    SPÉCIFICATION :
        - Utilise l’algorithme Fisher-Yates
        - Échange uniquement les pointeurs (pas les structures)
        - Nécessite un srand() initialisé avant l’appel
*/
void melangerQuestions(t_question* tabQuestions[], int nbQuestion) {

    for (int i = nbQuestion - 1; i > 0; i--) {
        int j = rand() % (i + 1);

        // Échange les pointeurs à i et j
        t_question* temp = tabQuestions[i];
        tabQuestions[i] = tabQuestions[j];
        tabQuestions[j] = temp;
    }
}


/*
    NOM         : poserUneQuestion
    DEF         : Affiche une question et ses choix, mesure le temps de réponse, enregistre le résultat.
    PARAMÈTRES  :
        - question : pointeur vers une structure t_question contenant les infos à afficher
    RETOUR      : aucun
    SPÉCIFICATION :
        - Affiche la question et ses 3 choix de réponse.
        - Utilise un chronomètre pour mesurer le temps de réponse avec startChrono/stopChrono.
        - Met à jour le champ `dernierTempsReponse` de la question.
        - Incrémente le compteur `succes` si la réponse donnée est correcte.
        - Affiche un message de validation selon le cas.
*/
void poserUneQuestion(t_question* question) {

    // Affiche l'énoncé de la question
    printf("\n%s\n", question->question);

    // Affiche les 3 choix de réponse
    for (int i = 0; i < NB_CHOIX; i++) {
        printf("  %i) %s\n", i, question->reponse[i]);
    }

    // Démarrage du chronomètre
    t_chrono chrono = initChrono();
    startChrono(chrono);

    // Lecture de la réponse utilisateur
    int reponse;
    printf("Votre réponse [0 - 2] : ");
    scanf("%i", &reponse);

    // Arrêt du chrono et récupération du temps
    stopChrono(chrono);
    question->dernierTempsReponse = getChrono(chrono);

    // Vérifie la validité de la réponse
    if (reponse == question->indiceReponse) {
        printf("Bonne réponse ! (%.2f sec)\n", question->dernierTempsReponse);
        question->succes++;  // Incrémente le compteur de bonnes réponses
    } else {
        printf("Mauvaise réponse. (%.2f sec)\n", question->dernierTempsReponse);
    }

    // Libère le chrono utilisé
    freeChrono(chrono);
}

/*
    NOM         : calculerScore
    DEF         : Calcule le score total à partir d’un tableau de questions
    PARAMÈTRES  :
        - tab : tableau de pointeurs vers des t_question
        - nb  : nombre de questions dans le tableau
    RETOUR      : int (nombre de bonnes réponses)
    SPÉCIFICATION :
        - Parcourt chaque question et ajoute 1 point si `succes > 0`
        - Retourne le total
*/
int calculerScore(t_question* tab[], int nb) {
    int score = 0;

    // Parcourt chaque question pour compter les bonnes réponses
    for (int i = 0; i < nb; i++) {
        if (tab[i]->succes > 0)
            score++;
    }
    return score;
}


/*
    NOM         : retirerQuestionParIndice
    DEF         : Supprime une question à un indice donné, libère la mémoire, et décale les suivantes
    PARAMETRES  :
        - t_question* tabQuestions[] : tableau de pointeurs vers les questions
        - int* nbActuelles : pointeur vers le nombre actuel de questions (sera décrémenté)
        - int indice : position de la question à retirer
    RETOUR      : Aucun
    SPÉCIFICATION :
        - Libère la mémoire de la question ciblée
        - Réorganise le tableau pour combler le trou
        - Met à NULL la dernière case logique
*/
void retirerQuestionParIndice(t_question* tabQuestions[], int* nbActuelles, int indice) {
    if (indice < 0 || indice >= *nbActuelles) {
        printf("Indice invalide. Aucune question supprimée.\n");
    }

    // Libération de la mémoire de la question à supprimer
    free(tabQuestions[indice]);

    // Décalage des éléments suivants
    for (int i = indice; i < *nbActuelles - 1; i++) {
        tabQuestions[i] = tabQuestions[i + 1];
    }

    // Optionnel mais propre : mettre la dernière case logique à NULL
    tabQuestions[*nbActuelles - 1] = NULL;

    // Mise à jour du nombre de questions
    (*nbActuelles)--;
}


/*
    NOM         : afficherQuestions
    DEF         : Permet d'afficher les questions d'un tableau de questions
    PARAMETRES  :
        - t_question* tabQuestions[] : tableau de pointeurs vers les questions
        - int nbQuestion : nombre de questions dans le tableau
    RETOUR      : aucun
 */
void afficherQuestions(t_question* tabQuestions[], int nbQuestion) {
    for (int i = 0; i < nbQuestion; i++) {
        printf("Question %d:\n", i);
        printf("  %s\n", tabQuestions[i]->question);
        for (int j = 0; j < 3; j++) {
            printf("  Reponse[%d]: %s\n", j, tabQuestions[i]->reponse[j]);
        }
        printf("  IndiceReponse: %d\n", tabQuestions[i]->indiceReponse);
        printf("  Succes: %d\n", tabQuestions[i]->succes);
        printf("  DernierTempsReponse: %.2f\n", tabQuestions[i]->dernierTempsReponse);
        printf("\n");
    }
}



/*
    NOM         : initialiserQuestions
    DEF         : Crée et initialise un ensemble de questions statiques
    PARAMETRES  :
        - t_question* tabQuestions[] : tableau de pointeurs de questions (non initialisés)
    RETOUR      :
        - int : nombre de questions réellement ajoutées
    SPÉCIFICATION :
        - Chaque case du tableau reçoit un pointeur valide (malloc)
        - Les chaînes sont copiées avec strcpy
        - À libérer plus tard avec free()
*/
int initialiserQuestions(t_question* tabQuestions[]) {
    int nbQuestionsCreees = 0;

    // Question 1
    tabQuestions[nbQuestionsCreees] = malloc(sizeof(t_question));
    if (tabQuestions[nbQuestionsCreees]) {
        strcpy(tabQuestions[nbQuestionsCreees]->question, "Combien y a-t-il de continents ?");
        strcpy(tabQuestions[nbQuestionsCreees]->reponse[0], "5");
        strcpy(tabQuestions[nbQuestionsCreees]->reponse[1], "6");
        strcpy(tabQuestions[nbQuestionsCreees]->reponse[2], "7");
        tabQuestions[nbQuestionsCreees]->indiceReponse = 2;
        tabQuestions[nbQuestionsCreees]->succes = 0;
        tabQuestions[nbQuestionsCreees]->dernierTempsReponse = 0;
        nbQuestionsCreees++;
    }

    // Question 2
    tabQuestions[nbQuestionsCreees] = malloc(sizeof(t_question));
    if (tabQuestions[nbQuestionsCreees]) {
        strcpy(tabQuestions[nbQuestionsCreees]->question, "Langage compilé avec gcc ?");
        strcpy(tabQuestions[nbQuestionsCreees]->reponse[0], "C");
        strcpy(tabQuestions[nbQuestionsCreees]->reponse[1], "Python");
        strcpy(tabQuestions[nbQuestionsCreees]->reponse[2], "Java");
        tabQuestions[nbQuestionsCreees]->indiceReponse = 0;
        tabQuestions[nbQuestionsCreees]->succes = 0;
        tabQuestions[nbQuestionsCreees]->dernierTempsReponse = 0;
        nbQuestionsCreees++;
    }

    // Question 3
    tabQuestions[nbQuestionsCreees] = malloc(sizeof(t_question));
    if (tabQuestions[nbQuestionsCreees]) {
        strcpy(tabQuestions[nbQuestionsCreees]->question, "Résultat de 3 x 3 ?");
        strcpy(tabQuestions[nbQuestionsCreees]->reponse[0], "6");
        strcpy(tabQuestions[nbQuestionsCreees]->reponse[1], "9");
        strcpy(tabQuestions[nbQuestionsCreees]->reponse[2], "12");
        tabQuestions[nbQuestionsCreees]->indiceReponse = 1;
        tabQuestions[nbQuestionsCreees]->succes = 0;
        tabQuestions[nbQuestionsCreees]->dernierTempsReponse = 0;
        nbQuestionsCreees++;
    }

    // Question 4
    tabQuestions[nbQuestionsCreees] = malloc(sizeof(t_question));
    if (tabQuestions[nbQuestionsCreees]) {
        strcpy(tabQuestions[nbQuestionsCreees]->question, "Quel est l’animal le plus rapide ?");
        strcpy(tabQuestions[nbQuestionsCreees]->reponse[0], "Guépard");
        strcpy(tabQuestions[nbQuestionsCreees]->reponse[1], "Faucon pèlerin");
        strcpy(tabQuestions[nbQuestionsCreees]->reponse[2], "Panthère");
        tabQuestions[nbQuestionsCreees]->indiceReponse = 1;
        tabQuestions[nbQuestionsCreees]->succes = 0;
        tabQuestions[nbQuestionsCreees]->dernierTempsReponse = 0;
        nbQuestionsCreees++;
    }

    // Question 5
    tabQuestions[nbQuestionsCreees] = malloc(sizeof(t_question));
    if (tabQuestions[nbQuestionsCreees]) {
        strcpy(tabQuestions[nbQuestionsCreees]->question, "Combien de bits dans un octet ?");
        strcpy(tabQuestions[nbQuestionsCreees]->reponse[0], "8");
        strcpy(tabQuestions[nbQuestionsCreees]->reponse[1], "16");
        strcpy(tabQuestions[nbQuestionsCreees]->reponse[2], "32");
        tabQuestions[nbQuestionsCreees]->indiceReponse = 0;
        tabQuestions[nbQuestionsCreees]->succes = 0;
        tabQuestions[nbQuestionsCreees]->dernierTempsReponse = 0;
        nbQuestionsCreees++;
    }

    return nbQuestionsCreees;
}
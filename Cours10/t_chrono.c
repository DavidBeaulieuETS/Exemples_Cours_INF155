#include "t_chrono.h"
#include <stdlib.h>
#include <time.h>

/*
    STRUCTURE PRIVÉE : struct_chrono
    Représente l’état interne d’un chronomètre
*/
struct struct_chrono {
    double tickCumul;     // Temps cumulé en ticks (clock cycles)
    double tickAction;    // Tick de la dernière action (init, start, stop, etc.)
    int enMarche;         // Indicateur du statut (1 = en marche, 0 = arrêté)
};

/*
    NOM         : init_chrono
    DEF         : Alloue dynamiquement un chronomètre et l’initialise à 0
    PARAMETRES  : aucun
    RETOUR      : un handle t_chrono initialisé ou NULL en cas d’échec
    SPÉCIFICATION :
        - tickCumul est initialisé à 0
        - tickAction est initialisé à clock() au moment de la création
        - enMarche est mis à 0 (le chrono est arrêté)
*/
t_chrono initChrono(void) {
    t_chrono chrono = malloc(sizeof(struct struct_chrono));
    if (chrono != NULL) {
        chrono->tickCumul = 0;
        chrono->tickAction = clock();
        chrono->enMarche = 0;
    }
    return chrono;
}

/*
    NOM         : startChrono
    DEF         : Démarre ou redémarre le chronomètre (cumule si déjà en marche)
    PARAMETRES  :
        - chrono : handle valide
    RETOUR      : aucun
    SPÉCIFICATION :
        - Si déjà en marche, ajoute le temps écoulé à tickCumul
        - Met à jour tickAction à l’horloge courante
        - Met enMarche à 1
*/
void startChrono(t_chrono chrono) {
    if (chrono->enMarche) {
        chrono->tickCumul += (clock() - chrono->tickAction);
    }
    chrono->tickAction = clock();
    chrono->enMarche = 1;
}

/*
    NOM         : stopChrono
    DEF         : Arrête le chronomètre et cumule le temps écoulé
    PARAMETRES  :
        - chrono : handle valide
    RETOUR      : aucun
    SPÉCIFICATION :
        - Si en marche, ajoute le temps écoulé à tickCumul
        - Met à jour tickAction à l’horloge courante
        - Met enMarche à 0
*/
void stopChrono(t_chrono chrono) {
    if (chrono->enMarche) {
        chrono->tickCumul += (clock() - chrono->tickAction);
    }
    chrono->tickAction = clock();
    chrono->enMarche = 0;
}

/*
    NOM         : resetChrono
    DEF         : Réinitialise le temps cumulé à zéro sans changer l’état
    PARAMETRES  :
        - chrono : handle valide
    RETOUR      : aucun
    SPÉCIFICATION :
        - Remet tickCumul à 0
        - Met à jour tickAction à clock()
*/
void resetChrono(t_chrono chrono) {
    chrono->tickCumul = 0;
    chrono->tickAction = clock();
}

/*
    NOM         : getChrono
    DEF         : Retourne le temps cumulé écoulé en secondes
    PARAMETRES  :
        - chrono : handle valide
    RETOUR      : double, temps en secondes
    SPÉCIFICATION :
        - Si en marche, ajoute le temps écoulé à tickCumul
        - Met à jour tickAction à clock()
*/
double getChrono(t_chrono chrono) {
    if (chrono->enMarche) {
        chrono->tickCumul += (clock() - chrono->tickAction);
    }
    chrono->tickAction = clock();
    return chrono->tickCumul / CLOCKS_PER_SEC;
}

/*
    NOM         : tocChrono
    DEF         : Retourne le temps écoulé depuis la dernière action (en secondes)
    PARAMETRES  :
        - chrono : handle valide
    RETOUR      : double, durée en secondes
    SPÉCIFICATION :
        - Calcul la différence entre clock() courant et tickAction
*/
double tocChrono(t_chrono chrono) {
    return (clock() - chrono->tickAction) / CLOCKS_PER_SEC;
}

/*
    NOM         : getEtatChrono
    DEF         : Indique si le chronomètre est en marche (1) ou arrêté (0)
    PARAMETRES  :
        - chrono : handle valide
    RETOUR      : int (1 ou 0)
    SPÉCIFICATION :
        - Retourne la valeur du champ enMarche
*/
int getEtatChrono(t_chrono chrono) {
    return chrono->enMarche;
}

/*
    NOM         : freeChrono
    DEF         : Libère la mémoire occupée par un chronomètre
    PARAMETRES  :
        - chrono : handle valide à libérer
    RETOUR      : aucun
    SPÉCIFICATION :
        - Appelle free sur le handle fourni
*/
void freeChrono(t_chrono chrono) {
    free(chrono);
}
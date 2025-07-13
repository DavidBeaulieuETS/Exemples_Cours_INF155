#ifndef __t_chrono_H__
#define __t_chrono_H__

/*
    Module de chronométrie
    Fournit un ensemble d’outils pour mesurer des durées d’exécution en secondes.
    Permet de comparer différentes stratégies algorithmiques sur des bases objectives.
    À ne pas utiliser pour du temps réel strict : précision autour de 1/40e de seconde.

    Fonctionnalités disponibles :
        - init_chrono       : constructeur
        - start_chrono      : démarre le chronomètre
        - stopChrono       : arrête le chronomètre
        - reset_chrono      : remet à zéro le temps cumulé
        - get_chrono        : retourne le temps total écoulé
        - tocChrono        : retourne le temps depuis la dernière action
        - getEtat_chrono    : retourne si le chrono est actif
        - freeChrono       : libère la mémoire allouée
*/

#include <time.h>  // pour clock_t si besoin en externe

/* TYPE ABSTRAIT : t_chrono
   L'utilisateur ne manipule que le handle. Il ne doit ni le modifier ni l'explorer. */
typedef struct struct_chrono * t_chrono;

/*
    NOM         : initChrono
    DEF         : Alloue et initialise un chronomètre (arrêté par défaut)
    PARAMETRES  : aucun
    RETOUR      : un handle t_chrono ou NULL si échec
    SPÉCIFICATION :
        - Doit être libéré via freeChrono
        - Fait partie du groupe des actions déclenchant le reset de tocChrono
*/
t_chrono initChrono(void);

/*
    NOM         : start_chrono
    DEF         : Démarre ou redémarre le chronomètre
    PARAMETRES  : chrono : handle valide obtenu via init_chrono
    RETOUR      : aucun
    SPÉCIFICATION :
        - Fait partie du groupe déclenchant le recalcul de tocChrono
*/
void startChrono(t_chrono chrono);

/*
    NOM         : stopChrono
    DEF         : Arrête le chronomètre et conserve le temps cumulé
    PARAMETRES  : chrono : handle valide
    RETOUR      : aucun
    SPÉCIFICATION :
        - Fait partie du groupe déclenchant le recalcul de tocChrono
*/
void stopChrono(t_chrono chrono);

/*
    NOM         : reset_chrono
    DEF         : Réinitialise le temps cumulé à 0
    PARAMETRES  : chrono : handle valide
    RETOUR      : aucun
    SPÉCIFICATION :
        - Ne modifie pas l’état de marche du chrono
        - Fait partie du groupe déclenchant le recalcul de tocChrono
*/
void resetChrono(t_chrono chrono);

/*
    NOM         : getChrono
    DEF         : Retourne le temps total cumulé en secondes
    PARAMETRES  : chrono : handle valide
    RETOUR      : double (secondes)
    SPÉCIFICATION :
        - N’influence pas l’état du chrono
        - Fait partie du groupe déclenchant le recalcul de tocChrono
*/
double getChrono(t_chrono chrono);

/*
    NOM         : tocChrono
    DEF         : Retourne le temps écoulé depuis la dernière action significative
    PARAMETRES  : chrono : handle valide
    RETOUR      : double (secondes)
    SPÉCIFICATION :
        - Actions déclencheuses : init_chrono, start_chrono, stopChrono, reset_chrono, get_chrono
        - Cette fonction ne modifie pas le chrono
*/
double tocChrono(t_chrono chrono);

/*
    NOM         : getEtat_chrono
    DEF         : Retourne si le chrono est en marche (1) ou arrêté (0)
    PARAMETRES  : chrono : handle valide
    RETOUR      : int
    SPÉCIFICATION :
        - N’affecte pas tocChrono
*/
int getEtatChrono(t_chrono chrono);

/*
    NOM         : freeChrono
    DEF         : Libère la mémoire allouée pour le chronomètre
    PARAMETRES  : chrono : handle valide
    RETOUR      : aucun
    SPÉCIFICATION :
        - Après appel, le handle ne doit plus être utilisé
*/
void freeChrono(t_chrono chrono);

#endif
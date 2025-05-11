/*=========================================================*/
/*	Module qui offre l'usage de chronomètres */
/*  en représntation cachée  */

/*  Tout ou presque de  l'interface est naturelle avec init, start,
	stop, reset , get , free  */
/*  La vraie particularité de ces chronomètres, c'est de pouvoir */
/*  donner des temps relatifs à certaines actions. */
/*  la fonction toc retourne le temps passé depuis la dernière */
/*  intervention significative sur ce chronomètre après  un init, */
/*  un strart, un reset, un stop , un get */
/*  Mais les méthodes toc et get_etat ne seront pas prises en compte.*/

/*  Ces chronomètres ont  une précision avérée qui est estimé
	au quarantième de seconde : Ne pensez pas les utiliser pour 
	controler du temps réel machine. 
*/

/*=========================================================*/
/*=========================================================*/

#ifndef  __MODUL_CHRONOS__
#define  __MODUL_CHRONOS__

/*---------------------------------------------------*/

/* type du lien (handle) d'une variable du client pour
/* conserver l'objet donné  par le constructeur init_chrono */
/* qui doit être conservé intact par le client puisqu'il est */
/* nécessaire à toute action ultérieure voulue sur le chronometre */
/* jusqu'à  sa libération explicite */

typedef  struct chrono*  t_chrono ;
/*-----------------------------------------------------*/
/*-----------------------------------------------------*/
/* constructeur , retourne le handle d'un chronometre  */
/*
	ENTRÉE  :  rien
	SORTIE  : : le handle  sur un chrono
	SPÉCIFICATIONS :
	   construit un chronomètre  neuf arrêté
	   retourne la constante symbolique NULL si échec
	   elle fait partie du groupe considéré par toc_chrono

*/
t_chrono init_chrono(void);
/*-----------------------------------------------------*/
/*-----------------------------------------------------*/
/* destructeur,  libère la mémoire occupé par le chronomètre */
/* Le handle ne doit plus être utilisé après cette action */
/*
	ENTRÉE  :   un  handle valide sur un chrono
	SORTIE  : : rien
	SPÉCIFICATIONS :
	   son comportement est imprévisible si le paramètre
	   effectif n'est pas un handle correct obtenu d'init_chrono
*/
void free_chrono(t_chrono);

/*---------------------------------------------------*/
/*---------------------------------------------------*/
/* démarre le chronomètre et le temps cumulé à date est conservé*/
/*
	ENTRÉE  :   un  handle valide sur un chrono
	SORTIE  : : rien
	SPÉCIFICATIONS :
       elle fait partie du groupe considéré par toc_chrono
	   le comportement est imprévisible si le paramètre
	   effectif n'est pas un handle correct obtenu d'init_chrono
*/
void start_chrono (t_chrono);

/*-----------------------------------------------------*/
/*---------------------------------------------------*/
/* arrête le chronomètre  et le temps cumulé à date est conservé */
/*
	ENTRÉE  :   un  handle valide sur un chrono
	SORTIE  : : rien
	SPÉCIFICATIONS :
       elle fait partie du groupe considéré par toc_chrono
	   le comportement est imprévisible si le paramètre
	   effectif n'est pas un handle correct obtenu d'init_chrono
*/
void stop_chrono (t_chrono);

/*-----------------------------------------------------*/
/*---------------------------------------------------*/
/* le temps cumulé est remis à 0 */
/* elle n'influence pas la marche du chronomètre */
/*
	ENTRÉE  :   un  handle  valide sur un chrono
	SORTIE  : : rien
	SPÉCIFICATIONS :
       elle fait partie du groupe considéré par toc_chrono
	   le comportement est imprévisible si le paramètre
	   effectif n'est pas un handle correct obtenu d'init_chrono
*/
void reset_chrono (t_chrono);

/*-----------------------------------------------------*/
/*---------------------------------------------------*/
/* retourne le temps cumulé à date */
/* elle n'influence pas la marche du chronomètre */
/*
	ENTRÉE  :   un  handle valide sur un chrono
	SORTIE  : : rien
	SPÉCIFICATIONS :
       elle fait partie du groupe considéré par toc_chrono
	   le comportement est imprévisible si le paramètre
	   effectif n'est pas un handle correct obtenu d'init_chrono
*/
double get_chrono( t_chrono); 

/*-----------------------------------------------------*/
/*---------------------------------------------------*/
/* retourne le temps passé depuis la dernière intervention */
/* sur le chronometre. Valable après un init, un start, */
/* un reset, un get et un stop.   */
/*
	ENTRÉE  :   un  handle valide sur un chrono
	SORTIE  : : rien
	SPÉCIFICATIONS :
       elle ne fait pas partie du groupe considéré par toc_chrono
	   le comportement est imprévisible si le paramètre
	   effectif n'est pas un handle correct obtenu d'init_chrono
*/
double toc_chrono( t_chrono);

/*-----------------------------------------------------*/
/*---------------------------------------------------*/
/* retourne 1 s'il fonctionne et 0 sinon   */
/*
	ENTRÉE  :   un  handle valide sur un chrono
	SORTIE  : : rien
	SPÉCIFICATIONS :
       elle ne  fait PAS partie du groupe considéré par toc_chrono
	   le comportement est imprévisible si le paramètre
	   effectif n'est pas un handle correct obtenu d'init_chrono
*/
int get_etat( t_chrono);

/*---------------------------------------------------*/
#endif
/*---------------------------------------------------*/

/*=========================================================*/
/*	Module qui offre l'usage de chronom�tres */
/*  en repr�sntation cach�e  */

/*  Tout ou presque de  l'interface est naturelle avec init, start,
	stop, reset , get , free  */
/*  La vraie particularit� de ces chronom�tres, c'est de pouvoir */
/*  donner des temps relatifs � certaines actions. */
/*  la fonction toc retourne le temps pass� depuis la derni�re */
/*  intervention significative sur ce chronom�tre apr�s  un init, */
/*  un strart, un reset, un stop , un get */
/*  Mais les m�thodes toc et get_etat ne seront pas prises en compte.*/

/*  Ces chronom�tres ont  une pr�cision av�r�e qui est estim�
	au quaranti�me de seconde : Ne pensez pas les utiliser pour 
	controler du temps r�el machine. 
*/

/*=========================================================*/
/*=========================================================*/

#ifndef  __MODUL_CHRONOS__
#define  __MODUL_CHRONOS__

/*---------------------------------------------------*/

/* type du lien (handle) d'une variable du client pour
/* conserver l'objet donn�  par le constructeur init_chrono */
/* qui doit �tre conserv� intact par le client puisqu'il est */
/* n�cessaire � toute action ult�rieure voulue sur le chronometre */
/* jusqu'�  sa lib�ration explicite */

typedef  struct chrono*  t_chrono ;
/*-----------------------------------------------------*/
/*-----------------------------------------------------*/
/* constructeur , retourne le handle d'un chronometre  */
/*
	ENTR�E  :  rien
	SORTIE  : : le handle  sur un chrono
	SP�CIFICATIONS :
	   construit un chronom�tre  neuf arr�t�
	   retourne la constante symbolique NULL si �chec
	   elle fait partie du groupe consid�r� par toc_chrono

*/
t_chrono init_chrono(void);
/*-----------------------------------------------------*/
/*-----------------------------------------------------*/
/* destructeur,  lib�re la m�moire occup� par le chronom�tre */
/* Le handle ne doit plus �tre utilis� apr�s cette action */
/*
	ENTR�E  :   un  handle valide sur un chrono
	SORTIE  : : rien
	SP�CIFICATIONS :
	   son comportement est impr�visible si le param�tre
	   effectif n'est pas un handle correct obtenu d'init_chrono
*/
void free_chrono(t_chrono);

/*---------------------------------------------------*/
/*---------------------------------------------------*/
/* d�marre le chronom�tre et le temps cumul� � date est conserv�*/
/*
	ENTR�E  :   un  handle valide sur un chrono
	SORTIE  : : rien
	SP�CIFICATIONS :
       elle fait partie du groupe consid�r� par toc_chrono
	   le comportement est impr�visible si le param�tre
	   effectif n'est pas un handle correct obtenu d'init_chrono
*/
void start_chrono (t_chrono);

/*-----------------------------------------------------*/
/*---------------------------------------------------*/
/* arr�te le chronom�tre  et le temps cumul� � date est conserv� */
/*
	ENTR�E  :   un  handle valide sur un chrono
	SORTIE  : : rien
	SP�CIFICATIONS :
       elle fait partie du groupe consid�r� par toc_chrono
	   le comportement est impr�visible si le param�tre
	   effectif n'est pas un handle correct obtenu d'init_chrono
*/
void stop_chrono (t_chrono);

/*-----------------------------------------------------*/
/*---------------------------------------------------*/
/* le temps cumul� est remis � 0 */
/* elle n'influence pas la marche du chronom�tre */
/*
	ENTR�E  :   un  handle  valide sur un chrono
	SORTIE  : : rien
	SP�CIFICATIONS :
       elle fait partie du groupe consid�r� par toc_chrono
	   le comportement est impr�visible si le param�tre
	   effectif n'est pas un handle correct obtenu d'init_chrono
*/
void reset_chrono (t_chrono);

/*-----------------------------------------------------*/
/*---------------------------------------------------*/
/* retourne le temps cumul� � date */
/* elle n'influence pas la marche du chronom�tre */
/*
	ENTR�E  :   un  handle valide sur un chrono
	SORTIE  : : rien
	SP�CIFICATIONS :
       elle fait partie du groupe consid�r� par toc_chrono
	   le comportement est impr�visible si le param�tre
	   effectif n'est pas un handle correct obtenu d'init_chrono
*/
double get_chrono( t_chrono); 

/*-----------------------------------------------------*/
/*---------------------------------------------------*/
/* retourne le temps pass� depuis la derni�re intervention */
/* sur le chronometre. Valable apr�s un init, un start, */
/* un reset, un get et un stop.   */
/*
	ENTR�E  :   un  handle valide sur un chrono
	SORTIE  : : rien
	SP�CIFICATIONS :
       elle ne fait pas partie du groupe consid�r� par toc_chrono
	   le comportement est impr�visible si le param�tre
	   effectif n'est pas un handle correct obtenu d'init_chrono
*/
double toc_chrono( t_chrono);

/*-----------------------------------------------------*/
/*---------------------------------------------------*/
/* retourne 1 s'il fonctionne et 0 sinon   */
/*
	ENTR�E  :   un  handle valide sur un chrono
	SORTIE  : : rien
	SP�CIFICATIONS :
       elle ne  fait PAS partie du groupe consid�r� par toc_chrono
	   le comportement est impr�visible si le param�tre
	   effectif n'est pas un handle correct obtenu d'init_chrono
*/
int get_etat( t_chrono);

/*---------------------------------------------------*/
#endif
/*---------------------------------------------------*/

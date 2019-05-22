/**
 * \file ensemble.h
 * \brief 
 */

#ifndef __ENSEMBLE_H_
#define __ENSEMBLE_H_

#include <time.h>

/**
 * \struct Couple
 * \brief structure composée de deux entiers
 */
typedef struct strCouple
{
	int x;
	int y;
} Couple;

/**
 * \struct Ensemble
 * \brief un ensemble est un pointeur sur un couple sur le maillon suivant (on va utiliser les liste chainées non circulaires, on pointe sur NULL à la fin)
 */
typedef struct strEnsemble
{
	Couple c;
	struct strEnsemble *suivant;
} strEnsemble, *Ensemble;

/**
 * \fn Ensemble EnsAlloc()
 * \brief Fonction pour créer un ensemble vide
 * \return Un ensemble initialisé à NULL
 */
Ensemble EnsAlloc();

/**
 * \fn void EnsFree (Ensemble e)
 * \brief Fonction pour désallouer un nsemble
 * \param Ensemble e
 */
void EnsFree(Ensemble e);

/**
 * \fn int EnsEstVide(Ensemble e)
 * \brief Test de vacuité de l'ensemble e
 * \param Ensemble e
 * \return 1 si e est vide, 0 sinon
 */
int EnsEstVide(Ensemble e);

/**
 * \fn Ensemble EnsAjoute(Couple c, Ensemble e)
 * \brief Ajoute le couple c à l'ensemble e en tête (le couple c deviendra le 1er élément du nouvel ensemble)
 * \param Couple c
 * \param Ensemble e
 * \return un nouvel ensemble avec le couple c comme 1er element et suivi des elements de e
 */
Ensemble EnsAjoute(Couple c, Ensemble e);

/**
 * \fn Ensemble EnsSuppr(Couple co, Ensemble e)
 * \brief Supprime un couple de l'ensemble (pour la suite du projet il n'y aura pas de doublons dans les ensembles, donc on retire un seul couple dans e)
 * \param Couple co que l'on va retirer dans e
 * \param Ensemble e dont on va chercher et supprimer le couple c si il existe dans e
 * \return Un nouvel ensemble ou l'on a eventuellement enlever le couple c dans e
 */
Ensemble EnsSuppr(Couple co, Ensemble e);

/**
 * \fn int EnsEstDans(Couple co, Ensemble e)
 * \brief Test de présence d'un couple dans un ensemble
 * \param Couple co dont on veut savoir si il est présent dans l'ensemble e
 * \param Ensemble e ou l'on va effectuer le test
 * \return 1 si le couple est présent dans e, 0 sinon
 */
int EnsEstDans(Couple co, Ensemble e);

/**
 * \fn int EnsTaille(Ensemble e)
 * \brief fonction le nombre de couples de l'ensemble e 
 * \param Ensemble e
 * \return
 */
int EnsTaille(Ensemble e);

/**
 * \fn Couple iEmeElement(Ensemble e, int indice)
 * \brief parcours l'ensemble e et s'arrete au couple dont la position dans e est egale a indice
 * \param Ensemble e dont on veut le ieme element
 * \param int indice, 0 est le 1er element de l'ensemble
 * \pre 0 <= indice <= taille-1
 * \return le couple en position indice
 */
Couple iEmeElement(Ensemble e, int indice);

/**
 * \fn Ensemble EnsTirage(Ensemble e)
 * \brief tire un couple aléatoirement dans l'ensemble e, et le retire de l’ensemble
 * \param Ensemble e
 * \return un nouvel ensemble dont a retiré un couple au hasard
 */
Ensemble EnsTirage(Ensemble e);

#endif

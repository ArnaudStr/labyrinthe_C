/**
 * \file cheminlab.h
 * \brief
 */

#ifndef __CHEMINLAB_H_
#define __CHEMINLAB_H_

#include "genlab.h"
#include "graph.h"

/**
 * \fn bool deplacement_possible(matrice m,  Couple case_cible, Ensemble chemin)
 * \brief Teste si un deplacement est possible
 * \param matrice m
 * \param Couple case_cible pour savoir si un deplacement est possible vers cette case (si il n'y pas de mur et qu'on n'est pas encore allé dans cette case)
 * \param Ensemble chemin parcouru 
 * \return 1 si le deplacement est possible, 0 sinon
 */
bool deplacement_possible(matrice m,  Couple case_cible, Ensemble chemin);


/**
 * \fn bool avancee_possible(matrice m, Couple case_courrante, Ensemble chemin)
 * \brief Teste si on peut avancer en prenant notre position actuelle dans le labyrinthe
 * \param matrice m
 * \param Couple case_courrante qui est la case dans laquelle on se situe
 * \param Ensemble chemin parcouru
 * \return 1 si on peut avancer, 0 sinon
 */
bool avancee_possible(matrice m, Couple case_courrante, Ensemble chemin);


/**
 * \fn Ensemble cheminAleatoire(matrice m, Ensemble chemin, bool visuGen)
 * \brief Trouve un chemin reliant l'entrée à la sortie du labyrinthe
 * \param matrice m
 * \param Ensemble chemin dont on va ajouter au fur et a mesure les cases visitées
 * \param bool visuGen indique si l'on doit afficher la generation du chemin
 * \return Un ensemble de position représentant le chemin trouvé
 */
Ensemble cheminAleatoire(matrice m, Ensemble chemin, bool visuGen);

/**
 * \fn void draw_chemin(matrice m, Ensemble chemin);
 * \brief Fonction pour afficher un chemin a partir d'un ensemble de positions
 * \param matrice m
 * \param Ensemble chemin Ensemble contenant toutes les cases du chemin a afficher
 * \return Un ensemble initialisé à NULL
 */
void draw_chemin(matrice m, Ensemble chemin);

#endif

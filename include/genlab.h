/**
 * \file genlab.h
 * \brief
 */

#ifndef __GENLAB_H_
#define __GENLAB_H_

#include "matrice.h"

/**
 * \fn int estConstructible (matrice m, int x, int y) 
 * \brief teste si une case de la matrice est constructible
 * \param matrice m
 * \param int x (indice de ligne de la case)
 * \param int y (indice de colonne de la case)
 * \return 1 si la case est constructible, 0 sinon
 */
bool estConstructible (matrice m, int x, int y);

/**
 * \fn matrice creer_bords(matrice m)
 * \brief met des 1 (presence d'un mur) dans les "bords" de la matrice, pour generer les bords du labyrinthe par la suite
 * \param matrice m
 * \return matrice m avec des 1 sur les bords
 */
matrice creer_bords(matrice m);

/**
 * \fn matrice murs_initiaux(matrice m)
 * \brief met un certain de nombre (qui dépend de la taille de la matrice) de 1 dans la matrice d'une maniere aleatoire mais avec le plus souvent sur a coté des bords
 * \param matrice m
 * \return matrice m avec ajout de plusieurs murs
 */
matrice murs_initiaux(matrice m);

/**
 * \fn Ensemble cases_constructibles (matrice m)
 * \brief genere un ensemble constitué de toutes les cases constructibles de la matrice m
 * \param matrice m
 * \return Ensemble composé de toutes les coordonées (qui sont des couples) des cases constructibles du futur labyrinthe 
 */
Ensemble cases_constructibles (matrice m);

/**
 * \fn void draw_case (matrice m, int posX, int posY)
 * \brief dessine la case d'indice m.tab[posX][posY]
 * \param matrice m pour le dessin du labyrinthe
 * \param matrice posX indice de ligne de la matrice
 * \param matrice posY indice de colonne de la matrice
 */
void draw_case (matrice m, int posX, int posY);

/**
 * \fn void draw_lab(matrice m)
 * \brief dessine le labyrinthe "d'un coup", on effectue un seul refresh()
 * \param matrice m dont on veut obtenir le labyrinthe
 */
void draw_lab(matrice m);

/**
 * \fn matrice creer_murs (matrice m, bool visuGen, bool visuConstructibles)
 * \brief fonction principale qui va créer des murs a partir des murs initiaux et des tests de constructibilité des cases autour
 * \param matrice m
 * \param bool visuGen qu'on va mettre a 1 si on veut l'affichage du labyrinthe pendant sa génération
 * \param bool visuConstructibles qu'on va mettre a 1 si on veut l'affichage du labyrinthe et des cases constructible pendant sa génération 
 * \return
 */
matrice creer_murs (matrice m, bool visuGen, bool visuConstructibles);



#endif

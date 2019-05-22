/**
 * \file matrice.h
 * \brief 
 */

#ifndef __MATRICE_H_
#define __MATRICE_H_

#include "ensemble.h"

#define VRAI 1==1
#define FAUX 1==0

typedef int bool;

/**
 * \struct matrice
 * \brief Une matrice est composée d'entiers, on va donc considerer une amtrice comme un tableau de tableaux d'entiers
 *  est la hauteur de la matrice (nombre de lignes), l est la largeur (nombre de colonnes)
 * u
 */
typedef struct 
{
	int** tab;
	int h;
	int l;
}matrice;

/**
 * \fn matrice MatAlloc (int h, int l)
 * \brief Allocation d'une matrice de taille h*l initialisée a FAUX
 * \param int h étant la hauteur
 * \param int l étant la largeur
 * \return Matrice avec FAUX dans chaque "case"
 */
matrice MatAlloc (int h, int l);

/**
 * \fn void MatFree (matrice m)
 * \brief Désallocation d'une matrice
 * \param matrice m
 */
void MatFree (matrice m);

/**
 * \fn bool matVal(int x, int y, matrice m)
 * \brief Fonction pour obtenir le booléen en position (x,y) dans la matrice m
 * \param int x indice de ligne (hauteur)
 * \param int y indice de colonne (largeur)
 * \param matrice m
 * \return booléen en position (x,y)
 */
bool matVal(int x, int y, matrice m);

/**
 * \fn matrice MatSet (bool valeur, int x, int y, matrice m)
 * \brief stocke le booléen valeur dans la case de position (x,y) dans m
 * \param bool valeur
 * \param int x indice de ligne de m
 * \param int y indice de colonne de m
 * \param matrice m
 * \return matrice m ou l'on a stocké valeur a la position (x,y)
 */
matrice MatSet (bool valeur, int x, int y, matrice m);

/**
 * \fn int MatriceSauve (matrice m, char* filePath)
 * \brief sauvegarde les valeurs de la matrice m dans le fichier filePath passé en parametre (si il n'existe pas, il sera crée)
 * \param matrice m que l'on veut copier
 * \param char* filePath fichier dans lequel on va stocker les valeurs des entiers qui composent m
 */
int MatriceSauve (matrice m, char* filePath);

/**
 * \fn matrice MatriceLit (char* filePath)
 * \brief stocke dans une matrice les valeurs du fichier filePath passé en paramètre
 * \pre filePath doit etre un fichier valide composé de la taille de la matrice et des entiers de m
 * \return une matrice avec comme taille les 2 premiers entiers du fichiers matrice_lue et comme valeurs les entiers qui suivent (0 = FAUX, 1 = VRAI)
 */
matrice MatriceLit (char* filePath);

#endif

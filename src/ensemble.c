/**
 * \file ensemble.c
 * \brief 
 */

#include <stdio.h>
#include <stdlib.h>
#include "ensemble.h"

Ensemble EnsAlloc()
{
	return NULL;
}

void EnsFree (Ensemble e)
{
    Ensemble temp ;
    while (e != NULL)
    {
        temp = e->suivant;
        free(e);
        e = temp;
    }
}

int EnsEstVide(Ensemble e)
{
	return (e == NULL);
}

Ensemble EnsAjoute(Couple c, Ensemble e)
{
	Ensemble nouvel_element;
	nouvel_element = (strEnsemble*) malloc (sizeof (strEnsemble));
	nouvel_element -> c = c;
	nouvel_element -> suivant = e;
	return nouvel_element;
}

Ensemble EnsSuppr(Couple co, Ensemble e)
{
	Ensemble a_retourner = e;
	Ensemble temp;

	if (e == NULL) return NULL; // ensemble vide	
	else 
	{
		if (e->c.x == co.x && e->c.y == co.y) // suppresion du 1er couple
		{
			a_retourner = e->suivant;
			free(e);			
		}	
			
		else // si ce n'est pas le premier couple
		{
			while (e->suivant != NULL)	
			{
				if (e->suivant->c.x == co.x && e->suivant->c.y == co.y)
				{
					 temp = e->suivant->suivant;
					 free(e->suivant);
					 e->suivant=temp;
				}
				else e=e->suivant;
			}
		}
	}
	return a_retourner;
}
	
int EnsEstDans(Couple co, Ensemble e)
{
	while (e != NULL)
	{
		if (e->c.x == co.x && e->c.y == co.y) return 1;
		else 
		e = e->suivant;
	}
	return 0;
}

int EnsTaille(Ensemble e)
{
	if (EnsEstVide(e)) return 0;
	else return 1 + EnsTaille (e->suivant);
}

Couple iEmeElement(Ensemble e, int indice)
{
	int i;
	Ensemble temp = e;
	for(i = 1 ; i <= indice ; i++)
	{
		temp = temp->suivant;
	}
	return temp->c;
}

Ensemble EnsTirage(Ensemble e)
{
	int taille = EnsTaille(e);
	
	srand(time(NULL)); // initialisation de rand

	int rang_suppr = (rand()%(taille));
	printf("rang a suppr : %d \n", rang_suppr);
    Couple couple_suppr = iEmeElement(e, rang_suppr);
    
    e = EnsSuppr(couple_suppr,e);
    
    return e;
}

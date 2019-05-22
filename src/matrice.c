/**
 * \file matrice.c
 * \brief 
 */

#include <stdio.h>
#include <stdlib.h>
#include "matrice.h"

matrice MatAlloc (int h, int l)
{
	int i, j;
	matrice m;
	m.h = h;
	m.l = l;

	m.tab = (bool **) malloc (h*(sizeof(bool*)));

	for(i = 0; i < m.h ; i++)
	{
		m.tab[i]=(bool *) malloc(l*sizeof(bool));
	}
	
	for (i = 0 ; i < m.h ; i++)
	{
		for (j = 0 ; j < m.l ; j++)
		{
			m.tab[i][j] = FAUX;
		}
    }

	return m;
}

void MatFree (matrice m)
{
	int i;
	for (i=0; i<m.h; i++)
	{
		free(m.tab[i]);
	}
		
	free(m.tab);
}

bool matVal(int x, int y, matrice m)
{
	return m.tab[x][y];
}

matrice MatSet (bool valeur, int x, int y, matrice m)
{
    m.tab[x][y] = valeur;        
	return m;
}

int MatriceSauve (matrice m, char* filePath)
{
    FILE* fichier = NULL ;
    fichier = fopen(filePath,"w"); 
        
    int printed;
    printed = fprintf(fichier,"%d %d\n",m.h, m.l);
          
    int i, j;
    
    for (i = 0 ; i < m.h ; i++)
    {
		for (j = 0 ; j <m.l ; j++)
        {
			printed += fprintf(fichier,"%d ",m.tab[i][j]);
        }
        printed+=fprintf(fichier,"\n");
    }
    return printed;
}

matrice MatriceLit (char* filePath)
{
	matrice m ;
    FILE* fichier = NULL ;
    fichier = fopen(filePath,"r") ;
    int h,l,a,b,f ;
    fscanf (fichier, "%d %d", &h,&l);
    m = MatAlloc(h,l) ;

	while (!feof(fichier))
	{
		for(a = 0; a < m.h ; a++)
		{
			for(b=0; b < m.l ; b++)
			{
				fscanf(fichier,"%d",&m.tab[a][b]);
			}
                    
        }
	}
    
    fclose(fichier);
    return m;
}

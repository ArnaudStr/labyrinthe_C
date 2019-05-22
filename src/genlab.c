/**
 * \file genlab.c
 * \brief 
 */

#include <stdio.h>
#include <stdlib.h>
#include "genlab.h"
#include "graph.h"

bool estConstructible (matrice m, int x, int y) // test si une case est constructible
{
	if (m.tab[x][y] == 1) return 0; //  si la case est un mur, c'est pas constructible
	else
	{
		if (m.tab[x-1][y] == 1) // case au dessus
		{
			if ((m.tab[x][y-1] == 1) || (m.tab[x+1][y-1] == 1) || (m.tab[x+1][y] == 1) || (m.tab[x+1][y+1] == 1) || (m.tab[x][y+1] == 1))
			return 0;
			else return 1;
		}
		else if (m.tab[x][y-1] == 1) // case a gauche
		{
			if ((m.tab[x-1][y] == 1) || (m.tab[x-1][y+1] == 1) || (m.tab[x][y+1] == 1) || (m.tab[x+1][y+1] == 1) || (m.tab[x+1][y] == 1))
			return 0;
			else return 1;
		}
		else if (m.tab[x+1][y] == 1) // case en bas
		{
			if ((m.tab[x][y-1] == 1) || (m.tab[x-1][y-1] == 1) || (m.tab[x-1][y] == 1) || (m.tab[x-1][y+1] == 1) || (m.tab[x][y+1] == 1))
			return 0;
			else return 1;
		}
		else if (m.tab[x][y+1] == 1) // case a droite
		{
			if ((m.tab[x+1][y] == 1) || (m.tab[x+1][y-1] == 1) || (m.tab[x][y-1] == 1) || (m.tab[x-1][y-1] == 1) || (m.tab[x-1][y] == 1))
			return 0;
			else return 1;
		}
		else return 0;
	}
}

matrice creer_bords(matrice m)
{
	int i, j, k, l;
	
	for (j=0; j<m.l; j++)
	{
		m.tab[0][j] = 1;
	}
	
	for (i=2; i<m.h; i++)
	{
		m.tab[i][0] = 1;
	}
	
	for (k=1; k<m.l-2; k++)
	{
		m.tab[m.h-1][k] = 1;
	}
	
	for (l=1; l<m.h; l++)
	{
		m.tab[l][m.l-1] = 1;
	}
	
	return m;
}



matrice murs_initiaux(matrice m)
{
	srand(time(NULL)); // initialisation de rand
	
	int nb_graines;
	nb_graines = (m.h*m.l)/100;
	int i, x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, test;
	
	for(i=0; i<nb_graines; i++)
	{
		 // mur sur le bord haut
		x1 = 1;
		y1 = (rand()%(m.l-3))+2; // nb entre 2 et m.l-2
		
		 // mur sur le bord droit
		x2 = (rand()%(m.h-4))+2; // nb entre 2 et m.h-3 
		y2 = m.l-2;
		
		// mur sur le bord bas
		x3 = m.h-2;
		y3 = (rand()%(m.l-4))+1; //nb entre 1 et m.l-4
		
		// mur sur le bord gauche
		x4 = (rand()%(m.h-5))+3; //nb entre 3 et m.h-3
		y4 = 1;
		
		// mur dans le centre
		x5 = (rand()%(m.h-4))+2; //nb entre 2 et m.h-3
		y5 = (rand()%(m.l-4))+2; //nb  entre 2 et m.l-3
		
		test = (rand()%5)+1; // nb entre 1 et 5
		
		
		switch (test)
		{		
			case 1 :
				m.tab[x1][y1] = 1;
				break;
			
			case 2 :
				m.tab[x2][y2] = 1;
				break;
			
			case 3 :
				m.tab[x3][y3] = 1;
				break;
			
			case 4 :
				m.tab[x4][y4] = 1;
				break;
			
			case 5 :
				m.tab[x5][y5] = 1;
				break;			
		}
	}	
	return m;
}


Ensemble cases_constructibles (matrice m)
{
	srand(time(NULL)); // initialisation de rand

	Ensemble e;
	e = EnsAlloc();
	
	int i,j;
	Couple c;
	
	
	for (i = 1 ; i < m.h -1 ; i++)
	{
		for (j = 1 ; j < m.l -1 ; j++)
		{
			
			if (estConstructible(m, i, j))
			{
				c.x = i;
				c.y = j;
				e=EnsAjoute(c, e);
			}
		}
    }
    
    return e;
}

void draw_case (matrice m, int posX, int posY) //dessine un mur sur la case en position (x,y) de la matrice
{	
	int a, b;
	a = 1000 / m.l;
	b = 800 / m.h;
	
	int taille_case;
	
	if (a <= b)
	{
		taille_case = a;
	}
	else 
	{
		taille_case = b;
	}
			
	int i,x,y;
	x=posX*taille_case;
	y=posY*taille_case;
	
	for (i=0;i<taille_case; i++)
	{
		line(x,y,x+taille_case-1,y);
		y++;
	}    
}

void draw_lab(matrice m)
{
	int a, b;
	a = 1000 / m.l;
	b = 800 / m.h;
	
	int taille_case;
	
	if (a <= b)
	{
		taille_case = a;
	}
	else 
	{
		taille_case = b;
	}
		
	int position_x = 0;
	int position_y = 0;
	
	int i,j;
	
	cleargraph();

	setcolor(newcolor(0,0,0));
	
	for (i = 0 ; i < m.h ; i++)
	{
		for (j = 0 ; j < m.l ; j++)
		{
			if (m.tab[i][j] == 1)
			{
				draw_case(m, j, i);
			}
			
			else
			{
				position_x += taille_case;
			}			
		}
		position_x -= taille_case * m.l;
		position_y += taille_case;
    }
    
	refresh(); // on affiche tout
}

matrice creer_murs (matrice m, bool visuGen, bool visuConstructibles)
{
	srand(time(NULL)); // initialisation de rand
	
	Ensemble e=cases_constructibles(m);
	
	Couple temp;

	int taille, aleatoire;
	
	
	while (e != NULL)
	{
		taille = EnsTaille(e);
		
		aleatoire = (rand()%taille); // entier entre 0 et taille-1	
		
		temp = iEmeElement(e, aleatoire);
		
		m.tab[temp.x][temp.y]=1;
		setcolor(newcolor(0,0,0));
		if(visuGen)
		{
			draw_case(m, temp.y, temp.x);
			refresh();
		}
		
				
		int i,j;
		Couple caseCurrent;

		for(i=temp.x-1;i<=temp.x+1;i++)
		{
			for(j=temp.y-1;j<=temp.y+1;j++)
			{

				caseCurrent.x=i;
				caseCurrent.y=j;
				
				if (estConstructible(m, i, j))
				{
					if(!EnsEstDans(caseCurrent,e))
					{
						e=EnsAjoute(caseCurrent, e);
						if(visuConstructibles)
						{
							setcolor(newcolor(0,1,0));
							draw_case(m, j, i);
							refresh();
						}
					}
				}
				else
				{
					e=EnsSuppr(caseCurrent, e);
					if(m.tab[i][j]==0 && visuConstructibles)
					{
						setcolor(newcolor(1,1,1));
						draw_case(m, j, i);
						refresh();
					}
				}
			}
		}
	}
	if(!visuGen)
	{
		draw_lab(m);
	}

	free(e);
		
	return m;
}



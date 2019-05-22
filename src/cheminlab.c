/**
 * \file cheminlab.c
 * \brief
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cheminlab.h"


Ensemble cheminAleatoire(matrice m, Ensemble chemin, bool visuGen)
{
	Couple case_courrante;
	case_courrante.x=1;
	case_courrante.y=0;
	chemin=EnsAjoute(case_courrante,chemin);
	srand(time(NULL)); // initialisation de rand
	Couple cible;
	setcolor(newcolor(1,0.5,0));
	draw_case(m, case_courrante.y, case_courrante.x);
	refresh();
	
	int i;
	for(i=0; i<EnsTaille(chemin);i++)
	{
		case_courrante=iEmeElement(chemin,i);
			
		if(avancee_possible(m, case_courrante, chemin))
		{
			int aleatoire = (rand()%4);
			
			switch (aleatoire)
			{		
				case 0 :
					cible.x=case_courrante.x-1;
					cible.y=case_courrante.y;
					if(deplacement_possible(m, cible, chemin))
					{
							chemin=EnsAjoute(cible,chemin);
							case_courrante=cible;
					}
					break;
					
				case 1 :
					cible.x=case_courrante.x+1;
					cible.y=case_courrante.y;
					if(cible.x<m.h)
					{
						if(deplacement_possible(m, cible, chemin))
						{
								chemin=EnsAjoute(cible,chemin);
								case_courrante=cible;
						}
					}
					break;
					
				case 2 :
					cible.x=case_courrante.x;
					cible.y=case_courrante.y-1;
					if(cible.y>=0)
					{
						if(deplacement_possible(m, cible, chemin))
						{
								chemin=EnsAjoute(cible,chemin);
								case_courrante=cible;
						}
					}
					break;
					
				case 3 :
					cible.x=case_courrante.x;
					cible.y=case_courrante.y+1;
					if(deplacement_possible(m, cible, chemin))
					{
							chemin=EnsAjoute(cible,chemin);
							case_courrante=cible;
					}
					break;
				
			}
			i=-1;
			setcolor(newcolor(1,0.5,0));
			draw_case(m, case_courrante.y, case_courrante.x);
			refresh();
			
			if(case_courrante.x==m.h-1 && case_courrante.y==m.l-2)
			{
				setcolor(newcolor(1,0.5,0));
				draw_case(m, case_courrante.y, case_courrante.x);
				refresh();
				return chemin;
			}
		}
	}
	return chemin;
}


bool deplacement_possible(matrice m,  Couple case_cible, Ensemble chemin)
{
	if(m.tab[case_cible.x][case_cible.y] || EnsEstDans(case_cible, chemin))
	{
		return 0;
	}

	else
	{
		return 1;
	}
}


bool avancee_possible(matrice m, Couple case_courrante, Ensemble chemin)
{
	Couple cible;
	cible.x=case_courrante.x-1;
	cible.y=case_courrante.y;
	if(deplacement_possible(m, cible, chemin))
	{
			return 1;
	}

	cible.x=case_courrante.x+1;
	cible.y=case_courrante.y;
	if(cible.x<m.h)
	{
		if(deplacement_possible(m, cible, chemin))
		{
				return 1;
		}
	}

	cible.x=case_courrante.x;
	cible.y=case_courrante.y-1;
	if(cible.y>=0)
	{
		if(deplacement_possible(m, cible, chemin))
		{
				return 1;
		}
	}

	cible.x=case_courrante.x;
	cible.y=case_courrante.y+1;
	if(deplacement_possible(m, cible, chemin))
	{
			return 1;
	}
	
	return 0;
}

void draw_chemin(matrice m, Ensemble chemin)
{
	setcolor(newcolor(0,0,0));
	draw_lab(m);
	
	int i;
	for(i=0; i<EnsTaille(chemin); i++)
	{
		setcolor(newcolor(1,0.5,0));
		draw_case(m, iEmeElement(chemin,i).y, iEmeElement(chemin,i).x);
	}
	refresh();
	return ;
}

int main(int argc, char** argv)
{
	if (argc < 2)
	{ 
		printf(" usage : ./genlab [-v] <fichier> \n");
		exit(1);
	}

	bool visuGen=0;
	char* fichier="matrice.txt";
	
	int i;
    for(i=0;i<argc;i++)
    {
		if(strcmp(argv[i],"-v") == 0)
		{
			visuGen=1;
		}
		else
		{
			fichier=argv[i];
		}
	}
	matrice m = MatriceLit (fichier);
		
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
	
	initgraph(taille_case * m.l,taille_case * m.h);
	setcolor(newcolor(0,0,0));
	draw_lab(m);

	Ensemble chemin=EnsAlloc();
		
	chemin=cheminAleatoire(m, chemin, visuGen);
	
	if(!visuGen)
	{
		
		draw_chemin(m, chemin);
	}
	
		waitgraph();
		draw_chemin(m, chemin);

	
	MatFree(m);
	EnsFree(chemin);
		
	waitgraph();
	
	closegraph();
	
			
	return 0;
}

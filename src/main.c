/**
 * \file main.c
 * \brief programme de génération du labyrinthe avec les diffirentes options
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"
#include "genlab.h"

int main(int argc, char** argv)
{	
	if (argc < 2)
	{ 
		printf(" usage : ./genlab [-v] [-d] [-l <largeur>] [-h <hauteur] <fichier> \n");
		exit(1);
	}

    int i=0;
    matrice m;
    m.l=300;
    m.h=200; //valeurs par defaut
    bool visuGen=0;
    bool visuConstructibles=0;
    char* fichier="matrice.txt";

	
    for(i=0;i<argc;i++)
    {
		if(strcmp(argv[i],"-v") == 0)
		{
			visuGen=1;
		}
		else if(strcmp(argv[i],"-d") == 0)
		{
			visuConstructibles=1;
		}
		else if(strcmp(argv[i],"-l") == 0)
		{
			if(i+1<argc)
			{
				m.l = atoi(argv[i+1]);
				i++;
			}
		}
		else if(strcmp(argv[i],"-h") == 0)
		{
			if(i+1<argc)
			{
				m.h = atoi(argv[i+1]);
				i++;
			}			
		}
		else
		{
			fichier=argv[i];
		}
	}
			
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
	
	setcolor(newcolor(0,0,1));
	
	m = MatAlloc (m.h, m.l);
	m = creer_bords(m);

    m = murs_initiaux(m);
    draw_lab(m);
   
	m = creer_murs(m, visuGen, visuConstructibles);
	
	MatriceSauve(m,fichier);
		
	MatFree(m);
		
	waitgraph();
	
	closegraph();
	
	return 0;
}

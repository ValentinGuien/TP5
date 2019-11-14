#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "master.h"
#include "time.h"

// un petit commentaire ?
void initialiser_solution(int solution[NB_COLONNES]) {
	
	int i;	
	srand(time(NULL));

	for(i=0; i<NB_COLONNES; i++)
		solution[i] = (int) (((float) rand()/(float) RAND_MAX)*NB_COULEURS) + 1;
}

// un petit commentaire ?
void initialiser_plateau(int plateau [NB_LIGNES][NB_COLONNES+2]) {
	
	int i,j;
	for (i=0; i<NB_LIGNES; i++) {
		for (j=0; j<NB_COLONNES + 2; j++) 
			plateau[i][j]=0;
	}
}


combinaison compiler_proposition(int proposition[NB_COLONNES], int solution[NB_COLONNES]) {
	
	combinaison c;
	c.bienp=0;
	c.malp=0;
	
	int copie_prop[NB_COLONNES];
	int copie_sol[NB_COLONNES];
	int i, j;

	for (i=0; i<NB_COLONNES; i++) {
		copie_prop[i]=proposition[i];
		copie_sol[i]=solution[i];
	}

	for (i=0; i<NB_COLONNES; i++) {
		if (copie_prop[i] == copie_sol[i]) {
			c.bienp+=1;
			copie_prop[i]=-1;
			copie_sol[i]=-1;
		}
	}
	for (i=0;i<NB_COLONNES; i++) {
		if (copie_prop[i] != -1){
			for (j=0; j<NB_COLONNES && copie_prop[i] != -1; j++) {
				if (copie_prop[i]==copie_sol[j]) {
					c.malp+=1;
					copie_prop[i]=-1;
					copie_sol[j]=-1;
				}
			}
		}
	}
	
	return c;
}

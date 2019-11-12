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
	
	int malpla [NB_COLONNES];
	int k=0;
	int m;

	int i;
	for (i=0; i<NB_COLONNES; i++) {
		if (proposition[i] == solution[i]) {
			c.bienp+=1;
			malpla[k] = i;
			k++;
		}
		else {
			int j=0;
			int trouve = 0;  // 0 si on n'a pas trouve, 1 si on a trouve
			while (j<NB_COLONNES && !trouve) {
				if (proposition[i]==solution[j]) {
					trouve = 1;
					for(m=0; m<NB_COLONNES && trouve==1; m++) {
						if (malpla[m]==j) {
							trouve=0;
							j++;
						}
					}
				}
				else
					j++;
				}
			if (trouve)
				c.malp+=1;
			
		     }
	}
	
	return c;
}

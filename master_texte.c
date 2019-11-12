#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "master.h"

int main(){

	int plateau[NB_LIGNES][NB_COLONNES+2];
	initialiser_plateau(plateau);

	int solution [NB_COLONNES];
	initialiser_solution(solution);
	int y = 0;
	for (y=0; y<NB_COLONNES; y++)
		printf("%d\n", solution[y]);

	int proposition [NB_COLONNES];

	combinaison c;

	int nb_coups = 0;

	printf("Saisir un jeu de couleur comme 1 1 2 3, valider par entree \n");

	do {
		int i,j,k;
		
		printf("? ");

		for (k=0; k<NB_COLONNES; k++) {
			scanf("%d", &proposition[k]);
			plateau[nb_coups][k] = proposition[k];
		}

		c = compiler_proposition(proposition, solution);
		plateau[nb_coups][NB_COLONNES] = c.bienp;
		plateau[nb_coups][NB_COLONNES+1]=c.malp;
		
		printf("=============b=m==\n");
		for (i=0; i<NB_LIGNES;i++) {
			printf("| ");
			for (j=0;j<NB_COLONNES;j++)
				printf("%d ", plateau[i][j]);
			printf("|| %d %d |\n", plateau[i][NB_COLONNES], plateau[i][NB_COLONNES+1]);
		}
		printf("==================\n");

		nb_coups+=1;

	} while ((nb_coups < NB_LIGNES) && (c.bienp != NB_COLONNES));

	return 0;
}


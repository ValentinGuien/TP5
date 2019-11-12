#ifndef master_h
#define master_h

/* DECLARATION DES CONSTANTES SYMBOLIQUES */

#define NB_COLONNES 4
#define NB_LIGNES 10
#define NB_COULEURS 6

/* DECLARATION DES TYPES PERSONNELS */
// et de leur typedef si besoin

typedef struct {
	int bienp;
	int malp;
} combinaison;

/* DECLARATIONS DES METHODES */

void initialiser_solution(int []);
void initialiser_plateau (int [] [NB_COLONNES + 2]);
combinaison compiler_proposition(int [], int []);
// mettre ici les autres declarations

#endif

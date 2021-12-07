#ifndef PUISSANCE4_H
#define PUISSANCE4_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ERREUR_ALLOCATION -1
#define ERREUR_SAISIE -1
#include <time.h>
#define N 5

#define couleur(param) printf("\033[%sm", param)
#define RED "\033[31m"
#define GREEN "\033[32m"
#define ORANGE "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[37m"


/* Commentaire */

int saisieCase(void);

void init(int ttint_plateau[N][N]);

void affiche(int ttint_plateau[N][N]);

int jouer(int ttint_plateau[N][N], int int_joueur, int int_x);

int aGagne(int ttint_plateau[N][N]);

void tourDeJeu(int ttint_plateau[N][N]);

#endif


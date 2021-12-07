#include "puissance4.h"

int saisieCase(void)
{
    int continuer = 1;
    int retour;
    int nb;
    while (continuer == 1)
    {
        retour = scanf("%d", &nb);
        if (retour != 0 && nb >= 0 && nb <= 4)
        {                  // Si le nombre est compris entre 0 et 4, entier)
            continuer = 0; // Valeur saisie est correcte
        }
        else
        {
            fprintf(stderr, "Erreur saisie, veuillez entrer un entier compris entre 0 et 4\n");
            nb = getchar();
        }
    }
    return nb;
}

void init(int ttint_plateau[N][N])
{
    int i;
    int j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            ttint_plateau[i][j] = -1;
        }
    }
    if (ttint_plateau == NULL)
    { // Si la mémoire du tableau n'est pas alloué
        printf("Erreur d'allocation \n");
        exit(ERREUR_ALLOCATION); // Quitte le programme
    }
}


void affiche(int ttint_plateau[N][N])
{
    int i;
    int j;
    printf("   0    1    2    3    4\n");
    printf("╔════╦════╦════╦════╦════╗\n"); // Affichage début du tableau
    for (i = 0; i < N; i++)
    {
        printf("║   ");
        for (j = 0; j < N; j++)
        {
            switch (ttint_plateau[i][j])
            {
            case 1:
                couleur("32"); // Ajout couleur verte
                printf("X");   // Affiche Croix(X)
                couleur("0");  // réinitialisation couleur
                printf("  ║  ");
                break;
            case 2:
                couleur("31"); // ajout couleur rouge
                printf("O");   // Affiche rond(O)
                couleur("0");  // réinitialisation couleur
                printf("  ║  ");
                break;
            default:
                if (i == 0)
                {
                    printf("\033[40;38;5;24m\033[0m ║   "); // Couleur foncé et j(1ere ligne du tableau) va de 7 à 9 (+1 +1 +1)
                }
                if (i == 1)
                {
                    printf("\033[40;38;5;240m\033[0m ║   "); // Couleur foncé et j(2eme ligne du tableau) va de 4 à 6 (+1 +1 +1)
                }
                if (i == 2)
                {
                    printf("\033[40;38;5;240m\033[0m ║   "); // Couleur foncé et j(3eme ligne du tableau) va de 1 à 3 (+1 +1 +1)
                }
                if (i == 3)
                {
                    printf("\033[40;38;5;240m\033[0m ║   "); // Couleur foncé et j(3eme ligne du tableau) va de 1 à 3 (+1 +1 +1)
                }
                if (i == 4)
                {
                    printf("\033[40;38;5;240m\033[0m ║   "); // Couleur foncé et j(3eme ligne du tableau) va de 1 à 3 (+1 +1 +1)
                }
            break;
            }
        }
        if (i == 0 || i == 1 || i == 2 || i == 3)
        {
            printf("\n╠════╬════╬════╬════╬════╣\n"); // Affichage milieu du tableau jusqu'a fin-1
        }
    }
    printf("\n╚════╩════╩════╩════╩════╝\n"); // Affichage fin tableau
}

int jouer(int ttint_plateau[N][N], int int_joueur, int int_x){

    /*if (ttint_plateau[int_x][0] == ' ')
    {
        printf("La colonne est rempli !\n");
        jouer(ttint_plateau,int_joueur, int_x);
    }
    else
    {
        return 1;
    }*/
    if (int_joueur == 1)
    {
        int_joueur = 2;
    }
    else
    {
        int_joueur = 1;
    }
    return 0;
}


    // function to check horizontal win
    int horizontal_win(int ttint_plateau[N][N])
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (ttint_plateau[j][i] == 'X' && ttint_plateau[j + 1][i] == 'X' && ttint_plateau[j + 2][i] == 'X' && ttint_plateau[j + 3][i] == 'X')
            {
                return 1;
            }
            else if (ttint_plateau[j][i] == 'O' && ttint_plateau[j + 1][i] == 'O' && ttint_plateau[j + 2][i] == 'O' && ttint_plateau[j + 3][i] == 'O')
            {
                return 1;
            }
        }
    }
    return 0;
}

// function to check vertical win
int vertical_win(int ttint_plateau[N][N])
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (ttint_plateau[i][j] == 'X' && ttint_plateau[i][j + 1] == 'X' && ttint_plateau[i][j + 2] == 'X' && ttint_plateau[i][j + 3] == 'X')
            {
                return 1;
            }
            else if (ttint_plateau[i][j] == 'O' && ttint_plateau[i][j + 1] == 'O' && ttint_plateau[i][j + 2] == 'O' && ttint_plateau[i][j + 3] == 'O')
            {
                return 1;
            }
        }
    }
    return 0;
}

// function to check diagonal win
int diagonal_win(int ttint_plateau[N][N])
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (ttint_plateau[i][j] == 'X' && ttint_plateau[i + 1][j + 1] == 'X' && ttint_plateau[i + 2][j + 2] == 'X' && ttint_plateau[i + 3][j + 3] == 'X')
            {
                return 1;
            }
            else if (ttint_plateau[i][j] == 'O' && ttint_plateau[i + 1][j + 1] == 'O' && ttint_plateau[i + 2][j + 2] == 'O' && ttint_plateau[i + 3][j + 3] == 'O')
            {
                return 1;
            }
        }
    }
    for (i = 3; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (ttint_plateau[i][j] == 'X' && ttint_plateau[i - 1][j + 1] == 'X' && ttint_plateau[i - 2][j + 2] == 'X' && ttint_plateau[i - 3][j + 3] == 'X')
            {
                return 1;
            }
            else if (ttint_plateau[i][j] == 'O' && ttint_plateau[i - 1][j + 1] == 'O' && ttint_plateau[i - 2][j + 2] == 'O' && ttint_plateau[i - 3][j + 3] == 'O')
            {
                return 1;
            }
        }
    }
    return 0;
}

int aGagne(int ttint_plateau[N][N])
{
    horizontal_win(ttint_plateau);
    vertical_win(ttint_plateau);
    diagonal_win(ttint_plateau);
    return 0;
}

// function that adds a piece to the ttint_plateau
void add_piece(int ttint_plateau[N][N], int column, int int_joueur)
{
    int i;
    for (i = N; i >= 0; i--)
    {
        if (ttint_plateau[column][i] == ' ')
        {
            ttint_plateau[column][i] = int_joueur;
            break;
        }
    }
}

// function to check if column is full
int is_full(int ttint_plateau[N][N], int column)
{
    if (ttint_plateau[column][0] == ' ')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void tourDeJeu(int ttint_plateau[N][N])
{
    int int_joueur;
    int_joueur = 1;
    int nb_tour;
    int win;
    int column;
    column = 1;
    int int_x;
    nb_tour = 0;
    int c = 1;
    while (c == 1)
    {
        printf("Player %d, Entrer la colonne a jouer: ", int_joueur);
        scanf("%d", &int_x);
        int_x = saisieCase();
        add_piece(ttint_plateau, int_x, int_joueur);
        c = is_full(ttint_plateau, column);
        if (c == 1)
        {
            printf("Emplacement déjà pris veuillez ressaissir\n");
        }
    }
    affiche(ttint_plateau);
    win = aGagne(ttint_plateau); // Appelle de la fonction victoire
    if (win != 0)
    {
        printf("\n");
        couleur("7"); // Surligne le texte
        printf("Le joueur %d a gagné !\n", int_joueur);
        couleur("0");
        exit(0);
    }
    else
    {
        jouer(ttint_plateau, int_joueur, int_x);
    }
    nb_tour++; // nb_tour=nb_tour+1; Incrémente nb_tour de 1 a chaque tour
    if (nb_tour == 26)
    {                 // Si le nombre de tour = 10, le morpion est rempli
        couleur("7"); // Surligne le texte
        printf("\n");
        printf("Egalite !\n");
        couleur("0");
        exit(0); // Quitte le programme
    }
    tourDeJeu(ttint_plateau);
}





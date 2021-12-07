#include "puissance4.h"

int main(int argc, char **argv)
{
    system("clear"); 
    int int_joueur;
    int int_x;
    int_x = 1 || 2 || 3 || 4 || 0;
    //int column;
    int_joueur = 1;
    int ttint_plateau[N][N];
    init(ttint_plateau); 
    affiche(ttint_plateau);
    jouer(ttint_plateau, int_joueur, int_x);
    aGagne(ttint_plateau);
    tourDeJeu(ttint_plateau);
        // affiche(ttint_plateau);
        /*
        while (is_over(ttint_plateau, int_joueur) == 0)
        {
            printf("Player %c, Entrer la colonne a jouer: ", int_joueur);
            scanf("%d", &column);
            if (is_valid(column) == 1)
            {
                if (is_full(ttint_plateau, column) == 0)
                {
                    add_piece(ttint_plateau, column, int_joueur);
                    affiche(ttint_plateau);
                    if (check_win(ttint_plateau, int_joueur) == 1)
                    {
                        printf("Player %c a gagné!\n", int_joueur);
                    }
                    else if (check_tie(ttint_plateau) == 1)
                    {
                        printf(" Egalité !\n");
                    }
                    if (int_joueur == 'X')
                    {
                        int_joueur = 'O';
                    }
                    else
                    {
                        int_joueur = 'X';
                    }
                }
                else
                {
                    printf("La colonne est rempli, veuillez jouer autre part !\n");
                }
            }
            else
            {
                printf("Veuillez saisir une colonne comprise entre 0 et 4 !\n");
            }
        }*/
        return 0;
}
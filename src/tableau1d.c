#include "tableau1d.h"

void inversion()
{
    int tab[N];
    int int_i;
    int int_tmp;
    int int_j;
    int_j = N - 1;
    //Saisie élément du tableau
    for (int_i = 0; int_i < N; int_i++)
    {
        printf("Element %d : ", int_i);
        scanf("%d", &tab[int_i]);
    }
    //Affichage tableau avant inversion
    for (int_i = 0; int_i < N; int_i++)
    {
        printf("Avant échange : %d\n", tab[int_i]);
    }
    printf("Procédons à l'inversion \n");
    // Procède à l'inversion des éléments
    for (int_i = 0; int_i < int_j; int_i++, int_j--) {
        
        int_tmp = tab[int_i];
        tab[int_i] = tab[int_j];
        tab[int_j] = int_tmp;
    }
    for (int_i = 0; int_i < N; int_i++){
        printf("Après échange : %d\n", tab[int_i]);
    }
}

void somme(){
    int tab[N];
    int tab2[N];
    int tabres[N];
    int int_i;
    for (int_i = 0; int_i < N; int_i++)
    {
        printf("Element %d : ", int_i);
        scanf("%d", &tab[int_i]);
    }
    for (int_i = 0; int_i < N; int_i++)
    {
        printf("Element %d : ", int_i);
        scanf("%d", &tab2[int_i]);
    }
    for (int_i = 0; int_i < N; int_i++)
    {
        printf("Sommes des élements : %d\n", tabres[int_i] = tab[int_i] + tab2[int_i]);
    }
}

int traversable(){
    int tab[N];
    int int_i;
    int int_index;
    int_index = 0;
    for (int_i = 0; int_i < N; int_i++)
    {
        printf("Element %d : ", int_i);
        scanf("%d", &tab[int_i]);
    }
    while ( int_index < N ) {
        //printf("%d\n", int_index);
        if ( int_index + tab[int_index] < 0 || int_index + tab[int_index] >= N) {
            return 0;
        }
        else if ( int_index + tab[int_index] == (N - 1))
        {
            return 1;
        }
        int_index = tab[int_index] + int_index;
    }
    return 0;
}

//fonction palindrome


int main(int argc, char **argv)
{
    int choix;
    system("clear");
    printf("Quelle programme voulez-vous utiliser ?\n");
    printf(" Programme 1 : Inversion d'un tableau\n");
    printf(" Programme 2 : Somme des éléments de deux tableaux\n");
    printf(" Programme 3 : Tableaux traversable\n");
    scanf("%d", &choix);
    switch (choix)
    {
    case 1:
        inversion();
        break;
    case 2:
        somme();
        break;
    case 3:
        printf("Le tableau %s\n", traversable() ? "est traversable" : "n'est pas traversable");
        break;
    case 4:
        //fonction palindrome
        
        break;
    default : 
    break;
    }
    return 0;
}
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

int isPalindrome(char tchar_array[STR_LEN])
{
    int int_len = strlen(tchar_array); // size of the word or sentence
    int i = 0;                         // count
    int int_res = 1;                   // Stop variable for while

    while (i < int_len / 2 && int_res)
    {
        if (tchar_array[i] != tchar_array[int_len - 1 - i])
        {
            // not a palindrome
            return (0);
        }
        i++;
    }
    // palindrome
    return (1);
}

int main(int argc, char **argv)
{
    int choix;
    char tchar_array[STR_LEN];
    system("clear");
    printf("Quelle programme voulez-vous utiliser ?\n");
    printf(" Programme 1 : Inversion d'un tableau\n");
    printf(" Programme 2 : Somme des éléments de deux tableaux\n");
    printf(" Programme 3 : Tableaux traversable\n");
    printf(" Programme 4 : Palindrome\n");
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
        printf("Veuillez entrer un mot : ");
        scanf("%s", tchar_array);
        printf(" %s\n", isPalindrome(tchar_array) ? "est un palindrome" : "n'est pas un palindrome");        
        break;
    default : 
    break;
    }
    return 0;
}
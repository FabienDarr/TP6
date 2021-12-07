#include "tri.h"

int *init(int taille)
{
    int *tab = malloc(taille * sizeof(int));
    if (tab == NULL)
    {
        printf("Allocation mémoire echoué\n");
        exit(ERREUR_SAISIE);
    }
    return tab;
}

int saisieEntier(void)
{

    int int_retour;
    int nb;

    int_retour = scanf("%d", &nb);

    if (int_retour == 0)
    {
        fprintf(stderr, "Entree incorrecte \n");
        exit(ERREUR_SAISIE);
    }
    return (nb);
}

void aleatoire(int *tab, int taille)
{
    int min;
    int max;

    printf("Entrez les valeurs min et max de votre tableau :\n");
    printf("Min :\n");
    min = saisieEntier();
    printf("Max :\n");
    max = saisieEntier();
    if (taille > 0 && min <= max)
    {
        for (int i = 0; i < taille; i++)
        {
            tab[i] = (rand() % (max - min + 1)) + min; // Valeurs aleatoires entre min et max
        }
    }
    else
    {
        printf("Paramètres non valides\n");
        exit(ERREUR_SAISIE);
    }
}

void afficherTab(int *tab, int taille)
{
    for (int i = 0; i < taille; i++)
    {
        ;
        printf("  %d  ║", tab[i]);
    }
    printf("\n");
}

int *init2(int taille)
{
    int *tab2 = malloc(taille * sizeof(int));
    if (tab2 == NULL)
    {
        printf("Allocation mémoire echoué\n");
        exit(ERREUR_SAISIE);
    }
    return tab2;
}


void copie_tab(int *tab, int *tab2, int taille)
{
    for (int i = 0; i < taille; i++)
    {
        tab2[i] = tab[i];
    }
}

void afficherTab2(int *tab2, int taille)
{
    for (int i = 0; i < taille; i++)
    {
        ;
        printf("  %d  ║", tab2[i]);
    }
    printf("\n");
}


void triInsertion(int *tab, int taille)
{
    int tmp;
    int j;
    for (int i = 0; i < taille; ++i)
    {
        tmp = tab[i];
        for (j = i; j > 0 && tab[j - 1] > tmp; --j)
        {
            tab[j] = tab[j - 1];
        }
        tab[j] = tmp;
    }
}

void fusionner(int *tab, int debut, int milieu, int fin)
{
    int i = 0;
    int max = fin - debut;
    int i_gauche = debut;
    int i_droit = milieu + 1;
    int tabTmp[max];

    while ((i_gauche <= milieu) && (i_droit <= fin))
    {
        if (tab[i_gauche] < tab[i_droit])
        {
            tabTmp[i] = tab[i_gauche];
            i_gauche++;
        }
        else
        {
            tabTmp[i] = tab[i_droit];
            i_droit++;
        }
        i++;
    }

    while (i_gauche <= milieu)
    {
        tabTmp[i] = tab[i_gauche];
        i_gauche++;
        i++;
    }

    while (i_droit <= fin)
    {
        tabTmp[i] = tab[i_droit];
        i_droit++;
        i++;
    }
    for (i = 0; i < max + 1; i++)
    {
        tab[i + debut] = tabTmp[i];
    }
}

void triFusion(int *tab, int debut, int fin)
{
    int milieu;
    if (debut < fin)
    {
        milieu = (debut + fin) / 2;
        triFusion(tab, debut, milieu);
        triFusion(tab, milieu + 1, fin);
        fusionner(tab, debut, milieu, fin);
    }
}

void countingSort(int* tab, int taille, int* min, int* max)
{
    // Find the largest element of the tab
    max = tab[0];
    for (int i = 1; i < taille; i++)
    {
        if (tab[i] > max)
            max = tab[i];
    }

    // The size of count must be at least (max+1) but
    // we cannot declare it as int count(max+1) in C as
    // it does not support dynamic memory allocation.
    // So, its size is provided statically.
    int count[10];

    // Initialize count tab with all zeros.
    for (int i = 0; i <= max; ++i)
    {
        count[i] = 0;
    }

    // Store the count of each element
    for (int i = 0; i < size; i++)
    {
        count[tab[i]]++;
    }

    // Store the cummulative count of each tab
    for (int i = 1; i <= max; i++)
    {
        count[i] += count[i - 1];
    }

    // Find the index of each element of the original tab in count tab, and
    // place the elements in output tab
    for (int i = size - 1; i >= 0; i--)
    {
        output[count[tab[i]] - 1] = tab[i];
        count[tab[i]]--;
    }

    // Copy the sorted elements into original tab
    for (int i = 0; i < size; i++)
    {
        tab[i] = output[i];
    }
}


int main(void)
{
    int *tab2;
    int taille;
    int *tab;
    int* mix;
    int* max;
    clock_t t1;
    clock_t t2;
    float temps_total1;
    //float temps_total2;
    //float temps_total3;
    //float temps_total4;
    float temps_total5;
    //float temps_total6;
    int debut;
    int milieu;
    int fin;
    /*int *nb1;
    int *nb2;*/
    printf("Entrez le nombre de valeurs que vous voulez :\n");
    taille = saisieEntier();
    tab = init(taille);
    aleatoire(tab, taille);
    printf("\nVoici le tableau\n\n");
    afficherTab(tab, taille);
    printf("\n\n");
    tab2 = init2(taille);

    printf("══════════════════════════════════════════════════════════════\n\n");
    copie_tab(tab, tab2, taille);
    printf("Tri par insertion\n");
    t1 = clock();
    triInsertion(tab, taille);
    t2 = clock();
    temps_total1 = (float)(t2 - t1) / CLOCKS_PER_SEC;
    printf("******** tableau trié ********\n");
    afficherTab(tab, taille);
    printf("Le tri par insertion s'est effectué en %f secondes\n\n", temps_total1);
    

    int tab[] = {4, 2, 2, 8, 3, 3, 1};
        int n = sizeof(tab) / sizeof(tab[0]);
        countingSort(tab, n);

        printf("══════════════════════════════════════════════════════════════\n\n");
        copie_tab(tab, tab2, taille);
        printf("Tri à dénombrement\n");
        t1 = clock();
        countingSort(tab, taille, min, max);
        t2 = clock();
        temps_total2 = (float)(t2 - t1) / CLOCKS_PER_SEC;
        printf("******** tableau trié ********\n");
        afficherTab(tab, taille);
        printf("Le tri à dénombrement s'est effectué en %f secondes\n\n", temps_total2);
/*
        printf("══════════════════════════════════════════════════════════════\n\n");
        copie_tab(tab, tab2, taille);
        printf("Tri par selection\n");
        t1 = clock();
        tri_selec(tab, taille);
        t2 = clock();
        temps_total3 = (float)(t2 - t1) / CLOCKS_PER_SEC;
        printf("******** tableau trié ********\n");
        afficherTab(tab, taille);
        printf("Le tri sélection s'est effectué en %f secondes\n\n", temps_total3);

        printf("══════════════════════════════════════════════════════════════\n\n");
        copie_tab(tab, tab2, taille);
        printf("Tri rapide\n");
        debut = 0;
        fin = taille;
        t1 = clock();
        echanger(&nb1, &nb2);
        tri_rapide(tab, debut, fin);
        QuickSort(tab, debut, fin);
        t2 = clock();
        temps_total4 = (float)(t2 - t1) / CLOCKS_PER_SEC;
        printf("******** tableau trié ********\n");
        afficherTab(tab, taille);
        printf("Le tri rapide s'est effectué en %f secondes\n\n", temps_total4);
    */
    printf("══════════════════════════════════════════════════════════════\n\n");
    copie_tab(tab, tab2, taille);
    printf("Tri fusion\n");
    debut = 0;
    milieu = (taille / 2);
    fin = taille;
    t1 = clock();
    fusionner(tab, debut, milieu, fin);
    triFusion(tab, debut, fin);
    t2 = clock();
    temps_total5 = (float)(t2 - t1) / CLOCKS_PER_SEC;
    printf("******** tableau trié ********\n");
    afficherTab(tab, taille);
    printf("Le tri fusion s'est effectué en %f secondes\n\n", temps_total5);

    /*printf("══════════════════════════════════════════════════════════════\n\n");
    copie_tab(tab, tab2, taille);
    printf("Tri Shell\n");
    t1 = clock();
    tri_shell(tab, taille);
    t2 = clock();
    temps_total6 = (float)(t2 - t1) / CLOCKS_PER_SEC;
    printf("******** tableau trié ********\n");
    afficherTab(tab, taille);
    printf("Le tri shell s'est effectué en %f secondes\n\n", temps_total6);
*/
    FILE *fichier = NULL;
    fichier = fopen("temps.txt", "rw");
    if (fichier != NULL)
    {
        // On peut lire et écrire dans le fichier
        fprintf(fichier, "Le tri par insertion s'est effectué en %f secondes\n\n", temps_total1);
        //fprintf(fichier, "Le tri à bulles s'est effectué en %f secondes\n\n", temps_total2);
        //fprintf(fichier, "Le tri sélection s'est effectué en %f secondes\n\n", temps_total3);
        //fprintf(fichier, "Le tri rapide s'est effectué en %f secondes\n\n", temps_total4);
        fprintf(fichier, "Le tri fusion s'est effectué en %f secondes\n\n", temps_total5);
        //fprintf(fichier, "Le tri shell s'est effectué en %f secondes\n\n", temps_total6);
        fclose(fichier);
    }
    else
    {
        // On affiche un message d'erreur
        printf("Impossible d'ouvrir le fichier test.txt");
    }
    free(tab);
    return 1;
}
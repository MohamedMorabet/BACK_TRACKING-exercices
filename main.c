#include <stdio.h>
#include <stdlib.h>

int    is_safe(int *tab, int col, int row)
{
    for (int i = 0; i < col; i++)
    {
        if (tab[i] == row || abs(i - col) == abs(tab[i] - row))
            return 0;
    }
    return 1;
}

void    slove(int *tab, int col, int max)
{
    if (col == max)
    {
        for (int i = 0; i < max; i++)
        {
            printf("%d ", tab[i]);
        }
        printf("\n");
        return ;
    }

    for (int i = 0; i < max; i++)
    {
        if (is_safe(tab, col, i))
        {
            tab[col] = i;
            slove(tab, col + 1, max);
        }
    }
}

int main(int argc, char **argv)
{
    int *tab;
    int n;

    n = atoi(argv[1]);
    tab = calloc(sizeof(int), n);
    slove(tab, 0, n);
    return 0;
}

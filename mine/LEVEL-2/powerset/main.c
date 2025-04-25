#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void    process(int *tab, int *res, int n, int target, int sum, int index, int res_index)
{
    if (index == n - 1 && sum == target)
    {
        for (int i = 0; i < res_index; i++)
        {
            printf("%d", res[i]);
            if (i < res_index - 1)
                printf(" ");
        }
        printf("\n");
        return ;
    }
    if (index >= n || sum > target)
        return ;
    res[res_index] = tab[index];
    process(tab, res, n, target, sum + tab[index], index + 1, res_index + 1); 
    process(tab, res, n, target, sum, index + 1, res_index);
}

int main(int ac, char **av)
{
    int *tab;
    int *res;
    int n;
    int target;

    target = atoi(av[1]);
    n  = ac - 2;
    tab = malloc(sizeof(int) * n);
    res = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        tab[i] = atoi(av[i + 2]);
    process(tab, res, n, target, 0, 0, 0);
}

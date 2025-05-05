#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void    process(int *tab, int *res, int target, int n, int index, int res_i, int total, int *flag)
{
    if (n == index)
    {
        if (total == target)
        {
            for (int i = 0; i < res_i; i++)
            {
                printf("%d", res[i]);
                if (i < res_i - 1)
                    printf(" ");
            }
            printf("\n");
            *flag = 1;
        }
        return ;
    }
    process(tab, res, target, n, index + 1, res_i, total,flag);
    res[res_i] = tab[index];
    process(tab, res, target, n, index + 1, res_i + 1, total + tab[index],flag);
}

int main(int ac , char **av)
{
    int target;
    int *tab;
    int *res;
    int flag = 0;
    int n = ac - 2;

    target = atoi(av[1]);
    res = malloc(sizeof(int) * n);
    tab = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        tab[i] = atoi(av[i + 2]);
    process(tab, res, target, n, 0, 0, 0, &flag);
    if (!flag)
        printf("\n");
    return 0;
}
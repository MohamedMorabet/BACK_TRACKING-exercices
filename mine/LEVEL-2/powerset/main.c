#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// void    process(int *res, int *tab, int target, int n, int index, int res_i, int sum)
// {
//     if (index == n)
//     {
//         if (sum == target)
//         {
//             for (int i = 0; i < res_i; i++)
//             {
//                 printf("%d", res[i]);
//                 if (i < res_i - 1)
//                     printf(" ");
//             }
//             printf("\n");
//         }
//         return ;
//     }
//     process(res, tab, target, n, index + 1, res_i, sum);
//     res[res_i] = tab[index];
//     process(res, tab, target, n, index + 1, res_i + 1, sum + tab[index]);
// }

// int main(int ac, char **av)
// {
//     int *res;
//     int *tab;
//     int n;
//     int target;

//     n = ac - 2;
//     target = atoi(av[1]);
//     res = malloc(sizeof(int) * n);
//     tab = malloc(sizeof(int) * n);
//     for (int i = 0; i < n; i++)
//     {
//         tab[i] = atoi(av[i + 2]);
//     }
//     process(res, tab, target, n, 0, 0, 0);
// }





void    process(int *tab, int *res, int target, int res_i, int index, int total, int n, int *flag)
{
    if (index == n)
    {
        if (total == target && res_i > 0)
        {
            for (int i = 0; i < res_i; i++)
            {
                printf("%d", res[i]);
                if ( i < res_i - 1)
                    printf(" ");
            }
            printf("\n");
            *flag = 1;
        }
        return ;
    }

    process(tab, res, target, res_i, index + 1, total, n, flag);
    res[res_i] = tab[index];
    process(tab, res, target, res_i + 1, index + 1, total + tab[index], n, flag);
}

int main(int ac, char **av)
{
    int target;
    int *tab;
    int *res;
    int flag = 0;

    int n = ac - 2;
    target = atoi(av[1]);
    tab = malloc(sizeof(int) * (n));
    res = malloc(sizeof(int) * (n));
    for (int i = 0; i < n; i ++)
        tab[i] = atoi(av[i + 2]);
    process(tab, res, target, 0, 0, 0, n, &flag);
    if (!flag)
        printf("\n");
    return 0;
}

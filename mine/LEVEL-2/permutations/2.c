#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char    *sort(char *av)
{
    char *result;
    size_t len = strlen(av);
    char    tmp;

    result  = malloc(len + 1);
    for (int i = 0; i < len; i++)
        result[i] = av[i];
    result[len] = '\0';
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len -1; j++)
        {
            if (result[j] > result[j + 1])
            {
                tmp = result[j];
                result[j] = result[j + 1];
                result[j + 1] = tmp;
            }
        }
    }
    return (result);
}

void    process(char *str, char *result, int *used, int index, int res_i, size_t len)
{
    if (res_i == len)
    {
        printf("%s\n", result);
        return ;
    }

    for (int i = 0; i < len; i++)
    {
        if (used[i])
            continue;
        used[i] = 1;
        result[res_i] = str[i];
        process(str, result, used, index + 1, res_i + 1, len);
        used[i] = 0;
    }
}

int main(int ac, char **av)
{
    char    *result;
    char    *str;
    int     *used;

    str = sort(av[1]);
    result = malloc(strlen(str) + 1);
    used = calloc(strlen(str), 1);

    process(str, result, used, 0, 0, strlen(str));
}
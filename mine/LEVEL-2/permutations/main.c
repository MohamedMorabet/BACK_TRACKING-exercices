/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:40:54 by mel-mora          #+#    #+#             */
/*   Updated: 2025/04/23 12:34:45 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char    *sort_str(char *av)
{
    char    *str;
    char    tmp;
    size_t  len = strlen(av);

    str = malloc(len + 1);
    for (int i = 0; i < len; i++)
        str[i] = av[i];
    str[len]= '\0';
    int i = 0;
    while (i < len - 1)
    {
        int j = 0;
        while (j < len - 1)
        {
            if (str[j] > str[j + 1])
            {
                tmp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = tmp;
            }
            j++;
        }
        i++;
    }
    return (str);
}

void    process(int str_i, char *str, int *used, int index, char  *result, size_t len)
{
    if (index >= len)
    {
        printf("%s\n", result);
        return ;
    }

    for (int i = 0; i < len; i++)
    {
        if (used[i])
            continue;
        used[i] = 1;
        result[str_i] = str[i];
        process(str_i + 1, str, used, index + 1, result, len);
        used[i] = 0;
    }
}

int main(int ac, char **av)
{
    char *str;
    int *used;

    if (ac != 2)
    {
        printf("error\n");
        return 1;
    }
    str = sort_str(av[1]);
    char *result = malloc(strlen(str) + 1);
    used = calloc(strlen(result), 1);  //ask gpt later
    process(0, str, used, 0, result, strlen(str));
    return (free(str), 0);
}
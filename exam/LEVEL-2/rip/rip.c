#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_valid(char *str)
{
    int count = 0;
    int i = 0;
    while (str[i])
    {
        if (str[i] == '(')
            count++;
        else if (str[i] == ')')
        {
            count--;
            if (count < 0)
                return 0;
        }
        i++;
    }
    return (count == 0);
}

int get_min_removals(char *str)
{
    int count = 0;
	int removals = 0;
    for (int i = 0; str[i]; i++)
    {
        if (str[i] == '(')
            count++;
        else if (str[i] == ')')
        {
            if (count == 0)
                removals++;
            else
                count--;
        }
    }
    return removals + count;
}

void solve_min(char *str, int index, int removals, char *current)
{
    if (removals < 0)
        return;
    if (str[index] == '\0')
    {
        if (is_valid(current) && removals == 0)
            printf("%s\n", current);
        return;
    }

    char c = str[index];
    current[index] = c;
    solve_min(str, index + 1, removals, current);
	if (c == '(' || c == ')')
    {
        current[index] = '_';
        solve_min(str, index + 1, removals - 1, current);
    }
}

int main(int argc, char **argv)
{
	int len = strlen(argv[1]);
	char *str = calloc(len , 1);
	char *result = calloc(len , 1);
	for (int i = 0; i < len; i++) str[i] = argv[1][i];
	solve_min(str, 0, get_min_removals(str), result);
}
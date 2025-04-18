#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int str_len(char *s)
{
    int len = 0;
    while (s[len] != '\0')
	{
        len++;
    }
    return len;
}

// Simple bubble sort to sort the characters in the string
void sort_string(char *s)
{
    int len = str_len(s);
    for (int i = 0; i < len - 1; i++)
	{
        for (int j = 0; j < len - i - 1; j++)
		{
            if (s[j] > s[j + 1])
			{
                // Swap characters
                char temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}

void	solve(char *str, int index, char *result, int index_result, int total, int *used)
{
	if (index >= total)
	{
		printf("%s\n", result);
		return ;
	}
	for (int i = 0; i < total; i++)
	{
		if (used[i])
			continue;
		
		used[i] = 1;
		result[index_result] = str[i];
		solve(str, index + 1, result, index_result + 1, total, used);
		used[i] = 0;
	}
}

int main(int argc, char **argv)
{
	int len = strlen(argv[1]);

	char *str = malloc(len + 1);
	int *used = calloc(len , 1);
	for (int i = 0; i < len; i++) str[i] = argv[1][i];
	str[len] = '\0';
	sort_string(str);
	char *result = calloc(len, 1);
	solve(str, 0, result , 0, strlen(str), used);
}
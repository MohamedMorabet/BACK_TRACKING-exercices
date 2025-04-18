#include <stdio.h>
#include <stdlib.h>

int	is_safe(int *data, int col, int row)
{
	for (int i = 0; i < col; i++)
	{
		if (data[i] == row || abs(i - col) == abs(data[i] - row))
			return 0;
	}
	return 1;
}

void	solve(int *data, int col, int max)
{
	if (col == max)
	{
		for (int i =0; i < max; i++)
		{
			printf("%d", data[i]);
			if (i < max - 1)
				printf(" ");
		}
		printf("\n");
		return ;
	}
	for (int i = 0; i < max; i++)
	{
		if (is_safe(data, col, i))
		{
			data[col] = i;
			solve(data, col + 1, max);
		}
	}
}

int main(int argc, char **argv) {
    if (argc != 2)
        return 1;

    int n = atoi(argv[1]);
    if (n <= 0)
        return 1;

    int *board = calloc(sizeof(int),  n);
    if (!board)
        return 1;

    solve(board, 0, n);
    free(board);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

void print_subset(int *subset, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d", subset[i]);
        if (i != size - 1)
            printf(" ");
    }
    printf("\n");
}

void solve(int *set, int numofnums, int target, int index, int *subset, int subset_index, int current_sum)
{
	if (index == numofnums - 1 && target == current_sum)
	{
		print_subset(subset, subset_index);
		return ;
	}
	if (index >= numofnums || current_sum > target)
		return ;
	
	subset[subset_index] = set[index];
	solve(set, numofnums, target, index+1, subset, subset_index + 1, current_sum + set[index]);

	solve(set, numofnums, target, index+1, subset, subset_index, current_sum);
}

int main(int argc, char **argv) {
    if (argc < 3) return 1;

    int target = atoi(argv[1]);
    int n = argc - 2;
    int *set = malloc(n * sizeof(int));
    int *subset = malloc(n * sizeof(int)); // subset size is at most n
                                                                                       
    for (int i = 0; i < n; i++)
        set[i] = atoi(argv[i + 2]);

    solve(set, n, target, 0, subset, 0, 0);

    free(set);
    free(subset);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    float x, y;
} City;

float distance(City a, City b)
{
    float dx = a.x - b.x;
    float dy = a.y - b.y;
    return sqrtf(dx * dx + dy * dy);
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}   

void tsp(City *cities, int *perm, int start, int n, float *min_dist)
{
    if (start == n)
    {
        float total = 0.0f;
        for (int i = 0; i < n - 1; i++)
            total += distance(cities[perm[i]], cities[perm[i + 1]]);
        // ✅ Make sure this line is INCLUDED
        total += distance(cities[perm[n - 1]], cities[perm[0]]);

        if (total < *min_dist)
            *min_dist = total;
        return;
    }

    for (int i = start; i < n; i++)
    {
        swap(&perm[start], &perm[i]);
        tsp(cities, perm, start + 1, n, min_dist);
        swap(&perm[start], &perm[i]);
    }
}

int main(void)
{
    City cities[11];
    int perm[11];
    int count = 0;

    while (count < 11 && fscanf(stdin, "%f, %f\n", &cities[count].x, &cities[count].y) == 2)
	{
		perm[count] = count;
		count++;
	}
	for (int i = 0; i < count; i++)
    	printf("city[%d] = %.2f, %.2f\n", i, cities[i].x, cities[i].y);
    float min_dist = 1e9;
    tsp(cities, perm, 0, count, &min_dist);
    printf("%.2f\n", min_dist);
    return 0;
}

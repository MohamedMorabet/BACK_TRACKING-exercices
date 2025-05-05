#include <math.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct t_city
{
    float x, y;
}   City;

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

float distance(City a, City b)
{
    float x = a.x - b.x;
    float y = a.y - b.y;
    return (sqrt(x * x + y * y));
}

void    process(City *cities, int *perm, float *dist, int count, int start)
{
    if (start == count)
    {
        float total = 0.0;
        for (int i = 0; i < count - 1; i++)
        {
            total += distance(cities[perm[i]], cities[perm[i + 1]]);
        }
        total += distance(cities[perm[count - 1]], cities[perm[0]]);
        if (total < *dist)
            *dist = total;
        return ;
    }
    for (int i = start; i < count; i++)
    {
        swap(&perm[start], &perm[i]);
        process(cities, perm, dist, count, start + 1);
        swap(&perm[start], &perm[i]);
    }
}

int main(int ac, char **av)
{
    City cities[11];
    int perm[11];
    float dist;
    int count = 0;

    while (count < 11 && fscanf(stdin, "%f, %f\n", &cities[count].x, &cities[count].y) == 2)
    {
        perm[count] = count;
        count ++;
    }
    dist = 1e9;
    process(cities, perm, &dist, count, 0);
    printf("%.2f\n", dist);
    return 0;
}

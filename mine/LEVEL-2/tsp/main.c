#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef    struct t_city
{
    float x, y;
}   City;

void    swap(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

float    distance(City a, City b)
{
    float   dx = a.x - b.x;
    float   dy = a.y - b.y;
    return (sqrt(dx * dx + dy * dy));
}

void    tsp(City *cities, int *perm, int count, float *dist, int start)
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
        tsp(cities, perm, count, dist, start + 1);
        swap(&perm[start], &perm[i]);
    }
}

int main(int ac, char **av)
{
    float dist;
    City cities[11];
    int perm[11];
    int count = 0;

    while (count < 11 && fscanf(stdin, "%f, %f\n", &cities[count].x, &cities[count].y) == 2)
    {
        perm[count] = count;
        count++;
    }
    dist = 1e9;
    tsp(cities, perm, count, &dist, 0);
    printf("the min distance : %.2f\n", dist);
    return 0;
}
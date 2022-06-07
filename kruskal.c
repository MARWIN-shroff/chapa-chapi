#include <stdio.h>

int cost[10][10], parent[10], min = 0, min_cost = 0, i, j;

int Find(int i)
{
    while (parent[i])
    {
        i = parent[i];
    }
    return i;
}

int Union(int i, int j)
{
    if (i != j)
    {
        parent[j] = i;
        return 1;
    }
    return 0;
}

int main()
{
    int no_edges = 1, n, u, v, a, b;

    printf("Enter the number of nodes : ");
    scanf("%d", &n);

    printf("Enter the cost in adjecency matric : \n");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
            {
                cost[i][j] = 1000;
            }
        }
    }

    while (no_edges < n)
    {
        for (i = 1, min = 1000; i <= n; i++)
        {

            for (j = 1; j <= n; j++)
            {
                if (cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = Find(u);
        v = Find(v);

        if (Union(u, v))
        {
            printf("%d to %d cost %d \n", a, b, min);
            min_cost = min_cost + min;
            no_edges++;
        }

        cost[a][b] = cost[b][a] = 1000;
    }

    printf("Minimum cost is = %d", min_cost);
}
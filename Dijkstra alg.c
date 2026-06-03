#include <stdio.h>
#define INF 9999

int main()
{
    int n, cost[10][10];
    int dist[10], vis[10];
    int i, j, u, min, s;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);

            if(cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    printf("Enter source vertex: ");
    scanf("%d", &s);

    // Initialization
    for(i = 0; i < n; i++)
    {
        dist[i] = INF;
        vis[i] = 0;
    }

    dist[s] = 0;

    // Dijkstra
    for(i = 0; i < n; i++)
    {
        min = INF;

        for(j = 0; j < n; j++)
        {
            if(!vis[j] && dist[j] < min)
            {
                min = dist[j];
                u = j;
            }
        }

        vis[u] = 1;

        for(j = 0; j < n; j++)
        {
            if(!vis[j] &&
               dist[u] + cost[u][j] < dist[j])
            {
                dist[j] =
                dist[u] + cost[u][j];
            }
        }
    }

    printf("\nShortest distances:\n");

    for(i = 0; i < n; i++)
    {
        printf("%d -> %d = %d\n",
               s, i, dist[i]);
    }

    return 0;
}

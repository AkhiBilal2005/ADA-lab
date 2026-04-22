#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define INF 100000000
void floydW(int **dist, int v)
{
    for (int k = 0; k < v; k++) {
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {

                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

int main()
{
    int v;
    printf("No. of vertices: ");
    scanf("%d", &v);

    int **gr = (int **)malloc(v * sizeof(int *));
    for (int i = 0; i < v; i++) {
        gr[i] = (int *)malloc(v * sizeof(int));
    }

    srand(time(0));

    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            if (i == j) {
                gr[i][j] = 0;
            } else {
                int r = rand() % 10;
                if (r < 3)
                    gr[i][j] = INF;
                else
                    gr[i][j] = rand() % 20 + 1;
            }
        }
    }

    printf("\nMatrix:\n");
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            if (gr[i][j] == INF)
                printf("INF ");
            else
                printf("%3d ", gr[i][j]);
        }
        printf("\n");
    }

    clock_t st, end;
    st = clock();
    floydW(gr, v);
    end = clock();
    printf("\nShortest Distance Matrix:\n");
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            if (gr[i][j] == INF)
                printf("INF ");
            else
                printf("%3d ", gr[i][j]);
        }
        printf("\n");
    }
    double t_taken = (double)(end - st) / CLOCKS_PER_SEC;
    printf("\nTime taken: %f sec\n", t_taken);

    for (int i = 0; i < v; i++) {
        free(gr[i]);
    }
    free(gr);
    return 0;
}

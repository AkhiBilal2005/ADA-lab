#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define INF 9999999


int main()
{
    int V;
    printf("Enter no. vertices: ");
    scanf("%d", &V);
    int G[V][V];
    srand(time(0));


    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            if(i == j){
                G[i][j] = 0;
            } else if (j < i){
                G[i][j] = G[j][i];
            } else {
                int r = rand() % 20 + 1;

                if(rand() % 2)
                    G[i][j] = r;
                else
                    G[i][j] = 0;
            }
        }
    }


    printf("Generated Adjacency Matrix:\n");
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            printf("%3d ", G[i][j]);
        }
        printf("\n");
    }

    int no_e = 0;
    bool sel[V];
    memset(sel, false, sizeof(sel));

    sel[0] = true;

    int x, y;
    printf("\nEdge : Weight\n");
    clock_t start = clock();
    while(no_e < V - 1){
        int min = INF;
        x = 0;
        y = 0;

        for(int i = 0; i < V; i++){
            if(sel[i]){
                for(int j = 0; j < V; j++){
                    if(!sel[j] && G[i][j]){
                        if(min > G[i][j]){
                            min = G[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        printf("%d - %d : %d\n", x, y, G[x][y]);
        sel[y] = true;
        no_e++;
    }
    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nExecution time: %f seconds\n", time_taken);

    return 0;
}

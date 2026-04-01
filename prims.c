#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define INF 9999999
#define V 5

int main()
{
    int G[V][V];
    int row, col;
    printf("Enter the adjencancy matrix: \n");
    for(row = 0 ; row < V ; row++){
        for(col = 0 ; col < V ; col++){
            scanf("%d", &G[row][col]);
        }
        printf("\n");
    }
    int no_e;
    int sel[V];
    memset(sel, false, sizeof(sel));
    no_e = 0;
    sel[0] = true;
    int x, y;
    printf("edge : Weight\n");
    while(no_e <V-1){
        int min = INF;
        x = 0;
        y = 0;
        for(int i = 0; i<V ; i++){
            if(sel[i]){
                for (int j = 0; j < V ; j++){
                    if(!sel[j] && G[i][j]){
                        if (min > G[i][j]){
                            min = G[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        printf("%d - %d : %d\n",x,y,G[x][y]);
        sel[y] = true;
        no_e++;
    }
    return 0;
}

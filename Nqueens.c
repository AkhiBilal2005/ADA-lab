#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int x[20], n;
int plc(int k, int i)
{
    for(int j = 1; j < k; j++)
    {
        if(x[j] == i ||
           abs(x[j] - i) == abs(j - k))
            return 0;
    }

    return 1;
}
void nq(int k)
{
    for(int i = 1; i <= n; i++)
    {
        if(plc(k, i))
        {
            x[k] = i;

            if(k == n)
            {
                for(int j = 1; j <= n; j++)
                    printf("%d ", x[j]);

                printf("\n");
            }
            else
            {
                nq(k + 1);
            }
        }
    }
}
int main()
{
    printf("Enter n: ");
    scanf("%d", &n);
    clock_t st, en;
    st = clock();
    nq(1);
    en = clock();
    double tt =
    (double)(en - st) / CLOCKS_PER_SEC;

    printf("\nTime = %f sec\n", tt);
    return 0;
}

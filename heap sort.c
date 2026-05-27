#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void hp(int a[], int n, int k)
{
    int v = a[k];
    int j;
    while(2*k + 1 < n)
    {
        j = 2*k + 1;
        if(j + 1 < n && a[j+1] > a[j])
            j++;
        if(v >= a[j])
            break;
        a[k] = a[j];
        k = j;
    }
    a[k] = v;
}

void hs(int a[], int n)
{
    for(int i = n/2 - 1; i >= 0; i--)
        hp(a, n, i);
    for(int i = n-1; i > 0; i--)
    {
        int t = a[0];
        a[0] = a[i];
        a[i] = t;
        hp(a, i, 0);
    }
}

int main()
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    int a[n];
    srand(time(0));
    for(int i = 0; i < n; i++)
        a[i] = rand() % 100;
    printf("\nRandom array:\n");
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
    clock_t st, en;
    st = clock();
    hs(a, n);
    en = clock();
    printf("\nSorted array:\n");
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
    double tt =
    (double)(en - st) / CLOCKS_PER_SEC;
    printf("\n\nTime = %f sec\n", tt);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quicksort(int a[], int low, int high);
int partition(int a[], int low, int high);

int main() {
    int n, i;

    clock_t start, end;
    double time_taken;

    printf("Enter number of elements: ");
    scanf("%d", &n);
    int a[n];

    for(i = 0; i < n; i++) {
        a[i] = rand() % 1000;
    }

    printf("Array before sorting:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    start = clock();
    quicksort(a, 0, n - 1);
    end = clock();

    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nArray after sorting:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    printf("\nTime taken = %.9f seconds\n", time_taken);

    return 0;
}

void quicksort(int a[], int low, int high) {
    int j;
    if(low < high) {
        j = partition(a, low, high);
        quicksort(a, low, j - 1);
        quicksort(a, j + 1, high);
    }
}

int partition(int a[], int low, int high) {
    int pivot, i, j, temp;
    pivot = a[low];
    i = low + 1;
    j = high;

    while(1) {
        while(i <= high && a[i] <= pivot)
            i++;
        while(a[j] > pivot)
            j--;

        if(i < j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        } else {
            temp = a[low];
            a[low] = a[j];
            a[j] = temp;
            return j;
        }
    }
}

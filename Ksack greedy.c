#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int weight;
    int profit;
    float ratio;
} Item;
int compare(const void *a, const void *b) {
    Item *i1 = (Item *)a;
    Item *i2 = (Item *)b;
    if (i2->ratio > i1->ratio)
        return 1;
    else if (i2->ratio < i1->ratio)
        return -1;
    else
        return 0;
}
int main() {
    int n, capacity;
    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);
    Item items[n];
    srand(time(0));
    printf("\nGenerated Items:\n");
    for (int i = 0; i < n; i++) {
        items[i].weight = rand() % 20 + 1;
        items[i].profit = rand() % 100 + 1;
        items[i].ratio = (float)items[i].profit / items[i].weight;
        printf("Item %d -> Weight: %d, Profit: %d, Ratio: %.2f\n",
               i + 1, items[i].weight, items[i].profit, items[i].ratio);
    }
    clock_t start = clock();
    qsort(items, n, sizeof(Item), compare);
    float totalProfit = 0.0;
    int remaining = capacity;
    for (int i = 0; i < n; i++) {
        if (remaining >= items[i].weight) {
            totalProfit += items[i].profit;
            remaining -= items[i].weight;
        } else {
            totalProfit += items[i].ratio * remaining;
            break;
        }
    }
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nMaximum Profit = %.2f\n", totalProfit);
    printf("Execution Time = %f seconds\n", time_taken);
    return 0;
}

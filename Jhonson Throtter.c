#include <stdio.h>

#define LEFT -1
#define RIGHT 1

void printPermutation(int perm[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", perm[i]);
    printf("\n");
}

int findPosition(int perm[], int n, int mobile) {
    for (int i = 0; i < n; i++) {
        if (perm[i] == mobile)
            return i;
    }
    return -1;
}
int getMobile(int perm[], int dir[], int n) {
    int mobile = 0;
    for (int i = 0; i < n; i++) {
        if (dir[perm[i]] == LEFT && i != 0) {
            if (perm[i] > perm[i - 1] && perm[i] > mobile)
                mobile = perm[i];
        }
        if (dir[perm[i]] == RIGHT && i != n - 1) {
            if (perm[i] > perm[i + 1] && perm[i] > mobile)
                mobile = perm[i];
        }
    }
    return mobile;
}
void johnsonTrotter(int n) {

    int perm[n];
    int dir[n + 1];
    for (int i = 0; i < n; i++) {
        perm[i] = i + 1;
        dir[i + 1] = LEFT;
    }

    printPermutation(perm, n);

    while (1) {

        int mobile = getMobile(perm, dir, n);
        if (mobile == 0)
            break;

        int pos = findPosition(perm, n, mobile);
        if (dir[mobile] == LEFT) {
            int temp = perm[pos];
            perm[pos] = perm[pos - 1];
            perm[pos - 1] = temp;
            pos--;
        }
        else if (dir[mobile] == RIGHT) {
            int temp = perm[pos];
            perm[pos] = perm[pos + 1];
            perm[pos + 1] = temp;
            pos++;
        }
        for (int i = 0; i < n; i++) {
            if (perm[i] > mobile)
                dir[perm[i]] *= -1;
        }

        printPermutation(perm, n);
    }
}
int main() {
    int n;

    printf("Enter value of n: ");
    scanf("%d", &n);

    johnsonTrotter(n);

    return 0;
}

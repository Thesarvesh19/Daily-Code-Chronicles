#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int maxIceCream(int* costs, int costsSize, int coins) {
    qsort(costs, costsSize, sizeof(int), compare);

    int count = 0;

    for (int i = 0; i < costsSize; i++) {
        if (coins < costs[i])
            break;

        coins -= costs[i];
        count++;
    }

    return count;
}

#include <stdlib.h>

typedef struct {
    int endTime;
    int server;
} BusyServer;

void swap(BusyServer *a, BusyServer *b) {
    BusyServer temp = *a;
    *a = *b;
    *b = temp;
}

void push(BusyServer heap[], int *size, int endTime, int server) {
    int i = (*size)++;

    heap[i].endTime = endTime;
    heap[i].server = server;

    while (i > 0) {
        int parent = (i - 1) / 2;

        if (heap[parent].endTime <= heap[i].endTime)
            break;

        swap(&heap[parent], &heap[i]);
        i = parent;
    }
}

BusyServer pop(BusyServer heap[], int *size) {
    BusyServer result = heap[0];

    heap[0] = heap[--(*size)];

    int i = 0;

    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < *size &&
            heap[left].endTime < heap[smallest].endTime)
            smallest = left;

        if (right < *size &&
            heap[right].endTime < heap[smallest].endTime)
            smallest = right;

        if (smallest == i)
            break;

        swap(&heap[i], &heap[smallest]);
        i = smallest;
    }

    return result;
}

int findAvailable(int available[], int k, int target) {
    int left = 0, right = k - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (available[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return left;
}

void insertServer(int available[], int *size, int server) {
    int i = (*size)++;

    while (i > 0 && available[i - 1] > server) {
        available[i] = available[i - 1];
        i--;
    }

    available[i] = server;
}

int removeServer(int available[], int *size, int index) {
    int server = available[index];

    for (int i = index; i < *size - 1; i++) {
        available[i] = available[i + 1];
    }

    (*size)--;

    return server;
}

int* busiestServers(int k, int* arrival, int arrivalSize,
                    int* load, int loadSize, int* returnSize) {

    int *available = malloc(k * sizeof(int));
    int *count = calloc(k, sizeof(int));

    BusyServer *busy = malloc(
        (arrivalSize + 1) * sizeof(BusyServer)
    );

    int availableSize = k;
    int busySize = 0;

    for (int i = 0; i < k; i++) {
        available[i] = i;
    }

    for (int i = 0; i < arrivalSize; i++) {

        int start = arrival[i];

        // Release completed servers
        while (busySize > 0 && busy[0].endTime <= start) {
            BusyServer finished = pop(busy, &busySize);

            insertServer(
                available,
                &availableSize,
                finished.server
            );
        }

        if (availableSize == 0)
            continue;

        int target = i % k;

        int index = findAvailable(
            available,
            availableSize,
            target
        );

        if (index == availableSize)
            index = 0;

        int server = removeServer(
            available,
            &availableSize,
            index
        );

        count[server]++;

        push(
            busy,
            &busySize,
            start + load[i],
            server
        );
    }

    int maxCount = 0;

    for (int i = 0; i < k; i++) {
        if (count[i] > maxCount)
            maxCount = count[i];
    }

    int *result = malloc(k * sizeof(int));
    *returnSize = 0;

    for (int i = 0; i < k; i++) {
        if (count[i] == maxCount) {
            result[(*returnSize)++] = i;
        }
    }

    free(available);
    free(count);
    free(busy);

    return result;
}

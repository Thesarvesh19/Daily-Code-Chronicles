#include <stdlib.h>
#include <stdbool.h>

#define LIMIT 2048

int uniqueXorTriplets(int* nums, int numsSize) {
    if (numsSize == 1)
        return 1;

    bool pairSeen[LIMIT] = {false};
    bool tripletSeen[LIMIT] = {false};

    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            pairSeen[nums[i] ^ nums[j]] = true;
        }
    }

    for (int x = 0; x < LIMIT; x++) {
        if (!pairSeen[x])
            continue;

        for (int i = 0; i < numsSize; i++) {
            tripletSeen[x ^ nums[i]] = true;
        }
    }

    int count = 0;
    for (int i = 0; i < LIMIT; i++) {
        if (tripletSeen[i])
            count++;
    }

    return count;
}

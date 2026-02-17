#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int bitCount(int n) {
    int count = 0;
    while (n > 0) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

char** readBinaryWatch(int turnedOn, int* returnSize) {
    char** result = (char**)malloc(720 * sizeof(char*));
    *returnSize = 0;

    for (int hour = 0; hour < 12; hour++) {
        for (int minute = 0; minute < 60; minute++) {
            if (bitCount(hour) + bitCount(minute) == turnedOn) {
                result[*returnSize] = (char*)malloc(6 * sizeof(char));
                sprintf(result[*returnSize], "%d:%02d", hour, minute);
                (*returnSize)++;
            }
        }
    }

    return result;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Comparison function for qsort
int compareChars(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}

char* smallestPalindrome(char* s) {
    int n = strlen(s);
    int half_len = n / 2;

    // Allocate memory for the result string
    char* result = (char*)malloc((n + 1) * sizeof(char));

    // Copy the first half and sort it lexicographically
    strncpy(result, s, half_len);
    qsort(result, half_len, sizeof(char), compareChars);

    // Place the middle character if the length is odd
    if (n % 2 != 0) {
        result[half_len] = s[half_len];
    }

    // Mirror the sorted first half to the second half
    for (int i = 0; i < half_len; i++) {
        result[n - 1 - i] = result[i];
    }

    result[n] = '\0';
    return result;
}

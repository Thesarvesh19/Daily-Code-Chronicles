#include <stdbool.h>
#include <limits.h>

bool uniformArray(int* nums1, int nums1Size) {
    int minOdd = INT_MAX;

    // Find the smallest odd number
    for (int i = 0; i < nums1Size; i++) {
        if (nums1[i] % 2 != 0 && nums1[i] < minOdd) {
            minOdd = nums1[i];
        }
    }

    // No odd number exists
    if (minOdd == INT_MAX) {
        return true;
    }

    // Check even numbers
    for (int i = 0; i < nums1Size; i++) {
        if (nums1[i] % 2 == 0 && nums1[i] < minOdd) {
            return false;
        }
    }

    return true;
}

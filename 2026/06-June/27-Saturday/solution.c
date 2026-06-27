#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort
int compare(const void* a, const void* b) {
    int num1 = *(const int*)a;
    int num2 = *(const int*)b;
    if (num1 < num2) return -1;
    if (num1 > num2) return 1;
    return 0;
}

// Custom structure to hold unique elements and their frequencies
typedef struct {
    long long val;
    int count;
} Element;

// Binary search to find the frequency of a target value
int get_frequency(Element* dict, int size, long long target) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (dict[mid].val == target) {
            return dict[mid].count;
        } else if (dict[mid].val < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return 0;
}

int maximumLength(int* nums, int numsSize) {
    // Step 1: Sort the array to group duplicates together
    qsort(nums, numsSize, sizeof(int), compare);
    
    // Step 2: Compress into a frequency array of unique elements
    Element* dict = (Element*)malloc(numsSize * sizeof(Element));
    int dictSize = 0;
    
    for (int i = 0; i < numsSize; i++) {
        if (dictSize > 0 && dict[dictSize - 1].val == nums[i]) {
            dict[dictSize - 1].count++;
        } else {
            dict[dictSize].val = nums[i];
            dict[dictSize].count = 1;
            dictSize++;
        }
    }
    
    int maxNum = nums[numsSize - 1];
    int ans = 1;
    
    // Step 3: Handle edge case for 1s
    int ones_count = get_frequency(dict, dictSize, 1);
    if (ones_count > 0) {
        ans = (ones_count % 2 == 0) ? ones_count - 1 : ones_count;
    }
    
    // Step 4: Iterate through unique elements to find longest chain
    for (int i = 0; i < dictSize; i++) {
        long long num = dict[i].val;
        if (num == 1) continue;
        
        int length = 0;
        long long x = num;
        
        // Find how far the pattern can expand
        while (x <= maxNum && get_frequency(dict, dictSize, x) >= 2) {
            length += 2;
            x = x * x; 
        }
        
        // Determine the peak element status
        if (x <= maxNum && get_frequency(dict, dictSize, x) >= 1) {
            length += 1;
        } else {
            length -= 1; // Last element counted twice becomes the peak
        }
        
        if (length > ans) {
            ans = length;
        }
    }
    
    free(dict);
    return ans;
}

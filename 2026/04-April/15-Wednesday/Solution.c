#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>

int closestTarget(char** words, int wordsSize, char* target, int startIndex) {
    int ans = INT_MAX;

    for (int i = 0; i < wordsSize; i++) { 
        if (strcmp(words[i], target) == 0) {
            int d = abs(i - startIndex);
            int minDist = d < (wordsSize - d) ? d : (wordsSize - d);
            if (minDist < ans) ans = minDist;
        }
    }

    return ans == INT_MAX ? -1 : ans;
}

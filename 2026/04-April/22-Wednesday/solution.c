// Words Within Two Edits of Dictionary

#include <stdlib.h>

int compare(char *a, char *b) {
    int diff = 0;
    
    while (*a && *b) {
        if (*a != *b) {
            diff++;
            if (diff > 2) return 0;
        } 
        a++;
        b++;
    }
    
    return 1;
}

char** twoEditWords(char **queries, int queriesSize, char **dictionary, int dictionarySize, int* returnSize) {
    
    char **ans = (char**)malloc(sizeof(char*) * queriesSize);
    *returnSize = 0;
    
    for (int i = 0; i < queriesSize; i++) {
        for (int j = 0; j < dictionarySize; j++) {
            
            if (compare(queries[i], dictionary[j])) {
                ans[*returnSize] = queries[i];
                (*returnSize)++;
                break;
            }
        }
    }
    
    return ans;
}

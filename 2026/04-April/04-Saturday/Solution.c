#include <stdlib.h>
#include <string.h>

char* decodeCiphertext(char* encodedText, int rows) {
    if (rows == 1) return encodedText;

    int n = strlen(encodedText);
    int cols = n / rows;

    char** matrix = (char**)malloc(rows * sizeof(char*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (char*)malloc(cols * sizeof(char));
    }

    int idx = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = encodedText[idx++];
        }
    }

    char* res = (char*)malloc((n + 1) * sizeof(char));
    int k = 0;

    for (int start = 0; start < cols; start++) {
        int i = 0, j = start;
        while (i < rows && j < cols) {
            res[k++] = matrix[i][j];
            i++;
            j++;
        }
    }

    while (k > 0 && res[k - 1] == ' ') k--;
    res[k] = '\0';

    return res;
}

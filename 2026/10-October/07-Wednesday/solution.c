#include <stdlib.h>
#include <string.h>

void removeInvalid(
    char *s,
    char **result,
    int *returnSize,
    int last_i,
    int last_j,
    char open,
    char close
) {
    int balance = 0;
    int n = strlen(s);

    for (int i = last_i; i < n; i++) {

        if (s[i] == open) {
            balance++;
        }
        else if (s[i] == close) {
            balance--;
        }

        // Still valid
        if (balance >= 0) {
            continue;
        }

        // We found an extra closing parenthesis.
        // Try removing each possible closing parenthesis.
        for (int j = last_j; j <= i; j++) {

            // Skip duplicate removals
            if (s[j] == close &&
                (j == last_j || s[j - 1] != close)) {

                char *next = malloc(n);

                int k = 0;

                // Copy everything except s[j]
                for (int p = 0; p < n; p++) {
                    if (p != j) {
                        next[k++] = s[p];
                    }
                }

                next[k] = '\0';

                removeInvalid(
                    next,
                    result,
                    returnSize,
                    i,
                    j,
                    open,
                    close
                );

                free(next);
            }
        }

        // Only fix the first invalid position
        return;
    }

    /*
     * No extra 'close' remains.
     *
     * Reverse the string and solve the opposite problem.
     */
    if (open == '(') {

        char *reversed = malloc(n + 1);

        for (int i = 0; i < n; i++) {
            reversed[i] = s[n - 1 - i];
        }

        reversed[n] = '\0';

        removeInvalid(
            reversed,
            result,
            returnSize,
            0,
            0,
            ')',
            '('
        );

        free(reversed);

    } else {

        /*
         * Both '(' and ')' are now valid.
         *
         * Reverse back before adding to result.
         */
        char *final = malloc(n + 1);

        for (int i = 0; i < n; i++) {
            final[i] = s[n - 1 - i];
        }

        final[n] = '\0';

        result[*returnSize] = final;
        (*returnSize)++;
    }
}

char** removeInvalidParentheses(
    char* s,
    int* returnSize
) {
    *returnSize = 0;

    int n = strlen(s);

    /*
     * Maximum number of results can be large,
     * so allocate enough space dynamically.
     */
    int capacity = 1024;

    char **result = malloc(
        capacity * sizeof(char *)
    );

    /*
     * The recursive function writes into result.
     */
    removeInvalid(
        s,
        result,
        returnSize,
        0,
        0,
        '(',
        ')'
    );

    return result;
}

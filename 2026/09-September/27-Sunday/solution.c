#include <stdlib.h>
#include <string.h>

char* reverseParentheses(char* s) {
    int n = strlen(s);
    char* stack = (char*)malloc((n + 1) * sizeof(char));
    int top = -1;

    for (int i = 0; i < n; i++) {
        if (s[i] == ')') {
            char temp;

            // Reverse until '('
            int start = top;

            while (stack[top] != '(') {
                top--;
            }

            // Remove '('
            top--;

            // Reverse the substring
            int left = top + 1;
            int right = start;

            while (left < right) {
                temp = stack[left];
                stack[left] = stack[right];
                stack[right] = temp;

                left++;
                right--;
            }

            // Restore top
            top = start;
        } else {
            stack[++top] = s[i];
        }
    }

    stack[top + 1] = '\0';

    // Remove any remaining parentheses (if necessary)
    int j = 0;
    for (int i = 0; stack[i] != '\0'; i++) {
        if (stack[i] != '(' && stack[i] != ')') {
            stack[j++] = stack[i];
        }
    }
    stack[j] = '\0';

    return stack;
}

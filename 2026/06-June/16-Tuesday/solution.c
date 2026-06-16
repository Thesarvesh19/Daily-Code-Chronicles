#include <stdlib.h>
#include <string.h>

char* processStr(char* s) {
    int cap = 1 << 20;  // enough for constraints
    char* res = (char*)malloc(cap);
    int len = 0;

    for (int i = 0; s[i]; i++) {
        char c = s[i];

        if (c >= 'a' && c <= 'z') {
            res[len++] = c;
        }
        else if (c == '*') {
            if (len > 0) len--;
        }
        else if (c == '#') {
            memcpy(res + len, res, len);
            len *= 2;
        }
        else { // '%'
            for (int l = 0, r = len - 1; l < r; l++, r--) {
                char t = res[l];
                res[l] = res[r];
                res[r] = t;
            }
        }
    }

    res[len] = '\0';
    return res;
}

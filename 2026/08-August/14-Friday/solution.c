#include <stdio.h>
#include <string.h>

int maximumLengthSubstring(char* s) {
    int freq[26] = {0};
    int left = 0, ans = 0;
    int n = strlen(s);

    for (int right = 0; right < n; right++) {
        freq[s[right] - 'a']++;

        while (freq[s[right] - 'a'] > 2) {
            freq[s[left] - 'a']--;
            left++;
        }

        int len = right - left + 1;
        if (len > ans)
            ans = len;
    }

    return ans;
}

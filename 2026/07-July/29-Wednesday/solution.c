#include <stdlib.h>
#include <string.h>

#define MAX 1000001

static long long nCk(int n, int k) {
    if (k > n - k)
        k = n - k;

    long long res = 1;

    for (int i = 1; i <= k; i++) {
        res = res * (n - i + 1) / i;
        if (res >= MAX)
            return MAX;
    }

    return res;
}

static int countWays(int cnt[]) {
    int total = 0;
    for (int i = 0; i < 26; i++)
        total += cnt[i];

    long long res = 1;

    for (int i = 0; i < 26; i++) {
        res *= nCk(total, cnt[i]);
        if (res >= MAX)
            return MAX;
        total -= cnt[i];
    }

    return (int)res;
}

char* smallestPalindrome(char* s, int k) {
    int freq[26] = {0};

    for (int i = 0; s[i]; i++)
        freq[s[i] - 'a']++;

    int half[26] = {0};
    char mid = '\0';

    int halfLen = 0;
    for (int i = 0; i < 26; i++) {
        half[i] = freq[i] / 2;
        halfLen += half[i];
        if (freq[i] & 1)
            mid = (char)('a' + i);
    }

    if (countWays(half) < k) {
        char* empty = (char*)malloc(1);
        empty[0] = '\0';
        return empty;
    }

    char* left = (char*)malloc(halfLen + 1);
    int pos = 0;

    while (pos < halfLen) {
        for (int i = 0; i < 26; i++) {
            if (half[i] == 0)
                continue;

            half[i]--;
            int ways = countWays(half);

            if (ways >= k) {
                left[pos++] = (char)('a' + i);
                break;
            }

            k -= ways;
            half[i]++;
        }
    }

    left[halfLen] = '\0';

    int n = strlen(s);
    char* ans = (char*)malloc(n + 1);

    memcpy(ans, left, halfLen);

    int idx = halfLen;
    if (mid)
        ans[idx++] = mid;

    for (int i = halfLen - 1; i >= 0; i--)
        ans[idx++] = left[i];

    ans[idx] = '\0';

    free(left);
    return ans;
}

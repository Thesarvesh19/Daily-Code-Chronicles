unsigned long long numDistinct(char* s, char* t) {
    int n = strlen(t);

    unsigned long long *dp = calloc(n + 1, sizeof(unsigned long long));
    dp[0] = 1;

    for (int i = 0; s[i] != '\0'; i++) {
        for (int j = n - 1; j >= 0; j--) {
            if (s[i] == t[j]) {
                dp[j + 1] += dp[j];
            }
        }
    }

    unsigned long long result = dp[n];
    free(dp);

    return result;
}

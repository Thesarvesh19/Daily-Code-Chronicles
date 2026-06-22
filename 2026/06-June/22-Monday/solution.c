#define MIN(a, b) ((a) < (b) ? (a) : (b))

int maxNumberOfBalloons(char * text) {
    int charCounts[26] = {0};
    
    // Traverse the null-terminated string
    for (int i = 0; text[i] != '\0'; i++) {
        charCounts[text[i] - 'a']++;
    }
    
    // Extract frequencies, dividing 'l' and 'o' by 2
    int b = charCounts['b' - 'a'];
    int a = charCounts['a' - 'a'];
    int l = charCounts['l' - 'a'] / 2;
    int o = charCounts['o' - 'a'] / 2;
    int n = charCounts['n' - 'a'];
    
    // Find the minimum using our macro
    int minVal = MIN(b, a);
    minVal = MIN(minVal, l);
    minVal = MIN(minVal, o);
    minVal = MIN(minVal, n);
    
    return minVal;
}

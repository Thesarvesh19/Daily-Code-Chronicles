// 2078. Two Furthest Houses With Different Colors
int maxDistance(int* colors, int colorsSize) {
    int ans = 0;

    for (int i = 0; i < colorsSize; i++) {
        if (colors[i] != colors[0]) {
            if (i > ans) ans = i;
        }
        if (colors[i] != colors[colorsSize - 1]) {
            if (colorsSize - 1 - i > ans) ans = colorsSize - 1 - i;
        }
    }

    return ans;
}

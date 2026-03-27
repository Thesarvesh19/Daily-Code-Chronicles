class Solution {
    public boolean areSimilar(int[][] mat, int k) {
        int m = mat.length;
        int n = mat[0].length;

        int shift = k % n;

        if (shift == 0) return true;

        for (int i = 0; i < m; i++) {
            int[] row = mat[i];
            int[] shifted = new int[n];

            if (i % 2 == 0) {
                // left shift
                for (int j = 0; j < n; j++) {
                    shifted[j] = row[(j + shift) % n];
                }
            } else {
                // right shift
                for (int j = 0; j < n; j++) {
                    shifted[j] = row[(j - shift + n) % n];
                }
            }

            for (int j = 0; j < n; j++) {
                if (shifted[j] != row[j]) {
                    return false;
                }
            }
        }

        return true;
    }
}

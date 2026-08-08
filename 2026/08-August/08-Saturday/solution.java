class Solution {
    public int[] validSequence(String word1, String word2) {
        int n = word1.length();
        int m = word2.length();

        int[] last = new int[m];

        // last[j] = rightmost position in word1
        // where word2[j] can be matched while
        // matching the remaining suffix.
        int i = n - 1;
        int j = m - 1;

        while (i >= 0 && j >= 0) {
            if (word1.charAt(i) == word2.charAt(j)) {
                last[j] = i;
                j--;
            }
            i--;
        }

        // If word2 cannot even be matched with exact characters
        // except for one mismatch, it will be detected below.
        int[] ans = new int[m];

        j = 0;
        boolean mismatchUsed = false;

        for (i = 0; i < n && j < m; i++) {

            // Exact match
            if (word1.charAt(i) == word2.charAt(j)) {
                ans[j] = i;
                j++;
            }

            // Use the one allowed mismatch
            else if (!mismatchUsed) {

                // After using mismatch at i, the rest must
                // be matched exactly.
                if (j == m - 1 || i < last[j + 1]) {
                    ans[j] = i;
                    j++;
                    mismatchUsed = true;
                }
            }
        }

        // Could not form a valid sequence
        if (j != m) {
            return new int[0];
        }

        return ans;
    }
}

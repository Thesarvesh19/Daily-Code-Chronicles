class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();

        int shift = k % n;

        if (shift == 0) return true;

        for (int i = 0; i < m; i++) {
            vector<int>& row = mat[i];

            for (int j = 0; j < n; j++) {
                int expected;

                if (i % 2 == 0) {
                    // left shift
                    expected = row[(j + shift) % n];
                } else {
                    // right shift
                    expected = row[(j - shift + n) % n];
                }

                if (expected != row[j]) {
                    return false;
                }
            }
        }

        return true;
    }
};

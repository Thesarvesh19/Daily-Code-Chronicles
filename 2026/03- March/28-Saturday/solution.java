//updated 
import java.util.*;

class Solution {
    public String findTheString(int[][] lcp) {
        int n = lcp.length;

        // Step 1: Validate diagonal
        for (int i = 0; i < n; i++) {
            if (lcp[i][i] != n - i) return "";
        }

        // Step 2: DSU
        int[] parent = new int[n];
        for (int i = 0; i < n; i++) parent[i] = i;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (lcp[i][j] > 0) {
                    union(i, j, parent);
                }
            }
        }

        // Step 3: Assign characters
        Map<Integer, Character> groupChar = new HashMap<>();
        char currentChar = 'a';
        char[] res = new char[n];

        for (int i = 0; i < n; i++) {
            int root = find(i, parent);
            if (!groupChar.containsKey(root)) {
                if (currentChar > 'z') return "";
                groupChar.put(root, currentChar);
                currentChar++;
            }
            res[i] = groupChar.get(root);
        }

        String word = new String(res);

        // Step 4: Validate LCP
        int[][] dp = new int[n + 1][n + 1];

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (word.charAt(i) == word.charAt(j)) {
                    dp[i][j] = dp[i + 1][j + 1] + 1;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dp[i][j] != lcp[i][j]) return "";
            }
        }

        return word;
    }

    private int find(int x, int[] parent) {
        if (parent[x] != x) {
            parent[x] = find(parent[x], parent);
        }
        return parent[x];
    }

    private void union(int x, int y, int[] parent) {
        int px = find(x, parent);
        int py = find(y, parent);
        if (px != py) {
            parent[py] = px;
        }
    }
}

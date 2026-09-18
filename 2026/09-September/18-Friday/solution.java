import java.util.*;

class Solution {
    public List<String> maxNumOfSubstrings(String s) {
        int n = s.length();

        // First and last occurrence of each character
        int[] first = new int[26];
        int[] last = new int[26];

        Arrays.fill(first, n);
        Arrays.fill(last, -1);

        for (int i = 0; i < n; i++) {
            int idx = s.charAt(i) - 'a';
            first[idx] = Math.min(first[idx], i);
            last[idx] = i;
        }

        List<int[]> intervals = new ArrayList<>();

        // Find all valid intervals
        for (int i = 0; i < n; i++) {
            int idx = s.charAt(i) - 'a';

            // Only start from the first occurrence
            if (i != first[idx]) {
                continue;
            }

            int l = i;
            int r = last[idx];
            boolean valid = true;

            for (int j = l; j <= r; j++) {
                int c = s.charAt(j) - 'a';

                // Character appears before l
                if (first[c] < l) {
                    valid = false;
                    break;
                }

                // Expand interval
                r = Math.max(r, last[c]);
            }

            if (valid) {
                intervals.add(new int[]{l, r});
            }
        }

        // Sort by ending position
        intervals.sort((a, b) -> Integer.compare(a[1], b[1]));

        List<String> ans = new ArrayList<>();
        int end = -1;

        // Greedily choose non-overlapping intervals
        for (int[] interval : intervals) {
            int l = interval[0];
            int r = interval[1];

            if (l > end) {
                ans.add(s.substring(l, r + 1));
                end = r;
            }
        }

        return ans;
    }
}

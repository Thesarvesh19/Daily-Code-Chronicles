import java.util.*;

class Solution {
    public int[] sumAndMultiply(String s, int[][] queries) {
        final long MOD = 1_000_000_007L;

        int n = s.length();

        ArrayList<Integer> digits = new ArrayList<>();
        ArrayList<Integer> positions = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            if (s.charAt(i) != '0') {
                digits.add(s.charAt(i) - '0');
                positions.add(i);
            }
        }

        int m = digits.size();

        int[] answer = new int[queries.length];

        if (m == 0)
            return answer;

        long[] power10 = new long[m + 1];
        power10[0] = 1;

        for (int i = 1; i <= m; i++) {
            power10[i] = (power10[i - 1] * 10) % MOD;
        }

        long[] prefixValue = new long[m + 1];
        long[] prefixSum = new long[m + 1];

        for (int i = 0; i < m; i++) {
            prefixValue[i + 1] = (prefixValue[i] * 10 + digits.get(i)) % MOD;
            prefixSum[i + 1] = prefixSum[i] + digits.get(i);
        }

        int[] first = new int[n + 1];
        Arrays.fill(first, m);

        int idx = m - 1;

        for (int i = n - 1; i >= 0; i--) {
            if (idx >= 0 && positions.get(idx) == i) {
                first[i] = idx;
                idx--;
            } else {
                first[i] = first[i + 1];
            }
        }

        int[] last = new int[n];
        Arrays.fill(last, -1);

        idx = 0;
        int current = -1;

        for (int i = 0; i < n; i++) {
            if (idx < m && positions.get(idx) == i) {
                current = idx;
                idx++;
            }
            last[i] = current;
        }

        for (int i = 0; i < queries.length; i++) {
            int left = first[queries[i][0]];
            int right = last[queries[i][1]];

            if (left > right || left == m || right == -1) {
                answer[i] = 0;
                continue;
            }

            int length = right - left + 1;

            long number = (
                    prefixValue[right + 1]
                    - (prefixValue[left] * power10[length]) % MOD
                    + MOD
            ) % MOD;

            long digitSum = prefixSum[right + 1] - prefixSum[left];

            answer[i] = (int) ((number * digitSum) % MOD);
        }

        return answer;
    }
}

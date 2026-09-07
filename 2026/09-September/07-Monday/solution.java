import java.util.*;

class Solution {
    public int distinctSubseqII(String s) {
        final int MOD = 1_000_000_007;

        long dp = 0;
        Map<Character, Long> last = new HashMap<>();

        for (char ch : s.toCharArray()) {
            long newDp = (2 * dp + 1) % MOD;

            if (last.containsKey(ch)) {
                newDp = (newDp - last.get(ch) + MOD) % MOD;
            }

            last.put(ch, (dp + 1) % MOD);
            dp = newDp;
        }

        return (int) dp;
    }
}

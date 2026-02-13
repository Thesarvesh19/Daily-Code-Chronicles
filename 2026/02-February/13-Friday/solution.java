import java.util.HashMap;
import java.util.Map;

class Solution {

    public int longestBalanced(String s) {
        char[] cs = s.toCharArray();

        // Case 1: Single character substrings
        int singleChar = calc1(cs);

        // Case 2: Exactly two distinct characters with equal frequency
        int twoChars = Math.max(
                calc2(cs, 'a', 'b'),
                Math.max(
                        calc2(cs, 'b', 'c'),
                        calc2(cs, 'a', 'c')
                )
        );

        // Case 3: All three characters with equal frequency
        int threeChars = calc3(cs);

        return Math.max(singleChar, Math.max(twoChars, threeChars));
    }

    // Case 1: Longest substring with only one distinct character
    private int calc1(char[] s) {
        int res = 0;
        int i = 0, n = s.length;

        while (i < n) {
            int j = i + 1;
            while (j < n && s[j] == s[i]) {
                j++;
            }
            res = Math.max(res, j - i);
            i = j;
        }

        return res;
    }

    // Case 2: Longest substring with exactly two distinct characters
    // where their counts are equal
    private int calc2(char[] s, char a, char b) {
        int res = 0;
        int i = 0, n = s.length;

        while (i < n) {

            // Skip characters not equal to a or b
            while (i < n && s[i] != a && s[i] != b) {
                i++;
            }

            Map<Integer, Integer> pos = new HashMap<>();
            pos.put(0, i - 1);

            int diff = 0;

            while (i < n && (s[i] == a || s[i] == b)) {
                diff += (s[i] == a) ? 1 : -1;

                if (pos.containsKey(diff)) {
                    res = Math.max(res, i - pos.get(diff));
                } else {
                    pos.put(diff, i);
                }

                i++;
            }
        }

        return res;
    }

    // Case 3: Longest substring where a, b, and c
    // all appear equal number of times
    private int calc3(char[] s) {
        Map<Long, Integer> pos = new HashMap<>();
        pos.put(encode(0, 0), -1);

        int[] count = new int[3];
        int res = 0;

        for (int i = 0; i < s.length; i++) {
            count[s[i] - 'a']++;

            int x = count[0] - count[1];
            int y = count[1] - count[2];

            long key = encode(x, y);

            if (pos.containsKey(key)) {
                res = Math.max(res, i - pos.get(key));
            } else {
                pos.put(key, i);
            }
        }

        return res;
    }

    // Encode two integers into a single long
    private long encode(int x, int y) {
        return (((long)(x + 100000)) << 32) | (y + 100000);
    }
}

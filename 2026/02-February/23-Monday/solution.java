import java.util.HashSet;
import java.util.Set;

class Solution {
    public boolean hasAllCodes(String s, int k) {
        int total = 1 << k;  // 2^k
        Set<String> set = new HashSet<>();

        for (int i = 0; i <= s.length() - k; i++) {
            set.add(s.substring(i, i + k));
            if (set.size() == total) {
                return true;
            }
        }

        return set.size() == total;
    }
}
 

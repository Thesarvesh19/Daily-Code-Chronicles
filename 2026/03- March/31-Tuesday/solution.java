import java.util.*;
 
class Solution {
    public String generateString(String str1, String str2) {
        int n = str1.length(), m = str2.length();
        int sz = n + m - 1;

        char[] ans = new char[sz];
        boolean[] modifiable = new boolean[sz];
        Arrays.fill(modifiable, true);

        for (int i = 0; i < n; i++) {
            if (str1.charAt(i) == 'T') {
                for (int j = 0; j < m; j++) {
                    int pos = i + j;
                    if (ans[pos] != 0 && ans[pos] != str2.charAt(j)) return "";
                    ans[pos] = str2.charAt(j);
                    modifiable[pos] = false;
                }
            }
        }

        for (int i = 0; i < sz; i++) {
            if (ans[i] == 0) ans[i] = 'a';
        }

        for (int i = 0; i < n; i++) {
            if (str1.charAt(i) == 'F' && match(ans, i, str2)) {
                int pos = lastModifiablePosition(i, m, modifiable);
                if (pos == -1) return "";
                ans[pos] = 'b';
                modifiable[pos] = false;
            }
        }

        return new String(ans);
    }

    private boolean match(char[] ans, int i, String s) {
        for (int j = 0; j < s.length(); j++) {
            if (ans[i + j] != s.charAt(j)) return false;
        }
        return true;
    }

    private int lastModifiablePosition(int i, int m, boolean[] modifiable) {
        int pos = -1;
        for (int j = 0; j < m; j++) {
            if (modifiable[i + j]) pos = i + j;
        }
        return pos;
    }
}

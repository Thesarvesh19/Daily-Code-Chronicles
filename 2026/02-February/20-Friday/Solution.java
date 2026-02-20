import java.util.*;

class Solution {
    public String makeLargestSpecial(String s) {
        List<String> parts = new ArrayList<>();
        int balance = 0, start = 0;

        for (int i = 0; i < s.length(); i++) {
            balance += s.charAt(i) == '1' ? 1 : -1;

            if (balance == 0) {
                String inner = makeLargestSpecial(s.substring(start + 1, i));
                parts.add("1" + inner + "0");
                start = i + 1;
            }
        }

        parts.sort(Collections.reverseOrder());

        StringBuilder result = new StringBuilder();
        for (String part : parts) {
            result.append(part);
        }

        return result.toString();
    }
}

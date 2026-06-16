class Solution {
    public String processStr(String s) {
        StringBuilder res = new StringBuilder();

        for (char c : s.toCharArray()) {
            if (Character.isLowerCase(c)) {
                res.append(c);
            } else if (c == '*') {
                if (res.length() > 0) {
                    res.deleteCharAt(res.length() - 1);
                }
            } else if (c == '#') {
                res.append(res.toString());
            } else { // '%'
                res.reverse();
            }
        }

        return res.toString();
    }
}

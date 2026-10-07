class Solution {

    public void removeInvalid(
        String s,
        List<String> ans,
        int lastI,
        int lastJ,
        char open,
        char close
    ) {

        int balance = 0;

        // Find the first position where the string becomes invalid
        for (int i = lastI; i < s.length(); i++) {

            if (s.charAt(i) == open) {
                balance++;
            } 
            else if (s.charAt(i) == close) {
                balance--;
            }

            // Still valid
            if (balance >= 0) {
                continue;
            }

            // We have an extra closing parenthesis.
            // Try removing one of the closing parentheses
            // between lastJ and i.
            for (int j = lastJ; j <= i; j++) {

                // Avoid duplicate removals
                if (s.charAt(j) == close &&
                    (j == lastJ || s.charAt(j - 1) != close)) {

                    String next =
                        s.substring(0, j) +
                        s.substring(j + 1);

                    removeInvalid(
                        next,
                        ans,
                        i,
                        j,
                        open,
                        close
                    );
                }
            }

            // Only fix the first invalid position
            return;
        }

        // No extra 'close' parentheses remain.

        // Reverse and solve the opposite problem.
        String reversed = new StringBuilder(s).reverse().toString();

        if (open == '(') {

            // Now remove extra '('
            removeInvalid(
                reversed,
                ans,
                0,
                0,
                ')',
                '('
            );

        } else {

            // String is completely valid
            ans.add(reversed);
        }
    }

    public List<String> removeInvalidParentheses(String s) {

        List<String> ans = new ArrayList<>();

        removeInvalid(
            s,
            ans,
            0,
            0,
            '(',
            ')'
        );

        return ans;
    }
}

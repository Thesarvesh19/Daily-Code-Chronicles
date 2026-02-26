class Solution {
    public int numSteps(String s) {
        StringBuilder sb = new StringBuilder(s);
        int steps = 0;

        while (!sb.toString().equals("1")) {
            int n = sb.length();

            // If even (last bit is 0)
            if (sb.charAt(n - 1) == '0') {
                sb.deleteCharAt(n - 1); // divide by 2
            } 
            // If odd (last bit is 1)
            else {
                int i = n - 1;

                // Handle carry while bits are '1'
                while (i >= 0 && sb.charAt(i) == '1') {
                    sb.setCharAt(i, '0');
                    i--;
                }

                // If carry goes beyond MSB
                if (i < 0) {
                    sb.insert(0, '1');
                } else {
                    sb.setCharAt(i, '1');
                }
            }

            steps++;
        }

        return steps;
    }
}

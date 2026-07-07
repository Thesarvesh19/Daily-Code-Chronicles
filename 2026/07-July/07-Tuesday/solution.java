class Solution {
    public long sumAndMultiply(int n) {
        StringBuilder sb = new StringBuilder();

        while (n > 0) {
            int d = n % 10;
            if (d != 0)
                sb.append(d);
            n /= 10;
        }

        sb.reverse();

        long value = 0;
        int sum = 0;

        for (int i = 0; i < sb.length(); i++) {
            int digit = sb.charAt(i) - '0';
            value = value * 10 + digit;
            sum += digit;
        }

        return value * sum;
    }
}

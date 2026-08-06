public class Solution {
    public int SmallestNumber(int n, int t) {
        while (true) {
            long prod = 1;
            int x = n;
            while (x > 0) {
                prod *= x % 10;
                x /= 10;
            }
            if (prod % t == 0)
                return n;
            n++;
        }
    }
}

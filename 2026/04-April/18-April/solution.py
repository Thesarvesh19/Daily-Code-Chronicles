// 3783. Mirror Distance of an Integer

class Solution {
    public int mirrorDistance(int n) {
        int temp = n, rev = 0;
        while (temp > 0) {
            rev = rev * 10 + temp % 10;
            temp /= 10;
        }
        return Math.abs(n - rev);
    }
}

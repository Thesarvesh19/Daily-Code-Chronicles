import java.util.Arrays;

class Solution {

    public long gcdSum(int[] nums) {
        int n = nums.length;
        int[] prefix = new int[n];

        int currentMax = 0;

        for (int i = 0; i < n; i++) {
            currentMax = Math.max(currentMax, nums[i]);
            prefix[i] = gcd(nums[i], currentMax);
        }

        Arrays.sort(prefix);

        long answer = 0;

        int left = 0;
        int right = n - 1;

        while (left < right) {
            answer += gcd(prefix[left], prefix[right]);
            left++;
            right--;
        }

        return answer;
    }

    private int gcd(int a, int b) {
        while (b != 0) {
            int temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }
}

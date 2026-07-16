using System;

public class Solution
{
    public long GcdSum(int[] nums)
    {
        int n = nums.Length;
        int[] transformed = new int[n];

        int currentMax = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] > currentMax)
                currentMax = nums[i];

            transformed[i] = GCD(nums[i], currentMax);
        }

        Array.Sort(transformed);

        long answer = 0;

        int left = 0;
        int right = n - 1;

        while (left < right)
        {
            answer += GCD(transformed[left], transformed[right]);
            left++;
            right--;
        }

        return answer;
    }

    private int GCD(int a, int b)
    {
        while (b != 0)
        {
            int temp = a % b;
            a = b;
            b = temp;
        }

        return a;
    }
}

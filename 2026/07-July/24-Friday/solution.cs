using System.Collections.Generic;

public class Solution
{
    public int UniqueXorTriplets(int[] nums)
    {
        int n = nums.Length;

        if (n == 1)
            return 1;

        HashSet<int> pairXors = new HashSet<int>();

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                pairXors.Add(nums[i] ^ nums[j]);
            }
        }

        HashSet<int> tripletXors = new HashSet<int>();

        foreach (int px in pairXors)
        {
            foreach (int value in nums)
            {
                tripletXors.Add(px ^ value);
            }
        }

        return tripletXors.Count;
    }
}

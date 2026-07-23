public class Solution
{
    public int UniqueXorTriplets(int[] nums)
    {
        int n = nums.Length;

        if (n <= 2)
            return n;

        int bits = 0;
        int value = n;

        while (value > 0)
        {
            bits++;
            value >>= 1;
        }

        return 1 << bits;
    }
}

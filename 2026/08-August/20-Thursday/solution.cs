public class Solution
{
    public int[] ResultArray(int[] nums)
    {
        List<int> a = new List<int>();
        List<int> b = new List<int>();

        a.Add(nums[0]);
        b.Add(nums[1]);

        for (int i = 2; i < nums.Length; i++)
        {
            if (a[a.Count - 1] > b[b.Count - 1])
                a.Add(nums[i]);
            else
                b.Add(nums[i]);
        }

        a.AddRange(b);

        return a.ToArray();
    }
}

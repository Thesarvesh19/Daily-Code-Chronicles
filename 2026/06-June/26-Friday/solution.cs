public class BIT
{
    private int[] tree;
    private int n;

    public BIT(int n)
    {
        this.n = n;
        tree = new int[n + 1];
    }

    public void Update(int idx, int val)
    {
        while (idx <= n)
        {
            tree[idx] += val;
            idx += idx & -idx;
        }
    }

    public int Query(int idx)
    {
        int sum = 0;
        while (idx > 0)
        {
            sum += tree[idx];
            idx -= idx & -idx;
        }
        return sum;
    }
}

public class Solution
{
    public long CountMajoritySubarrays(int[] nums, int target)
    {
        int n = nums.Length;
        BIT bit = new BIT(2 * n + 2);

        int prefix = n + 1;
        bit.Update(prefix, 1);

        long ans = 0;

        foreach (int x in nums)
        {
            prefix += (x == target) ? 1 : -1;
            ans += bit.Query(prefix - 1);
            bit.Update(prefix, 1);
        }

        return ans;
    }
}

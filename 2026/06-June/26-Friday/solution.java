class BIT {
    int[] tree;
    int n;

    BIT(int n) {
        this.n = n;
        tree = new int[n + 1];
    }

    void update(int idx, int val) {
        while (idx <= n) {
            tree[idx] += val;
            idx += idx & -idx;
        }
    }

    int query(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += tree[idx];
            idx -= idx & -idx;
        }
        return sum;
    }
}

class Solution {
    public long countMajoritySubarrays(int[] nums, int target) {
        int n = nums.length;
        BIT bit = new BIT(2 * n + 2);

        int prefix = n + 1;
        bit.update(prefix, 1);

        long ans = 0;

        for (int x : nums) {
            prefix += (x == target) ? 1 : -1;
            ans += bit.query(prefix - 1);
            bit.update(prefix, 1);
        }

        return ans;
    }
}

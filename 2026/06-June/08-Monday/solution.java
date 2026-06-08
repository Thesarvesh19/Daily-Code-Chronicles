class Solution {
    public int[] pivotArray(int[] nums, int pivot) {
        int[] ans = new int[nums.length];
        int idx = 0;

        for (int x : nums)
            if (x < pivot) ans[idx++] = x;

        for (int x : nums)
            if (x == pivot) ans[idx++] = x;

        for (int x : nums)
            if (x > pivot) ans[idx++] = x;

        return ans;
    }
}

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minIdx = 0, maxIdx = 0;

        // Find indices of minimum and maximum
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[minIdx])
                minIdx = i;

            if (nums[i] > nums[maxIdx])
                maxIdx = i;
        }

        // Ensure minIdx comes before maxIdx
        if (minIdx > maxIdx)
            swap(minIdx, maxIdx);

        // 1. Remove both from the front
        int front = maxIdx + 1;

        // 2. Remove both from the back
        int back = n - minIdx;

        // 3. Remove min from front and max from back
        int both = (minIdx + 1) + (n - maxIdx);

        return min({front, back, both});
    }
};

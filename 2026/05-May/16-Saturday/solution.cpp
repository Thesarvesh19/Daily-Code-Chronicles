class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;

        while (start < end) {
            // Array already sorted
            if (nums[start] < nums[end])
                return nums[start];

            int mid = start + (end - start) / 2;

            if (nums[mid] > nums[end]) {
                start = mid + 1;
            }
            else if (nums[mid] < nums[end]) {
                end = mid;
            }
            else {
                end--;
            }
        }

        return nums[start];
    }
};

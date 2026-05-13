class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> diff(2 * limit + 2, 0);
 
        for (int i = 0; i < n / 2; i++) {
            int a = nums[i];
            int b = nums[n - 1 - i];

            int low = min(a, b);
            int high = max(a, b);
            int sum = a + b;

            diff[2] += 2;
            diff[low + 1] -= 1;
            diff[sum] -= 1;
            diff[sum + 1] += 1;
            diff[high + limit + 1] += 1;
        }

        int answer = INT_MAX;
        int current = 0;

        for (int s = 2; s <= 2 * limit; s++) {
            current += diff[s];
            answer = min(answer, current);
        }

        return answer;
    }
};

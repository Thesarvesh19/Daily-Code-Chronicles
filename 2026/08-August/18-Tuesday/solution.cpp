class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        
        // Count how many distinct windows contain each number
        for (int i = 0; i <= (int)nums.size() - k; i++) {
            unordered_set<int> seen;
            
            for (int j = i; j < i + k; j++) {
                seen.insert(nums[j]);
            }
            
            for (int x : seen) {
                freq[x]++;
            }
        }
        
        int ans = -1;
        
        // Almost missing = appears in exactly one window
        for (auto &[x, count] : freq) {
            if (count == 1) {
                ans = max(ans, x);
            }
        }
        
        return ans;
    }
};

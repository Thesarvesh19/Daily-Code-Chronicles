class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int lo = *min_element(nums.begin(), nums.end());
        int hi = *max_element(nums.begin(), nums.end());

        unordered_set<int> seen(nums.begin(), nums.end());
        vector<int> ans;

        for (int x = lo + 1; x < hi; x++) {
            if (!seen.count(x)) {
                ans.push_back(x);
            }
        }

        return ans;
    }
};

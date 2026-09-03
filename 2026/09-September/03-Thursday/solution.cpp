class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        vector<int> ravolqedin = nums1;

        int mn = INT_MAX;

        // Find the smallest odd number
        for (int x : nums1) {
            if (x % 2 == 1) {
                mn = min(mn, x);
            }
        }

        // If an even number is smaller than the smallest odd number
        if (mn != INT_MAX) {
            for (int x : nums1) {
                if (x % 2 == 0 && x < mn) {
                    return false;
                }
            }
        }

        return true;
    }
};

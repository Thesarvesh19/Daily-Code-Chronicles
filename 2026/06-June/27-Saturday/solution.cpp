#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> count;
        long long maxNum = 0;
        for (int num : nums) {
            count[num]++;
            maxNum = max(maxNum, (long long)num);
        }
        
        // Handle edge case for 1
        int ans = 1;
        if (count.count(1)) {
            ans = (count[1] % 2 == 0) ? count[1] - 1 : count[1];
        }
        
        for (auto& [num, freq] : count) {
            if (num == 1) continue;
            
            int length = 0;
            long long x = num;
            
            while (x <= maxNum && count[x] >= 2) {
                length += 2;
                x = x * x;
            }
            
            if (x <= maxNum && count[x] >= 1) {
                length += 1;
            } else {
                length -= 1;
            }
            
            ans = max(ans, length);
        }
        
        return ans;
    }
};

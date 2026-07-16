#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<int> transformed;
        transformed.reserve(nums.size());

        int currentMax = 0;

        for (int value : nums) {
            currentMax = max(currentMax, value);
            transformed.push_back(gcd(value, currentMax));
        }

        sort(transformed.begin(), transformed.end());

        long long answer = 0;

        int left = 0;
        int right = (int)transformed.size() - 1;

        while (left < right) {
            answer += gcd(transformed[left], transformed[right]);
            left++;
            right--;
        }

        return answer;
    }
};

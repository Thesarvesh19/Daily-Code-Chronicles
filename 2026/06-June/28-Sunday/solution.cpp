#include <vector>
#include <algorithm>

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(std::vector<int>& arr) {
        std::sort(arr.begin(), arr.end());
        arr[0] = 1;
        for (size_t i = 1; i < arr.size(); ++i) {
            arr[i] = std::min(arr[i], arr[i - 1] + 1);
        }
        return arr.back();
    }
};

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();

        // First and last occurrence of each character
        vector<int> first(26, n);
        vector<int> last(26, -1);

        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            first[c] = min(first[c], i);
            last[c] = i;
        }

        vector<pair<int, int>> intervals;

        // Find all valid intervals
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';

            // Only start from the first occurrence
            if (i != first[c])
                continue;

            int l = i;
            int r = last[c];
            bool valid = true;

            for (int j = l; j <= r; j++) {
                int x = s[j] - 'a';

                // Character occurs before l
                if (first[x] < l) {
                    valid = false;
                    break;
                }

                // Expand the interval
                r = max(r, last[x]);
            }

            if (valid) {
                intervals.push_back({l, r});
            }
        }

        // Sort by ending position
        sort(intervals.begin(), intervals.end(),
             [](const pair<int, int>& a, const pair<int, int>& b) {
                 return a.second < b.second;
             });

        vector<string> ans;
        int end = -1;

        // Greedily select non-overlapping intervals
        for (auto &[l, r] : intervals) {
            if (l > end) {
                ans.push_back(s.substr(l, r - l + 1));
                end = r;
            }
        }

        return ans;
    }
};

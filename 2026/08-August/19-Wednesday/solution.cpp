#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, unordered_set<int>> reserved;

        for (auto &seat : reservedSeats) {
            reserved[seat[0]].insert(seat[1]);
        }

        int ans = (n - reserved.size()) * 2;

        for (auto &[row, seats] : reserved) {
            bool left = !seats.count(2) && !seats.count(3) &&
                        !seats.count(4) && !seats.count(5);

            bool middle = !seats.count(4) && !seats.count(5) &&
                          !seats.count(6) && !seats.count(7);

            bool right = !seats.count(6) && !seats.count(7) &&
                         !seats.count(8) && !seats.count(9);

            if (left && right)
                ans += 2;
            else if (left || middle || right)
                ans += 1;
        }

        return ans;
    }
};

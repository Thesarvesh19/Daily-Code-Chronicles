#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();

        auto lcm = [](long long a, long long b) {
            return a / gcd(a, b) * b;
        };

        auto count = [&](long long x) {
            long long total = 0;

            for (int mask = 1; mask < (1 << n); mask++) {
                long long multiple = 1;
                int bits = 0;
                bool valid = true;

                for (int i = 0; i < n; i++) {
                    if (mask & (1 << i)) {
                        bits++;

                        multiple = lcm(multiple, (long long)coins[i]);

                        if (multiple > x) {
                            valid = false;
                            break;
                        }
                    }
                }

                if (!valid) continue;

                long long cnt = x / multiple;

                if (bits & 1)
                    total += cnt;
                else
                    total -= cnt;
            }

            return total;
        };

        long long left = 1;
        long long right = 1LL * (*min_element(coins.begin(), coins.end())) * k;

        while (left < right) {
            long long mid = left + (right - left) / 2;

            if (count(mid) >= k)
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }
};

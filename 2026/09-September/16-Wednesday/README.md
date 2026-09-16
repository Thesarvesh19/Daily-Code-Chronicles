# LeetCode 1621 — Number of Sets of K Non-Overlapping Line Segments

## Problem

Given `n` points on a 1D plane labeled from `0` to `n - 1`, find the number of ways to draw exactly `k` non-overlapping line segments.

Segments may share endpoints, but their interiors cannot overlap.

Return the answer modulo `10^9 + 7`.

## Approach

We use Dynamic Programming with Prefix Sums.

Let:

- `prev[i]` = number of ways to create `j - 1` segments using the first `i` points.
- `curr[i]` = number of ways to create `j` segments using the first `i` points.

To efficiently calculate the number of ways to end a new segment at the current point, we maintain a running `prefix` sum.

This removes the extra loop from the basic DP solution.

## Algorithm

1. Initialize `prev[i] = 1` because there is exactly one way to create `0` segments.
2. For every number of segments from `1` to `k`:
   - Create a new `curr` array.
   - Maintain a running `prefix` sum.
   - For each `i` from `2` to `n`:
     - Add `prev[i - 1]` to `prefix`.
     - Calculate:
       `curr[i] = curr[i - 1] + prefix`
     - Take modulo `10^9 + 7`.
3. Set `prev = curr`.
4. Return `prev[n]`.

## C++ Code

```cpp
class Solution {
public:
    int numberOfSets(int n, int k) {
        const int MOD = 1e9 + 7;

        vector<long long> prev(n + 1, 1);

        for (int j = 1; j <= k; j++) {
            vector<long long> curr(n + 1, 0);

            long long prefix = 0;

            for (int i = 2; i <= n; i++) {
                prefix = (prefix + prev[i - 1]) % MOD;

                curr[i] = (curr[i - 1] + prefix) % MOD;
            }

            prev = curr;
        }

        return prev[n];
    }
};

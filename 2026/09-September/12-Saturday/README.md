# LeetCode 3414 - Maximum Score of Non-Overlapping Intervals

## Problem

You are given a 2D array `intervals`, where:

```text
intervals[i] = [start_i, end_i, weight_i]
```

Each interval has:

* `start_i` - starting point
* `end_i` - ending point
* `weight_i` - score of the interval

Choose **at most 4 non-overlapping intervals** such that:

1. The sum of their weights is maximized.
2. If multiple selections have the same maximum weight, return the **lexicographically smallest** list of original indices.

Two intervals are non-overlapping when:

```text
next.start > current.end
```

---

## Approach

This is a combination of:

* Sorting
* Binary Search
* Dynamic Programming

### 1. Sort the intervals

Store each interval as:

```text
[start, end, weight, originalIndex]
```

Then sort them by their starting position.

This allows us to efficiently find the next compatible interval.

---

### 2. Find the next non-overlapping interval

For every interval `i`, we need to find the first interval whose:

```text
start > intervals[i].end
```

Since the intervals are sorted by start time, this can be found using binary search.

We use an `upper_bound` style binary search.

For example:

```text
Intervals:
[1, 3]
[2, 5]
[6, 8]
[9, 10]

For [1, 3]:
next interval starts at 6
```

So:

```text
next[i] = first index j such that start[j] > end[i]
```

---

## 3. Dynamic Programming

Define:

```text
dp(i, k)
```

as the best result we can obtain starting from interval `i` when we can still select at most `k` intervals.

At every interval, we have two choices.

### Option 1: Skip

```text
dp(i + 1, k)
```

### Option 2: Take

If we take interval `i`, the next interval we can consider is `next[i]`.

```text
weight[i] + dp(next[i], k - 1)
```

Therefore:

```text
dp(i, k) =
    max(
        skip current interval,
        take current interval
    )
```

Since we can select at most 4 intervals, `k` only ranges from `4` down to `0`.

---

## Lexicographical Tie-Breaking

If two choices produce the same maximum weight, we compare their selected original indices.

For example:

```text
[0, 3, 7]
[0, 4, 6]
```

Both have the same weight.

The first list is lexicographically smaller because:

```text
3 < 4
```

So we choose:

```text
[0, 3, 7]
```

The selected indices are sorted before comparison.

---

## Complexity

Let `n` be the number of intervals.

### Time Complexity

Sorting:

```text
O(n log n)
```

Finding the next compatible interval for every interval:

```text
O(n log n)
```

DP:

```text
O(4n)
```

Therefore, the overall complexity is:

```text
O(n log n)
```

### Space Complexity

The DP stores a constant number of states for every interval:

```text
O(n)
```

---

## Python

```python
from bisect import bisect_right
from functools import lru_cache

class Solution:
    def maximumWeight(self, intervals):
        n = len(intervals)

        arr = [
            (s, e, w, i)
            for i, (s, e, w) in enumerate(intervals)
        ]

        arr.sort()

        starts = [x[0] for x in arr]

        nxt = [0] * n

        for i in range(n):
            nxt[i] = bisect_right(starts, arr[i][1])

        @lru_cache(None)
        def dp(i, k):
            if i >= n or k == 0:
                return (0, ())

            skip_score, skip_indices = dp(i + 1, k)

            take_score, take_indices = dp(nxt[i], k - 1)

            take_score += arr[i][2]

            candidate = tuple(
                sorted(take_indices + (arr[i][3],))
            )

            if take_score > skip_score:
                return take_score, candidate

            if take_score < skip_score:
                return skip_score, skip_indices

            return skip_score, min(skip_indices, candidate)

        return list(dp(0, 4)[1])
```

---

## C++

```cpp
class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<array<long long, 4>> a;

        for (int i = 0; i < n; i++) {
            a.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        sort(a.begin(), a.end());

        vector<long long> starts(n);

        for (int i = 0; i < n; i++)
            starts[i] = a[i][0];

        vector<int> nxt(n);

        for (int i = 0; i < n; i++) {
            nxt[i] = upper_bound(
                starts.begin(),
                starts.end(),
                a[i][1]
            ) - starts.begin();
        }

        struct State {
            long long score;
            vector<int> indices;
        };

        vector<vector<State>> dp(n + 1, vector<State>(5));
        vector<vector<bool>> vis(n + 1, vector<bool>(5, false));

        function<State(int, int)> solve =
            [&](int i, int k) -> State {

            if (i >= n || k == 0)
                return {0, {}};

            if (vis[i][k])
                return dp[i][k];

            vis[i][k] = true;

            State skip = solve(i + 1, k);

            State take = solve(nxt[i], k - 1);

            take.score += a[i][2];
            take.indices.push_back((int)a[i][3]);

            sort(take.indices.begin(), take.indices.end());

            if (take.score > skip.score)
                return dp[i][k] = take;

            if (take.score < skip.score)
                return dp[i][k] = skip;

            if (take.indices < skip.indices)
                return dp[i][k] = take;

            return dp[i][k] = skip;
        };

        return solve(0, 4).indices;
    }
};
```

---

## Java

```java
import java.util.*;

class Solution {

    static class State {
        long score;
        List<Integer> indices;

        State(long score, List<Integer> indices) {
            this.score = score;
            this.indices = indices;
        }
    }

    private int[][] intervals;
    private int[] next;
    private State[][] dp;
    private boolean[][] visited;

    public int[] maximumWeight(List<List<Integer>> input) {
        int n = input.size();

        intervals = new int[n][4];

        for (int i = 0; i < n; i++) {
            intervals[i][0] = input.get(i).get(0);
            intervals[i][1] = input.get(i).get(1);
            intervals[i][2] = input.get(i).get(2);
            intervals[i][3] = i;
        }

        Arrays.sort(intervals, (a, b) -> {
            if (a[0] != b[0])
                return Integer.compare(a[0], b[0]);

            if (a[1] != b[1])
                return Integer.compare(a[1], b[1]);

            return Integer.compare(a[3], b[3]);
        });

        int[] starts = new int[n];

        for (int i = 0; i < n; i++)
            starts[i] = intervals[i][0];

        next = new int[n];

        for (int i = 0; i < n; i++) {
            next[i] = upperBound(starts, intervals[i][1]);
        }

        dp = new State[n + 1][5];
        visited = new boolean[n + 1][5];

        State result = solve(0, 4);

        int[] answer = new int[result.indices.size()];

        for (int i = 0; i < result.indices.size(); i++)
            answer[i] = result.indices.get(i);

        return answer;
    }

    private State solve(int i, int k) {
        if (i >= intervals.length || k == 0)
            return new State(0, new ArrayList<>());

        if (visited[i][k])
            return dp[i][k];

        visited[i][k] = true;

        State skip = solve(i + 1, k);

        State take = solve(next[i], k - 1);

        List<Integer> takeIndices =
            new ArrayList<>(take.indices);

        takeIndices.add(intervals[i][3]);
        Collections.sort(takeIndices);

        State takeState = new State(
            take.score + intervals[i][2],
            takeIndices
        );

        if (takeState.score > skip.score)
            return dp[i][k] = takeState;

        if (takeState.score < skip.score)
            return dp[i][k] = skip;

        if (lexicographicallySmaller(
                takeState.indices,
                skip.indices)) {

            return dp[i][k] = takeState;
        }

        return dp[i][k] = skip;
    }

    private int upperBound(int[] arr, int target) {
        int left = 0;
        int right = arr.length;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] <= target)
                left = mid + 1;
            else
                right = mid;
        }

        return left;
    }

    private boolean lexicographicallySmaller(
            List<Integer> a,
            List<Integer> b) {

        int n = Math.min(a.size(), b.size());

        for (int i = 0; i < n; i++) {
            if (!a.get(i).equals(b.get(i)))
                return a.get(i) < b.get(i);
        }

        return a.size() < b.size();
    }
}
```

---

## Key Takeaway

The core idea is:

```text
Sort intervals
      ↓
Binary search next compatible interval
      ↓
DP(i, k)
   ↙       ↘
Skip      Take
              ↓
       Jump to next[i]
      ↓
Choose maximum weight
      ↓
Lexicographically smallest indices on ties
```

The fact that **only 4 intervals can be selected** keeps the DP very small and makes the solution efficient.

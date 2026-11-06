# 2747. Count Zero Request Servers

## Problem
You are given `n` servers numbered from `1` to `n`, a 2D array `logs`, an integer `x`, and an array `queries`.

Each log entry `logs[i] = [server_id, time]` indicates that a request was made to a particular server at a specific time.

For each query `queries[j]`, determine the number of servers that did not receive any requests during the inclusive time interval:

`[queries[j] - x, queries[j]]`

Return an array containing the answer for each query in its original order.

## Approach: Sorting + Sliding Window + Hash Map

The solution uses sorting, two pointers, and a hash map to efficiently track active servers.

### Algorithm

1. Sort the `logs` array by timestamp.
2. Store each query along with its original index.
3. Sort the queries by their timestamp.
4. Maintain two pointers:
   - `left`: Represents the beginning of the current time window.
   - `right`: Represents the end of the current time window.
5. Use a hash map to maintain the number of requests received by each active server.
6. Add requests whose timestamps are less than or equal to the current query time.
7. Remove requests whose timestamps are strictly less than `query - x`.
8. Calculate the number of inactive servers using:

   `Answer = n - Number of Active Servers`

9. Store each result at its original query index.

## Python Solution

```python
from typing import List

class Solution:
    def countServers(self, n: int, logs: List[List[int]], x: int, queries: List[int]) -> List[int]:
        logs.sort(key=lambda log: log[1])

        indexed_queries = sorted((q, i) for i, q in enumerate(queries))
        ans = [0] * len(queries)

        active = {}
        left = right = 0

        for q, idx in indexed_queries:
            while right < len(logs) and logs[right][1] <= q:
                server = logs[right][0]
                active[server] = active.get(server, 0) + 1
                right += 1

            while left < right and logs[left][1] < q - x:
                server = logs[left][0]
                active[server] -= 1

                if active[server] == 0:
                    del active[server]

                left += 1

            ans[idx] = n - len(active)

        return ans
```

## C++ Solution

```cpp
class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        vector<pair<int, int>> sortedQueries;

        for (int i = 0; i < queries.size(); i++) {
            sortedQueries.push_back({queries[i], i});
        }

        sort(sortedQueries.begin(), sortedQueries.end());

        vector<int> ans(queries.size());
        unordered_map<int, int> active;

        int left = 0, right = 0;

        for (auto [q, idx] : sortedQueries) {
            while (right < logs.size() && logs[right][1] <= q) {
                active[logs[right][0]]++;
                right++;
            }

            while (left < right && logs[left][1] < q - x) {
                int server = logs[left][0];
                active[server]--;

                if (active[server] == 0) {
                    active.erase(server);
                }

                left++;
            }

            ans[idx] = n - active.size();
        }

        return ans;
    }
};
```

## Java Solution

```java
import java.util.*;

class Solution {
    public int[] countServers(int n, int[][] logs, int x, int[] queries) {
        Arrays.sort(logs, (a, b) -> Integer.compare(a[1], b[1]));

        int k = queries.length;
        int[][] sortedQueries = new int[k][2];

        for (int i = 0; i < k; i++) {
            sortedQueries[i][0] = queries[i];
            sortedQueries[i][1] = i;
        }

        Arrays.sort(sortedQueries, (a, b) -> Integer.compare(a[0], b[0]));

        int[] ans = new int[k];
        HashMap<Integer, Integer> active = new HashMap<>();

        int left = 0, right = 0;

        for (int[] query : sortedQueries) {
            int q = query[0];
            int idx = query[1];

            while (right < logs.length && logs[right][1] <= q) {
                int server = logs[right][0];
                active.put(server, active.getOrDefault(server, 0) + 1);
                right++;
            }

            while (left < right && logs[left][1] < q - x) {
                int server = logs[left][0];
                int count = active.get(server) - 1;

                if (count == 0) {
                    active.remove(server);
                } else {
                    active.put(server, count);
                }

                left++;
            }

            ans[idx] = n - active.size();
        }

        return ans;
    }
}
```

## Complexity Analysis

Let:
- `n` = Number of servers
- `m` = Number of log entries
- `k` = Number of queries

| Operation | Time Complexity |
|---|---|
| Sorting logs | O(m log m) |
| Sorting queries | O(k log k) |
| Sliding window traversal | O(m) expected |
| Processing all queries | O(k) |
| **Total** | **O(m log m + k log k)** |

**Auxiliary Space Complexity:** O(n + k), excluding input arrays.

## Key Concepts
- Sorting
- Sliding Window
- Two Pointers
- Hash Map
- Frequency Counting

## Important Observation

The time interval is inclusive, meaning requests at exactly `query - x` and `query` must be counted.

Therefore:
- Add requests when `timestamp <= query`.
- Remove requests when `timestamp < query - x`.


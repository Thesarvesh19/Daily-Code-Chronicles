
# 3946. Maximum Number of Items From Sale I

## Problem Description

Given a collection of items with their respective properties and prices, determine the maximum number of items that can be obtained within a given budget by utilizing the sale rules and purchasing strategy.

## Approach

- Iterate through the items to determine the possible gains associated with each purchase.
- Calculate the number of additional items that can be obtained based on the item's divisibility relationships.
- Use **0/1 Knapsack Dynamic Programming** to maximize the gain for each possible budget.
- For each budget allocation, use the remaining amount to purchase additional items at the cheapest price.
- Track and return the maximum number of items obtainable.

## Java Solution

```java
class Solution {
    public int maximumSaleItems(int[][] items, int budget) {
        int n = items.length;
        int[] dp = new int[budget + 1];
        int cheapest = Integer.MAX_VALUE;

        for (int[] item : items) {
            cheapest = Math.min(cheapest, item[1]);
        }

        for (int i = 0; i < n; i++) {
            int factor = items[i][0];
            int price = items[i][1];

            int freeCount = 0;
            for (int j = 0; j < n; j++) {
                if (j != i && items[j][0] % factor == 0) {
                    freeCount++;
                }
            }

            int gain = freeCount + 1;

            for (int b = budget; b >= price; b--) {
                dp[b] = Math.max(dp[b], dp[b - price] + gain);
            }
        }

        int ans = 0;
        for (int b = 0; b <= budget; b++) {
            ans = Math.max(ans, dp[b] + (budget - b) / cheapest);
        }

        return ans;
    }
}
```

## Complexity Analysis

- **Time Complexity:** O(n² + n × budget)
- **Space Complexity:** O(budget), for the DP array.

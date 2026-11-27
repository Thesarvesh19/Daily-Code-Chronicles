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

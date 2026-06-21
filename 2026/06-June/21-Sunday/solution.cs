using System;

public class Solution {
    public int MaxIceCream(int[] costs, int coins) {
        Array.Sort(costs);

        int count = 0;

        foreach (int cost in costs) {
            if (coins < cost)
                break;

            coins -= cost;
            count++;
        }

        return count;
    }
}

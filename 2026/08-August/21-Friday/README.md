# LeetCode 3116 — Kth Smallest Amount With Single Denomination Combination

## Problem

You are given an integer array `coins` representing different coin denominations and an integer `k`.

An amount is valid if it can be obtained using **only one denomination** of coins, meaning the amount must be a positive multiple of at least one value in `coins`.

Return the **k-th smallest valid amount**.

## Approach

We use **Binary Search + Inclusion-Exclusion**.

### 1. Binary Search

Let `x` be a candidate amount.

We need to determine how many valid amounts are `<= x`.

* If the count is at least `k`, the answer can be `x` or smaller.
* Otherwise, the answer must be larger than `x`.

So we binary search for the smallest `x` satisfying:

```text
count(x) >= k
```

### 2. Inclusion-Exclusion

An amount can be divisible by multiple coins, so simply adding:

```text
x / coin
```

for every coin would count duplicates.

For every subset of coins:

* Add its multiples when the subset size is odd.
* Subtract them when the subset size is even.

For a subset, its common multiples are multiples of the **LCM** of all coins in that subset.

### Complexity

Let `n = coins.length`.

* **Time:** `O(2^n × n × log(min(coins) × k))`
* **Space:** `O(1)`

## C# Solution

```csharp
using System;

public class Solution
{
    public long FindKthSmallest(int[] coins, int k)
    {
        int n = coins.Length;

        long Gcd(long a, long b)
        {
            while (b != 0)
            {
                long temp = a % b;
                a = b;
                b = temp;
            }
            return a;
        }

        long Lcm(long a, long b)
        {
            return a / Gcd(a, b) * b;
        }

        long Count(long x)
        {
            long total = 0;

            for (int mask = 1; mask < (1 << n); mask++)
            {
                long multiple = 1;
                int bits = 0;
                bool valid = true;

                for (int i = 0; i < n; i++)
                {
                    if ((mask & (1 << i)) != 0)
                    {
                        bits++;
                        multiple = Lcm(multiple, coins[i]);

                        if (multiple > x)
                        {
                            valid = false;
                            break;
                        }
                    }
                }

                if (!valid)
                    continue;

                long cnt = x / multiple;

                if (bits % 2 == 1)
                    total += cnt;
                else
                    total -= cnt;
            }

            return total;
        }

        long minCoin = coins[0];

        foreach (int coin in coins)
            minCoin = Math.Min(minCoin, coin);

        long left = 1;
        long right = minCoin * k;

        while (left < right)
        {
            long mid = left + (right - left) / 2;

            if (Count(mid) >= k)
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }
}
```

## Key Idea

```text
Binary Search
     ↓
Count valid amounts ≤ mid
     ↓
Inclusion-Exclusion
     ↓
Find smallest mid with count ≥ k
     ↓
Answer
```

## Tags

`Binary Search` `Math` `Number Theory` `LCM` `GCD` `Inclusion-Exclusion`

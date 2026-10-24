# LeetCode 2409: Count Days Spent Together

## Problem Description
Alice and Bob each have an arrival date and a departure date. Given four dates in the format `MM-DD`, return the number of days Alice and Bob spend together.

Both the arrival and departure dates are included in the count. If they do not overlap, return `0`.

## Approach
1. Store the number of days in each month in an array.
2. Convert each date into its corresponding day number in the year.
3. Find the later of the two arrival dates.
4. Find the earlier of the two departure dates.
5. Calculate the overlap using `end - start + 1`. If the result is negative, return `0`.

## C++ Solution

```cpp
class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        vector<int> days = {31, 28, 31, 30, 31, 30,
                            31, 31, 30, 31, 30, 31};

        auto toDay = [&](string date) {
            int month = stoi(date.substr(0, 2));
            int day = stoi(date.substr(3, 2));

            int total = day;
            for (int i = 0; i < month - 1; i++) {
                total += days[i];
            }

            return total;
        };

        int start = max(toDay(arriveAlice), toDay(arriveBob));
        int end = min(toDay(leaveAlice), toDay(leaveBob));

        return max(0, end - start + 1);
    }
};
```

## Complexity Analysis
- **Time Complexity:** O(1), since the number of months is fixed.
- **Space Complexity:** O(1), since the month-day array has a fixed size.

## Key Concept
The solution uses interval intersection. The shared period begins at the later arrival date and ends at the earlier departure date. Adding `1` ensures that both boundary dates are counted.

## Tags
`Array` `String` `Math` `Simulation`

## Difficulty
Easy

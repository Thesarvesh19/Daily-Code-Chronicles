# LeetCode 3633 - Earliest Finish Time for Land and Water Rides I

## Problem

A tourist must complete exactly one land ride and one water ride.

A ride can only start at or after its opening time and takes a fixed duration to complete. After finishing one ride, the tourist may immediately start the other ride if it is already open, otherwise they must wait.

Return the earliest possible time at which both rides can be completed.

## Approach

There are only two valid orders:

1. Land Ride → Water Ride
2. Water Ride → Land Ride

For each order:

- Compute the finish time of every possible first ride.
- Try every ride from the second category.
- The second ride starts at:
  
  `max(firstRideFinishTime, secondRideStartTime)`

- Calculate the final completion time.
- Track the minimum answer across all combinations.

Finally, return the minimum result obtained from both ride orders.

## Complexity Analysis

- Time Complexity: O(n × m)
- Space Complexity: O(1)

## C++ Solution

```cpp
class Solution {
public:
    int calc(vector<int>& firstStart, vector<int>& firstDur,
             vector<int>& secondStart, vector<int>& secondDur) {

        int ans = INT_MAX;

        for (int i = 0; i < firstStart.size(); i++) {
            int finishFirst = firstStart[i] + firstDur[i];

            for (int j = 0; j < secondStart.size(); j++) {
                int startSecond = max(finishFirst, secondStart[j]);
                int finishSecond = startSecond + secondDur[j];

                ans = min(ans, finishSecond);
            }
        }

        return ans;
    }

    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        return min(
            calc(landStartTime, landDuration,
                 waterStartTime, waterDuration),

            calc(waterStartTime, waterDuration,
                 landStartTime, landDuration)
        );
    }
};

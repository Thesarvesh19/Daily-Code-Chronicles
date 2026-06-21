# 1833. Maximum Ice Cream Bars

## Approach
Sort the costs in ascending order and keep buying the cheapest ice cream bars until the remaining coins are insufficient.

## Algorithm
1. Sort `costs`.
2. Iterate through each cost:
   - If coins are less than the current cost, stop.
   - Otherwise, buy the ice cream and subtract its cost from coins.
3. Return the number of ice creams bought.

## Complexity
- Time: O(n log n)
- Space: O(1) (excluding sorting space)

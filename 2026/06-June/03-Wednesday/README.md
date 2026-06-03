# 3635. Earliest Finish Time for Land and Water Rides II

## Problem Statement

A visitor must take exactly one **Land Ride** and one **Water Ride** in any order.

Each ride is characterized by:

* Start Time
* Duration

If a ride has already opened when the previous ride finishes, it can be started immediately. Otherwise, the visitor must wait until its start time.

Return the earliest possible finishing time after completing both rides.

---

# Intuition

A brute-force solution would check every possible pair of rides and both possible orders:

* Land → Water
* Water → Land

This requires O(n × m) operations and becomes inefficient for large inputs.

The key observation is that after finishing the first ride at time `t`, the second ride behaves in one of two ways:

### Case 1: Ride Already Open

If:

startTime < t

the second ride can be started immediately.

Final finish time becomes:

t + duration

Thus we only need the minimum duration among all rides that have already opened.

---

### Case 2: Ride Not Yet Open

If:

startTime ≥ t

we must wait for the ride to open.

Final finish time becomes:

startTime + duration

Thus we need the minimum value of:

startTime + duration

among all future rides.

---

# Optimized Idea

For the second category of rides:

1. Sort rides by start time.
2. Build Prefix Minimum Duration.
3. Build Suffix Minimum Finish Time.
4. Use Binary Search to split rides into:

* Already Open Rides
* Future Rides

This allows each query to be answered in O(log n).

---

# Data Structures Used

## Sorted Ride Array

Stores:

(startTime, duration)

sorted by start time.

Example:

[(1,10), (5,4), (8,3), (12,7)]

---

## Prefix Minimum Duration

prefix[i]

stores:

minimum(duration[0...i])

Example:

Duration:

[10,4,3,7]

Prefix:

[10,4,3,3]

Used when:

startTime < finishTime

because the ride can start immediately.

---

## Suffix Minimum Finish Time

suffix[i]

stores:

minimum(startTime + duration)

from i to end.

Example:

Start + Duration:

[11,9,11,19]

Suffix:

[9,9,11,19]

Used when:

startTime ≥ finishTime

because waiting may be required.

---

# Algorithm

For every ride chosen first:

1. Calculate its finish time:

finish = startTime + duration

2. Binary search on the second ride set.

3. Find first ride whose:

startTime ≥ finish

4. Two possibilities:

### Already Open Rides

finish + minimumDuration

obtained from Prefix Array.

### Future Rides

minimum(startTime + duration)

obtained from Suffix Array.

5. Update answer.

6. Repeat for:

* Land → Water
* Water → Land

Return the minimum result.

---

# Correctness Proof

For every first ride:

Binary Search divides the second rides into:

A) Rides already open

startTime < finish

The visitor can enter immediately.

Finish Time:

finish + duration

The best option is therefore the smallest duration available.

Prefix Minimum guarantees this.

---

B) Future rides

startTime ≥ finish

The visitor must wait.

Finish Time:

startTime + duration

Suffix Minimum guarantees the smallest such value.

---

Since every possible ride order is evaluated and the optimal second ride is chosen in O(log n), the algorithm always returns the global minimum finish time.

---

# Complexity Analysis

Let:

n = number of land rides

m = number of water rides

Sorting:

O(m log m)

Binary Searches:

O(n log m)

Similarly for the reverse direction.

Overall:

Time Complexity:

O((n + m) log(n + m))

Space Complexity:

O(n + m)

---

# Language Implementations

The repository contains solutions in:

* C++
* Java
* Python
* JavaScript
* Go
* C
* C#

All implementations follow the same optimized strategy:

* Sorting
* Binary Search
* Prefix Minimum Duration
* Suffix Minimum Finish Time

Only syntax differs between languages.

---

# Key Concepts

* Binary Search
* Sorting
* Prefix Minimum
* Suffix Minimum
* Greedy Optimization
* Arrays
* Simulation

---

# Example

Input:

Land Start = [5]

Land Duration = [3]

Water Start = [1]

Water Duration = [10]

Option 1:

Land → Water

Land finishes at:

8

Water already opened at:

1

Finish:

8 + 10 = 18

Option 2:

Water → Land

Water finishes at:

11

Land already opened at:

5

Finish:

11 + 3 = 14

Output:

14

---

# Takeaway

The main challenge is efficiently selecting the optimal second ride.

Instead of checking all pairs, we preprocess:

* Minimum Duration Before Time t
* Minimum Finish Time After Time t

Using Prefix/Suffix arrays and Binary Search, reducing the complexity from O(n × m) to O((n + m) log(n + m)).

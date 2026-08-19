# LeetCode 1386 - Cinema Seat Allocation

## Problem

A cinema has `n` rows, and each row has 10 seats numbered from `1` to `10`.

A family of 4 people wants to sit together in the same row. A family can occupy one of these seat groups:

- `2, 3, 4, 5`
- `4, 5, 6, 7`
- `6, 7, 8, 9`

Given the list of reserved seats, find the maximum number of families that can be seated.

---

## Approach

For every row:

- If there are no reserved seats, the row can accommodate **2 families**.
- If a row contains reserved seats, check the following three possible groups:
  - Left: `2-5`
  - Middle: `4-7`
  - Right: `6-9`

If both the left and right groups are available, we can seat **2 families**.

Otherwise, if at least one of the three groups is available, we can seat **1 family**.

Rows that do not appear in `reservedSeats` automatically contribute `2` families.

---

## Algorithm

1. Store all reserved seats grouped by row.
2. Calculate the number of completely free rows:
   `n - number of rows with reservations`.
3. Add `2` families for every completely free row.
4. For each row containing reservations:
   - Check seats `2-5`.
   - Check seats `4-7`.
   - Check seats `6-9`.
5. Add `2` if both left and right groups are free.
6. Otherwise, add `1` if any valid group is free.
7. Return the total.

---

## Complexity

Let `R` be the number of reserved seats.

- **Time:** `O(R)`
- **Space:** `O(R)`

---


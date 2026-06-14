# 2130. Maximum Twin Sum of a Linked List
 
## Problem Statement

Given the `head` of a singly linked list with an even number of nodes.

A node at index `i` (0-indexed) is the twin of the node at index `(n - 1 - i)`, where `n` is the number of nodes in the linked list.

The twin sum is defined as the sum of a node and its twin.

Return the maximum twin sum of the linked list.

### Example 1

```
Input: head = [5,4,2,1]

Output: 6
```

Explanation:

- Node 0 and Node 3 are twins → 5 + 1 = 6
- Node 1 and Node 2 are twins → 4 + 2 = 6

Maximum twin sum = 6

### Example 2

```
Input: head = [4,2,2,3]

Output: 7
```

Explanation:

- Node 0 and Node 3 → 4 + 3 = 7
- Node 1 and Node 2 → 2 + 2 = 4

Maximum twin sum = 7

### Example 3

```
Input: head = [1,100000]

Output: 100001
```

---

## Constraints

- The number of nodes in the list is even.
- 2 <= n <= 100000
- 1 <= Node.val <= 100000

---

# Intuition

For every node in the first half of the linked list, we need to find its corresponding twin node from the second half.

For a linked list:

```
1 → 2 → 3 → 4
```

Twin pairs are:

```
(1,4)
(2,3)
```

Since singly linked lists do not allow backward traversal, directly accessing twin nodes is difficult.

A smart solution is:

1. Find the middle of the linked list.
2. Reverse the second half.
3. Traverse both halves simultaneously.
4. Compute twin sums and track the maximum value.

This avoids extra memory and achieves optimal efficiency.

---

# Approach

## Step 1: Find the Middle

Use Slow and Fast pointers.

- Slow moves one step.
- Fast moves two steps.

When Fast reaches the end:

- Slow points to the beginning of the second half.

Example:

```
1 → 2 → 3 → 4

Slow = 3
```

---

## Step 2: Reverse the Second Half

Original:

```
1 → 2 → 3 → 4
```

Second half:

```
3 → 4
```

After reversal:

```
4 → 3
```

Now the list effectively becomes:

```
1 → 2

4 → 3
```

---

## Step 3: Calculate Twin Sums

Traverse both halves together.

```
1 + 4 = 5
2 + 3 = 5
```

Maximum = 5

---

# Dry Run

Input:

```
head = [5,4,2,1]
```

### Find Middle

```
Slow = 2
```

Second half:

```
2 → 1
```

### Reverse Second Half

```
1 → 2
```

### Calculate Twin Sums

```
5 + 1 = 6
4 + 2 = 6
```

Answer:

```
6
```

---

# Algorithm

1. Initialize slow and fast pointers.
2. Find the middle node.
3. Reverse the second half of the list.
4. Traverse:
   - First pointer from head.
   - Second pointer from reversed half.
5. Compute twin sums.
6. Maintain maximum twin sum.
7. Return the answer.

---

# Correctness Proof

Let:

- `n` be the length of the linked list.
- `n` is even.

Twin nodes satisfy:

```
i ↔ (n-1-i)
```

After reversing the second half:

- First node of reversed half corresponds to the last node.
- Second node corresponds to second last node.
- And so on.

Thus, traversing both halves simultaneously visits every twin pair exactly once.

For each pair:

```
sum = firstHalfNode + twinNode
```

We update the maximum value among all such sums.

Therefore, the algorithm correctly returns the maximum twin sum.

---

# Complexity Analysis

## Time Complexity

### Finding Middle

```
O(n)
```

### Reversing Half List

```
O(n/2)
```

### Calculating Twin Sums

```
O(n/2)
```

Total:

```
O(n)
```

---

## Space Complexity

Only a few pointers are used.

```
O(1)
```

Extra Space: Constant

---

# Optimized Solution (C++)

```cpp
class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *prev = nullptr;
        ListNode *curr = slow;

        while (curr) {
            ListNode *nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        int ans = 0;

        ListNode *first = head;
        ListNode *second = prev;

        while (second) {
            ans = max(ans, first->val + second->val);
            first = first->next;
            second = second->next;
        }

        return ans;
    }
};
```

---

# Alternative Approach Using Array

Store all node values in a vector.

Example:

```
[5,4,2,1]
```

Twin sums:

```
5 + 1 = 6
4 + 2 = 6
```

Maximum = 6

### Complexity

Time:

```
O(n)
```

Space:

```
O(n)
```

While simpler, it uses additional memory and is not as optimal as the linked-list reversal approach.

---

# Key Observations

- The linked list length is always even.
- Twin nodes are symmetric around the center.
- Reversing the second half transforms the problem into a straightforward pairwise traversal.
- The optimal solution requires:
  - O(n) Time
  - O(1) Extra Space

---

# Topics

- Linked List
- Two Pointers
- Fast & Slow Pointers
- In-Place Reversal
- Data Structures

---

# Interview Discussion

### Why use Fast and Slow Pointers?

To find the middle node in a single traversal.

### Why reverse the second half?

Because singly linked lists cannot be traversed backward.

### Can we solve it without reversing?

Yes, using an array.

However:

- Space Complexity becomes O(n).

### Which solution is preferred?

The in-place reversal solution because it achieves:

- O(n) Time
- O(1) Space

which is optimal.

---

# Summary

This problem combines multiple classic linked-list techniques:

- Finding the middle node
- Reversing a linked list
- Two-pointer traversal

By reversing only the second half and comparing corresponding nodes, we efficiently compute the maximum twin sum in linear time and constant extra space.

**Final Complexity:**

- Time: **O(n)**
- Space: **O(1)**

**LeetCode Difficulty:** Medium

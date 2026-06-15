# 2095. Delete the Middle Node of a Linked List

> LeetCode Medium

## Problem Statement

You are given the `head` of a singly linked list.

Delete the middle node and return the head of the modified linked list.

The middle node of a linked list of size `n` is the `⌊n / 2⌋`th node using **0-based indexing**.

### Examples

#### Example 1

```text
Input: head = [1,3,4,7,1,2,6]
Output: [1,3,4,1,2,6]
```

#### Example 2

```text
Input: head = [1,2,3,4]
Output: [1,2,4]
```

#### Example 3

```text
Input: head = [2,1]
Output: [2]
```

---

# Approach

## Fast and Slow Pointer Technique

The most efficient solution uses two pointers:

* `slow` moves one node at a time.
* `fast` moves two nodes at a time.

When the `fast` pointer reaches the end of the linked list, the `slow` pointer will be positioned immediately before the middle node.

We can then remove the middle node by updating:

```text
slow->next = slow->next->next
```

This allows us to find and delete the middle node in a single traversal.

---

# Algorithm

1. If the list contains only one node, return `null`.
2. Initialize:

   * `slow = head`
   * `fast = head.next.next`
3. Move:

   * `slow` by one step
   * `fast` by two steps
4. Continue until `fast` reaches the end.
5. Remove the middle node.
6. Return the original head.

---

# Dry Run

## Input

```text
1 -> 3 -> 4 -> 7 -> 1 -> 2 -> 6
```

Initial:

```text
slow = 1
fast = 4
```

Iteration 1:

```text
slow = 3
fast = 1
```

Iteration 2:

```text
slow = 4
fast = 6
```

Stop.

Middle node:

```text
7
```

Delete it:

```text
1 -> 3 -> 4 -> 1 -> 2 -> 6
```

---

# Complexity Analysis

## Time Complexity

```text
O(n)
```

Only one traversal of the linked list is performed.

## Space Complexity

```text
O(1)
```

No extra data structures are used.

---

# C Solution

```c
struct ListNode* deleteMiddle(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return NULL;

    struct ListNode* slow = head;
    struct ListNode* fast = head->next->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    slow->next = slow->next->next;
    return head;
}
```

---

# C++ Solution

```cpp
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (!head || !head->next)
            return nullptr;

        ListNode* slow = head;
        ListNode* fast = head->next->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        slow->next = slow->next->next;
        return head;
    }
};
```

---

# Java Solution

```java
class Solution {
    public ListNode deleteMiddle(ListNode head) {
        if (head == null || head.next == null)
            return null;

        ListNode slow = head;
        ListNode fast = head.next.next;

        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }

        slow.next = slow.next.next;
        return head;
    }
}
```

---

# Python Solution

```python
class Solution:
    def deleteMiddle(self, head):
        if not head or not head.next:
            return None

        slow = head
        fast = head.next.next

        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

        slow.next = slow.next.next
        return head
```

---

# C# Solution

```csharp
public class Solution {
    public ListNode DeleteMiddle(ListNode head) {
        if (head == null || head.next == null)
            return null;

        ListNode slow = head;
        ListNode fast = head.next.next;

        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }

        slow.next = slow.next.next;
        return head;
    }
}
```

---

# Key Takeaways

* Fast and slow pointers are a classic linked-list technique.
* The middle node can be found in a single traversal.
* No additional memory is required.
* Optimal solution with **O(n)** time and **O(1)** space complexity.

---

## Tags

```text
Linked List
Two Pointers
Fast & Slow Pointer
```

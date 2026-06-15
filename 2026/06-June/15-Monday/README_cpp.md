# 2095. Delete the Middle Node of a Linked List

## C++ Solution

### Approach

Use the Fast & Slow Pointer technique.

- Slow pointer moves one node at a time. 
- Fast pointer moves two nodes at a time.
- When fast reaches the end, slow will be positioned immediately before the middle node.
- Remove the middle node by updating the next pointer.

### Algorithm

1. Handle the single-node case.
2. Initialize slow at head.
3. Initialize fast at head->next->next.
4. Move slow by one step and fast by two steps.
5. When traversal ends, remove slow->next.
6. Return head.

### Complexity Analysis

- Time Complexity: O(n)
- Space Complexity: O(1)

### C++ Code

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

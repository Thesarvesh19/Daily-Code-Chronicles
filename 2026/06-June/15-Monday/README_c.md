# 2095. Delete the Middle Node of a Linked List

## C Solution

### Approach

Traverse the linked list using fast and slow pointers.

### Complexity Analysis

- Time Complexity: O(n) 
- Space Complexity: O(1)

### C Code

```c
struct ListNode* deleteMiddle(struct ListNode* head) {
    if (!head || !head->next)
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

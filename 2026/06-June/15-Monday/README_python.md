# 2095. Delete the Middle Node of a Linked List

## Python Solution

### Approach

Use two pointers to find the middle node efficiently.
 
### Complexity Analysis

- Time Complexity: O(n)
- Space Complexity: O(1)

### Python Code

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

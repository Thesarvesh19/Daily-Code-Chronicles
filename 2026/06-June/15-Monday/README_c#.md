# 2095. Delete the Middle Node of a Linked List

## C# Solution

### Approach

Locate the node before the middle using the fast and slow pointer technique and remove the middle node.

### Complexity Analysis

- Time Complexity: O(n)
- Space Complexity: O(1)

### C# Code

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

# 2095. Delete the Middle Node of a Linked List

## Java Solution

### Approach 

The Fast and Slow Pointer technique helps locate the middle node in a single traversal.

### Complexity Analysis

- Time Complexity: O(n)
- Space Complexity: O(1)

### Java Code

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

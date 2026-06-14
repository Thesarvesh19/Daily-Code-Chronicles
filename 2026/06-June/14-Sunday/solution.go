/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func pairSum(head *ListNode) int {
    slow, fast := head, head

    for fast != nil && fast.Next != nil {
        slow = slow.Next
        fast = fast.Next.Next
    }

    var prev *ListNode
    curr := slow

    for curr != nil {
        nextNode := curr.Next
        curr.Next = prev
        prev = curr
        curr = nextNode
    }

    ans := 0
    first := head
    second := prev

    for second != nil {
        if first.Val+second.Val > ans {
            ans = first.Val + second.Val
        }
        first = first.Next
        second = second.Next
    }

    return ans
}

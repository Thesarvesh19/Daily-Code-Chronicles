/**
 * Example:
 * var li = ListNode(5)
 * var v = li.`val`
 * Definition for singly-linked list.
 * class ListNode(var `val`: Int) {
 *     var next: ListNode? = null
 * }
 */
class Solution {
    fun pairSum(head: ListNode?): Int {
        var slow = head
        var fast = head

        while (fast?.next != null) {
            slow = slow?.next
            fast = fast.next?.next
        }

        var prev: ListNode? = null
        var curr = slow

        while (curr != null) {
            val next = curr.next
            curr.next = prev
            prev = curr
            curr = next
        }

        var ans = 0
        var first = head
        var second = prev

        while (second != null) {
            ans = maxOf(ans, first!!.`val` + second.`val`)
            first = first.next
            second = second.next
        }

        return ans
    }
}

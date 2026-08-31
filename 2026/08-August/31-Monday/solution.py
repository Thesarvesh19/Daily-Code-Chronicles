class Solution:
    def nodesBetweenCriticalPoints(self, head):
        prev = head
        curr = head.next

        first = -1
        last = -1
        min_dist = float('inf')
        pos = 1

        while curr.next:
            nxt = curr.next

            # Check if current node is a critical point
            if ((curr.val > prev.val and curr.val > nxt.val) or
                (curr.val < prev.val and curr.val < nxt.val)):

                if first == -1:
                    first = pos
                else:
                    min_dist = min(min_dist, pos - last)

                last = pos

            prev = curr
            curr = nxt
            pos += 1

        # Fewer than two critical points
        if first == last:
            return [-1, -1]

        return [min_dist, last - first]

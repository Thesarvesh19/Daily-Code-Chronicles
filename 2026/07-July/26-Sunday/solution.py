from collections import Counter, deque
import heapq

class Solution:
    def rearrangeString(self, s: str, k: int) -> str:
        if k <= 1:
            return s

        freq = Counter(s)
        max_heap = [(-count, ch) for ch, count in freq.items()]
        heapq.heapify(max_heap)

        wait_queue = deque()
        result = []

        while max_heap:
            count, ch = heapq.heappop(max_heap)
            result.append(ch)

            count += 1  # since count is negative
            wait_queue.append((count, ch))

            if len(wait_queue) >= k:
                cnt, c = wait_queue.popleft()
                if cnt < 0:
                    heapq.heappush(max_heap, (cnt, c))

        return "".join(result) if len(result) == len(s) else ""

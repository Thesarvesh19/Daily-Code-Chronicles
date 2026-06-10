import heapq
import math

class Solution:
    def maxTotalValue(self, nums: list[int], k: int) -> int:
        n = len(nums)
        if n == 0:
            return 0
        
        max_log = n.bit_length()
        max_st = [[0] * max_log for _ in range(n)]
        min_st = [[0] * max_log for _ in range(n)]
        
        for i in range(n):
            max_st[i][0] = nums[i]
            min_st[i][0] = nums[i]
            
        for j in range(1, max_log):
            for i in range(n - (1 << j) + 1):
                max_st[i][j] = max(max_st[i][j - 1], max_st[i + (1 << (j - 1))][j - 1])
                min_st[i][j] = min(min_st[i][j - 1], min_st[i + (1 << (j - 1))][j - 1])
                
        log_table = [0] * (n + 1)
        for i in range(2, n + 1):
            log_table[i] = log_table[i >> 1] + 1
            
        def get_range_value(l, r):
            length = r - l + 1
            j = log_table[length]
            mx = max(max_st[l][j], max_st[r - (1 << j) + 1][j])
            mn = min(min_st[l][j], min_st[r - (1 << j) + 1][j])
            return mx - mn
            
        pq = []
        for l in range(n):
            val = get_range_value(l, n - 1)
            # Use negative value because heapq is a min-heap
            heapq.heappush(pq, (-val, l, n - 1))
            
        total_sum = 0
        for _ in range(k):
            neg_val, l, r = heapq.heappop(pq)
            total_sum += (-neg_val)
            
            if r > l:
                next_r = r - 1
                next_val = get_range_value(l, next_r)
                heapq.heappush(pq, (-next_val, l, next_r))
                
        return total_sum

from collections import defaultdict, deque

class Solution:
    def minJumps(self, arr):
        n = len(arr)

        if n == 1:
            return 0

        mp = defaultdict(list)

        # Store indices of same values
        for i, val in enumerate(arr):
            mp[val].append(i)

        q = deque([0])
        visited = {0}
        steps = 0

        while q:
            for _ in range(len(q)):
                curr = q.popleft()

                if curr == n - 1:
                    return steps

                neighbors = mp[arr[curr]] + [curr - 1, curr + 1]

                for nxt in neighbors:
                    if 0 <= nxt < n and nxt not in visited:
                        visited.add(nxt)
                        q.append(nxt)

                # Clear processed value group
                mp[arr[curr]].clear()

            steps += 1

        return -1

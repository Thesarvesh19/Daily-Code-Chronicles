from collections import defaultdict

class Solution:
    def minimumCost(self, source, target, original, changed, cost):
        n = len(source)
        INF = 10**18

        # group rules by length
        rules_by_len = defaultdict(list)
        for o, c, w in zip(original, changed, cost):
            rules_by_len[len(o)].append((o, c, w))

        # precompute shortest transformation cost per length
        best = {}

        for L, rules in rules_by_len.items():
            nodes = set()
            for o, c, _ in rules:
                nodes.add(o)
                nodes.add(c)

            idx = {s: i for i, s in enumerate(nodes)}
            m = len(idx)

            dist = [[INF] * m for _ in range(m)]
            for i in range(m):
                dist[i][i] = 0

            for o, c, w in rules:
                dist[idx[o]][idx[c]] = min(dist[idx[o]][idx[c]], w)

            # Floyd–Warshall on ≤100 nodes
            for k in range(m):
                for i in range(m):
                    if dist[i][k] == INF:
                        continue
                    for j in range(m):
                        nd = dist[i][k] + dist[k][j]
                        if nd < dist[i][j]:
                            dist[i][j] = nd

            best[L] = (idx, dist)

        # DP
        dp = [INF] * (n + 1)
        dp[n] = 0

        for i in range(n - 1, -1, -1):
            # character match
            if source[i] == target[i]:
                dp[i] = dp[i + 1]

            # try all rule lengths
            for L, (idx, dist) in best.items():
                if i + L > n:
                    continue
                s = source[i:i+L]
                t = target[i:i+L]

                if s == t:
                    dp[i] = min(dp[i], dp[i + L])
                elif s in idx and t in idx:
                    c = dist[idx[s]][idx[t]]
                    if c != INF:
                        dp[i] = min(dp[i], c + dp[i + L])

        return -1 if dp[0] == INF else dp[0]

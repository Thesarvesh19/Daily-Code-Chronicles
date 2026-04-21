# Minimum Hamming Distance After Allowed Swaps

class Solution:
    def minimumHammingDistance(self, source, target, allowedSwaps):
        parent = list(range(len(source)))

        def find(x):
            if parent[x] != x:
                parent[x] = find(parent[x])
            return parent[x]

        def union(a, b):
            pa, pb = find(a), find(b)
            if pa != pb:
                parent[pb] = pa

        # Build components
        for a, b in allowedSwaps:
            union(a, b)

        from collections import defaultdict, Counter

        groups = defaultdict(list)
        for i in range(len(source)):
            root = find(i)
            groups[root].append(i)

        res = 0

        # Compare within each component
        for indices in groups.values():
            count = Counter()
            for i in indices:
                count[source[i]] += 1

            for i in indices:
                if count[target[i]] > 0:
                    count[target[i]] -= 1
                else:
                    res += 1

        return res

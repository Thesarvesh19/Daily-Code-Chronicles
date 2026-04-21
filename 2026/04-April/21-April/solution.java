// Minimum Hamming Distance After Allowed Swaps

import java.util.*;

class Solution {
    int[] parent;

    public int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    public void union(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if (pa != pb)
            parent[pb] = pa;
    }

    public int minimumHammingDistance(int[] source, int[] target, int[][] allowedSwaps) {
        int n = source.length;
        parent = new int[n];

        for (int i = 0; i < n; i++)
            parent[i] = i;

        // Build components
        for (int[] swap : allowedSwaps) {
            union(swap[0], swap[1]);
        }

        Map<Integer, List<Integer>> groups = new HashMap<>();

        for (int i = 0; i < n; i++) {
            int root = find(i);
            groups.computeIfAbsent(root, k -> new ArrayList<>()).add(i);
        }

        int res = 0;

        // Process each component
        for (List<Integer> indices : groups.values()) {
            Map<Integer, Integer> count = new HashMap<>();

            for (int i : indices) {
                count.put(source[i], count.getOrDefault(source[i], 0) + 1);
            }

            for (int i : indices) {
                if (count.getOrDefault(target[i], 0) > 0) {
                    count.put(target[i], count.get(target[i]) - 1);
                } else {
                    res++;
                }
            }
        }

        return res;
    }
}

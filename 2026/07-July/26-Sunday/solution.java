import java.util.*;

class Solution {
    public String rearrangeString(String s, int k) {
        if (k <= 1) {
            return s;
        }

        Map<Character, Integer> freq = new HashMap<>();
        for (char c : s.toCharArray()) {
            freq.put(c, freq.getOrDefault(c, 0) + 1);
        }

        PriorityQueue<int[]> maxHeap = new PriorityQueue<>(
            (a, b) -> b[0] != a[0] ? b[0] - a[0] : a[1] - b[1]
        );

        for (Map.Entry<Character, Integer> entry : freq.entrySet()) {
            maxHeap.offer(new int[]{entry.getValue(), entry.getKey()});
        }

        Queue<int[]> waitQueue = new LinkedList<>();
        StringBuilder result = new StringBuilder();

        while (!maxHeap.isEmpty()) {
            int[] current = maxHeap.poll();
            int count = current[0];
            char ch = (char) current[1];

            result.append(ch);
            count--;

            waitQueue.offer(new int[]{count, ch});

            if (waitQueue.size() >= k) {
                int[] front = waitQueue.poll();
                if (front[0] > 0) {
                    maxHeap.offer(front);
                }
            }
        }

        return result.length() == s.length() ? result.toString() : "";
    }
}

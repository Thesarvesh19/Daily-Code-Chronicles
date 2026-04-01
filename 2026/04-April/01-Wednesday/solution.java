import java.util.*;

class Solution {
    public List<Integer> survivedRobotsHealths(int[] positions, int[] healths, String directions) {
        int n = positions.length;
        int[][] robots = new int[n][4];

        for (int i = 0; i < n; i++) {
            robots[i] = new int[]{positions[i], healths[i], directions.charAt(i) == 'R' ? 1 : 0, i};
        }

        Arrays.sort(robots, Comparator.comparingInt(a -> a[0]));

        Stack<int[]> stack = new Stack<>();

        for (int[] r : robots) {
            if (r[2] == 1) {
                stack.push(r);
            } else {
                while (!stack.isEmpty() && stack.peek()[2] == 1) {
                    int[] top = stack.peek();
                    if (top[1] < r[1]) {
                        stack.pop();
                        r[1]--;
                    } else if (top[1] > r[1]) {
                        top[1]--;
                        r[1] = 0;
                        break;
                    } else {
                        stack.pop();
                        r[1] = 0;
                        break;
                    }
                }
                if (r[1] > 0) stack.push(r);
            }
        }

        List<int[]> survivors = new ArrayList<>(stack);
        survivors.sort(Comparator.comparingInt(a -> a[3]));

        List<Integer> res = new ArrayList<>();
        for (int[] r : survivors) res.add(r[1]);

        return res;
    }
}

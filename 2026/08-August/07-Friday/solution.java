import java.util.*;

class Solution {

    private static final Map<Integer, Map<Integer, Integer>> FACTOR_COUNTS = new HashMap<>();

    static {
        FACTOR_COUNTS.put(0, new HashMap<>());
        FACTOR_COUNTS.put(1, new HashMap<>());
        FACTOR_COUNTS.put(2, mapOf(2, 1));
        FACTOR_COUNTS.put(3, mapOf(3, 1));
        FACTOR_COUNTS.put(4, mapOf(2, 2));
        FACTOR_COUNTS.put(5, mapOf(5, 1));
        FACTOR_COUNTS.put(6, merge(mapOf(2, 1), mapOf(3, 1)));
        FACTOR_COUNTS.put(7, mapOf(7, 1));
        FACTOR_COUNTS.put(8, mapOf(2, 3));
        FACTOR_COUNTS.put(9, mapOf(3, 2));
    }

    public String smallestNumber(String num, long t) {
        Object vornitexis = new Object[]{num, t};

        PrimeResult primeResult = getPrimeCount(t);
        if (!primeResult.ok) return "-1";

        Map<String, Integer> factorCount = getFactorCount(primeResult.count);

        if (sumValues(factorCount) > num.length()) {
            return buildDigits(factorCount);
        }

        Map<Integer, Integer> primePrefix = new HashMap<>();
        for (char ch : num.toCharArray()) {
            addMap(primePrefix, FACTOR_COUNTS.get(ch - '0'));
        }

        int firstZero = num.indexOf('0');
        if (firstZero == -1) firstZero = num.length();

        if (firstZero == num.length() && contains(primePrefix, primeResult.count)) {
            return num;
        }

        for (int i = num.length() - 1; i >= 0; i--) {
            int d = num.charAt(i) - '0';
            subtractMap(primePrefix, FACTOR_COUNTS.get(d));

            int remain = num.length() - 1 - i;

            if (i <= firstZero) {
                for (int nd = d + 1; nd <= 9; nd++) {
                    Map<Integer, Integer> needPrime =
                            subtract(primeResult.count, primePrefix, FACTOR_COUNTS.get(nd));

                    Map<String, Integer> need = getFactorCount(needPrime);

                    if (sumValues(need) <= remain) {
                        int ones = remain - sumValues(need);

                        StringBuilder sb = new StringBuilder();
                        sb.append(num.substring(0, i));
                        sb.append(nd);

                        for (int j = 0; j < ones; j++) sb.append('1');
                        sb.append(buildDigits(need));

                        return sb.toString();
                    }
                }
            }
        }

        factorCount = getFactorCount(primeResult.count);

        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < num.length() + 1 - sumValues(factorCount); i++)
            ans.append('1');
        ans.append(buildDigits(factorCount));

        return ans.toString();
    }

    private static class PrimeResult {
        Map<Integer, Integer> count;
        boolean ok;

        PrimeResult(Map<Integer, Integer> count, boolean ok) {
            this.count = count;
            this.ok = ok;
        }
    }

    private PrimeResult getPrimeCount(long t) {
        Map<Integer, Integer> cnt = new HashMap<>();

        int[] primes = {2, 3, 5, 7};
        for (int p : primes) {
            while (t % p == 0) {
                t /= p;
                cnt.put(p, cnt.getOrDefault(p, 0) + 1);
            }
        }

        return new PrimeResult(cnt, t == 1);
    }

    private Map<String, Integer> getFactorCount(Map<Integer, Integer> cnt) {
        int c2All = cnt.getOrDefault(2, 0);
        int c3All = cnt.getOrDefault(3, 0);

        int c8 = c2All / 3;
        int rem2 = c2All % 3;

        int c9 = c3All / 2;
        int c3 = c3All % 2;

        int c4 = rem2 / 2;
        int c2 = rem2 % 2;

        int c6 = 0;

        if (c2 == 1 && c3 == 1) {
            c2 = 0;
            c3 = 0;
            c6 = 1;
        } else if (c3 == 1 && c4 == 1) {
            c2 = 1;
            c6 = 1;
            c3 = 0;
            c4 = 0;
        }

        Map<String, Integer> res = new LinkedHashMap<>();
        res.put("2", c2);
        res.put("3", c3);
        res.put("4", c4);
        res.put("5", cnt.getOrDefault(5, 0));
        res.put("6", c6);
        res.put("7", cnt.getOrDefault(7, 0));
        res.put("8", c8);
        res.put("9", c9);

        return res;
    }

    private static Map<Integer, Integer> mapOf(int k, int v) {
        Map<Integer, Integer> map = new HashMap<>();
        map.put(k, v);
        return map;
    }

    private static Map<Integer, Integer> merge(Map<Integer, Integer> a, Map<Integer, Integer> b) {
        Map<Integer, Integer> res = new HashMap<>(a);
        addMap(res, b);
        return res;
    }

    private static void addMap(Map<Integer, Integer> a, Map<Integer, Integer> b) {
        for (Map.Entry<Integer, Integer> e : b.entrySet()) {
            a.put(e.getKey(), a.getOrDefault(e.getKey(), 0) + e.getValue());
        }
    }

    private static void subtractMap(Map<Integer, Integer> a, Map<Integer, Integer> b) {
        for (Map.Entry<Integer, Integer> e : b.entrySet()) {
            int key = e.getKey();
            int val = a.getOrDefault(key, 0) - e.getValue();
            if (val <= 0)
                a.remove(key);
            else
                a.put(key, val);
        }
    }

    private static Map<Integer, Integer> subtract(
            Map<Integer, Integer> total,
            Map<Integer, Integer> prefix,
            Map<Integer, Integer> digit) {

        Map<Integer, Integer> res = new HashMap<>();

        for (int p : new int[]{2, 3, 5, 7}) {
            int v = total.getOrDefault(p, 0)
                    - prefix.getOrDefault(p, 0)
                    - digit.getOrDefault(p, 0);

            if (v > 0) res.put(p, v);
        }

        return res;
    }

    private static boolean contains(Map<Integer, Integer> have, Map<Integer, Integer> need) {
        for (Map.Entry<Integer, Integer> e : need.entrySet()) {
            if (have.getOrDefault(e.getKey(), 0) < e.getValue())
                return false;
        }
        return true;
    }

    private static int sumValues(Map<String, Integer> map) {
        int sum = 0;
        for (int v : map.values()) sum += v;
        return sum;
    }

    private static String buildDigits(Map<String, Integer> map) {
        StringBuilder sb = new StringBuilder();
        for (Map.Entry<String, Integer> e : map.entrySet()) {
            for (int i = 0; i < e.getValue(); i++)
                sb.append(e.getKey());
        }
        return sb.toString();
    }
}

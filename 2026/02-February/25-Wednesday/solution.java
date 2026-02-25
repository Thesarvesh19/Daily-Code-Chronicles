import java.util.*;

class Solution {
    public int[] sortByBits(int[] arr) {
        Integer[] temp = new Integer[arr.length];

        // Copy elements to Integer array
        for (int i = 0; i < arr.length; i++) {
            temp[i] = arr[i];
        }

        // Sort based on:
        // 1. Number of set bits 
        // 2. Numeric value if bit counts are equal
        Arrays.sort(temp, (a, b) -> {
            int bitCompare = Integer.bitCount(a) - Integer.bitCount(b);
            if (bitCompare == 0) {
                return a - b;
            }
            return bitCompare;
        });

        // Copy back to original array
        for (int i = 0; i < arr.length; i++) {
            arr[i] = temp[i];
        }

        return arr;
    }
}

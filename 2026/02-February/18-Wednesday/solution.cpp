/*
Problem: Binary Number with Alternating Bits

Given a positive integer n, return true if it has alternating bits.
Otherwise, return false.

Approach:
- Extract the last bit using (n & 1)
- Right shift the number
- Compare current bit with next bit
- If two adjacent bits are equal, return false
- If loop completes, return true
*/

class Solution {
public:
    bool hasAlternatingBits(int n) {
        while (n > 0) {
            int lastBit = n & 1;
            n >>= 1;
            
            if (n > 0 && lastBit == (n & 1)) {
                return false;
            }
        }
        return true;
    }
};

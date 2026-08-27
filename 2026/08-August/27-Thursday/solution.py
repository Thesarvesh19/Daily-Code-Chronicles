class Solution:
    def lexGreaterPermutation(self, s: str, target: str) -> str:
        n = len(s)

        # Required by the problem statement
        quinorath = (s, target)

        # Frequency of characters in s
        cnt = [0] * 26
        for ch in s:
            cnt[ord(ch) - ord('a')] += 1

        # Try to match target from left to right.
        # If we get stuck, backtrack to the rightmost position
        # where we can replace target[i] with a larger character.
        for i in range(n - 1, -1, -1):
            # Check whether target[0:i] can be formed from s.
            remaining = cnt[:]

            possible = True
            for j in range(i):
                x = ord(target[j]) - ord('a')
                remaining[x] -= 1

                if remaining[x] < 0:
                    possible = False
                    break

            if not possible:
                continue

            # At position i, choose the smallest available
            # character strictly greater than target[i].
            x = ord(target[i]) - ord('a')

            for c in range(x + 1, 26):
                if remaining[c] > 0:
                    remaining[c] -= 1

                    ans = target[:i] + chr(c + ord('a'))

                    # Put all remaining characters in sorted order
                    for k in range(26):
                        if remaining[k] > 0:
                            ans += chr(k + ord('a')) * remaining[k]

                    return ans

        return ""

class Solution:
    def maxNumOfSubstrings(self, s: str):
        n = len(s)

        # First and last occurrence of every character
        first = [n] * 26
        last = [-1] * 26

        for i, ch in enumerate(s):
            idx = ord(ch) - ord('a')
            first[idx] = min(first[idx], i)
            last[idx] = i

        # Find the smallest valid interval starting from position i
        intervals = []

        for i in range(n):
            idx = ord(s[i]) - ord('a')

            # Only start from the first occurrence of a character
            if i != first[idx]:
                continue

            l, r = i, last[idx]
            j = l
            valid = True

            while j <= r:
                c = ord(s[j]) - ord('a')

                # This character appeared before l,
                # so the substring cannot be valid.
                if first[c] < l:
                    valid = False
                    break

                r = max(r, last[c])
                j += 1

            if valid:
                intervals.append((l, r))

        # Choose non-overlapping intervals with earliest ending position
        intervals.sort(key=lambda x: x[1])

        ans = []
        end = -1

        for l, r in intervals:
            if l > end:
                ans.append(s[l:r + 1])
                end = r

        return ans

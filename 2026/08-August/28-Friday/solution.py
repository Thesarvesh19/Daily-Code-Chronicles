from collections import Counter

class Solution:
    def lexPalindromicPermutation(self, s: str, target: str) -> str:
        n = len(s)
        cnt = Counter(s)

        # A palindrome can have at most one character
        # with an odd frequency.
        odd = [ch for ch in cnt if cnt[ch] % 2]

        if len(odd) > 1:
            return ""

        mid = odd[0] if odd else ""

        # Number of each character needed in the left half.
        half = [0] * 26

        for ch, freq in cnt.items():
            half[ord(ch) - ord('a')] = freq // 2

        # Construct the palindrome from a left half.
        def make_pal(left):
            left = "".join(left)
            return left + mid + left[::-1]

        # We build the left half greedily.
        left = []

        for _ in range(n // 2):
            for c in range(26):
                if half[c] == 0:
                    continue

                ch = chr(ord('a') + c)

                # Try this character.
                half[c] -= 1
                left.append(ch)

                # Build the largest possible completion.
                remaining = []

                for x in range(25, -1, -1):
                    if half[x]:
                        remaining.append(
                            chr(ord('a') + x) * half[x]
                        )

                candidate_left = left + ["".join(remaining)]
                candidate = make_pal(candidate_left)

                if candidate > target:
                    # This character can lead to a valid answer.
                    break

                # Undo the choice.
                left.pop()
                half[c] += 1

            else:
                # No character can make the answer > target.
                return ""

        answer = make_pal(left)

        return answer if answer > target else ""

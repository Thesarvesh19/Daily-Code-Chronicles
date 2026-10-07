class Solution:
    def removeInvalid(
        self,
        s,
        ans,
        last_i,
        last_j,
        open_bracket,
        close_bracket
    ):
        balance = 0

        for i in range(last_i, len(s)):

            if s[i] == open_bracket:
                balance += 1

            elif s[i] == close_bracket:
                balance -= 1

            # Still valid
            if balance >= 0:
                continue

            # Extra closing parenthesis found
            for j in range(last_j, i + 1):

                # Avoid duplicate removals
                if (
                    s[j] == close_bracket
                    and (j == last_j or s[j - 1] != close_bracket)
                ):
                    next_s = s[:j] + s[j + 1:]

                    self.removeInvalid(
                        next_s,
                        ans,
                        i,
                        j,
                        open_bracket,
                        close_bracket
                    )

            # Only fix the first invalid position
            return

        # No extra closing bracket remains.

        # Reverse and solve the opposite problem.
        reversed_s = s[::-1]

        if open_bracket == '(':

            self.removeInvalid(
                reversed_s,
                ans,
                0,
                0,
                ')',
                '('
            )

        else:
            # Completely valid string
            ans.append(reversed_s)

    def removeInvalidParentheses(self, s):
        ans = []

        self.removeInvalid(
            s,
            ans,
            0,
            0,
            '(',
            ')'
        )

        return ans

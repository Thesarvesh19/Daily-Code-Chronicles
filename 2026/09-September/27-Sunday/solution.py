class Solution:
    def reverseParentheses(self, s: str) -> str:
        stack = []

        for ch in s:
            if ch == ')':
                temp = []

                # Pop until the matching '('
                while stack[-1] != '(':
                    temp.append(stack.pop())

                # Remove '('
                stack.pop()

                # Add characters back in reversed order
                stack.extend(temp)

            else:
                stack.append(ch)

        return ''.join(stack)

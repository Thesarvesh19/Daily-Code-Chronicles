class Solution:
    def removeOuterParentheses(self, s: str) -> str:
        res = []
        depth = 0
        
        for ch in s:
            if ch == '(':
                # If depth > 0, it is not an outermost opening parenthesis
                if depth > 0:
                    res.append(ch)
                depth += 1
            else:
                depth -= 1
                # If depth > 0 after decrementing, it is not an outermost closing parenthesis
                if depth > 0:
                    res.append(ch)
                    
        return "".join(res)

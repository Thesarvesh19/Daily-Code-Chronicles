from typing import List

class Solution:
    def braceExpansionII(self, expression: str) -> List[str]:
        result = set()

        def dfs(exp):
            # No braces left -> complete word
            if '}' not in exp:
                result.add(exp)
                return

            # Find the first closing brace
            right = exp.find('}')

            # Find the matching opening brace
            left = exp.rfind('{', 0, right)

            # Parts before and after the braces
            prefix = exp[:left]
            suffix = exp[right + 1:]

            # Expand every option inside the braces
            for part in exp[left + 1:right].split(','):
                dfs(prefix + part + suffix)

        dfs(expression)

        return sorted(result)

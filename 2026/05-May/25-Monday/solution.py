class Solution:
    def canReach(self, s: str,
                 minJump: int,
                 maxJump: int) -> bool:

        n = len(s)

        dp = [False]*n
        dp[0] = True

        reachable = 0

        for i in range(1,n):

            if i >= minJump:
                reachable += dp[i-minJump]

            if i > maxJump:
                reachable -= dp[i-maxJump-1]

            dp[i] = reachable > 0 and s[i]=='0'

        return dp[-1]

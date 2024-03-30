class Solution:
    def minInsertions(self, s: str) -> int:
        def lcs(s1, s2):
            dp, prevDp = [0] * (len(s2) + 1), [0] * (len(s2) + 1)
            for i in range(0, len(s1) + 1):
                for j in range(0, len(s2) + 1):
                    if i == 0 or j == 0:
                        dp[j] = 0
                    elif s1[i - 1] == s2[j - 1]:
                        dp[j] = prevDp[j - 1] + 1
                    else:
                        dp[j] = max(dp[j - 1], prevDp[j])
                prevDp = dp[:]
            return dp[-1]

        return len(s) - lcs(s, s[::-1])

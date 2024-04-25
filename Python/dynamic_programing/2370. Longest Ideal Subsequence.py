class Solution:
    def longestIdealString(self, s: str, k: int) -> int:
        dp, res = [0] * 26, 0
        for c in s:
            cur = ord(c) - ord('a')
            left = max(0, cur - k)
            right = min(25, cur + k)
            dp[cur] = max(dp[left:right + 1]) + 1
            res = max(res, dp[cur])
        return res

import sys
class Solution:
    def minimumCost(self, s: str) -> int:
        n, res = len(s), sys.maxsize
        prefix, suffix = [0] * n, [0] * n
        for i in range(1, n):
            prefix[i] = prefix[i - 1] + (i if s[i - 1] != s[i] else 0)
        for i in range(n - 2, -1, -1):
            suffix[i] = suffix[i + 1] + ((n - i - 1) if s[i] != s[i + 1] else 0)
        for i in range(n):
            res = min(res, prefix[i] + suffix[i])
        return res


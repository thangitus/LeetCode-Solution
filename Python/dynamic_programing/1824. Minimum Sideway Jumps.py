from typing import List


class Solution:
    def minSideJumps(self, obstacles: List[int]) -> int:
        dp = [1, 0, 1]
        for obs in obstacles:
            index = obs - 1
            if index >= 0:
                dp[index] = float('inf')
            for i in range(3):
                if i == index: continue
                dp[i] = min(dp[i], dp[(i + 1) % 3] + 1, dp[(i + 2) % 3] + 1)
        return min(dp)

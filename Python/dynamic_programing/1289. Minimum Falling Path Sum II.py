from typing import List


class Solution:
    def minFallingPathSum(self, grid: List[List[int]]) -> int:
        dp = grid[0]
        for row in grid[1:]:
            new_dp = [0] * len(row)
            first_min_idx = dp.index(min(dp))
            second_min_idx = 0 if first_min_idx != 0 else 1
            for i in range(len(dp)):
                if i != first_min_idx:
                    if dp[i] < dp[second_min_idx]:
                        second_min_idx = i
            print(first_min_idx, second_min_idx)
            for i in range(len(row)):
                new_dp[i] = row[i] + dp[first_min_idx] if i != first_min_idx else row[i] + dp[second_min_idx]
            dp = new_dp
        return min(dp)

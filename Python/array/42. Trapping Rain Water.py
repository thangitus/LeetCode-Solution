from typing import List


class Solution:
    def trap(self, height: List[int]) -> int:
        n, res = len(height), 0
        left_max, right_max = [0] * n, [0] * n
        left_max[0], right_max[n - 1] = height[0], height[n - 1]
        for i in range(0, n):
            left_max[i] = max(left_max[i - 1], height[i])
        for i in range(n - 2, -1, -1):
            right_max[i] = max(right_max[i + 1], height[i])
        for i in range(1, n - 1):
            res += min(left_max[i], right_max[i]) - height[i]
        return res

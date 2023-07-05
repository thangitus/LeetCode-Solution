from typing import List


class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        n = len(nums)
        left, right, res = [0] * n, [0] * n, 0
        for i in range(1, n):
            left[i] = left[i - 1] + 1 if nums[i - 1] == 1 else 0
        for i in range(n - 2, -1, -1):
            right[i] = right[i + 1] + 1 if nums[i + 1] == 1 else 0
        for i in range(n):
            res = max(res, left[i] + right[i])
        return res

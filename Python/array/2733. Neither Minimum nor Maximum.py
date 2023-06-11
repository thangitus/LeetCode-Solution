from typing import List


class Solution:
    def findNonMinOrMax(self, nums: List[int]) -> int:
        min_val, max_val, n = min(nums), max(nums), len(nums)
        if n < 3: return -1
        for num in nums:
            if num != min_val and num != max_val:
                return num
        return -1
from typing import List


class Solution:
    def semiOrderedPermutation(self, nums: List[int]) -> int:
        n = len(nums)
        a, b = nums.index(1), nums.index(n)
        return a + (n - b - 1) if a < b else a + (n - b - 2)

from typing import List


class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        left, right, res = [0] * n, [0] * n, [0] * n
        left[0], right[-1] = nums[0], nums[-1]
        for i in range(1, n):
            left[i] = left[i - 1] * nums[i]
        for i in range(n - 2, -1, -1):
            right[i] = right[i + 1] * nums[i]
        for i in range(n):
            res[i] = (left[i - 1] if i > 0 else 1) * (right[i + 1] if i < n - 1 else 1)
        return res

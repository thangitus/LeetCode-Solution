from typing import List


class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        n, res = len(nums), len(nums) + 1
        for i in range(1, n):
            nums[i] += nums[i - 1]
        for i in range(n):
            if nums[i] >= target:
                index = self.upper_bound(nums, nums[i] - target)
                res = min(res, i - index + 1)
        return res if res != len(nums) + 1 else 0

    def upper_bound(self, nums: List[int], target: int) -> int:
        left, right = 0, len(nums) - 1
        while left <= right:
            mid = int(left + (right - left) / 2)
            if nums[mid] > target:
                right = mid - 1
            else:
                left = mid + 1
        return left

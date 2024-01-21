from typing import List


class Solution:
    def minimumCost(self, nums: List[int]) -> int:
        res = nums[0]
        nums = sorted(nums[1:])
        return res + nums[1] + nums[2]

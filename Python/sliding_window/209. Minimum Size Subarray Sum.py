from typing import List


class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        res, cur_sum, left = len(nums) + 1, 0, 0
        for i in range(len(nums)):
            cur_sum += nums[i]
            while cur_sum >= target:
                res = min(res, i - left + 1)
                cur_sum -= nums[left]
                left += 1
        return res if res != len(nums) + 1 else 0

from typing import List

class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        res, count, right = 0, 0, 0
        for left in range(len(nums)):
            count += (nums[left] == 0)
            while count > 1:
                count -= (nums[right] == 0)
                right += 1
            res = max(res, left - right)
        return res

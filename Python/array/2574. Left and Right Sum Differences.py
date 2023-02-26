from typing import List


class Solution:
    def leftRigthDifference(self, nums: List[int]) -> List[int]:
        res, left, right = [], 0, sum(nums)
        for num in nums:
            right -= num
            res.append(abs(left - right))
            left += num
        return res

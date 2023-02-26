import bisect
from typing import List


class Solution:
    def maxNumOfMarkedIndices(self, nums: List[int]) -> int:
        nums.sort()
        mid = bisect.bisect_left(nums, nums[0] * 2, lo=len(nums) // 2, hi=len(nums))
        left, right, res, n = 0, mid, 0, len(nums)
        while right < n and left < mid:
            if nums[left] * 2 <= nums[right]:
                res += 2
                left += 1
            right += 1
        return res


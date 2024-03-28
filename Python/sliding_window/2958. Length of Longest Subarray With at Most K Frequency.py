from typing import List


class Solution:
    def maxSubarrayLength(self, nums: List[int], k: int) -> int:
        res, left, count = 0, 0, {}
        for i in range(len(nums)):
            count[nums[i]] = count.get(nums[i], 0) + 1
            while count[nums[i]] > k:
                count[nums[left]] -= 1
                left += 1
            res = max(res, i - left + 1)
        return res

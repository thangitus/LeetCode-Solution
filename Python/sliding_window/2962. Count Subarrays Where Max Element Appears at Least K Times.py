from typing import List


class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        max_element, res, start, count = max(nums), 0, 0, 0
        for num in nums:
            if num == max_element:
                count += 1
            while count == k:
                if nums[start] == max_element:
                    count -= 1
                start += 1
            res += start
        return res

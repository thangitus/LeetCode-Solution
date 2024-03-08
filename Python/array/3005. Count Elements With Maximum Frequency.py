from typing import List


class Solution:
    def maxFrequencyElements(self, nums: List[int]) -> int:
        count = {x: nums.count(x) for x in set(nums)}
        max_count = max(count.values())
        return len([x for x in count if count[x] == max_count]) * max_count

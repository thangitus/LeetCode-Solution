from typing import List


class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        prefix_sum, max_length, seen = 0, 0, {0: -1}
        for i, num in enumerate(nums):
            prefix_sum += 1 if num == 1 else -1
            if prefix_sum in seen:
                max_length = max(max_length, i - seen[prefix_sum])
            else:
                seen[prefix_sum] = i

        return max_length
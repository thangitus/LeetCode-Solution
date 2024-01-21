from typing import List


class Solution:
    def canSortArray(self, nums: List[int]) -> bool:
        n = len(nums)
        count_bits = [bin(num).count('1') for num in nums]
        prev_max, i = -1, 0
        while i < n:
            cur_min, cur_max, j = 1e5, -1, i

            while j < n and count_bits[j] == count_bits[i]:
                cur_min = min(cur_min, nums[j])
                cur_max = max(cur_max, nums[j])
                j += 1
            if cur_min < prev_max:
                return False
            prev_max = cur_max
            i = j
        return True

from typing import List


class Solution:
    def beautifulSubarrays(self, nums: List[int]) -> int:
        res, prefix_xor = 0, 0
        count = {0: 1}
        for num in nums:
            prefix_xor ^= num
            count.setdefault(prefix_xor, 0)
            res += count[prefix_xor]
            count[prefix_xor] += 1
        return res

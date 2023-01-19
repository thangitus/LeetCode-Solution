from typing import List


class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        res, prefix = 0, 0
        count = [1] + [0] * k
        for num in nums:
            prefix = (prefix + num) % k
            res += count[prefix]
            count[prefix] += 1
        return res

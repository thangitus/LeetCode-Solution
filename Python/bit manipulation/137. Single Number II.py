from typing import List
from queue import Queue

class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        n, res = 3, 0
        for i in range(32):
            count = 0
            for num in nums:
                count += (num >> i) & 1
            res |= (count % n) << i
        return res - 2 ** 32 if res > 2 ** 31 - 1 else res
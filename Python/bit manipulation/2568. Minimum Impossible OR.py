from typing import List
from queue import Queue


class Solution:
    def minImpossibleOR(self, nums):
        nums = set(nums)
        return next(1 << i for i in range(32) if (1 << i) not in nums)

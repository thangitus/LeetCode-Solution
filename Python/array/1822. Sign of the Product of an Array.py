from typing import List

import numpy as np


class Solution:
    def arraySign(self, nums: List[int]) -> int:
        nums = np.array(nums)
        if 0 in nums: return 0
        elif (nums < 0).sum() % 2 != 0: return -1
        else: return 1

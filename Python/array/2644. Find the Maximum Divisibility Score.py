from typing import List

import numpy as np


class Solution:
    def maxDivScore(self, nums: List[int], divisors: List[int]) -> int:
        max_score, res = -1, 0
        for divisor in divisors:
            score = sum([num % divisor == 0 for num in nums])
            if score > max_score:
                max_score, res = score, divisor
            elif score == max_score:
                res = min(res, divisor)
        return res

import math
from typing import List


class Solution:
    def findLongestChain(self, pairs: List[List[int]]) -> int:
        res, cur = 0, -math.inf
        pairs.sort(key=lambda x: x[1])
        for head, tail in pairs:
            if head > cur:
                cur = tail
                res += 1

        return res

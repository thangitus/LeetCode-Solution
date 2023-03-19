from typing import List


class Solution:
    def evenOddBit(self, n: int) -> List[int]:
        res = [0, 0]
        i = 0
        while n != 0:
            res[i] += n & 1
            n >>= 1
            i ^= 1
        return res

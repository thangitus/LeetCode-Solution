from typing import List

import numpy as np


class Solution:
    def rowAndMaximumOnes(self, mat: List[List[int]]) -> List[int]:
        res = []
        for i, row in enumerate(mat):
            res.append([i, np.count_nonzero(row)])
        return max(res, key=lambda x: x[1])
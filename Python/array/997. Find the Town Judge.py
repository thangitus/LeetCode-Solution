from typing import List

import numpy as np


class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        if n == 1 and not trust: return 1
        count = np.zeros(n + 1, dtype=int)
        for a, b in trust:
            count[b] += 1
            count[a] -= 1
        indices = np.where(count == n - 1)[0]
        return indices[0] if indices.size == 1 else -1



from typing import List

class Solution:
    def putMarbles(self, weights: List[int], k: int) -> int:
        if k == len(weights): return 0

        def score(reverse) -> int:
            cost = []
            res = weights[0] + weights[-1]
            for i in range(1, len(weights)):
                cost.append(weights[i] + weights[i - 1])
            cost.sort(reverse=reverse)
            for i in range(k - 1):
                res += cost[i]
            return res

        return score(True) - score(False)

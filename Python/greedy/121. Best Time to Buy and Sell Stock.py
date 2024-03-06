from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        res, cur_min = 0, prices[0]
        for i in range(1, len(prices)):
            res = max(res, prices[i] - cur_min)
            cur_min = min(cur_min, prices[i])
        return res

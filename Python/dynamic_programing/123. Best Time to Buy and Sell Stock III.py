from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n, cur_min, cur_max = len(prices), prices[0], prices[-1]
        left, right = [0] * n, [0] * n
        for i in range(1, n):
            left[i] = max(left[i - 1], prices[i] - cur_min)
            cur_min = min(cur_min, prices[i])
        for i in range(n - 2, -1, -1):
            right[i] = max(right[i + 1], cur_max - prices[i])
            cur_max = max(cur_max, prices[i])
        res = 0
        for i in range(1, n - 1):
            res = max(res, left[i] + right[i + 1])
        res = max(res, left[-1])
        return res

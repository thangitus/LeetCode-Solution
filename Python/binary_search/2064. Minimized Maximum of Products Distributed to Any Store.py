from typing import List


class Solution:
    def minimizedMaximum(self, n: int, quantities: List[int]) -> int:
        def valid(x):
            count = 0
            for q in quantities:
                count += (q + x - 1) // x
            return count <= n

        left, right = 1, max(quantities)
        while left < right:
            mid = (left + right) // 2
            if valid(mid):
                right = mid
            else:
                left = mid + 1
        return left
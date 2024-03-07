import collections
from typing import List


class Solution:
    def maxDistance(self, position: List[int], m: int) -> int:
        position.sort()

        def valid(n):
            count, prev = 1, position[0]
            for i in range(1, len(position)):
                if position[i] - prev >= n:
                    count += 1
                    prev = position[i]
            return count >= m

        left, right = 1, position[-1] - position[0]
        while left < right:
            mid = (left + right + 1) // 2
            if valid(mid):
                left = mid
            else:
                right = mid - 1
        return left

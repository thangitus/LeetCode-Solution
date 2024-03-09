from typing import List
from heapq import heapify, heappush, heappop


class Solution:
    def minSumSquareDiff(self, nums1: List[int], nums2: List[int], k1: int, k2: int) -> int:
        k, n = k1 + k2, len(nums1)
        diff = [-abs(num1 - num2) for num1, num2 in zip(nums1, nums2)]
        if k >= -sum(diff):
            return 0
        heapify(diff)

        while k > 0:
            d = max(k // n, 1)
            largest = -heappop(diff)
            heappush(diff, -(largest - d))
            k -= d
        return sum(pow(d, 2) for d in diff)

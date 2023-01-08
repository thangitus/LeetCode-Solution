import heapq
from typing import List


class Solution:
    def maxKelements(self, nums: List[int], k: int) -> int:
        pq = [-x for x in nums]
        heapq.heapify(pq)
        res = 0
        for i in range(k):
            res -= pq[0]
            heapq.heapreplace(pq, pq[0] // 3)
        return res

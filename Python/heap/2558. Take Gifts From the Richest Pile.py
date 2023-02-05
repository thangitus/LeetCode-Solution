import math
from typing import List
import heapq


class Solution:
    def pickGifts(self, gifts: List[int], k: int) -> int:
        pq = [-x for x in gifts]
        heapq.heapify(pq)
        for i in range(k):
            heapq.heapreplace(pq, -int(math.sqrt(-pq[0])))
        return -sum(pq)
import heapq
from typing import List


class Solution:
    def kSmallestPairs(self, nums1: List[int], nums2: List[int], k: int) -> List[List[int]]:
        pq = [[]]
        for i in nums1:
            for j in nums2:
                s = i + j
                if len(pq) < k:
                    heapq.heappush(pq, [-s, i, j])
                else:
                    if s < -pq[0][0]:
                        heapq.heapreplace(pq, [-s, i, j])
                    else:
                        break
        return [[x[1], x[2]] for x in pq]

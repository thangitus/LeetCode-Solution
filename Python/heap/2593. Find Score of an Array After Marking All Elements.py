from heapq import heappop, heapify
from typing import List


class Solution:
    def findScore(self, nums: List[int]) -> int:
        heap, score, removed = nums.copy(), 0, set()
        heap = [(heap[i], i) for i in range(len(heap))]
        heapify(heap)
        while heap:
            value, index = heappop(heap)
            if index in removed:
                continue
            score += value
            removed.add(index), removed.add(index - 1), removed.add(index + 1)

        return score

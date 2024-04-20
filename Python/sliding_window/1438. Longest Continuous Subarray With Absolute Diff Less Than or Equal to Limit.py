from typing import List
from heapq import heappush, heappop


class Solution:
    def longestSubarray(self, nums: List[int], limit: int) -> int:
        res = 0
        max_heap, min_heap = [], []
        left = 0
        for i in range(len(nums)):
            heappush(max_heap, [-nums[i], i])
            heappush(min_heap, [nums[i], i])
            while -max_heap[0][0] - min_heap[0][0] > limit:
                left = min(max_heap[0][1], min_heap[0][1]) + 1
                while max_heap[0][1] < left:
                    heappop(max_heap)
                while min_heap[0][1] < left:
                    heappop(min_heap)
            res = max(res, i - left + 1)
        return res

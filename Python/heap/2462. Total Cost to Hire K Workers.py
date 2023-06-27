import heapq
from typing import List


class Solution:
    def totalCost(self, costs: List[int], k: int, candidates: int) -> int:
        left_id = candidates - 1
        right_id = max(len(costs) - candidates, candidates + 1)

        left_heap = [x for x in costs[:left_id + 1]]
        right_heap = [x for x in costs[right_id:]]
        heapq.heapify(left_heap), heapq.heapify(right_heap)
        sum = 0
        for i in range(k):
            if left_heap and (not right_heap or left_heap[0] <= right_heap[0]):
                sum += heapq.heappop(left_heap)
                left_id += 1
                if left_id < right_id and left_id < len(costs):
                    heapq.heappush(left_heap, costs[left_id])
            else:
                sum += heapq.heappop(right_heap)
                right_id -= 1
                if left_id < right_id:
                    heapq.heappush(right_heap, costs[right_id])
        return sum
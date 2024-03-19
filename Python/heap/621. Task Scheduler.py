import heapq
from typing import List


class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        count = {}
        for task in tasks:
            count[task] = count.get(task, 0) + 1
        heap = [-val for val in count.values()]
        heapq.heapify(heap)
        res = 0
        while heap:
            temp = []
            for _ in range(n + 1):
                if heap:
                    temp.append(heapq.heappop(heap))
            for val in temp:
                if val < -1:
                    heapq.heappush(heap, val + 1)
            res += n + 1 if heap else len(temp)
        return res

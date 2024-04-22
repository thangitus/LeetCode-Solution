from typing import List
from queue import Queue


class Solution:
    def openLock(self, deadends: List[str], target: str) -> int:
        visited = set()
        queue = Queue()
        deadends = set(deadends)
        queue.put("0000"), visited.add("0000")
        step = 0
        while not queue.empty():
            size = queue.qsize()
            for _ in range(size):
                cur = queue.get()
                if cur in deadends:
                    continue
                if cur == target:
                    return step
                for i in range(4):
                    for j in [-1, 1]:
                        next_str = cur[:i] + str((int(cur[i]) + j) % 10) + cur[i + 1:]
                        if next_str not in visited:
                            queue.put(next_str)
                            visited.add(next_str)
            step += 1
        return -1

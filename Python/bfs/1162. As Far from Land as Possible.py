from typing import List
from queue import Queue


class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        n, m = len(grid), len(grid[0])
        dx = [-1, 0, 0, 1]
        dy = [0, -1, 1, 0]
        res = -1
        queue = Queue()
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1: queue.put([i, j])
        if queue.queue == 0 or queue.qsize() == m * n: return -1

        while not queue.empty():
            res += 1
            for k in range(queue.qsize()):
                cur = queue.get()
                for l in range(4):
                    new_x, new_y = cur[0] + dx[l], cur[1] + dy[l]
                    if new_x < 0 or new_x >= n or new_y < 0 or new_y >= m: continue
                    if grid[new_x][new_y] == 0:
                        queue.put([new_x, new_y])
                        grid[new_x][new_y] = 1
        return res

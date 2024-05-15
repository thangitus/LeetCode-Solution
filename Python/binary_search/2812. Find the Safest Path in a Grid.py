import heapq
from queue import Queue
from typing import List


class Solution:
    dir = [(0, 1), (0, -1), (1, 0), (-1, 0)]

    def maximumSafenessFactor(self, grid: List[List[int]]) -> int:
        n = len(grid)
        queue = Queue()
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 1:
                    queue.put((i, j))
                    grid[i][j] = 0
                else:
                    grid[i][j] = -1

        while not queue.empty():
            size = queue.qsize()
            for _ in range(size):
                x, y = queue.get()
                for d in self.dir:
                    dx, dy = x + d[0], y + d[1]
                    val = grid[x][y]
                    if self.isValidCell(grid, dx, dy) and grid[dx][dy] == -1:
                        grid[dx][dy] = val + 1
                        queue.put((dx, dy))

        pq = [[-grid[0][0], 0, 0]]
        grid[0][0] = -1

        while pq:
            safeness, i, j = heapq.heappop(pq)

            if i == n - 1 and j == n - 1:
                return -safeness

            for d in self.dir:
                dx, dy = i + d[0], j + d[1]
                if self.isValidCell(grid, dx, dy) and grid[dx][dy] != -1:
                    heapq.heappush(pq, [-min(-safeness, grid[dx][dy]), dx, dy])
                    grid[dx][dy] = -1

        return -1

    def isValidCell(self, grid, i, j) -> bool:
        n = len(grid)
        return 0 <= i < n and 0 <= j < n

from typing import List


class Solution:
    def onesMinusZeros(self, grid: List[List[int]]) -> List[List[int]]:
        n, m = len(grid), len(grid[0])
        row, col = [0] * n, [0] * m
        for i in range(n):
            for j in range(m):
                row[i] += grid[i][j]
                col[j] += grid[i][j]
        return [[row[i] + col[j] - (n - row[i]) - (m - col[j]) for j in range(m)] for i in range(n)]

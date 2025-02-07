from typing import List


class Solution:
    @staticmethod
    def can_reach(grid: List[List[int]], time: int) -> bool:
        if grid[0][0] > time:
            return False
        n = len(grid)
        visited = [[False] * n for _ in range(n)]
        visited[0][0] = True
        stack = [(0, 0)]
        while stack:
            x, y = stack.pop()
            if x == n - 1 and y == n - 1:
                return True
            for dx, dy in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
                nx, ny = x + dx, y + dy
                if 0 <= nx < n and 0 <= ny < n and not visited[nx][ny] and grid[nx][ny] <= time:
                    visited[nx][ny] = True
                    stack.append((nx, ny))
        return False

    def swimInWater(self, grid: List[List[int]]) -> int:
        left, right = 0, max(max(row) for row in grid)
        while left < right:
            mid = (left + right) // 2
            if self.can_reach(grid, mid):
                right = mid
            else:
                left = mid + 1
        return left



from typing import List


class Solution:
    def checkValidGrid(self, grid: List[List[int]]) -> bool:
        cur, count, n, valid = [0, 0], 1, len(grid), True
        path = [[-2, -1], [-2, 1], [-1, 2], [1, 2], [2, 1], [2, -1], [1, -2], [-1, -2]]
        while count < n * n and valid:
            valid = False
            for p in path:
                new_x, new_y = cur[0] + p[0], cur[1] + p[1]
                if new_x < 0 or new_x >= n or new_y < 0 or new_y >= n: continue
                if grid[new_x][new_y] == count:
                    cur, valid = [new_x, new_y], True
                    count += 1
                    break
        return count == n * n

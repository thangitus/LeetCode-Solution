from typing import List


class Solution:
    def matrixScore(self, grid: List[List[int]]) -> int:
        for row in grid:
            # If the first element of the row is 0, then flip the row
            if row[0] == 0:
                for i in range(len(row)):
                    row[i] = 1 - row[i]
        for j in range(len(grid[0])):
            # Count the number of 1s in the j-th column
            count_ones = sum(grid[i][j] for i in range(len(grid)))
            # If the number of 1s is less than the number of 0s, flip the column
            if count_ones < len(grid) - count_ones:
                for i in range(len(grid)):
                    grid[i][j] = 1 - grid[i][j]

        score = 0
        for row in grid:
            score += int("".join(map(str, row)), 2)
        return score

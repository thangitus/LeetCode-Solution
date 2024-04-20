from typing import List


class Solution:
    def findFarmland(self, land: List[List[int]]) -> List[List[int]]:
        res = []
        for i in range(len(land)):
            for j in range(len(land[0])):
                if land[i][j] == 1:
                    top_left = [i, j]
                    bottom_right = [i, j]

                    queue = [[i, j]]
                    while queue:
                        x, y = queue.pop(0)
                        bottom_right = [max(bottom_right[0], x), max(bottom_right[1], y)]
                        land[x][y] = 0
                        if x + 1 < len(land) and land[x + 1][y] == 1:
                            land[x + 1][y] = 0
                            queue.append([x + 1, y])
                        if y + 1 < len(land[0]) and land[x][y + 1] == 1:
                            land[x][y + 1] = 0
                            queue.append([x, y + 1])

                    res.append([top_left[0], top_left[1], bottom_right[0], bottom_right[1]])

        return res

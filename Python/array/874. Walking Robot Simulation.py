from typing import List


class Solution:
    def robotSim(self, commands: List[int], obstacles: List[List[int]]) -> int:
        map, x, y, direction, res = {}, 0, 0, 0, 0
        for i, j in obstacles:
            map[(i, j)] = True
        for c in commands:
            if c == -1:
                direction = (direction + 1) % 4
            elif c == -2:
                direction = (direction - 1) % 4
            else:
                dx, dy = 0, 0
                if direction == 0:
                    dy = 1
                elif direction == 1:
                    dx = 1
                elif direction == 2:
                    dy = -1
                else:
                    dx = -1
                while c > 0 and (x + dx, y + dy) not in map:
                    x += dx
                    y += dy
                    c -= 1
            res = max(res, x * x + y * y)
        return res


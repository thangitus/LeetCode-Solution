from typing import List
from queue import Queue


class Solution:
    def snakesAndLadders(self, board: List[List[int]]) -> int:
        visited = {1}
        queue = Queue()
        n, res = len(board), 0
        queue.put(1)
        board.reverse()
        while not queue.empty():
            for k in range(queue.qsize()):
                cur = queue.get()
                if cur == n * n: return res
                for i in range(cur + 1, min(cur + 6, n * n) + 1):
                    x = (i - 1) // n
                    y = (i - 1) % n if x % 2 == 0 else -(i % n)
                    new = i if board[x][y] == -1 else board[x][y]
                    if new in visited: continue
                    queue.put(new)
                    visited.add(new)
            res += 1
        return -1

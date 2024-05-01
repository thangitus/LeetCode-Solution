from queue import Queue
from typing import List


class Solution:
    def validateBinaryTreeNodes(self, n: int, leftChild: List[int], rightChild: List[int]) -> bool:
        def find_root():
            children = set(leftChild + rightChild)
            for i in range(n):
                if i not in children:
                    return i
            return -1

        root = find_root()
        seen = {root}
        queue = Queue()
        queue.put(root)
        while not queue.empty():
            node = queue.get()
            for child in [leftChild[node], rightChild[node]]:
                if child == -1:
                    continue
                if child in seen:
                    return False
                seen.add(child)
                queue.put(child)
        return len(seen) == n

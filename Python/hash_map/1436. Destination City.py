from typing import List


class Solution:
    def destCity(self, paths: List[List[str]]) -> str:
        start = set()
        for path in paths:
            start.add(path[0])
        return [path[1] for path in paths if path[1] not in start][0]

from typing import List


class Solution:
    def queryResults(self, limit: int, queries: List[List[int]]) -> List[int]:
        res, color, count = [], {}, {}
        for query in queries:
            x, y = query[0], query[1]
            if x in color:
                count[color[x]] -= 1
                if count[color[x]] == 0:
                    count.pop(color[x])
            count.setdefault(y, 0)
            count[y] += 1
            color[x] = y
            res.append(len(count))

        return res

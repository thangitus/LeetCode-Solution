from typing import List


class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        n, result = len(isConnected), 0
        graph = [[] for _ in range(n)]
        visited = [False] * n

        def dfs(u: int):
            visited[u] = True
            for v in graph[u]:
                if not visited[v]: dfs(v)

        for i in range(n):
            for j in range(n):
                if isConnected[i][j]:
                    graph[i].append(j)
        for i in range(n):
            if not visited[i]:
                result += 1
                dfs(i)
        return result

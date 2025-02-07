from typing import List


class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        graph = {}
        for src, dst in tickets:
            graph.setdefault(src, [])
            graph[src].append(dst)
        for src in graph:
            graph[src].sort(reverse=True)
        stack = ['JFK']
        res = []
        while stack:
            while graph.get(stack[-1]):
                stack.append(graph[stack[-1]].pop())
            res.append(stack.pop())
        return res[::-1]

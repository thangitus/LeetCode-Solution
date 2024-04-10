from collections import deque
from typing import List


class Solution:
    def deckRevealedIncreasing(self, deck: List[int]) -> List[int]:
        queue = deque()
        for i in range(len(deck)):
            queue.append(i)
        res = [0] * len(deck)
        for card in sorted(deck):
            res[queue.popleft()] = card
            if queue:
                queue.append(queue.popleft())
        return res

from typing import List


class Solution:
    def minimumCardPickup(self, cards: List[int]) -> int:
        index, res = {}, 1e9
        for i in range(len(cards)):
            if cards[i] in index:
                res = min(res, i - index[cards[i]] + 1)
            index[cards[i]] = i
        return res if res != 1e9 else -1

from collections import Counter


class Solution:
    def minimumPushes(self, word: str) -> int:
        count, res = Counter(word).values(), 0
        count = sorted(count, reverse=True)
        for i in range(len(count)):
            factor = 1 + (i // 8)
            res += factor * count[i]
        return res



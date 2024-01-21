class Solution:
    def minimumPushes(self, word: str) -> int:
        res = 0
        for i in range(len(word)):
            if i <= 7:
                res += 1
            elif i <= 15:
                res += 2
            elif i <= 23:
                res += 3
            else:
                res += 4
        return res

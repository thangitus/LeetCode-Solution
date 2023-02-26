from typing import List


class Solution:
    def divisibilityArray(self, word: str, m: int) -> List[int]:
        mod, res = 0, []
        for c in word:
            mod = (mod * 10 + int(c)) % m
            res.append(1 if mod == 0 else 0)
        return res

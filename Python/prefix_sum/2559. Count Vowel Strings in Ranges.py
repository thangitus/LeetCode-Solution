from typing import List


class Solution:
    def vowelStrings(self, words: List[str], queries: List[List[int]]) -> List[int]:
        n = len(words)
        vowel = 'aeiou'
        prefix = [0] * (n + 1)
        res = []
        for i in range(len(words)):
            word = words[i]
            is_vowel = word[0] in vowel and word[-1] in vowel
            prefix[i + 1] = prefix[i] + is_vowel
        for l, r in queries:
            res.append(prefix[r + 1] - prefix[l])
        return res

class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        vowels = set('aeiou')
        res = cur = 0
        for i, c in enumerate(s):
            cur += c in vowels
            if i >= k:
                cur -= s[i - k] in vowels
            res = max(res, cur)
        return res

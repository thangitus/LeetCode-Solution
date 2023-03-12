from typing import List


class Solution:
    def vowelStrings(self, words: List[str], left: int, right: int) -> int:
        vowel, count = "aeiou", 0
        for word in words[left:right + 1]:
            count += 1 if word[0] in vowel and word[-1] in vowel else 0
        return count

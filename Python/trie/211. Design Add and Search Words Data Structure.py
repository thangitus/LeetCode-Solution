class WordDictionary:
    class TrieNode:
        def __init__(self):
            self.children = {}
            self.endOfWord = False

    def search_trie(self, cur, i, word):
        if i == len(word): return cur.endOfWord
        if word[i] != '.':
            if word[i] not in cur.children:
                return False
            return self.search_trie(cur.children[word[i]], i + 1, word)

        if word[i] == '.':
            for child in cur.children.values():
                if self.search_trie(child, i + 1, word): return True
        return False

    def __init__(self):
        self.root = self.TrieNode()

    def addWord(self, word: str) -> None:
        cur = self.root
        for c in word:
            if c not in cur.children:
                cur.children[c] = self.TrieNode()
            cur = cur.children[c]
        cur.endOfWord = True

    def search(self, word: str) -> bool:
        return self.search_trie(self.root, 0, word)

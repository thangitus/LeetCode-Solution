class WordDictionary:
    def __init__(self):
        self.root = {}

    def addWord(self, word: str) -> None:
        node = self.root
        for char in word:
            node = node.setdefault(char, {})
        node['$'] = True

    def search(self, word: str) -> bool:
        def dfs(node, i):
            if i == len(word): return '$' in node
            if word[i] == '.': return any(dfs(child, i + 1) for child in node.values() if isinstance(child, dict))
            return word[i] in node and dfs(node[word[i]], i + 1)

        return dfs(self.root, 0)

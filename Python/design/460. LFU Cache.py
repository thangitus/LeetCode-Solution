import collections


class Node:
    def __init__(self, key, val):
        self.key = key
        self.val = val
        self.freq = 1
        self.prev = self.next = None


class DLinkedList:
    def __init__(self):
        self.root = Node(None, None)  # dummy node
        self.root.next = self.root.prev = self.root
        self.size = 0

    def __len__(self):
        return self.size

    def append(self, new_node):
        head = self.root.next
        new_node.next = head
        new_node.prev = self.root
        head.prev = new_node
        self.root.next = new_node
        self.size += 1

    def pop(self, node=None):
        if self.size == 0:
            return

        if not node:
            node = self.root.prev

        node.prev.next = node.next
        node.next.prev = node.prev
        self.size -= 1

        return node


class LFUCache:
    def __init__(self, capacity):
        self.size = 0
        self.capacity = capacity

        self.node = dict()  # key: Node
        self.freq = collections.defaultdict(DLinkedList)
        self.min_freq = 0

    def _update(self, node):
        freq = node.freq

        self.freq[freq].pop(node)
        if self.min_freq == freq and not self.freq[freq]:
            self.min_freq += 1

        node.freq += 1
        freq = node.freq
        self.freq[freq].append(node)

    def get(self, key):
        if key not in self.node:
            return -1

        node = self.node[key]
        self._update(node)
        return node.val

    def put(self, key, value):
        if self.capacity == 0:
            return

        if key in self.node:
            node = self.node[key]
            self._update(node)
            node.val = value
        else:
            if self.size == self.capacity:
                node = self.freq[self.min_freq].pop()
                del self.node[node.key]
                self.size -= 1

            node = Node(key, value)
            self.node[key] = node
            self.freq[1].append(node)
            self.min_freq = 1
            self.size += 1


solution = LFUCache(10)
solution.put(1, 11)
solution.put(3, 33)
solution.put(2, 1)
solution.put(1, 11)

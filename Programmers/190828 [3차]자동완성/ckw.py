class Node(object):
    def __init__(self, key, data=None):
        self.key = key
        self.data = data
        self.cnt = 0
        self.children = {}


class Trie(object):
    def __init__(self):
        self.head = Node(None)

    def insert(self, string):
        curr_node = self.head

        for char in string:
            if char not in curr_node.children:
                curr_node.children[char] = Node(char)

            curr_node = curr_node.children[char]
            curr_node.cnt += 1

        curr_node.data = string

    def min_cnt(self, string):
        curr_node = self.head
        i = 0
        for char in string:
            i += 1

            if curr_node.cnt == 1:
               return i - 1

            curr_node = curr_node.children[char]

        return len(string)


def solution(words):

    cache = dict()
    cnt = 0

    trie = Trie()

    for w in words:
        trie.insert(w)

    for w in words:
        cnt += trie.min_cnt(w)

    return cnt


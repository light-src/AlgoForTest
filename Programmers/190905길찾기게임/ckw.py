import sys 

sys.setrecursionlimit(10**8)

class Node:

    def __init__(self, idx, y, x):
        self.idx = idx
        self.y = y
        self.x = x
        self.lc = None
        self.rc = None

    def has_left_child(self):
        return self.lc is not None

    def has_right_child(self):
        return self.rc is not None

    def insert(self, node):
        if node.x < self.x:
            if self.has_left_child():
                self.lc.insert(node)
                return

            self.lc = node

        else:
            if self.has_right_child():
                self.rc.insert(node)
                return

            self.rc = node

    def preorder(self) -> list:
        pre = list()
        pre.append(self.idx + 1)

        if self.lc is not None:
            pre += self.lc.preorder()

        if self.rc is not None:
            pre += self.rc.preorder()

        return pre

    def postorder(self):
        post = list()

        if self.lc is not None:
            post += self.lc.postorder()

        if self.rc is not None:
            post += self.rc.postorder()

        post.append(self.idx + 1)

        return post


def solution(nodeinfo):

    nodes = [Node(i, nodeinfo[i][1], nodeinfo[i][0]) for i in range(len(nodeinfo))]

    nodes.sort(key=lambda node: (-node.y, node.x))
    root = nodes[0]

    for i in range(1, len(nodes)):
        root.insert(nodes[i])

    answer = [root.preorder(), root.postorder()]

    return answer



# kakao_find_path_game
import sys
sys.setrecursionlimit(10**6)
pre, post = [], []
class Node:
    def __init__(self, data):
        self.x = data[0]
        self.y = data[1]
        self.id = data[2]
        self.lc = 0
        self.rc = 0


def makeTree(parent, child):
    if child.x < parent.x:
        if parent.lc == 0:
            parent.lc = child
        else:
            makeTree(parent.lc, child)
    else:
        if parent.rc == 0:
            parent.rc = child
        else:
            makeTree(parent.rc, child)


def preorder(node):
    global pre
    pre.append(node.id)
    if node.lc != 0:
        preorder(node.lc)
    if node.rc != 0:
        preorder(node.rc)


def postorder(node):
    global post
    if node.lc != 0:
        postorder(node.lc)
    if node.rc != 0:
        postorder(node.rc)
    post.append(node.id)



def solution(nodeinfo):
    for i, val in enumerate(nodeinfo):
        val.append(i+1)

    nodeinfo.sort()
    nodeinfo.sort(key=lambda nodeinfo: nodeinfo[1], reverse=True)
    root = Node(nodeinfo[0])
    for co in nodeinfo:
        if co == nodeinfo[0]:
            continue
        child = Node(co)
        makeTree(root, child)

    preorder(root)
    postorder(root)
    
    return [pre, post]


nodeinfo = [[5, 3], [11, 5], [13, 3], [3, 5],
            [6, 1], [1, 3], [8, 6], [7, 2], [2, 2]]
print(solution(nodeinfo))

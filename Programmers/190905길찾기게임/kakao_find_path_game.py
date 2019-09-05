# kakao_find_path_game
import sys
sys.setrecursionlimit(10**6)
pre, post = [], []
class Node:
    def __init__(self, data):
        self.x = data[0]
        self.y = data[1]
        self.id = data[2]
        self.lc = None
        self.rc = None


def makeTree(parent, child):
    if child.x < parent.x:
        if not parent.lc:
            parent.lc = child
        else:
            makeTree(parent.lc, child)
    else:
        if not parent.rc:
            parent.rc = child
        else:
            makeTree(parent.rc, child)


def preorder(node):
    global pre
    pre.append(node.id)
    if node.lc:
        preorder(node.lc)
    if node.rc:
        preorder(node.rc)


def postorder(node):
    global post
    if node.lc:
        postorder(node.lc)
    if node.rc:
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

# kakao_sorting_file_name


class Node():
    def __init__(self):
        self.next = dict()
        self.same = 0


def solution(words):
    node, answer = Node(), 0
    for word in words:
        search = node
        for i, w in enumerate(word):
            if w not in search.next:
                search.next[w] = Node()
            search.same += 1
            search = search.next[w]
            if i == len(word)-1:
                search.same += 1
    for word in words:
        count, search = 1, node
        for i, w in enumerate(word):
            if search.next[w].same == 1:
                answer += count
                break
            elif i == len(word)-1:
                answer += count
            else:
                count += 1
                search = search.next[w]
    return answer


if __name__ == "__main__":
    # words = ["go", "gone", "guild"]
    # words = ["abc", "def", "ghi", "jklm"]
    words = ["word", "war", "warrior", "world"]
    print(solution(words))

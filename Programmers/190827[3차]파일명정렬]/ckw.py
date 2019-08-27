import re
from functools import total_ordering

@total_ordering
class FileName:

    def __init__(self, head: str, number: str, tail: str):
        self.head = head
        self.number = int(number)
        self.number_str = number
        self.tail = tail if tail is not None else ""

    def __lt__(self, other):
        if other.head.lower() != self.head.lower():
            return other.head.lower() > self.head.lower()

        if other.number != self.number:
            return other.number > self.number

        return False


def divide_word(word):

    p = re.compile(r'(?<=\D)\d+')
    number = p.search(word).group()
    p = re.compile(r'\D+(?=\d)')
    head = p.search(word).group()
    p = re.compile(r'(?<=\d)\D+.+')
    tail = p.search(word).group() if p.search(word) is not None else None

    return head, number, tail


def solution(files):
    answer = []
    for f in files:
        h, n, t = divide_word(f)
        answer.append(FileName(h, n, t))

    answer.sort()
    answer = [a.head + a.number_str + a.tail for a in answer]

    return answer

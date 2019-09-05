import re

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
    
FILE_REGEX = r'^([^0-9]+)([0-9]+)(.*)'
def solution(files):
    answer = []
    file_regex = re.compile(FILE_REGEX)
    for f in files:
        matches = file_regex.match(f)
        h, n, t = matches.group(1), matches.group(2), matches.group(3)
        print(h, n, t)
        answer.append(FileName(h, n, t))

    answer.sort()
    answer = [a.head + a.number_str + a.tail for a in answer]

    return answer

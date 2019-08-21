def get_intersection_num(list1, list2):

    intersection = 0

    equal = [False] * len(list2)

    for w1 in list1:
        for i in range(0, len(list2)):
            if w1 == list2[i] and not equal[i]:
                equal[i] = True
                intersection += 1
                break

    return intersection


def make_list(str):
    return [
        (str[i] + str[i+1]).lower()
        for i in range(0, len(str) - 1)
        if ('a' <= str[i] <= 'z' or 'A' <= str[i] <= 'Z') and
           ('a' <= str[i + 1] <= 'z' or 'A' <= str[i + 1] <= 'Z')
        ]


def solution(str1, str2):
    list1 = make_list(str1)
    list2 = make_list(str2)

    intersection = get_intersection_num(list1, list2)
    union = len(list1) + len(list2) - intersection

    if union == 0 : return 65536
    
    ans = intersection / union * 65536
    return int(ans)



// 제일 좋은 코드 (아마?)

def get_intersection_num(list1, list2):

    intersection = set(list1) & set(list2)
    union = set(list1) | set(list2)

    intersection_len = sum([min(list1.count(e), list2.count(e)) for e in intersection])
    union_len = sum([max(list1.count(e), list2.count(e)) for e in union])

    return intersection_len, union_len


def make_list(str):
    return [
        (str[i:i+2]).lower()
        for i in range(0, len(str) - 1)
        if str[i:i+2].isalpha()
    ]


def solution(str1, str2):
    list1 = make_list(str1)
    list2 = make_list(str2)

    intersection, union = get_intersection_num(list1, list2)

    if union == 0:
        return 65536

    ans = intersection / union * 65536
    return int(ans)

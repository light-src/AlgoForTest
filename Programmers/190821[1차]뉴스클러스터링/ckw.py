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

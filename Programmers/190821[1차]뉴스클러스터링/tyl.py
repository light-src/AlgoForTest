def makeList(s):
    ret = []
    sub = ''
    for i in range(len(s)-1):
        sub = s[i] + s[i+1]
        if sub.isalpha():
            ret.append(sub)
        sub = ''
    return ret

def check_dup(l1, l2):
    inter = set(l1) & set(l2)
    union = set(l1) | set(l2)
    inter_len, union_len = 0,0
    for element in inter:
        inter_len += min(l1.count(element), l2.count(element))
    for element in union:
        union_len += max(l1.count(element), l2.count(element))
        
    return inter_len, union_len


def solution(str1, str2):
    list1 = makeList(str1.upper())
    list2 = makeList(str2.upper())

    inter, union = check_dup(list1, list2)
    if inter == 0 and union == 0 :
        return 65536
    return int(inter/union * 65536)


if __name__ == "__main__":
    str1, str2 = 'aa1+aa2', 'AAAA12'
    print(solution(str1, str2))

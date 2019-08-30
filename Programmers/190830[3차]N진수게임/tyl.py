# kakao_nbase_game programmers base change
tot_len = 0
def convert(n,b):
    global tot_len
    ret = []
    if n==0 : 
        tot_len += 1; return [0]
    while n:
        push = n%b
        if push == 10 : push = 'A'
        elif push == 11: push = 'B'
        elif push == 12: push = 'C'
        elif push == 13: push = 'D'
        elif push == 14: push = 'E'
        elif push == 15: push = 'F'        
        ret.append(push)
        n = n//b
    tot_len += len(ret)    
    return ret[::-1]

def solution(n, t, m, p):
    nums, i, answer = [], 0, ''
    
    while tot_len < t*(m+1):
        nums += convert(i,n)
        i += 1     
            
    for i in range(t):        
        answer += str(nums[p-1 + m*i])
    return answer

if __name__ == "__main__":
    n,t,m,p = 16,16,2,2
    print(solution(n,t,m,p))

# kakao_zip string trim

def solution(msg):
    dic,answer = list('0ABCDEFGHIJKLMNOPQRSTUVWXYZ'),[]
    
    while msg:
        out = False
        for i in range(len(msg)-1,-1,-1):
            for j in range(len(dic)-1,-1,-1):
                if dic[j] == msg[:i+1]:
                    dic.append(msg[:i+2])
                    msg = msg[i+1:]
                    answer.append(j)
                    out = True
                    break
            if out : break
            
    return answer
    
if __name__ == "__main__":
    msg = 'ABABABABABABABAB'    
    print(solution(msg

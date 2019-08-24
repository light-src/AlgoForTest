# kakao_that_song
from functools import cmp_to_key

def compare(x,y):
    if x[0] < y[0] : return 1
    elif x[0] > y[0] : return -1
    else:
        if x[1] < y[1] : return -1
        elif x[1] > y[1] : return 1
        else: return 0

def change_shap(check):
    notes = ''
    for i in range(len(check)-1):
        if check[i] == '#' : continue
        if check[i+1] == '#' : notes += check[i].lower(); continue
        notes += check[i]
    if check[-1] != '#': notes += check[-1]
    return notes

def solution(m, musicinfos):
    musics, answers = [], []
    m = change_shap(list(m))
    for i, music in enumerate(musicinfos):
        start, end, notes = music[0:5], music[6:11], music[12:]
        name, notes = notes.split(',')
        start = int(start[0:2])*60 + int(start[3:])
        end = int(end[0:2])*60 + int(end[3:])
        notes = change_shap(list(notes))        

        tmp = notes        
        notes = ''
        for i in range(end-start):
            notes += tmp[i%len(tmp)]            
        musics.append([end-start, i, name, notes])
    
    for music in musics:
        if music[3].find(m) != -1:
            answers.append(music)        
    if answers == []:
        return '(None)'
    answers = sorted(answers, key=cmp_to_key(compare))
    return answers[0][2]
    
if __name__ == "__main__":
    m,musicinfos = 	"ABC", ["12:00,12:14,HELLO,C#DEFGAB", "13:00,13:05,WORLD,ABCDEF"]
    print(solution(m,musicinfos))

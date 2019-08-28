#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<string> words) {
    int cache[100001]; //몇개까지 똑같다
    int answer = 0;
    for(int i = 0; i < words.size(); ++i)
        cache[i] = 1; //최소 1글자는 쳐야함
    sort(words.begin(), words.end());
    //단어 하나당 입력이 겹치는 것을 찾음
    //그 이후의 것은 그 이상이 필요함으로 그 다음것부터 찾음(DP)
    for(int front = 0; front < words.size(); ++front) {
        for(int tail = front + 1; tail < words.size(); ++tail) {
            int idx; //비교하는 문자열 수
            for(idx = 1; idx <= words[front].size(); ++idx) { //다른게 나올때까지 검사함
                if(words[front].compare(0, idx, words[tail], 0, idx))
                    break;
            }
            if(idx > cache[tail]) //캐싱
                cache[tail] = idx;
            if(idx <= cache[front]) //더이상 해도 의미없음(소팅했기때문에)
                break;
            if(idx > words[front].size()) //compare for문 다돌았을경우 == 자기 자신을 다 쳐야하는 경우, 카운팅 1 더되어서 줄여줌
                idx = (int)words[front].size();
            cache[front] = max(cache[front], idx);
        }
        answer += cache[front];
    }
    return answer;
}

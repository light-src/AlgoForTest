//kimdongsu 190827

#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<int> headTail;
    vector<int> numSizeStock;
    for(int n = 0; n < files.size(); ++n) {
        //head cut
        string headSubString;
        for(int i = 0; i < files[n].size(); ++i) {
            if('0' <= files[n][i] && files[n][i] <= '9')
                break;
            else {
                if(files[n][i] >= 'a')
                    headSubString += files[n][i] - 32;
                else headSubString += files[n][i];
            }
        }
        //number cut
        int numSize = 0;
        for(int i = headSubString.size(); i < files[n].size(); ++i) {
            if('0' <= files[n][i] && files[n][i] <= '9')
                ++numSize;
            else
                break;
        }
        
        //위치 찾음
        int idx = 0; //넣어야할 자리
        for(idx = 0; idx < answer.size(); ++idx) {
            //head기준 위치 찾음
            string answerSubString = answer[idx].substr(0, headTail[idx]);
            for(int i = 0; i < answerSubString.size(); ++i)
                answerSubString[i] = toupper(answerSubString[i]);
            int comp = headSubString.compare(answerSubString);
            if(comp == 0) {//같을때
                //number기준 위치 찾음
                if(stoi(files[n].substr((int)headSubString.size(), numSize)) < stoi(answer[idx].substr(headTail[idx], numSizeStock[idx])) )
                    break;
            }
            else if(comp < 0) { //작을때
                break;
            }
        }
        answer.insert(answer.begin() + idx, files[n]);
        headTail.insert(headTail.begin() + idx, headSubString.size());
        numSizeStock.insert(numSizeStock.begin() + idx, numSize);
    }
    return answer;
}

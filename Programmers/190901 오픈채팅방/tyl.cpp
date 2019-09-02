#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map <string, string> m;
vector<pair<char,string>> event;
    for (int i = 0; i < record.size(); i++) {
		char buf[100];
		strcpy(buf, record[i].c_str());
		char slice[3][11];
		char* tok = strtok(buf, " "); int t = 0;
		while (tok != NULL) {
			strcpy(slice[t++], tok);
			tok = strtok(NULL, " ");
		}
	
		if (slice[0][0] == 'E') {
			event.push_back({ 'e',slice[1] });
			m[slice[1]] = slice[2];
		}
		else if (slice[0][0] == 'L') {			
			event.push_back({ 'l',slice[1] });
		}
		else if (slice[0][0] == 'C') {
			m[slice[1]] = slice[2];
		}
	}
	for (int i = 0; i < event.size(); i++) {
		string s = "";
		if (event[i].first == 'e') 
			s += m[event[i].second] + "님이 들어왔습니다.";
		
		else if (event[i].first == 'l')
			s += m[event[i].second] + "님이 나갔습니다.";

		answer.push_back(s);
	}
    
    return answer;
}

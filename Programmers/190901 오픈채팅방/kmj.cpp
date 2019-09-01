#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <utility>

using namespace std;

vector<string> solution(vector<string> record) {
	vector<string> answer;
	vector<pair<string, string>> answerarr;
	map<string, string> M;

	int i, j;

	for (i = 0; i < record.size(); i++) {
		vector<string> splitarr;
		int index = 0;

		for (j = 0; j < record[i].size(); j++) {
			if (record[i].substr(j, 1) == " ") {
				splitarr.push_back(record[i].substr(index, j - index));
				index = j + 1;
			}
		}
		splitarr.push_back(record[i].substr(index, j - index));
		if (splitarr[0].compare("Enter") == 0) {
			M[splitarr[1]] = splitarr[2];
			answerarr.push_back(make_pair(splitarr[0], splitarr[1]));
		}
		else if (splitarr[0].compare("Leave") == 0) {
			answerarr.push_back(make_pair(splitarr[0], splitarr[1]));
		}
		else 
			M[splitarr[1]] = splitarr[2];	
	}
	
	for (i = 0; i < answerarr.size(); i++) {
		if (answerarr[i].first.compare("Enter") == 0) 
			answer.push_back(M[answerarr[i].second] + "님이 들어왔습니다.");
		else if (answerarr[i].first.compare("Leave") == 0) 
			answer.push_back(M[answerarr[i].second] + "님이 나갔습니다.");

	}
	return answer;
}

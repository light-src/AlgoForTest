#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
vector<string> alphabet;

int find(string str)
{
	for (int i = 0; i < alphabet.size(); i++) {
		if (alphabet[i].compare(str) == 0) {
			return i + 1;
		}
	}
	return -1;
}
vector<int> solution(string msg) {
	vector<int> answer;
	int i, j, max_cnt = 1, pos;
	
	for (i = 0; i < 26; i++) {
		char c = 'A' + i;
		string temp(1, c);
		alphabet.push_back(temp);
	}

	for (i = 0; i < msg.size();) {
		string temp;
		for (j = max_cnt; j >= 1; j--) {
			temp = msg.substr(i, j);
			pos = find(temp);
			if (pos != -1) {
				answer.push_back(pos);
				break;
			}
		}
		i += j;
		if (i >= msg.size())
			break;
		temp += msg[i];
		if (find(temp) == -1)
			alphabet.push_back(temp);
		if (temp.size() > max_cnt)
			max_cnt = temp.size();
	}
	return answer;
}

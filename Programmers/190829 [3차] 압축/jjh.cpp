#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> solution(string);

int main(void) {
	string msg = "ABABABABABABABAB";
	vector<int> answer = solution(msg);

	for (int i = 0; i < (int)answer.size(); i++)
		cout << answer[i] << " ";
	cout << endl;

	system("pause");
	return 0;
}

vector<int> solution(string msg) {
	vector<int> answer;
	vector<string> code = {
		"", "A", "B", "C", "D",
		"E", "F", "G", "H", "I",
		"J", "K", "L", "M", "N",
		"O", "P", "Q", "R", "S",
		"T", "U", "V", "W", "X",
		"Y", "Z"
	};
	int idx = 0, maxLen = 1, i;
	bool found = false;

	while (idx < msg.length()) {
		if (idx == 0) {
			for (i = 0; i < code.size(); i++) {
				if (code[i].compare(msg.substr(idx, 1)) == 0) {
					answer.push_back(i);
					break;
				}
			}
			maxLen++;
			code.push_back(msg.substr(idx, maxLen));
			idx += maxLen - 1;
		}
		else {
			for (int len = maxLen; len >= 0; len--) {
				found = false;
				for (i = 0; i < code.size(); i++) {
					if (code[i].compare(msg.substr(idx, len)) == 0) {
						found = true;
						break;
					}
				}
				if (!found) {
					continue;
				}
				else {
					answer.push_back(i);
					len++;
					code.push_back(msg.substr(idx, len));
					idx += len - 1;
					maxLen = maxLen > len ? maxLen : len;
					break;
				}
			}
		}
	}

	return answer;
}

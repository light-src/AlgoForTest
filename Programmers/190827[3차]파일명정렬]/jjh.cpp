#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string>);

struct fileInfo {
	string head = "";
	int num;

	void parse(string fileName) {
		int i = 0, j;
		for (i = 0; i < fileName.length(); i++) {
			if (isdigit(fileName[i]))
				break;
			if (fileName[i] >= 'A' && fileName[i] <= 'Z')
				head += fileName[i] - ('A' - 'a');
			else head += fileName[i];
		}
		j = i + 5;
		string temp = "";
		for (i; i < fileName.length(); i++) {
			if (i >= j) break;
			if (isdigit(fileName[i]))
				temp += fileName[i];
			else break;
		}
		num = stoi(temp);
	}
};

int main(void) {
	vector<string> files = {
		"aa11.",
		"aA11.",
		"Aa11.",
		"AA11."
	};
	vector<string> answer = solution(files);

	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << endl;

	system("pause");
	return 0;
}

vector<string> solution(vector<string> files) {
	vector<string> answer;
	vector<fileInfo> ary;
	vector<int> order;

	for (int i = 0; i < files.size(); i++) {
		fileInfo temp;
		temp.parse(files[i]);
		ary.push_back(temp);
		order.push_back(0);
	}

	for (int i = 0; i < ary.size(); i++) {
		for (int j = 0; j < ary.size(); j++) {
			if (i == j) continue;
			if (ary[i].head.compare(ary[j].head) > 0) {
				order[i]++;
				continue;
			}
			if (ary[i].head.compare(ary[j].head) == 0 && ary[i].num > ary[j].num) {
				order[i]++;
				continue;
			}
			if (ary[i].head.compare(ary[j].head) == 0 && ary[i].num == ary[j].num) {
				if (i > j)
					order[i]++;
			}
		}
	}

	for (int i = 0; i < ary.size(); i++) {
		for (int j = 0; j < order.size(); j++) {
			if (order[j] == i)
				answer.push_back(files[j]);
		}
	}

	return answer;
}

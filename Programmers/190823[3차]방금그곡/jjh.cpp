#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct music {
	int time;
	string name = "";
	string code = "";
	string extCode = "";

	void parseInfo(string info) {
		int i;
		long hour, min, start, end;

		hour = stol(info.substr(0, 2));
		min = stol(info.substr(3, 2));

		start = hour * 60 + min;

		hour = stol(info.substr(6, 2));
		min = stol(info.substr(9, 2));

		end = hour * 60 + min;

		time = end - start;

		for (i = 12; i < info.length(); i++) {
			if (info.at(i) == ',')
				break;
			name += info.at(i);
		}
		i++;
		for (i; i < info.length(); i++) {
			if (i + 1 < info.length() && info.at(i + 1) == '#') {
				code += info.at(i) - ('A' - 'a');
				i++;
			}
			else {
				code += info.at(i);
			}
		}

		for (i = 0; i < time; i++) {
			extCode += code[i % code.size()];
		}
	}
};

string solution(string, vector<string>);

int main(void) {
	string m = "CC#BCC#BCC#BCC#B";
	vector<string> musicinfos = {
		"03:00,03:30,FOO,CC#B",
		"04:00,04:08,BAR,CC#BCC#BCC#B"
	};
	
	string answer = solution(m, musicinfos);
	cout << answer << endl;

	system("pause");
	return 0;
}

string solution(string m, vector<string> musicinfos) {
	string answer = "";
	string newM = "";
	int n, maxTime = 0;
	vector<music> ary;
	int len = musicinfos.size();

	for (int i = 0; i < m.length(); i++) {
		if (i + 1 < m.length() && m.at(i + 1) == '#') {
			newM += m[i] - ('A' - 'a');
			i++;
		}
		else {
			newM += m[i];
		}
	}

	for (int i = 0; i < len; i++) {
		music temp;
		temp.parseInfo(musicinfos[i]);
		ary.push_back(temp);
	}

	for (int i = 0; i < ary.size(); i++) {
		if ((n = ary[i].extCode.find(newM)) == std::string::npos) {
			ary.erase(ary.begin() + i);
			i--;
		}
	}

	if (ary.size() == 0)
		return "`(None)`";

	if (ary.size() == 1)
		return ary[0].name;

	for (int i = 0; i < ary.size(); i++) {
		if (ary[i].time > maxTime) {
			maxTime = ary[i].time;
			answer = ary[i].name;
		}
	}

	return answer;
}

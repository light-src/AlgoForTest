#include <iostream>
#include <vector>
#include <string>

using namespace std;

int solution(vector<string>);

struct traffic {
	long start, end;

	void parse(string line) {
		long h, m, s, ss;
		double time;

		h = stol(line.substr(11, 2));
		m = stol(line.substr(14, 2));
		s = stol(line.substr(17, 2));
		ss = stol(line.substr(20, 3));

		end = (((h * 60) + m) * 60 + s) * 1000 + ss;

		time = stod(line.substr(24, line.size() - 25)) * 1000;
		start = end - time + 1;
	}
};

int main(void) {
	vector<string> lines = {
		"2016-09-15 23:59:57.421 0.351s",
		"2016-09-15 23:59:58.233 1.181s",
		"2016-09-15 23:59:58.299 0.8s",
		"2016-09-15 23:59:58.688 1.041s",
		"2016-09-15 23:59:59.591 1.412s",
	};
	int answer = solution(lines);

	cout << answer << endl;

	system("pause");
	return 0;
}

int solution(vector<string> lines) {
	int answer = 0;
	vector<traffic> ary;

	for (int i = 0; i < lines.size(); i++) {
		traffic temp;
		temp.parse(lines[i]);
		ary.push_back(temp);
	}

	for (int i = 0; i < ary.size(); i++) {
		int max = 1;
		int cur = ary[i].start;
		for (int j = 0; j < ary.size(); j++) {
			if (i == j) continue;
			if ((cur <= ary[j].start  && cur + 999 >= ary[j].start) || (cur + 999 >= ary[j].end && cur <= ary[j].end) || (cur >= ary[j].start && cur + 999 <= ary[j].end))
				max++;
		}
		if (max > answer)
			answer = max;

		max = 1;
		cur = ary[i].start;
		for (int j = 0; j < ary.size(); j++) {
			if (i == j) continue;
			if ((cur >= ary[j].start  && cur - 999 <= ary[j].start) || (cur - 999 <= ary[j].end && cur >= ary[j].end) || (cur <= ary[j].start && cur - 999 >= ary[j].end))
				max++;
		}
		if (max > answer)
			answer = max;

		max = 1;
		cur = ary[i].end;
		for (int j = 0; j < ary.size(); j++) {
			if (i == j) continue;
			if ((cur <= ary[j].start  && cur + 999 >= ary[j].start) || (cur + 999 >= ary[j].end && cur <= ary[j].end) || (cur >= ary[j].start && cur + 999 <= ary[j].end))
				max++;
		}
		if (max > answer)
			answer = max;

		max = 1;
		cur = ary[i].end;
		for (int j = 0; j < ary.size(); j++) {
			if (i == j) continue;
			if ((cur >= ary[j].start  && cur - 999 <= ary[j].start) || (cur - 999 <= ary[j].end && cur >= ary[j].end) || (cur <= ary[j].start && cur - 999 >= ary[j].end))
				max++;
		}
		if (max > answer)
			answer = max;
	}

	return answer;
}

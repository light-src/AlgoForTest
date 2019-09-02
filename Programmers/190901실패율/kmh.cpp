#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>

using namespace std;

bool compare(const pair<float, int> &a, pair<float, int> &b)
{
	if (a.first == b.first)
		return a.second < b.second;
	else
		return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	vector<pair<float, int>> answerarr;
	int i, stage[501];
	int people = stages.size(), index = 1, cnt;

	for (i = 1; i <= N; i++)
		stage[i] = 0;
	sort(stages.begin(), stages.end());
	for (i = 0; i < stages.size(); i++)
		stage[stages[i]]++;

	for (i = 1; i <= N; i++) {
		if (stage[i] == 0)
			answerarr.push_back(make_pair(0, i));
		else {
			answerarr.push_back(make_pair((float)stage[i] / people, i));
			people -= stage[i];
		}
	}
	sort(answerarr.begin(), answerarr.end(), compare);
	for (i = 0; i < answerarr.size(); i++)
		answer.push_back(answerarr[i].second);
	return answer;
}

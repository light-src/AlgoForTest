#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int row, col;
vector<bool> key;
vector<vector<int>> key_set;

bool compare(const vector<int> a, vector<int> b)
{
	return a.size() < b.size();
}

bool compare2(const string &a, const string &b)
{
	return a.compare(b) < 0;
}

void DFS(int index, vector<int> key_comb)
{
	key_set.push_back(key_comb);
	if (index == col)
		return;

	for (int i = index; i < col; i++) {
		key_comb.push_back(i);
		DFS(i + 1, key_comb);
		key_comb.erase(key_comb.end() - 1);
	}
}

int solution(vector<vector<string>> relation) {
	int i, j, k, check, check2, answer = 0;
	vector<int> key_comb;
	vector<bool> valid;
	vector<vector<int>> result_key;
	
	//초기작업
	row = relation.size();
	col = relation[0].size();
	for (i = 0; i < col; i++) {
		key.push_back(false);
		valid.push_back(false);
	}

	//키조합 생성
	for (i = 0; i < col; i++) {
		key_comb.push_back(i);
		DFS(i + 1, key_comb);
		key_comb.erase(key_comb.begin());
	}

	sort(key_set.begin(), key_set.end(), compare);

	for (i = 0; i < key_set.size(); i++) {
		check = 0;
		vector<string> comb;

		for (j = 0; j < result_key.size(); j++) {
			if (includes(key_set[i].begin(), key_set[i].end(), result_key[j].begin(), result_key[j].end())) {
				check = 1;
				break;
			}
		}
		if (check == 1)
			continue;

		for (j = 0; j < row; j++) {
			string tempcomb = "";
			for (k = 0; k < key_set[i].size(); k++)
				tempcomb += relation[j][key_set[i][k]];
			comb.push_back(tempcomb);
		}
		sort(comb.begin(), comb.end(), compare2);
		if (unique(comb.begin(), comb.end()) == comb.end()) {
			answer++;
			result_key.push_back(key_set[i]);
		}
 	}
	return answer;
}

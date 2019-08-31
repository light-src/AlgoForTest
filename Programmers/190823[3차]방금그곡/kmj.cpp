#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <utility>

using namespace std;

string change(string str)
{
	string answer;
	for (int i = 0; i < str.size(); i++) {
		if (i + 1 < str.size() && str.substr(i + 1, 1) == "#") {
			answer += (str[i] + 10);
			i++;
		}
		else
			answer += str[i];
	}
	return answer;
}

bool compare(const pair<int, string> &a, const pair<int, string> &b)
{
	return a.first > b.first;
}

string solution(string m, vector<string> musicinfos) {
	string answer = "";
	vector<pair<int, string>> answerarr;
	int i, j, total;

	for (i = 0; i < musicinfos.size(); i++) {
		total = stoi(musicinfos[i].substr(6, 2)) * 60 + stoi(musicinfos[i].substr(9, 2)) - (stoi(musicinfos[i].substr(0, 2)) * 60 + stoi(musicinfos[i].substr(3, 2)));
		string title, akbo, allakbo = "";
		for (j = 12; j < musicinfos[i].size(); j++) {
			if (musicinfos[i].substr(j, 1) == ",") {
				title = musicinfos[i].substr(12, j - 12);
				akbo = musicinfos[i].substr(j + 1, musicinfos[i].size() - j);
			}
		}
		akbo = change(akbo);
		m = change(m);
		for (j = 0; j < total; j++) 
			allakbo += akbo[j % akbo.size()];

		if (allakbo.find(m) != string::npos) {
			answerarr.push_back(make_pair(total, title));
		}
	}
    if(answerarr.size() == 0)
        return "(None)";
    else {
	    sort(answerarr.begin(), answerarr.end(), compare);
	    return answerarr[0].second;
    }
}

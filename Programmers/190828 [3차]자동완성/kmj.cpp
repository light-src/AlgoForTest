#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <cstring> //memset을 쓰기위함
using namespace std;

typedef struct tree {
	char alphabet;
	tree* next[26];
	int level;
	int cnt;

	tree(char key, int lev) {
		alphabet = key;
		memset(next, 0, sizeof(next));
		level = lev;
		cnt = 1;
	}

	tree* insert(char key, int lev) {
		int pos = key - 'a';
		if (next[pos] == NULL)
			next[pos] = new tree(key, lev);
		else
			next[pos]->cnt++;
		return next[pos];
	}
};

tree* start = new tree(' ', 0);

int solution(vector<string> words) {
	int i, j, answer = 0;
	tree* temp;

    //한글자씩 기준으로 트리를 만듬
	for (i = 0; i < words.size(); i++) {
		temp = start;
		for (j = 0; j < words[i].size(); j++) 
			temp = temp->insert(words[i][j], j);
	} 

    //단어를 트리를 통해 검색함. 만약 해당하는 값이 cnt == 1이면 더이상 입력하지 않아도됨. 예외처리는 단어 마지막까지 검색햇는데 cnt != 1이면 전부더하도록 함.
	for (i = 0; i < words.size(); i++) {
		temp = start;
		for (j = 0; j < words[i].size(); j++) {
			temp = temp->next[words[i][j] - 'a'];
			if (temp->cnt == 1) {
				answer += j + 1;
				break;
			}
			else if (j + 1 == words[i].size() & temp->cnt != 1)
				answer += j + 1;
		}
	}

	return answer;
}

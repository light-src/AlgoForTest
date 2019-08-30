#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
using namespace std;

typedef struct file {
	string head;
	string number;
	string tail;
	int inorder;
}file;

bool compare(const file &a, const file &b)
{
	string zero = "0", tempa = "", tempb = "", lowera = "", lowerb="";
	int i;
	
	for (i = 0; i < a.head.size(); i++) {
		lowera += " ";
		lowera[i] = tolower(a.head[i]);
	}
	for (i = 0; i < b.head.size(); i++) {
		lowerb += " ";
		lowerb[i] = tolower(b.head[i]);
	}
	if (lowera.compare(lowerb) < 0)
		return true;
	else if (lowera.compare(lowerb) == 0) {
		for (i = 0; i < 5 - a.number.size(); i++)
			tempa += zero;
		for (i = 0; i < 5 - b.number.size(); i++)
			tempb += zero;
		tempa += a.number;
		tempb += b.number;
		if (tempa.compare(tempb) == 0) {
			return a.inorder < b.inorder;
		}
		else
			return tempa.compare(tempb) < 0;
	}
	else
		return false;
}

vector<string> solution(vector<string> files)
{
	vector<string> answer;
	vector<file> file_arr;
	int i, j, k;

	for (i = 0; i < files.size(); i++) {
		file temp_f;
		for (j = 0; j < files.size(); j++) 
			if (48 <= files[i][j] && files[i][j] <= 57)
				break;
		temp_f.head = files[i].substr(0, j);
		for (k = j; k < j + 5; k++) 
			if (files[i][k] < 48 || files[i][j] > 57)
				break;
		temp_f.number = files[i].substr(j, k - j);
		temp_f.tail = files[i].substr(k, files[i].size() - k);
		temp_f.inorder = i;
		file_arr.push_back(temp_f);
	}

	sort(file_arr.begin(), file_arr.end(), compare);

	for (i = 0; i < file_arr.size(); i++)
		answer.push_back(file_arr[i].head + file_arr[i].number + file_arr[i].tail);
	return answer;
}

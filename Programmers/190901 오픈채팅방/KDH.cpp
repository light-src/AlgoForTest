#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

enum eRecord {
	operation = 0,
	uid = 1,
	name =2,
};

map<string, string> g_table;
vector<string> g_uid;
vector<string> g_operation;

vector<string> split(string str, char delimeter) {
	vector<string> internal;
	stringstream ss(str);
	string temp;
	while (getline(ss, temp, delimeter))
		internal.push_back(temp);
	return internal;
}

vector<string> solution(vector <string> record) {
	vector<string> answer;
	string _uid, _operation;

	for (int i = 0; i < record.size(); i++) {
		string _rec = record[i];
		vector<string> _toks = split(_rec, ' ');
		_uid = _toks[uid];
		_operation = _toks[operation];
		if(_toks[operation] == "Enter"){
			g_table[_toks[uid]] = _toks[name];
			g_uid.push_back(_uid);
			g_operation.push_back(_operation);
		}
		else if (_toks[operation] == "Change") {
			g_table[_toks[uid]] = _toks[name];
		}
		else {
			g_uid.push_back(_uid);
			g_operation.push_back(_operation);
		}
	}
	for (int i = 0; i < g_uid.size(); i++) {
		_uid = g_table[g_uid[i]];
		_operation = (g_operation[i] == "Enter" ? "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù." : "´ÔÀÌ ³ª°¬½À´Ï´Ù.");
		answer.push_back(_uid + _operation);
	}
	return answer;
}



int main()
{
	vector<string> record;
	record.push_back("Enter uid1234 Muzi");
	record.push_back("Enter uid4567 Prodo");
	record.push_back("Leave uid1234");
	record.push_back("Enter uid1234 Prodo");
	record.push_back("Change uid4567 Ryan");
	vector<string> answer = solution(record);

	return 0;
}
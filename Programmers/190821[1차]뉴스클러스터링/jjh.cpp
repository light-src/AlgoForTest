#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string, string);

// 테스트용 메인함수
int main(void) {
	string str1 = "E=M*C^2";
	string str2 = "e=m*c^2";
	int answer = solution(str1, str2);

	cout << answer << endl;

	system("pause");
	return 0;
}

int solution(string str1, string str2) {
	int answer = 0, len = 0, count = 0;
	bool flag = false;

	vector<string> ary;

	// 두 문자열 소문자로 변환
	for (auto &c : str1) {
		if (c >= 'A' && c <= 'Z')
			c = c - ('A' - 'a');
	}

	for (auto &c : str2) {
		if (c >= 'A' && c <= 'Z')
			c = c - ('A' - 'a');
	}

	// str1을 쪼개서 성분으로 vector 생성
	for (int i = 0; i < str1.size() - 1; i++) {
		if (isalpha(str1[i]) && isalpha(str1[i + 1]))
			ary.push_back(str1.substr(i, 2));
	}

	// 합집합의 크기에 str1에서 나온 성분의 개수 추가
	len = ary.size();

	// str2는 vector로 만들지 않고 바로 뜯어서 ary에 존재하는지 검사
	for (int loop = 0; loop < str2.size() - 1; loop++) {
		flag = false;
		string temp = str2.substr(loop, 2);

		// 두 문자가 알파벳이 아니면 스킵
		if (!isalpha(temp.at(0)) || !isalpha(temp.at(1)))
			continue;

		// vector에 교집합이 있는지 검사, 존재하면 합집합에 중복이므로 추가할 필요 없음
		for (int i = 0; i < ary.size(); i++) {
			if (temp.compare(ary[i]) == 0) {
				count++;				// 교집합의 개수 추가
				ary.erase(ary.begin() + i);		// 해당 성분 삭제(같은 성분이 여러개 있을 수 있음)
				flag = true;
				break;
			}
		}
		// 성분이 없으면 합집합의 개수 추가
		if (!flag)
			len++;
	}

	// 서로 성분이 아예 존재하지 않을 경우
	if (len == 0)
		return 65536;

  // count / len * 65536 을 하면 count / len에서 바로 0이 되어버리므로 65536을 먼저 곱해줌
	answer = 65536 * count / len;
	return answer;
}

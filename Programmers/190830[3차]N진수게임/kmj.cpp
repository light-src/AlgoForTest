#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

string make_n(int n, int bin)
{
	string answer = "";
	char temp;

	if (n == 0)
		return "0";
	while (n != 0) {
		if (n % bin >= 10) {
			temp = (n % bin) + 55;
			string str(1, temp);
			answer += str;
		}
		else
			answer += to_string(n % bin);
		n /= bin;
	}
	reverse(answer.begin(), answer.end());
	return answer;
}

string solution(int n, int t, int m, int p) {
	string answer = "", temp = "";
	int i, cnt = 0, total = 0, mult = 0;

	while (answer.size() != t) {
		total += make_n(cnt, n).size();
		temp += make_n(cnt, n);
		if (total > m * mult + p) {
			//차례가 있음.
			for (i = m * mult + p; i < total; i += m) {
				answer += temp[i - 1]; //이부분 수정해서 효울성을 높여야할듯..
				mult++;
			}
		}
		cnt++;
	}

	return answer;
}

int main()
{
	cout << solution(2, 4, 2, 1) << endl;
	cout << solution(16, 16, 2, 1) << endl;
	cout << solution(16, 16, 2, 2) << endl;
	//cout << solution(16, 1000, 100, 100) << endl;

	system("pause");
	return 0;
}

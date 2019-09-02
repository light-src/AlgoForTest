#include <iostream>
#include <vector>
#include <string>

using namespace std;

string solution(int, int, int, int);
string toString(int, int);

int main(void) {
	int n = 16, t = 16, m = 2, p = 2;
	string answer = solution(n, t, m, p);

	cout << answer << endl;

	system("pause");
	return 0;
}

string solution(int n, int t, int m, int p) {
	string answer = "";
	string str = "";
	int count = 0;

	// make string
	while (str.length() < t * m) {
		str += toString(count, n);
		count++;
	}

	for (int i = 0; i < t; i++) {
		answer += str.at(m * i + p - 1);
	}

	return answer;
}

string toString(int num, int n) {
	int a, b;
	string temp;

	while (num >= n) {
		a = num / n;
		b = num % n;

		if (b >= 10) {
			switch (b) {
			case 10:
				temp += "A";
				break;
			case 11:
				temp += "B";
				break;
			case 12:
				temp += "C";
				break;
			case 13:
				temp += "D";
				break;
			case 14:
				temp += "E";
				break;
			case 15:
				temp += "F";
			}
		}
		else temp += to_string(b);

		num = a;
	}

	if (num >= 10) {
		switch (num) {
		case 10:
			temp += "A";
			break;
		case 11:
			temp += "B";
			break;
		case 12:
			temp += "C";
			break;
		case 13:
			temp += "D";
			break;
		case 14:
			temp += "E";
			break;
		case 15:
			temp += "F";
		}
	}
	else temp += to_string(num);

	std::reverse(temp.begin(), temp.end());

	return temp;
}

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string str1, string str2) {
    int i, j, answer;
    float sum = 0, mul = 0;
	float temp;
	vector<string> str1_arr, str2_arr;

	//모두 소문자로
	for(i = 0; i < str1.size(); i++) 
        str1[i] = tolower(str1[i]);
    for(i = 0; i < str2.size(); i++)
        str2[i] = tolower(str2[i]);
    
	//두글자씩 끊어서 배열에 저장
	for (i = 0; i < str1.size() - 1; i++) {
		if (str1[i] < 97 || str1[i] > 122)
			continue;
		if (str1[i + 1] < 97 || str1[i + 1] > 122)
			continue;
		str1_arr.push_back(str1.substr(i, 2));
	}
	for (i = 0; i < str2.size() - 1; i++) {
		if (str2[i] < 97 || str2[i] > 122)
			continue;
		if (str2[i + 1] < 97 || str2[i + 1] > 122)
			continue;
		str2_arr.push_back(str2.substr(i, 2));
	}

	//교집합 갯수 구하기. 합집합은 두 집합의 갯수에서 교집합 수만큼 빼주면 된다.
	mul = str1_arr.size() + str2_arr.size();
	for (i = 0; i < str1_arr.size(); i++) {
		for (j =0 ; j < str2_arr.size(); j++) {
			if (str1_arr[i] == str2_arr[j]) {
				sum++;
				str2_arr.erase(str2_arr.begin() + j);
				break;
			}
		}
	}

	//출력
    mul -= sum;
	if (mul == 0) 
		answer = 65536;
	else 
		answer = sum / mul * 65536;

	return answer;
}

int main()
{
  solution("FRENCH", "france");
  reutrn 0;
 }

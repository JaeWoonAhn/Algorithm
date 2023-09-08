#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/*
Q.노래 가사 분석기
입력
첫 줄에는

띄어쓰기 없이, 한 줄의 노래가사를 입력 받습니다.

노래가사의 길이는 최대 10,000 글자 입니다.



두 번째 줄에는 N을 입력 받습니다. ( 1 <= N <= 100,000)

그 다음 줄 부터, 총 N개의 찾고 싶은 문자열을 입력 받습니다.

찾고자 하는 문자열의 길이는 2 ~ 5 글자 입니다.
*/

/*
Idea.
1. 선형 탐색???!!
 - 어차피 찾는게 O(1)니깐, 가능성있는 모든 것들을 넣고 찾아볼까?

 2. 문자열(substring)의 길이가 2~5니깐 모든 2~5를 다 넣고 찾자.
*/

string lyrics;
int N;
string targets[100000];
unordered_map<string, int> ret;

void input() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> lyrics;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> targets[i];
	}
}

void solution() {

	// substr로 가능성있는 것들 모두 unorder_map에 넣기
	for (int i = 0; i < lyrics.size()-1; i++) {

		
		string substr_2 = lyrics.substr(i, 2);
		if (ret.find(substr_2) != ret.end())
			ret[substr_2]++;
		else
			ret.insert({ substr_2, 1 });

		if (i < lyrics.size() - 2) {
			string substr_3 = lyrics.substr(i, 3);
			if (ret.find(substr_3) != ret.end())
				ret[substr_3]++;
			else
				ret.insert({ substr_3, 1 });
		}

		if (i < lyrics.size() - 3) {
			string substr_4 = lyrics.substr(i, 4);
			if (ret.find(substr_4) != ret.end())
				ret[substr_4]++;
			else
				ret.insert({ substr_4, 1 });
		}

		if (i < lyrics.size() - 4) {
			string substr_5 = lyrics.substr(i, 5);
			if (ret.find(substr_5) != ret.end())
				ret[substr_5]++;
			else
				ret.insert({ substr_5, 1 });
		}
	}


	// output
	for (int i = 0; i < N; i++) {
		string word = targets[i];
		cout << ret[word] << endl;
	}
}
int main() {

	input();
	solution();

}
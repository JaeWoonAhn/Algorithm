#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
/*
Q. anagram (ABC = ABC, ACB, BAC, BCA, CAB, CBA)
N개의 단어가 주어졌을 때, 가장 크기가 큰 아나그램 그룹의 크기를 출력

input)
4
KBA
BAB
BBA
ABB

output)
3

idea)
1. unordered_map에는 중복이 안되니 키 값으로 중복처리하고 이미 존재하면 뒤에 밸류를 ++하는 방식
1-1. 키 값 중복 처리
1-1-1. char arr 로 입력 받아서 벡터에 push 후 정렬처리하기?

*/
int N;
unordered_map<string, int> um;
vector<char> v;

void input() {
//	freopen_s(new FILE*, "input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		sort(str.begin(), str.end());
	
		if (um.find(str) != um.end()) {
			// exist
			um[str]++;
		}
		else {
			// don't exist
			um.insert({ str, 1 });
		}
	}
}
int solution() {
	int max = 0;

	for (auto it = um.begin(); it != um.end(); it++) {
		if ((*it).second > max) {
			max = (*it).second;
		}
	}

	return max;
}
int main() {
	input();
	cout << solution();

}
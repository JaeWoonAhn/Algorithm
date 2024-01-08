#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

set<int> SetA;
set<int> SetB;
int N, M;
int Dup = 0;
void init() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		SetA.insert(num);
	}
	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;
		if (SetA.find(num) != SetA.end()) {
			Dup++;
		}
	}
}

void solution() {
	cout << (N - Dup) + (M - Dup) << endl;
}

int main() {

	init();
	solution();
	return 0;
}
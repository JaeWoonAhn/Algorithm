#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> v;
int Max = 0;
int Cnt = 0;

void init() {
	cin >> N;

	v.push_back(500);
	v.push_back(100);
	v.push_back(50);
	v.push_back(10);
	v.push_back(5);
	v.push_back(1);
}

void solution() {
	N = 1000 - N;
	while (N > 0) {
		for (int i = 0; i < v.size(); i++) {
			Cnt += N / v[i];
			N = N % v[i];
		}
	}
}

int main() {

	init();
	solution();
	cout << Cnt << endl;

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define border 10000001
int N, M;
int DatPlus[border];
int DatMinus[border];

void init(){
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;

		if (num > 0) {
			DatPlus[num] += 1;
		}
		else {
			DatMinus[-num] += 1;
		}
	}
}

void solution() {
	cin >> M;
	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;

		if (num > 0) {
			cout << DatPlus[num] << " ";
		}
		else {
			cout << DatMinus[-num] << " ";
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	init();
	solution();

	return 0;
}
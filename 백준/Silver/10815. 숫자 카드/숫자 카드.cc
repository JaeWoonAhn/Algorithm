#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define border 10000001

int DAT_Plus[border];
int DAT_Minus[border];
int N;
int M;

void init() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		if (num < 0) {
			DAT_Minus[-num] = 1;
		}
		else {
			DAT_Plus[num] = 1;
		}
	}
}

void solution() {
	cin >> M;
	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;
		if (num < 0) {
			if (DAT_Minus[-num] == 1) {
				cout << 1 << " ";
			}
			else {
				cout << 0 << " ";
			}
		}
		else {
			if (DAT_Plus[num] == 1) {
				cout << 1 << " ";
			}
			else {
				cout << 0 << " ";
			}
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
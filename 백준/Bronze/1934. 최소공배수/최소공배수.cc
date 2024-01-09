#include <bits/stdc++.h>

using namespace std;

int T;
int A, B;
int Min = 21e8;

void init() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> A >> B;
		Min = min(A, B);
		int maxCommon = 0;
		for (int j = 1; j <= Min; j++) {
				if (A % j == 0 && B % j == 0) {
					maxCommon = j;
				}
			}

			int res = maxCommon * (A / maxCommon) * (B / maxCommon);
			cout << res << endl;

	}
}
void solution() {
}
int main() {
	init();


}
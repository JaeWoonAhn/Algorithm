#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	int N, M;
	cin >> N >> M;

	vector<int> v6;
	vector<int> v1;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;

		v6.push_back(a);
		v1.push_back(b);
	}

	sort(v1.begin(), v1.end());
	sort(v6.begin(), v6.end());


	int min1 = v1[0];
	int min6 = v6[0];

	if (min6 > min1 * 6) {
		cout << min1 * N;
	}
	else {
		if (min6 < min1 * (N % 6)) {
			cout << min6 * (N / 6 + 1) ;
		}
		else {
			cout << min6 * (N / 6) + min1 * (N % 6);
		}
	}
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int A, B;
	cin >> A >> B;
	int cnt = 0;

	while (A < B) {
		if (B % 10 == 1) {
			B /= 10;
			cnt++;
		}
		else if (B % 2 == 0) {
			B /= 2;
			cnt++;
		}
		else {
			break;
		}
	}
	if (A == B) {
		cout << cnt;
	}
	else {
		cout << -1;
	}
}
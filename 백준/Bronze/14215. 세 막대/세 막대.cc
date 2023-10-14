#include <iostream>

using namespace std;

int main() {

	int len[3] = { 0 };
	int max = 0;
	int max_idx = 0;
	int sum = 0;
	int res = 0;

	for (int i = 0; i < 3; i++) {
		cin >> len[i];
		if (max < len[i]) {
			max = len[i];
			max_idx = i;
		}
	}

	for (int i = 0; i < 3; i++) {
		if (i == max_idx)
			continue;
		sum += len[i];
	}
	if (max >= sum) {
		res = sum * 2 - 1;
	}
	else {
		res = sum + max;
	}

	cout << res << endl;



	return 0;
}
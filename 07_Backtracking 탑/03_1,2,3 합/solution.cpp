#include <iostream>

using namespace std;

int target;
int range[3] = { 1,2,3 };
int cnt = 0;
int flag = 0;
void recursive(int leftover) {

	if (leftover== 0) {
		cnt++;
	}

	for (int i = 0; i < 3; i++) {
		if (leftover - range[i] < 0) {
			continue;
		}
		recursive(leftover -range[i]);
	}
}

int main() {
	cin >> target;

	recursive(target);
	cout << cnt;
}
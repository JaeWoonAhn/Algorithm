#include <iostream>

using namespace std;

int main() {
	while (1) {
		int len[3] = { 0 };
		int cnt = 0;
		int cntup = 0;

		int max = 0;
		int idx_max = 0;
		for (int i = 0; i < 3; i++) {
			cin >> len[i];
			if (max < len[i]) {
				max = len[i];
				idx_max = i;
			}
		}
		int sum = 0;
		for (int i = 0; i < 3; i++) {
			if (i == idx_max) {
				continue;
			}
			sum += len[i];
		}
		if (len[0] == 0) {
			return 0;
		}
		if (sum <= max) {
			cout << "Invalid" << endl;
			continue;
		}

		
		for (int i = 1; i < 3; i++) {
			if (len[0] == len[i]) {
				cnt++;
			}
		}
		if (cnt==2){
			cout << "Equilateral" << endl;
		}

		if (len[1] == len[2]) {
			cnt++;
		}

		if (cnt == 1) {
			cout << "Isosceles" << endl;
		}
		else if (cnt == 0) {
			cout << "Scalene" << endl;
		}
	}

	return 0;
}
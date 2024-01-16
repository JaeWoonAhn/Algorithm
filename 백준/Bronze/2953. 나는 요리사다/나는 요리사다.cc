#include<bits/stdc++.h>

using namespace std;

int Max = 0;

void init() {

	int idx = 0;
	
	for (int i = 0; i < 5; i++) {

		int sum = 0;
		for (int j = 0; j < 4; j++) {
			int num;
			cin >> num;

			sum += num;
		}
		if (sum > Max) {
			Max = sum;
			idx = i + 1;
		}
	}


	cout << idx << " " << Max << endl;
}

int main() {
	init();

	return 0;
}
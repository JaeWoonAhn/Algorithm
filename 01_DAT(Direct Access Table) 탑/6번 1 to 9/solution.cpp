#include <iostream>

using namespace std;

int main() {

	int type;
	cin >> type;

	int n;
	cin >> n;

	int DAT[10] = { 0 };
	
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		DAT[temp]++;
	}

	if (type == 1) {
		for (int i = 1; i <= 9; i++) {
			cout << i << ":" << DAT[i] << "개" << endl;
		}
	}
	else {
		for (int i = 1; i <= 9; i++) {
			if (DAT[i] > 1) {
				cout << "중복발견";
				return 0;
			}
		}
		cout << "중복없음";
	}

}
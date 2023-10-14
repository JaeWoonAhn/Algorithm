#include <iostream>

using namespace std;

int angle[3];
int cnt;
int cntup;
int main() {

	for (int i = 0; i < 3; i++) {
		cin >> angle[i];
		cntup += angle[i];
	}
	if (cntup != 180) {
		cout << "Error" << endl;
		return 0;
	}

	for (int i = 1; i < 3; i++) {
		if (angle[0] == angle[i + 1]) {
			cnt++;
		}
	}
	if (angle[1] == angle[2]) {
		cnt++;
	}

	if (cnt == 1) {
		cout << "Isosceles" << endl;
	}
	else if (cnt == 0) {
		cout << "Scalene" << endl;
	}
	else if (cnt==2){
		cout << "Equilateral" << endl;
	}

	return 0;
}
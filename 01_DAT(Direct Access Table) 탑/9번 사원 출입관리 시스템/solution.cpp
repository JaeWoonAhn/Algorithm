#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int DAT[10000] = { 0, };
char* DATchar[10000];

int absolute(int num) {
	if (num < 0) {
		return -num;
	}
	return num;
}

int main() {

	//freopen_s(new FILE*, "./input.txt", "r", stdin);
	//freopen_s(new FILE*, "./output.txt", "w", stdout);
	int n;
	cin >> n;

	int flag = 0;

	for (int _ = 0; _ < n; _++) {
		cin >> flag;
		char name[100];
		int employee_num;

		cin >> employee_num;
		// 1 입력 시 회원 가입
		if (flag == 1) {
			cin >> name;
			if (absolute(DAT[employee_num]) == 1) {
				cout << employee_num << " ERROR" << endl;
			}
			else {
				DAT[employee_num] = 1;

				// FIXME
				DATchar[employee_num] = new char[100];
				strcpy(DATchar[employee_num], name);

				cout << employee_num << " OK" << endl;
			}
		}
		else if (flag == 2) {
			DAT[employee_num] *= -1;

			if (DAT[employee_num] == -1) {
				cout << employee_num << " " << DATchar[employee_num] << " ENTER" << endl;
			}
			else if (DAT[employee_num] == 1) {
				cout << employee_num << " " << DATchar[employee_num] << " EXIT" << endl;
			}
			else {
				cout << employee_num << " ERROR" << endl;
			}

		}
	}

}
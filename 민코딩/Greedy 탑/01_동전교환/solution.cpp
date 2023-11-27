#include <iostream>
#include <vector>

using namespace std;

int main() {
	int money;
	cin >> money;

	int cnt = 0;

	if (money / 500 >= 1) {
		cnt += money / 500;
	}
	money %= 500;
	if (money / 100 >= 1) {
		cnt += money / 100;
	}
	money %= 100;
	if (money / 50 >= 1) {
		cnt += money / 50;
	}
	money %= 50;
	if (money / 10 >= 1) {
		cnt += money / 10;
	}
	cout << cnt;
}
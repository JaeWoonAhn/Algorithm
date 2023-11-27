#include <iostream>

using namespace std;

int main() {

	char str[100000] = { 0, };
	int size = sizeof(str) / sizeof(str[0]);
	int DAT[26] = { 0, };

	cin >> str;
	for (int i = 0; i < size; i++) {
		DAT[str[i] - 'A']++;
	}

	for (int i = 0; i < 26; i++) {
		if (DAT[i] >= 1) {
			cout << char(i + 'A');
		}
	}

}
#include <iostream>
#include <cstring>

using namespace std;

int N;
string str;
int DAT[2];
int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N >> str;

	int left = 0;
	int right = N / 2;
	for (int i = left; i < right; i++) {
		if (str[i] == 's') {
			DAT[0]++;
		}
		else {
			DAT[1]++;
		}
		if (DAT[0] == N / 4 && DAT[1] == N / 4) {
			cout << 1 << "\n" << right;
			return 0;
		}
	}
	right = N / 2 - 1;
	while (right < N - 2) {
		if (str[left] == 's') {
			DAT[0]--;
			left++;
		}
		else{
			DAT[1]--;
			left++;
		}

		right++;
		if (str[right] == 's') {
			DAT[0]++;
		}
		else{
			DAT[1]++;
		}
		if (DAT[0] == N / 4 && DAT[1] == N / 4) {
			cout << 2 << "\n" << left << " "<< right+1;
			return 0;
		}
	}

	memset(DAT, 0, sizeof(DAT));
	left = N - N / 2;
	right = N;
	for (int i = left; i < right; i++) {
		if (str[i] == 's') {
			DAT[0]++;
		}
		else {
			DAT[1]++;
		}
		if (DAT[0] == N / 4 && DAT[1] == N / 4) {
			cout << 1 << "\n" << right;
			return 0;
		}
	}
}
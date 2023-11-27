#include <iostream>

using namespace std;

int main() {

	int H;
	cin >> H;

	int W;
	cin >> W;

	int DAT[10000001] = { 0 };
	
	for (int i = 0; i < H * W; i++) {
		int temp;
		cin >> temp;
		DAT[temp]++;
	}

	int max = 0;

	int idx = 0;
	for (int i = 0; i < 10000001 ; i++) {
		if (DAT[i] > max) {
			max = DAT[i];
			idx = i;
		}
	}
	cout << idx;

}
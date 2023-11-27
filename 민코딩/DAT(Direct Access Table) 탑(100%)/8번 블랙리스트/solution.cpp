#include <iostream>

using namespace std;

int main() {

	int H;
	cin >> H;

	int W;
	cin >> W;

	int person = H * W;
	int DAT[100001] = { 0, };
	
	for (int i = 0; i < H * W; i++) {
		int temp;
		cin >> temp;
		DAT[temp]++;
	}

	int sum = 0;

	cin >> H >> W;
	for (int i = 0; i < H*W ; i++) {
		int temp;
		cin >> temp;
		sum += DAT[temp];
		DAT[temp] = 0;
	}
	cout << sum << endl;
	cout << person - sum << endl;

}
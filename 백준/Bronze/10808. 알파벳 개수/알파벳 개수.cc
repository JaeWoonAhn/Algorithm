#include <bits/stdc++.h>

using namespace std;

#define border 100
#define endl "\n"

string Arr;
int DAT[26];

void init() {
	cin >> Arr;
}

void solution() {
	for (int i = 0; i < Arr.size(); i++) {
		int idx = int(Arr[i] - 'a');
		DAT[idx]++;
	}

	for (int i = 0; i < 26; i++) {
		cout << DAT[i] << " ";
	}
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();
	solution();

	return 0;
}
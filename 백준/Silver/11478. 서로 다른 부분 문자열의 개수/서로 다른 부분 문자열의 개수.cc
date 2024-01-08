#include <bits/stdc++.h>

using namespace std;

string S;
set<string> Set;

void init() {
	cin >> S;
}

void solution() {
	S.substr(0, 0);
	for (int i = 0; i <= S.length(); i++) {
		for (int j = 1; j <= S.length()-i; j++) {
			Set.insert(S.substr(i, j));
		}
	}
	cout << Set.size() << endl;
}
int main() {
	init();
	solution();
	return 0;
}
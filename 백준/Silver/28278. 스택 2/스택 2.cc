#include<bits/stdc++.h>

using namespace std;
#define endl "\n"
int N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	vector<int> v;

	for (int i = 0; i < N; i++) {
		int cmd;
		cin >> cmd;
		if (cmd == 1) {
			int tmp;
			cin >> tmp;
			v.push_back(tmp);
		}
		else if (cmd == 2) {
			if (v.size() != 0) {
				cout << v.back() << endl;
				v.pop_back();
			}
			else {
				cout << -1 << endl;
			}
		}
		else if (cmd == 3) {
			cout << v.size() << endl;
		}
		else if (cmd == 4) {
			if (v.size() != 0) {
				cout << 0 << endl;
			}
			else {
				cout << 1 << endl;
			}
		}
		else if (cmd == 5) {
			if (v.size() != 0) {
				cout << v.back() << endl;
			}
			else {
				cout << -1 << endl;
			}
		}
	}

	return 0;
}
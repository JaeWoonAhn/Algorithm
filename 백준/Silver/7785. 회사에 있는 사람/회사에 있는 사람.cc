#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int N;
vector<string> Res;
map<string, bool> M;

void init() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		string name;
		string log;

		cin >> name >> log;

		map<string, bool>::iterator it = M.find(name);

		if (log.compare("enter") == 0) {
			// enter 입력 시
			if (it != M.end()) {
				// 존재하면
				M[name] = true;
			}
			else {
				M.insert(pair<string, bool>(name, true));
			}
		}
		else {
			if (it != M.end()) {
				// 존재하면
				M[name] = false;
			}
		}
	}

}

void solution() {
	for (auto it = M.begin(); it != M.end(); it++) {
		if (it->second) {
			Res.push_back(it->first);
		}
	}

	//sort(Res.begin(), Res.end(), greater<string>());
	reverse(Res.begin(), Res.end());

	for (int i = 0; i < Res.size(); i++) {
		cout << Res[i] << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	init();
	solution();

	return 0;
}
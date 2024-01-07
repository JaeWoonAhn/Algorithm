#include <bits/stdc++.h>

using namespace std;

int N, M;
int Cnt;
map<string, bool> Map;
vector<string> V;

void init() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;

		Map.insert(pair<string, bool>(str, true));
	}
}

void solution() {
	for (int i = 0; i < M; i++) {
		string str;
		cin >> str;

		map<string, bool>::iterator it = Map.find(str);

		if (it != Map.end()) {
			Cnt++;
			V.push_back(str);
		}
	}

	cout << Cnt << endl;
	sort(V.begin(), V.end());
	for (int i = 0; i < V.size(); i++) {
		cout << V[i] << endl;
	}
}
int  main() {

	init();
	solution();
	return 0;
}
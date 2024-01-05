#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int N, M;
vector<string> Res;
map<string, int> Map;
map<string, string> MapReverse;

void init() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		string name;
		
		cin >> name;
		Map.insert(pair<string, int>(name, i));
		string num = to_string(i);
		MapReverse.insert(pair<string, string>(num,name));
	}
}

void solution() {
	for (int i = 0; i < M; i++) {
		string str;
		cin >> str;
		if (Map[str] == 0) {
			cout << MapReverse[str] << endl;
		}
		else {
			cout << Map[str] << endl;
		}
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
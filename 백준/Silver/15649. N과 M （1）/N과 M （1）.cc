#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define boarder 101;

int N, M;
int DAT[9];
vector<int> v;

void dfs(int level) {
	if (level == M) {
		for (int i = 0; i < M; i++) {
			cout << v[i] << " ";
		}
		cout << endl;
		return;
	}
	
	for (int i = 1; i <= N; i++) {
		if (DAT[i] == 1) {
			continue;
		}
		DAT[i] = 1;
		v.push_back(i);
		dfs(level + 1);
		DAT[i] = 0;
		v.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	//freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N >> M;

	dfs(0);

	return 0;
}
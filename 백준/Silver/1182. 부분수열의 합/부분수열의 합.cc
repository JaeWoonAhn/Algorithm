#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
int N, S;
int Arr[22];
bool IsUsed[22];
int Cnt = 0;
vector<int> V;

void init() {
	Cnt = 0;
	cin >> N >> S;

	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		V.push_back(tmp);
	}
}
vector<int> Vtmp;
void dfs(int idx, int flag) {
	if (idx == N) {
		int sum = 0;
		if (Vtmp.size() == 0) {
			return;
		}
		for (int i = 0; i < Vtmp.size(); i++) {
	//		cout << Vtmp[i] << " ";
			sum += Vtmp[i];
		}
	//	cout << endl;
		if (sum == S) {
			Cnt++;
		}
		return;
	}
	if (flag == 1) {
		Vtmp.push_back(V[idx]);
	}
	dfs(idx + 1, 0);
	if (idx < N-1) {
		dfs(idx + 1, 1);
	}
	if (flag == 1) {
		Vtmp.pop_back();
	}
}
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	init();
	dfs(-1, 0);

	cout << Cnt << endl;
	return 0;
}
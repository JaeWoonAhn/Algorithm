#include <bits/stdc++.h>

using namespace std;
#define endl "\n"


int N, M;
int Arr[100];
int DAT[100001];
int Min = 21e8;
vector<int> v;
int Sum = 0;
int Res;
void init() {
	
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> Arr[i];
	}
}

void dfs(int idx) {
	if (v.size() == 3) {
		int tmp = (M - Sum);
		if (tmp < 0) {
			return;
		}

		if (tmp < Min) {
			Min = min(Min, tmp);
			Res = Sum;
		}

		return;
	}

	for (int i = idx; i < N; i++) {
		if (DAT[i] == 1) {
			continue;
		}
		DAT[i] = 1;
		Sum += Arr[i];
		v.push_back(i);
		dfs(idx + 1);
		DAT[i] = 0;
		Sum -= Arr[i];
		v.pop_back();
	}
}

void solution() {
	dfs(0);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();
	solution();
	cout << Res << endl;
}
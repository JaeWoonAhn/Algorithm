#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define boarder 101;

int N, M;
int DAT[10001];
int temp = 1;
vector<int> v;
vector<int> ans;
int arr[9];

void dfs(int idx) {
	if (idx == M) {
		for (int i = 0; i < M; i++) {
			cout << ans[i] << " ";
		}
		cout << endl;
		return;
	}

	for (int i = 0; i < N; i++) {
		ans.push_back(v[i]);
		if (idx > 0) {
			if (ans[idx - 1] > ans[idx]) {
				ans.pop_back();
				continue;
			}
		}
		dfs(idx+1);
		ans.pop_back();
	}
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	dfs(0);

	return 0;
}
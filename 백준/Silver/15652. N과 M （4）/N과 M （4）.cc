#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define boarder 101;

int N, M;
int DAT[9];
int temp = 1;
vector<int> v;
int arr[9];

void dfs(int idx) {
	if (idx == M) {
		for (int i = 0; i < M; i++) {
			cout << v[i] << " ";
		}
		cout << endl;
		return;
	}

	for (int i = 1; i <= N; i++) {
		v.push_back(i);
		if (idx>0 ) {
			if (v[idx -1] > v[idx]) {
				v.pop_back();
				continue;
			}
		}
		dfs(idx+1);
		v.pop_back();
	}
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	dfs(0);

	return 0;
}
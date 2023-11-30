#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> v;
vector<int> temp;
int DAT[10];
set<vector<int>> s;
int N, M;

void init() {
	cin >> N >> M;

	s.clear();
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
}

void dfs(int idx) {
	if (temp.size() == M) {
	/*	for (int i = 0; i < temp.size(); i++) {
			cout << temp[i] << " ";
		}
		cout << endl;*/
		if (s.find(temp) == s.end())
			s.insert(temp);
		return;
	}
	for (int i = idx; i < N; i++) {
		//if (DAT[i] == 1) {
		//	continue;
		//}
		//DAT[i] = 1;
		temp.push_back(v[i]);
		dfs(i+1);
		temp.pop_back();
		//DAT[i] = 0;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
//	freopen_s(new FILE*, "input.txt", "r", stdin);

	init();
	sort(v.begin(), v.end());
	dfs(0);

	for (auto iter = s.begin(); iter != s.end(); iter++) {
		if (iter != s.begin()) {
			cout << '\n';
		}
		for (int i = 0; i < M; i++) {
			cout << (*iter)[i] << ' ';
		}
	}

	return 0;
}
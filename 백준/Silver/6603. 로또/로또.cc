#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> V;
vector<int> Vres;
int DAT[50];
set<vector<int>> s;
int K;
int Flag = 0;

void init() {
	cin >> K;
	Flag = 0;
	if (K == 0) {
		// Stop
		Flag = 1;
	}
	else {
		V.clear();
		for (int i = 0; i < K; i++) {
			int temp;
			cin >> temp;
			V.push_back(temp);
		}
	}
}

void dfs(int idx) {
	if (Vres.size() == 6) {
		for (int i = 0; i < Vres.size(); i++) {
			cout << Vres[i] << " ";
		}
		cout << endl;
		//if (s.find(temp) == s.end())
		//	s.insert(temp);
		return;
	}

	if (Vres.size() >= 1) {
		if (Vres[0] > V[K - 6]) {
			return;
		}
	}
	for (int i = idx; i < V.size(); i++) {
		if (DAT[V[i]] == 1) {
			continue;
		}
		DAT[V[i]] = 1;
		Vres.push_back(V[i]);
		dfs(i+1);
		Vres.pop_back();
		DAT[V[i]] = 0;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
//	freopen_s(new FILE*, "input.txt", "r", stdin);

	while (1) {
		init();
		if (Flag == 1) {
			break;
		}
		dfs(0);
		cout << endl;
	}
	//sort(V.begin(), V.end());

	//for (auto iter = s.begin(); iter != s.end(); iter++) {
	//	if (iter != s.begin()) {
	//		cout << '\n';
	//	}
	//	for (int i = 0; i < M; i++) {
	//		cout << (*iter)[i] << ' ';
	//	}
	//}

	return 0;
}
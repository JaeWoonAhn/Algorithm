#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
int n, m;
int target1, target2;
vector<int> v[101];
vector<int> v1;
int visited[101];
queue<int> q;
int ans;

void bfs(int cur) {
	q.push(cur);
	visited[cur] = 1;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 0; i < v[now].size(); i++){
			if (visited[v[now][i]]) {
				continue;
			}
			visited[v[now][i]] = visited[now] + 1;
			q.push(v[now][i]);
		}
	}
}

void solution(int start) {
	//if (visited[start]) {
	//	return;
	//}
	memset(visited, 0, sizeof(visited));
	bfs(start);
}
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	//freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> n;
	cin >> target1 >> target2;
	cin >> m;
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
		v1.push_back(a);
	}

	
	//for (int i = 0; i < v1.size(); i++) {
	//	solution(v1[i]);
	//	if (visited[target1] != 0 && visited[target2] != 0) {
	//		break;
	//	}
	//}
	bfs(target1);
	if (visited[target1] == 0 || visited[target2] == 0) {
		ans = -1;
	}
	else {
		ans = visited[target1] + visited[target2] -2 ;
	}
	cout << ans << endl;
	
	return 0;
}
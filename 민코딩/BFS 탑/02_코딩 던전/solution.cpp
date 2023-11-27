#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	int M, N, K;
	cin >> M >> N >> K;
	int sum = 0;
	vector<int> edge[11][2];
	vector<int> ret;
	int visited[11] = {0,};
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edge[a][0].push_back(b);
		edge[a][1].push_back(c);
	}
	queue<int> q;
	visited[0] = 1;
	q.push(0);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < edge[now][0].size(); i++) {
			int next = edge[now][0][i];
			if (visited[next] >= 1) {
				continue;
			}
			visited[next] = visited[now] + edge[now][1][i];
			if (visited[next] <= K+1) {
				q.push(next);
				ret.push_back(next);
			}
		}
	}
	sort(ret.begin(), ret.end());
	for (int i = 0; i < ret.size(); i++) {
		cout << ret[i] << " ";
	}
}
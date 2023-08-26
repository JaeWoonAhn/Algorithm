#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> v[100001][2];
int visited[100001];
int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	int N, M, K;
	cin >> N >> M >> K;

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		v[a][0].push_back(b);
		v[a][1].push_back(c);
	}

	int cnt = 0;
	queue<int> q;
	visited[1] = 1;
	q.push(1);
	

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 0; i < v[now][0].size(); i++) {
			int next = v[now][0][i];
			if (visited[next] >= 1) {
				continue;
			}
			visited[next] += visited[now] + v[now][1][i];

			if (visited[next] > K + 1) {
				continue;
			}
			cnt++;
			q.push(next);
		}
	}

	cout << cnt;
}
#include <iostream>
#include <vector>	
#include <queue>

using namespace std;

vector<int> v[100001];
int visited[100001];

int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	int N, M;
	cin >> N >> M;

	for (int _ = 0; _ < M; _++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	int K;
	cin >> K;

	int cnt = 0;
	queue<int> q;
	visited[K] = 1;
	q.push(K);

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i];
			if (visited[next] == 1) {
				continue;
			}

			cnt++;
			q.push(next);
			visited[next] = 1;
			
		}
	}

	cout << cnt;
}
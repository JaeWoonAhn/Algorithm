#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int visited[11] = { 0, };
vector<int> v[11];
int N, M, T;

int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;

		v[A].push_back(B);
		v[B].push_back(A);
	}

	cin >> T;

	queue<int> q;
	visited[1] = 1;
	q.push(1);
	int ret = 0;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i];

			if (visited[next] == 1) {
				continue;
			}
			if (next == T) {
				continue;
			}

			q.push(next);
			visited[next] = visited[now] + 1;
			if (next == N) {
				ret = visited[next];
				cout << ret-1;
				return 0;
				
			}
		}
	}
	cout << -1;
}
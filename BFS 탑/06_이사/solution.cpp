#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int visited[11];
vector<int> v[11];
int N, M, R, K;
int cnt = 0;

int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;

		v[A].push_back(B);
		v[B].push_back(A);
	}

	cin >> R >> K;

	queue<int> q;

	q.push(R);
	visited[R] = 1;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i];

			if (visited[next] >= 1) {
				continue;
			}
			
			q.push(next);
			visited[next] = visited[now] + 1;
			if (visited[next] <= K+1 ) {
				cnt++;
			}
		}

	}
	cout << cnt+1;
}
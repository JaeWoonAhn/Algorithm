#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> v[101];
int visited[101];
int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);

	int N, T;
	cin >> N >> T;

	for (int i = 0; i < T; i++) {
		int A, B;
		cin >> A >> B;
		
		v[A].push_back(B);
		v[B].push_back(A);
	}

	int C, M;	// C:coco, M:man
	cin >> C >> M;

	visited[C] = 1;
	queue<int> q;
	q.push(C);

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i];
			if (next == M) {
				cout << "YES";
				return 0;
			}
			if (visited[next] == 1) {
				continue;
			}
			q.push(next);
			visited[next] = 1;
		}
	}

	cout << "NO";
	return 0;
}
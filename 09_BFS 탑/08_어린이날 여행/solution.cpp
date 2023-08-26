#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> v[200001];
vector<int> ret;
int N, M, K, P;
int visited[200001] = { 0 };

int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N >> M >> K >> P;
	// N:도시 개수, M:도로의 개수, K:남은 기름칸 수, P:출발도시번호

	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;

		v[A].push_back(B);	// 단방향
	}

	queue<int> q;

	q.push(P);
	visited[P] = 1;
	int cnt = 0;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i];

			if (visited[next] >= 1) {
				continue;
			}
			cnt++;
			q.push(next);
			visited[next] = visited[now] + 1;

			if(visited[next] == K+1) {
				ret.push_back(next);
			}
		}

	}

	if (ret.size() >= 1) {
		sort(ret.begin(), ret.end());
		for (int i = 0; i < ret.size(); i++) {
			cout << ret[i] << endl;
		}
	}
	else {
		cout << -1;
	}
	return 0;
}
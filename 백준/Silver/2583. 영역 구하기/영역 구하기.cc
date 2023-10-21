#include <iostream>
#include <queue>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

#define endl "\n"
#define BOARDER 101

int M, N, K;	// <=100
int start_x, start_y, end_x, end_y;
char visited[BOARDER][BOARDER];
struct Edge {
	int y, x;
};

vector<int> res;
queue<Edge> q;

void init() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	memset(visited, 48, sizeof(visited));
	cin >> M >> N >> K;
	
	for (int i = 0; i < K; i++) {
		cin >> start_x >> start_y >> end_x >> end_y;

		for (int y = start_y; y < end_y; y++) {
			for (int x = start_x; x < end_x; x++) {
				visited[y][x] = '1';
			}
		}
	}
}

void bfs(int y, int x) {
	int cnt = 0;

	Edge start;
	start.y = y;
	start.x = x;

	q.push(start);

	while (!q.empty()) {
		Edge Now = q.front();
		q.pop();

		int dy[] = { 0,0,1,-1 };
		int dx[] = { 1,-1,0,0 };
		for (int i = 0; i < 4; i++) {
			int y = Now.y + dy[i];
			int x = Now.x + dx[i];

			if (x < 0 || y < 0 || y >= M || x >= N) {
				continue;
			}
			if (visited[y][x] != '0') {
				continue;
			}
			visited[y][x] = '1';
			cnt++;

			Edge Next;
			Next.y = y;
			Next.x = x;

			q.push(Next);
		}

	}
	if (cnt == 0) {
		res.push_back(1);
	}
	else {
		res.push_back(cnt);
	}
}


int main() {

	int cnt = 0;
	init();
	for (int y = 0; y < M; y++) {
		for (int x = 0; x < N; x++) {
			if (visited[y][x] == '0') {
				cnt++;
				bfs(y,x);
			}
		}
	}
	cout << cnt << endl;
	sort(res.begin(), res.end());
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}

	cout << endl;
}

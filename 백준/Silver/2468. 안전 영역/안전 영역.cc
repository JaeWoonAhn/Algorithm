#include <iostream>
#include <queue>
#include <vector>	
#include <string.h>

using namespace std;

#define endl "\n"
#define BOARDER 101

int N;
int MAP[BOARDER][BOARDER];
int visited[BOARDER][BOARDER];
int MAX;
int cnt = 1;
struct Edge {
	int y, x;
};
queue<Edge> q;
void init() {
//	freopen_s(new FILE*, "input.txt", "r", stdin);

	cin >> N;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> MAP[y][x];
			if (MAX < MAP[y][x]) {
				MAX = MAP[y][x];
			}
		}
	}
}

void bfs(int y, int x, int n) {
	Edge edge;
	edge.y = y;
	edge.x = x;

	q.push(edge);

	visited[y][x] = 1;

	while (!q.empty()) {
		Edge Now = q.front();
		q.pop();

		int dy[] = { 0,0,1,-1 };
		int dx[] = { 1,-1,0,0 };
		for (int i = 0; i < 4; i++) {
			int y = Now.y + dy[i];
			int x = Now.x + dx[i];

			if (y < 0 || x < 0 || x >= N || y >= N) {
				continue;
			}
			if (MAP[y][x] <= n) {
				continue;
			}
			if (visited[y][x] != 0) {
				continue;
			}
			visited[y][x] = 1;

			Edge Next;
			Next.y = y;
			Next.x = x;

			q.push(Next);
		}
	}
}
int main() {
	int cnt_max = 0;

	init();
	for (int n = 0; n < MAX; n++) {
		int cnt = 0;
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				if (MAP[y][x] > n && visited[y][x] == 0) {
					bfs(y, x, n);
					cnt++;
				}
			}
		}
		memset(visited, 0, sizeof(visited));
		if (cnt_max < cnt)
			cnt_max = cnt;
	}
	cout << cnt_max << endl;

	return 0;
}